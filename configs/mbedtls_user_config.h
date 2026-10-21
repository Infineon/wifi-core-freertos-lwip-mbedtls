/**
 * \file config.h
 *
 * \brief Configuration options (set of defines)
 *
 *  This set of compile-time options may be used to enable
 *  or disable features selectively, and reduce the global
 *  memory footprint.
 */
/*
 *  Copyright (C) 2006-2018, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

#ifndef MBEDTLS_USER_CONFIG_HEADER
#define MBEDTLS_USER_CONFIG_HEADER

#if !defined(COMPONENT_4390X)
#include "cy_syslib.h"
#endif

/**
 * Compiling Mbed TLS for Cortex-M0/0+/1/M23 cores with optimization enabled and on ARMC6 compiler results in errors. 
 * These cores lack the required full Thumb-2 support, causing the inline assembly to require more registers than available.
 * The workaround is to use 'MULADDC_CANNOT_USE_R7' compilation flag, or without optimization flag, 
 * but note that this will compile without the assmebly optimization.
 *
 * To read more about this issue, refer to https://github.com/ARMmbed/mbed-os/pull/14529/commits/86e7bc559b0d1a055bf84ea9249763d2349fb6e8
 */

#if defined(COMPONENT_CM0P) && defined(COMPONENT_ARM)
#define MULADDC_CANNOT_USE_R7
#endif

/**
 * \def MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
 *
 * Enable the PSK based ciphersuite modes in SSL / TLS.
 *
 * This enables the following ciphersuites (if other requisites are
 * enabled as well):
 *      MBEDTLS_TLS_PSK_WITH_AES_256_GCM_SHA384
 *      MBEDTLS_TLS_PSK_WITH_AES_256_CBC_SHA384
 *      MBEDTLS_TLS_PSK_WITH_AES_256_CBC_SHA
 *      MBEDTLS_TLS_PSK_WITH_CAMELLIA_256_GCM_SHA384
 *      MBEDTLS_TLS_PSK_WITH_CAMELLIA_256_CBC_SHA384
 *      MBEDTLS_TLS_PSK_WITH_AES_128_GCM_SHA256
 *      MBEDTLS_TLS_PSK_WITH_AES_128_CBC_SHA256
 *      MBEDTLS_TLS_PSK_WITH_AES_128_CBC_SHA
 *      MBEDTLS_TLS_PSK_WITH_CAMELLIA_128_GCM_SHA256
 *      MBEDTLS_TLS_PSK_WITH_CAMELLIA_128_CBC_SHA256
 *      MBEDTLS_TLS_PSK_WITH_3DES_EDE_CBC_SHA
 *      MBEDTLS_TLS_PSK_WITH_RC4_128_SHA
 */
#undef MBEDTLS_KEY_EXCHANGE_PSK_ENABLED

/**
 * \def MBEDTLS_NO_PLATFORM_ENTROPY
 *
 * Do not use built-in platform entropy functions.
 * This is useful if your platform does not support
 * standards like the /dev/urandom or Windows CryptoAPI.
 *
 * Uncomment this macro to disable the built-in platform entropy functions.
 */
#define MBEDTLS_NO_PLATFORM_ENTROPY

/**
 * \def MBEDTLS_ENTROPY_FORCE_SHA256
 *
 * Force the entropy accumulator to use a SHA-256 accumulator instead of the
 * default SHA-512 based one (if both are available).
 *
 * Requires: MBEDTLS_SHA256_C
 *
 * On 32-bit systems SHA-256 can be much faster than SHA-512. Use this option
 * if you have performance concerns.
 *
 * This option is only useful if both MBEDTLS_SHA256_C and
 * MBEDTLS_SHA512_C are defined. Otherwise the available hash module is used.
 */
#define MBEDTLS_ENTROPY_FORCE_SHA256

