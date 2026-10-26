/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * castep_cell data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_castep(sxsch_cursor*q){sxsch_token l,t[12];unsigned n,mode=0;bool lattice=false;while(sxsch_next(q,&l,t,12,&n,"#!")){if(q->c->count>=24000)return true;if(sxsch_ci(q,t[0],"%block")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(section,t[1]);lattice=sxsch_ci(q,t[1],"lattice_cart");mode=sxsch_ci(q,t[1],"positions_frac")?2:0;}else if(sxsch_ci(q,t[0],"%endblock")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(section,t[1]);}else if(n==1){SC_EMIT(units,t[0]);mode=sxsch_ci(q,t[0],"bohr")?1:0;}else if(lattice){if(n!=3||!sxsch_xyz(q,t,mode==1?4:3))return false;}else{if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,mode))return false;}}return true;}
bool sx_castep_cell_build(sxsch_cursor*q)
{
 return sxsch_castep(q);
}
#undef SC_EMIT
