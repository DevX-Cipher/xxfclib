/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alignment_phylip data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_alignment_columns_fields[]={SX_FIELD("alignment_columns","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_alignment_columns={0x60730012U,"sequence_alignment_columns",sxseq_alignment_columns_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_sequence_count_fields[]={SX_FIELD("sequence_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_sequence_count={0x60730013U,"sequence_sequence_count",sxseq_sequence_count_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_phylip(sxseq_cursor*q)
{
 sxseq_token line,t[128];uint64_t rows;if(!sxseq_line(q,&line))return false;unsigned n=sxseq_split(q,line,t,128,false);if(n!=2||!sxseq_number(q,t[0],&rows)||rows<2||rows>1024)return false;SEQ_EMIT(sequence_count,t[0]);SEQ_EMIT(alignment_columns,t[1]);uint64_t row=0;
 while(sxseq_line(q,&line)){if(q->c->count>=24000)return true;if(!sxseq_trim(q,line).z)continue;if(row<rows){if(line.z<=10)return false;SEQ_EMIT(identifier,((sxseq_token){line.a,10}));line.a+=10;line.z-=10;}n=sxseq_split(q,line,t,128,false);if(!n||n>128)return false;for(unsigned i=0;i<n;i++)SEQ_EMIT(sequence_text,t[i]);row++;}return row>=rows;
}
bool sx_alignment_phylip_build(sxseq_cursor*q)
{
 return sxseq_phylip(q);
}
#undef SEQ_EMIT
