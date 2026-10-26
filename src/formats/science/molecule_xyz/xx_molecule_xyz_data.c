/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * molecule_xyz data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_xyz_x_fields[]={SX_FIELD("xyz_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_xyz_x={0x6051007dU,"science_xyz_x",sxsa_xyz_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_xyz_y_fields[]={SX_FIELD("xyz_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_xyz_y={0x6051007eU,"science_xyz_y",sxsa_xyz_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_xyz_z_fields[]={SX_FIELD("xyz_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_xyz_z={0x6051007fU,"science_xyz_z",sxsa_xyz_z_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_xyz(sxsa_cursor*q){sxsa_token line,t[4];const sx_layout*atom[]={&sxsa_element,&sxsa_xyz_x,&sxsa_xyz_y,&sxsa_xyz_z};while(sxsa_line(q,&line)){uint64_t n;if(!sxsa_number(q,line,&n))return false;SA_EMIT(atom_count,line);if(!sxsa_line(q,&line))return false;SA_EMIT(comment,line);for(uint64_t i=0;i<n;i++){if(!sxsa_line(q,&line)||sxsa_split(q,line,t,4,false)!=4||!sxsa_fields(q,t,4,atom,4))return false;if(q->c->count>=24000)return true;}}return true;}
bool sx_molecule_xyz_build(sxsa_cursor*q)
{
 return sxsa_xyz(q);
}
#undef SA_EMIT
