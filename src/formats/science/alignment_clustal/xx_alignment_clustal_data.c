/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alignment_clustal data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_consensus_fields[]={SX_FIELD("consensus","char",0,0,SX_STRING)};
const sx_layout sxseq_consensus={0x6073001cU,"sequence_consensus",sxseq_consensus_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_clustal(sxseq_cursor*q)
{
 sxseq_token line,t[4];if(!sxseq_line(q,&line))return false;SEQ_EMIT(signature,line);
 while(sxseq_line(q,&line)){if(q->c->count>=24000)return true;if(!sxseq_trim(q,line).z)continue;if(q->b[line.a]==' '||q->b[line.a]=='\t'){SEQ_EMIT(consensus,line);continue;}unsigned n=sxseq_split(q,line,t,4,false);if(n<2||n>3)return false;SEQ_EMIT(identifier,t[0]);if(!sxseq_chunks(q,&sxseq_sequence_text,t[1]))return false;if(n==3)SEQ_EMIT(residue_total,t[2]);}return true;
}
bool sx_alignment_clustal_build(sxseq_cursor*q)
{
 return sxseq_clustal(q);
}
#undef SEQ_EMIT
