/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gaussian_fchk data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_value_type_fields[]={SX_FIELD("value_type","char",0,0,SX_STRING)};
const sx_layout sxsch_value_type={0x60610013U,"chemistry_value_type",sxsch_value_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_value_count_fields[]={SX_FIELD("value_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_value_count={0x60610016U,"chemistry_value_count",sxsch_value_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_label_fields[]={SX_FIELD("fchk_label","char",0,0,SX_STRING)};
const sx_layout sxsch_fchk_label={0x606100a8U,"chemistry_fchk_label",sxsch_fchk_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_job_fields[]={SX_FIELD("fchk_job","char",0,0,SX_STRING)};
const sx_layout sxsch_fchk_job={0x606100a9U,"chemistry_fchk_job",sxsch_fchk_job_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_method_fields[]={SX_FIELD("fchk_method","char",0,0,SX_STRING)};
const sx_layout sxsch_fchk_method={0x606100aaU,"chemistry_fchk_method",sxsch_fchk_method_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_basis_fields[]={SX_FIELD("fchk_basis","char",0,0,SX_STRING)};
const sx_layout sxsch_fchk_basis={0x606100abU,"chemistry_fchk_basis",sxsch_fchk_basis_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_array_marker_fields[]={SX_FIELD("fchk_array_marker","char",0,0,SX_STRING)};
const sx_layout sxsch_fchk_array_marker={0x606100acU,"chemistry_fchk_array_marker",sxsch_fchk_array_marker_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_integer_fields[]={SX_FIELD("fchk_integer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_fchk_integer={0x606100adU,"chemistry_fchk_integer",sxsch_fchk_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_real_fields[]={SX_FIELD("fchk_real","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_fchk_real={0x606100aeU,"chemistry_fchk_real",sxsch_fchk_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_coordinate_fields[]={SX_FIELD("fchk_coordinate","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_fchk_coordinate={0x606100afU,"chemistry_fchk_coordinate",sxsch_fchk_coordinate_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_fchk(sxsch_cursor*q){sxsch_token l,t[4];unsigned n;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,4,&n,"")||n!=3)return false;SC_EMIT(fchk_job,t[0]);SC_EMIT(fchk_method,t[1]);SC_EMIT(fchk_basis,t[2]);while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;if(l.z<47)return false;sxsch_token key=sxsch_trim(q,(sxsch_token){l.a,40});SC_EMIT(fchk_label,((sxsch_token){l.a,40}));SC_EMIT(value_type,((sxsch_token){l.a+43,1}));bool real=q->b[l.a+43]=='R';n=sxsch_split(q,(sxsch_token){l.a+45,l.z-45},t,4,false);if(n!=1&&n!=2)return false;bool coordinates=sxsch_eq(q,key,"Current cartesian coordinates");const sx_layout*layout=coordinates?&sxsch_fchk_coordinate:real?&sxsch_fchk_real:sxsch_eq(q,key,"Number of atoms")?&sxsch_atom_count:sxsch_eq(q,key,"Atomic numbers")?&sxsch_atomic_number:&sxsch_fchk_integer;if(n==1){if(!sxsch_emit(q,layout,t[0]))return false;}else{uint64_t remaining;if(!sxsch_number(q,t[1],&remaining))return false;SC_EMIT(fchk_array_marker,t[0]);SC_EMIT(value_count,t[1]);unsigned width=real?16:12;while(remaining){if(!sxsch_line(q,&l)||l.z%width)return false;uint64_t got=(uint64_t)l.z/width;if(!got||got>remaining)return false;for(unsigned j=0;j<got;j++)if(!sxsch_column(q,layout,l,j*width,width))return false;remaining-=got;if(q->c->count>=24000)return true;}}}return true;}
bool sx_gaussian_fchk_build(sxsch_cursor*q)
{
 return sxsch_fchk(q);
}
#undef SC_EMIT
