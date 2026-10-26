/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bluemoon's Sound Club for Windows module (.SN2) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_order32_fields[]={
 SX_FIELD("pattern","int32",0,4,SX_ID),
};
const sx_layout sxmw_order32={UINT32_C(0x60870007),"order32",sxmw_order32_fields,SX_COUNT(sxmw_order32_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sn2_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,3,SX_ID),
 SX_FIELD("payload_bytes","uint32",3,4,SX_SIZE),
};
const sx_layout sxmw_sn2_chunk={UINT32_C(0x60870042),"sn2_chunk",sxmw_sn2_chunk_fields,SX_COUNT(sxmw_sn2_chunk_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_sn2(sxmw_view*v)
{uint64_t end=v->c->size,p=31,n,ce;uint8_t tag[3];if(!sxmw_eq(v,0,"SN2",3,end)||!sxmw_u(v,3,4,&n,end)||!sxmw_span(v,7,n,end)||!MW_ROW(sn2_header,0,end))return false;end=7+n;
 while(p<end){if(!sxmw_read(v,p,tag,3,end)||!sxmw_u(v,p+3,4,&n,end)||!sxmw_span(v,p+7,n,end)||!MW_TAKE(sn2_chunk,&p,1,end))return false;ce=p+n;
  if(!xx_rt_memcmp(tag,"NAM",3)){if(!sxmw_text_emit(v,p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SEQ",3)){if(n%4||!MW_TAKE(order32,&p,n/4,ce))return false;}
  p=ce;
 }return true;}
bool sx_bluemoon_soundclub_sn2_build(sxmw_view*v)
{
 return sxmw_sn2(v);
}
#undef MW_ROW
#undef MW_TAKE
