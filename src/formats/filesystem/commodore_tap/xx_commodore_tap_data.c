/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Commodore Tap data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_c64_tap_header_fields[] = {
    SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
    SX_FIELD("version","uint8",12,1,SX_NONE),
    SX_FIELD("computer_platform","uint8",13,1,SX_ID),
    SX_FIELD("video_standard","uint8",14,1,SX_ID),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
    SX_FIELD("pulse_data_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxse_c64_tap_header = {0x602f000aU,"c64_tap_header",sxse_c64_tap_header_fields,SX_COUNT(sxse_c64_tap_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_commodore_tap_build(sx_context*c)
{
 return SXSE_ADD(c,c64_tap_header,0,20);
}
#undef SXSE_ADD