/**
 * \def MBEDTLS_SSL_FALLBACK_SCSV
 *
 * Enable support for FALLBACK_SCSV (draft-ietf-tls-downgrade-scsv-00).
 *
 * For servers, it is recommended to always enable this, unless you support
 * only one version of TLS, or know for sure that none of your clients
 * implements a fallback strategy.
 *
 * For clients, you only need this if you're using a fallback strategy, which
 * is not recommended in the first place, unless you absolutely need it to
 * interoperate with buggy (version-intolerant) servers.
 *
 * Comment this macro to disable support for FALLBACK_SCSV
 */
#undef MBEDTLS_SSL_FALLBACK_SCSV

/**
 * \def MBEDTLS_SSL_CBC_RECORD_SPLITTING
 *
 * Enable 1/n-1 record splitting for CBC mode in SSLv3 and TLS 1.0.
 *
 * This is a countermeasure to the BEAST attack, which also minimizes the risk
 * of interoperability issues compared to sending 0-length records.
 *
 * Comment this macro to disable 1/n-1 record splitting.
 */
#undef MBEDTLS_SSL_CBC_RECORD_SPLITTING

/**
 * \def MBEDTLS_SSL_RENEGOTIATION
 *
 * Enable support for TLS renegotiation.
 *
 * The two main uses of renegotiation are (1) refresh keys on long-lived
 * connections and (2) client authentication after the initial handshake.
 * If you don't need renegotiation, it's probably better to disable it, since
 * it has been associated with security issues in the past and is easy to
 * misuse/misunderstand.
 *
 * Comment this to disable support for renegotiation.
 *
 * \note   Even if this option is disabled, both client and server are aware
 *         of the Renegotiation Indication Extension (RFC 5746) used to
 *         prevent the SSL renegotiation attack (see RFC 5746 Sect. 1).
 *         (See \c mbedtls_ssl_conf_legacy_renegotiation for the
 *          configuration of this extension).
 *
 */
#undef MBEDTLS_SSL_RENEGOTIATION

/**
 * \def MBEDTLS_SSL_SRV_SUPPORT_SSLV2_CLIENT_HELLO
 *
 * Enable support for receiving and parsing SSLv2 Client Hello messages for the
 * SSL Server module (MBEDTLS_SSL_SRV_C).
 *
 * Uncomment this macro to enable support for SSLv2 Client Hello messages.
 */
//#define MBEDTLS_SSL_SRV_SUPPORT_SSLV2_CLIENT_HELLO

/**
 * \def MBEDTLS_SSL_PROTO_TLS1
 *
 * Enable support for TLS 1.0.
 *
 * Requires: MBEDTLS_MD5_C
 *           MBEDTLS_SHA1_C
 *
 * Comment this macro to disable support for TLS 1.0
 */
#undef MBEDTLS_SSL_PROTO_TLS1

/**
 * \def MBEDTLS_SSL_PROTO_TLS1_1
 *
 * Enable support for TLS 1.1 (and DTLS 1.0 if DTLS is enabled).
 *
 * Requires: MBEDTLS_MD5_C
 *           MBEDTLS_SHA1_C
 *
 * Comment this macro to disable support for TLS 1.1 / DTLS 1.0
 */
#undef MBEDTLS_SSL_PROTO_TLS1_1

/**
 * \def MBEDTLS_SSL_PROTO_DTLS
 *
 * Enable support for DTLS (all available versions).
 *
 * Enable this and MBEDTLS_SSL_PROTO_TLS1_1 to enable DTLS 1.0,
 * and/or this and MBEDTLS_SSL_PROTO_TLS1_2 to enable DTLS 1.2.
 *
 * Requires: MBEDTLS_SSL_PROTO_TLS1_1
 *        or MBEDTLS_SSL_PROTO_TLS1_2
 *
 * Comment this macro to disable support for DTLS
 */
#undef MBEDTLS_SSL_PROTO_DTLS

