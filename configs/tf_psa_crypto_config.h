/**
 * \file tf_psa_crypto_config.h
 *
 * PSA algorithm configuration for TF-PSA-Crypto 1.0
 * Target: PSVP-EXPLORER_B0 (PSE84 / CAT1D) with MXCRYPTO hardware accelerator
 *
 * MXCRYPTO capabilities:
 *   - Hash:   SHA-1/224/256/384/512 HW
 *   - HMAC:   HW
 *   - CMAC:   HW (via AES)
 *   - Cipher: AES-ECB/CBC/CFB/CTR/GCM HW
 *   - AEAD:   AES-CCM/GCM HW
 *   - ECDSA:  HW (secp256/384/521 r1)
 *   - ECDH:   HW
 *   - RSA:    SW only
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */
/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */

#ifndef TF_PSA_CRYPTO_CONFIG_H
#define TF_PSA_CRYPTO_CONFIG_H

#include <limits.h>

/* Currently there is a bug with MBEDTLS 3.4.0 compilation with IAR compiler when assembly instructions are enabled. Hence
 * disabling assembly instructions for IAR. This will be fixed in future MBEDTLS releases.
 */
#if defined (__IAR_SYSTEMS_ICC__)
#undef MBEDTLS_HAVE_ASM
#endif

/* ---- PSA Crypto core ---- */
#define MBEDTLS_PSA_CRYPTO_C
#if !defined(CY_TFM_PSA_SUPPORTED) && !defined(COMPONENT_SECURE_DEVICE)
#define MBEDTLS_PSA_CRYPTO_DRIVERS
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG
#define MBEDTLS_PSA_DRIVER_GET_ENTROPY
#endif
#define MBEDTLS_PSA_CRYPTO_CONFIG

/* ---- Platform ---- */
/**
 * \def MBEDTLS_HAVE_TIME
 *
 * System has time.h and time().
 * The time does not need to be correct, only time differences are used,
 * by contrast with MBEDTLS_HAVE_TIME_DATE
 *
 * Defining MBEDTLS_HAVE_TIME allows you to specify MBEDTLS_PLATFORM_TIME_ALT,
 * MBEDTLS_PLATFORM_TIME_MACRO, MBEDTLS_PLATFORM_TIME_TYPE_MACRO and
 * MBEDTLS_PLATFORM_STD_TIME.
 *
 * Comment if your system does not support time functions.
 */
#define MBEDTLS_HAVE_TIME


/**
 * \def MBEDTLS_PLATFORM_C
 *
 * Enable the platform abstraction layer that allows you to re-assign
 * functions like calloc(), free(), snprintf(), printf(), fprintf(), exit().
 *
 * Enabling MBEDTLS_PLATFORM_C enables to use of MBEDTLS_PLATFORM_XXX_ALT
 * or MBEDTLS_PLATFORM_XXX_MACRO directives, allowing the functions mentioned
 * above to be specified at runtime or compile time respectively.
 *
 * \note This abstraction layer must be enabled on Windows (including MSYS2)
 * as other modules rely on it for a fixed snprintf implementation.
 *
 * Module:  platform/platform.c
 * Caller:  Most other .c files
 *
 * This module enables abstraction of common (libc) functions.
 */
#define MBEDTLS_PLATFORM_C

#define MBEDTLS_PLATFORM_MS_TIME_ALT

/**
 * \def MBEDTLS_BASE64_C
 *
 * Enable the Base64 module.
 *
 * Module:  utilities/base64.c
 * Caller:  utilities/pem.c
 *
 * This module is required for PEM support (required by X.509).
 */
#define MBEDTLS_BASE64_C

/**
 * \def MBEDTLS_PEM_PARSE_C
 *
 * Enable PEM decoding / parsing.
 *
 * Module:  utilities/pem.c
 * Caller:  extras/pkparse.c
 *
 * Requires: MBEDTLS_BASE64_C
 *           optionally PSA_WANT_ALG_MD5
 *
 * This modules adds support for decoding / parsing PEM files.
 */
#define MBEDTLS_PEM_PARSE_C

/**
 * \def MBEDTLS_PEM_WRITE_C
 *
 * Enable PEM encoding / writing.
 *
 * Module:  utilities/pem.c
 * Caller:  extras/pkwrite.c
 *
 * Requires: MBEDTLS_BASE64_C
 *
 * This modules adds support for encoding / writing PEM files.
 */
#define MBEDTLS_PEM_WRITE_C

#undef MBEDTLS_FS_IO

