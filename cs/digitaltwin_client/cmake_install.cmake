# Install script for directory: D:/azure-iot-sdk-c/digitaltwin_client

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
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_client_common.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_client_version.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_device_client.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_device_client_ll.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_interface_client.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/digitaltwin_model_definition.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_interface_private.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_interface_list.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_lock_thread_binding.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_lock_thread_binding_impl.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_lock_thread_binding_stub.h"
    "D:/azure-iot-sdk-c/digitaltwin_client/./inc/internal/dt_raw_interface.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/digitaltwin_client/Debug/digitaltwin_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/digitaltwin_client/Release/digitaltwin_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/digitaltwin_client/MinSizeRel/digitaltwin_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/digitaltwin_client/RelWithDebInfo/digitaltwin_client.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/azure-iot-sdk-c/cs/digitaltwin_client/tests/cmake_install.cmake")

endif()

