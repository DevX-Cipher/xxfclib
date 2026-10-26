/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PAKLEO (.PLL) archives data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_pakleo_header_fields[] = {
 SX_FIELD("banner","char[37]",0,37,SX_SIGNATURE),
};
const sx_layout sxafr_pakleo_header = {UINT32_C(0x60540006),"pakleo_header",sxafr_pakleo_header_fields,SX_COUNT(sxafr_pakleo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_pakleo_member_fields[] = {
 SX_FIELD("unused1","uint8[2]",0,2,SX_NONE),
 SX_FIELD("method_tag","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","int32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",11,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("dos_date","uint16",17,2,SX_NONE),
 SX_FIELD("unused2","uint8[2]",19,2,SX_NONE),
 SX_FIELD("crc32","uint32",21,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",25,1,SX_SIZE),
};
const sx_layout sxafr_pakleo_member = {UINT32_C(0x60540007),"pakleo_member",sxafr_pakleo_member_fields,SX_COUNT(sxafr_pakleo_member_fields),SX_LE};
static bool sxafr_pakleo(sx_context*c){uint64_t p=37;if(!sxafr_add(c,&sxafr_pakleo_header,0))return false;while(p<(uint64_t)c->size){uint8_t h[26];if(!sxafr_read(c,p,h,26)||h[2]!='-'||h[3]!='l'||h[4]!='l'||h[5]<'0'||h[5]>'9'||h[6]!='-')return false;uint64_t z=sxafr_uint(h+7,4,false),n=h[25];if(z>INT32_MAX||!sxafr_span(c,p+26,n)||!sxafr_add(c,&sxafr_pakleo_member,p))return false;p+=26+n;if(!sxafr_span(c,p,z))return false;p+=z;}return true;}
bool sx_pakleo_build(sx_context*c)
{
 return sxafr_pakleo(c);
}
