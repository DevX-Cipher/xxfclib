/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PAINTSHOP PSP data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_psp_header_fields[]={
 SX_FIELD("signature","bytes",0,27,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",27,5,SX_RESERVED),
 SX_FIELD("major_version","uint16",32,2,SX_ID),
 SX_FIELD("minor_version","uint16",34,2,SX_ID),
};
const sx_layout sxnx_psp_header={UINT32_C(0x60320035),"psp_header",sxnx_psp_header_fields,SX_COUNT(sxnx_psp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_block_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("block_id","uint16",4,2,SX_ID),
 SX_FIELD("initial_size","uint32",6,4,SX_SIZE),
 SX_FIELD("data_size","uint32",10,4,SX_SIZE),
};
const sx_layout sxnx_psp_block={UINT32_C(0x60320036),"psp_block",sxnx_psp_block_fields,SX_COUNT(sxnx_psp_block_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_image_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("resolution","double",8,8,SX_NONE),
 SX_FIELD("resolution_unit","uint8",16,1,SX_ID),
 SX_FIELD("compression","uint16",17,2,SX_ID),
 SX_FIELD("bit_depth","uint16",19,2,SX_NONE),
 SX_FIELD("plane_count","uint16",21,2,SX_COUNT_PROP),
 SX_FIELD("color_count","uint32",23,4,SX_COUNT_PROP),
 SX_FIELD("grayscale","uint8",27,1,SX_FLAGS),
 SX_FIELD("total_image_size","uint32",28,4,SX_SIZE),
 SX_FIELD("active_layer","uint32",32,4,SX_ID),
 SX_FIELD("layer_count","uint16",36,2,SX_COUNT_PROP),
};
const sx_layout sxnx_psp_image={UINT32_C(0x60320037),"psp_image",sxnx_psp_image_fields,SX_COUNT(sxnx_psp_image_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_layer_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("layer_type","uint8",256,1,SX_ID),
 SX_FIELD("image_left","int32",257,4,SX_NONE),
 SX_FIELD("image_top","int32",261,4,SX_NONE),
 SX_FIELD("image_right","int32",265,4,SX_NONE),
 SX_FIELD("image_bottom","int32",269,4,SX_NONE),
 SX_FIELD("saved_image_left","int32",273,4,SX_NONE),
 SX_FIELD("saved_image_top","int32",277,4,SX_NONE),
 SX_FIELD("saved_image_right","int32",281,4,SX_NONE),
 SX_FIELD("saved_image_bottom","int32",285,4,SX_NONE),
 SX_FIELD("opacity","uint8",289,1,SX_NONE),
 SX_FIELD("blend_mode","uint8",290,1,SX_ID),
 SX_FIELD("visible","uint8",291,1,SX_FLAGS),
 SX_FIELD("transparency_protected","uint8",292,1,SX_FLAGS),
 SX_FIELD("link_group","uint8",293,1,SX_ID),
 SX_FIELD("mask_left","int32",294,4,SX_NONE),
 SX_FIELD("mask_top","int32",298,4,SX_NONE),
 SX_FIELD("mask_right","int32",302,4,SX_NONE),
 SX_FIELD("mask_bottom","int32",306,4,SX_NONE),
 SX_FIELD("saved_mask_left","int32",310,4,SX_NONE),
 SX_FIELD("saved_mask_top","int32",314,4,SX_NONE),
 SX_FIELD("saved_mask_right","int32",318,4,SX_NONE),
 SX_FIELD("saved_mask_bottom","int32",322,4,SX_NONE),
 SX_FIELD("mask_linked","uint8",326,1,SX_FLAGS),
 SX_FIELD("mask_disabled","uint8",327,1,SX_FLAGS),
 SX_FIELD("opaque_blend_ranges","bytes",328,43,SX_NONE),
 SX_FIELD("bitmap_count","uint16",371,2,SX_COUNT_PROP),
 SX_FIELD("channel_count","uint16",373,2,SX_COUNT_PROP),
};
const sx_layout sxnx_psp_layer={UINT32_C(0x60320038),"psp_layer",sxnx_psp_layer_fields,SX_COUNT(sxnx_psp_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_channel_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("bitmap_type","uint16",8,2,SX_ID),
 SX_FIELD("channel_type","uint16",10,2,SX_ID),
};
const sx_layout sxnx_psp_channel={UINT32_C(0x60320039),"psp_channel",sxnx_psp_channel_fields,SX_COUNT(sxnx_psp_channel_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_psp_blocks(sxnx_view*v,size_t p,size_t end,unsigned depth)
{if(depth>3)return false;while(p<end){if(!SN_ROW(psp_block,p,end))return false;unsigned id=sxnx_u16(v->p+p+4,false);uint32_t init=sxnx_u32(v->p+p+6,false),n=sxnx_u32(v->p+p+10,false);p+=14;if(init>n||!sxnx_need(v,p,n,end))return false;size_t finish=p+n;
 const sx_layout*l=id==0?&sxnx_psp_image:id==4?&sxnx_psp_layer:id==5?&sxnx_psp_channel:NULL;
 if(l&&!sxnx_row(v,l,p,p+init))return false;if((id==3||id==4)&&!sxnx_psp_blocks(v,p+init,finish,depth+1))return false;p=finish;}return p==end;}
static bool sxnx_psp(sxnx_view*v){return SN_ROW(psp_header,0,v->n)&&sxnx_psp_blocks(v,36,v->n,0);}
bool sx_paintshop_psp_build(sxnx_view*v)
{
 return sxnx_psp(v);
}
#undef SN_ROW
