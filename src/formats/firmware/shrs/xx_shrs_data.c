/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * D-Link SHRS data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_shrs_header_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("encrypted_size","uint32",8,4,SX_SIZE),
    SX_FIELD("iv","byte[16]",12,16,SX_NONE),
};
const sx_layout sx_fm_shrs_header_prefix = {0x60220004U,"shrs_header_prefix",sx_fm_shrs_header_prefix_fields,SX_COUNT(sx_fm_shrs_header_prefix_fields),SX_BE};
bool sx_shrs_build(sx_context*c)
{
    return sx_fm_add(c,&sx_fm_shrs_header_prefix,0,28);
}
