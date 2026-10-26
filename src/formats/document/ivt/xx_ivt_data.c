/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MediaView titles (*.ivt) data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_ivt_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","int32",4,4,SX_OFFSET),
};
const sx_layout sxdm_ivt_header={UINT32_C(0x6023001B),"ivt_header",sxdm_ivt_header_fields,SX_COUNT(sxdm_ivt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_btree_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("unknown1","bytes",6,20,SX_NONE),
 SX_FIELD("last_leaf_page","uint32",26,4,SX_ID),
 SX_FIELD("root_page","uint32",30,4,SX_ID),
 SX_FIELD("unknown2","bytes",34,4,SX_NONE),
 SX_FIELD("page_count","int32",38,4,SX_COUNT_PROP),
 SX_FIELD("level_count","uint16",42,2,SX_COUNT_PROP),
 SX_FIELD("entry_count","int32",44,4,SX_COUNT_PROP),
};
const sx_layout sxdm_ivt_btree_header={UINT32_C(0x6023001C),"ivt_btree_header",sxdm_ivt_btree_header_fields,SX_COUNT(sxdm_ivt_btree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leaf_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("previous_page","uint32",4,4,SX_ID),
 SX_FIELD("next_page","uint32",8,4,SX_ID),
};
const sx_layout sxdm_ivt_leaf_header={UINT32_C(0x6023001D),"ivt_leaf_header",sxdm_ivt_leaf_header_fields,SX_COUNT(sxdm_ivt_leaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_index_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("first_child","uint32",4,4,SX_ID),
};
const sx_layout sxdm_ivt_index_header={UINT32_C(0x6023001E),"ivt_index_header",sxdm_ivt_index_header_fields,SX_COUNT(sxdm_ivt_index_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_key_length_fields[]={
 SX_FIELD("name_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxdm_ivt_key_length={UINT32_C(0x6023001F),"ivt_key_length",sxdm_ivt_key_length_fields,SX_COUNT(sxdm_ivt_key_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_child_pointer_fields[]={
 SX_FIELD("child_page","uint32",0,4,SX_ID),
};
const sx_layout sxdm_ivt_child_pointer={UINT32_C(0x60230020),"ivt_child_pointer",sxdm_ivt_child_pointer_fields,SX_COUNT(sxdm_ivt_child_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_entry_terminator_fields[]={
 SX_FIELD("zero","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxdm_ivt_entry_terminator={UINT32_C(0x60230021),"ivt_entry_terminator",sxdm_ivt_entry_terminator_fields,SX_COUNT(sxdm_ivt_entry_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_mszip_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxdm_ivt_mszip_header={UINT32_C(0x60230022),"ivt_mszip_header",sxdm_ivt_mszip_header_fields,SX_COUNT(sxdm_ivt_mszip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_mszip_block_header_fields[]={
 SX_FIELD("unpacked_size","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("signature","char[2]",4,2,SX_SIGNATURE),
};
const sx_layout sxdm_ivt_mszip_block_header={UINT32_C(0x60230023),"ivt_mszip_block_header",sxdm_ivt_mszip_block_header_fields,SX_COUNT(sxdm_ivt_mszip_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_1_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,1,SX_OFFSET),
};
const sx_layout sxdm_ivt_leb_offset_1={UINT32_C(0x60230024),"ivt_leb_offset_1",sxdm_ivt_leb_offset_1_fields,SX_COUNT(sxdm_ivt_leb_offset_1_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_2_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,2,SX_OFFSET),
};
const sx_layout sxdm_ivt_leb_offset_2={UINT32_C(0x60230025),"ivt_leb_offset_2",sxdm_ivt_leb_offset_2_fields,SX_COUNT(sxdm_ivt_leb_offset_2_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_3_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,3,SX_OFFSET),
};
const sx_layout sxdm_ivt_leb_offset_3={UINT32_C(0x60230026),"ivt_leb_offset_3",sxdm_ivt_leb_offset_3_fields,SX_COUNT(sxdm_ivt_leb_offset_3_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_4_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,4,SX_OFFSET),
};
const sx_layout sxdm_ivt_leb_offset_4={UINT32_C(0x60230027),"ivt_leb_offset_4",sxdm_ivt_leb_offset_4_fields,SX_COUNT(sxdm_ivt_leb_offset_4_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_5_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,5,SX_OFFSET),
};
const sx_layout sxdm_ivt_leb_offset_5={UINT32_C(0x60230028),"ivt_leb_offset_5",sxdm_ivt_leb_offset_5_fields,SX_COUNT(sxdm_ivt_leb_offset_5_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_1_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,1,SX_SIZE),
};
const sx_layout sxdm_ivt_leb_size_1={UINT32_C(0x60230029),"ivt_leb_size_1",sxdm_ivt_leb_size_1_fields,SX_COUNT(sxdm_ivt_leb_size_1_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_2_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,2,SX_SIZE),
};
const sx_layout sxdm_ivt_leb_size_2={UINT32_C(0x6023002A),"ivt_leb_size_2",sxdm_ivt_leb_size_2_fields,SX_COUNT(sxdm_ivt_leb_size_2_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_3_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,3,SX_SIZE),
};
const sx_layout sxdm_ivt_leb_size_3={UINT32_C(0x6023002B),"ivt_leb_size_3",sxdm_ivt_leb_size_3_fields,SX_COUNT(sxdm_ivt_leb_size_3_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_4_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,4,SX_SIZE),
};
const sx_layout sxdm_ivt_leb_size_4={UINT32_C(0x6023002C),"ivt_leb_size_4",sxdm_ivt_leb_size_4_fields,SX_COUNT(sxdm_ivt_leb_size_4_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_5_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,5,SX_SIZE),
};
const sx_layout sxdm_ivt_leb_size_5={UINT32_C(0x6023002D),"ivt_leb_size_5",sxdm_ivt_leb_size_5_fields,SX_COUNT(sxdm_ivt_leb_size_5_fields),SX_LE};
static const sx_layout *const sxdm_ivt_leb_offset_rows[]={&sxdm_ivt_leb_offset_1,&sxdm_ivt_leb_offset_2,&sxdm_ivt_leb_offset_3,&sxdm_ivt_leb_offset_4,&sxdm_ivt_leb_offset_5};
static const sx_layout *const sxdm_ivt_leb_size_rows[]={&sxdm_ivt_leb_size_1,&sxdm_ivt_leb_size_2,&sxdm_ivt_leb_size_3,&sxdm_ivt_leb_size_4,&sxdm_ivt_leb_size_5};
static bool sxdm_ivt_leb(sx_context *c,int64_t *at,int64_t end,bool size,uint32_t *value)
{
 int64_t start=*at;uint32_t v=0;uint8_t b;
 for(unsigned i=0;i<5;i++){if(*at>=end||!sx_read(c,(*at)++,&b,1))return false;if(i==4&&(b&0xf8))return false;v|=(uint32_t)(b&127)<<(7*i);if(!(b&128)){*value=v;return sxdm_add(c,size?sxdm_ivt_leb_size_rows[i]:sxdm_ivt_leb_offset_rows[i],start,(int64_t)i+1);}}return false;
}
static bool sxdm_ivt_mszip(sx_context *c,uint32_t off,uint32_t size)
{
 uint8_t b[12];if(size<12)return true;if(!sx_read(c,off,b,12))return false;if((xx_rt_memcmp(b,"mszp",4)&&xx_rt_memcmp(b,"nszp",4))||sxdm_u32(b+8))return true;
 if(!sxdm_add(c,&sxdm_ivt_mszip_header,off,12))return false;int64_t at=(int64_t)off+12,end=(int64_t)off+size;
 for(unsigned i=0;at<end;i++){if(i>=65536||end-at<6||!sx_read(c,at,b,6))return true;uint16_t packed=sxdm_u16(b+2);if(packed<2||packed>(uint64_t)(end-at-4)||xx_rt_memcmp(b+4,"CK",2))return true;if(!sxdm_add(c,&sxdm_ivt_mszip_block_header,at,6))return false;at+=4+packed;}return true;
}
static bool sxdm_ivt_page(sx_context *c,int64_t pages,uint32_t count,uint32_t index,unsigned depth,uint8_t *seen)
{
 uint8_t b[12];if(index>=count||seen[index]||depth>31)return false;seen[index]=1;int64_t start=pages+(int64_t)index*8192;
 if(!sx_read(c,start,b,12))return false;uint16_t unused=sxdm_u16(b),n=sxdm_u16(b+2);if(!n||unused>8180)return false;int64_t end=start+8192-unused,at=start+(depth?8:12);
 if(!sxdm_add(c,depth?&sxdm_ivt_index_header:&sxdm_ivt_leaf_header,start,depth?8:12))return false;
 if(depth&&!sxdm_ivt_page(c,pages,count,sxdm_u32(b+4),depth-1,seen))return false;
 for(unsigned i=0;i<n;i++){
  if(at>=end||!sx_read(c,at,b,1)||!b[0]||!sxdm_add(c,&sxdm_ivt_key_length,at,1))return false;uint8_t name=b[0];at++;if(name>(uint64_t)(end-at))return false;at+=name;
  if(depth){uint32_t child;if(end-at<4||!sx_u32(c,at,false,&child)||!sxdm_add(c,&sxdm_ivt_child_pointer,at,4)||!sxdm_ivt_page(c,pages,count,child,depth-1,seen))return false;at+=4;}
  else{uint32_t off,size;if(!sxdm_ivt_leb(c,&at,end,false,&off)||!sxdm_ivt_leb(c,&at,end,true,&size)||at>=end||!sx_read(c,at,b,1)||b[0]||!sxdm_add(c,&sxdm_ivt_entry_terminator,at++,1))return false;if(size&&sxdm_span(c,off,size)&&!sxdm_ivt_mszip(c,off,size))return false;}
 }return at==end;
}
static bool sxdm_ivt(sx_context *c)
{
 uint8_t b[48];uint32_t dir;if(!sx_u32(c,4,false,&dir)||dir>INT32_MAX||!sxdm_add(c,&sxdm_ivt_header,0,8)||!sx_read(c,dir,b,48)||!sxdm_add(c,&sxdm_ivt_btree_header,dir,48))return false;
 uint32_t count=sxdm_u32(b+38),root=sxdm_u32(b+30);uint16_t levels=sxdm_u16(b+42);if(!count||count>65536||!levels||levels>32||!sxdm_span(c,(int64_t)dir+48,(uint64_t)count*8192))return false;
 uint8_t *seen=xx_mem_calloc(count,1);if(!seen)return false;bool ok=sxdm_ivt_page(c,(int64_t)dir+48,count,root,levels-1,seen);xx_mem_free(seen);return ok;
}
bool sx_ivt_build(sx_context*c)
{
 return sxdm_ivt(c);
}
