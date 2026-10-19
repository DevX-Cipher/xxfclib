/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XX_SIG_H
#define XX_SIG_H

#include "xxfclib/xxfc_defs.h"
#include "xxfclib/formats/xx_data_signature.h"
#include "xxfclib/io/xx_io.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Normalize signature notation using xx_data_sig_normalize(), requiring
 * quoted literals to be terminated. An unterminated quote produces an empty
 * string. Release the returned string with xx_str_free(); NULL means an
 * allocation failure. */
XXFC_API char *xx_sig_normalize(const char *text);

/** Parse and validate a complete normalized signature. Unlike the general
 * parser, rejects partial byte records, incomplete operators and unsupported
 * pointer widths. Empty text is valid and produces no records.
 *
 * signature receives the parsed records even on failure and must be released
 * with xx_data_signature_free(). Optional parser_error distinguishes parser
 * failures and odd hexadecimal runs from other invalid record shapes. */
XXFC_API int xx_sig_valid(const char *normalized, xx_data_signature *signature, int *parser_error);

/** Compare normalized hexadecimal nibbles through xx_io_buffer_view(). A '.'
 * matches any single nibble; an odd length compares only the final byte's
 * high nibble. length is the number of characters, not bytes. The device must
 * support buffer views. An empty comparison succeeds without reading. */
XXFC_API int xx_sig_compare_nibbles(xx_io_device *device, int64_t offset, const char *normalized, size_t length);

#ifdef __cplusplus
}
#endif

#endif /* XX_SIG_H */
