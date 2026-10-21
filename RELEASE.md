# Wi-Fi Core FreeRTOS lwIP mbedtls library

## What's included?

See the [README.md](./README.md) for a complete description of the [Wi-Fi Core FreeRTOS lwIP mbedtls](https://github.com/Infineon/wifi-core-freertos-lwip-mbedtls) library.

## Known issues
| Problem | Workaround |
| :--- | :--- |
| IAR 9.30 toolchain throws build errors on Debug mode, if application explicitly includes iar_dlmalloc.h file. | Add '--advance-heap' to LDFLAGS in application Makefile. |

## Changelog

### v4.0.0

- Added support for Mbed TLS version 4.2.0
- Documentation updates to make documentation AI-friendly, minor fixes for the assets to make them Hobsification-compatible and minor code update.

### v3.1.2

- Supports Mbed TLS version 3.6.6

### v3.1.1

- Minor bug fix.

### v3.1.0
- Added Trusted Firmware-M (TF-M) support for WiFi connectivity on CM33

### v3.0.0

- Added support for PSOC™ Edge E84 (PSE84) platform.
- Enabled LLVM_ARM toolchain support.

### v2.2.2

- Minor bug fix.

### v2.2.1

- Enabled Mbedtls acceleration with D-cache on XMC7200 devices.

### v2.2.0

- Added support for D-cache enablement on XMC7200 devices.

### v2.1.0

- Added support for CY8CEVAL-062S2-CYW955513SDM2WLIPA kit

### v2.0.0

- Supports TLS protocol version 1.3
- Supports Mbed TLS version 3.4.0
- Added support for CY8CEVAL-062S2-CYW43022CUB kit

### v1.1.0

- Added support for KIT_XMC72_EVK_MUR_43439M2 kit

### v1.0.0

- Initial release for Wi-Fi Core FreeRTOS lwIP mbedtls library
- Provides the configuration files for lwIP network stack and mbedTLS security stack.