/**
 * \def MBEDTLS_SSL_DTLS_CONNECTION_ID
 *
 * Enable support for the DTLS Connection ID (CID) extension,
 * which allows to identify DTLS connections across changes
 * in the underlying transport. The CID functionality is described
 * in RFC 9146.
 *
 * Setting this option enables the SSL APIs `mbedtls_ssl_set_cid()`,
 * mbedtls_ssl_get_own_cid()`, `mbedtls_ssl_get_peer_cid()` and
 * `mbedtls_ssl_conf_cid()`. See the corresponding documentation for
 * more information.
 *
 * The maximum lengths of outgoing and incoming CIDs can be configured
 * through the options
 * - MBEDTLS_SSL_CID_OUT_LEN_MAX
 * - MBEDTLS_SSL_CID_IN_LEN_MAX.
 *
 * Requires: MBEDTLS_SSL_PROTO_DTLS
 *
 * Uncomment to enable the Connection ID extension.
 */
#undef MBEDTLS_SSL_DTLS_CONNECTION_ID

/**
 * \def MBEDTLS_SSL_DTLS_ANTI_REPLAY
 *
 * Enable support for the anti-replay mechanism in DTLS.
 *
 * Requires: MBEDTLS_SSL_TLS_C
 *           MBEDTLS_SSL_PROTO_DTLS
 *
 * \warning Disabling this is often a security risk!
 * See mbedtls_ssl_conf_dtls_anti_replay() for details.
 *
 * Comment this to disable anti-replay in DTLS.
 */
#undef MBEDTLS_SSL_DTLS_ANTI_REPLAY

/**
 * \def MBEDTLS_SSL_DTLS_HELLO_VERIFY
 *
 * Enable support for HelloVerifyRequest on DTLS servers.
 *
 * This feature is highly recommended to prevent DTLS servers being used as
 * amplifiers in DoS attacks against other hosts. It should always be enabled
 * unless you know for sure amplification cannot be a problem in the
 * environment in which your server operates.
 *
 * \warning Disabling this can ba a security risk! (see above)
 *
 * Requires: MBEDTLS_SSL_PROTO_DTLS
 *
 * Comment this to disable support for HelloVerifyRequest.
 */
#undef MBEDTLS_SSL_DTLS_HELLO_VERIFY

/**
 * \def MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE
 *
 * Enable server-side support for clients that reconnect from the same port.
 *
 * Some clients unexpectedly close the connection and try to reconnect using the
 * same source port. This needs special support from the server to handle the
 * new connection securely, as described in section 4.2.8 of RFC 6347. This
 * flag enables that support.
 *
 * Requires: MBEDTLS_SSL_DTLS_HELLO_VERIFY
 *
 * Comment this to disable support for clients reusing the source port.
 */
#undef MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE

/**
 * \def MBEDTLS_SSL_DTLS_BADMAC_LIMIT
 *
 * Enable support for a limit of records with bad MAC.
 *
 * See mbedtls_ssl_conf_dtls_badmac_limit().
 *
 * Requires: MBEDTLS_SSL_PROTO_DTLS
 */
#undef MBEDTLS_SSL_DTLS_BADMAC_LIMIT

/**
 * \def MBEDTLS_SSL_EXPORT_KEYS
 *
 * Enable support for exporting key block and master secret.
 * This is required for certain users of TLS, e.g. EAP-TLS.
 *
 * Comment this macro to disable support for key export
 */
#undef MBEDTLS_SSL_EXPORT_KEYS


/**
 * \def MBEDTLS_SSL_TRUNCATED_HMAC
 *
 * Enable support for RFC 6066 truncated HMAC in SSL.
 *
 * Comment this macro to disable support for truncated HMAC in SSL
 */
#undef MBEDTLS_SSL_TRUNCATED_HMAC

/**
 * \def MBEDTLS_NET_C
 *
 * Enable the TCP and UDP over IPv6/IPv4 networking routines.
 *
 * \note This module only works on POSIX/Unix (including Linux, BSD and OS X)
 * and Windows. For other platforms, you'll want to disable it, and write your
 * own networking callbacks to be passed to \c mbedtls_ssl_set_bio().
 *
 * \note See also our Knowledge Base article about porting to a new
 * environment:
 * https://tls.mbed.org/kb/how-to/how-do-i-port-mbed-tls-to-a-new-environment-OS
 *
 * Module:  library/net_sockets.c
 *
 * This module provides networking routines.
 */
