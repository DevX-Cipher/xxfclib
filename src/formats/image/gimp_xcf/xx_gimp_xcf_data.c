/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GIMP XCF data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_xcf_header_fields[]={
 SX_FIELD("signature","bytes",0,9,SX_SIGNATURE),
 SX_FIELD("version","char[5]",9,5,SX_ID),
 SX_FIELD("width","uint32",14,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",18,4,SX_COUNT_PROP),
 SX_FIELD("image_type","uint32",22,4,SX_ID),
};
const sx_layout sxnx_xcf_header={UINT32_C(0x60320067),"xcf_header",sxnx_xcf_header_fields,SX_COUNT(sxnx_xcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_property_fields[]={
 SX_FIELD("property_type","uint32",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_xcf_property={UINT32_C(0x60320068),"xcf_property",sxnx_xcf_property_fields,SX_COUNT(sxnx_xcf_property_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_string_fields[]={
 SX_FIELD("string_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnx_xcf_string={UINT32_C(0x60320069),"xcf_string",sxnx_xcf_string_fields,SX_COUNT(sxnx_xcf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_offset_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxnx_xcf_offset={UINT32_C(0x6032006A),"xcf_offset",sxnx_xcf_offset_fields,SX_COUNT(sxnx_xcf_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_layer_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("layer_type","uint32",8,4,SX_ID),
};
const sx_layout sxnx_xcf_layer={UINT32_C(0x6032006B),"xcf_layer",sxnx_xcf_layer_fields,SX_COUNT(sxnx_xcf_layer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_channel_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxnx_xcf_channel={UINT32_C(0x6032006C),"xcf_channel",sxnx_xcf_channel_fields,SX_COUNT(sxnx_xcf_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_hierarchy_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("bytes_per_pixel","uint32",8,4,SX_SIZE),
};
const sx_layout sxnx_xcf_hierarchy={UINT32_C(0x6032006D),"xcf_hierarchy",sxnx_xcf_hierarchy_fields,SX_COUNT(sxnx_xcf_hierarchy_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_level_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxnx_xcf_level={UINT32_C(0x6032006E),"xcf_level",sxnx_xcf_level_fields,SX_COUNT(sxnx_xcf_level_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_color_count_fields[]={
 SX_FIELD("color_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxnx_xcf_color_count={UINT32_C(0x6032006F),"xcf_color_count",sxnx_xcf_color_count_fields,SX_COUNT(sxnx_xcf_color_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_opacity_fields[]={
 SX_FIELD("opacity","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_xcf_opacity={UINT32_C(0x60320070),"xcf_opacity",sxnx_xcf_opacity_fields,SX_COUNT(sxnx_xcf_opacity_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_mode_fields[]={
 SX_FIELD("mode","uint32",0,4,SX_ID),
};
const sx_layout sxnx_xcf_mode={UINT32_C(0x60320071),"xcf_mode",sxnx_xcf_mode_fields,SX_COUNT(sxnx_xcf_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_boolean_fields[]={
 SX_FIELD("enabled","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnx_xcf_boolean={UINT32_C(0x60320072),"xcf_boolean",sxnx_xcf_boolean_fields,SX_COUNT(sxnx_xcf_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_geometry_offset_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
const sx_layout sxnx_xcf_geometry_offset={UINT32_C(0x60320073),"xcf_geometry_offset",sxnx_xcf_geometry_offset_fields,SX_COUNT(sxnx_xcf_geometry_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_compression_fields[]={
 SX_FIELD("compression","uint8",0,1,SX_ID),
};
const sx_layout sxnx_xcf_compression={UINT32_C(0x60320074),"xcf_compression",sxnx_xcf_compression_fields,SX_COUNT(sxnx_xcf_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_xcf_guide_fields[]={
 SX_FIELD("position","int32",0,4,SX_NONE),
 SX_FIELD("orientation","uint8",4,1,SX_ID),
};
const sx_layout sxnx_xcf_guide={UINT32_C(0x60320075),"xcf_guide",sxnx_xcf_guide_fields,SX_COUNT(sxnx_xcf_guide_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_resolution_fields[]={
 SX_FIELD("horizontal","float",0,4,SX_NONE),
 SX_FIELD("vertical","float",4,4,SX_NONE),
};
const sx_layout sxnx_xcf_resolution={UINT32_C(0x60320076),"xcf_resolution",sxnx_xcf_resolution_fields,SX_COUNT(sxnx_xcf_resolution_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_tattoo_fields[]={
 SX_FIELD("tattoo","uint32",0,4,SX_ID),
};
const sx_layout sxnx_xcf_tattoo={UINT32_C(0x60320077),"xcf_tattoo",sxnx_xcf_tattoo_fields,SX_COUNT(sxnx_xcf_tattoo_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_unit_fields[]={
 SX_FIELD("unit","uint32",0,4,SX_ID),
};
const sx_layout sxnx_xcf_unit={UINT32_C(0x60320078),"xcf_unit",sxnx_xcf_unit_fields,SX_COUNT(sxnx_xcf_unit_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_parasite_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_xcf_parasite={UINT32_C(0x60320079),"xcf_parasite",sxnx_xcf_parasite_fields,SX_COUNT(sxnx_xcf_parasite_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_sample_point_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
const sx_layout sxnx_xcf_sample_point={UINT32_C(0x6032007A),"xcf_sample_point",sxnx_xcf_sample_point_fields,SX_COUNT(sxnx_xcf_sample_point_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_walk_xcf_string(sxnx_view*v,size_t*p,size_t end)
{if(!SN_ROW(xcf_string,*p,end))return false;unsigned z=sxnx_u32(v->p+*p,true);*p+=4;if(!sxnx_need(v,*p,z,end))return false;*p+=z;return true;}
static bool sxnx_xcf_props(sxnx_view*v,size_t*p)
{for(unsigned i=0;i<1024;i++){if(!SN_ROW(xcf_property,*p,v->n))return false;unsigned type=sxnx_u32(v->p+*p,true),z=sxnx_u32(v->p+*p+4,true);*p+=8;if(!sxnx_need(v,*p,z,v->n))return false;size_t end=*p+z;if(!type)return z==0;const sx_layout*l=NULL;
 if(type==1){if(!SN_ROW(xcf_color_count,*p,end)||!sxnx_table(v,&sxnx_rgb_palette_entry,*p+4,sxnx_u32(v->p+*p,true),end))return false;}else if(type==6)l=&sxnx_xcf_opacity;else if(type==7)l=&sxnx_xcf_mode;else if(type>=8&&type<=14)l=&sxnx_xcf_boolean;else if(type==15)l=&sxnx_xcf_geometry_offset;else if(type==16)l=&sxnx_rgb_palette_entry;else if(type==17)l=&sxnx_xcf_compression;else if(type==18){if(z%5||!sxnx_table(v,&sxnx_xcf_guide,*p,z/5,end))return false;}else if(type==19)l=&sxnx_xcf_resolution;else if(type==20)l=&sxnx_xcf_tattoo;else if(type==22)l=&sxnx_xcf_unit;else if(type==21){while(*p<end){if(!sxnx_walk_xcf_string(v,p,end)||!SN_ROW(xcf_parasite,*p,end))return false;unsigned n=sxnx_u32(v->p+*p+4,true);*p+=8;if(!sxnx_need(v,*p,n,end))return false;*p+=n;}}else if(type==27){if(z%8||!sxnx_table(v,&sxnx_xcf_sample_point,*p,z/8,end))return false;}
 if(l&&!sxnx_row(v,l,*p,end))return false;*p=end;}return false;}
static bool sxnx_walk_xcf_hierarchy(sxnx_view*v,size_t p)
{if(!SN_ROW(xcf_hierarchy,p,v->n))return false;p+=12;for(unsigned i=0;i<=16;i++){if(!SN_ROW(xcf_offset,p,v->n))return false;size_t at=sxnx_u32(v->p+p,true);p+=4;if(!at)return true;if(i==16||!SN_ROW(xcf_level,at,v->n))return false;uint64_t w=sxnx_u32(v->p+at,true),h=sxnx_u32(v->p+at+4,true),tiles=((w+63)/64)*((h+63)/64);if(!tiles||tiles>4096)return false;at+=8;for(uint64_t j=0;j<=tiles;j++){if(!SN_ROW(xcf_offset,at,v->n))return false;unsigned value=sxnx_u32(v->p+at,true);at+=4;if(!value)break;if(j==tiles)return false;}}
 return false;}
static bool sxnx_xcf_drawable(sxnx_view*v,size_t p,bool layer)
{if(!sxnx_row(v,layer?&sxnx_xcf_layer:&sxnx_xcf_channel,p,v->n))return false;p+=layer?12:8;if(!sxnx_walk_xcf_string(v,&p,v->n)||!sxnx_xcf_props(v,&p)||!SN_ROW(xcf_offset,p,v->n))return false;unsigned hierarchy=sxnx_u32(v->p+p,true);p+=4;unsigned mask=0;if(layer){if(!SN_ROW(xcf_offset,p,v->n))return false;mask=sxnx_u32(v->p+p,true);}if(hierarchy&&!sxnx_walk_xcf_hierarchy(v,hierarchy))return false;return !mask||sxnx_xcf_drawable(v,mask,false);}
static bool sxnx_xcf(sxnx_view*v)
{if(!SN_ROW(xcf_header,0,v->n))return false;size_t p=26;if(!sxnx_xcf_props(v,&p))return false;for(unsigned kind=0;kind<2;kind++){bool done=false;for(unsigned i=0;i<=1024;i++){if(!SN_ROW(xcf_offset,p,v->n))return false;unsigned at=sxnx_u32(v->p+p,true);p+=4;if(!at){done=true;break;}if(i==1024||!sxnx_xcf_drawable(v,at,kind==0))return false;}if(!done)return false;}return true;}
bool sx_gimp_xcf_build(sxnx_view*v)
{
 return sxnx_xcf(v);
}
#undef SN_ROW
