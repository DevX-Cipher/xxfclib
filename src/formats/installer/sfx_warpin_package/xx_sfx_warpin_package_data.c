/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_warpin_package data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_warpin_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("format_revision","uint16",4,2,SX_ID),
    SX_FIELD("description","char[512]",6,512,SX_NONE),
    SX_FIELD("application_revision","uint16",518,2,SX_ID),
    SX_FIELD("operating_system","uint16",520,2,SX_ID),
    SX_FIELD("package_count","uint16",522,2,SX_COUNT_PROP),
    SX_FIELD("script_unpacked_size_low","uint16",524,2,SX_NONE),
    SX_FIELD("script_packed_size","uint16",526,2,SX_SIZE),
    SX_FIELD("optional_blob_size","int32",528,4,SX_SIZE),
};
const sx_layout sxiex_warpin_header = {0x60820010U,"warpin_header",sxiex_warpin_header_fields,SX_COUNT(sxiex_warpin_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_warpin_extension_fields[] = {
    SX_FIELD("extension_size","int32",0,4,SX_SIZE),
};
const sx_layout sxiex_warpin_extension = {0x60820011U,"warpin_extension",sxiex_warpin_extension_fields,SX_COUNT(sxiex_warpin_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_warpin_package_fields[] = {
    SX_FIELD("package_id","uint16",0,2,SX_ID),
    SX_FIELD("file_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("data_offset","int32",4,4,SX_OFFSET),
    SX_FIELD("unpacked_size","int32",8,4,SX_SIZE),
    SX_FIELD("packed_size","int32",12,4,SX_SIZE),
    SX_FIELD("description","char[32]",16,32,SX_NONE),
};
const sx_layout sxiex_warpin_package = {0x60820012U,"warpin_package",sxiex_warpin_package_fields,SX_COUNT(sxiex_warpin_package_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_warpin_member_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("unknown","uint16",2,2,SX_NONE),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("package_id","uint16",6,2,SX_ID),
    SX_FIELD("unpacked_size","int32",8,4,SX_SIZE),
    SX_FIELD("packed_size","int32",12,4,SX_SIZE),
    SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("name","char[256]",20,256,SX_NONE),
    SX_FIELD("modification_time","uint32",276,4,SX_TIME),
    SX_FIELD("creation_time","uint32",280,4,SX_TIME),
    SX_FIELD("extension","uint8",284,1,SX_ID),
};
const sx_layout sxiex_warpin_member = {0x60820013U,"warpin_member",sxiex_warpin_member_fields,SX_COUNT(sxiex_warpin_member_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_warpin(sx_context*c,const sxiex_records*r){
 uint8_t h[532];if(!sxiex_read(c,0,h,sizeof(h))||sxiex32(h,false)!=0xbe020477U)return true;
 if(!SXIEX_ADD(c,warpin_header,0))return false;uint64_t at=532;uint16_t rev=sxiex16(h+4,false),count=sxiex16(h+522,false),packed=sxiex16(h+526,false);uint32_t optional=sxiex32(h+528,false);
 if(rev==4){uint32_t n;if(!sxiex_u32(c,at,&n)||n<40||!sxiex_span(c,at,n))return true;if(!SXIEX_ADD(c,warpin_extension,at))return false;at+=n;}
 if(!sxiex_span(c,at,(uint64_t)packed+optional))return true;at+=packed+optional;
 if(sxiex_span(c,at,(uint64_t)count*48)&&!sxiex_put(c,&sxiex_warpin_package,at,count))return false;
 for(size_t i=0;i<r->count;i++)if(r->items[i].header_size==285&&sxiex_eq(c,r->items[i].header,"\x12\xf0",2)&&!SXIEX_ADD(c,warpin_member,r->items[i].header))return false;
 return true;
}
bool sx_sfx_warpin_package_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_warpin(c,records);
}
#undef SXIEX_ADD
