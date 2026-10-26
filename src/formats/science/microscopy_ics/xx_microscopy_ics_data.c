/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MICROSCOPY ICS data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_filename_fields[]={SX_FIELD("filename","char",0,0,SX_STRING)};
const sx_layout sxsm_filename={0x6063000eU,"mesh_filename",sxsm_filename_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_significant_bits_fields[]={SX_FIELD("significant_bits","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_significant_bits={0x6063003bU,"mesh_significant_bits",sxsm_significant_bits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_ics_parameter_count_fields[]={SX_FIELD("ics_parameter_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_ics_parameter_count={0x6063003cU,"mesh_ics_parameter_count",sxsm_ics_parameter_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_byte_order_index_fields[]={SX_FIELD("byte_order_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_byte_order_index={0x6063003dU,"mesh_byte_order_index",sxsm_byte_order_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_parameter_origin_fields[]={SX_FIELD("parameter_origin","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_parameter_origin={0x6063003eU,"mesh_parameter_origin",sxsm_parameter_origin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_parameter_scale_fields[]={SX_FIELD("parameter_scale","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_parameter_scale={0x6063003fU,"mesh_parameter_scale",sxsm_parameter_scale_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_name_fields[]={SX_FIELD("axis_name","char",0,0,SX_STRING)};
const sx_layout sxsm_axis_name={0x60630074U,"mesh_axis_name",sxsm_axis_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_unit_fields[]={SX_FIELD("axis_unit","char",0,0,SX_STRING)};
const sx_layout sxsm_axis_unit={0x60630075U,"mesh_axis_unit",sxsm_axis_unit_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_ics(sxsm_cursor*q){sxsm_token line,t[32];unsigned n;if(!sxsm_line(q,&line))return false;/* First physical line declares separators; preserve tab as raw. */while(sxsm_next(q,&line,t,32,&n,"")){if(q->c->count>=24000)return true;SM_EMIT(key,t[0]);if(sxsm_eq(q,t[0],"end"))return true;if(n<2)return false;if(sxsm_eq(q,t[0],"ics_version")){SM_EMIT(option_value,t[1]);continue;}if(sxsm_eq(q,t[0],"filename")){SM_EMIT(filename,t[1]);continue;}if(sxsm_eq(q,t[0],"history")){SM_EMIT(text_value,((sxsm_token){t[1].a,line.a+line.z-t[1].a}));continue;}SM_EMIT(key,t[1]);if(n<3)return false;const sx_layout*l=&sxsm_option_value;
 if(sxsm_eq(q,t[0],"layout")){if(sxsm_eq(q,t[1],"parameters"))l=&sxsm_ics_parameter_count;else if(sxsm_eq(q,t[1],"sizes")){SM_EMIT(sample_bits,t[2]);if(!sxsm_each(q,t+3,n-3,&sxsm_axis_count))return false;continue;}else if(sxsm_eq(q,t[1],"significant_bits"))l=&sxsm_significant_bits;else if(sxsm_eq(q,t[1],"order"))l=&sxsm_axis_name;}
 else if(sxsm_eq(q,t[0],"representation")){if(sxsm_eq(q,t[1],"byte_order"))l=&sxsm_byte_order_index;else if(sxsm_eq(q,t[1],"format"))l=&sxsm_type_name;else if(sxsm_eq(q,t[1],"compression"))l=&sxsm_encoding;}
 else if(sxsm_eq(q,t[0],"parameter")){if(sxsm_eq(q,t[1],"origin"))l=&sxsm_parameter_origin;else if(sxsm_eq(q,t[1],"scale"))l=&sxsm_parameter_scale;else if(sxsm_eq(q,t[1],"units"))l=&sxsm_axis_unit;else if(sxsm_eq(q,t[1],"labels"))l=&sxsm_axis_name;}
 if(!sxsm_each(q,t+2,n-2,l))return false;}return false;}
bool sx_microscopy_ics_build(sxsm_cursor*q)
{
 return sxsm_ics(q);
}
#undef SM_EMIT
