/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lammps_dump data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_lammps_timestep_fields[]={SX_FIELD("lammps_timestep","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_lammps_timestep={0x6061006fU,"chemistry_lammps_timestep",sxsch_lammps_timestep_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_boundary_code_fields[]={SX_FIELD("boundary_code","char",0,0,SX_STRING)};
const sx_layout sxsch_boundary_code={0x60610073U,"chemistry_boundary_code",sxsch_boundary_code_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_column_name_fields[]={SX_FIELD("column_name","char",0,0,SX_STRING)};
const sx_layout sxsch_column_name={0x60610074U,"chemistry_column_name",sxsch_column_name_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static const sx_layout*sxsch_lammps_col(sxsch_cursor*q,sxsch_token t){if(sxsch_eq(q,t,"id"))return &sxsch_atom_id;if(sxsch_eq(q,t,"type"))return &sxsch_species_index;if(sxsch_eq(q,t,"element"))return &sxsch_element;const char*keys[]={"x","y","z","xu","yu","zu","xs","ys","zs","vx","vy","vz"};const sx_layout*rows[]={&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z,&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z,&sxsch_fractional_x,&sxsch_fractional_y,&sxsch_fractional_z,&sxsch_lammps_velocity_x,&sxsch_lammps_velocity_y,&sxsch_lammps_velocity_z};for(unsigned i=0;i<SX_COUNT(keys);i++)if(sxsch_eq(q,t,keys[i]))return rows[i];return &sxsch_real_value;}
static bool sxsch_dump(sxsch_cursor*q){sxsch_token l,t[80];const sx_layout*cols[64];unsigned n,ncol=0,phase=0,bounds=0;uint64_t count=0;while(sxsch_next(q,&l,t,80,&n,"#")){if(q->c->count>=24000)return true;if(sxsch_eq(q,t[0],"ITEM:")){if(n<2)return false;SC_EMIT(keyword,t[0]);if(sxsch_eq(q,t[1],"TIMESTEP")){phase=1;SC_EMIT(section,t[1]);}else if(sxsch_eq(q,t[1],"NUMBER")){phase=2;if(!sxsch_each(q,t+1,n-1,&sxsch_keyword))return false;}else if(sxsch_eq(q,t[1],"BOX")){if(n!=6&&n!=9)return false;phase=3;bounds=3;if(!sxsch_each(q,t+1,n-4,&sxsch_keyword)||!sxsch_each(q,t+n-3,3,&sxsch_boundary_code))return false;}else if(sxsch_eq(q,t[1],"ATOMS")){if(n<7||n>66)return false;phase=4;ncol=n-2;SC_EMIT(section,t[1]);for(unsigned i=0;i<ncol;i++){SC_EMIT(column_name,t[i+2]);cols[i]=sxsch_lammps_col(q,t[i+2]);}}else return false;}else if(phase==1){if(n!=1)return false;SC_EMIT(lammps_timestep,t[0]);}else if(phase==2){if(n!=1||!sxsch_number(q,t[0],&count))return false;SC_EMIT(atom_count,t[0]);}else if(phase==3){if(!bounds||(n!=2&&n!=3))return false;bounds--;SC_EMIT(box_lower,t[0]);SC_EMIT(box_upper,t[1]);if(n==3)SC_EMIT(box_tilt,t[2]);}else if(phase==4){if(!count||n!=ncol||!sxsch_fields(q,t,n,cols,ncol))return false;count--;}else return false;}return count==0;}
bool sx_lammps_dump_build(sxsch_cursor*q)
{
 return sxsch_dump(q);
}
#undef SC_EMIT
