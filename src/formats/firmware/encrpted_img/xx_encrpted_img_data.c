/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * D-Link encrpted_img data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_encrpted_img_header_fields[] = {
    SX_FIELD("magic","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("unknown","byte[4]",12,4,SX_NONE),
};
const sx_layout sx_fm_encrpted_img_header = {0x60220009U,"encrpted_img_header",sx_fm_encrpted_img_header_fields,SX_COUNT(sx_fm_encrpted_img_header_fields),SX_LE};
bool sx_encrpted_img_build(sx_context*c)
{
    return sx_fm_add(c,&sx_fm_encrpted_img_header,0,16);
}
