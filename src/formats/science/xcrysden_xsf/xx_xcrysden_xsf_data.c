/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xcrysden_xsf data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_xsf(sxsch_cursor*q){sxsch_token l,t[8];unsigned n;bool crystal=false;uint64_t count=0;if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);crystal=sxsch_eq(q,t[0],"CRYSTAL");if(crystal){if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,8,&n,"")||n!=3||!sxsch_xyz(q,t,3))return false;if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);if(!sxsch_next(q,&l,t,8,&n,"")||n!=2||!sxsch_number(q,t[0],&count))return false;SC_EMIT(atom_count,t[0]);SC_EMIT(integer_value,t[1]);}uint64_t got=0;while(sxsch_next(q,&l,t,8,&n,"#")){if(q->c->count>=24000)return true;if(n!=4&&n!=7)return false;uint64_t z;if(sxsch_number(q,t[0],&z))SC_EMIT(atomic_number,t[0]);else SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0)||(n==7&&!sxsch_xyz(q,t+4,13)))return false;got++;}return got&&(!crystal||got==count);}
bool sx_xcrysden_xsf_build(sxsch_cursor*q)
{
 return sxsch_xsf(q);
}
#undef SC_EMIT
