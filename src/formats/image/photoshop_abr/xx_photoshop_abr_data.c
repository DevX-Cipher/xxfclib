/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PHOTOSHOP ABR data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_abr_header_fields[]={
 SX_FIELD("version","int16",0,2,SX_ID),
 SX_FIELD("brush_count","int16",2,2,SX_COUNT_PROP),
};
const sx_layout sxnx_abr_header={UINT32_C(0x60320027),"abr_header",sxnx_abr_header_fields,SX_COUNT(sxnx_abr_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_record_fields[]={
 SX_FIELD("brush_type","int16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
};
const sx_layout sxnx_abr_record={UINT32_C(0x60320028),"abr_record",sxnx_abr_record_fields,SX_COUNT(sxnx_abr_record_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_sample_prefix_fields[]={
 SX_FIELD("misc","int32",0,4,SX_NONE),
 SX_FIELD("spacing","int16",4,2,SX_NONE),
};
const sx_layout sxnx_abr_sample_prefix={UINT32_C(0x60320029),"abr_sample_prefix",sxnx_abr_sample_prefix_fields,SX_COUNT(sxnx_abr_sample_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_name_header_fields[]={
 SX_FIELD("utf16_units","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxnx_abr_name_header={UINT32_C(0x6032002A),"abr_name_header",sxnx_abr_name_header_fields,SX_COUNT(sxnx_abr_name_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_sample_geometry_fields[]={
 SX_FIELD("antialias","uint8",0,1,SX_FLAGS),
 SX_FIELD("bounds_top","int16",1,2,SX_NONE),
 SX_FIELD("bounds_left","int16",3,2,SX_NONE),
 SX_FIELD("bounds_bottom","int16",5,2,SX_NONE),
 SX_FIELD("bounds_right","int16",7,2,SX_NONE),
 SX_FIELD("top","int32",9,4,SX_NONE),
 SX_FIELD("left","int32",13,4,SX_NONE),
 SX_FIELD("bottom","int32",17,4,SX_NONE),
 SX_FIELD("right","int32",21,4,SX_NONE),
 SX_FIELD("depth","int16",25,2,SX_NONE),
 SX_FIELD("compression","uint8",27,1,SX_ID),
};
const sx_layout sxnx_abr_sample_geometry={UINT32_C(0x6032002B),"abr_sample_geometry",sxnx_abr_sample_geometry_fields,SX_COUNT(sxnx_abr_sample_geometry_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_row_size_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_abr_row_size={UINT32_C(0x6032002C),"abr_row_size",sxnx_abr_row_size_fields,SX_COUNT(sxnx_abr_row_size_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_abr(sxnx_view*v)
{if(!SN_ROW(abr_header,0,v->n))return false;unsigned version=sxnx_u16(v->p,true),count=sxnx_u16(v->p+2,true);if(count>1024)return false;size_t p=4;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(abr_record,p,v->n))return false;uint32_t n=sxnx_u32(v->p+p+2,true);p+=6;if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;if(!SN_ROW(abr_sample_prefix,p,end))return false;p+=6;if(version==2){if(!SN_ROW(abr_name_header,p,end))return false;uint32_t units=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,(uint64_t)units*2,end))return false;p+=units*2;}
 if(!SN_ROW(abr_sample_geometry,p,end))return false;int64_t top=(int32_t)sxnx_u32(v->p+p+9,true),bottom=(int32_t)sxnx_u32(v->p+p+17,true);unsigned compression=v->p[p+27];p+=28;if(bottom<top)return false;if(compression==1&&!sxnx_table(v,&sxnx_abr_row_size,p,(uint64_t)(bottom-top),end))return false;p=end;}return p==v->n;}
bool sx_photoshop_abr_build(sxnx_view*v)
{
 return sxnx_abr(v);
}
#undef SN_ROW
