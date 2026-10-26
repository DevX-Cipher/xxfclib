/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BPG IMAGE data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_bpg_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("pixel_format_alpha_depth","uint8",4,1,SX_FLAGS),
 SX_FIELD("color_space_extensions_alpha_flags","uint8",5,1,SX_FLAGS),
};
const sx_layout sxnx_bpg_header={UINT32_C(0x6032007B),"bpg_header",sxnx_bpg_header_fields,SX_COUNT(sxnx_bpg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_1_fields[]={
 SX_FIELD("width","uintbase128",0,1,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_width_1={UINT32_C(0x6032007C),"bpg_width_1",sxnx_bpg_width_1_fields,SX_COUNT(sxnx_bpg_width_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_2_fields[]={
 SX_FIELD("width","uintbase128",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_width_2={UINT32_C(0x6032007D),"bpg_width_2",sxnx_bpg_width_2_fields,SX_COUNT(sxnx_bpg_width_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_3_fields[]={
 SX_FIELD("width","uintbase128",0,3,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_width_3={UINT32_C(0x6032007E),"bpg_width_3",sxnx_bpg_width_3_fields,SX_COUNT(sxnx_bpg_width_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_1_fields[]={
 SX_FIELD("height","uintbase128",0,1,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_height_1={UINT32_C(0x6032007F),"bpg_height_1",sxnx_bpg_height_1_fields,SX_COUNT(sxnx_bpg_height_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_2_fields[]={
 SX_FIELD("height","uintbase128",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_height_2={UINT32_C(0x60320080),"bpg_height_2",sxnx_bpg_height_2_fields,SX_COUNT(sxnx_bpg_height_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_3_fields[]={
 SX_FIELD("height","uintbase128",0,3,SX_COUNT_PROP),
};
const sx_layout sxnx_bpg_height_3={UINT32_C(0x60320081),"bpg_height_3",sxnx_bpg_height_3_fields,SX_COUNT(sxnx_bpg_height_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_1_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,1,SX_SIZE),
};
const sx_layout sxnx_bpg_picture_bytes_1={UINT32_C(0x60320082),"bpg_picture_bytes_1",sxnx_bpg_picture_bytes_1_fields,SX_COUNT(sxnx_bpg_picture_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_2_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,2,SX_SIZE),
};
const sx_layout sxnx_bpg_picture_bytes_2={UINT32_C(0x60320083),"bpg_picture_bytes_2",sxnx_bpg_picture_bytes_2_fields,SX_COUNT(sxnx_bpg_picture_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_3_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,3,SX_SIZE),
};
const sx_layout sxnx_bpg_picture_bytes_3={UINT32_C(0x60320084),"bpg_picture_bytes_3",sxnx_bpg_picture_bytes_3_fields,SX_COUNT(sxnx_bpg_picture_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_4_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,4,SX_SIZE),
};
const sx_layout sxnx_bpg_picture_bytes_4={UINT32_C(0x60320085),"bpg_picture_bytes_4",sxnx_bpg_picture_bytes_4_fields,SX_COUNT(sxnx_bpg_picture_bytes_4_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_1_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,1,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_bytes_1={UINT32_C(0x60320086),"bpg_extension_bytes_1",sxnx_bpg_extension_bytes_1_fields,SX_COUNT(sxnx_bpg_extension_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_2_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,2,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_bytes_2={UINT32_C(0x60320087),"bpg_extension_bytes_2",sxnx_bpg_extension_bytes_2_fields,SX_COUNT(sxnx_bpg_extension_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_3_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,3,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_bytes_3={UINT32_C(0x60320088),"bpg_extension_bytes_3",sxnx_bpg_extension_bytes_3_fields,SX_COUNT(sxnx_bpg_extension_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_1_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,1,SX_ID),
};
const sx_layout sxnx_bpg_extension_tag_1={UINT32_C(0x60320089),"bpg_extension_tag_1",sxnx_bpg_extension_tag_1_fields,SX_COUNT(sxnx_bpg_extension_tag_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_2_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,2,SX_ID),
};
const sx_layout sxnx_bpg_extension_tag_2={UINT32_C(0x6032008A),"bpg_extension_tag_2",sxnx_bpg_extension_tag_2_fields,SX_COUNT(sxnx_bpg_extension_tag_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_3_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,3,SX_ID),
};
const sx_layout sxnx_bpg_extension_tag_3={UINT32_C(0x6032008B),"bpg_extension_tag_3",sxnx_bpg_extension_tag_3_fields,SX_COUNT(sxnx_bpg_extension_tag_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_4_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,4,SX_ID),
};
const sx_layout sxnx_bpg_extension_tag_4={UINT32_C(0x6032008C),"bpg_extension_tag_4",sxnx_bpg_extension_tag_4_fields,SX_COUNT(sxnx_bpg_extension_tag_4_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_5_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,5,SX_ID),
};
const sx_layout sxnx_bpg_extension_tag_5={UINT32_C(0x6032008D),"bpg_extension_tag_5",sxnx_bpg_extension_tag_5_fields,SX_COUNT(sxnx_bpg_extension_tag_5_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_1_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,1,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_data_bytes_1={UINT32_C(0x6032008E),"bpg_extension_data_bytes_1",sxnx_bpg_extension_data_bytes_1_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_2_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,2,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_data_bytes_2={UINT32_C(0x6032008F),"bpg_extension_data_bytes_2",sxnx_bpg_extension_data_bytes_2_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_3_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,3,SX_SIZE),
};
const sx_layout sxnx_bpg_extension_data_bytes_3={UINT32_C(0x60320090),"bpg_extension_data_bytes_3",sxnx_bpg_extension_data_bytes_3_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_hevc_header_bytes_1_fields[]={
 SX_FIELD("hevc_header_bytes","uintbase128",0,1,SX_SIZE),
};
const sx_layout sxnx_bpg_hevc_header_bytes_1={UINT32_C(0x60320091),"bpg_hevc_header_bytes_1",sxnx_bpg_hevc_header_bytes_1_fields,SX_COUNT(sxnx_bpg_hevc_header_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_nal_fields[]={
 SX_FIELD("type_layer","uint8",0,1,SX_FLAGS),
 SX_FIELD("layer_temporal_id","uint8",1,1,SX_FLAGS),
};
const sx_layout sxnx_bpg_nal={UINT32_C(0x60320092),"bpg_nal",sxnx_bpg_nal_fields,SX_COUNT(sxnx_bpg_nal_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_bpg_uint(sxnx_view*v,size_t*p,size_t end,unsigned kind,uint32_t*out)
{size_t start=*p;unsigned width;if(!sxnx_varuint(v,p,end,out,&width))return false;const sx_layout*l=NULL;switch(kind){
case 0:switch(width){case 1:l=&sxnx_bpg_width_1;break;case 2:l=&sxnx_bpg_width_2;break;case 3:l=&sxnx_bpg_width_3;break;}break;
case 1:switch(width){case 1:l=&sxnx_bpg_height_1;break;case 2:l=&sxnx_bpg_height_2;break;case 3:l=&sxnx_bpg_height_3;break;}break;
case 2:switch(width){case 1:l=&sxnx_bpg_picture_bytes_1;break;case 2:l=&sxnx_bpg_picture_bytes_2;break;case 3:l=&sxnx_bpg_picture_bytes_3;break;case 4:l=&sxnx_bpg_picture_bytes_4;break;}break;
case 3:switch(width){case 1:l=&sxnx_bpg_extension_bytes_1;break;case 2:l=&sxnx_bpg_extension_bytes_2;break;case 3:l=&sxnx_bpg_extension_bytes_3;break;}break;
case 4:switch(width){case 1:l=&sxnx_bpg_extension_tag_1;break;case 2:l=&sxnx_bpg_extension_tag_2;break;case 3:l=&sxnx_bpg_extension_tag_3;break;case 4:l=&sxnx_bpg_extension_tag_4;break;case 5:l=&sxnx_bpg_extension_tag_5;break;}break;
case 5:switch(width){case 1:l=&sxnx_bpg_extension_data_bytes_1;break;case 2:l=&sxnx_bpg_extension_data_bytes_2;break;case 3:l=&sxnx_bpg_extension_data_bytes_3;break;}break;
case 6:switch(width){case 1:l=&sxnx_bpg_hevc_header_bytes_1;break;}break;
}return l&&sxnx_row(v,l,start,*p);}
static bool sxnx_bpg(sxnx_view*v)
{if(!SN_ROW(bpg_header,0,v->n))return false;size_t p=6;uint32_t z;for(unsigned i=0;i<3;i++)if(!sxnx_bpg_uint(v,&p,v->n,i,&z))return false;if(v->p[5]&8){if(!sxnx_bpg_uint(v,&p,v->n,3,&z)||!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;while(p<end){if(!sxnx_bpg_uint(v,&p,end,4,&z)||!sxnx_bpg_uint(v,&p,end,5,&z)||!sxnx_need(v,p,z,end))return false;p+=z;}}
 for(unsigned i=0;i<(((v->p[4]&16)||(v->p[5]&4))?2U:1U);i++){if(!sxnx_bpg_uint(v,&p,v->n,6,&z)||!sxnx_need(v,p,z,v->n))return false;p+=z;}
 unsigned work=0;while(p<v->n){if(++work>2048||!SN_ROW(bpg_nal,p,v->n))return false;p+=2;size_t end=p;unsigned zeros=0;while(end<v->n){if(!sxnx_need(v,end,1,v->n))return false;if(!v->p[end]){zeros++;end++;continue;}if(v->p[end]==1&&zeros>=2){end-=zeros;break;}zeros=0;end++;}p=end;if(p<v->n){unsigned zero=0;while(p<v->n&&!v->p[p]){p++;zero++;}if(p==v->n)break;if(v->p[p]!=1||zero<2||zero>16)return false;p++;}}
 return true;}
bool sx_bpg_image_build(sxnx_view*v)
{
 return sxnx_bpg(v);
}
#undef SN_ROW
