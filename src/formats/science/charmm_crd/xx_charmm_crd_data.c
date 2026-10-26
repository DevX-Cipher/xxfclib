/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * charmm_crd data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_residue_id_fields[]={SX_FIELD("residue_id","char",0,0,SX_STRING)};
const sx_layout sxsch_residue_id={0x6061000aU,"chemistry_residue_id",sxsch_residue_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_segment_name_fields[]={SX_FIELD("segment_name","char",0,0,SX_STRING)};
const sx_layout sxsch_segment_name={0x6061000bU,"chemistry_segment_name",sxsch_segment_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_residue_index_fields[]={SX_FIELD("residue_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_residue_index={0x6061001aU,"chemistry_residue_index",sxsch_residue_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_weight_fields[]={SX_FIELD("weight","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_weight={0x60610023U,"chemistry_weight",sxsch_weight_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_charmm(sxsch_cursor*q){sxsch_token l,t[12];unsigned n;uint64_t atoms;if(!sxsch_next(q,&l,t,12,&n,"*"))return false;if(!n||n>2||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);if(n==2)SC_EMIT(keyword,t[1]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,12,&n,"*")||n!=10)return false;SC_EMIT(atom_id,t[0]);SC_EMIT(residue_index,t[1]);SC_EMIT(residue_name,t[2]);SC_EMIT(atom_name,t[3]);if(!sxsch_xyz(q,t+4,0))return false;SC_EMIT(segment_name,t[7]);SC_EMIT(residue_id,t[8]);SC_EMIT(weight,t[9]);}return true;}
bool sx_charmm_crd_build(sxsch_cursor*q)
{
 return sxsch_charmm(q);
}
#undef SC_EMIT
