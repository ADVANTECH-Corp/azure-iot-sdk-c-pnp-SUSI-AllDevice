#ifndef __IMPL__
#define __IMPL__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"
#include "parson.h"

/**
* Type definition
*/



/**
* Device telemetries related methods.
*/

double Sensors_Information_Telemetry_ReadVvcore();

double Sensors_Information_Telemetry_ReadVvcore2();

double Sensors_Information_Telemetry_ReadV25v();

double Sensors_Information_Telemetry_ReadV33v();

double Sensors_Information_Telemetry_ReadV5v();

double Sensors_Information_Telemetry_ReadV12v();

double Sensors_Information_Telemetry_ReadV5vstandby();

double Sensors_Information_Telemetry_ReadV3vstandby();

double Sensors_Information_Telemetry_ReadVcmosbattery();

double Sensors_Information_Telemetry_ReadV5nv();

double Sensors_Information_Telemetry_ReadV12nv();

double Sensors_Information_Telemetry_ReadVvtt();

double Sensors_Information_Telemetry_ReadV24v();

double Sensors_Information_Telemetry_ReadTcpu();

double Sensors_Information_Telemetry_ReadTchipset();

double Sensors_Information_Telemetry_ReadTsystem();

double Sensors_Information_Telemetry_ReadTcpu2();

double Sensors_Information_Telemetry_ReadFcpu();

double Sensors_Information_Telemetry_ReadFsystem();

double Sensors_Information_Telemetry_ReadFcpu2();

/**
* Device properties related methods.
*/
char* Device_Detailed_Information_Property_GetDeviceName();

char* Device_Detailed_Information_Property_GetAgentID();

char* Device_Detailed_Information_Property_GetDeviceGroups();

char* Device_Detailed_Information_Property_GetWakeOnLAN();

char* Device_Detailed_Information_Property_GetConnectionStatus();

char* Device_Detailed_Information_Property_GetAutoReport();

char* Device_Detailed_Information_Property_GetStatusMessage();

char* Device_Detailed_Information_Property_GetProduct();

char* Device_Detailed_Information_Property_GetManufacturer();

char* Device_Detailed_Information_Property_GetVersion();

char* Device_Detailed_Information_Property_GetPlatform();

char* Device_Detailed_Information_Property_GetOperatingSystem();

char* Device_Detailed_Information_Property_GetMAC();

char* Device_Detailed_Information_Property_GetCPU();

char* Device_Detailed_Information_Property_GetMemory();

char* Device_Detailed_Information_Property_GetGrafanaFolder();

char* Device_Detailed_Information_Property_GetGrafanaBoard();

char* Device_Detailed_Information_Property_GetBiosVersion();

char* Device_Detailed_Information_Property_GetECFirmware();

char* Device_Detailed_Information_Property_GetDriverVersion();

char* Device_Detailed_Information_Property_GetLibraryVersion();

char* Device_Detailed_Information_Property_GetFirmwareVersion();

char* Device_Detailed_Information_Property_GetLastConnectedAt();








char* DeviceInfo_Property_GetManufacturer();

char* DeviceInfo_Property_GetModel();

char* DeviceInfo_Property_GetSwVersion();

char* DeviceInfo_Property_GetOsName();

char* DeviceInfo_Property_GetProcessorArchitecture();

char* DeviceInfo_Property_GetProcessorManufacturer();

char* DeviceInfo_Property_GetTotalStorage();

char* DeviceInfo_Property_GetTotalMemory();






#ifdef __cplusplus
}
#endif

#endif // __IMPL__
