/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_sbx_extractor data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_sbx_member_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("record_size","int32",4,4,SX_SIZE),
    SX_FIELD("dos_date","uint16",8,2,SX_NONE),
    SX_FIELD("dos_time","uint16",10,2,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("name_length","uint8",13,1,SX_SIZE),
};
const sx_layout sxiex_sbx_member = {0x60820001U,"sbx_member",sxiex_sbx_member_fields,SX_COUNT(sxiex_sbx_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbx_plain_size_fields[] = {
    SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
};
const sx_layout sxiex_sbx_plain_size = {0x60820002U,"sbx_plain_size",sxiex_sbx_plain_size_fields,SX_COUNT(sxiex_sbx_plain_size_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_sbx(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t h[14];if(m->header_size<18||!sxiex_read(c,m->header,h,14)||xx_rt_memcmp(h,"SB1\0",4))continue;uint64_t n=h[13];if(m->header_size!=18+n)continue;if(!SXIEX_ADD(c,sbx_member,m->header)||!sxiex_name(c,m->header+14,n)||!SXIEX_ADD(c,sbx_plain_size,m->header+14+n))return false;}return true;
}
bool sx_sfx_sbx_extractor_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_sbx(c,records);
}
#undef SXIEX_ADD
