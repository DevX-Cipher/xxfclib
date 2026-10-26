/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * larian_lsf data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_lsf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("engine_version","int32",8,4,SX_ID),
 SX_FIELD("strings_uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("strings_stored_size","uint32",16,4,SX_SIZE),
 SX_FIELD("nodes_uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("nodes_stored_size","uint32",24,4,SX_SIZE),
 SX_FIELD("attributes_uncompressed_size","uint32",28,4,SX_SIZE),
 SX_FIELD("attributes_stored_size","uint32",32,4,SX_SIZE),
 SX_FIELD("values_uncompressed_size","uint32",36,4,SX_SIZE),
 SX_FIELD("values_stored_size","uint32",40,4,SX_SIZE),
 SX_FIELD("compression_flags","uint8",44,1,SX_FLAGS),
 SX_FIELD("unknown2","uint8",45,1,SX_NONE),
 SX_FIELD("unknown3","uint16",46,2,SX_NONE),
 SX_FIELD("metadata_format","uint32",48,4,SX_ID),
};
const sx_layout sxgp_lsf_header={UINT32_C(0x60360065),"lsf_header",sxgp_lsf_header_fields,SX_COUNT(sxgp_lsf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_string_table_fields[]={
 SX_FIELD("bucket_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgp_lsf_string_table={UINT32_C(0x60360066),"lsf_string_table",sxgp_lsf_string_table_fields,SX_COUNT(sxgp_lsf_string_table_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_bucket_fields[]={
 SX_FIELD("string_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxgp_lsf_bucket={UINT32_C(0x60360067),"lsf_bucket",sxgp_lsf_bucket_fields,SX_COUNT(sxgp_lsf_bucket_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_string_fields[]={
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxgp_lsf_string={UINT32_C(0x60360068),"lsf_string",sxgp_lsf_string_fields,SX_COUNT(sxgp_lsf_string_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_node_fields[]={
 SX_FIELD("name_reference","uint32",0,4,SX_ID),
 SX_FIELD("first_attribute_index","int32",4,4,SX_ID),
 SX_FIELD("parent_index","int32",8,4,SX_ID),
};
const sx_layout sxgp_lsf_node={UINT32_C(0x60360069),"lsf_node",sxgp_lsf_node_fields,SX_COUNT(sxgp_lsf_node_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_attribute_fields[]={
 SX_FIELD("name_reference","uint32",0,4,SX_ID),
 SX_FIELD("type_length","uint32",4,4,SX_FLAGS),
 SX_FIELD("node_index","int32",8,4,SX_ID),
};
const sx_layout sxgp_lsf_attribute={UINT32_C(0x6036006A),"lsf_attribute",sxgp_lsf_attribute_fields,SX_COUNT(sxgp_lsf_attribute_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_lsf(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=52,z[4],buckets;if(!SG_ROW(lsf_header,0,end))return false;for(unsigned i=0;i<4;i++)if(!sxgp_word(v,12+i*8,4,false,&z[i],end))return false;
 if(!sxgp_span(v,p,z[0],end)||!SG_ROW(lsf_string_table,p,p+z[0])||!sxgp_word(v,p,4,false,&buckets,p+z[0])||buckets>4096)return false;uint64_t stop=p+z[0];p+=4;
 for(uint64_t i=0;i<buckets;i++){uint64_t n,len;if(!SG_ROW(lsf_bucket,p,stop)||!sxgp_word(v,p,2,false,&n,stop))return false;p+=2;for(uint64_t j=0;j<n;j++){if(!SG_ROW(lsf_string,p,stop)||!sxgp_word(v,p,2,false,&len,stop)||!sxgp_span(v,p+2,len,stop))return false;p+=2+len;}}
 if(p!=stop||z[1]%12||z[2]%12||!sxgp_table(v,&sxgp_lsf_node,p,z[1]/12,end))return false;p+=z[1];return sxgp_table(v,&sxgp_lsf_attribute,p,z[2]/12,end)&&sxgp_span(v,p+z[2],z[3],end);}
bool sx_larian_lsf_build(sxgp_view*v)
{
 return sxgp_lsf(v);
}
#undef SG_ROW
