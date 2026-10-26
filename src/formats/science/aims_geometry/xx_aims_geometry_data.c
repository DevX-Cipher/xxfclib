/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * aims_geometry data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_relaxation_constraint_fields[]={SX_FIELD("relaxation_constraint","char",0,0,SX_STRING)};
const sx_layout sxsch_relaxation_constraint={0x606100b0U,"chemistry_relaxation_constraint",sxsch_relaxation_constraint_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_initial_charge_fields[]={SX_FIELD("initial_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_initial_charge={0x606100bcU,"chemistry_initial_charge",sxsch_initial_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_initial_spin_fields[]={SX_FIELD("initial_spin","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_initial_spin={0x606100bdU,"chemistry_initial_spin",sxsch_initial_spin_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_aims(sxsch_cursor*q){sxsch_token l,t[8];unsigned n;while(sxsch_next(q,&l,t,8,&n,"#")){if(q->c->count>=24000)return true;SC_EMIT(keyword,t[0]);if(sxsch_eq(q,t[0],"lattice_vector")){if(n!=4||!sxsch_xyz(q,t+1,3))return false;}else if(sxsch_eq(q,t[0],"atom")||sxsch_eq(q,t[0],"atom_frac")){if(n!=5||!sxsch_xyz(q,t+1,sxsch_eq(q,t[0],"atom")?0:2))return false;SC_EMIT(element,t[4]);}else{if(n!=2)return false;const sx_layout*layout=sxsch_eq(q,t[0],"initial_charge")?&sxsch_initial_charge:sxsch_eq(q,t[0],"initial_moment")?&sxsch_initial_spin:&sxsch_relaxation_constraint;if(!sxsch_emit(q,layout,t[1]))return false;}}return true;}
bool sx_aims_geometry_build(sxsch_cursor*q)
{
 return sxsch_aims(q);
}
#undef SC_EMIT
