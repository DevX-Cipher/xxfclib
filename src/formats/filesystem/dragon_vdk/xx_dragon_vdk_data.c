/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Dragon Vdk data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_vdk_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("compatibility","uint8",5,1,SX_NONE),
    SX_FIELD("source_id","uint8",6,1,SX_ID),
    SX_FIELD("source_version","uint8",7,1,SX_NONE),
    SX_FIELD("cylinder_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("head_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("compression_and_name_length","uint8",11,1,SX_FLAGS),
};
const sx_layout sxse_vdk_header = {0x602f0045U,"vdk_header",sxse_vdk_header_fields,SX_COUNT(sxse_vdk_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_dragon_vdk_build(sx_context*c)
{
 return SXSE_ADD(c,vdk_header,0,12);
}
#undef SXSE_ADD
