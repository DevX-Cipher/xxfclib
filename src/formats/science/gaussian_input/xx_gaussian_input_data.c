/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gaussian_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_gaussian_coordinate_x_fields[]={SX_FIELD("gaussian_coordinate_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_coordinate_x={0x60610024U,"chemistry_gaussian_coordinate_x",sxsch_gaussian_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_coordinate_y_fields[]={SX_FIELD("gaussian_coordinate_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_coordinate_y={0x60610025U,"chemistry_gaussian_coordinate_y",sxsch_gaussian_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_coordinate_z_fields[]={SX_FIELD("gaussian_coordinate_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_coordinate_z={0x60610026U,"chemistry_gaussian_coordinate_z",sxsch_gaussian_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_x_fields[]={SX_FIELD("gaussian_lattice_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_lattice_x={0x60610027U,"chemistry_gaussian_lattice_x",sxsch_gaussian_lattice_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_y_fields[]={SX_FIELD("gaussian_lattice_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_lattice_y={0x60610028U,"chemistry_gaussian_lattice_y",sxsch_gaussian_lattice_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_z_fields[]={SX_FIELD("gaussian_lattice_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_gaussian_lattice_z={0x60610029U,"chemistry_gaussian_lattice_z",sxsch_gaussian_lattice_z_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_gaussian(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,phase=0;bool route=false;while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;l=sxsch_trim(q,l);if(!l.z){if(phase<2&&route)phase++;continue;}if(phase==0){if(q->b[l.a]=='%'){sxsch_token key,value;if(!sxsch_assignment(q,(sxsch_token){l.a+1,l.z-1},&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"nprocshared")?&sxsch_processor_count:sxsch_ci(q,key,"chk")?&sxsch_filename:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;}else{route=true;SC_EMIT(option_value,l);}}else if(phase==1){SC_EMIT(title,l);}else{n=sxsch_split(q,l,t,16,false);if(phase==2){if(n!=2)return false;SC_EMIT(charge,t[0]);SC_EMIT(multiplicity,t[1]);phase=3;}else{if(n!=4)return false;bool lattice=sxsch_ci(q,t[0],"tv");if(lattice)SC_EMIT(keyword,t[0]);else SC_EMIT(element,t[0]);const sx_layout*const coords[]={&sxsch_gaussian_coordinate_x,&sxsch_gaussian_coordinate_y,&sxsch_gaussian_coordinate_z};const sx_layout*const tv[]={&sxsch_gaussian_lattice_x,&sxsch_gaussian_lattice_y,&sxsch_gaussian_lattice_z};if(!sxsch_fields(q,t+1,3,lattice?tv:coords,3))return false;}}}return phase==3;}
bool sx_gaussian_input_build(sxsch_cursor*q)
{
 return sxsch_gaussian(q);
}
#undef SC_EMIT
