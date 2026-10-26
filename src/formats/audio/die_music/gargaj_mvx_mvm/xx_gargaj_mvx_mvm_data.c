/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_GARGAJ_MVX_MVM data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcmore_mvx_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("tempo_bpm","uint8",4,1,SX_NONE),
 SX_FIELD("ticks_per_beat","uint8",5,1,SX_NONE),
 SX_FIELD("song_row_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("machine_count","uint8",10,1,SX_COUNT_PROP),
};
const sx_layout sxpcmore_mvx_header={UINT32_C(0x60990019),"mvx_header",sxpcmore_mvx_header_fields,SX_COUNT(sxpcmore_mvx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_mvx_machine_id_fields[]={
 SX_FIELD("machine_id","uint8",0,1,SX_ID),
};
const sx_layout sxpcmore_mvx_machine_id={UINT32_C(0x6099001A),"mvx_machine_id",sxpcmore_mvx_machine_id_fields,SX_COUNT(sxpcmore_mvx_machine_id_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_mvx_machine_order_fields[]={
 SX_FIELD("machine_index","uint8",0,1,SX_NONE),
};
const sx_layout sxpcmore_mvx_machine_order={UINT32_C(0x6099001B),"mvx_machine_order",sxpcmore_mvx_machine_order_fields,SX_COUNT(sxpcmore_mvx_machine_order_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_mvx_connection_count_fields[]={
 SX_FIELD("connection_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcmore_mvx_connection_count={UINT32_C(0x6099001C),"mvx_connection_count",sxpcmore_mvx_connection_count_fields,SX_COUNT(sxpcmore_mvx_connection_count_fields),SX_LE};
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
static bool sxpcmore_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxpcmore_width(l);return !count||!z||count>UINT64_MAX/z||!sxpcmore_span(c,p,count*z)?true:sxpcmore_put(c,l,p,count);}
static bool sxpcmore_mvx(sx_context*c){
 uint8_t h[11];if(!sxpcmore_read(c,0,h,11)||xx_rt_memcmp(h,"MVM\0",4))return false;
 if(!SXPCMORE_ADD(c,mvx_header,0))return false;
 uint64_t p=11,n=h[10];if(!sxpcmore_span(c,p,2*n+1))return true;
 if(!sxpcmore_put(c,&sxpcmore_mvx_machine_id,p,n)||!sxpcmore_put(c,&sxpcmore_mvx_machine_order,p+n,n)||!SXPCMORE_ADD(c,mvx_connection_count,p+2*n))return false;
 uint8_t count;if(!sxpcmore_u8(c,p+2*n,&count))return false;p+=2*n+1;
 return sxpcmore_opt(c,&sxpcmore_mvx_connection,p,count);
}
bool sx_gargaj_mvx_mvm_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_mvx(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
