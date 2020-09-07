#ifndef __DEVICE__
#define __DEVICE__

bool Device_Init();
void Device_LoopAllProperties(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL, JSON_Object* desiredObject, int version);
void Device_SendAllTelemetries(IOTHUB_DEVICE_CLIENT_LL_HANDLE deviceClientLL);

#endif