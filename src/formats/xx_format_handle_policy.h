/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Internal capability policy shared by identities and native discovery.
 */
#ifndef XX_FORMAT_HANDLE_POLICY_H
#define XX_FORMAT_HANDLE_POLICY_H

#include "xxfclib/xxfc_defs.h"

/* Some inspection readers inherit the common payload-members vtable even
 * though their parser only returns metadata and no unpackable members.
 * Callback presence alone must not turn those identities into handles. */
static inline bool xx_format_handle_is_inspection_only(xx_file_type_t type)
{
    return type == XX_FILE_TYPE_UNKNOWN || type == XX_FILE_TYPE_BINARY || type == XX_FILE_TYPE_TEXT;
}

#endif
