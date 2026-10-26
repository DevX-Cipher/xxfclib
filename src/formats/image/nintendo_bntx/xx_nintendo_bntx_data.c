/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo bntx data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_bntx_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("byte_order","uint16",12,2,SX_ID),
    SX_FIELD("alignment_shift","uint8",14,1,SX_NONE),
    SX_FIELD("target_address_bits","uint8",15,1,SX_NONE),
    SX_FIELD("filename_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("flags","uint16",20,2,SX_FLAGS),
    SX_FIELD("first_block_offset","uint16",22,2,SX_OFFSET),
    SX_FIELD("relocation_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxrm_bntx_header = {UINT32_C(0x601d001a),"bntx_header",sxrm_bntx_header_fields,SX_COUNT(sxrm_bntx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_container_fields[] = {
    SX_FIELD("target","char[4]",0,4,SX_ID),
    SX_FIELD("texture_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("texture_pointer_table_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("data_block_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("dictionary_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("memory_pool_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("memory_pool_pointer","uint64",40,8,SX_POINTER),
    SX_FIELD("base_memory_pool_offset","uint32",48,4,SX_OFFSET),
    SX_FIELD("padding","uint8[4]",52,4,SX_RESERVED),
};
const sx_layout sxrm_bntx_container = {UINT32_C(0x601d001b),"bntx_container",sxrm_bntx_container_fields,SX_COUNT(sxrm_bntx_container_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_block_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("next_block_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("block_size","uint32",8,4,SX_SIZE),
    SX_FIELD("padding","uint8[4]",12,4,SX_RESERVED),
};
const sx_layout sxrm_bntx_block = {UINT32_C(0x601d001c),"bntx_block",sxrm_bntx_block_fields,SX_COUNT(sxrm_bntx_block_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_texture_info_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("dimensions","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("tile_mode","uint16",2,2,SX_ID),
    SX_FIELD("swizzle","uint16",4,2,SX_NONE),
    SX_FIELD("mipmap_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sample_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("padding0","uint8[2]",10,2,SX_RESERVED),
    SX_FIELD("format","uint32",12,4,SX_ID),
    SX_FIELD("access_flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("width","int32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("depth","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("array_length","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("texture_layout","uint32",36,4,SX_FLAGS),
    SX_FIELD("texture_layout2","uint32",40,4,SX_FLAGS),
    SX_FIELD("padding1","uint8[20]",44,20,SX_RESERVED),
    SX_FIELD("image_size","uint32",64,4,SX_SIZE),
    SX_FIELD("alignment_bytes","uint32",68,4,SX_SIZE),
    SX_FIELD("component_selection","uint32",72,4,SX_FLAGS),
    SX_FIELD("texture_type","uint8",76,1,SX_ID),
    SX_FIELD("padding2","uint8[3]",77,3,SX_RESERVED),
    SX_FIELD("name_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("parent_offset","uint64",88,8,SX_OFFSET),
    SX_FIELD("mipmap_pointer_table_offset","uint64",96,8,SX_OFFSET),
    SX_FIELD("user_data_offset","uint64",104,8,SX_OFFSET),
    SX_FIELD("texture_pointer","uint64",112,8,SX_POINTER),
    SX_FIELD("texture_view_pointer","uint64",120,8,SX_POINTER),
    SX_FIELD("descriptor_slot_offset","uint64",128,8,SX_OFFSET),
    SX_FIELD("user_dictionary_offset","uint64",136,8,SX_OFFSET),
};
const sx_layout sxrm_bntx_texture_info = {UINT32_C(0x601d001d),"bntx_texture_info",sxrm_bntx_texture_info_fields,SX_COUNT(sxrm_bntx_texture_info_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_pointer_fields[] = {
    SX_FIELD("file_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxrm_bntx_pointer = {UINT32_C(0x601d001e),"bntx_pointer",sxrm_bntx_pointer_fields,SX_COUNT(sxrm_bntx_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_string_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxrm_bntx_string_length = {UINT32_C(0x601d001f),"bntx_string_length",sxrm_bntx_string_length_fields,SX_COUNT(sxrm_bntx_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_relocation_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("self_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("section_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxrm_bntx_relocation_header = {UINT32_C(0x601d0020),"bntx_relocation_header",sxrm_bntx_relocation_header_fields,SX_COUNT(sxrm_bntx_relocation_header_fields),SX_LE};
static bool sxrm_bntx_name(sx_context *c,uint64_t p){uint8_t b[2];return !sxrm_read(c,p,b,2)||!sxrm_span(c,p+2,sxrm16(b,false))||sxrm_add(c,&sxrm_bntx_string_length,p);}
static bool sxrm_bntx(sx_context *c)
{
 uint8_t h[160];if(!sxrm_read(c,0,h,88)||xx_rt_memcmp(h,"BNTX\0\0\0\0",8)||!sxrm_add(c,&sxrm_bntx_header,0)||!sxrm_add(c,&sxrm_bntx_container,32))return false;
 uint64_t table=sxrm_uint(h+40,8,false),data=sxrm_uint(h+48,8,false);uint32_t count=sxrm32(h+36,false),reloc=sxrm32(h+24,false),name=sxrm32(h+16,false);
 if(name>=2&&!sxrm_bntx_name(c,name-2))return false;
 if(data>=88&&sxrm_read(c,data,h,16)&&!xx_rt_memcmp(h,"BRTD",4)&&!sxrm_add(c,&sxrm_bntx_block,data))return false;
 if(reloc>=88&&sxrm_read(c,reloc,h,16)&&!xx_rt_memcmp(h,"_RLT",4)&&!sxrm_add(c,&sxrm_bntx_relocation_header,reloc))return false;
 if(count>1024||table<88||!sxrm_span(c,table,(uint64_t)count*8))return true;if(!sxrm_table(c,&sxrm_bntx_pointer,table,count))return false;
 for(uint32_t i=0;i<count;i++){if(!sxrm_read(c,table+(uint64_t)i*8,h,8))return false;uint64_t q=sxrm_uint(h,8,false);if(q<88||!sxrm_read(c,q,h,160)||xx_rt_memcmp(h,"BRTI",4))continue;
  if(!sxrm_add(c,&sxrm_bntx_block,q)||!sxrm_add(c,&sxrm_bntx_texture_info,q+16))return false;uint64_t nameoff=sxrm_uint(h+96,8,false),mips=sxrm_uint(h+112,8,false);unsigned n=sxrm16(h+22,false);
  if(nameoff>=88&&!sxrm_bntx_name(c,nameoff))return false;if(n<=16&&mips>=88&&sxrm_span(c,mips,(uint64_t)n*8)&&!sxrm_table(c,&sxrm_bntx_pointer,mips,n))return false;
 }return !c->failed;
}
bool sx_nintendo_bntx_build(sx_context*c)
{
 return sxrm_bntx(c);
}
