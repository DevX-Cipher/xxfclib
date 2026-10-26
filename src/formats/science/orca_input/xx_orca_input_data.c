/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * orca_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_memory_mb_fields[]={SX_FIELD("memory_mb","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_memory_mb={0x606100b9U,"chemistry_memory_mb",sxsch_memory_mb_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_orca(sxsch_cursor*q){sxsch_token l,t[64];unsigned n;bool geometry=false;if(!sxsch_next(q,&l,t,64,&n,"#"))return false;SC_EMIT(keyword,t[0]);if(!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;while(sxsch_next(q,&l,t,64,&n,"#")){if(q->c->count>=24000)return true;if(sxsch_ci(q,t[0],"*xyz")){if(n!=3)return false;SC_EMIT(keyword,t[0]);SC_EMIT(charge,t[1]);SC_EMIT(multiplicity,t[2]);geometry=true;}else if(sxsch_eq(q,t[0],"*")){SC_EMIT(keyword,t[0]);geometry=false;}else if(geometry){if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}else{SC_EMIT(keyword,t[0]);if(n>1&&!sxsch_each(q,t+1,n-1,sxsch_ci(q,t[0],"%maxcore")?&sxsch_memory_mb:sxsch_ci(q,t[0],"nprocs")?&sxsch_processor_count:&sxsch_option_value))return false;}}return true;}
bool sx_orca_input_build(sxsch_cursor*q)
{
 return sxsch_orca(q);
}
#undef SC_EMIT
