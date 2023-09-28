# Wi-Fi Core FreeRTOS lwIP mbedtls library

This repo comprises core components needed for Wi-Fi connectivity support. The library bundles FreeRTOS, lwIP TCP/IP stack, mbed TLS for security, Wi-Fi host driver (WHD), wifi connection manager (WCM), secure sockets, connectivity utilities and configuration files.

## Features and functionality

This library provides the configuration files for lwIP network stack and mbedTLS security stack. It also includes following libraries as dependees in the ModusToolbox&trade; manifest system. Using ModusToolbox&trade; manifest system the dependees are automatically pulled when an application uses this library in ModusToolbox&trade; environment.

- **Wi-Fi Host Driver (WHD):** Embedded Wi-Fi host driver that provides a set of APIs to interact with Infineon WLAN chips. See [Wi-Fi host driver (WHD)](https://github.com/Infineon/wifi-host-driver).

- **FreeRTOS for Infineon MCUs:** FreeRTOS kernel, distributed as standard C source files with the configuration header file, for use with the Infineon MCUs. See the
[README](https://github.com/Infineon/freertos/blob/master/README.md) for details.

- **CLib FreeRTOS support library:** This library provides the necessary hooks to make C library functions such as malloc and free thread-safe. This implementation is specific to FreeRTOS; this library is required for building your application. See the [CLib FreeRTOS support library](https://github.com/Infineon/clib-support) web site for details.

- **lwIP:** A lightweight open-source TCP/IP stack, version: 2.1.2. See the [lwIP](https://savannah.nongnu.org/projects/lwip/) web site for details.

   **Note:** Using this library in a project will cause lwIP to be downloaded on your computer. It is your responsibility to understand and accept the lwIP license.

- **lwIP FreeRTOS Integration Library:** This repo contains the FreeRTOS dependencies required by the lwIP stack. See [lwIP FreeRTOS Integration Library](https://github.com/Infineon/lwip-freertos-integration) for details.

- **lwIP Network Interface Integration Library:** This library is an integration layer that links the lwIP network stack with the underlying Wi-Fi host driver (WHD). See [lwIP Network Interface Integration Library](https://github.com/Infineon/lwip-network-interface-integration) for details.

- **mbed TLS:** An open-source, portable, easy-to-use, readable and flexible SSL library that has cryptographic capabilities, version: 2.25.0. See the [mbed TLS](https://tls.mbed.org/) web site for details.

   **Note:** Using this library in a project will cause mbed TLS to be downloaded on your computer. It is your responsibility to understand and accept the mbed TLS license and regional use restrictions (including abiding by all applicable export control laws).

- **RTOS Abstraction Layer:** The RTOS abstraction APIs allow the middleware to be written to be RTOS-aware, but without depending on any particular RTOS. See [RTOS Abstraction Layer](https://github.com/Infineon/abstraction-rtos) repository for details.

- **Wi-Fi Connection Manager (WCM):** WCM is a library which helps application developers to manage Wi-Fi Connectivity. The library provides a set of APIs that can be used to establish and monitor Wi-Fi connections on Infineon platforms that support Wi-Fi connectivity. See the [Wi-Fi Connection Manager ](https://github.com/Infineon/wifi-connection-manager) repository for details.

- **Secure Sockets:** Network abstraction APIs for the underlying lwIP network stack and mbed TLS security library. The secure sockets library eases application development by exposing a socket-like interface for both secure and non-secure socket communication. See the [Secure Sockets](https://github.com/Infineon/secure-sockets) repository for details.

- **Connectivity Utilities:** The connectivity utilities library is a collection of general purpose middleware utilities. See the [Connectivity Utilities](https://github.com/Infineon/connectivity-utilities) repository for details.

- **Predefined configuration files:** For FreeRTOS, lwIP, and mbed TLS for typical embedded IoT use cases. See **Quick Start** section for details.

## Supported platforms

This library and its features are supported on the following PSoC&trade; 6 platforms:

- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; prototyping kit  (CY8CPROTO-062-4343W)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8cproto-062-4343w/)

- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; pioneer kit (CY8CKIT-062S2-43012)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-062s2-43012/)

- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; pioneer kit (CY8CKIT-062-WiFi-BT)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-062-wifi-bt/)

- [PSoC&trade; 64S0S2 Wi-Fi Bluetooth&reg; pioneer kit (CY8CKIT-064S0S2-4343W)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-064s0s2-4343w/)

- [PSoC&trade; 62S2 evaluation kit (CY8CEVAL-062S2-LAI-4373M2)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ceval-062s2/)

- [CYW954907AEVAL1F evaluation kit (CYW954907AEVAL1F)](https://www.infineon.com/cms/en/product/evaluation-boards/cyw954907aeval1f/)

- [CYW943907AEVAL1F Evaluation Kit (CYW943907AEVAL1F)](https://www.infineon.com/cms/en/product/evaluation-boards/cyw943907aeval1f/)

- [PSoC&trade; 62S2 evaluation kit (CY8CEVAL-062S2-MUR-43439M2)](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ceval-062s2/)

- [XMC7200D-E272K8384 kit (KIT_XMC72_EVK_MUR_43439M2)](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc72_evk/)

## Quick start

A set of pre-defined configuration files have been bundled with this library for lwIP, and mbed TLS. These files are located in the configs folder.

You should do the following:

1. Copy *lwipopts.h*, and *mbedtls_user_config.h* files from the *configs* directory to the top-level code example directory in the project. This ensures that all the latest configuration changes are updated in the code example as well.

2. Configure the `MBEDTLS_USER_CONFIG_FILE` C macro to mbedtls_user_config.h in the Makefile to provide the user configuration to the mbed TLS library. The Makefile entry should look like as follows:

    ```
    DEFINES+=MBEDTLS_USER_CONFIG_FILE='"mbedtls_user_config.h"'
    ```

3. Add the `CYBSP_WIFI_CAPABLE` build configuration to enable the Wi-Fi functionality. The Makefile entry should look like as follows:

    ```
    DEFINES+=CYBSP_WIFI_CAPABLE
    ```

4. Add the `CY_RTOS_AWARE` build configuration to inform the HAL that an RTOS environment is being used. The Makefile entry should look like as follows:

    ```
    DEFINES+=CY_RTOS_AWARE
    ```

5. If your application uses automatic private IP addressing (Auto IP), enable `LWIP_AUTOIP` and `LWIP_DHCP_AUTOIP_COOP` in *lwipopts.h* like as follows:

    ```
    #define AUTOIP 1
    #define LWIP_DHCP_AUTOIP_COOP 1
    ```

6. Add the following to `COMPONENTS` in the code example project's Makefile: `FREERTOS`, `LWIP`, and `MBEDTLS`.

    For example:

    ```
    COMPONENTS=FREERTOS LWIP MBEDTLS
    ```
7. All the log messages are disabled by default. Do the following to enable log messages:

   1. Add the `ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS` macro to the *DEFINES* in the code example's Makefile to enable logs for lwIP network interface integration library. The Makefile entry should look like as follows:
       ```
       DEFINES+=ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS
       ```

   2. Add the `ENABLE_WCM_LOGS` macro to the *DEFINES* in the code example's Makefile to enable logs for wifi connection manager library. The Makefile entry should look like as follows:
       ```
       DEFINES+=ENABLE_WCM_LOGS
       ```

   3. Add the `ENABLE_SECURE_SOCKETS_LOGS` macro to the *DEFINES* in the code example's Makefile to enable logs for secure sockets library. The Makefile entry should look like as follows:
       ```
       DEFINES+=ENABLE_SECURE_SOCKETS_LOGS
       ```

   4. Call the `cy_log_init()` function provided by the *cy-log* module. cy-log is part of the *connectivity-utilities* library. See [connectivity-utilities library API documentation](https://infineon.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html) for cy-log details.

Secure sockets, lwIP, and mbed TLS libraries contain reference and test applications. To ensure that these applications do not conflict with the code examples, a *.cyignore* file is also included with this library.

## Additional information

- [Wi-Fi Core FreeRTOS lwIP mbedtls RELEASE.md](./RELEASE.md)

- [Connectivity Utilities API documentation - for cy-log details](https://Infineon.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html)

- [ModusToolbox&trade; software environment, quick start guide, documentation, and videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software)

- [Wi-Fi Core FreeRTOS lwIP mbedtls version](./version.xml)

- [ModusToolbox&trade; cloud connectivity code examples](https://github.com/Infineon?q=mtb-example-anycloud%20NOT%20Deprecated)
