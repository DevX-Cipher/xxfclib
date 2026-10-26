/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gromacs_gro data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_gro_residue_name_fields[]={SX_FIELD("gro_residue_name","char",0,0,SX_STRING)};
const sx_layout sxsa_gro_residue_name={0x6051006aU,"science_gro_residue_name",sxsa_gro_residue_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_atom_name_fields[]={SX_FIELD("gro_atom_name","char",0,0,SX_STRING)};
const sx_layout sxsa_gro_atom_name={0x6051006bU,"science_gro_atom_name",sxsa_gro_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_residue_number_fields[]={SX_FIELD("gro_residue_number","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_gro_residue_number={0x6051006cU,"science_gro_residue_number",sxsa_gro_residue_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_atom_number_fields[]={SX_FIELD("gro_atom_number","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_gro_atom_number={0x6051006dU,"science_gro_atom_number",sxsa_gro_atom_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_x_fields[]={SX_FIELD("gro_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_x={0x6051006eU,"science_gro_x",sxsa_gro_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_y_fields[]={SX_FIELD("gro_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_y={0x6051006fU,"science_gro_y",sxsa_gro_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_z_fields[]={SX_FIELD("gro_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_z={0x60510070U,"science_gro_z",sxsa_gro_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_vx_fields[]={SX_FIELD("gro_vx","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_vx={0x60510071U,"science_gro_vx",sxsa_gro_vx_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_vy_fields[]={SX_FIELD("gro_vy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_vy={0x60510072U,"science_gro_vy",sxsa_gro_vy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_vz_fields[]={SX_FIELD("gro_vz","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_vz={0x60510073U,"science_gro_vz",sxsa_gro_vz_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_xx_fields[]={SX_FIELD("gro_box_xx","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_xx={0x60510074U,"science_gro_box_xx",sxsa_gro_box_xx_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_yy_fields[]={SX_FIELD("gro_box_yy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_yy={0x60510075U,"science_gro_box_yy",sxsa_gro_box_yy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_zz_fields[]={SX_FIELD("gro_box_zz","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_zz={0x60510076U,"science_gro_box_zz",sxsa_gro_box_zz_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_xy_fields[]={SX_FIELD("gro_box_xy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_xy={0x60510077U,"science_gro_box_xy",sxsa_gro_box_xy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_xz_fields[]={SX_FIELD("gro_box_xz","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_xz={0x60510078U,"science_gro_box_xz",sxsa_gro_box_xz_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_yx_fields[]={SX_FIELD("gro_box_yx","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_yx={0x60510079U,"science_gro_box_yx",sxsa_gro_box_yx_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_yz_fields[]={SX_FIELD("gro_box_yz","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_yz={0x6051007aU,"science_gro_box_yz",sxsa_gro_box_yz_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_zx_fields[]={SX_FIELD("gro_box_zx","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_zx={0x6051007bU,"science_gro_box_zx",sxsa_gro_box_zx_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gro_box_zy_fields[]={SX_FIELD("gro_box_zy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_gro_box_zy={0x6051007cU,"science_gro_box_zy",sxsa_gro_box_zy_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
#define SA_COL(n,o,z) do{if(!sxsa_column(q,&sxsa_##n,line,(o),(z)))return false;}while(0)
static bool sxsa_gro(sxsa_cursor*q){sxsa_token line,t[9];uint64_t count;if(!sxsa_line(q,&line))return false;SA_EMIT(title,line);if(!sxsa_line(q,&line)||!sxsa_number(q,line,&count))return false;SA_EMIT(atom_count,line);const sx_layout*pos[]={&sxsa_gro_x,&sxsa_gro_y,&sxsa_gro_z,&sxsa_gro_vx,&sxsa_gro_vy,&sxsa_gro_vz};for(uint64_t i=0;i<count;i++){if(!sxsa_line(q,&line)||(line.z!=44&&line.z!=68))return false;SA_COL(gro_residue_number,0,5);SA_COL(gro_residue_name,5,5);SA_COL(gro_atom_name,10,5);SA_COL(gro_atom_number,15,5);for(unsigned j=0;j<(line.z==44?3U:6U);j++)if(!sxsa_column(q,pos[j],line,20+8*j,8))return false;if(q->c->count>=24000)return true;}if(!sxsa_line(q,&line))return false;unsigned n=sxsa_split(q,line,t,9,false);const sx_layout*box[]={&sxsa_gro_box_xx,&sxsa_gro_box_yy,&sxsa_gro_box_zz,&sxsa_gro_box_xy,&sxsa_gro_box_xz,&sxsa_gro_box_yx,&sxsa_gro_box_yz,&sxsa_gro_box_zx,&sxsa_gro_box_zy};return (n==3||n==9)&&sxsa_fields(q,t,n,box,9);}
bool sx_gromacs_gro_build(sxsa_cursor*q)
{
 return sxsa_gro(q);
}
#undef SA_EMIT
#undef SA_COL
