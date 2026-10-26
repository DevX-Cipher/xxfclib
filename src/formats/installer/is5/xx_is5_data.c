/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IS5 data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_is5_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("volume_info","uint32",8,4,SX_FLAGS),
 SX_FIELD("descriptor_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("descriptor_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxan_is5_header = {UINT32_C(0x60770007),"is5_header",sxan_is5_header_fields,SX_COUNT(sxan_is5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_descriptor_fields[] = {
 SX_FIELD("unknown0","uint8[12]",0,12,SX_NONE),
 SX_FIELD("file_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown1","uint32",16,4,SX_NONE),
 SX_FIELD("file_table_size","uint32",20,4,SX_SIZE),
 SX_FIELD("repeated_table_size","uint32",24,4,SX_SIZE),
 SX_FIELD("directory_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint8[8]",32,8,SX_NONE),
 SX_FIELD("member_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("second_table_offset","uint32",44,4,SX_OFFSET),
};
const sx_layout sxan_is5_descriptor = {UINT32_C(0x60770008),"is5_descriptor",sxan_is5_descriptor_fields,SX_COUNT(sxan_is5_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_member_v5_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("directory_index","uint32",4,4,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("unknown","uint8[20]",18,20,SX_NONE),
 SX_FIELD("data_offset","uint32",38,4,SX_OFFSET),
};
const sx_layout sxan_is5_member_v5 = {UINT32_C(0x60770009),"is5_member_v5",sxan_is5_member_v5_fields,SX_COUNT(sxan_is5_member_v5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_member_v6_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint64",2,8,SX_SIZE),
 SX_FIELD("compressed_size","uint64",10,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",18,8,SX_OFFSET),
 SX_FIELD("md5","uint8[16]",26,16,SX_CHECKSUM),
 SX_FIELD("unknown1","uint8[16]",42,16,SX_NONE),
 SX_FIELD("name_offset","uint32",58,4,SX_OFFSET),
 SX_FIELD("directory_index","uint16",62,2,SX_NONE),
 SX_FIELD("unknown2","uint8[23]",64,23,SX_NONE),
};
const sx_layout sxan_is5_member_v6 = {UINT32_C(0x6077000a),"is5_member_v6",sxan_is5_member_v6_fields,SX_COUNT(sxan_is5_member_v6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_table_offset_fields[] = {
 SX_FIELD("entry_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxan_is5_table_offset = {UINT32_C(0x6077000b),"is5_table_offset",sxan_is5_table_offset_fields,SX_COUNT(sxan_is5_table_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_volume_prefix_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("first_file_index","uint32",8,4,SX_NONE),
 SX_FIELD("last_file_index","uint32",12,4,SX_NONE),
};
const sx_layout sxan_is5_volume_prefix = {UINT32_C(0x60770046),"is5_volume_prefix",sxan_is5_volume_prefix_fields,SX_COUNT(sxan_is5_volume_prefix_fields),SX_LE};
static bool sxan_is5(sx_context*c){uint64_t version,desc,descz,table,z,dirs,n,second,p,no,len;if(!sxan_add(c,&sxan_is5_header,0)||!sxan_word(c,4,4,false,&version)||!sxan_word(c,12,4,false,&desc)||!sxan_word(c,16,4,false,&descz)||descz<48||!sxan_span(c,desc,descz)||!sxan_add(c,&sxan_is5_descriptor,desc))return false;unsigned major=(version>>24)==1?(unsigned)(version>>12)&15:0;if(desc>=36&&!sxan_add(c,&sxan_is5_volume_prefix,20))return false;if(!sxan_word(c,desc+12,4,false,&table)||!sxan_word(c,desc+20,4,false,&z)||!sxan_word(c,desc+28,4,false,&dirs)||!sxan_word(c,desc+40,4,false,&n)||!sxan_word(c,desc+44,4,false,&second))return false;table+=desc;if(!sxan_span(c,table,z)||dirs>z/4||!sxan_table(c,&sxan_is5_table_offset,table,4,dirs))return false;for(uint64_t i=0;i<dirs;i++){if(!sxan_word(c,table+4*i,4,false,&no)||no>=z||!sxan_zlen(c,table+no,table+z,&len)||!sxan_named(c,table+no,len))return false;}
 for(uint64_t i=0;i<n;i++){if(major>=6){if(second>z||i>=(z-second)/87)return false;p=table+second+i*87;if(!sxan_add(c,&sxan_is5_member_v6,p)||!sxan_word(c,p+58,4,false,&no))return false;}else{if(dirs+i>=z/4||!sxan_add(c,&sxan_is5_table_offset,table+4*(dirs+i))||!sxan_word(c,table+4*(dirs+i),4,false,&p)||p>z||z-p<42)return false;p+=table;if(!sxan_add(c,&sxan_is5_member_v5,p)||!sxan_word(c,p,4,false,&no))return false;}uint64_t flags,packed;if(!sxan_word(c,p+(major>=6?0:8),2,false,&flags)||!sxan_word(c,p+(major>=6?10:14),major>=6?8:4,false,&packed))return false;if(!(flags&8)&&packed&&no<z&&sxan_zlen(c,table+no,table+z,&len)&&!sxan_named(c,table+no,len))return false;}return true;}
bool sx_is5_build(sx_context*c)
{
bool ok=false;
ok=sxan_is5(c);
(void)ok;return c->count&&sxan_finish(c);
}