/* ---- Hash algorithms ---- */
#define PSA_WANT_ALG_SHA_1              1
#define PSA_WANT_ALG_SHA_224            1
#define PSA_WANT_ALG_SHA_256            1
#define PSA_WANT_ALG_SHA_384            1
#define PSA_WANT_ALG_SHA_512            1

/* All SHA variants HW accelerated on MXCRYPTO */
#define MBEDTLS_PSA_ACCEL_ALG_SHA_1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_224
#define MBEDTLS_PSA_ACCEL_ALG_SHA_256
#define MBEDTLS_PSA_ACCEL_ALG_SHA_384
#define MBEDTLS_PSA_ACCEL_ALG_SHA_512

/* ---- Symmetric cipher algorithms ---- */
#define PSA_WANT_ALG_ECB_NO_PADDING     1
#define PSA_WANT_ALG_CBC_NO_PADDING     1
#define PSA_WANT_ALG_CFB                1
#define PSA_WANT_ALG_CTR                1
#define PSA_WANT_ALG_GCM                1
#define PSA_WANT_ALG_CCM                1
#define PSA_WANT_ALG_STREAM_CIPHER      1
#define PSA_WANT_KEY_TYPE_AES           1

/* ChaCha20-Poly1305: no MXCRYPTO dispatch block, so SW builtin */
#define PSA_WANT_ALG_CHACHA20_POLY1305  1
#define PSA_WANT_KEY_TYPE_CHACHA20      1

/* AES cipher modes → dispatched via IFX_PSA_MXCRYPTO_CIPHER */
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES
#define MBEDTLS_PSA_ACCEL_ALG_ECB_NO_PADDING
#define MBEDTLS_PSA_ACCEL_ALG_CBC_NO_PADDING
#define MBEDTLS_PSA_ACCEL_ALG_CFB
#define MBEDTLS_PSA_ACCEL_ALG_CTR
#define MBEDTLS_PSA_ACCEL_ALG_GCM
#define MBEDTLS_PSA_ACCEL_ALG_CCM

/* ---- MAC algorithms ---- */
#define PSA_WANT_ALG_HMAC               1
#define PSA_WANT_ALG_CMAC               1
#define PSA_WANT_KEY_TYPE_HMAC          1
#define PSA_WANT_ALG_PBKDF2_AES_CMAC_PRF_128 1

/* HMAC and CMAC HW accelerated on MXCRYPTO */
#define MBEDTLS_PSA_ACCEL_ALG_HMAC
#define MBEDTLS_PSA_ACCEL_ALG_CMAC

/* ---- RSA algorithms ---- */
/* MXCRYPTO has no PSA dispatch block for RSA → all SW */
#define PSA_WANT_ALG_RSA_PKCS1V15_CRYPT     1
#define PSA_WANT_ALG_RSA_OAEP               1
#define PSA_WANT_ALG_RSA_PKCS1V15_SIGN      1
#define PSA_WANT_ALG_RSA_PSS                1
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY    1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC    1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT   1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_EXPORT   1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE 1
/* No MBEDTLS_PSA_ACCEL_ALG_RSA_* — all RSA uses SW builtin */

/* ---- ECC algorithms ---- */
/* PSA_WANT_ECC_SECP_R1_192/224 removed in TF-PSA-Crypto 1.0 */
#define PSA_WANT_ECC_SECP_R1_256        1
#define PSA_WANT_ECC_SECP_R1_384        1
#define PSA_WANT_ECC_SECP_R1_521        1
#define PSA_WANT_ALG_ECDSA              1
#define PSA_WANT_ALG_ECDH               1
#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY 1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC    1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_IMPORT   1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_EXPORT   1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE 1

/* ---- Legacy ECP arithmetic for WPA3-SAE ---- */
/* WPA3-SAE (Dragonfly) calls mbedtls_ecp_* directly and PSA offers no equivalent.
 * Because every ECC mechanism above is accelerated, crypto_adjust_config_enable_builtins.h
 * leaves MBEDTLS_ECP_C off and ecp.c compiles to an empty object.
 *
 * MBEDTLS_ECP_C and MBEDTLS_ECP_DP_SECP256R1_ENABLED cannot be set here: the build
 * includes tf_psa_crypto_config_check_user.h after this file and it rejects both.
 * PSA_WANT_ALG_JPAKE passes that check, and its branch in the adjust header defines
 * them for us. Side effect: ecjpake.c is built and registered as a PSA builtin, so
 * it survives --gc-sections even though nothing calls it. */
#define PSA_WANT_ALG_JPAKE              1

