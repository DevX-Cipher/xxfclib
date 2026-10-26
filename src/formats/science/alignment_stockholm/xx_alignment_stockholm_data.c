/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alignment_stockholm data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_annotation_key_fields[]={SX_FIELD("annotation_key","char",0,0,SX_STRING)};
const sx_layout sxseq_annotation_key={0x6073001dU,"sequence_annotation_key",sxseq_annotation_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_annotation_text_fields[]={SX_FIELD("annotation_text","char",0,0,SX_STRING)};
const sx_layout sxseq_annotation_text={0x6073001eU,"sequence_annotation_text",sxseq_annotation_text_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_stockholm(sxseq_cursor*q)
{
 sxseq_token line,t[8];if(!sxseq_line(q,&line))return false;SEQ_EMIT(signature,line);
 while(sxseq_line(q,&line)){
  if(q->c->count>=24000)return true;line=sxseq_trim(q,line);if(!line.z)continue;if(sxseq_eq(q,line,"//")){SEQ_EMIT(terminator,line);return true;}
  if(q->b[line.a]=='#'&&(line.z<2||q->b[line.a+1]!='=')){SEQ_EMIT(comment,line);continue;}
  unsigned n=sxseq_split(q,line,t,8,false);if(n>8||n<2)return false;
  if(q->b[line.a]=='#'){
   bool id=sxseq_eq(q,t[0],"#=GS")||sxseq_eq(q,t[0],"#=GR");unsigned key=id?2:1;if(n<=key+1)return false;SEQ_EMIT(keyword,t[0]);if(id)SEQ_EMIT(identifier,t[1]);SEQ_EMIT(annotation_key,t[key]);if(!sxseq_chunks(q,&sxseq_annotation_text,(sxseq_token){t[key+1].a,line.a+line.z-t[key+1].a}))return false;
  }else{if(n!=2)return false;SEQ_EMIT(identifier,t[0]);if(!sxseq_chunks(q,&sxseq_sequence_text,t[1]))return false;}
 }return false;
}
bool sx_alignment_stockholm_build(sxseq_cursor*q)
{
 return sxseq_stockholm(q);
}
#undef SEQ_EMIT