#undef MBEDTLS_NET_C

/**
 * \def MBEDTLS_SSL_COOKIE_C
 *
 * Enable basic implementation of DTLS cookies for hello verification.
 *
 * Module:  library/ssl_cookie.c
 * Caller:
 */
#undef MBEDTLS_SSL_COOKIE_C

/**
 * \def MBEDTLS_TIMING_C
 *
 * Enable the semi-portable timing interface.
 *
 * \note The provided implementation only works on POSIX/Unix (including Linux,
 * BSD and OS X) and Windows. On other platforms, you can either disable that
 * module and provide your own implementations of the callbacks needed by
 * \c mbedtls_ssl_set_timer_cb() for DTLS, or leave it enabled and provide
 * your own implementation of the whole module by setting
 * \c MBEDTLS_TIMING_ALT in the current file.
 *
 * \note See also our Knowledge Base article about porting to a new
 * environment:
 * https://tls.mbed.org/kb/how-to/how-do-i-port-mbed-tls-to-a-new-environment-OS
 *
 * Module:  library/timing.c
 * Caller:  library/havege.c
 *
 * This module is used by the HAVEGE random number generator.
 */
#undef MBEDTLS_TIMING_C

/**
 * \def MBEDTLS_X509_CRL_PARSE_C
 *
 * Enable X.509 CRL parsing.
 *
 * Module:  library/x509_crl.c
 * Caller:  library/x509_crt.c
 *
 * Requires: MBEDTLS_X509_USE_C
 *
 * This module is required for X.509 CRL parsing.
 */
#undef MBEDTLS_X509_CRL_PARSE_C

/**
 * \def MBEDTLS_X509_CSR_PARSE_C
 *
 * Enable X.509 Certificate Signing Request (CSR) parsing.
 *
 * Module:  library/x509_csr.c
 * Caller:  library/x509_crt_write.c
 *
 * Requires: MBEDTLS_X509_USE_C
 *
 * This module is used for reading X.509 certificate request.
 */
#undef MBEDTLS_X509_CSR_PARSE_C

/**
 * \def MBEDTLS_X509_CREATE_C
 *
 * Enable X.509 core for creating certificates.
 *
 * Module:  library/x509_create.c
 *
 * Requires: MBEDTLS_BIGNUM_C, MBEDTLS_OID_C, MBEDTLS_PK_WRITE_C
 *
 * This module is the basis for creating X.509 certificates and CSRs.
 */
#undef MBEDTLS_X509_CREATE_C

/**
 * \def MBEDTLS_X509_CSR_WRITE_C
 *
 * Enable creating X.509 Certificate Signing Requests (CSR).
 *
 * Module:  library/x509_csr_write.c
 *
 * Requires: MBEDTLS_X509_CREATE_C
 *
 * This module is required for X.509 certificate request writing.
 */
#undef MBEDTLS_X509_CSR_WRITE_C

/**
 * \def MBEDTLS_X509_CRT_WRITE_C
 *
 * Enable creating X.509 certificates.
 *
 * Module:  library/x509_crt_write.c
 *
 * Requires: MBEDTLS_X509_CREATE_C
 *
 * This module is required for X.509 certificate creation.
 */
#undef MBEDTLS_X509_CRT_WRITE_C

/**
 * \def MBEDTLS_CERTS_C
 *
 * Enable the test certificates.
 *
 * Module:  library/certs.c
 * Caller:
 *
 * This module is used for testing (ssl_client/server).
 */
#undef MBEDTLS_CERTS_C

/**
 * \def MBEDTLS_ERROR_C
 *
 * Enable error code to error string conversion.
 *
 * Module:  library/error.c
 * Caller:
 *
 * This module enables mbedtls_strerror().
 */
#undef MBEDTLS_ERROR_C

