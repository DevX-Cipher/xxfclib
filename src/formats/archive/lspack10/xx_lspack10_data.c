/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LSPack10 data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_lspack10_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_NONE),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",22,4,SX_SIZE),
 SX_FIELD("reserved0","uint16",26,2,SX_NONE),
 SX_FIELD("reserved1","uint16",28,2,SX_NONE),
 SX_FIELD("reserved2","uint16",30,2,SX_NONE),
 SX_FIELD("reserved3","uint32",32,4,SX_NONE),
 SX_FIELD("name_size","uint16",36,2,SX_SIZE),
 SX_FIELD("path_size","uint16",38,2,SX_SIZE),
};
const sx_layout sxaf_lspack10_member = {UINT32_C(0x603c0011),"lspack10_member",sxaf_lspack10_member_fields,SX_COUNT(sxaf_lspack10_member_fields),SX_LE};
static bool sxaf_lspack(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t b[40];if(!sxaf_read(c,p,b,40)||xx_rt_memcmp(b,"FL\3\4",4)||!sxaf_add(c,&sxaf_lspack10_member,p))return false;uint64_t n=sxaf_uint(b+18,4,false),names=sxaf_uint(b+36,2,false)+sxaf_uint(b+38,2,false);p+=40;if(!sxaf_span(c,p,names)||!sxaf_span(c,p+names,n))return false;p+=names+n;}return true;}
bool sx_lspack10_build(sx_context*c)
{
 return sxaf_lspack(c);
}
