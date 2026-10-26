/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * reiniervanvliet_sidmon1 data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_sid1_sequence_fields[]={
 SX_FIELD("track_number","uint32",0,4,SX_ID),
 SX_FIELD("unknown","uint8",4,1,SX_NONE),
 SX_FIELD("note_transpose","int8",5,1,SX_NONE),
};
const sx_layout sxnextm_sid1_sequence={UINT32_C(0x608B0072),"sid1_sequence",sxnextm_sid1_sequence_fields,SX_COUNT(sxnextm_sid1_sequence_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_sid1(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,limit=e<4096?e:4096,p=0,word,base,seq[4],data,n;
 if(e<1024||!sxnextm_find16(v,&p,0x41fa,limit-4,e)||!sxnextm_be(v,p+2,2,&word,e)||word>e-p-2)return false;base=p+2+word;p+=4;
 for(unsigned i=0;i<4;i++){uint64_t at;if(!sxnextm_find16(v,&p,0xd1e8,limit-4,e)||!sxnextm_rel(v,p+2,2,base,&at,e)||!NX_ROW(sid1_base_offset,at,e)||!sxnextm_rel32(v,at,base,&seq[i],e))return false;p+=4;}
 p=0;for(;p+4<limit;p+=2)if(sxnextm_eq(v,p,"\x48\xe7\xff\xfe",4,e))break;
 if(p+4>=limit||!sxnextm_find16(v,&p,0x6100,limit-4,e)||!sxnextm_find16(v,&p,0xd3e9,limit-4,e)||!sxnextm_rel(v,p+2,2,base,&word,e)||!NX_ROW(sid1_base_offset,word,e)||!sxnextm_rel32(v,word,base,&data,e)||!NX_ROW(sid1_song,data,e)||!sxnextm_be(v,data+28,4,&n,e)||!n)return false;n--;
 for(unsigned i=0;i<4;i++)if(!sxnextm_table(v,&sxnextm_sid1_sequence,seq[i],n,e))return false;return true;}
bool sx_reiniervanvliet_sidmon1_build(sxnextm_view*v)
{
 return sxnextm_sid1(v);
}
#undef NX_ROW
