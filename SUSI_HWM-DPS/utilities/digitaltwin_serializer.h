﻿/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.2.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 2019年10月2日
 ***********************************************************************************************/

#ifndef DIGITALTWIN_SERIALIZER
#define DIGITALTWIN_SERIALIZER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "azure_c_shared_utility/xlogging.h"
#include "parson.h"

#include "../SUSI_HWM.h"

#ifdef __cplusplus
extern "C"
{
#endif

bool Device_Detailed_Information_SerializeBiosVersionProperty(char* payloadBuffer, int size);

bool Device_Detailed_Information_SerializeECFirmwareProperty(char* payloadBuffer, int size);

bool Device_Detailed_Information_SerializeDriverVersionProperty(char * payloadBuffer, int size);

bool Device_Detailed_Information_SerializeLibraryVersionProperty(char * payloadBuffer, int size);

bool Device_Detailed_Information_SerializeFirmwareVersionProperty(char * payloadBuffer, int size);

bool Device_Detailed_Information_SerializeLastConnectedAtProperty(char * payloadBuffer, int size);

bool Sensors_Information_SerializeVvcoreTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeVvcore2Telemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV25vTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV33vTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeV5vTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV12vTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV5vstandbyTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV3vstandbyTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeVcmosbatteryTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeV5nvTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV12nvTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeVvttTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeV24vTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeTcpuTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeTchipsetTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeTsystemTelemetry(char * payloadBuffer, int size);

bool Sensors_Information_SerializeTcpu2Telemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeFcpuTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeFsystemTelemetry(char* payloadBuffer, int size);

bool Sensors_Information_SerializeFcpu2Telemetry(char* payloadBuffer, int size);

bool DeviceInfo_SerializeManufacturerProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeModelProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeSwVersionProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeOsNameProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeProcessorArchitectureProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeProcessorManufacturerProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeTotalStorageProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeTotalMemoryProperty(char * payloadBuffer, int size);

#ifdef __cplusplus
}
#endif

#endif // DIGITALTWIN_SERIALIZER
