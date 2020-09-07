#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

#this is CMakeLists.txt for PNP_SUSI
project("PNP_SUSI")
#Compile As C99
if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
        set (CMAKE_C_FLAGS "--std=c99 /DWIN32 /D_WINDOWS /W3")
        if (NOT IN_OPENWRT)
            set (CMAKE_CXX_FLAGS "--std=c++11 /DWIN32 /D_WINDOWS /W3 /GR /EHsc")
        endif()
    endif()
else()
    set (CMAKE_C_STANDARD 99)
    set (CMAKE_CXX_STANDARD 11)
endif()

cmake_minimum_required(VERSION 2.8)
file(GLOB PNP_SUSI_h_files
    "./*.h"
	"./utilities/*.h"
)

file(GLOB PNP_SUSI_c_files
    "./*.c"
	"./utilities/*.c"
)

# Add source code from azure-iot-sdk-c as a subdirectory
set(skip_samples ON CACHE BOOL "set skip_samples to ON to skip building samples (default is OFF)[if possible, they are always build]")
set(hsm_type_symm_key ON CACHE BOOL "Symmetric key type of hsm used with the Provisioning client")
set(use_prov_client ON CACHE BOOL "Enable provisioning client")
add_subdirectory(azure-iot-sdk-c)



include_directories(. ./utilities ./SUSI4/include)
include_directories(
${azure_iot_sdks_SOURCE_DIR}/deps/parson 
${azure_iot_sdks_SOURCE_DIR}/iothub_client/samples/pnp/common
${azure_iot_sdks_SOURCE_DIR}/provisioning_client/inc
${MQTT_INC_FOLDER} 
${SHARED_UTIL_INC_FOLDER} 
${UMOCK_C_INC_FOLDER} 
${MACRO_UTILS_INC_FOLDER} 
${IOTHUB_CLIENT_INC_FOLDER} 
${DIGITALTWIN_CLIENT_INC_FOLDER} 
${DEV_AUTH_MODULES_CLIENT_INC_FOLDER}
)

add_definitions(-DUSE_PROV_MODULE_FULL)
add_executable(PNP_SUSI ${PNP_SUSI_c_files} ${PNP_SUSI_h_files} ${azure_iot_sdks_SOURCE_DIR}/iothub_client/samples/pnp/common/pnp_dps_ll.c)
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT "PNP_SUSI") 

target_link_libraries(PNP_SUSI
iothub_client_mqtt_transport
iothub_client_mqtt_ws_transport
umqtt
iothub_client
prov_device_ll_client
prov_mqtt_transport
iothub_client_http_transport
iothub_client_amqp_transport
iothub_client_amqp_ws_transport
parson
prov_auth_client
hsm_security_client
aziotsharedutil
${CMAKE_SOURCE_DIR}/SUSI4/lib/x64/Susi4.lib
)