/* Above the upstream default of 4: buys scalar-multiplication speed for SAE at the
 * cost of a larger comb table. */
#define MBEDTLS_ECP_WINDOW_SIZE         6

/* ECDSA/ECDH HW accelerated on MXCRYPTO */
#define MBEDTLS_PSA_ACCEL_ALG_ECDSA
#define MBEDTLS_PSA_ACCEL_ALG_ECDH
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_256
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_384
#define MBEDTLS_PSA_ACCEL_ECC_SECP_R1_521
#if defined(COMPONENT_SECURE_DEVICE) || defined(CY_TFM_PSA_SUPPORTED)
#define MBEDTLS_PSA_ACCEL_ECC_SECP_K1_256
#endif

// Disabled because cy-mbedtls-acceleration does not implement ECC key-pair import currently; use the software path instead.
// #define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_PUBLIC_KEY
// #define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_BASIC
// #define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_IMPORT
// #define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_EXPORT
// #define MBEDTLS_PSA_ACCEL_KEY_TYPE_ECC_KEY_PAIR_GENERATE
// #define MBEDTLS_PSA_P256M_DRIVER_ENABLED

/* ---- Key derivation ---- */
#define PSA_WANT_ALG_HKDF               1
#define PSA_WANT_ALG_HKDF_EXTRACT       1
#define PSA_WANT_ALG_HKDF_EXPAND        1
#define PSA_WANT_ALG_TLS12_PRF          1
#define PSA_WANT_ALG_TLS12_PSK_TO_MS    1

/* ---- mbedtls compat modules (still valid in TF-PSA-Crypto 1.0) ---- */
/**
 * \def MBEDTLS_MD_C
 *
 * Enable the generic layer for message digest (hashing).
 *
 * Requires: MBEDTLS_PSA_CRYPTO_C with at least one hash.
 * Module:  extras/md.c
 * Caller:  drivers/builtin/src/ecdsa.c
 *          drivers/builtin/src/ecjpake.c
 *          drivers/builtin/src/hmac_drbg.c
 *          drivers/builtin/src/psa_crypto_ecp.c
 *          drivers/builtin/src/psa_crypto_rsa.c
 *          drivers/builtin/src/rsa.c
 *          extras/pk.c
 *          utilities/constant_time.c
 *          utilities/pkcs5.c
 *
 * Uncomment to enable generic message digest wrappers.
 */
#define MBEDTLS_MD_C

/**
 * \def MBEDTLS_NIST_KW_C
 *
 * Enable the 128-bit key wrapping modes from NIST SP 800-38F:
 * KW (also known as RFC 3394) and KWP (RFC 5649).
 * Currently these modes are only supported with AES.
 *
 * Module:  extras/nist_kw.c
 *
 * Auto enables: PSA_WANT_ALG_ECB_NO_PADDING
 */
#define MBEDTLS_NIST_KW_C

/**
 * \def MBEDTLS_PK_C
 *
 * Enable the generic public (asymmetric) key layer.
 *
 * Module:  extras/pk.c
 * Caller:  drivers/builtin/src/psa_crypto_rsa.c
 *
 * Requires: #MBEDTLS_PSA_CRYPTO_CLIENT and at least one between
 *           #PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY and
 *           #PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY.
 *
 * Uncomment to enable generic public key wrappers.
 */
#define MBEDTLS_PK_C

/**
 * \def MBEDTLS_PKCS5_C
 *
 * Enable PKCS#5 functions.
 *
 * Module:  utilities/pkcs5.c
 *
 * Auto-enables: MBEDTLS_MD_C
 *
 * This module adds support for the PKCS#5 functions.
 */
#define MBEDTLS_PKCS5_C

/**
 * \def MBEDTLS_PK_PARSE_C
 *
 * Enable the generic public (asymmetric) key parser.
 *
 * Module:  extras/pkparse.c
 *
 * Requires: MBEDTLS_ASN1_PARSE_C, MBEDTLS_PK_C
 *
 * Uncomment to enable generic public key parse functions.
 */
#define MBEDTLS_PK_PARSE_C

/**
 * \def MBEDTLS_PK_WRITE_C
 *
 * Enable the generic public (asymmetric) key writer.
 *
 * Module:  extras/pkwrite.c
 *
 * Requires: MBEDTLS_ASN1_WRITE_C, MBEDTLS_PK_C
 *
 * Uncomment to enable generic public key write functions.
 */
#define MBEDTLS_PK_WRITE_C

