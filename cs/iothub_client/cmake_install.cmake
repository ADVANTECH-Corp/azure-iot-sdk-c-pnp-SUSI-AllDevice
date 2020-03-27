# Install script for directory: D:/azure-iot-sdk-c/iothub_client

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
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_core.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_core_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_core_common.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_diagnostic.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_internal_consts.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_options.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_private.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_version.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_device_client.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_device_client_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_client_streaming.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_module_client.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_module_client_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_transport_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_message.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/blob.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_ll_uploadtoblob.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_hsm_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_authorization.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_retry_control.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_transport_ll_private.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothubtransporthttp.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothub_transport_ll.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_authorization.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_retry_control.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_transport_ll_private.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_common.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_device.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_cbs_auth.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_connection.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_telemetry_messenger.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_twin_messenger.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_messenger.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_amqp_streaming.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransportamqp_methods.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/message_queue.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/uamqp_messaging.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothubtransportamqp.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothubtransportamqp_websockets.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_authorization.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_retry_control.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_transport_ll_private.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_mqtt_common.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothubtransportmqtt.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_authorization.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_client_retry_control.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothub_transport_ll_private.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/internal/iothubtransport_mqtt_common.h"
    "D:/azure-iot-sdk-c/iothub_client/./inc/iothubtransportmqtt_websockets.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client_http_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client_http_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client_http_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client_http_transport.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client_amqp_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client_amqp_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client_amqp_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client_amqp_transport.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client_amqp_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client_amqp_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client_amqp_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client_amqp_ws_transport.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client_mqtt_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client_mqtt_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client_mqtt_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client_mqtt_transport.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Debug/iothub_client_mqtt_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/Release/iothub_client_mqtt_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/MinSizeRel/iothub_client_mqtt_ws_transport.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/iothub_client/RelWithDebInfo/iothub_client_mqtt_ws_transport.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/azure-iot-sdk-c/cs/iothub_client/tests/cmake_install.cmake")

endif()

