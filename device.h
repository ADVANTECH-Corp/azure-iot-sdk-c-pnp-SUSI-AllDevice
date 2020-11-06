#ifndef __DEVICE__
#define __DEVICE__

bool Device_Init();
void Device_LoopAllProperties(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, JSON_Object* desiredObject, int version);
void Device_SendAllTelemetries(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL);
int Device_ProcessAllCommands(const char* methodName, const unsigned char* payload, size_t size, unsigned char** response, size_t* responseSize);

#endif