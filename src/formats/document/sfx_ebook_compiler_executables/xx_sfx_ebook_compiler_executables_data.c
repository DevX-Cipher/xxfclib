/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_ebook_compiler_executables data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_ebook_creator_header_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("list_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("new_class_marker","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("directory_schema","uint16",6,2,SX_ID),
    SX_FIELD("directory_class_name_length","uint16",8,2,SX_SIZE),
    SX_FIELD("directory_class_name","char[10]",10,10,SX_NONE),
    SX_FIELD("list_identifier","uint16",20,2,SX_ID),
    SX_FIELD("file_count","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("new_element_marker","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("element_schema","uint16",26,2,SX_ID),
    SX_FIELD("element_class_name_length","uint16",28,2,SX_SIZE),
    SX_FIELD("element_class_name","char[11]",30,11,SX_NONE),
    SX_FIELD("element_identifier","uint16",41,2,SX_ID),
};
const sx_layout sxiex_ebook_creator_header = {0x60820043U,"ebook_creator_header",sxiex_ebook_creator_header_fields,SX_COUNT(sxiex_ebook_creator_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_member_fields[] = {
    SX_FIELD("block_size","int32",0,4,SX_SIZE),
    SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
const sx_layout sxiex_ebook_creator_member = {0x60820044U,"ebook_creator_member",sxiex_ebook_creator_member_fields,SX_COUNT(sxiex_ebook_creator_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_ref_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("element_identifier","uint16",2,2,SX_ID),
};
const sx_layout sxiex_ebook_creator_ref = {0x60820045U,"ebook_creator_ref",sxiex_ebook_creator_ref_fields,SX_COUNT(sxiex_ebook_creator_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_list_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("list_identifier","uint16",2,2,SX_ID),
    SX_FIELD("element_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxiex_ebook_creator_list = {0x60820046U,"ebook_creator_list",sxiex_ebook_creator_list_fields,SX_COUNT(sxiex_ebook_creator_list_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_element_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("element_type","uint16",2,2,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_ebook_creator_element = {0x60820047U,"ebook_creator_element",sxiex_ebook_creator_element_fields,SX_COUNT(sxiex_ebook_creator_element_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_name_fields[] = {
    SX_FIELD("file_index","uint32",0,4,SX_NONE),
    SX_FIELD("flags1","uint32",4,4,SX_FLAGS),
    SX_FIELD("flags2","uint32",8,4,SX_FLAGS),
    SX_FIELD("flags3","uint32",12,4,SX_FLAGS),
};
const sx_layout sxiex_ebook_creator_name = {0x60820048U,"ebook_creator_name",sxiex_ebook_creator_name_fields,SX_COUNT(sxiex_ebook_creator_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_ebook_creator_footer_fields[] = {
    SX_FIELD("overlay_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","char[2]",4,2,SX_SIGNATURE),
};
const sx_layout sxiex_ebook_creator_footer = {0x60820049U,"ebook_creator_footer",sxiex_ebook_creator_footer_fields,SX_COUNT(sxiex_ebook_creator_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("signature","char[5]",4,5,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",9,4,SX_NONE),
};
const sx_layout sxiex_sbook_header = {0x6082004aU,"sbook_header",sxiex_sbook_header_fields,SX_COUNT(sxiex_sbook_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_count_fields[] = {
    SX_FIELD("count_or_zero","uint32",0,4,SX_NONE),
};
const sx_layout sxiex_sbook_count = {0x6082004bU,"sbook_count",sxiex_sbook_count_fields,SX_COUNT(sxiex_sbook_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_name_length_fields[] = {
    SX_FIELD("name_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_sbook_name_length = {0x6082004cU,"sbook_name_length",sxiex_sbook_name_length_fields,SX_COUNT(sxiex_sbook_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_member_fields[] = {
    SX_FIELD("dos_datetime","uint32",0,4,SX_NONE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
};
const sx_layout sxiex_sbook_member = {0x6082004dU,"sbook_member",sxiex_sbook_member_fields,SX_COUNT(sxiex_sbook_member_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_chunk_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_sbook_chunk = {0x6082004eU,"sbook_chunk",sxiex_sbook_chunk_fields,SX_COUNT(sxiex_sbook_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sbook_footer_fields[] = {
    SX_FIELD("zero1","uint32",0,4,SX_RESERVED),
    SX_FIELD("zero2","uint32",4,4,SX_RESERVED),
    SX_FIELD("overlay_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxiex_sbook_footer = {0x6082004fU,"sbook_footer",sxiex_sbook_footer_fields,SX_COUNT(sxiex_sbook_footer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_ebook(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint32_t v;if(!sxiex_pe(c,&p))return true;
 if(sxiex_eq(c,p,"\0\0\x02\0\xff\xff",6)){
  if(!sxiex_span(c,p,43)||!SXIEX_ADD(c,ebook_creator_header,p))return false;uint64_t end=0;
  for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=27&&m->header_size!=12)continue;if(m->header_size==12&&!SXIEX_ADD(c,ebook_creator_ref,m->header))return false;if(!SXIEX_ADD(c,ebook_creator_member,m->data-8))return false;if(m->data+m->packed>end)end=m->data+m->packed;}
  uint8_t h[8];if(end&&sxiex_read(c,end,h,6)&&sxiex16(h,false)==0x8001){uint16_t n=sxiex16(h+4,false);if(!SXIEX_ADD(c,ebook_creator_list,end))return false;uint64_t at=end+6;
   for(unsigned i=0;i<n&&i<24000;i++){if(!sxiex_read(c,at,h,8))break;uint64_t z=sxiex32(h+4,false);if(sxiex16(h,false)!=0x8003||!sxiex_span(c,at+8,z))break;if(!SXIEX_ADD(c,ebook_creator_element,at))return false;
    if(sxiex16(h+2,false)==2){uint64_t q=at+8,e=q+z;while(q<e){if(!sxiex_zstr(c,&q,e)||e-q<16)break;if(!SXIEX_ADD(c,ebook_creator_name,q))return false;q+=16;}}at+=8+z;}
  }
  if(c->size>=6&&sxiex_u32(c,(uint64_t)c->size-6,&v)&&v==p&&!SXIEX_ADD(c,ebook_creator_footer,(uint64_t)c->size-6))return false;
 }else if(sxiex_u32(c,p,&v)&&v==5&&(sxiex_eq(c,p+4,"Sbook",5)||sxiex_eq(c,p+4,"Ebook",5))){
  if(!SXIEX_ADD(c,sbook_header,p))return false;uint64_t end=0;
  for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint32_t n;if(!sxiex_u32(c,m->header+4,&n)||m->header_size!=16U+(uint64_t)n)continue;
   if(!SXIEX_ADD(c,sbook_count,m->header)||!SXIEX_ADD(c,sbook_name_length,m->header+4)||!sxiex_name(c,m->header+8,n)||!SXIEX_ADD(c,sbook_member,m->header+8+n))return false;
   uint64_t q=m->data,e=q+m->packed;while(e-q>=4){uint32_t z;if(!sxiex_u32(c,q,&z)||z>e-q-4)break;if(!SXIEX_ADD(c,sbook_chunk,q))return false;q+=4+z;}if(e>end)end=e;
  }
  if(end&&sxiex_span(c,end,12)&&!SXIEX_ADD(c,sbook_footer,end))return false;
 }
 return true;
}
bool sx_sfx_ebook_compiler_executables_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_ebook(c,records);
}
#undef SXIEX_ADD
