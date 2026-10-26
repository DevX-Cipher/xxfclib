/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * partl_voodoosupremesynthesizer data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_vss_footer_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("subsongs","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxnextm_vss_footer={UINT32_C(0x608B0052),"vss_footer",sxnextm_vss_footer_fields,SX_COUNT(sxnextm_vss_footer_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_vss(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b,n;if(e<64)return false;for(b=(e-64+1)&~UINT64_C(1);b+8<=e;b+=2)if(sxnextm_eq(v,b,"VSS0",4,e))break;
 if(b+8>e||!sxnextm_be(v,b+4,4,&n,e)||n>=256||!NX_ROW(vss_footer,b,e)||!sxnextm_table(v,&sxnextm_vss_song_offset,b+8,n,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t song,p,min=b,x;if(!sxnextm_rel32(v,b+8+i*4,b,&song,e)||song>=b)return false;p=song;unsigned count=0;while(p<min){if(count++>=65536||!sxnextm_rel32(v,p,song,&x,e)||!NX_TAKE(vss_data_offset,&p,1,min))return false;if(x>=song&&x<min)min=x;}if(p!=min||count<4)return false;}return true;}
bool sx_partl_voodoosupremesynthesizer_build(sxnextm_view*v)
{
 return sxnextm_vss(v);
}
#undef NX_ROW
#undef NX_TAKE
