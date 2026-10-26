/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dl_poly_config data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_dlp_level_fields[]={SX_FIELD("dlp_level","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_dlp_level={0x6061005fU,"chemistry_dlp_level",sxsch_dlp_level_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_periodicity_fields[]={SX_FIELD("dlp_periodicity","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_dlp_periodicity={0x60610060U,"chemistry_dlp_periodicity",sxsch_dlp_periodicity_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_dlp(sxsch_cursor*q){sxsch_token l,t[4];unsigned n;uint64_t level,periodic,atoms;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_number(q,t[0],&level)||level>2||!sxsch_number(q,t[1],&periodic)||!sxsch_number(q,t[2],&atoms))return false;SC_EMIT(dlp_level,t[0]);SC_EMIT(dlp_periodicity,t[1]);SC_EMIT(atom_count,t[2]);if(periodic)for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_xyz(q,t,3))return false;for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,4,&n,"")||n!=2)return false;SC_EMIT(element,t[0]);SC_EMIT(atom_id,t[1]);for(unsigned k=0;k<=level;k++)if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_xyz(q,t,k==0?0:k==1?9:10))return false;}return true;}
bool sx_dl_poly_config_build(sxsch_cursor*q)
{
 return sxsch_dlp(q);
}
#undef SC_EMIT
