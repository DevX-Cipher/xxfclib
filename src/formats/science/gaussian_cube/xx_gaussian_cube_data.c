/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gaussian_cube data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_cube_origin_x_fields[]={SX_FIELD("cube_origin_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_origin_x={0x605100b9U,"science_cube_origin_x",sxsa_cube_origin_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_origin_y_fields[]={SX_FIELD("cube_origin_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_origin_y={0x605100baU,"science_cube_origin_y",sxsa_cube_origin_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_origin_z_fields[]={SX_FIELD("cube_origin_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_origin_z={0x605100bbU,"science_cube_origin_z",sxsa_cube_origin_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_vector_x_fields[]={SX_FIELD("cube_vector_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_vector_x={0x605100bcU,"science_cube_vector_x",sxsa_cube_vector_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_vector_y_fields[]={SX_FIELD("cube_vector_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_vector_y={0x605100bdU,"science_cube_vector_y",sxsa_cube_vector_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_vector_z_fields[]={SX_FIELD("cube_vector_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_vector_z={0x605100beU,"science_cube_vector_z",sxsa_cube_vector_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_atom_x_fields[]={SX_FIELD("cube_atom_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_atom_x={0x605100bfU,"science_cube_atom_x",sxsa_cube_atom_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_atom_y_fields[]={SX_FIELD("cube_atom_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_atom_y={0x605100c0U,"science_cube_atom_y",sxsa_cube_atom_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_atom_z_fields[]={SX_FIELD("cube_atom_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_atom_z={0x605100c1U,"science_cube_atom_z",sxsa_cube_atom_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_axis_count_fields[]={SX_FIELD("cube_axis_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_cube_axis_count={0x605100c2U,"science_cube_axis_count",sxsa_cube_axis_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_atomic_number_fields[]={SX_FIELD("atomic_number","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_atomic_number={0x605100c3U,"science_atomic_number",sxsa_atomic_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_nuclear_charge_fields[]={SX_FIELD("cube_nuclear_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_nuclear_charge={0x605100c4U,"science_cube_nuclear_charge",sxsa_cube_nuclear_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_cube_value_fields[]={SX_FIELD("cube_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_cube_value={0x605100c5U,"science_cube_value",sxsa_cube_value_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_cube(sxsa_cursor*q){sxsa_token line,t[8];uint64_t atoms;for(unsigned i=0;i<2;i++){if(!sxsa_line(q,&line))return false;SA_EMIT(comment,line);}if(!sxsa_line(q,&line)||sxsa_split(q,line,t,8,false)!=4||!sxsa_number(q,t[0],&atoms))return false;const sx_layout*origin[]={&sxsa_atom_count,&sxsa_cube_origin_x,&sxsa_cube_origin_y,&sxsa_cube_origin_z};if(!sxsa_fields(q,t,4,origin,4))return false;const sx_layout*axis[]={&sxsa_cube_axis_count,&sxsa_cube_vector_x,&sxsa_cube_vector_y,&sxsa_cube_vector_z};for(unsigned i=0;i<3;i++){if(!sxsa_line(q,&line)||sxsa_split(q,line,t,8,false)!=4||!sxsa_fields(q,t,4,axis,4))return false;}const sx_layout*atom[]={&sxsa_atomic_number,&sxsa_cube_nuclear_charge,&sxsa_cube_atom_x,&sxsa_cube_atom_y,&sxsa_cube_atom_z};for(uint64_t i=0;i<atoms;i++){if(!sxsa_line(q,&line)||sxsa_split(q,line,t,8,false)!=5||!sxsa_fields(q,t,5,atom,5))return false;if(q->c->count>=24000)return true;}while(sxsa_line(q,&line)){int64_t p=line.a,end=p+line.z;while(p<end){while(p<end&&sxsa_space(q->b[p]))p++;int64_t a=p;while(p<end&&!sxsa_space(q->b[p]))p++;if(p>a)SA_EMIT(cube_value,((sxsa_token){a,p-a}));}if(q->c->count>=24000)return true;}return true;}
bool sx_gaussian_cube_build(sxsa_cursor*q)
{
 return sxsa_cube(q);
}
#undef SA_EMIT
