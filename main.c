// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// This sample implements an IoT Plug and Play based thermostat.  This demonstrates a *relatively* simple PnP device
// that does only acts as a thermostat and does not have additional components.  

// The DigitalTwin Definition Language document describing the component implemented in this sample
// is available at https://github.com/Azure/opendigitaltwins-dtdl/blob/master/DTDL/v2/samples/Thermostat.json.

// Standard C header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// IoTHub Device Client and IoT core utility related header files
#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "iothub_message.h"
#include "iothub_client_options.h"
#include "iothubtransportmqtt.h"
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/xlogging.h"

#ifdef SET_TRUSTED_CERT_IN_SAMPLES
#include "azure_c_shared_utility/shared_util_options.h"
#include "certs.h"
#endif // SET_TRUSTED_CERT_IN_SAMPLES

#ifdef USE_PROV_MODULE_FULL
#include "pnp_dps_ll.h"
#endif // USE_PROV_MODULE_FULL

// JSON parser library
#include "parson.h"

#include "device.h"
#include "impl.h"

// This device's PnP ModelId.
char g_ModelId[128] = "dtmi:Advantech:UTC_520;2";
char g_ModelName[64] = "UTC-520";

// Environment variable used to specify how app connects to hub and the two possible values
static const char g_securityTypeEnvironmentVariable[] = "DPS";
static const char g_securityTypeConnectionStringValue[] = "connectionString";
static const char g_securityTypeDpsValue[] = "DPS";

// Environment variable used to specify this application's connection string
static const char g_connectionStringEnvironmentVariable[] = "IOTHUB_DEVICE_CONNECTION_STRING";

#ifdef USE_PROV_MODULE_FULL

// Environment variable used to specify this application's DPS id scope
char g_dpsIdScopeEnvironmentVariable[128] = "{}";

// Environment variable used to specify this application's DPS device id
char g_dpsDeviceIdEnvironmentVariable[128] = "{}";

// Environment variable used to specify this application's DPS device key
char g_dpsDeviceKeyEnvironmentVariable[128] = "{}";


// Environment variable used to optionally specify this application's DPS id scope
static const char g_dpsEndpointEnvironmentVariable[] = "global.azure-devices-provisioning.net";

// Global provisioning endpoint for DPS if one is not specified via the environment
static const char g_dps_DefaultGlobalProvUri[] = "global.azure-devices-provisioning.net";

// Values of connection / security settings read from environment variables and/or DPS runtime
PNP_DEVICE_CONFIGURATION g_pnpDeviceConfiguration;
#endif // USE_PROV_MODULE_FULL

// Connection string used to authenticate device when connection strings are used
const char* g_pnpDeviceConnectionString;

// Amount of time to sleep between polling hub, in milliseconds.  Set to wake up every 100 milliseconds.
static unsigned int g_sleepBetweenPollsMs = 100;

// Every time the main loop wakes up, on the g_sendTelemetryPollInterval(th) pass will send a telemetry message.
// So we will send telemetry every (g_sendTelemetryPollInterval * g_sleepBetweenPollsMs) milliseconds; 60 seconds as currently configured.
static const int g_sendTelemetryPollInterval = 30;

// Whether verbose tracing at the IoTHub client is enabled or not.
static bool g_hubClientTraceEnabled = true;

// JSON fields from desired property to retrieve.
static const char g_IoTHubTwinDesiredVersion[] = "$version";


// Name of command this component supports to get report information
static const char g_getMinMaxReport[] = "getMaxMinReport";
// Return codes for device methods and desired property responses
static int g_statusSuccess = 200;
static int g_statusBadFormat = 400;
static int g_statusNotFoundStatus = 404;
static int g_statusInternalError = 500;

// An empty JSON body for PnP command responses
static const char g_JSONEmpty[] = "{}";
static const size_t g_JSONEmptySize = sizeof(g_JSONEmpty) - 1;


//
// CopyTwinPayloadToString takes the twin payload data, which arrives as a potentially non-NULL terminated string, and creates
// a new copy of the data with a NULL terminator.  The JSON parser this sample uses, parson, only operates over NULL terminated strings.
//
static char* CopyTwinPayloadToString(const unsigned char* payload, size_t size)
{
    char* jsonStr;

    if ((jsonStr = (char*)malloc(size+1)) == NULL)
    {
        LogError("Unable to allocate %lu size buffer", (unsigned long)(size+1));
    }
    else
    {
        memcpy(jsonStr, payload, size);
        jsonStr[size] = '\0';
    }

    return jsonStr;
}



