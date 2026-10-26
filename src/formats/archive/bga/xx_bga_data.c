/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bga data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_bga_member_fields[] = {
 SX_FIELD("header_checksum","int32",0,4,SX_CHECKSUM),
 SX_FIELD("method","char[4]",4,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",16,2,SX_NONE),
 SX_FIELD("dos_time","uint16",18,2,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_NONE),
 SX_FIELD("header_type","uint8",21,1,SX_NONE),
 SX_FIELD("archive_type","uint16",22,2,SX_NONE),
 SX_FIELD("directory_name_size","uint16",24,2,SX_SIZE),
 SX_FIELD("file_name_size","uint16",26,2,SX_SIZE),
};
const sx_layout sxaf_bga_member = {UINT32_C(0x603c0019),"bga_member",sxaf_bga_member_fields,SX_COUNT(sxaf_bga_member_fields),SX_LE};
static bool sxaf_bga(sx_context*c){uint64_t p=0;while(sxaf_span(c,p,28)){uint8_t b[28];if(!sxaf_read(c,p,b,28))return false;uint64_t n=sxaf_uint(b+8,4,false),names=sxaf_uint(b+24,2,false)+sxaf_uint(b+26,2,false);if(!names||names>1024||!sxaf_span(c,p+28,names)||((xx_rt_memcmp(b+4,"GZIP",4))&&(xx_rt_memcmp(b+4,"BZ2\0",4))))return false;uint8_t name[1024];if(!sxaf_read(c,p+28,name,(size_t)names))return false;int32_t sum=0;for(unsigned i=4;i<28;i++)sum+=(b[i]&128)?(int32_t)b[i]-256:b[i];for(uint64_t i=0;i<names;i++)sum+=(name[i]&128)?(int32_t)name[i]-256:name[i];if((uint32_t)sum!=(uint32_t)sxaf_uint(b,4,false)||!sxaf_add(c,&sxaf_bga_member,p))return false;p+=28+names;if(!sxaf_span(c,p,n))return false;p+=n;}return true;}
bool sx_bga_build(sx_context*c)
{
 return sxaf_bga(c);
}
