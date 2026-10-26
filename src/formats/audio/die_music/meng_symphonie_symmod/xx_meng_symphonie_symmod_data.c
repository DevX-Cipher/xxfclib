/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Patrick Meng's Symphonie module (.SYMMOD) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_sym_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
};
const sx_layout sxmta_sym_header={UINT32_C(0x6081003E),"sym_header",sxmta_sym_header_fields,SX_COUNT(sxmta_sym_header_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_sym(sxmta_view*v)
{uint64_t end=v->c->size,p=8,id,n;
 if(!sxmta_eq(v,0,"SymM",4,end)||!MTA_ROW(sym_header,0,end))return false;
 while(p<end){if(!sxmta_be(v,p,4,&id,end))return false;int64_t k=id<=INT32_MAX?(int64_t)id:(int64_t)id-INT64_C(4294967296);
  if(k==-12){if(!MTA_TAKE(sym_empty_sample,&p,1,end))return false;continue;}
  if(k>=-21&&k<=-10){if(!sxmta_be(v,p+4,4,&n,end)||!MTA_TAKE(sym_bytes,&p,1,end)||!sxmta_skip(v,&p,n,end))return false;}
  else if((k>=-7&&k<=-1)||(k>=10&&k<=12)){if(!sxmta_take(v,k==-1||k==-2||k==-4?&sxmta_sym_count:&sxmta_sym_value,&p,1,end))return false;}
  else return true;
 }return true;}
bool sx_meng_symphonie_symmod_build(sxmta_view*v)
{
 return sxmta_sym(v);
}
#undef MTA_ROW
#undef MTA_TAKE