//
// SetEmptyCommandResponse sets the response to be an empty JSON.  IoT Hub needs
// legal JSON, regardless of error status, so if command implementation did not set this do so here.
//
static void SetEmptyCommandResponse(unsigned char** response, size_t* responseSize, int* result)
{
    if ((*response = calloc(1, g_JSONEmptySize)) == NULL)
    {
        LogError("Unable to allocate empty JSON response");
        *result = g_statusInternalError;
    }
    else
    {
        memcpy(*response, g_JSONEmpty, g_JSONEmptySize);
        *responseSize = g_JSONEmptySize;
        // We only overwrite the caller's result on error; otherwise leave as it was
    }
}

//
// Thermostat_DeviceMethodCallback is invoked by IoT SDK when a device method arrives.
//
static int Thermostat_DeviceMethodCallback(const char* methodName, const unsigned char* payload, size_t size, unsigned char** response, size_t* responseSize, void* userContextCallback)
{
    (void)userContextCallback;

    char* jsonStr = NULL;
    JSON_Value* rootValue = NULL;
    const char* sinceStr;
    int result = g_statusNotFoundStatus;

    LogInfo("Device method %s arrived", methodName);

    *response = NULL;
    *responseSize = 0;
    /*
    if (strcmp(methodName, g_getMinMaxReport) != 0)
    {
        LogError("Method name %s is not supported on this component", methodName);
        result = g_statusNotFoundStatus;
    }
    else if ((jsonStr = CopyTwinPayloadToString(payload, size)) == NULL)
    {
        LogError("Unable to allocate twin buffer");
        result = g_statusInternalError;
    }
    else if ((rootValue = json_parse_string(jsonStr)) == NULL)
    {
        LogError("Unable to parse twin JSON");
        result = g_statusBadFormat;
    }
    // See caveats section in ../readme.md; we don't actually respect this sinceStr to keep the sample simple,
    // but want to demonstrate how to parse out in any case.
    else if ((sinceStr = json_value_get_string(rootValue)) == NULL)
    {
        LogError("Cannot retrieve since value");
        result = g_statusBadFormat;
    }
    else if (BuildMaxMinCommandResponse(response, responseSize) == false)
    {
        LogError("Unable to build response");
        result = g_statusInternalError;        
    }
    else
    {
        LogInfo("Returning success from command request");
        result = g_statusSuccess;
    }
    */
    if (*response == NULL)
    {
        SetEmptyCommandResponse(response, responseSize, &result);
    }

    //json_value_free(rootValue);
    //free(jsonStr);
    
    return result;
}

//
// GetDesiredJson retrieves JSON_Object* in the JSON tree corresponding to the desired payload.
//
static JSON_Object* GetDesiredJson(DEVICE_TWIN_UPDATE_STATE updateState, JSON_Value* rootValue)
{
    JSON_Object* rootObject = NULL;
    JSON_Object* desiredObject;

    if ((rootObject = json_value_get_object(rootValue)) == NULL)
    {
        LogError("Unable to get root object of JSON");
        desiredObject = NULL;
    }
    else
    {
        if (updateState == DEVICE_TWIN_UPDATE_COMPLETE)
        {
            // For a complete update, the JSON from IoTHub will contain both "desired" and "reported" - the full twin.
            // We only care about "desired" in this sample, so just retrieve it.
            desiredObject = json_object_get_object(rootObject, "desired");
        }
        else
        {
            // For a patch update, IoTHub only sends "desired" portion of twin and does not explicitly put a "desired:" JSON envelope.
            // So here we simply need the root of the JSON itself.
            desiredObject = rootObject;
        }
    }

    return desiredObject;
}

