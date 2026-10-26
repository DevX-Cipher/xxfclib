/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * atari_sap data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_sap_binary_marker_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxau_sap_binary_marker={UINT32_C(0x602C003D),"sap_binary_marker",sxau_sap_binary_marker_fields,SX_COUNT(sxau_sap_binary_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sap_load_segment_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("end_address_inclusive","uint16",2,2,SX_ADDRESS),
};
const sx_layout sxau_sap_load_segment={UINT32_C(0x602C003E),"sap_load_segment",sxau_sap_load_segment_fields,SX_COUNT(sxau_sap_load_segment_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_sap(sxau_view*v)
{size_t at=0;while(at+1<v->n&&at<65536&&!(v->p[at]==255&&v->p[at+1]==255))at++;if(!SA_ROW(sap_binary_marker,at,v->n))return false;at+=2;while(at<v->n){if(!sxau_need(v,at,2,v->n))return false;if(sxau_u16(v->p+at,false)==65535){if(!SA_ROW(sap_binary_marker,at,v->n))return false;at+=2;}if(!SA_ROW(sap_load_segment,at,v->n))return false;uint32_t a=sxau_u16(v->p+at,false),b=sxau_u16(v->p+at+2,false);at+=4;if(b<a||!sxau_need(v,at,b-a+1,v->n))return false;at+=b-a+1;}return true;}
bool sx_atari_sap_build(sxau_view*v)
{
 return sxau_sap(v);
}
#undef SA_ROW
