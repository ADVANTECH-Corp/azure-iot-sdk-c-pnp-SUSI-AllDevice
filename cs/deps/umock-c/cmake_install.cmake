# Install script for directory: D:/azure-iot-sdk-c/deps/umock-c

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/Debug/umock_c.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/Release/umock_c.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/MinSizeRel/umock_c.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/RelWithDebInfo/umock_c.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/umock_c" TYPE FILE FILES
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umock_c.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umock_c_internal.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umock_c_negative_tests.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umock_c_prod.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockalloc.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockcall.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockcallrecorder.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypename.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypes.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypes_bool.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypes_c.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypes_stdint.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umocktypes_charptr.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockcallpairs.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockstring.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umockautoignoreargs.h"
    "D:/azure-iot-sdk-c/deps/umock-c/./inc/umock_c/umock_log.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/umock_cTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/umock_cTargets.cmake"
         "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/umock_cTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/umock_cTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/azure-iot-sdk-c/cs/deps/umock-c/CMakeFiles/Export/cmake/umock_cTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "D:/azure-iot-sdk-c/deps/umock-c/configs/umock_cFunctions.cmake"
    "D:/azure-iot-sdk-c/deps/umock-c/configs/umock_cConfig.cmake"
    "D:/azure-iot-sdk-c/cs/deps/umock-c/umock_c/umock_cConfigVersion.cmake"
    )
endif()

