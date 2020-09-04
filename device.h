#ifndef __DEVICE__
#define __DEVICE__

bool Device_Init();
void Device_LoopAllProperties(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, JSON_Object* desiredObject, int version);
void Device_SendAllTelemetries(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL);

//void UpdateTemperatureAndStatistics(double desiredTemp, bool* maxTempUpdated);
//void SendTargetTemperatureReport(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, double desiredTemp, int responseStatus, int version, const char* description);
//void SendMaxTemperatureSinceReboot(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL);
//bool BuildMaxMinCommandResponse(unsigned char** response, size_t* responseSize);



#endif