# Wi-Fi Core FreeRTOS lwIP mbedtls - Comprehensive Wi-Fi Connectivity Middleware for Infineon MCUs

# Overview

The Wi-Fi Core FreeRTOS lwIP mbedtls library bundles the core components needed for Wi-Fi connectivity support on Infineon platforms. It provides pre-integrated FreeRTOS, lwIP TCP/IP stack, mbed TLS security, Wi-Fi Host Driver (WHD), Wi-Fi Connection Manager (WCM), secure sockets, connectivity utilities, and predefined configuration files, enabling developers to quickly build secure Wi-Fi-connected IoT applications.

This library acts as a convenience bundle in the ModusToolbox&trade; manifest system. When an application includes this library, all dependent middleware libraries are automatically pulled in, simplifying project setup. It also ships predefined configuration files for lwIP and mbed TLS tuned for typical embedded IoT use cases.

Current release: v4.0.0 (see [RELEASE.md](./RELEASE.md) and [version.xml](./version.xml)).

# Features

- **Bundled Wi-Fi connectivity stack:** Integrates WHD, WCM, lwIP (v2.1.2), mbed TLS (v4.2.0), FreeRTOS, secure sockets, and connectivity utilities into a single dependency.
- **TLS 1.2 and TLS 1.3 support:** Supports TLS protocol versions 1.2 and 1.3 through mbed TLS for modern secure communication.
- **Trusted Firmware-M (TF-M) support:** Enables Wi-Fi connectivity with TF-M on CM33 cores for PSA-compliant secure processing environments.
- **Predefined configuration files:** Ships ready-to-use `lwipopts.h`, `mbedtls_user_config.h`, `tf_psa_crypto_config.h`, `tf_psa_crypto_user_config.h` and `ifx_tfm_config.h` for common IoT scenarios.
- **mbed TLS code size tunables:** Configurable mbed TLS options allow users to selectively disable unused features to reduce code footprint on memory-constrained platforms.

# When to Use

Use this library when building Wi-Fi-connected IoT applications on supported Infineon platforms with FreeRTOS. Typical scenarios include:

- Developing cloud-connected IoT devices that require secure (TLS) Wi-Fi communication.
- Building applications that need Wi-Fi station (STA), soft access point (AP), or concurrent AP+STA functionality.
- Projects targeting PSOC&trade; Edge E84 (PSE84) platforms that require a fully integrated Wi-Fi connectivity stack with FreeRTOS and lwIP.
- Applications requiring TF-M-based secure processing with Wi-Fi connectivity on CM33 cores.

# Prerequisites

## Hardware Requirements

This library runs on Infineon Wi-Fi-capable device families:

- **PSOC&trade; 6** with CYW43022 / CYW955513 connectivity
- **XMC7200** with CYW43xxx connectivity
- **PSOC&trade; Edge E84**

See [RELEASE.md](./RELEASE.md) for the specific kits validated in each release.

## Software Requirements

This version of the library was validated for compatibility with the following software and tools:

| Software and tools                                              | Version |
| :---                                                            | :---    |
| ModusToolbox&trade; software environment                        | 3.9     |
| ModusToolbox&trade; Device Configurator                         | 5.90    |
| GCC Compiler                                                    | 14.2.1  |
| IAR Compiler                                                    | 9.50.2  |
| Arm&reg; Compiler 6                                             | 6.22    |
| LLVM compiler                                                   | 22.1.0  |

## Read Documentation First

