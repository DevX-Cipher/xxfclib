/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARCFS data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_arcfs_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("directory_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("minimum_read_version", "uint32", 16, 4, SX_NONE),
    SX_FIELD("minimum_write_version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("unknown_24", "uint32", 24, 4, SX_NONE),
    SX_FIELD("reserved", "bytes", 28, 68, SX_RESERVED),
};
const sx_layout sxl_arcfs_header = { UINT32_C(0x600A0035), "arcfs_header", sxl_arcfs_header_fields, SX_COUNT(sxl_arcfs_header_fields), SX_LE };
static bool sxl_arcfs(sx_context *c)
{
    uint32_t dir,data;
    if(!sxl_sig(c,0,"Archive\0",8)||!sx_u32(c,8,false,&dir)||!dir||dir%36||!sx_u32(c,12,false,&data)||data<96+(uint64_t)dir||data>(uint64_t)c->size||!sx_add(c,&sxl_arcfs_header,0,96)||!sx_table(c,&sxl_arcfs_directory,96,36,dir/36))return false;
    for(uint32_t i=0;i<dir/36;i++){uint8_t status;uint32_t off,size;int64_t at=96+(int64_t)i*36;if(!sxl_byte(c,at,&status)||!sx_u32(c,at+28,false,&size)||!sx_u32(c,at+32,false,&off))return false;if(status>1&&!(off&0x80000000U)&&!sxl_span(c,(uint64_t)data+off,size))return false;}return true;
}
bool sx_arcfs_build(sx_context*c)
{
    return sxl_arcfs(c);
}
