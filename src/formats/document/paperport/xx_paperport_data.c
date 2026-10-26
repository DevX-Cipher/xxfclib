/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PaperPort desktop files data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_paperport_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("variant","uint8",3,1,SX_ID),
 SX_FIELD("unknown1","uint8",4,1,SX_NONE),
 SX_FIELD("marker","uint8",5,1,SX_SIGNATURE),
 SX_FIELD("metadata","bytes",6,158,SX_NONE),
 SX_FIELD("root_offset","int32",164,4,SX_OFFSET),
 SX_FIELD("unknown_tail","bytes",168,32,SX_NONE),
};
const sx_layout sxdm_paperport_header={UINT32_C(0x60230010),"paperport_header",sxdm_paperport_header_fields,SX_COUNT(sxdm_paperport_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_chunk_header_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("payload_size","int32",2,4,SX_SIZE),
 SX_FIELD("unknown1","bytes",6,20,SX_NONE),
 SX_FIELD("chunk_type","uint16",26,2,SX_ID),
 SX_FIELD("unknown2","bytes",28,4,SX_NONE),
};
const sx_layout sxdm_paperport_chunk_header={UINT32_C(0x60230011),"paperport_chunk_header",sxdm_paperport_chunk_header_fields,SX_COUNT(sxdm_paperport_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_root_prefix_fields[]={
 SX_FIELD("page_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("unknown1","bytes",2,8,SX_NONE),
 SX_FIELD("page_count_copy","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown2","bytes",12,10,SX_NONE),
};
const sx_layout sxdm_paperport_root_prefix={UINT32_C(0x60230012),"paperport_root_prefix",sxdm_paperport_root_prefix_fields,SX_COUNT(sxdm_paperport_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_root_entry_fields[]={
 SX_FIELD("unknown1","bytes",0,4,SX_NONE),
 SX_FIELD("item_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("unknown2","bytes",8,4,SX_NONE),
};
const sx_layout sxdm_paperport_root_entry={UINT32_C(0x60230013),"paperport_root_entry",sxdm_paperport_root_entry_fields,SX_COUNT(sxdm_paperport_root_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_page_item_fields[]={
 SX_FIELD("unknown1","bytes",0,34,SX_NONE),
 SX_FIELD("image_offset","int32",34,4,SX_OFFSET),
 SX_FIELD("unknown2","bytes",38,24,SX_NONE),
};
const sx_layout sxdm_paperport_page_item={UINT32_C(0x60230014),"paperport_page_item",sxdm_paperport_page_item_fields,SX_COUNT(sxdm_paperport_page_item_fields),SX_LE};
static bool sxdm_pp_chunk(sx_context *c,int64_t at,uint16_t type,uint32_t minimum,uint32_t *size)
{
 uint8_t b[32];if(!sx_read(c,at,b,32)||xx_rt_memcmp(b,"VZ",2)||sxdm_u16(b+26)!=type||(int32_t)sxdm_u32(b+2)<0)return false;*size=sxdm_u32(b+2);return *size>=minimum&&sxdm_span(c,at+32,*size)&&sxdm_add(c,&sxdm_paperport_chunk_header,at,32);
}
static bool sxdm_paperport(sx_context *c)
{
 uint8_t b[200];uint32_t n;if(!sx_read(c,0,b,200)||!sxdm_add(c,&sxdm_paperport_header,0,200))return false;int64_t root=(int32_t)sxdm_u32(b+164);
 if(!sxdm_pp_chunk(c,root,0x8000,54,&n)||!sx_read(c,root+32,b,22)||!sxdm_add(c,&sxdm_paperport_root_prefix,root+32,22))return false;uint16_t count=sxdm_u16(b);if((uint64_t)count*12>n-22)return false;
 for(unsigned i=0;i<count;i++){int64_t at=root+54+(int64_t)i*12;if(!sx_read(c,at,b,12)||!sxdm_add(c,&sxdm_paperport_root_entry,at,12))return false;int64_t item=(int32_t)sxdm_u32(b+4);if(!sxdm_pp_chunk(c,item,0x4000,62,&n)||!sx_read(c,item+32,b,62)||!sxdm_add(c,&sxdm_paperport_page_item,item+32,62)||!sxdm_pp_chunk(c,(int32_t)sxdm_u32(b+34),0x1000,136,&n))return false;}return true;
}
bool sx_paperport_build(sx_context*c)
{
 return sxdm_paperport(c);
}