/**
 * \def MBEDTLS_PK_PARSE_EC_COMPRESSED
 *
 * Enable the support for parsing public keys of type Short Weierstrass
 * (PSA_ECC_FAMILY_SECP_XXX and PSA_ECC_FAMILY_BRAINPOOL_XXX) which are using the
 * compressed point format.
 */
#define MBEDTLS_PK_PARSE_EC_COMPRESSED

/**
 * \def MBEDTLS_ASN1_PARSE_C
 *
 * Enable the generic ASN1 parser.
 *
 * Module:  utilities/asn1parse.c
 * Caller:  extras/pkparse.c
 *          utilities/pkcs5.c
 */
#define MBEDTLS_ASN1_PARSE_C

/**
 * \def MBEDTLS_ASN1_WRITE_C
 *
 * Enable the generic ASN1 writer.
 *
 * Module:  utilities/asn1write.c
 * Caller:  drivers/builtin/src/ecdsa.c
 *          extras/pkwrite.c
 */
#define MBEDTLS_ASN1_WRITE_C

/**
 * \def MBEDTLS_CTR_DRBG_C
 *
 * Enable the CTR_DRBG AES-based random generator.
 * The CTR_DRBG generator uses AES-256 by default.
 * To use AES-128 instead, set #MBEDTLS_PSA_CRYPTO_RNG_STRENGTH to 128.
 *
 * AES support can either be achieved through built-in AES or PSA. Built-in is
 * the default option when present otherwise PSA is used.
 *
 * Module:  drivers/builtin/src/ctr_drbg.c
 *
 * Requires: MBEDTLS_PSA_CRYPTO_C, PSA_WANT_KEY_TYPE_AES and
 *           PSA_WANT_ALG_ECB_NO_PADDING
 *
 * This module provides the CTR_DRBG AES random number generator.
 */
#define MBEDTLS_CTR_DRBG_C

/**
 * \def MBEDTLS_HMAC_DRBG_C
 *
 * Enable the HMAC_DRBG random generator.
 *
 * Module:  drivers/builtin/src/hmac_drbg.c
 * Caller:
 *
 * Requires: MBEDTLS_MD_C
 *
 * Uncomment to enable the HMAC_DRBG random number generator.
 */
#define MBEDTLS_HMAC_DRBG_C

/**
 * \def MBEDTLS_PSA_KEY_STORE_DYNAMIC
 *
 * Dynamically resize the PSA key store to accommodate any number of
 * volatile keys (until the heap memory is exhausted).
 *
 * If this option is disabled, the key store has a fixed size
 * #MBEDTLS_PSA_KEY_SLOT_COUNT for volatile keys and loaded persistent keys
 * together.
 *
 * This option has no effect when #MBEDTLS_PSA_CRYPTO_C is disabled.
 *
 * Module:  core/psa_crypto.c
 * Requires: MBEDTLS_PSA_CRYPTO_C
 */
#define MBEDTLS_PSA_KEY_STORE_DYNAMIC

/**
 * \def MBEDTLS_AESCE_C
 *
 * Enable AES cryptographic extension support on Armv8.
 *
 * Module:  drivers/builtin/src/aesce.c
 * Caller:  drivers/builtin/src/aes.c
 *
 * Requires: The AES built-in implementation
 *
 * \warning Runtime detection only works on Linux. For non-Linux operating
 *          system, Armv8-A Cryptographic Extensions must be supported by
 *          the CPU when this option is enabled.
 *
 * \note    Minimum compiler versions for this feature when targeting aarch64
 *          are Clang 4.0; armclang 6.6; GCC 6.0; or MSVC 2019 version 16.11.2.
 *          Minimum compiler versions for this feature when targeting 32-bit
 *          Arm or Thumb are Clang 11.0; armclang 6.20; or GCC 6.0.
 *
 * \note \c CFLAGS must be set to a minimum of \c -march=armv8-a+crypto for
 * armclang <= 6.9
 *
 * This module adds support for the AES Armv8-A Cryptographic Extensions on Armv8 systems.
 */
#define MBEDTLS_AESCE_C

/**
 * \def MBEDTLS_ECP_NIST_OPTIM
 *
 * Enable specific 'modulo p' routines for each NIST prime.
 * Depending on the prime and architecture, makes operations 4 to 8 times
 * faster on the corresponding curve.
 *
 * Comment this macro to disable NIST curves optimisation.
 */
#define MBEDTLS_ECP_NIST_OPTIM

/* ---- IFX HW driver selection ---- */
#define IFX_PSA_MXCRYPTO_PRESENT

#endif /* TF_PSA_CRYPTO_CONFIG_H */
