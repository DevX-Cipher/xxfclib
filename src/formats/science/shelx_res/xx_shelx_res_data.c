/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * shelx_res data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_occupancy_fields[]={SX_FIELD("occupancy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_occupancy={0x60610022U,"chemistry_occupancy",sxsch_occupancy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_wavelength_fields[]={SX_FIELD("wavelength","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_wavelength={0x60610067U,"chemistry_wavelength",sxsch_wavelength_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_alpha_fields[]={SX_FIELD("cell_alpha","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_alpha={0x6061006bU,"chemistry_cell_alpha",sxsch_cell_alpha_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_beta_fields[]={SX_FIELD("cell_beta","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_beta={0x6061006cU,"chemistry_cell_beta",sxsch_cell_beta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_gamma_fields[]={SX_FIELD("cell_gamma","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_gamma={0x6061006dU,"chemistry_cell_gamma",sxsch_cell_gamma_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_shelx_lattice_fields[]={SX_FIELD("shelx_lattice","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_shelx_lattice={0x6061006eU,"chemistry_shelx_lattice",sxsch_shelx_lattice_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_shelx(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;while(sxsch_next(q,&l,t,128,&n,"!")){if(q->c->count>=24000)return true;if(sxsch_eq(q,t[0],"TITL")){SC_EMIT(keyword,t[0]);if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(sxsch_eq(q,t[0],"CELL")){if(n!=8)return false;SC_EMIT(keyword,t[0]);const sx_layout*cols[]={&sxsch_wavelength,&sxsch_cell_a,&sxsch_cell_b,&sxsch_cell_c,&sxsch_cell_alpha,&sxsch_cell_beta,&sxsch_cell_gamma};if(!sxsch_fields(q,t+1,7,cols,7))return false;}else if(sxsch_eq(q,t[0],"LATT")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(shelx_lattice,t[1]);}else if(sxsch_eq(q,t[0],"SFAC")){SC_EMIT(keyword,t[0]);if(!sxsch_each(q,t+1,n-1,&sxsch_element))return false;}else if(sxsch_eq(q,t[0],"END")){SC_EMIT(keyword,t[0]);}else{if(n!=6)return false;SC_EMIT(atom_label,t[0]);SC_EMIT(species_index,t[1]);if(!sxsch_xyz(q,t+2,2))return false;SC_EMIT(occupancy,t[5]);}}return true;}
bool sx_shelx_res_build(sxsch_cursor*q)
{
 return sxsch_shelx(q);
}
#undef SC_EMIT
