/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Chromium DataPack data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_pak_header4_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
    SX_FIELD("resource_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("encoding", "uint8", 8, 1, SX_ID),
};
const sx_layout sx_p_pak_header4 = { UINT32_C(0x60070044), "pak_header4", sx_p_pak_header4_fields, SX_COUNT(sx_p_pak_header4_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pak_header5_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
    SX_FIELD("encoding", "uint8", 4, 1, SX_ID),
    SX_FIELD("reserved", "bytes", 5, 3, SX_RESERVED),
    SX_FIELD("resource_count", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("alias_count", "uint16", 10, 2, SX_COUNT_PROP),
};
const sx_layout sx_p_pak_header5 = { UINT32_C(0x60070045), "pak_header5", sx_p_pak_header5_fields, SX_COUNT(sx_p_pak_header5_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pak_resource_fields[] = {
    SX_FIELD("resource_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("data_offset", "uint32", 2, 4, SX_OFFSET),
};
const sx_layout sx_p_pak_resource = { UINT32_C(0x60070046), "pak_resource", sx_p_pak_resource_fields, SX_COUNT(sx_p_pak_resource_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pak_alias_fields[] = {
    SX_FIELD("resource_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("resource_index", "uint16", 2, 2, SX_ID),
};
const sx_layout sx_p_pak_alias = { UINT32_C(0x60070047), "pak_alias", sx_p_pak_alias_fields, SX_COUNT(sx_p_pak_alias_fields), SX_LE };
static bool sx_p_pak(sx_context *c)
{
    uint32_t v,count,previous=0;uint16_t n,aliases=0;uint8_t enc;int64_t header;
    if(!sx_u32(c,0,false,&v))return false;
    if(v==4){header=9;if(!sx_u32(c,4,false,&count)||!sx_p_byte(c,8,&enc)||!sx_add(c,&sx_p_pak_header4,0,9))return false;}else if(v==5){header=12;if(!sx_u16(c,8,false,&n)||!sx_u16(c,10,false,&aliases)||!sx_p_byte(c,4,&enc)||!sx_add(c,&sx_p_pak_header5,0,12))return false;count=n;}else return false;
    if(count>65535||enc>2||!sx_table(c,&sx_p_pak_resource,header,6,(uint64_t)count+1)||!sx_table(c,&sx_p_pak_alias,header+6*((int64_t)count+1),4,aliases))return false;
    uint64_t payload=header+6*((uint64_t)count+1)+4*aliases;for(uint32_t i=0;i<=count;i++){uint32_t off;if(!sx_u32(c,header+6*i+2,false,&off)||off<payload||off<previous||off>(uint64_t)c->size)return false;previous=off;}if(previous!=(uint64_t)c->size)return false;
    for(unsigned i=0;i<aliases;i++){uint16_t which;if(!sx_u16(c,header+6*((int64_t)count+1)+4*i+2,false,&which)||which>=count)return false;}return true;
}
bool sx_chromium_pak_build(sx_context*c)
{
    return sx_p_pak(c);
}
