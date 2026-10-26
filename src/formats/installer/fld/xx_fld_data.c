/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FLD data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_fld_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",17,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("method","uint8",25,1,SX_NONE),
 SX_FIELD("marker","char[1]",26,1,SX_SIGNATURE),
};
const sx_layout sxasy_fld_member = {UINT32_C(0x60440010),"fld_member",sxasy_fld_member_fields,SX_COUNT(sxasy_fld_member_fields),SX_LE};
static bool sxasy_fld(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&sxasy_span(c,p,27);i++){uint8_t h[27];if(!sxasy_read(c,p,h,27)||h[0]!=12||h[26]!='$')return false;uint64_t n=sxasy_uint(h+13,4,false);if(n>INT32_MAX||!sxasy_span(c,p+27,n)||!sxasy_add(c,&sxasy_fld_member,p))return false;if(h[25]==1&&!sxasy_dcl(c,p+27,n))return false;p+=27+n;}return true;}
bool sx_fld_build(sx_context*c)
{
 return sxasy_fld(c);
}
