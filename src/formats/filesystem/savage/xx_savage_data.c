/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SAVAGE data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_savage_header_fields[] = {
    SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
    SX_FIELD("unknown_01","uint8",1,1,SX_NONE),
    SX_FIELD("method","char[5]",2,5,SX_SIGNATURE),
    SX_FIELD("packed_bytes","uint32",7,4,SX_SIZE),
    SX_FIELD("disk_bytes","uint32",11,4,SX_SIZE),
    SX_FIELD("unknown_0f","byte[14]",15,14,SX_NONE),
    SX_FIELD("disk_crc16","uint16",29,2,SX_CHECKSUM),
};
const sx_layout sxdr_savage_header = {0x607f000cU,"savage_header",sxdr_savage_header_fields,SX_COUNT(sxdr_savage_header_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_savage(sx_context*c){uint8_t h[31];return sxdr_read(c,0,h,31)&&h[0]==29&&!xx_rt_memcmp(h+2,"*SVG*",5)&&sxdr32(h+11,false)==901120&&SXDR_ADD(c,savage_header,0);}
#undef SXDR_ADD
bool sx_savage_build(sx_context*c)
{
 return sxdr_savage(c);
}
