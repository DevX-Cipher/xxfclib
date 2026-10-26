/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari ST Sound Header module (.SND,.SNDH) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_sndh_header_fields[]={
 SX_FIELD("init_instruction","bytes",0,4,SX_NONE),
 SX_FIELD("exit_instruction","bytes",4,4,SX_NONE),
 SX_FIELD("play_instruction","bytes",8,4,SX_NONE),
 SX_FIELD("magic","bytes",12,4,SX_SIGNATURE),
};
const sx_layout sxmr_sndh_header={UINT32_C(0x607D004B),"sndh_header",sxmr_sndh_header_fields,SX_COUNT(sxmr_sndh_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_tag_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
};
const sx_layout sxmr_sndh_tag={UINT32_C(0x607D004C),"sndh_tag",sxmr_sndh_tag_fields,SX_COUNT(sxmr_sndh_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_tunes_fields[]={
 SX_FIELD("tag","bytes",0,2,SX_ID),
 SX_FIELD("tunes","ascii_decimal[2]",2,2,SX_COUNT_PROP),
};
const sx_layout sxmr_sndh_tunes={UINT32_C(0x607D004D),"sndh_tunes",sxmr_sndh_tunes_fields,SX_COUNT(sxmr_sndh_tunes_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_default_fields[]={
 SX_FIELD("tag","bytes",0,2,SX_ID),
 SX_FIELD("default_tune","ascii_decimal[2]",2,2,SX_NONE),
};
const sx_layout sxmr_sndh_default={UINT32_C(0x607D004E),"sndh_default",sxmr_sndh_default_fields,SX_COUNT(sxmr_sndh_default_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_timer_fields[]={
 SX_FIELD("timer","bytes",0,2,SX_ID),
};
const sx_layout sxmr_sndh_timer={UINT32_C(0x607D004F),"sndh_timer",sxmr_sndh_timer_fields,SX_COUNT(sxmr_sndh_timer_fields),SX_BE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_sndh(sxmr_view*v)
{uint64_t end=v->c->size,p=16,n=1,x,base,last,q;uint8_t b[4];if(!sxmr_eq(v,12,"SNDH",4,end)||!MR_ROW(sndh_header,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,b,4,end))return false;
  if(!xx_rt_memcmp(b,"HDNS",4))return MR_ROW(sndh_tag,p,end);
  if(!b[0]){p++;continue;}
  if(!xx_rt_memcmp(b,"##",2)||(!xx_rt_memcmp(b,"#!",2)&&xx_rt_memcmp(b,"#!SN",4))){if(b[2]<'0'||b[2]>'9'||b[3]<'0'||b[3]>'9')return false;x=(b[2]-'0')*10+b[3]-'0';if(b[1]=='#'){if(!x||!MR_ROW(sndh_tunes,p,end))return false;n=x;}else if(!MR_ROW(sndh_default,p,end))return false;p+=4;continue;}
  if(!xx_rt_memcmp(b,"TITL",4)||!xx_rt_memcmp(b,"COMM",4)||!xx_rt_memcmp(b,"RIPP",4)||!xx_rt_memcmp(b,"CONV",4)||!xx_rt_memcmp(b,"YEAR",4)||!xx_rt_memcmp(b,"FLAG",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;if(!sxmr_string(v,&p,end))return false;continue;}
  if((b[0]=='T'&&b[1]>='A'&&b[1]<='D')||(b[0]=='!'&&b[1]=='V')){if(!MR_ROW(sndh_timer,p,end))return false;p+=2;if(!sxmr_string(v,&p,end))return false;continue;}
  if(!xx_rt_memcmp(b,"TIME",4)||!xx_rt_memcmp(b,"FRMS",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;x=b[0]=='T'?2:4;if(!sxmr_table(v,x==2?&sxmr_sndh_seconds:&sxmr_sndh_frames,p,n,end))return false;p+=n*x;continue;}
  if(!xx_rt_memcmp(b,"#!SN",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;base=p;last=p+2*n;if(!sxmr_table(v,&sxmr_sndh_name_offset,p,n,end))return false;
   for(uint64_t i=0;i<n;i++){if(!sxmr_be(v,base+2*i,2,&x,end)||x<2*n||!sxmr_span(v,base,x,end))return false;q=base+x;if(!sxmr_string(v,&q,end))return false;if(q>last)last=q;}p=last;continue;}
  /* Unrecognized extension tags have no length grammar; preserve them and later code verbatim. */
  return true;
 }
 return false;}
bool sx_atarist_soundheader_build(sxmr_view*v)
{
 return sxmr_sndh(v);
}
#undef MR_ROW
