/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * crystal_fort34 data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_symmetry_count_fields[]={SX_FIELD("symmetry_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_symmetry_count={0x60610017U,"chemistry_symmetry_count",sxsch_symmetry_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dimension_fields[]={SX_FIELD("dimension","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_dimension={0x60610061U,"chemistry_dimension",sxsch_dimension_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_crystal_centering_fields[]={SX_FIELD("crystal_centering","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_crystal_centering={0x60610062U,"chemistry_crystal_centering",sxsch_crystal_centering_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_crystal_type_fields[]={SX_FIELD("crystal_type","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_crystal_type={0x60610063U,"chemistry_crystal_type",sxsch_crystal_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_energy_fields[]={SX_FIELD("energy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_energy={0x60610064U,"chemistry_energy",sxsch_energy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_energy_delta_fields[]={SX_FIELD("energy_delta","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_energy_delta={0x60610065U,"chemistry_energy_delta",sxsch_energy_delta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_symmetry_component_fields[]={SX_FIELD("symmetry_component","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_symmetry_component={0x60610066U,"chemistry_symmetry_component",sxsch_symmetry_component_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_crystal(sxsch_cursor*q){sxsch_token l,t[16];unsigned n;uint64_t atoms,ops;if(!sxsch_next(q,&l,t,16,&n,"#")||(n!=3&&n!=8))return false;SC_EMIT(dimension,t[0]);SC_EMIT(crystal_centering,t[1]);SC_EMIT(crystal_type,t[2]);if(n==8){SC_EMIT(keyword,t[3]);SC_EMIT(energy,t[4]);SC_EMIT(keyword,t[5]);if(t[6].z<2)return false;SC_EMIT(energy_delta,((sxsch_token){t[6].a,t[6].z-1}));SC_EMIT(text_value,t[7]);}for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,16,&n,"#")||n!=3||!sxsch_xyz(q,t,3))return false;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=1||!sxsch_number(q,t[0],&ops)||ops!=1)return false;SC_EMIT(symmetry_count,t[0]);for(unsigned j=0;j<4;j++)if(!sxsch_next(q,&l,t,16,&n,"#")||n!=3||!sxsch_each(q,t,3,&sxsch_symmetry_component))return false;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=1||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=4)return false;SC_EMIT(atomic_number,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}return true;}
bool sx_crystal_fort34_build(sxsch_cursor*q)
{
 return sxsch_crystal(q);
}
#undef SC_EMIT
