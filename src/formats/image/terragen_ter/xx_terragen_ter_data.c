/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TERRAGEN_TER data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_ter_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
const sx_layout sxmo_ter_header = {UINT32_C(0x60210070),"ter_header",sxmo_ter_header_fields,SX_COUNT(sxmo_ter_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_end_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_ter_end = {UINT32_C(0x60210071),"ter_end",sxmo_ter_end_fields,SX_COUNT(sxmo_ter_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_size_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("size_minus_one","uint16",4,2,SX_NONE),
    SX_FIELD("padding","uint16",6,2,SX_RESERVED),
};
const sx_layout sxmo_ter_size = {UINT32_C(0x60210072),"ter_size",sxmo_ter_size_fields,SX_COUNT(sxmo_ter_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_point_count_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("point_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("padding","uint16",6,2,SX_RESERVED),
};
const sx_layout sxmo_ter_point_count = {UINT32_C(0x60210073),"ter_point_count",sxmo_ter_point_count_fields,SX_COUNT(sxmo_ter_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_scale_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("x","float32",4,4,SX_NONE),
    SX_FIELD("y","float32",8,4,SX_NONE),
    SX_FIELD("z","float32",12,4,SX_NONE),
};
const sx_layout sxmo_ter_scale = {UINT32_C(0x60210074),"ter_scale",sxmo_ter_scale_fields,SX_COUNT(sxmo_ter_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_radius_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("radius","float32",4,4,SX_NONE),
};
const sx_layout sxmo_ter_radius = {UINT32_C(0x60210075),"ter_radius",sxmo_ter_radius_fields,SX_COUNT(sxmo_ter_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_curvature_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("mode","uint32",4,4,SX_ID),
};
const sx_layout sxmo_ter_curvature = {UINT32_C(0x60210076),"ter_curvature",sxmo_ter_curvature_fields,SX_COUNT(sxmo_ter_curvature_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_altitude_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("height_scale","int16",4,2,SX_NONE),
    SX_FIELD("base_height","int16",6,2,SX_NONE),
};
const sx_layout sxmo_ter_altitude = {UINT32_C(0x60210077),"ter_altitude",sxmo_ter_altitude_fields,SX_COUNT(sxmo_ter_altitude_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_height_fields[] = {
    SX_FIELD("height_sample","int16",0,2,SX_NONE),
};
const sx_layout sxmo_ter_height = {UINT32_C(0x60210078),"ter_height",sxmo_ter_height_fields,SX_COUNT(sxmo_ter_height_fields),SX_LE};
static bool sxmo_ter(sx_context*c){uint8_t h[16];if(!sxmo_read(c,0,h,16)||xx_rt_memcmp(h,"TERRAGENTERRAIN ",16)||!sxmo_add(c,&sxmo_ter_header,0))return false;uint64_t p=16,end=(uint64_t)c->size,width=0,height=0;
 for(unsigned i=0;p<end&&i<4096;i++){if(end-p<4||!sxmo_read(c,p,h,4))break;const sx_layout*l=NULL;unsigned z=0;if(!xx_rt_memcmp(h,"SIZE",4)){l=&sxmo_ter_size;z=8;}else if(!xx_rt_memcmp(h,"XPTS",4)||!xx_rt_memcmp(h,"YPTS",4)){l=&sxmo_ter_point_count;z=8;}else if(!xx_rt_memcmp(h,"SCAL",4)){l=&sxmo_ter_scale;z=16;}else if(!xx_rt_memcmp(h,"CRAD",4)){l=&sxmo_ter_radius;z=8;}else if(!xx_rt_memcmp(h,"CRVM",4)){l=&sxmo_ter_curvature;z=8;}else if(!xx_rt_memcmp(h,"ALTW",4)){l=&sxmo_ter_altitude;z=8;}else if(!xx_rt_memcmp(h,"EOF ",4)){l=&sxmo_ter_end;z=4;}else break;if(z>end-p||!sxmo_read(c,p,h,z))break;if(!sxmo_add(c,l,p))return false;p+=z;
 if(l==&sxmo_ter_size)width=height=(uint64_t)sxmo16(h+4,false)+1;else if(l==&sxmo_ter_point_count){if(h[0]=='X')width=sxmo16(h+4,false);else height=sxmo16(h+4,false);}else if(l==&sxmo_ter_altitude){if(!width||!height||height>1000000/width||width*height*2>end-p)break;if(!sxmo_table(c,&sxmo_ter_height,p,width*height))return false;p=(p+width*height*2+3)&~UINT64_C(3);if(p>end)break;}else if(l==&sxmo_ter_end)break;}return !c->failed;}
bool sx_terragen_ter_build(sx_context*c)
{
bool ok=false;
ok=sxmo_ter(c);
return ok&&c->count>0&&sxmo_finish(c);
}
