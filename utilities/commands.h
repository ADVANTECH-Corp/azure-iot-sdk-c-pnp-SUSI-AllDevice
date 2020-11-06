#ifndef __COMMAND__
#define __COMMAND__

int Command_Parser_All(const char* methodName, const unsigned char* payload, size_t size, unsigned char** response, size_t* responseSize);

#endif