/**
 * \def MBEDTLS_RIPEMD160_C
 *
 * Enable the RIPEMD-160 hash algorithm.
 *
 * Module:  library/ripemd160.c
 * Caller:  library/md.c
 *
 */
#undef MBEDTLS_RIPEMD160_C

/**
 * \def MBEDTLS_ARC4_C
 *
 * Enable the ARCFOUR stream cipher.
 *
 * Module:  library/arc4.c
 * Caller:  library/cipher.c
 *
 * This module enables the following ciphersuites (if other requisites are
 * enabled as well):
 *      MBEDTLS_TLS_ECDH_ECDSA_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_ECDH_RSA_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_ECDHE_ECDSA_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_ECDHE_RSA_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_DHE_PSK_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_RSA_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_RSA_WITH_RC4_128_MD5
 *      MBEDTLS_TLS_RSA_PSK_WITH_RC4_128_SHA
 *      MBEDTLS_TLS_PSK_WITH_RC4_128_SHA
 *
 * \warning   ARC4 is considered a weak cipher and its use constitutes a
 *            security risk. If possible, we recommend avoidng dependencies on
 *            it, and considering stronger ciphers instead.
 *
 */
#undef MBEDTLS_ARC4_C

/**
 * \def MBEDTLS_XTEA_C
 *
 * Enable the XTEA block cipher.
 *
 * Module:  library/xtea.c
 * Caller:
 */
#undef MBEDTLS_XTEA_C

/**
 * \def MBEDTLS_BLOWFISH_C
 *
 * Enable the Blowfish block cipher.
 *
 * Module:  library/blowfish.c
 */
#undef MBEDTLS_BLOWFISH_C

/**
 * \def MBEDTLS_PKCS7_C
 *
 * Enable PKCS #7 core for using PKCS #7-formatted signatures.
 * RFC Link - https://tools.ietf.org/html/rfc2315
 *
 * Module:  library/pkcs7.c
 *
 * Requires: MBEDTLS_ASN1_PARSE_C, MBEDTLS_OID_C, MBEDTLS_PK_PARSE_C,
 *           MBEDTLS_X509_CRT_PARSE_C MBEDTLS_X509_CRL_PARSE_C,
 *           MBEDTLS_BIGNUM_C, MBEDTLS_MD_C
 *
 * This module is required for the PKCS #7 parsing modules.
 */
#undef MBEDTLS_PKCS7_C

/**
 * \def MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
 *
 * Enable the ECDHE-PSK based ciphersuite modes in SSL / TLS.
 *
 * Requires: MBEDTLS_ECDH_C
 *
 * This enables the following ciphersuites (if other requisites are
 * enabled as well):
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA384
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_CAMELLIA_256_CBC_SHA384
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA256
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_CAMELLIA_128_CBC_SHA256
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_3DES_EDE_CBC_SHA
 *      MBEDTLS_TLS_ECDHE_PSK_WITH_RC4_128_SHA
 */
#undef MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED

/**
 * \def MBEDTLS_SSL_PROTO_TLS1_3
 *
 * Enable support for TLS 1.3.
 *
 * \note The support for TLS 1.3 is not comprehensive yet, in particular
 *       pre-shared keys are not supported.
 *       See docs/architecture/tls13-support.md for a description of the TLS
 *       1.3 support that this option enables.
 *
 * Requires: MBEDTLS_SSL_KEEP_PEER_CERTIFICATE
 * Requires: MBEDTLS_PSA_CRYPTO_C
 *
 * \note TLS 1.3 uses PSA crypto for cryptographic operations that are
 *       directly performed by TLS 1.3 code. As a consequence, you must
 *       call psa_crypto_init() before the first TLS 1.3 handshake.
 *
 * \note Cryptographic operations performed indirectly via another module
 *       (X.509, PK) or by code shared with TLS 1.2 (record protection,
 *       running handshake hash) only use PSA crypto if
 *       #MBEDTLS_USE_PSA_CRYPTO is enabled.
 *
 * Uncomment this macro to enable the support for TLS 1.3.
 */
