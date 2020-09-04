#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "parson.h"
#include "impl.h"
#include "properties.h"


typedef char* (*Property_Read)();

Property_Read g_Property_Readfuncs[] = {
    /*Device_Detailed_Information_Property_GetDeviceName,
    Device_Detailed_Information_Property_GetAgentID,
    Device_Detailed_Information_Property_GetDeviceGroups,
    Device_Detailed_Information_Property_GetWakeOnLAN,
    Device_Detailed_Information_Property_GetConnectionStatus,
    Device_Detailed_Information_Property_GetAutoReport,
    Device_Detailed_Information_Property_GetStatusMessage,
    Device_Detailed_Information_Property_GetProduct,
    Device_Detailed_Information_Property_GetManufacturer,
    Device_Detailed_Information_Property_GetVersion,
    Device_Detailed_Information_Property_GetPlatform,
    Device_Detailed_Information_Property_GetOperatingSystem,
    Device_Detailed_Information_Property_GetMAC,
    Device_Detailed_Information_Property_GetCPU,
    Device_Detailed_Information_Property_GetMemory,
    Device_Detailed_Information_Property_GetGrafanaFolder,
    Device_Detailed_Information_Property_GetGrafanaBoard,*/
    Device_Detailed_Information_Property_GetBiosVersion,
    Device_Detailed_Information_Property_GetECFirmware,
    Device_Detailed_Information_Property_GetDriverVersion,
    Device_Detailed_Information_Property_GetLibraryVersion,
    Device_Detailed_Information_Property_GetFirmwareVersion,
    Device_Detailed_Information_Property_GetLastConnectedAt,

    DeviceInfo_Property_GetManufacturer,
    DeviceInfo_Property_GetModel,
    DeviceInfo_Property_GetSwVersion,
    DeviceInfo_Property_GetOsName,
    DeviceInfo_Property_GetProcessorArchitecture,
    DeviceInfo_Property_GetProcessorManufacturer,
    DeviceInfo_Property_GetTotalStorage,
    DeviceInfo_Property_GetTotalMemory
};

const char* g_Property_Readnames[] = {
    /*"DeviceName",
    "AgentID",
    "DeviceGroups",
    "WakeOnLAN",
    "ConnectionStatus",
    "AutoReport",
    "StatusMessage",
    "Product",
    "Manufacturer",
    "Version",
    "Platform",
    "OperatingSystem",
    "MAC",
    "CPU",
    "Memory",
    "GrafanaFolder",
    "GrafanaBoard",*/
    "BiosVersion",
    "ECFirmware",
    "DriverVersion",
    "LibraryVersion",
    "FirmwareVersion",
    "LastConnectedAt",

    "manufacturer",
    "model",
    "swVersion",
    "osName",
    "processorArchitecture",
    "processorManufacturer",
    "totalStorage",
    "totalMemory"
};

enum {
    TYPE_STRING,
    TYPE_DOUBLE,
    TYPE_DATETIME
};
const int g_Property_Readtypes[] = {
    /*TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,*/
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_DATETIME,

    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_STRING,
    TYPE_DOUBLE,
    TYPE_DOUBLE
};


//
// Thermostat_SendCurrentTemperature sends a PnP telemetry indicating the current temperature
//
void Property_Send(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char *stringBuffer)
{
    IOTHUB_CLIENT_RESULT iothubClientResult;

    if ((iothubClientResult = IoTHubDeviceClient_LL_SendReportedState(deviceClientLL, (const unsigned char*)stringBuffer, strlen(stringBuffer), NULL, NULL)) != IOTHUB_CLIENT_OK)
    {
        printf("Unable to send reported state for maximum temperature.  Error=%d", iothubClientResult);
    }
    else
    {
        printf("Sending maxTempSinceReboot property");
    }
}

void Property_Send_Double(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char *name, char* value)
{
    char stringBuffer[32];
    const char BodyFormat[] = "{\"%s\":%s}";
    if (snprintf(stringBuffer, sizeof(stringBuffer), BodyFormat, name, value) < 0)
    {
        printf("snprintf of current temperature telemetry failed");
    }
    else {
        Property_Send(deviceClientLL, stringBuffer);
    }
}

void Property_Send_String(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char* name, char* value)
{
    char stringBuffer[128];
    const char BodyFormat[] = "{\"%s\":\"%s\"}";
    if (snprintf(stringBuffer, sizeof(stringBuffer), BodyFormat, name, value) < 0)
    {
        printf("snprintf of current temperature telemetry failed");
    }
    else {
        Property_Send(deviceClientLL, stringBuffer);
    }

}

void Property_Send_Datetime(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, char* name, char* value)
{
    char stringBuffer[128];
    const char BodyFormat[] = "{\"%s\":\"%s\"}";
    if (snprintf(stringBuffer, sizeof(stringBuffer), BodyFormat, name, value) < 0)
    {
        printf("snprintf of current temperature telemetry failed");
    }
    else {
        Property_Send(deviceClientLL, stringBuffer);
    }
}

void Property_Send_All(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL)
{
    size_t n = sizeof(g_Property_Readfuncs) / sizeof(g_Property_Readfuncs[0]);

    for (int i = 0; i < n; i++) {
        switch (g_Property_Readtypes[i]) {
            case TYPE_DOUBLE:
            {
                char* value = g_Property_Readfuncs[i]();
                Property_Send_Double(deviceClientLL, g_Property_Readnames[i], value);
            }
            break;
            case TYPE_DATETIME:
            {
                char* value = g_Property_Readfuncs[i]();
                Property_Send_Datetime(deviceClientLL, g_Property_Readnames[i], value);
            }
            break;
            case TYPE_STRING:
            default:
            {
                char* value = g_Property_Readfuncs[i]();
                Property_Send_String(deviceClientLL, g_Property_Readnames[i], value);
            }
            break;
        }
        
    }

}

