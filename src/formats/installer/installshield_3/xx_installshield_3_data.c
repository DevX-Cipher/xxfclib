/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InstallShield 3.x/5.x SFX data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_installshield3_descriptor_fields[] = {
    SX_FIELD("descriptor_size","uint32",0,4,SX_SIZE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("file_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("end_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("unknown","uint32",20,4,SX_NONE),
    SX_FIELD("reserved","uint32",24,4,SX_RESERVED),
    SX_FIELD("encoded_unused_string","byte[40]",28,40,SX_NONE),
    SX_FIELD("encoded_command","byte[128]",68,128,SX_NONE),
    SX_FIELD("encoded_product_title","byte[80]",196,80,SX_NONE),
    SX_FIELD("encoded_source_directory","byte[128]",276,128,SX_NONE),
};
const sx_layout sxil_installshield3_descriptor = {0x60850025U,"installshield3_descriptor",sxil_installshield3_descriptor_fields,SX_COUNT(sxil_installshield3_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield3_name_size_fields[] = {
    SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_installshield3_name_size = {0x60850026U,"installshield3_name_size",sxil_installshield3_name_size_fields,SX_COUNT(sxil_installshield3_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield3_member_fields[] = {
    SX_FIELD("dos_date","uint16",0,2,SX_NONE),
    SX_FIELD("dos_time","uint16",2,2,SX_NONE),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxil_installshield3_member = {0x60850027U,"installshield3_member",sxil_installshield3_member_fields,SX_COUNT(sxil_installshield3_member_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_is3(sx_context*c,sxil_records*r){
 if(!r->count)return true;uint64_t p=0,start=0;uint8_t b[28];static const uint8_t magic[]={0x94,1,0,0,6,0,0,0};
 uint32_t resource_size; if(sxil_resource(c,1024,0,"MYRESOURCE",&p,&resource_size)&&resource_size>=404){if(!SXIL_ADD(c,installshield3_descriptor,p))return false;}
 while(sxil_find(c,magic,8,start,r->items[0].header,&p)){start=p+8;if(!sxil_read(c,p,b,28))break;if(sxil32(b+8,false)==r->items[0].header&&sxil32(b+12,false)>=r->count){if(!SXIL_ADD(c,installshield3_descriptor,p))return false;break;}}
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;uint32_t n;if(!sxil_u32(c,m->header,&n)||!n||n>1024||(uint64_t)n+12!=m->header_size)continue;if(!SXIL_ADD(c,installshield3_name_size,m->header)||!sxil_encoded(c,m->header+4,n)||!SXIL_ADD(c,installshield3_member,m->header+4+n))return false;}return true;
}
bool sx_installshield_3_build(sx_context*c,sxil_records records)
{
 return sxil_is3(c,&records);
}
#undef SXIL_ADD