#define MBEDTLS_SSL_PROTO_TLS1_3

#ifndef MBEDTLS_SSL_PROTO_TLS1_3
/**
 * \def MBEDTLS_SSL_KEEP_PEER_CERTIFICATE
 *
 * This option controls the availability of the API mbedtls_ssl_get_peer_cert()
 * giving access to the peer's certificate after completion of the handshake.
 *
 * Unless you need mbedtls_ssl_peer_cert() in your application, it is
 * recommended to disable this option for reduced RAM usage.
 *
 * \note If this option is disabled, mbedtls_ssl_get_peer_cert() is still
 *       defined, but always returns \c NULL.
 *
 * \note This option has no influence on the protection against the
 *       triple handshake attack. Even if it is disabled, Mbed TLS will
 *       still ensure that certificates do not change during renegotiation,
 *       for exaple by keeping a hash of the peer's certificate.
 *
 * Comment this macro to disable storing the peer's certificate
 * after the handshake.
 */
#undef MBEDTLS_SSL_KEEP_PEER_CERTIFICATE
#endif

/* MBEDTLS 3.4 version has build error when TLS1.3 is enabled and session ticket flag is not enabled.
 * Hence, enabling session ticket flag when TLS1.3 is enabled though we dont support.
 * Note: User should not disable session ticket flag when TLS1.3 is enabled otherwise it will result into
 *       build error.
 */
#ifndef MBEDTLS_SSL_PROTO_TLS1_3
/**
 * \def MBEDTLS_SSL_SESSION_TICKETS
 *
 * Enable support for RFC 5077 session tickets in SSL.
 * Client-side, provides full support for session tickets (maintenance of a
 * session store remains the responsibility of the application, though).
 * Server-side, you also need to provide callbacks for writing and parsing
 * tickets, including authenticated encryption and key management. Example
 * callbacks are provided by MBEDTLS_SSL_TICKET_C.
 *
 * Comment this macro to disable support for SSL session tickets
 */
#undef MBEDTLS_SSL_SESSION_TICKETS
#endif

#ifdef MBEDTLS_SSL_PROTO_TLS1_3
/**
 * \def MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE
 *
 * Enable TLS 1.3 middlebox compatibility mode.
 *
 * As specified in Section D.4 of RFC 8446, TLS 1.3 offers a compatibility
 * mode to make a TLS 1.3 connection more likely to pass through middle boxes
 * expecting TLS 1.2 traffic.
 *
 * Turning on the compatibility mode comes at the cost of a few added bytes
 * on the wire, but it doesn't affect compatibility with TLS 1.3 implementations
 * that don't use it. Therefore, unless transmission bandwidth is critical and
 * you know that middlebox compatibility issues won't occur, it is therefore
 * recommended to set this option.
 *
 * Comment to disable compatibility mode for TLS 1.3. If
 * MBEDTLS_SSL_PROTO_TLS1_3 is not enabled, this option does not have any
 * effect on the build.
 *
 */
#define MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE
#endif

/**
 * \def MBEDTLS_DEPRECATED_REMOVED
 *
 * Remove deprecated functions and features so that they generate an error if
 * used. Functionality deprecated in one version will usually be removed in the
 * next version. You can enable this to help you prepare the transition to a
 * new major version by making sure your code is not using this functionality.
 *
 * Uncomment to get errors on using deprecated functions and features.
 */
#define MBEDTLS_DEPRECATED_REMOVED

/**
 * \def Enable MBEDTLS debug logs & set debug level
 *
 * MBEDTLS_VERBOSE values:
 * 0 No debug      - No logs are printed on console
 * 1 Error         - Error messages are printed on console
 * 2 State change  - State level change logs are printed on console
 * 3 Informational - Informational logs printed on console
 * 4 Verbose       - All the logs are printed on console
 */
#define MBEDTLS_VERBOSE 0

