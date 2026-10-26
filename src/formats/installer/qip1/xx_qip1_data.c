/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QIP1 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_qip1_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("flag","uint8",10,1,SX_NONE),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",15,4,SX_SIZE),
 SX_FIELD("name","char[13]",19,13,SX_NONE),
};
const sx_layout sxasy_qip1_member = {UINT32_C(0x60440022),"qip1_member",sxasy_qip1_member_fields,SX_COUNT(sxasy_qip1_member_fields),SX_LE};
static bool sxasy_qip(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[32];if(!sxasy_read(c,p,h,32)||h[0]!='Q'||h[1]!='D')return false;uint64_t z=sxasy_uint(h+4,4,false);if(z>INT32_MAX||!sxasy_span(c,p+32,z)||!sxasy_add(c,&sxasy_qip1_member,p))return false;if(sxasy_uint(h+15,4,false)&&!sxasy_dcl(c,p+32,z))return false;p+=32+z;}return true;}
bool sx_qip1_build(sx_context*c)
{
 return sxasy_qip(c);
}