//
// Thermostat_DeviceTwinCallback is invoked by the IoT SDK when a twin - either full twin or a PATCH update - arrives.
//
static void Thermostat_DeviceTwinCallback(DEVICE_TWIN_UPDATE_STATE updateState, const unsigned char* payload, size_t size, void* userContextCallback)
{
    // The device handle associated with this request is passed as the context, since we will need to send reported events back.
    IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL = (IOTHUB_DEVICE_CLIENT_LL_HANDLE)userContextCallback;

    char* jsonStr = NULL;
    JSON_Value* rootValue = NULL;
    JSON_Object* desiredObject;
    JSON_Value* versionValue = NULL;
    

    LogInfo("DeviceTwin callback invoked");

    if ((jsonStr = CopyTwinPayloadToString(payload, size)) == NULL)
    {
        LogError("Unable to allocate twin buffer");
    }
    else if ((rootValue = json_parse_string(jsonStr)) == NULL)
    {
        LogError("Unable to parse twin JSON");
    }
    else if ((desiredObject = GetDesiredJson(updateState, rootValue)) == NULL)
    {
        LogError("Cannot retrieve desired JSON object");
    }
    else if ((versionValue = json_object_get_value(desiredObject, g_IoTHubTwinDesiredVersion)) == NULL)
    {
        // The $version does need to be set in *any* legitimate twin desired document.  Its absence suggests 
        // something is fundamentally wrong with how we've received the twin and we should not proceed.
        LogError("Cannot retrieve field %s for twin.  The underlying IoTHub device twin protocol (NOT the service solution directly) should have specified this.", g_IoTHubTwinDesiredVersion);
    }
    else if (json_value_get_type(versionValue) != JSONNumber)
    {
        // The $version must be a number (and in practice an int) A non-numerical value indicates 
        // something is fundamentally wrong with how we've received the twin and we should not proceed.
        LogError("JSON field %s is not a number but must be", g_IoTHubTwinDesiredVersion);
    }
    else {

        int version = (int)json_value_get_number(versionValue);
        Device_LoopAllProperties(deviceClientLL, desiredObject, version);
    }

    json_value_free(rootValue);
    free(jsonStr);
}

//
// GetConnectionStringFromEnvironment retrieves the connection string based on environment variable
//
static bool GetConnectionStringFromEnvironment()
{
    bool result;

    if ((g_pnpDeviceConnectionString = getenv(g_connectionStringEnvironmentVariable)) == NULL)
    {
        LogError("Cannot read environment variable=%s", g_connectionStringEnvironmentVariable);
        result = false;
    }
    else
    {
#ifdef USE_PROV_MODULE_FULL
        g_pnpDeviceConfiguration.securityType = PNP_CONNECTION_SECURITY_TYPE_CONNECTION_STRING;
#endif
        result = true;    
    }

    return result;
}

//
// GetDpsFromEnvironment retrieves DPS configuration for a symmetric key based connection
// from environment variables
//
static bool GetDpsFromEnvironment()
{
#ifndef USE_PROV_MODULE_FULL
    // Explain to user misconfiguration.  The "run_e2e_tests" must be set to OFF because otherwise
    // the e2e's test HSM layer and symmetric key logic will conflict.
    LogError("DPS based authentication was requested via environment variables, but DPS is not enabled.");
    LogError("DPS is an optional component of the Azure IoT C SDK.  It is enabled with symmetric keys at cmake time by");
    LogError("passing <-Duse_prov_client=ON -Dhsm_type_symm_key=ON -Drun_e2e_tests=OFF> to cmake's command line");
    return false;
#else
    bool result = true;

    /*if ((g_pnpDeviceConfiguration.u.dpsConnectionAuth.endpoint = getenv(g_dpsEndpointEnvironmentVariable)) == NULL)
    {
        // We will fall back to standard endpoint if one is not specified
        g_pnpDeviceConfiguration.u.dpsConnectionAuth.endpoint = g_dps_DefaultGlobalProvUri;
    }

    if ((g_pnpDeviceConfiguration.u.dpsConnectionAuth.idScope = getenv(g_dpsIdScopeEnvironmentVariable)) == NULL)
    {
        LogError("Cannot read environment variable=%s", g_dpsIdScopeEnvironmentVariable);
        result = false;
    }
    else if ((g_pnpDeviceConfiguration.u.dpsConnectionAuth.deviceId = getenv(g_dpsDeviceIdEnvironmentVariable)) == NULL)
    {
        LogError("Cannot read environment variable=%s", g_dpsDeviceIdEnvironmentVariable);
        result = false;
    }
    else if ((g_pnpDeviceConfiguration.u.dpsConnectionAuth.deviceKey = getenv(g_dpsDeviceKeyEnvironmentVariable)) == NULL)
    {
        LogError("Cannot read environment variable=%s", g_dpsDeviceKeyEnvironmentVariable);
        result = false;
    }
    else
    {
        g_pnpDeviceConfiguration.securityType = PNP_CONNECTION_SECURITY_TYPE_DPS;
        result = true;    
    }*/

    g_pnpDeviceConfiguration.u.dpsConnectionAuth.endpoint = g_dpsEndpointEnvironmentVariable;
    g_pnpDeviceConfiguration.u.dpsConnectionAuth.idScope = g_dpsIdScopeEnvironmentVariable;
    g_pnpDeviceConfiguration.u.dpsConnectionAuth.deviceId = g_dpsDeviceIdEnvironmentVariable;
    g_pnpDeviceConfiguration.u.dpsConnectionAuth.deviceKey = g_dpsDeviceKeyEnvironmentVariable;
    g_pnpDeviceConfiguration.securityType = PNP_CONNECTION_SECURITY_TYPE_DPS;

    return result;
#endif // USE_PROV_MODULE_FULL
}