/** 
 * \def Comment out below line in addition to setting MBEDTLS_VERBOSE value to get the MBEDTLS logs
 *
 * MBEDTLS_DEBUG_C flag is by default undefined to save code space (~60Kb). For low memory platform, when MBEDTLS_DEBUG_C is enabled
 * make sure to remove unwanted features of MBEDTLS which are not used in the application to avoid code size overflow issues.
 */
#undef MBEDTLS_DEBUG_C


/* When TLS1.3 and TLS1.2 both are enabled, there is no version negotiation currently supported for server. Hence, when both
 * are enabled, the below macro can be changed to force the TLS version to be used on server side. Please note that this macro
 * is only used when device is acting as a server. for client, version negotiation is supported.
 */
#define FORCE_TLS_VERSION MBEDTLS_SSL_VERSION_TLS1_3

/**
 * \def MBEDTLS_USE_PSA_CRYPTO
 *
 * Make the X.509 and TLS library use PSA for cryptographic operations, and
 * enable new APIs for using keys handled by PSA Crypto.
 *
 * \note Development of this option is currently in progress, and parts of Mbed
 * TLS's X.509 and TLS modules are not ported to PSA yet. However, these parts
 * will still continue to work as usual, so enabling this option should not
 * break backwards compatibility.
 *
 * \note See docs/use-psa-crypto.md for a complete description of what this
 * option currently does, and of parts that are not affected by it so far.
 *
 * \warning If you enable this option, you need to call `psa_crypto_init()`
 * before calling any function from the SSL/TLS, X.509 or PK modules.
 *
 * Requires: MBEDTLS_PSA_CRYPTO_C.
 *
 * Uncomment this to enable internal use of PSA Crypto and new associated APIs.
 */
#define MBEDTLS_USE_PSA_CRYPTO

/**
 * \def MBEDTLS_PSA_CRYPTO_CONFIG
 *
 * This setting allows support for cryptographic mechanisms through the PSA
 * API to be configured separately from support through the mbedtls API.
 *
 * When this option is disabled, the PSA API exposes the cryptographic
 * mechanisms that can be implemented on top of the `mbedtls_xxx` API
 * configured with `MBEDTLS_XXX` symbols.
 *
 * When this option is enabled, the PSA API exposes the cryptographic
 * mechanisms requested by the `PSA_WANT_XXX` symbols defined in
 * include/psa/crypto_config.h. The corresponding `MBEDTLS_XXX` settings are
 * automatically enabled if required (i.e. if no PSA driver provides the
 * mechanism). You may still freely enable additional `MBEDTLS_XXX` symbols
 * in mbedtls_config.h.
 *
 * If the symbol #MBEDTLS_PSA_CRYPTO_CONFIG_FILE is defined, it specifies
 * an alternative header to include instead of include/psa/crypto_config.h.
 *
 * This feature is still experimental and is not ready for production since
 * it is not completed.
 */
#define MBEDTLS_PSA_CRYPTO_CONFIG

#if defined(CY_TFM_PSA_SUPPORTED)
/* PSA-Client builds skip the builtin ECP adjustments, so ssl.h sizes the TLS 1.2 ECDH
 * premaster from MBEDTLS_ECP_MAX_BYTES, which falls back to 1 incorrectly and causes psa_raw_key_agreement() to fail. 
 * Declare the curves so it matches PSA_WANT_ECC_*. This only changes header-level sizing;
 * MBEDTLS_ECP_C is not enabled, so the legacy ECP code is not compiled in.
 */
#if defined(PSA_WANT_ECC_SECP_R1_256) || defined(PSA_WANT_ECC_SECP_R1_384) || \
    defined(PSA_WANT_ECC_SECP_R1_521)
#if !defined(MBEDTLS_ECP_LIGHT)
#define MBEDTLS_ECP_LIGHT
#endif
#if defined(PSA_WANT_ECC_SECP_R1_256) && !defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#endif
#if defined(PSA_WANT_ECC_SECP_R1_384) && !defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#endif
#if defined(PSA_WANT_ECC_SECP_R1_521) && !defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif
#endif
#endif

#endif /* MBEDTLS_USER_CONFIG_HEADER */
