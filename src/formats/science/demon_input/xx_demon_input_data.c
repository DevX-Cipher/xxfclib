/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * demon_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_demon(sxsch_cursor*q){sxsch_token l,t[16];unsigned n;bool geometry=false;while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(geometry){if(n!=6)return false;SC_EMIT(atom_label,t[0]);if(!sxsch_xyz(q,t+1,0))return false;SC_EMIT(atomic_number,t[4]);SC_EMIT(mass,t[5]);}else{SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"geometry")){geometry=true;if(!sxsch_each(q,t+1,n-1,&sxsch_units))return false;}else if(sxsch_ci(q,t[0],"title")){if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(!sxsch_each(q,t+1,n-1,sxsch_ci(q,t[0],"basis")?&sxsch_basis_name:sxsch_ci(q,t[0],"scftype")?&sxsch_method_name:&sxsch_option_value))return false;}}return geometry;}
bool sx_demon_input_build(sxsch_cursor*q)
{
 return sxsch_demon(q);
}
#undef SC_EMIT
