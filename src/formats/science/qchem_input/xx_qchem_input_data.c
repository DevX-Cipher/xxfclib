/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * qchem_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_convergence_exponent_fields[]={SX_FIELD("convergence_exponent","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_convergence_exponent={0x6061002cU,"chemistry_convergence_exponent",sxsch_convergence_exponent_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_qchem(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;bool first=false;while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;l=sxsch_trim(q,l);if(!l.z)continue;if(section==1&&q->b[l.a]!='$'){SC_EMIT(comment,l);continue;}int64_t comment=0;while(comment<l.z&&q->b[l.a+comment]!='#')comment++;if(comment<l.z){SC_EMIT(comment,((sxsch_token){l.a+comment,l.z-comment}));l.z=comment;l=sxsch_trim(q,l);if(!l.z)continue;}n=sxsch_split(q,l,t,16,false);if(!n||n>16)return false;if(q->b[t[0].a]=='$'){SC_EMIT(section,t[0]);section=sxsch_ci(q,t[0],"$comment")?1:sxsch_ci(q,t[0],"$rem")?2:sxsch_ci(q,t[0],"$molecule")?3:0;first=section==3;}else if(section==1)SC_EMIT(comment,l);else if(section==2){if(n!=2)return false;const sx_layout*layout=sxsch_ci(q,t[0],"scf_convergence")||sxsch_ci(q,t[0],"thresh")?&sxsch_convergence_exponent:sxsch_ci(q,t[0],"max_scf_cycles")?&sxsch_iteration_count:sxsch_ci(q,t[0],"method")?&sxsch_method_name:sxsch_ci(q,t[0],"basis")?&sxsch_basis_name:sxsch_ci(q,t[0],"jobtype")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,t[0],t[1],layout))return false;}else if(section==3){if(first){if(n!=2)return false;SC_EMIT(charge,t[0]);SC_EMIT(multiplicity,t[1]);first=false;}else{if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}}else return false;}return true;}
bool sx_qchem_input_build(sxsch_cursor*q)
{
 return sxsch_qchem(q);
}
#undef SC_EMIT
