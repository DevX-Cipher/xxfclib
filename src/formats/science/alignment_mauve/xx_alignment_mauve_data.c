/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alignment_mauve data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_mauve_sequence_id_fields[]={SX_FIELD("mauve_sequence_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxseq_mauve_sequence_id={0x60730027U,"sequence_mauve_sequence_id",sxseq_mauve_sequence_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_mauve_start_fields[]={SX_FIELD("mauve_start","ascii_signed",0,0,SX_NONE)};
const sx_layout sxseq_mauve_start={0x60730028U,"sequence_mauve_start",sxseq_mauve_start_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_mauve_end_fields[]={SX_FIELD("mauve_end","ascii_signed",0,0,SX_NONE)};
const sx_layout sxseq_mauve_end={0x60730029U,"sequence_mauve_end",sxseq_mauve_end_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_source_filename_fields[]={SX_FIELD("source_filename","char",0,0,SX_STRING)};
const sx_layout sxseq_source_filename={0x6073002aU,"sequence_source_filename",sxseq_source_filename_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_mauve(sxseq_cursor*q)
{
 sxseq_token line,t[16];if(!sxseq_line(q,&line))return false;SEQ_EMIT(signature,line);
 while(sxseq_line(q,&line)){if(q->c->count>=24000)return true;line=sxseq_trim(q,line);if(!line.z)continue;if(q->b[line.a]=='#'){SEQ_EMIT(comment,line);continue;}if(sxseq_eq(q,line,"=")){SEQ_EMIT(terminator,line);continue;}
  if(q->b[line.a]=='>'){unsigned n=sxseq_split(q,line,t,16,false);if(n<4||n>16)return false;SEQ_EMIT(keyword,t[0]);int64_t c=0,d;while(c<t[1].z&&q->b[t[1].a+c]!=':')c++;d=c+1;while(d<t[1].z&&q->b[t[1].a+d]!='-')d++;if(!c||d>=t[1].z||d==c+1)return false;SEQ_EMIT(mauve_sequence_id,((sxseq_token){t[1].a,c}));SEQ_EMIT(mauve_start,((sxseq_token){t[1].a+c+1,d-c-1}));SEQ_EMIT(mauve_end,((sxseq_token){t[1].a+d+1,t[1].z-d-1}));SEQ_EMIT(strand,t[2]);SEQ_EMIT(source_filename,t[3]);if(n>4)SEQ_EMIT(comment,((sxseq_token){t[4].a,line.a+line.z-t[4].a}));
  }else if(!sxseq_chunks(q,&sxseq_sequence_text,line))return false;
 }return true;
}
bool sx_alignment_mauve_build(sxseq_cursor*q)
{
 return sxseq_mauve(q);
}
#undef SEQ_EMIT
