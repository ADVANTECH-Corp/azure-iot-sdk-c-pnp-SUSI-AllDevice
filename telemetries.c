#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "parson.h"
#include "impl.h"
#include "telemetries.h"


typedef double (*Telemetry_Read)();

Telemetry_Read g_Telemetry_Readfuncs[] = {
    Sensors_Information_Telemetry_ReadVvcore,
    Sensors_Information_Telemetry_ReadVvcore2,
    Sensors_Information_Telemetry_ReadV25v,
    Sensors_Information_Telemetry_ReadV33v,
    Sensors_Information_Telemetry_ReadV5v,
    Sensors_Information_Telemetry_ReadV12v,
    Sensors_Information_Telemetry_ReadV5vstandby,
    Sensors_Information_Telemetry_ReadV3vstandby,
    Sensors_Information_Telemetry_ReadVcmosbattery,
    Sensors_Information_Telemetry_ReadV5nv,
    Sensors_Information_Telemetry_ReadV12nv,
    Sensors_Information_Telemetry_ReadVvtt,
    Sensors_Information_Telemetry_ReadV24v,
    Sensors_Information_Telemetry_ReadTcpu,
    Sensors_Information_Telemetry_ReadTchipset,
    Sensors_Information_Telemetry_ReadTsystem,
    Sensors_Information_Telemetry_ReadTcpu2,
    Sensors_Information_Telemetry_ReadFcpu,
    Sensors_Information_Telemetry_ReadFsystem,
    Sensors_Information_Telemetry_ReadFcpu2
};

const char* g_Telemetry_Readnames[] = {
    "vvcore",
    "vvcore2",
    "v25v",
    "v33v",
    "v5v",
    "v12v",
    "v5vstandby",
    "v3vstandby",
    "vcmosbattery",
    "v5nv",
    "v12nv",
    "vvtt",
    "v24v",
    "tcpu",
    "tchipset",
    "tsystem",
    "tcpu2",
    "fcpu",
    "fsystem",
    "fcpu2"
};

//
// Thermostat_SendCurrentTemperature sends a PnP telemetry indicating the current temperature
//
void Telemetry_Send(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char *stringBuffer)
{
    IOTHUB_MESSAGE_HANDLE messageHandle = NULL;
    IOTHUB_CLIENT_RESULT iothubResult;

    if ((messageHandle = IoTHubMessage_CreateFromString(stringBuffer)) == NULL)
    {
        printf("IoTHubMessage_CreateFromString failed");
    }
    else if ((iothubResult = IoTHubDeviceClient_LL_SendEventAsync(deviceClientLL, messageHandle, NULL, NULL)) != IOTHUB_CLIENT_OK)
    {
        printf("Unable to send telemetry message, error=%d", iothubResult);
    }

    IoTHubMessage_Destroy(messageHandle);
}

void Telemetry_Send_Double(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char *name, double value)
{
    char stringBuffer[32];
    const char OneDouble_BodyFormat[] = "{\"%s\":%.02f}";
    if (snprintf(stringBuffer, sizeof(stringBuffer), OneDouble_BodyFormat, name, value) < 0)
    {
        printf("snprintf of current temperature telemetry failed");
    }
    else {
        Telemetry_Send(deviceClientLL, stringBuffer);
    }

}

void Telemetry_Send_Vvcore(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL)
{
    double value = Sensors_Information_Telemetry_ReadVvcore();
    Telemetry_Send_Double(deviceClientLL, "vvcore", value);
}

void Telemetry_Send_All(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL)
{
    size_t n = sizeof(g_Telemetry_Readfuncs) / sizeof(g_Telemetry_Readfuncs[0]);
    double value;
    for (int i = 0; i < n; i++) {
        value = g_Telemetry_Readfuncs[i]();
        Telemetry_Send_Double(deviceClientLL, g_Telemetry_Readnames[i], value);
    }

}

