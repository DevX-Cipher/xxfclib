/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cp2k_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_cp2k(sxsch_cursor*q){sxsch_token l,t[16],stack[16];unsigned n,depth=0;while(sxsch_next(q,&l,t,16,&n,"#!")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='&'){SC_EMIT(section,t[0]);if(sxsch_ci(q,t[0],"&end")){if(!depth)return false;depth--;}else{if(depth==16)return false;stack[depth++]=t[0];}if(n>1&&!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;}else if(depth&&sxsch_ci(q,stack[depth-1],"&coord")){if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}else{SC_EMIT(option_name,t[0]);if(sxsch_ci(q,t[0],"abc")){if(n!=4)return false;const sx_layout*cols[]={&sxsch_cell_a,&sxsch_cell_b,&sxsch_cell_c};if(!sxsch_fields(q,t+1,3,cols,3))return false;}else if(n>1){const sx_layout*layout=sxsch_ci(q,t[0],"cutoff")||sxsch_ci(q,t[0],"rel_cutoff")?&sxsch_cutoff_ry:sxsch_ci(q,t[0],"eps_scf")||sxsch_ci(q,t[0],"eps_default")?&sxsch_threshold:sxsch_ci(q,t[0],"alpha_weights")?&sxsch_real_value:sxsch_ci(q,t[0],"basis_set_file_name")||sxsch_ci(q,t[0],"potential_file_name")?&sxsch_filename:sxsch_ci(q,t[0],"method")?&sxsch_method_name:sxsch_ci(q,t[0],"basis_set")?&sxsch_basis_name:&sxsch_option_value;if(!sxsch_each(q,t+1,n-1,layout))return false;}}}return !depth;}
bool sx_cp2k_input_build(sxsch_cursor*q)
{
 return sxsch_cp2k(q);
}
#undef SC_EMIT
