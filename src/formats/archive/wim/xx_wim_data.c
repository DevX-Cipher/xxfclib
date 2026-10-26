/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WIM data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_wim_header_fields[] = {
    SX_FIELD("signature", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 16, 4, SX_FLAGS),
    SX_FIELD("chunk_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("part_number", "uint16", 40, 2, SX_NONE),
    SX_FIELD("total_parts", "uint16", 42, 2, SX_COUNT_PROP),
    SX_FIELD("image_count", "uint32", 44, 4, SX_COUNT_PROP),
};
const sx_layout sx_p_wim_header = { UINT32_C(0x60070038), "wim_header", sx_p_wim_header_fields, SX_COUNT(sx_p_wim_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_wim_boot_fields[] = {
    SX_FIELD("boot_index", "uint32", 0, 4, SX_ID),
};
const sx_layout sx_p_wim_boot = { UINT32_C(0x6007003A), "wim_boot", sx_p_wim_boot_fields, SX_COUNT(sx_p_wim_boot_fields), SX_LE };
static bool sx_p_wim(sx_context *c)
{
    uint32_t size;if(!sx_p_sig(c,0,"MSWIM\0\0\0",8)||!sx_u32(c,8,false,&size)||size<116||size>208||!sx_p_span(c,0,size)||!sx_add(c,&sx_p_wim_header,0,48))return false;
    int offs[]={48,72,96,124};for(unsigned i=0;i<4;i++)if(size>=(unsigned)offs[i]+24){uint64_t sf,off;if(!sx_add(c,&sx_p_wim_resource,offs[i],24)||!sx_u64(c,offs[i],false,&sf)||!sx_u64(c,offs[i]+8,false,&off))return false;uint64_t packed=sf&UINT64_C(0x00ffffffffffffff);if(i<2&&!sx_p_span(c,off,packed))return false;if(i==0&&packed&&!(sf>>56&4)){if(packed%50||!sx_table(c,&sx_p_wim_blob,(int64_t)off,50,packed/50))return false;}}
    return size<124||sx_add(c,&sx_p_wim_boot,120,4);
}
bool sx_wim_build(sx_context*c)
{
    return sx_p_wim(c);
}
