/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * d_link_alpha_encimg_v2 data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_alpha_encimg_header_prefix_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",36,4,SX_SIGNATURE),
    SX_FIELD("version","char[16]",40,16,SX_NONE),
    SX_FIELD("model","char[16]",56,16,SX_NONE),
    SX_FIELD("flags0","uint32",72,4,SX_FLAGS),
    SX_FIELD("flags1","uint32",76,4,SX_FLAGS),
    SX_FIELD("reserve0","uint32",80,4,SX_RESERVED),
    SX_FIELD("reserve1","uint32",84,4,SX_RESERVED),
    SX_FIELD("build_number","char[16]",88,16,SX_NONE),
};
const sx_layout sx_fm_alpha_encimg_header_prefix = {0x6022000aU,"alpha_encimg_header_prefix",sx_fm_alpha_encimg_header_prefix_fields,SX_COUNT(sx_fm_alpha_encimg_header_prefix_fields),SX_FILE};
static const xx_data_struct_field_desc sx_fm_alpha_encimg_header_suffix_fields[] = {
    SX_FIELD("device_name","char[32]",0,32,SX_NONE),
    SX_FIELD("digest","byte[16]",32,16,SX_CHECKSUM),
};
const sx_layout sx_fm_alpha_encimg_header_suffix = {0x6022000dU,"alpha_encimg_header_suffix",sx_fm_alpha_encimg_header_suffix_fields,SX_COUNT(sx_fm_alpha_encimg_header_suffix_fields),SX_LE};
static bool sx_fm_alpha(sx_context *c)
{
    uint32_t le,be;if(!sx_fm_u32(c,104,false,&le)||!sx_fm_u32(c,104,true,&be))return false;
    return sx_fm_add(c,&sx_fm_alpha_encimg_header_prefix,0,104)&&sx_fm_add(c,le<=be?&sx_fm_alpha_encimg_payload_le:&sx_fm_alpha_encimg_payload_be,104,8)&&sx_fm_add(c,&sx_fm_alpha_encimg_header_suffix,112,48);
}
bool sx_d_link_alpha_encimg_v2_build(sx_context*c)
{
    return sx_fm_alpha(c);
}
