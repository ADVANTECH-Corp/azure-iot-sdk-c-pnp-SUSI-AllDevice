#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "parson.h"
#include "impl.h"
#include "commands.h"






int g_Current_Pin = 0;
bool GPIO_SET_PIN(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result = false;
    int pin = 0;
    sscanf(request, "%d", &pin);

    result = GPIO_isAvailable(pin);
    if (result) {
        g_Current_Pin = pin;
    }

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", g_Current_Pin)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", g_Current_Pin)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    return result;
}
bool GPIO_GET_PIN(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", g_Current_Pin)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", g_Current_Pin)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    return result;
}

bool GPIO_SET_VALUE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = value ? 1 : 0;

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool GPIO_GET_VALUE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = GPIO_Get(g_Current_Pin);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool GPIO_SET_DIRECTION(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = value ? 1 : 0;

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set_Direction(g_Current_Pin, value);


    return result;
}
bool GPIO_GET_DIRECTION(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = GPIO_Get_Direction(g_Current_Pin);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_ID(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetId(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_ID(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetId();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_ENABLE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetEnable(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_ENABLE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetEnable();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_BRIGHTNESS(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetBrightness(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_BRIGHTNESS(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetBrightness();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_LEVEL(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetLevel(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_LEVEL(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetLevel();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_POLARITY(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetPolarity(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_POLARITY(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetPolarity();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool VGA_SET_FREQUENCY(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = VGA_SetFrequency(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool VGA_GET_FREQUENCY(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = VGA_GetFrequency();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}


bool SDRAM_GET_PARTNUMBER(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char *value = SDRAM_GetPartNumber();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_MEMORYTYPE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetMemoryType();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_MEMORYSPEED(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = SDRAM_GetMemorySpeed();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_MODULETYPE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetModuleType();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_MODULESIZE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = SDRAM_GetModuleSize();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_WEEKYEAR(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetWeekYear();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_RANK(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = SDRAM_GetRank();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_BANK(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = SDRAM_GetBank();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_VOLTAGE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    double value = SDRAM_GetVoltage();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%02f", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%02f", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_TEMPRATURE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    double value = SDRAM_GetTemperature();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%02f", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%02f", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_MODULEMANUFACTURE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetModuleManufacture();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_DRAMMANUFACTURE(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetDramManufacture();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}
bool SDRAM_GET_WRITEPROTECTION(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    char* value = SDRAM_GetWriteProtection() == 0 ? "DISABLE" : "ENABLE";

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "\"%s\"", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "\"%s\"", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

bool SDRAM_SET_SOCKET(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = 0;
    sscanf(request, "%d", &value);

    value = SDRAM_SetSocket(value);

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }

    GPIO_Set(g_Current_Pin, value);


    return result;
}
bool SDRAM_GET_SOCKET(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize) {
    int responseBuilderSize = 0;
    unsigned char* responseBuilder = NULL;
    bool result;
    int value = SDRAM_GetSocket();

    //if ((responseBuilderSize = snprintf(NULL, 0, "{\"PIN\":%s}", request)) < 0) {
    if ((responseBuilderSize = snprintf(NULL, 0, "%d", value)) < 0) {
        printf("snprintf to determine string length for command response failed");
        result = false;
    }
    // We MUST allocate the response buffer.  It is returned to the IoTHub SDK in the direct method callback and the SDK in turn sends this to the server.
    else if ((responseBuilder = calloc(1, responseBuilderSize + 1)) == NULL)
    {
        printf("Unable to allocate %lu bytes", (unsigned long)(responseBuilderSize + 1));
        result = false;
    }
    //else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "{\"PIN\":%s}", request)) < 0)
    else if ((responseBuilderSize = snprintf((char*)responseBuilder, responseBuilderSize + 1, "%d", value)) < 0)
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
        *resSize = (size_t)responseBuilderSize;
        printf("Response=<%s>", (const char*)responseBuilder);
    }
    else
    {
        free(responseBuilder);
    }


    return result;
}

typedef bool (*Command_Process)(const unsigned char* request, size_t reqSize, unsigned char** response, size_t* resSize);

char* g_Command_Name[] = {
    "GPIO*SET_PIN",
    "GPIO*GET_PIN",
    "GPIO*SET_VALUE",
    "GPIO*GET_VALUE",
    "GPIO*SET_DIRECTION",
    "GPIO*GET_DIRECTION",

    "VGA*SET_ID",
    "VGA*GET_ID",
    "VGA*SET_ENABLE",
    "VGA*GET_ENABLE",
    "VGA*SET_BRIGHTNESS",
    "VGA*GET_BRIGHTNESS",
    "VGA*SET_LEVEL",
    "VGA*GET_LEVEL",
    "VGA*SET_POLARITY",
    "VGA*GET_POLARITY",
    "VGA*SET_FREQUENCY",
    "VGA*GET_FREQUENCY",


    "SDRAM*GET_PARTNUMBER",
    "SDRAM*GET_MEMORYTYPE",
    "SDRAM*GET_MEMORYSPEED",
    "SDRAM*GET_MODULETYPE",
    "SDRAM*GET_MODULESIZE",
    "SDRAM*GET_WEEKYEAR",
    "SDRAM*GET_RANK",
    "SDRAM*GET_BANK",
    "SDRAM*GET_VOLTAGE",
    "SDRAM*GET_TEMPRATURE",
    "SDRAM*GET_MODULEMANUFACTURE",
    "SDRAM*GET_DRAMMANUFACTURE",
    "SDRAM*GET_WRITEPROTECTION",
    "SDRAM*SET_SOCKET",
    "SDRAM*GET_SOCKET"

};

Command_Process g_Command_Process[] = {
	GPIO_SET_PIN,
	GPIO_GET_PIN,
	GPIO_SET_VALUE,
	GPIO_GET_VALUE,
    GPIO_SET_DIRECTION,
    GPIO_GET_DIRECTION,

    VGA_SET_ID,
    VGA_GET_ID,
    VGA_SET_ENABLE,
    VGA_GET_ENABLE,
    VGA_SET_BRIGHTNESS,
    VGA_GET_BRIGHTNESS,
    VGA_SET_LEVEL,
    VGA_GET_LEVEL,
    VGA_SET_POLARITY,
    VGA_GET_POLARITY,
    VGA_SET_FREQUENCY,
    VGA_GET_FREQUENCY,

    SDRAM_GET_PARTNUMBER,
    SDRAM_GET_MEMORYTYPE,
    SDRAM_GET_MEMORYSPEED,
    SDRAM_GET_MODULETYPE,
    SDRAM_GET_MODULESIZE,
    SDRAM_GET_WEEKYEAR,
    SDRAM_GET_RANK,
    SDRAM_GET_BANK,
    SDRAM_GET_VOLTAGE,
    SDRAM_GET_TEMPRATURE,
    SDRAM_GET_MODULEMANUFACTURE,
    SDRAM_GET_DRAMMANUFACTURE,
    SDRAM_GET_WRITEPROTECTION,
    SDRAM_SET_SOCKET,
    SDRAM_GET_SOCKET
};

static char* CopyTwinPayloadToString(const unsigned char* payload, size_t size)
{
    char* jsonStr;

    if ((jsonStr = (char*)malloc(size + 1)) == NULL)
    {
        printf("Unable to allocate %lu size buffer", (unsigned long)(size + 1));
    }
    else
    {
        memcpy(jsonStr, payload, size);
        jsonStr[size] = '\0';
    }

    return jsonStr;
}

int Command_Parser_All(const char* methodName, const unsigned char* payload, size_t size, unsigned char** response, size_t* responseSize) {
	size_t n = sizeof(g_Command_Process) / sizeof(g_Command_Process[0]);

    char* contentStr = NULL;
    JSON_Value* rootValue = NULL;
    const char* sinceStr;
    char request[128] = { 0 };

	for (int i = 0; i < n; i++) {
        if (strcmp(methodName, g_Command_Name[i]) != 0)
        {
            printf("Method name %s is not supported on this component", methodName);
        }
        else if ((contentStr = CopyTwinPayloadToString(payload, size)) == NULL)
        {
            printf("Unable to allocate twin buffer");
        }
        else 
        {
            strcpy(request, contentStr);
            g_Command_Process[i](request,strlen(request), response, responseSize);
        }

	}

    return 200;
}



