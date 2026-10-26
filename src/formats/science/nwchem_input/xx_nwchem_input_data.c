/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nwchem_input data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_unpaired_electrons_fields[]={SX_FIELD("unpaired_electrons","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_unpaired_electrons={0x606100b1U,"chemistry_unpaired_electrons",sxsch_unpaired_electrons_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_memory_amount_fields[]={SX_FIELD("memory_amount","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_memory_amount={0x606100b8U,"chemistry_memory_amount",sxsch_memory_amount_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_nwchem(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,mode=0,lattice=0;bool geometry=false,system=false;while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(lattice){if(n!=3||!sxsch_xyz(q,t,3))return false;lattice--;continue;}if(geometry&&n==4&&!sxsch_ci(q,t[0],"system")){SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,mode))return false;continue;}SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"geometry")){geometry=true;mode=0;for(unsigned i=1;i<n;i++){if(sxsch_ci(q,t[i],"au"))mode=1;SC_EMIT(option_value,t[i]);}}else if(sxsch_ci(q,t[0],"system")){system=true;if(!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;}else if(sxsch_ci(q,t[0],"lattice_vectors"))lattice=3;else if(sxsch_ci(q,t[0],"end")){if(system)system=false;else geometry=false;}else if(sxsch_ci(q,t[0],"title")){if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(n>1){const sx_layout*layout=sxsch_ci(q,t[0],"charge")?&sxsch_charge:sxsch_ci(q,t[0],"mult")?&sxsch_multiplicity:sxsch_ci(q,t[0],"nopen")?&sxsch_unpaired_electrons:sxsch_ci(q,t[0],"maxiter")?&sxsch_iteration_count:sxsch_ci(q,t[0],"thresh")?&sxsch_threshold:sxsch_ci(q,t[0],"memory")?&sxsch_memory_amount:sxsch_ci(q,t[0],"start")||sxsch_ci(q,t[0],"permanent_dir")||sxsch_ci(q,t[0],"scratch_dir")?&sxsch_filename:&sxsch_option_value;if(!sxsch_emit(q,layout,t[1]))return false;if(n>2&&!sxsch_each(q,t+2,n-2,sxsch_ci(q,t[0],"memory")?&sxsch_units:&sxsch_option_value))return false;}}return true;}
bool sx_nwchem_input_build(sxsch_cursor*q)
{
 return sxsch_nwchem(q);
}
#undef SC_EMIT
