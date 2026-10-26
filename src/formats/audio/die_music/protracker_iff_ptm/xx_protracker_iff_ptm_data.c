/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ProTracker IFF-wrapped module (.PTM) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_pt36_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("form_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
const sx_layout sxmr_pt36_header={UINT32_C(0x607D0048),"pt36_header",sxmr_pt36_header_fields,SX_COUNT(sxmr_pt36_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_pt36_info_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("samples","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",34,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("volume","uint16",38,2,SX_NONE),
 SX_FIELD("tempo","uint16",40,2,SX_NONE),
 SX_FIELD("flags","uint16",42,2,SX_FLAGS),
 SX_FIELD("day","uint16",44,2,SX_NONE),
 SX_FIELD("month","uint16",46,2,SX_NONE),
 SX_FIELD("year","uint16",48,2,SX_NONE),
 SX_FIELD("hour","uint16",50,2,SX_NONE),
 SX_FIELD("minute","uint16",52,2,SX_NONE),
 SX_FIELD("second","uint16",54,2,SX_NONE),
 SX_FIELD("play_hours","uint16",56,2,SX_NONE),
 SX_FIELD("play_minutes","uint16",58,2,SX_NONE),
 SX_FIELD("play_seconds","uint16",60,2,SX_NONE),
 SX_FIELD("play_milliseconds","uint16",62,2,SX_NONE),
};
const sx_layout sxmr_pt36_info={UINT32_C(0x607D004A),"pt36_info",sxmr_pt36_info_fields,SX_COUNT(sxmr_pt36_info_fields),SX_BE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_pt36(sxmr_view*v)
{uint64_t end=v->c->size,p=12,n,first=4;uint8_t id[4];if(!sxmr_eq(v,0,"FORM",4,end)||!sxmr_eq(v,8,"MODL",4,end)||!MR_ROW(pt36_header,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,id,4,end)||!sxmr_be(v,p+4,4,&n,end)||n<8+first||!MR_ROW(pt36_chunk,p,end))return false;n-=8+first;first=0;p+=8;if(!sxmr_span(v,p,n,end))return false;
  if(!xx_rt_memcmp(id,"INFO",4)&&n>=64){if(!MR_ROW(pt36_info,p,end))return false;}
  else if(!xx_rt_memcmp(id,"VERS",4)&&n>4){if(!sxmr_text_emit(v,p+4,n-4,end))return false;}
  else if(!xx_rt_memcmp(id,"CMNT",4)){if(!sxmr_text_emit(v,p,n,end))return false;}
  p+=n;
 }
 return true;}
bool sx_protracker_iff_ptm_build(sxmr_view*v)
{
 return sxmr_pt36(v);
}
#undef MR_ROW
