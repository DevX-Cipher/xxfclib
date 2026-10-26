/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ORACLE SQUEEZE data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_oracle_squeeze_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("checksum", "uint16", 6, 2, SX_CHECKSUM),
};
const sx_layout sxl_oracle_squeeze_header = { UINT32_C(0x600A0009), "oracle_squeeze_header", sxl_oracle_squeeze_header_fields, SX_COUNT(sxl_oracle_squeeze_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_squeeze_tree_header_fields[] = {
    SX_FIELD("node_count", "uint16", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxl_squeeze_tree_header = { UINT32_C(0x600A000A), "squeeze_tree_header", sxl_squeeze_tree_header_fields, SX_COUNT(sxl_squeeze_tree_header_fields), SX_LE };
static bool sxl_squeeze(sx_context *c)
{
    int64_t at;uint16_t nodes;uint32_t n;
    if(!sxl_sig(c,0,"\x76\xff",2)||!sx_u32(c,2,false,&n)||!n||!sx_add(c,&sxl_oracle_squeeze_header,0,8)||!sxl_name(c,8,c->size<264?c->size:264,&at)||!sx_u16(c,at,false,&nodes)||!nodes||nodes>256)return false;
    if(!sx_add(c,&sxl_squeeze_tree_header,at,2)||!sx_table(c,&sxl_squeeze_tree_node,at+2,4,nodes)||!sxl_span(c,at+2+(uint64_t)nodes*4,1))return false;
    for(uint16_t i=0;i<nodes*2;i++){uint16_t v;if(!sx_u16(c,at+2+(int64_t)i*2,false,&v))return false;int32_t x=(v&0x8000)?(int32_t)v-65536:(int32_t)v;if(x>=nodes||x < -257)return false;}
    return true;
}
bool sx_oraclesqueeze_build(sx_context*c)
{
    return sxl_squeeze(c);
}
