/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * siesta_xv data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_siesta(sxsch_cursor*q){sxsch_token l,t[10];unsigned n;uint64_t atoms;for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,10,&n,"#")||n!=6||!sxsch_xyz(q,t,4)||!sxsch_xyz(q,t+3,12))return false;if(!sxsch_next(q,&l,t,10,&n,"#")||n!=1||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,10,&n,"#")||n!=8)return false;SC_EMIT(species_index,t[0]);SC_EMIT(atomic_number,t[1]);if(!sxsch_xyz(q,t+2,1)||!sxsch_xyz(q,t+5,11))return false;}return true;}
bool sx_siesta_xv_build(sxsch_cursor*q)
{
 return sxsch_siesta(q);
}
#undef SC_EMIT