//
// GetConfigurationFromEnvironment reads how to connect to the IoT Hub (using 
// either a connection string or a DPS symmetric key) from the environment.
//
static bool GetConnectionSettingsFromEnvironment()
{
    const char* securityTypeString = "DPS";
    bool result;

    /*if ((securityTypeString = getenv(g_securityTypeEnvironmentVariable)) == NULL)
    {
        LogError("Cannot read environment variable=%s", g_securityTypeEnvironmentVariable);
        result = false;
    }
    else
    {*/
        if (strcmp(securityTypeString, g_securityTypeConnectionStringValue) == 0)
        {
            result = GetConnectionStringFromEnvironment();
        }
        else if (strcmp(securityTypeString, g_securityTypeDpsValue) == 0)
        {
            result = GetDpsFromEnvironment();
        }
        else
        {
            LogError("Environment variable %s must be either %s or %s", g_securityTypeEnvironmentVariable, g_securityTypeConnectionStringValue, g_securityTypeDpsValue);
            result = false;
        }
    //}

    return result;    
}

//
// CreateDeviceClientLLHandle performs actual handle creation (but nothing more), depending
// on whether connection strings or DPS is used.
//
static IOTHUB_DEVICE_CLIENT_LL_HANDLE CreateDeviceClientLLHandle(void)
{
#ifdef USE_PROV_MODULE_FULL
    if (g_pnpDeviceConfiguration.securityType == PNP_CONNECTION_SECURITY_TYPE_DPS)
    {
        // Pass the modelId to DPS here AND later on to IoT Hub (see SetOption on OPTION_MODEL_ID) when
        // that connection is created.  We need to do both because DPS does not auto-populate the modelId
        // it receives on DPS connection to the IoT Hub.
        g_pnpDeviceConfiguration.modelId = g_ModelId;
        g_pnpDeviceConfiguration.enableTracing = g_hubClientTraceEnabled;
        return PnP_CreateDeviceClientLLHandle_ViaDps(&g_pnpDeviceConfiguration);
    }
#endif
    return IoTHubDeviceClient_LL_CreateFromConnectionString(g_pnpDeviceConnectionString, MQTT_Protocol);
}

