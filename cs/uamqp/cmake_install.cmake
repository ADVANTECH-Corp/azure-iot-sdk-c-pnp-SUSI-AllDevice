# Install script for directory: D:/azure-iot-sdk-c/uamqp

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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/uamqp/Debug/uamqp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/uamqp/Release/uamqp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/uamqp/MinSizeRel/uamqp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/uamqp/RelWithDebInfo/uamqp.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/azureiot/azure_uamqp_c" TYPE FILE FILES
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_role.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sender_settle_mode.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_receiver_settle_mode.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_handle.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_seconds.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_milliseconds.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_delivery_tag.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sequence_no.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_delivery_number.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_transfer_number.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_format.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_ietf_language_tag.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_fields.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_error.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_amqp_error.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_connection_error.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_session_error.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_link_error.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_open.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_begin.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_attach.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_flow.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_transfer.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_disposition.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_detach.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_end.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_close.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_code.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_mechanisms.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_init.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_challenge.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_response.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_sasl_outcome.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_terminus_durability.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_terminus_expiry_policy.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_node_properties.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_filter_set.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_source.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_target.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_annotations.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_id_ulong.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_id_uuid.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_id_binary.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_id_string.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_address_string.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_header.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_delivery_annotations.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_message_annotations.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_application_properties.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_data.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_amqp_sequence.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_amqp_value.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_footer.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_properties.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_received.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_accepted.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_rejected.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_released.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions_modified.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_definitions.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_frame_codec.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_management.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqp_types.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqpvalue.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/amqpvalue_to_string.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/async_operation.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/cbs.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/connection.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/frame_codec.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/header_detect_io.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/link.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/message.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/message_receiver.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/message_sender.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/messaging.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_anonymous.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_frame_codec.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_mechanism.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_server_mechanism.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_mssbcbs.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_plain.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/saslclientio.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/sasl_server_io.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/server_protocol_io.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/session.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/socket_listener.h"
    "D:/azure-iot-sdk-c/uamqp/./inc/azure_uamqp_c/uamqp.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/uamqpTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/uamqpTargets.cmake"
         "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/uamqpTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/uamqpTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/uamqp/CMakeFiles/Export/cmake/uamqpTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "D:/azure-iot-sdk-c/uamqp/configs/uamqpConfig.cmake"
    "D:/azure-iot-sdk-c/cs/uamqp/uamqp/uamqpConfigVersion.cmake"
    )
endif()

