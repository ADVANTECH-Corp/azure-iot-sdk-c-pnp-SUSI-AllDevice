# Install script for directory: D:/azure-iot-sdk-c/serializer

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/azure_iot_sdks")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/azureiot" TYPE FILE FILES
    "D:/azure-iot-sdk-c/serializer/./inc/agenttypesystem.h"
    "D:/azure-iot-sdk-c/serializer/./inc/codefirst.h"
    "D:/azure-iot-sdk-c/serializer/./inc/commanddecoder.h"
    "D:/azure-iot-sdk-c/serializer/./inc/datamarshaller.h"
    "D:/azure-iot-sdk-c/serializer/./inc/datapublisher.h"
    "D:/azure-iot-sdk-c/serializer/./inc/dataserializer.h"
    "D:/azure-iot-sdk-c/serializer/./inc/iotdevice.h"
    "D:/azure-iot-sdk-c/serializer/./inc/jsondecoder.h"
    "D:/azure-iot-sdk-c/serializer/./inc/jsonencoder.h"
    "D:/azure-iot-sdk-c/serializer/./inc/multitree.h"
    "D:/azure-iot-sdk-c/serializer/./inc/schema.h"
    "D:/azure-iot-sdk-c/serializer/./inc/schemalib.h"
    "D:/azure-iot-sdk-c/serializer/./inc/schemaserializer.h"
    "D:/azure-iot-sdk-c/serializer/./inc/serializer.h"
    "D:/azure-iot-sdk-c/serializer/./inc/serializer_devicetwin.h"
    "D:/azure-iot-sdk-c/serializer/./inc/methodreturn.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/serializer/Debug/serializer.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/serializer/Release/serializer.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/serializer/MinSizeRel/serializer.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/serializer/RelWithDebInfo/serializer.lib")
  endif()
endif()

