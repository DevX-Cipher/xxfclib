/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WEBSOCKET FRAMES data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_websocket_length16_fields[]={
 SX_FIELD("payload_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxnm_websocket_length16={UINT32_C(0x6026009E),"websocket_length16",sxnm_websocket_length16_fields,SX_COUNT(sxnm_websocket_length16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_length64_fields[]={
 SX_FIELD("payload_length","uint64",0,8,SX_SIZE),
};
const sx_layout sxnm_websocket_length64={UINT32_C(0x6026009F),"websocket_length64",sxnm_websocket_length64_fields,SX_COUNT(sxnm_websocket_length64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_mask_fields[]={
 SX_FIELD("masking_key","bytes",0,4,SX_NONE),
};
const sx_layout sxnm_websocket_mask={UINT32_C(0x602600A0),"websocket_mask",sxnm_websocket_mask_fields,SX_COUNT(sxnm_websocket_mask_fields),SX_BE};
static uint64_t sxnm_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,true);}
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_websocket(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(websocket_frame_header,at,v->n))return false;unsigned op=v->p[at]&15,f=v->p[at+1];uint64_t n=f&127;at+=2;
  if(n==126){if(!SN_ROW(websocket_length16,at,v->n))return false;n=sxnm_u16(v->p+at);at+=2;}else if(n==127){if(!SN_ROW(websocket_length64,at,v->n))return false;n=sxnm_u64(v->p+at);at+=8;}
  if(f&128){if(!SN_ROW(websocket_mask,at,v->n))return false;at+=4;}if(!sxnm_need(v,at,n,v->n))return false;if(!(f&128)&&op==8&&n>=2&&!SN_ROW(websocket_close_code,at,at+(size_t)n))return false;at+=(size_t)n;
 }return true;
}
bool sx_websocket_frames_build(sxnm_view*v)
{
 return sxnm_websocket(v);
}
#undef SN_ROW
