/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * matrix_market data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_matrix_rows_fields[]={SX_FIELD("matrix_rows","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_matrix_rows={0x6051001aU,"science_matrix_rows",sxsa_matrix_rows_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_columns_fields[]={SX_FIELD("matrix_columns","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_matrix_columns={0x6051001bU,"science_matrix_columns",sxsa_matrix_columns_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_entries_fields[]={SX_FIELD("matrix_entries","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_matrix_entries={0x6051001cU,"science_matrix_entries",sxsa_matrix_entries_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_row_fields[]={SX_FIELD("matrix_row","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_matrix_row={0x6051004dU,"science_matrix_row",sxsa_matrix_row_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_column_fields[]={SX_FIELD("matrix_column","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_matrix_column={0x6051004eU,"science_matrix_column",sxsa_matrix_column_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_object_fields[]={SX_FIELD("matrix_object","char",0,0,SX_STRING)};
const sx_layout sxsa_matrix_object={0x6051004fU,"science_matrix_object",sxsa_matrix_object_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_storage_fields[]={SX_FIELD("matrix_storage","char",0,0,SX_STRING)};
const sx_layout sxsa_matrix_storage={0x60510050U,"science_matrix_storage",sxsa_matrix_storage_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_field_fields[]={SX_FIELD("matrix_field","char",0,0,SX_STRING)};
const sx_layout sxsa_matrix_field={0x60510051U,"science_matrix_field",sxsa_matrix_field_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_symmetry_fields[]={SX_FIELD("matrix_symmetry","char",0,0,SX_STRING)};
const sx_layout sxsa_matrix_symmetry={0x60510052U,"science_matrix_symmetry",sxsa_matrix_symmetry_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_integer_fields[]={SX_FIELD("matrix_integer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_matrix_integer={0x60510053U,"science_matrix_integer",sxsa_matrix_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_real_fields[]={SX_FIELD("matrix_real","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_matrix_real={0x60510054U,"science_matrix_real",sxsa_matrix_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_matrix_imaginary_fields[]={SX_FIELD("matrix_imaginary","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_matrix_imaginary={0x60510055U,"science_matrix_imaginary",sxsa_matrix_imaginary_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_matrix(sxsa_cursor*q){sxsa_token line,t[5];if(!sxsa_line(q,&line)||sxsa_split(q,line,t,5,false)!=5)return false;SA_EMIT(record_type,t[0]);SA_EMIT(matrix_object,t[1]);SA_EMIT(matrix_storage,t[2]);SA_EMIT(matrix_field,t[3]);SA_EMIT(matrix_symmetry,t[4]);bool coord=sxsa_eq(q,t[2],"coordinate"),integer=sxsa_eq(q,t[3],"integer"),complex=sxsa_eq(q,t[3],"complex"),pattern=sxsa_eq(q,t[3],"pattern"),header=true;while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;line=sxsa_trim(q,line);if(!line.z)continue;if(q->b[line.a]=='%'){SA_EMIT(comment,line);continue;}unsigned n=sxsa_split(q,line,t,5,false);if(header){if(n!=(coord?3U:2U))return false;SA_EMIT(matrix_rows,t[0]);SA_EMIT(matrix_columns,t[1]);if(coord)SA_EMIT(matrix_entries,t[2]);header=false;}else{unsigned at=coord?2:0;if(n!=at+(pattern?0:complex?2:1))return false;if(coord){SA_EMIT(matrix_row,t[0]);SA_EMIT(matrix_column,t[1]);}if(!pattern&&!sxsa_emit(q,integer?&sxsa_matrix_integer:&sxsa_matrix_real,t[at]))return false;if(complex)SA_EMIT(matrix_imaginary,t[at+1]);}}return !header;}
bool sx_matrix_market_build(sxsa_cursor*q)
{
 return sxsa_matrix(q);
}
#undef SA_EMIT
