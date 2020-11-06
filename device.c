#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "parson.h"
#include "device.h"
#include "impl.h"
#include "commands.h"
#include "telemetries.h"
#include "Susi4.h"

// Size of buffer to store ISO 8601 time.
#define TIME_BUFFER_SIZE 128
// Format string to create an ISO 8601 time.  This corresponds to the DTDL datetime schema item.
static const char g_ISO8601Format[] = "%Y-%m-%dT%H:%M:%SZ";
// Start time of the program, stored in ISO 8601 format string for UTC.
char g_ProgramStartTime[TIME_BUFFER_SIZE];

//
// BuildUtcTimeFromCurrentTime writes the current time, in ISO 8601 format, into the specified buffer
//
bool BuildUtcTimeFromCurrentTime(char* utcTimeBuffer, size_t utcTimeBufferSize)
{
    bool result;
    time_t currentTime;
    struct tm* currentTimeTm;

    time(&currentTime);
    currentTimeTm = gmtime(&currentTime);

    if (strftime(utcTimeBuffer, utcTimeBufferSize, g_ISO8601Format, currentTimeTm) == 0)
    {
        printf("snprintf on UTC time failed");
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

bool Device_Init() {
    SusiStatus_t if_initial;

    if_initial = SusiLibInitialize();
    if (if_initial == SUSI_STATUS_SUCCESS)
    {
        LogInfo("SUSI_API initial succeed.");
    }
    else
    {
        LogInfo("SUSI_API initial error code %lu.", if_initial);
    }

    Impl_Init();

    return BuildUtcTimeFromCurrentTime(g_ProgramStartTime, sizeof(g_ProgramStartTime));
}

/**********************************************************************************************************************/

// The default temperature to use before any is set.
#define DEFAULT_TEMPERATURE_VALUE 22
// Current temperature of the thermostat.
static double g_currentTemperature = DEFAULT_TEMPERATURE_VALUE;
// Minimum temperature thermostat has been at during current execution run.
static double g_minTemperature = DEFAULT_TEMPERATURE_VALUE;
// Maximum temperature thermostat has been at during current execution run.
static double g_maxTemperature = DEFAULT_TEMPERATURE_VALUE;
// Number of times temperature has been updated, counting the initial setting as 1.  Used to determine average temperature.
static int g_numTemperatureUpdates = 1;
// Total of all temperature updates during current execution run.  Used to determine average temperature.
static double g_allTemperatures = DEFAULT_TEMPERATURE_VALUE;

//
// UpdateTemperatureAndStatistics updates the temperature and min/max/average values
//
void UpdateTemperatureAndStatistics(double desiredTemp, bool* maxTempUpdated)
{
    if (desiredTemp > g_maxTemperature)
    {
        g_maxTemperature = desiredTemp;
        *maxTempUpdated = true;
    }
    else if (desiredTemp < g_minTemperature)
    {
        g_minTemperature = desiredTemp;
    }

    g_numTemperatureUpdates++;
    g_allTemperatures += desiredTemp;

    g_currentTemperature = desiredTemp;
}

/**********Property*********/
// Format string to indicate the device received an update request for the temperature.  Because this is a "writeable"
// property from the service solution's perspective, we need to return a status code (HTTP status code style) and version
// for the solution to correlate the request and its status.
//static const char g_targetTemperatureResponseFormat[] = "{\"targetTemperature\":{\"value\":%.2f,\"ac\":%d,\"av\":%d,\"ad\":\"%s\"}}";
static const char g_targetTemperatureResponseFormat[] = "{\"BiosVersion\":%s}";
//
// SendTargetTemperatureReport sends a PnP property indicating the device has received the desired targeted temperature
//
void SendTargetTemperatureReport(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, double desiredTemp, int responseStatus, int version, const char* description)
{
    IOTHUB_CLIENT_RESULT iothubClientResult;
    char targetTemperatureResponseProperty[256];

    if (snprintf(targetTemperatureResponseProperty, sizeof(targetTemperatureResponseProperty), g_targetTemperatureResponseFormat, "V1.1") < 0)
    {
        printf("snprintf building targetTemperature response failed");
    }
    else if ((iothubClientResult = IoTHubDeviceClient_LL_SendReportedState(deviceClientLL, (const unsigned char*)targetTemperatureResponseProperty, strlen(targetTemperatureResponseProperty), NULL, NULL)) != IOTHUB_CLIENT_OK)
    {
        printf("Unable to send reported state for target temperature.  Error=%d", iothubClientResult);
    }
    else
    {
        printf("Sending maxTempSinceReboot property");
    }
}

/*
// Format string to report the property maximum temperature since reboot.  This is a "read only" property from the
// service solution's perspective, which means we don't need to include any sort of status codes.
static const char g_maxTemperatureSinceRebootFormat[] = "{\"maxTempSinceLastReboot\":%.2f}";
//
// SendMaxTemperatureSinceReboot reports a PnP property indicating the maximum temperature since the last reboot (simulated here by lifetime of executable)
//
void SendMaxTemperatureSinceReboot(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL)
{
    IOTHUB_CLIENT_RESULT iothubClientResult;
    char maxTemperatureSinceRebootProperty[256];

    if (snprintf(maxTemperatureSinceRebootProperty, sizeof(maxTemperatureSinceRebootProperty), g_maxTemperatureSinceRebootFormat, g_maxTemperature) < 0)
    {
        printf("snprintf building maxTemperature failed");
    }
    else if ((iothubClientResult = IoTHubDeviceClient_LL_SendReportedState(deviceClientLL, (const unsigned char*)maxTemperatureSinceRebootProperty, strlen(maxTemperatureSinceRebootProperty), NULL, NULL)) != IOTHUB_CLIENT_OK)
    {
        printf("Unable to send reported state for maximum temperature.  Error=%d", iothubClientResult);
    }
    else
    {
        printf("Sending maxTempSinceReboot property");
    }
}
*/
/**********Telemetry*********/
/*
// Format string for sending temperature telemetry
static const char g_temperatureTelemetryBodyFormat[] = "{\"vvcore\":%.02f}";

//
// Thermostat_SendCurrentTemperature sends a PnP telemetry indicating the current temperature
//
void Thermostat_SendCurrentTemperature(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL)
{
    IOTHUB_MESSAGE_HANDLE messageHandle = NULL;
    IOTHUB_CLIENT_RESULT iothubResult;

    char temperatureStringBuffer[32];

    if (snprintf(temperatureStringBuffer, sizeof(temperatureStringBuffer), g_temperatureTelemetryBodyFormat, g_currentTemperature) < 0)
    {
        printf("snprintf of current temperature telemetry failed");
    }
    else if ((messageHandle = IoTHubMessage_CreateFromString(temperatureStringBuffer)) == NULL)
    {
        printf("IoTHubMessage_CreateFromString failed");
    }
    else if ((iothubResult = IoTHubDeviceClient_LL_SendEventAsync(deviceClientLL, messageHandle, NULL, NULL)) != IOTHUB_CLIENT_OK)
    {
        printf("Unable to send telemetry message, error=%d", iothubResult);
    }

    IoTHubMessage_Destroy(messageHandle);
}
*/

/**********COMMAND*********/
// snprintf format for building getMaxMinReport
static const char g_minMaxCommandResponseFormat[] = "{\"maxTemp\":%.2f,\"minTemp\":%.2f,\"avgTemp\":%.2f,\"startTime\":\"%s\",\"endTime\":\"%s\"}";

//
// BuildMaxMinCommandResponse builds the response to the command for getMaxMinReport
//
bool BuildMaxMinCommandResponse(unsigned char** response, size_t* responseSize)
{
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char currentTime[TIME_BUFFER_SIZE];

    if (BuildUtcTimeFromCurrentTime(currentTime, sizeof(currentTime)) == false)
    {
        printf("Unable to output the current time");
        result = false;
    }
    else if ((responseBuilderSize = snprintf(NULL, 0, g_minMaxCommandResponseFormat, g_minTemperature, g_maxTemperature, g_allTemperatures / g_numTemperatureUpdates, g_ProgramStartTime, currentTime)) < 0)
    {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, g_minMaxCommandResponseFormat, g_minTemperature, g_maxTemperature, g_allTemperatures / g_numTemperatureUpdates, g_ProgramStartTime, currentTime)) < 0)
    {
        printf("snprintf to output buffer for command response");
        result = false;
    }
    else
    {
        result = true;
    }

    if (result == true)
    {
        *response = responseBuilder;
        *responseSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    return result;
}






//=======================================================================================================//
//static const char g_JSONTargetTemperature[] = "targetTemperature";

void Device_LoopAllProperties(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, JSON_Object* desiredObject, int version) {

    /*JSON_Value* targetTemperatureValue = NULL;

    if ((targetTemperatureValue = json_object_get_value(desiredObject, g_JSONTargetTemperature)) == NULL)
    {
        printf("JSON property %s not specified.  This is NOT an error as the server doesn't need to set this, but there is no further action to take.", g_JSONTargetTemperature);
    }
    else if (json_value_get_type(targetTemperatureValue) != JSONNumber)
    {
        printf("JSON field %s is not a number", g_JSONTargetTemperature);
    }
    else
    {
        double targetTemperature = json_value_get_number(targetTemperatureValue);

        printf("Received targetTemperature = %f", targetTemperature);

        bool maxTempUpdated = false;
        UpdateTemperatureAndStatistics(targetTemperature, &maxTempUpdated);

        // The device needs to let the service know that it has received the targetTemperature desired property.
        SendTargetTemperatureReport(deviceClientLL, targetTemperature, 200, version, "success");

        if (maxTempUpdated)
        {
            // If the Maximum temperature has been updated, we also report this as a property.
            SendMaxTemperatureSinceReboot(deviceClientLL);
        }

    }*/
    Property_Send_All(deviceClientLL);
}

void Device_SendAllTelemetries(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL) {
    Telemetry_Send_All(deviceClientLL);
}

int Device_ProcessAllCommands(const char* methodName, const unsigned char* payload, size_t size, unsigned char** response, size_t* responseSize) {
    return Command_Parser_All(methodName, payload, size, response, responseSize);
}

//=======================================================================================================//