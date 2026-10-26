/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * quantum_espresso_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_mixing_factor_fields[]={SX_FIELD("mixing_factor","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_mixing_factor={0x6061002aU,"chemistry_mixing_factor",sxsch_mixing_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_qe_total_charge_fields[]={SX_FIELD("qe_total_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_qe_total_charge={0x6061002bU,"chemistry_qe_total_charge",sxsch_qe_total_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_move_flag_fields[]={SX_FIELD("move_flag","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_move_flag={0x60610075U,"chemistry_move_flag",sxsch_move_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_k_grid_fields[]={SX_FIELD("k_grid","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_k_grid={0x60610076U,"chemistry_k_grid",sxsch_k_grid_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_k_shift_fields[]={SX_FIELD("k_shift","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_k_shift={0x60610077U,"chemistry_k_shift",sxsch_k_shift_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_qe(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0,mode=0,left=0;bool namelist=false;while(sxsch_next(q,&l,t,16,&n,"!#")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='&'||sxsch_eq(q,t[0],"/")){namelist=q->b[t[0].a]=='&';SC_EMIT(section,t[0]);continue;}if(namelist){sxsch_token key,value;if(!sxsch_assignment(q,l,&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"nat")?&sxsch_atom_count:sxsch_ci(q,key,"ntyp")?&sxsch_type_count:sxsch_ci(q,key,"ibrav")?&sxsch_integer_value:sxsch_ci(q,key,"ecutwfc")||sxsch_ci(q,key,"ecutrho")?&sxsch_cutoff_ry:sxsch_ci(q,key,"tot_charge")?&sxsch_qe_total_charge:sxsch_ci(q,key,"mixing_beta")?&sxsch_mixing_factor:sxsch_ci(q,key,"conv_thr")?&sxsch_threshold:sxsch_ci(q,key,"electron_maxstep")?&sxsch_iteration_count:sxsch_ci(q,key,"calculation")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;continue;}if(sxsch_ci(q,t[0],"atomic_species")){section=1;SC_EMIT(section,t[0]);}else if(sxsch_ci(q,t[0],"atomic_positions")){if(n!=2)return false;section=2;mode=sxsch_ci(q,t[1],"bohr")?1:sxsch_ci(q,t[1],"crystal")?2:0;SC_EMIT(section,t[0]);SC_EMIT(units,t[1]);}else if(sxsch_ci(q,t[0],"cell_parameters")){if(n!=2)return false;section=3;left=3;mode=sxsch_ci(q,t[1],"bohr")?4:3;SC_EMIT(section,t[0]);SC_EMIT(units,t[1]);}else if(sxsch_ci(q,t[0],"k_points")){if(n!=2)return false;section=4;left=sxsch_ci(q,t[1],"automatic")?1:0;SC_EMIT(section,t[0]);SC_EMIT(coordinate_mode,t[1]);}else if(section==1){if(n!=3)return false;SC_EMIT(element,t[0]);SC_EMIT(mass,t[1]);SC_EMIT(filename,t[2]);}else if(section==2){if((n!=4&&n!=7)||!sxsch_xyz(q,t+1,mode))return false;SC_EMIT(element,t[0]);if(n==7&&!sxsch_each(q,t+4,3,&sxsch_move_flag))return false;}else if(section==3){if(!left||n!=3||!sxsch_xyz(q,t,mode))return false;left--;}else if(section==4){if(!left||n!=6||!sxsch_each(q,t,3,&sxsch_k_grid)||!sxsch_each(q,t+3,3,&sxsch_k_shift))return false;left--;}else return false;}return true;}
bool sx_quantum_espresso_input_build(sxsch_cursor*q)
{
 return sxsch_qe(q);
}
#undef SC_EMIT
