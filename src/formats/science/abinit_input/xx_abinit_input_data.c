/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * abinit_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_abinit_cell_scale_x_fields[]={SX_FIELD("abinit_cell_scale_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_cell_scale_x={0x6061003dU,"chemistry_abinit_cell_scale_x",sxsch_abinit_cell_scale_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_cell_scale_y_fields[]={SX_FIELD("abinit_cell_scale_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_cell_scale_y={0x6061003eU,"chemistry_abinit_cell_scale_y",sxsch_abinit_cell_scale_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_cell_scale_z_fields[]={SX_FIELD("abinit_cell_scale_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_cell_scale_z={0x6061003fU,"chemistry_abinit_cell_scale_z",sxsch_abinit_cell_scale_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_x_fields[]={SX_FIELD("abinit_rprim_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_rprim_x={0x60610040U,"chemistry_abinit_rprim_x",sxsch_abinit_rprim_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_y_fields[]={SX_FIELD("abinit_rprim_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_rprim_y={0x60610041U,"chemistry_abinit_rprim_y",sxsch_abinit_rprim_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_z_fields[]={SX_FIELD("abinit_rprim_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_abinit_rprim_z={0x60610042U,"chemistry_abinit_rprim_z",sxsch_abinit_rprim_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cutoff_selected_fields[]={SX_FIELD("cutoff_selected","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cutoff_selected={0x606100bbU,"chemistry_cutoff_selected",sxsch_cutoff_selected_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_abinit(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;uint64_t atoms=0;while(sxsch_next(q,&l,t,128,&n,"#")){if(q->c->count>=24000)return true;SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"acell")){if(!sxsch_next(q,&l,t,128,&n,"#")||(n!=3&&n!=4))return false;const sx_layout*cols[]={&sxsch_abinit_cell_scale_x,&sxsch_abinit_cell_scale_y,&sxsch_abinit_cell_scale_z};if(!sxsch_fields(q,t,3,cols,3))return false;if(n==4)SC_EMIT(units,t[3]);}else if(sxsch_ci(q,t[0],"rprim")){const sx_layout*cols[]={&sxsch_abinit_rprim_x,&sxsch_abinit_rprim_y,&sxsch_abinit_rprim_z};for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_fields(q,t,3,cols,3))return false;}else if(sxsch_ci(q,t[0],"typat")){uint64_t count=0;while(count<atoms){if(!sxsch_next(q,&l,t,128,&n,"#")||n>atoms-count||!sxsch_each(q,t,n,&sxsch_species_index))return false;count+=n;if(q->c->count>=24000)return true;}}else if(sxsch_ci(q,t[0],"xcart")){for(uint64_t j=0;j<atoms;j++){if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_xyz(q,t,1))return false;if(q->c->count>=24000)return true;}}else{if(n<2)return false;const sx_layout*layout=&sxsch_integer_value;if(sxsch_ci(q,t[0],"natom")){if(!sxsch_number(q,t[1],&atoms))return false;layout=&sxsch_atom_count;}else if(sxsch_ci(q,t[0],"ntypat"))layout=&sxsch_type_count;else if(sxsch_ci(q,t[0],"znucl"))layout=&sxsch_atomic_number;else if(sxsch_ci(q,t[0],"ecut"))layout=&sxsch_cutoff_selected;if(!sxsch_each(q,t+1,layout==&sxsch_cutoff_selected?1:n-1,layout))return false;if(layout==&sxsch_cutoff_selected&&n>2)SC_EMIT(units,t[2]);}}return true;}
bool sx_abinit_input_build(sxsch_cursor*q)
{
 return sxsch_abinit(q);
}
#undef SC_EMIT
