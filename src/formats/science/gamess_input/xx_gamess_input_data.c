/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gamess_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_nuclear_charge_fields[]={SX_FIELD("nuclear_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_nuclear_charge={0x606100beU,"chemistry_nuclear_charge",sxsch_nuclear_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_symmetry_name_fields[]={SX_FIELD("symmetry_name","char",0,0,SX_STRING)};
const sx_layout sxsch_symmetry_name={0x606100bfU,"chemistry_symmetry_name",sxsch_symmetry_name_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_gamess(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;while(sxsch_next(q,&l,t,16,&n,"!")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='$'){SC_EMIT(section,t[0]);if(sxsch_ci(q,t[0],"$data")){section=2;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,16,&n,"!")||n!=1)return false;SC_EMIT(symmetry_name,t[0]);}else if(sxsch_ci(q,t[0],"$end"))section=0;else section=1;}else if(section==2){if(n!=5)return false;SC_EMIT(element,t[0]);SC_EMIT(nuclear_charge,t[1]);if(!sxsch_xyz(q,t+2,0))return false;}else if(section==1){for(unsigned j=0;j<n;j++){sxsch_token key,value;if(!sxsch_assignment(q,t[j],&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"mult")?&sxsch_multiplicity:sxsch_ci(q,key,"icharg")?&sxsch_charge:sxsch_ci(q,key,"ngauss")||sxsch_ci(q,key,"ndfunc")||sxsch_ci(q,key,"npfunc")?&sxsch_integer_value:sxsch_ci(q,key,"units")?&sxsch_units:sxsch_ci(q,key,"gbasis")?&sxsch_basis_name:sxsch_ci(q,key,"scftyp")?&sxsch_method_name:sxsch_ci(q,key,"runtyp")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;}}else return false;}return true;}
bool sx_gamess_input_build(sxsch_cursor*q)
{
 return sxsch_gamess(q);
}
#undef SC_EMIT
