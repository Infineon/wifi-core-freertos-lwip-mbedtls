/*****************************************************************************
* \file ifx_psa_crypto_config.h
*
* \brief
*  PSA crypto configuration options.
*
********************************************************************************
*  Copyright The Mbed TLS Contributors

* Copyright (C) 2022 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may
* not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef PSA_CRYPTO_CONFIG_H
#define PSA_CRYPTO_CONFIG_H

/*
 * CBC-MAC is not yet supported via the PSA API in Mbed TLS.
 */
//#define PSA_WANT_ALG_CBC_MAC                    1
#define PSA_WANT_ALG_CBC_NO_PADDING             1
#define MBEDTLS_PSA_ACCEL_ALG_CBC_NO_PADDING

#define PSA_WANT_ALG_CCM                        1
#define MBEDTLS_PSA_ACCEL_ALG_CCM

#define PSA_WANT_ALG_CMAC                       1
#define MBEDTLS_PSA_ACCEL_ALG_CMAC

#define PSA_WANT_ALG_CFB                        1
#define MBEDTLS_PSA_ACCEL_ALG_CFB

#define PSA_WANT_ALG_CTR                        1
#define MBEDTLS_PSA_ACCEL_ALG_CTR

#define PSA_WANT_ALG_ECB_NO_PADDING             1

#define PSA_WANT_ALG_ECDH                       1

#define PSA_WANT_ALG_ECDSA                      1
#define MBEDTLS_PSA_ACCEL_ALG_ECDSA

#define PSA_WANT_ALG_GCM                        1
#define MBEDTLS_PSA_ACCEL_ALG_GCM

#define PSA_WANT_ALG_HMAC                       1
#define MBEDTLS_PSA_ACCEL_ALG_HMAC

#define PSA_WANT_ALG_RSA_OAEP                   1
#define MBEDTLS_PSA_ACCEL_ALG_RSA_OAEP

#define PSA_WANT_ALG_RSA_PKCS1V15_CRYPT         1
#define MBEDTLS_PSA_ACCEL_ALG_RSA_PKCS1V15_CRYPT
#define PSA_WANT_ALG_RSA_PKCS1V15_SIGN          1
//#define MBEDTLS_PSA_ACCEL_ALG_RSA_PKCS1V15_SIGN

#define PSA_WANT_ALG_SHA_1                      1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_1
#define PSA_WANT_ALG_SHA_224                    1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_224
#define PSA_WANT_ALG_SHA_256                    1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_256
#define PSA_WANT_ALG_SHA_384                    1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_384
#define PSA_WANT_ALG_SHA_512                    1
#define MBEDTLS_PSA_ACCEL_ALG_SHA_512
#define PSA_WANT_ALG_SHA3_224                   1
#define MBEDTLS_PSA_ACCEL_ALG_SHA3_224
#define PSA_WANT_ALG_SHA3_256                   1
#define MBEDTLS_PSA_ACCEL_ALG_SHA3_256
#define PSA_WANT_ALG_SHA3_384                   1
#define MBEDTLS_PSA_ACCEL_ALG_SHA3_384
#define PSA_WANT_ALG_SHA3_512                   1
#define MBEDTLS_PSA_ACCEL_ALG_SHA3_512

#define PSA_WANT_KEY_TYPE_HMAC                  1
#define PSA_WANT_KEY_TYPE_AES                   1
#define MBEDTLS_PSA_ACCEL_KEY_TYPE_AES

#define PSA_WANT_ECC_SECP_R1_192                1
#define PSA_WANT_ECC_SECP_R1_224                1
/* For secp256r1, consider enabling #MBEDTLS_PSA_P256M_DRIVER_ENABLED
 * (see the description in mbedtls/mbedtls_config.h for details). */
//#define PSA_WANT_ECC_SECP_R1_256                1
#define PSA_WANT_ECC_SECP_R1_384                1
#define PSA_WANT_ECC_SECP_R1_521                1


/* Not supported through mbedtls acceleration */
#define PSA_WANT_ALG_FFDH                       1
#define PSA_WANT_ALG_DETERMINISTIC_ECDSA        1
#define PSA_WANT_ALG_CHACHA20_POLY1305          1
#define PSA_WANT_ALG_CCM_STAR_NO_TAG            1
#define PSA_WANT_ALG_JPAKE                      1
#define PSA_WANT_ALG_HKDF                       1
#define PSA_WANT_ALG_HKDF_EXTRACT               1
#define PSA_WANT_ALG_HKDF_EXPAND                1
#define PSA_WANT_ALG_MD5                        1
#define PSA_WANT_ALG_OFB                        1
#define PSA_WANT_ALG_PBKDF2_HMAC                1
#define PSA_WANT_ALG_PBKDF2_AES_CMAC_PRF_128    1
#define PSA_WANT_ALG_RIPEMD160                  1
#define PSA_WANT_ALG_RSA_PSS                    1
#define PSA_WANT_ALG_STREAM_CIPHER              1
#define PSA_WANT_ALG_TLS12_PRF                  1
#define PSA_WANT_ALG_TLS12_PSK_TO_MS            1
#define PSA_WANT_ALG_TLS12_ECJPAKE_TO_PMS       1
/* XTS is not yet supported via the PSA API in Mbed TLS.
 * Note: when adding support, also adjust include/mbedtls/config_psa.h */
//#define PSA_WANT_ALG_XTS                        1
#define PSA_WANT_ECC_BRAINPOOL_P_R1_256         1
#define PSA_WANT_ECC_BRAINPOOL_P_R1_384         1
#define PSA_WANT_ECC_BRAINPOOL_P_R1_512         1
#define PSA_WANT_ECC_MONTGOMERY_255             1
#define PSA_WANT_ECC_MONTGOMERY_448             1
#define PSA_WANT_ECC_SECP_K1_192                1
/*
 * SECP224K1 is buggy via the PSA API in Mbed TLS
 * (https://github.com/Mbed-TLS/mbedtls/issues/3541). Thus, do not enable it by
 * default.
 */
//#define PSA_WANT_ECC_SECP_K1_224                1
#define PSA_WANT_ECC_SECP_K1_256                1
#define PSA_WANT_KEY_TYPE_ARIA                  1
#define PSA_WANT_KEY_TYPE_CAMELLIA              1
#define PSA_WANT_KEY_TYPE_CHACHA20              1
#define PSA_WANT_KEY_TYPE_DES                   1

#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY          1
#define PSA_WANT_KEY_TYPE_DH_PUBLIC_KEY         1
#define PSA_WANT_KEY_TYPE_RAW_DATA              1
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY           1
/*
 * The following symbols extend and deprecate the legacy
 * PSA_WANT_KEY_TYPE_xxx_KEY_PAIR ones. They include the usage of that key in
 * the name's suffix. "_USE" is the most generic and it can be used to describe
 * a generic suport, whereas other ones add more features on top of that and
 * they are more specific.
 */
/* Either all the PSA acceleration for ECC key pair should be enabled or all should be disabled
 * Since crypto acceleration driver doesnt support import key operation. Disabling all the ECC
 * key pair operations and using the software.
 */
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC             1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_IMPORT            1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_EXPORT             1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE           1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_DERIVE             1

#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC              1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT             1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_EXPORT             1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE           1

#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_BASIC       1
#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_IMPORT    1
#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_EXPORT    1
#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_GENERATE  1
//#define PSA_WANT_KEY_TYPE_DH_KEY_PAIR_DERIVE    1 /* Not supported */

#endif /* PSA_CRYPTO_CONFIG_H */
