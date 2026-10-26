/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_flashjester_jugglor data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_jugglor_member_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name_storage","char[255]",5,255,SX_NONE),
    SX_FIELD("directory_length","uint8",260,1,SX_SIZE),
    SX_FIELD("directory_storage","char[255]",261,255,SX_NONE),
    SX_FIELD("unused_string_length","uint8",516,1,SX_SIZE),
    SX_FIELD("unused_string_storage","byte[255]",517,255,SX_NONE),
    SX_FIELD("unpacked_size","uint32",772,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",776,4,SX_SIZE),
    SX_FIELD("local_filetime","uint64",780,8,SX_TIME),
    SX_FIELD("unknown","byte[4]",788,4,SX_NONE),
    SX_FIELD("end_signature","uint32",792,4,SX_SIGNATURE),
};
const sx_layout sxiex_jugglor_member = {0x6082003fU,"jugglor_member",sxiex_jugglor_member_fields,SX_COUNT(sxiex_jugglor_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_exeattachment_member_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name_storage","char[255]",5,255,SX_NONE),
    SX_FIELD("directory_length","uint8",260,1,SX_SIZE),
    SX_FIELD("directory_storage","char[255]",261,255,SX_NONE),
    SX_FIELD("unpacked_size","uint32",516,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",520,4,SX_SIZE),
    SX_FIELD("local_filetime","uint64",524,8,SX_TIME),
    SX_FIELD("unknown","byte[8]",532,8,SX_NONE),
    SX_FIELD("end_signature","uint32",540,4,SX_SIGNATURE),
};
const sx_layout sxiex_exeattachment_member = {0x60820040U,"exeattachment_member",sxiex_exeattachment_member_fields,SX_COUNT(sxiex_exeattachment_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_jugglor_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("overlay_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("chain_size","uint32",8,4,SX_SIZE),
    SX_FIELD("file_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("producer_value","uint32",16,4,SX_NONE),
    SX_FIELD("unpacked_size_sum","uint32",20,4,SX_SIZE),
    SX_FIELD("version_length","uint8",24,1,SX_SIZE),
    SX_FIELD("version_storage","char[187]",25,187,SX_NONE),
    SX_FIELD("unknown","uint32",212,4,SX_NONE),
    SX_FIELD("end_signature","uint32",216,4,SX_SIGNATURE),
};
const sx_layout sxiex_jugglor_trailer = {0x60820041U,"jugglor_trailer",sxiex_jugglor_trailer_fields,SX_COUNT(sxiex_jugglor_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_exeattachment_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","byte[270]",4,270,SX_NONE),
    SX_FIELD("end_signature","uint32",274,4,SX_SIGNATURE),
};
const sx_layout sxiex_exeattachment_trailer = {0x60820042U,"exeattachment_trailer",sxiex_exeattachment_trailer_fields,SX_COUNT(sxiex_exeattachment_trailer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_jugglor(sx_context*c,const sxiex_records*r){
 uint64_t end=0;bool jugglor=false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=796&&m->header_size!=544)continue;jugglor=m->header_size==796;if(!sxiex_put(c,jugglor?&sxiex_jugglor_member:&sxiex_exeattachment_member,m->header,1))return false;
 uint64_t e=m->data+m->packed;if(!jugglor&&sxiex_span(c,e,278)&&sxiex_eq(c,e,"\xa3\x61\x4a\x6a",4)&&!SXIEX_ADD(c,exeattachment_trailer,e))return false;if(e>end)end=e;}
 if(jugglor&&end&&sxiex_span(c,end,220)&&sxiex_eq(c,end,"\xa3\x61\x4a\x6a",4)&&!SXIEX_ADD(c,jugglor_trailer,end))return false;return true;
}
bool sx_sfx_flashjester_jugglor_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_jugglor(c,records);
}
#undef SXIEX_ADD
