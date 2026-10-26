/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HARWELL BOEING data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_format_string_fields[]={SX_FIELD("format_string","char",0,0,SX_STRING)};
const sx_layout sxsm_format_string={0x6063000fU,"mesh_format_string",sxsm_format_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_total_lines_fields[]={SX_FIELD("hb_total_lines","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_hb_total_lines={0x60630053U,"mesh_hb_total_lines",sxsm_hb_total_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_pointer_lines_fields[]={SX_FIELD("hb_pointer_lines","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_hb_pointer_lines={0x60630054U,"mesh_hb_pointer_lines",sxsm_hb_pointer_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_index_lines_fields[]={SX_FIELD("hb_index_lines","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_hb_index_lines={0x60630055U,"mesh_hb_index_lines",sxsm_hb_index_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_value_lines_fields[]={SX_FIELD("hb_value_lines","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_hb_value_lines={0x60630056U,"mesh_hb_value_lines",sxsm_hb_value_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_rhs_lines_fields[]={SX_FIELD("hb_rhs_lines","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_hb_rhs_lines={0x60630057U,"mesh_hb_rhs_lines",sxsm_hb_rhs_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_rows_fields[]={SX_FIELD("matrix_rows","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_matrix_rows={0x60630058U,"mesh_matrix_rows",sxsm_matrix_rows_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_columns_fields[]={SX_FIELD("matrix_columns","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_matrix_columns={0x60630059U,"mesh_matrix_columns",sxsm_matrix_columns_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nonzero_count_fields[]={SX_FIELD("nonzero_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_nonzero_count={0x6063005aU,"mesh_nonzero_count",sxsm_nonzero_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_elemental_values_fields[]={SX_FIELD("elemental_values","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_elemental_values={0x6063005bU,"mesh_elemental_values",sxsm_elemental_values_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_column_pointer_fields[]={SX_FIELD("column_pointer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_column_pointer={0x6063005cU,"mesh_column_pointer",sxsm_column_pointer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_row_index_fields[]={SX_FIELD("row_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_row_index={0x6063005dU,"mesh_row_index",sxsm_row_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_key_fields[]={SX_FIELD("matrix_key","char",0,0,SX_STRING)};
const sx_layout sxsm_matrix_key={0x6063005eU,"mesh_matrix_key",sxsm_matrix_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_type_fields[]={SX_FIELD("matrix_type","char",0,0,SX_STRING)};
const sx_layout sxsm_matrix_type={0x6063005fU,"mesh_matrix_type",sxsm_matrix_type_fields,1,SX_LE};
static bool sxsm_column(sxsm_cursor*q,const sx_layout*l,sxsm_token line,unsigned at,unsigned width){if(at>(uint64_t)line.z||width>(uint64_t)line.z-at)return false;sxsm_token t={line.a+at,width};/* Blank optional numeric columns remain raw. */if(!sxsm_trim(q,t).z)return true;return sxsm_emit(q,l,t);}
#define SM_COL(n,o,z) do{if(!sxsm_column(q,&sxsm_##n,line,(o),(z)))return false;}while(0)
static bool sxsm_hb_format(sxsm_cursor*q,sxsm_token t,unsigned*repeat,unsigned*width){t=sxsm_trim(q,t);if(t.z<5||q->b[t.a]!='(')return false;int64_t p=1,a=p;while(p<t.z&&q->b[t.a+p]>='0'&&q->b[t.a+p]<='9')p++;uint64_t v;if(!sxsm_number(q,(sxsm_token){t.a+a,p-a},&v)||v>1000||!v)return false;*repeat=(unsigned)v;if(p==t.z)return false;p++;a=p;while(p<t.z&&q->b[t.a+p]>='0'&&q->b[t.a+p]<='9')p++;if(!sxsm_number(q,(sxsm_token){t.a+a,p-a},&v)||!v||v>96)return false;*width=(unsigned)v;return true;}
static bool sxsm_hb(sxsm_cursor*q){sxsm_token line;unsigned repeats[3],widths[3];uint64_t cols,nnz;if(!sxsm_line(q,&line)||line.z!=80)return false;SM_COL(title,0,72);SM_COL(matrix_key,72,8);if(!sxsm_line(q,&line)||(line.z!=56&&line.z!=70))return false;const sx_layout*counts[]={&sxsm_hb_total_lines,&sxsm_hb_pointer_lines,&sxsm_hb_index_lines,&sxsm_hb_value_lines,&sxsm_hb_rhs_lines};for(unsigned i=0;i<(unsigned)line.z/14;i++)if(!sxsm_column(q,counts[i],line,i*14,14))return false;
 if(!sxsm_line(q,&line)||line.z!=70)return false;SM_COL(matrix_type,0,3);SM_COL(matrix_rows,14,14);SM_COL(matrix_columns,28,14);SM_COL(nonzero_count,42,14);SM_COL(elemental_values,56,14);if(!sxsm_number(q,(sxsm_token){line.a+28,14},&cols)||!sxsm_number(q,(sxsm_token){line.a+42,14},&nnz)||cols>1000000||nnz>1000000)return false;
 if(!sxsm_line(q,&line)||(line.z!=52&&line.z!=72))return false;for(unsigned i=0;i<3;i++){unsigned at=i*16,width=i==2?20:16;if(!sxsm_column(q,&sxsm_format_string,line,at,width)||!sxsm_hb_format(q,(sxsm_token){line.a+at,width},repeats+i,widths+i))return false;}
 const sx_layout*values[]={&sxsm_column_pointer,&sxsm_row_index,&sxsm_scalar_value};uint64_t totals[]={cols+1,nnz,nnz};for(unsigned k=0;k<3;k++){uint64_t done=0;bool first=true;while(done<totals[k]){if(q->c->count>=24000)return true;unsigned n=(unsigned)(totals[k]-done<repeats[k]?totals[k]-done:repeats[k]);if(!sxsm_line(q,&line))return false;if(k==2&&first&&widths[k]>1&&(uint64_t)line.z==(uint64_t)n*(widths[k]-1))widths[k]--;first=false;if((uint64_t)line.z!=(uint64_t)n*widths[k])return false;for(unsigned i=0;i<n;i++)if(!sxsm_column(q,values[k],line,i*widths[k],widths[k]))return false;done+=n;}}return true;}
bool sx_harwell_boeing_build(sxsm_cursor*q)
{
 return sxsm_hb(q);
}
#undef SM_COL