//
// CreateAndConfigureDeviceClientHandleForPnP creates a IOTHUB_DEVICE_CLIENT_LL_HANDLE for this application, setting its
// ModelId along with various callbacks.
//
static IOTHUB_DEVICE_CLIENT_LL_HANDLE CreateAndConfigureDeviceClientHandleForPnP(void)
{
    IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceHandle = NULL;
    IOTHUB_CLIENT_RESULT iothubResult;
    bool urlAutoEncodeDecode = true;
    int iothubInitResult;
    bool result;

    // Before invoking ANY IoTHub Device SDK functionality, IoTHub_Init must be invoked.
    if ((iothubInitResult = IoTHub_Init()) != 0)
    {
        LogError("Failure to initialize client.  Error=%d", iothubInitResult);
        result = false;
    }
    // Create the deviceHandle itself.
    else if ((deviceHandle = CreateDeviceClientLLHandle()) == NULL)
    {
        LogError("Failure creating IotHub client.  Hint: Check your connection string or DPS configuration");
        result = false;
    }
    // Sets verbosity level
    else if ((iothubResult = IoTHubDeviceClient_LL_SetOption(deviceHandle, OPTION_LOG_TRACE, &g_hubClientTraceEnabled)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set logging option, error=%d", iothubResult);
        result = false;
    }
    // Sets the name of ModelId for this PnP device.
    // This *MUST* be set before the client is connected to IoTHub.  We do not automatically connect when the 
    // handle is created, but will implicitly connect to subscribe for device method and device twin callbacks below.
    else if ((iothubResult = IoTHubDeviceClient_LL_SetOption(deviceHandle, OPTION_MODEL_ID, g_ModelId)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set the ModelID, error=%d", iothubResult);
        result = false;
    }
    // Sets the callback function that processes incoming device methods, which is the channel PnP Commands are transferred over
    else if ((iothubResult = IoTHubDeviceClient_LL_SetDeviceMethodCallback(deviceHandle, Thermostat_DeviceMethodCallback, NULL)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set device method callback, error=%d", iothubResult);
        result = false;
    }
    // Sets the callback function that processes device twin changes from the IoTHub, which is the channel that PnP Properties are 
    // transferred over.  This will also automatically retrieve the full twin for the application. 
    else if ((iothubResult = IoTHubDeviceClient_LL_SetDeviceTwinCallback(deviceHandle, Thermostat_DeviceTwinCallback, (void*)deviceHandle)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set device twin callback, error=%d", iothubResult);
        result = false;
    }
    // Enabling auto url encode will have the underlying SDK perform URL encoding operations automatically.
    else if ((iothubResult = IoTHubDeviceClient_LL_SetOption(deviceHandle, OPTION_AUTO_URL_ENCODE_DECODE, &urlAutoEncodeDecode)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set auto Url encode option, error=%d", iothubResult);
        result = false;
    }
#ifdef SET_TRUSTED_CERT_IN_SAMPLES
    // Setting the Trusted Certificate.  This is only necessary on systems without built in certificate stores.
    else if ((iothubResult = IoTHubDeviceClient_LL_SetOption(deviceHandle, OPTION_TRUSTED_CERT, certificates)) != IOTHUB_CLIENT_OK)
    {
        LogError("Unable to set the trusted cert, error=%d", iothubResult);
        result = false;
    }
#endif // SET_TRUSTED_CERT_IN_SAMPLES
    else
    {
        result = true;
    }

    if ((result == false) && (deviceHandle != NULL))
    {
        IoTHubDeviceClient_LL_Destroy(deviceHandle);
        deviceHandle = NULL;
    }

    if ((result == false) &&  (iothubInitResult == 0))
    {
        IoTHub_Deinit();
    }

    return deviceHandle;
}

int main(int argc, char **argv)
{
    if (argc < 6) {
        printf("Please use \"PNP_SUSI.exe {model id} {model version} {dps id scope} {dps device id} {dps device key}\"\n");
        printf("ex: PNP_SUSI.exe \"UTC_520\" \"2\" \"scope\" \"123-456\" \"dkfjiefj=\"\n");
    }

    sprintf(g_ModelId, "dtmi:Advantech:%s;%s", argv[1], argv[2]);
    sprintf(g_ModelName, "%s", argv[1]);

    printf("your model id:\t%s\n", g_ModelId);

    strcpy(g_dpsIdScopeEnvironmentVariable, argv[3]);
    strcpy(g_dpsDeviceIdEnvironmentVariable, argv[4]);
    strcpy(g_dpsDeviceKeyEnvironmentVariable, argv[5]);

    printf("dps id scope: \t%s\n", g_dpsIdScopeEnvironmentVariable);
    printf("dps model id: \t%s\n", g_dpsDeviceIdEnvironmentVariable);
    printf("dps model key:\t%s\n", g_dpsDeviceKeyEnvironmentVariable);

    IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL = NULL;

    if (GetConnectionSettingsFromEnvironment() == false)
    {
        LogError("Cannot read required environment variable(s)");
    }
    else if (Device_Init() == false)
    {
        LogError("Unable to output the program start time");
    }
    else if ((deviceClientLL = CreateAndConfigureDeviceClientHandleForPnP()) == NULL)
    {
        LogError("Failed creating IotHub device client");
    }
    else
    {
        LogInfo("Successfully created device client handle.  Hit Control-C to exit program\n");

        int numberOfIterations = 0;
        //SendMaxTemperatureSinceReboot(deviceClientLL);

        while (true)
        {
            // Wake up periodically to poll.  Even if we do not plan on sending telemetry, we still need to poll periodically in order to process
            // incoming requests from the server and to do connection keep alives.
            if ((numberOfIterations % g_sendTelemetryPollInterval) == 0)
            {
                Device_SendAllTelemetries(deviceClientLL);
            }

            IoTHubDeviceClient_LL_DoWork(deviceClientLL);
            ThreadAPI_Sleep(g_sleepBetweenPollsMs);
            numberOfIterations++;
        }

        // Clean up the iothub sdk handle
        IoTHubDeviceClient_LL_Destroy(deviceClientLL);
        // Free all the IoT SDK subsystem
        IoTHub_Deinit();        
    }

    return 0;
}
