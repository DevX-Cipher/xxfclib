/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * unityfs data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_unity_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",8,4,SX_ID),
};
const sx_layout sxgp_unity_header={UINT32_C(0x60360039),"unity_header",sxgp_unity_header_fields,SX_COUNT(sxgp_unity_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_sizes_fields[]={
 SX_FIELD("file_size","int64",0,8,SX_SIZE),
 SX_FIELD("compressed_info_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_info_size","uint32",12,4,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
};
const sx_layout sxgp_unity_sizes={UINT32_C(0x6036003A),"unity_sizes",sxgp_unity_sizes_fields,SX_COUNT(sxgp_unity_sizes_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_info_fields[]={
 SX_FIELD("data_hash","bytes",0,16,SX_CHECKSUM),
 SX_FIELD("block_count","int32",16,4,SX_COUNT_PROP),
};
const sx_layout sxgp_unity_info={UINT32_C(0x6036003B),"unity_info",sxgp_unity_info_fields,SX_COUNT(sxgp_unity_info_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_block_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
const sx_layout sxgp_unity_block={UINT32_C(0x6036003C),"unity_block",sxgp_unity_block_fields,SX_COUNT(sxgp_unity_block_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_node_count_fields[]={
 SX_FIELD("node_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgp_unity_node_count={UINT32_C(0x6036003D),"unity_node_count",sxgp_unity_node_count_fields,SX_COUNT(sxgp_unity_node_count_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_node_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
 SX_FIELD("data_size","int64",8,8,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
};
const sx_layout sxgp_unity_node={UINT32_C(0x6036003E),"unity_node",sxgp_unity_node_fields,SX_COUNT(sxgp_unity_node_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_cstring(sxgp_view*v,uint64_t*p,uint64_t end,uint64_t max)
{uint64_t start=*p,c;while(*p<end&&*p-start<max){if(++v->work>4000000||!sxgp_word(v,*p,1,false,&c,end))return false;(*p)++;if(!c)return true;}return false;}
static bool sxgp_unity(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=12,ver,size,packed,flags,info,blocks,nodes;if(!SG_ROW(unity_header,0,end)||!sxgp_word(v,8,4,true,&ver,end)||!sxgp_cstring(v,&p,end,256)||!sxgp_cstring(v,&p,end,256)||!SG_ROW(unity_sizes,p,end)||!sxgp_word(v,p,8,true,&size,end)||size>end||!sxgp_word(v,p+8,4,true,&packed,end)||!sxgp_word(v,p+16,4,true,&flags,end))return false;p+=20;if(ver>=7)p=(p+15)&~UINT64_C(15);if(packed>size)return false;info=flags&128?size-packed:p;if(!sxgp_span(v,info,packed,size))return false;end=info+packed;
 if(!SG_ROW(unity_info,info,end)||!sxgp_word(v,info+16,4,true,&blocks,end)||blocks>65536||!sxgp_table(v,&sxgp_unity_block,info+20,blocks,end))return false;p=info+20+10*blocks;
 if(!SG_ROW(unity_node_count,p,end)||!sxgp_word(v,p,4,true,&nodes,end)||nodes>65536)return false;p+=4;
 for(uint64_t i=0;i<nodes;i++){if(!SG_ROW(unity_node,p,end))return false;p+=20;if(!sxgp_cstring(v,&p,end,4096))return false;}return p==end;}
bool sx_unityfs_build(sxgp_view*v)
{
 return sxgp_unity(v);
}
#undef SG_ROW
