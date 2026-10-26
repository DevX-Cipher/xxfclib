/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lammps_data data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_lammps_mass_fields[]={SX_FIELD("lammps_mass","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_mass={0x6061003cU,"chemistry_lammps_mass",sxsch_lammps_mass_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_lammps(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(n==1&&(sxsch_eq(q,t[0],"Atoms")||sxsch_eq(q,t[0],"Masses")||sxsch_eq(q,t[0],"Velocities"))){section=sxsch_eq(q,t[0],"Atoms")?1:sxsch_eq(q,t[0],"Masses")?2:3;SC_EMIT(section,t[0]);continue;}if(!section){if(n==2){SC_EMIT(atom_count,t[0]);SC_EMIT(keyword,t[1]);}else if(n==3){SC_EMIT(type_count,t[0]);if(!sxsch_each(q,t+1,2,&sxsch_keyword))return false;}else if(n==4){SC_EMIT(box_lower,t[0]);SC_EMIT(box_upper,t[1]);if(!sxsch_each(q,t+2,2,&sxsch_keyword))return false;}else if(n==6){if(!sxsch_each(q,t,3,&sxsch_box_tilt)||!sxsch_each(q,t+3,3,&sxsch_keyword))return false;}else return false;}else if(section==1){if(n!=5)return false;SC_EMIT(atom_id,t[0]);SC_EMIT(species_index,t[1]);if(!sxsch_xyz(q,t+2,7))return false;}else if(section==2){if(n!=2)return false;SC_EMIT(species_index,t[0]);SC_EMIT(lammps_mass,t[1]);}else{if(n!=4)return false;SC_EMIT(atom_id,t[0]);if(!sxsch_xyz(q,t+1,8))return false;}}return section!=0;}
bool sx_lammps_data_build(sxsch_cursor*q)
{
 return sxsch_lammps(q);
}
#undef SC_EMIT
