# Install script for directory: D:/azure-iot-sdk-c/provisioning_client/deps/utpm

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/Debug/utpm.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/Release/utpm.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/MinSizeRel/utpm.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/RelWithDebInfo/utpm.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/azureiot/azure_utpm_c" TYPE FILE FILES
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/BaseTypes.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/Capabilities.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/CompilerDependencies.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/GpMacros.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/gbfiledescript.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/Implementation.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/Marshal_fp.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/Memory_fp.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/swap.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/Tpm.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/TPMB.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/TpmBuildSwitches.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/TpmError.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/TpmTypes.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/tpm_codec.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/tpm_comm.h"
    "D:/azure-iot-sdk-c/provisioning_client/deps/utpm/./inc/azure_utpm_c/gbfiledescript.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/utpmTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/utpmTargets.cmake"
         "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/utpmTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/utpmTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/CMakeFiles/Export/cmake/utpmTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/provisioning_client/deps/utpm/utpm/utpmConfigVersion.cmake")
endif()

