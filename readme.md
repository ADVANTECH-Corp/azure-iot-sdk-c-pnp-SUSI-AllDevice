# Use the code in your device project

Follow the steps to use the code with the Azure IoT Device C SDK source to compile a device app.

For more details about setting up your development environment for compiling the C Device SDK. Check the [instructions](https://github.com/Azure/azure-iot-sdk-c/blob/master/iothub_client/readme.md#compiling-the-c-device-sdk) for each platform.

## Windows

1. Install [Visual Studio](https://www.visualstudio.com/downloads/). You can use the Visual Studio Community Free download if you meet the licensing requirements. (Visual Studio 2015 is also supported.)

    > Be sure to include **Desktop development with C++** and **NuGet Package Manager** from the Visual Studio Installer.

1. Install [git](http://www.git-scm.com/). Confirm git is in your PATH by typing `git version` from a command prompt.

1. Install [CMake](https://cmake.org/). Make sure it is in your PATH by typing `cmake -version` from a command prompt. CMake will be used to create Visual Studio projects to build libraries and samples.

1. Clone the the SDK to your local machine using the `refresh-preview` branch
    ```bash
    git clone --recursive --single-branch --branch refresh-preview git@github.com:ADVANTECH-Corp/azure-iot-sdk-c-pnp-SUSI-AllDevice.git
    ```
    > The `--recursive` argument instructs git to clone other GitHub repos this SDK depends on. Dependencies are listed [here](https://github.com/Azure/azure-iot-sdk-c/blob/master/.gitmodules).

1. In the same **azure-iot-sdk-c-pnp-SUSI-AllDevice** folder, create a folder to contain the compiled app.
    ```bash
    mkdir cmake
    cd cmake
    ```

1. In the **cmake** folder you just created, run CMake to build the entire folder of Device SDK including the generated app code.
    ```bash
    cmake ..
    cmake --build . -- /m /p:Configuration=Release
    ```

1. Once the build has succeeded, you can test it by invoking the following command.
    ```bash
    Release\\PNP_SUSI.exe {model id} {model version} {dps id scope} {dps device id} {dps device key}
    ```

## Ubuntu

1. Make sure all dependencies are installed before building the SDK. For Ubuntu, you can use apt-get to install the right packages.
    ```bash
    sudo apt-get update
    sudo apt-get install -y git cmake build-essential curl libcurl4-openssl-dev libssl-dev uuid-dev
    ```

1. Verify that **CMake** is at least version **2.8.12** and **gcc** is at least version **4.4.7**.
    ```bash
    cmake --version
    gcc --version
    ```

1. Clone the preview release of the SDK to your local machine using the `refresh-preview` branch
    ```bash
    git clone --recursive --single-branch --branch refresh-preview git@github.com:ADVANTECH-Corp/azure-iot-sdk-c-pnp-SUSI-AllDevice.git
    ```
    > The `--recursive` argument instructs git to clone other GitHub repos this SDK depends on. Dependencies are listed [here](https://github.com/Azure/azure-iot-sdk-c/blob/master/.gitmodules).

1. In the same **azure-iot-sdk-c-pnp-SUSI-AllDevice** folder, create a folder to contain the compiled app.
    ```bash
    mkdir cmake
    cd cmake
    ```

1. In the **cmake** folder you just created, run CMake to build the entire folder of Device SDK including the generated app code.
    ```bash
    cmake ..
    cmake --build .
    ```

1. Once the build has succeeded, you can test it by invoking the following command.
    ```bash
    ./Release/PNP_SUSI {model id} {model version} {dps id scope} {dps device id} {dps device key}
    ```