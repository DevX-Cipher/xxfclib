/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TWRX data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_twrx_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("stamp_low","uint32",10,4,SX_NONE),
 SX_FIELD("packed_crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint32",26,4,SX_SIZE),
};
const sx_layout sxap_twrx_header = {UINT32_C(0x6072001b),"twrx_header",sxap_twrx_header_fields,SX_COUNT(sxap_twrx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_twrx_deflate_fields[] = {
 SX_FIELD("method","uint16",0,2,SX_NONE),
 SX_FIELD("stream_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxap_twrx_deflate = {UINT32_C(0x6072001c),"twrx_deflate",sxap_twrx_deflate_fields,SX_COUNT(sxap_twrx_deflate_fields),SX_LE};
static bool sxap_twrx(sx_context*c){uint64_t p=0;while(sxap_span(c,p,30)){uint64_t method,z,n;if(!sxap_word(c,p+8,2,false,&method)||!sxap_word(c,p+18,4,false,&z)||!sxap_word(c,p+26,4,false,&n)||!sxap_add(c,&sxap_twrx_header,p)||!sxap_span(c,p+30,n)||!sxap_text(c,&sxap_archivepackages_name,p+30,n,false))return false;p+=30+n;if(!sxap_span(c,p,z))return true;if(method==6&&!sxap_dcl(c,p,z))return false;if(method==8&&z>=6&&!sxap_add(c,&sxap_twrx_deflate,p))return false;p+=z;}return true;}
bool sx_twrx_build(sx_context*c)
{
 return sxap_twrx(c);
}
