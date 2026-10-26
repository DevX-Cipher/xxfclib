/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUTEL data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_autel_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("copyright","char[16]",16,16,SX_NONE),
};
const sx_layout sx_fm_autel_header = {0x60220007U,"autel_header",sx_fm_autel_header_fields,SX_COUNT(sx_fm_autel_header_fields),SX_LE};
bool sx_autel_build(sx_context*c)
{
    return sx_fm_add(c,&sx_fm_autel_header,0,32);
}
