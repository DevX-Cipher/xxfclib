/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DN data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_dn_data_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque_prefix","uint8[14]",4,14,SX_NONE),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("opaque_word","uint16",26,2,SX_NONE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
const sx_layout sxaf_dn_data_header = {UINT32_C(0x603c002a),"dn_data_header",sxaf_dn_data_header_fields,SX_COUNT(sxaf_dn_data_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dn_directory_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque_prefix","uint8[26]",4,26,SX_NONE),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("opaque_tail","uint8[10]",32,10,SX_NONE),
 SX_FIELD("data_header_offset","uint32",42,4,SX_OFFSET),
};
const sx_layout sxaf_dn_directory_header = {UINT32_C(0x603c002b),"dn_directory_header",sxaf_dn_directory_header_fields,SX_COUNT(sxaf_dn_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dn_end_marker_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxaf_dn_end_marker = {UINT32_C(0x603c002c),"dn_end_marker",sxaf_dn_end_marker_fields,SX_COUNT(sxaf_dn_end_marker_fields),SX_LE};
static bool sxaf_dn(sx_context*c){uint64_t p=0;while(sxaf_span(c,p,4)){uint8_t b[46];if(!sxaf_read(c,p,b,4)||b[0]!=0x84||b[1]!=0x8d)return false;uint64_t hs,n=0,names;if(b[2]==1&&b[3]==2){hs=30;if(!sxaf_read(c,p,b,30))return false;n=sxaf_uint(b+18,4,false);names=sxaf_uint(b+28,2,false);if(!sxaf_add(c,&sxaf_dn_data_header,p))return false;}else if(b[2]==3&&b[3]==4){hs=46;if(!sxaf_read(c,p,b,46))return false;names=sxaf_uint(b+30,2,false);if(!sxaf_add(c,&sxaf_dn_directory_header,p))return false;}else if(b[2]==5&&b[3]==6)return sxaf_add(c,&sxaf_dn_end_marker,p);else return false;p+=hs;if(!sxaf_span(c,p,names)||!sxaf_span(c,p+names,n))return false;p+=names+n;}return true;}
bool sx_dn_build(sx_context*c)
{
 return sxaf_dn(c);
}
