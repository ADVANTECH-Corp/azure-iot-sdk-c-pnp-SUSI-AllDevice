# Install script for directory: D:/azure-iot-sdk-c/c-utility

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/c-utility/Debug/aziotsharedutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/c-utility/Release/aziotsharedutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/c-utility/MinSizeRel/aziotsharedutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/c-utility/RelWithDebInfo/aziotsharedutil.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/azureiot/azure_c_shared_utility" TYPE FILE FILES
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/agenttime.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/azure_base32.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/azure_base64.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/buffer_.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/constbuffer_array.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/connection_string_parser.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/crt_abstractions.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/constmap.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/condition.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/const_defines.h"
    "D:/azure-iot-sdk-c/c-utility/inc/azure_c_shared_utility/consolelogger.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/doublylinkedlist.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/envvariable.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/gballoc.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/gbnetwork.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/gb_stdio.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/gb_time.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/gb_rand.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/hmac.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/hmacsha256.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/http_proxy_io.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/singlylinkedlist.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/lock.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/map.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/optimize_size.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/platform.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/refcount.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/sastoken.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/sha-private.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/shared_util_options.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/sha.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/socketio.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/srw_lock.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/stdint_ce6.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/strings.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/strings_types.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/string_token.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/string_tokenizer.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/string_tokenizer_types.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/string_utils.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/tlsio_options.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/tickcounter.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/threadapi.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/xio.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/uniqueid.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/uuid.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/urlencode.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/vector.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/vector_types.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/vector_types_internal.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/xlogging.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/constbuffer.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/tlsio.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/optionhandler.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/memory_data.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/wsio.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/uws_client.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/uws_frame_encoder.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/utf8_checker.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/ws_url.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/httpapi.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/httpapiex.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/httpapiexsas.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/httpheaders.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/tlsio_schannel.h"
    "D:/azure-iot-sdk-c/c-utility/./inc/azure_c_shared_utility/x509_schannel.h"
    "D:/azure-iot-sdk-c/c-utility/./pal/windows/refcount_os.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/azure_c_shared_utilityTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/azure_c_shared_utilityTargets.cmake"
         "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/azure_c_shared_utilityTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/azure_c_shared_utilityTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/c-utility/CMakeFiles/Export/cmake/azure_c_shared_utilityTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "D:/azure-iot-sdk-c/c-utility/configs/azure_c_shared_utilityConfig.cmake"
    "D:/azure-iot-sdk-c/c-utility/configs/azure_c_shared_utilityFunctions.cmake"
    "D:/azure-iot-sdk-c/c-utility/configs/azure_iot_build_rules.cmake"
    "D:/azure-iot-sdk-c/cs/c-utility/azure_c_shared_utility/azure_c_shared_utilityConfigVersion.cmake"
    )
endif()