- [Wi-Fi Connection Manager Reference Manual](https://infineon.github.io/wifi-connection-manager/api_reference_manual/html/index.html) - Primary Wi-Fi connectivity API used with this bundle
- [Secure Sockets Reference Manual](https://infineon.github.io/secure-sockets/api_reference_manual/html/index.html) - Socket API for secure and non-secure communication
- [Connectivity Utilities Reference Manual - for cy-log details](https://Infineon.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html) - Logging utilities

## Choose Starting Template

Create an Empty application in ModusToolbox&trade; (always prefer starting from the Empty template).

## Add Required Libraries

Add the **wifi-core-freertos-lwip-mbedtls** library using the ModusToolbox&trade; **Library Manager** (available in the ModusToolbox&trade; for VS Code extension and the Eclipse IDE), or by creating the `.mtb` file in the application's `deps` folder and running `make getlibs` (applicable for latest-3.X and later):

```
# deps/wifi-core-freertos-lwip-mbedtls.mtb
https://github.com/Infineon/wifi-core-freertos-lwip-mbedtls#latest-v4.X#$$ASSET_REPO$$/wifi-core-freertos-lwip-mbedtls/latest-v4.X
```

The following dependent libraries are automatically pulled in via the ModusToolbox&trade; manifest system:

- [Wi-Fi Host Driver (WHD)](https://github.com/Infineon/wifi-host-driver) - Embedded Wi-Fi host driver for interacting with Infineon WLAN chips
- [FreeRTOS for Infineon MCUs](https://github.com/Infineon/freertos) - FreeRTOS kernel for Infineon MCUs
- [CLib FreeRTOS support library](https://github.com/Infineon/clib-support) - Thread-safe C library hooks for FreeRTOS
- [lwIP](https://savannah.nongnu.org/projects/lwip/) (v2.1.2) - Lightweight open-source TCP/IP stack
- [lwIP FreeRTOS Integration Library](https://github.com/Infineon/lwip-freertos-integration) - FreeRTOS dependencies for lwIP
- [lwIP Network Interface Integration Library](https://github.com/Infineon/lwip-network-interface-integration) - Integration layer linking lwIP with WHD
- [mbed TLS](https://tls.mbed.org/) (v4.2.0) - Portable SSL library with cryptographic capabilities
- [RTOS Abstraction Layer](https://github.com/Infineon/abstraction-rtos) - RTOS-agnostic abstraction APIs for middleware
- [Wi-Fi Connection Manager (WCM)](https://github.com/Infineon/wifi-connection-manager) - Wi-Fi connectivity management APIs
- [Secure Sockets](https://github.com/Infineon/secure-sockets) - Socket-like interface for secure and non-secure communication
- [Connectivity Utilities](https://github.com/Infineon/connectivity-utilities) - General purpose middleware utilities

**Note:**
1. Using this library in a project will cause lwIP to be downloaded on your computer. It is your responsibility to understand and accept the lwIP license.
2. Using this library in a project will cause mbed TLS to be downloaded on your computer. It is your responsibility to understand and accept the mbed TLS license and regional use restrictions (including abiding by all applicable export control laws).
3. mbed TLS hardware crypto acceleration is enabled for the GCC toolchain. For Arm and IAR toolchains it is disabled.

## Configure Makefile

Add the following to your project's Makefile:


1. Enable required COMPONENTS:
```
COMPONENTS=FREERTOS LWIP MBEDTLS
```

2. Add required build defines:
```
# mbed TLS configuration.
DEFINES+=MBEDTLS_USER_CONFIG_FILE='"configs/mbedtls_user_config.h"'

# TF-PSA-Crypto (PSA Crypto API) configuration, required by mbed TLS 4.x.
DEFINES+=IFX_TF_PSA IFX_TF_PSA_CRYPTO
DEFINES+=TF_PSA_CRYPTO_CONFIG_FILE='"configs/tf_psa_crypto_config.h"'
DEFINES+=TF_PSA_CRYPTO_USER_CONFIG_FILE='"configs/tf_psa_crypto_user_config.h"'

DEFINES+=CYBSP_WIFI_CAPABLE
DEFINES+=CY_RTOS_AWARE
```

**Note:** When upgrading to mbed TLS v4.x, the `cy-mbedtls-acceleration` library depends on the `ifx-wolfcrypto` library. `ifx-wolfcrypto` specifies the Makefile configuration settings that must be added to the application to use this dependency. Refer to the [ifx-wolfcrypto compilation instructions](https://github.com/Infineon/ifx-wolfcrypto/tree/latest-v5.X#compiling) for the required settings.


## Add Headers

Copy the following configuration files from the library's `configs` directory to the top-level code example directory in the project:

- `lwipopts.h` - lwIP stack configuration
- `mbedtls_user_config.h` - mbed TLS user configuration

Starting with mbed TLS v4.2.0, also copy the TF-PSA-Crypto configuration files:
- `tf_psa_crypto_config.h` - TF-PSA-Crypto (PSA Crypto API) configuration
- `tf_psa_crypto_user_config.h` - TF-PSA-Crypto user configuration

For TF-M-based applications on PSE84, also copy:
- `ifx_tfm_config.h` - TF-M crypto buffer configuration

# Quick Start

This quick start demonstrates how to set up a Wi-Fi-connected FreeRTOS application with lwIP and mbed TLS from an empty ModusToolbox&trade; project.

**Step 1:** Copy `lwipopts.h` and `mbedtls_user_config.h` files from the `configs` directory to the top-level code example directory in the project.

**Step 2:** Configure the Makefile with the required COMPONENTS and DEFINES:
```
COMPONENTS=FREERTOS LWIP MBEDTLS
DEFINES+=MBEDTLS_USER_CONFIG_FILE='"mbedtls_user_config.h"'
DEFINES+=TF_PSA_CRYPTO_CONFIG_FILE='"tf_psa_crypto_config.h"'
DEFINES+=TF_PSA_CRYPTO_USER_CONFIG_FILE='"tf_psa_crypto_user_config.h"'
DEFINES+=CYBSP_WIFI_CAPABLE
DEFINES+=CY_RTOS_AWARE
```

**Step 3:** (Optional) If your application uses automatic private IP addressing (Auto IP), enable `LWIP_AUTOIP` and `LWIP_DHCP_AUTOIP_COOP` in `lwipopts.h`:
```c
#define AUTOIP 1
#define LWIP_DHCP_AUTOIP_COOP 1
```

**Step 4:** (Optional) Enable logging by adding the following defines to your Makefile and calling `cy_log_init()` in your application:
```
DEFINES+=ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS
DEFINES+=ENABLE_WCM_LOGS
DEFINES+=ENABLE_SECURE_SOCKETS_LOGS
```

**Step 5:** Add the following code to your main.c (see the Sample Code section for the complete example).

**Expected Outcome:** The device connects to a Wi-Fi access point and obtains an IP address via DHCP.

## Sample Code

This section provides a complete, runnable code example demonstrating Wi-Fi connectivity initialization, connection, and event handling using the Wi-Fi Connection Manager (WCM) with FreeRTOS.

### FreeRTOS Example (main.c)

```c
#include <stdio.h>
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy_wcm.h"
#include <FreeRTOS.h>
#include <task.h>

#define WIFI_SSID     "YOUR_SSID"
#define WIFI_PASSWORD "YOUR_PASSWORD"
#define MAX_RETRIES   5

static void event_callback(cy_wcm_event_t event, cy_wcm_event_data_t *event_data)
{
    if (event == CY_WCM_EVENT_DISCONNECTED)
    {
        printf("Wi-Fi disconnected!\n");
    }
    else if (event == CY_WCM_EVENT_CONNECTED)
    {
        printf("Wi-Fi connected!\n");
    }
    else if (event == CY_WCM_EVENT_IP_CHANGED)
    {
        if (event_data->ip_addr.version == CY_WCM_IP_VER_V4)
        {
            uint32_t ip = event_data->ip_addr.ip.v4;
            printf("IP Address: %lu.%lu.%lu.%lu\n",
                   (ip & 0xFF), (ip >> 8) & 0xFF,
                   (ip >> 16) & 0xFF, (ip >> 24) & 0xFF);
        }
    }
}

static void wifi_task(void *arg)
{
    cy_rslt_t result;

    /* Initialize Wi-Fi Connection Manager */
    cy_wcm_config_t config;
    config.interface = CY_WCM_INTERFACE_TYPE_STA;
    result = cy_wcm_init(&config);
    if (result != CY_RSLT_SUCCESS)
    {
        printf("cy_wcm_init failed: 0x%lx\n", (unsigned long)result);
        vTaskDelete(NULL);
        return;
    }

    /* Register event callback */
    cy_wcm_register_event_callback(&event_callback);

    /* Set up connection parameters */
    cy_wcm_connect_params_t connect_params;
    memset(&connect_params, 0, sizeof(cy_wcm_connect_params_t));
    memcpy(connect_params.ap_credentials.SSID, WIFI_SSID, sizeof(WIFI_SSID));
    memcpy(connect_params.ap_credentials.password, WIFI_PASSWORD, sizeof(WIFI_PASSWORD));
    connect_params.ap_credentials.security = CY_WCM_SECURITY_WPA2_AES_PSK;

    /* Connect to the AP with retries */
    cy_wcm_ip_address_t ip_addr;
    for (int retry = 0; retry < MAX_RETRIES; retry++)
    {
        result = cy_wcm_connect_ap(&connect_params, &ip_addr);
        if (result == CY_RSLT_SUCCESS)
        {
            printf("Successfully connected to Wi-Fi AP\n");
            break;
        }
        printf("Connection attempt %d failed, retrying...\n", retry + 1);
        cy_rtos_delay_milliseconds(1000);
    }

    /* Application loop */
    while (1)
    {
        cy_rtos_delay_milliseconds(500);
    }
}

int main(void)
{
    cy_rslt_t result;

    /* Initialize the board support package */
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS)
    {
        return -1;
    }

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io for UART logging */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 115200);

    printf("Wi-Fi Core FreeRTOS lwIP mbedtls Application\n");

    /* Create the Wi-Fi task */
    xTaskCreate(wifi_task, "WiFi_Task", 1024 * 10, NULL, 1, NULL);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    return 0;
}
```

## Expected Outcome

When you successfully run the Quick Start example, you should observe:

- Terminal Output:
```
Wi-Fi Core FreeRTOS lwIP mbedtls Application
Wi-Fi connected!
IP Address: 192.168.1.100
Successfully connected to Wi-Fi AP
```

# Troubleshooting

| Problem | Workaround |
| :------- | :---------- |
| Wi-Fi connection fails or times out. | Verify that the SSID and password are correct, and that the access point is within range. Ensure `CYBSP_WIFI_CAPABLE` is defined in the Makefile. |
| Build errors related to mbed TLS configuration. | Ensure `MBEDTLS_USER_CONFIG_FILE` is correctly defined in the Makefile and that `mbedtls_user_config.h` is copied to the top-level project directory. |
| Missing COMPONENT errors during build. | Ensure `COMPONENTS=FREERTOS LWIP MBEDTLS` is added to the Makefile. |
| Conflicts with lwIP, mbed TLS, or secure sockets test applications. | A `.cyignore` file is included with this library to prevent conflicts. Verify it is present in the project. |

# Related Code Examples

- [ModusToolbox&trade; cloud connectivity code examples](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software)

# Related Application Notes

- [ModusToolbox&trade; software environment, quick start guide, documentation, and videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software)

# Configuration Reference

This section provides comprehensive documentation of all configuration parameters for the library.

## COMPONENT Flags

Add the following to `COMPONENTS` in your Makefile:

| Component   | Description |
| :---        | :---        |
| `FREERTOS`  | Enables FreeRTOS kernel support |
| `LWIP`      | Enables lwIP TCP/IP stack |
| `MBEDTLS`   | Enables mbed TLS security library |

## Build Defines

| Define | Description |
| :---   | :---        |
| `MBEDTLS_USER_CONFIG_FILE='"mbedtls_user_config.h"'` | Points mbed TLS to the user configuration file |
| `CYBSP_WIFI_CAPABLE` | Enables Wi-Fi functionality in BSP |
| `CY_RTOS_AWARE` | Informs HAL that an RTOS environment is being used |
| `ENABLE_CONNECTIVITY_MIDDLEWARE_LOGS` | Enables logs for lwIP network interface integration library |
| `ENABLE_WCM_LOGS` | Enables logs for Wi-Fi Connection Manager library |
| `ENABLE_SECURE_SOCKETS_LOGS` | Enables logs for secure sockets library |

## mbed TLS Code Size Tunables

mbed TLS provides options for users to tune functionality based on their needs via `mbedtls_user_config.h`. The following table lists options that can further reduce overall code size:

| mbed TLS config | Code size saving | Comments |
| :---            | :----            | :----    |
| `#define MBEDTLS_X509_REMOVE_INFO` | ~8K | Omits `mbedtls_x509_*_info()`, `mbedtls_debug_print_crt()` and related functions/constants, reducing code footprint by several KB. |
| `#undef MBEDTLS_ARIA_C` | ~6K | Disables the ARIA ciphers. |
| `#undef MBEDTLS_SSL_SRV_C` | ~16K | Disables server functionality when the application only runs as a secure client. |
| `#undef MBEDTLS_SSL_CLI_C` | ~14K | Disables client functionality when the application only runs as a secure server. |
| `#undef MBEDTLS_CAMELLIA_C` | ~7K | Disables the Camellia block cipher. |

## lwIP Configuration (lwipopts.h)

Key lwIP configuration parameters included in the predefined `lwipopts.h`:

| Parameter | Default | Description |
| :---      | :----  | :---        |
| `LWIP_IPV4` | 1 | Enables IPv4 networking |
| `LWIP_IPV6` | 1 | Enables IPv6 networking |
| `LWIP_TCP` | 1 | Enables TCP protocol |
| `LWIP_UDP` | 1 | Enables UDP protocol |
| `LWIP_ICMP` | 1 | Enables ICMP protocol |
| `LWIP_IGMP` | 1 | Enables IGMP protocol |
| `LWIP_RAW` | 1 | Enables raw API |
| `LWIP_AUTOIP` | Disabled | Enable for automatic private IP addressing |
| `LWIP_DHCP_AUTOIP_COOP` | Disabled | Enable to allow DHCP and AutoIP simultaneously |

# Industry Standards and Compliance

Communication Standards:
- IEEE 802.11 - Wi-Fi wireless networking
- TLS 1.2 / TLS 1.3 - Transport Layer Security protocols
- PSA Certified - Platform Security Architecture compliance (via TF-M support on CM33)

# Release Notes and Changelog

- [RELEASE.md](./RELEASE.md) - Detailed release notes for all versions

# License

This library is subject to Infineon software license terms.

- [LICENSE](./LICENSE.txt)

# Copyright

(c) 2026, Infineon Technologies AG, or an affiliate of Infineon
Technologies AG.  All rights reserved.
