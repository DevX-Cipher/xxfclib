/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * vasp_poscar data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_boolean_text_fields[]={SX_FIELD("boolean_text","char",0,0,SX_STRING)};
const sx_layout sxsch_boolean_text={0x6061000eU,"chemistry_boolean_text",sxsch_boolean_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_species_count_fields[]={SX_FIELD("species_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_species_count={0x60610018U,"chemistry_species_count",sxsch_species_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_scale_fields[]={SX_FIELD("scale","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_scale={0x6061005eU,"chemistry_scale",sxsch_scale_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_vasp(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;uint64_t atoms=0;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,128,&n,"#")||n!=1)return false;SC_EMIT(scale,t[0]);for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_xyz(q,t,5))return false;if(!sxsch_next(q,&l,t,128,&n,"#")||!sxsch_each(q,t,n,&sxsch_element))return false;if(!sxsch_next(q,&l,t,128,&n,"#"))return false;for(unsigned i=0;i<n;i++){uint64_t v;if(!sxsch_number(q,t[i],&v)||v>100000-atoms)return false;atoms+=v;SC_EMIT(species_count,t[i]);}if(!sxsch_next(q,&l,t,128,&n,"#"))return false;bool selective=sxsch_ci(q,t[0],"selective");if(selective){if(!sxsch_each(q,t,n,&sxsch_keyword)||!sxsch_next(q,&l,t,128,&n,"#"))return false;}if(n!=1)return false;SC_EMIT(coordinate_mode,t[0]);unsigned mode=sxsch_ci(q,t[0],"direct")?2:6;for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,128,&n,"#")||n!=(selective?6U:3U)||!sxsch_xyz(q,t,mode))return false;if(selective&&!sxsch_each(q,t+3,3,&sxsch_boolean_text))return false;}return true;}
bool sx_vasp_poscar_build(sxsch_cursor*q)
{
 return sxsch_vasp(q);
}
#undef SC_EMIT
