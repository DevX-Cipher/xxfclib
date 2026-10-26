/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cri_awb data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_awb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("offset_width","uint8",5,1,SX_SIZE),
 SX_FIELD("id_width","uint16",6,2,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("alignment","uint16",12,2,SX_SIZE),
 SX_FIELD("subkey","uint16",14,2,SX_ID),
};
const sx_layout sxau_awb_header={UINT32_C(0x602C0001),"awb_header",sxau_awb_header_fields,SX_COUNT(sxau_awb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_id16_fields[]={
 SX_FIELD("entry_id","uint16",0,2,SX_ID),
};
const sx_layout sxau_awb_id16={UINT32_C(0x602C0002),"awb_id16",sxau_awb_id16_fields,SX_COUNT(sxau_awb_id16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_offset16_fields[]={
 SX_FIELD("entry_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxau_awb_offset16={UINT32_C(0x602C0003),"awb_offset16",sxau_awb_offset16_fields,SX_COUNT(sxau_awb_offset16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_id32_fields[]={
 SX_FIELD("entry_id","uint32",0,4,SX_ID),
};
const sx_layout sxau_awb_id32={UINT32_C(0x602C0004),"awb_id32",sxau_awb_id32_fields,SX_COUNT(sxau_awb_id32_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_offset32_fields[]={
 SX_FIELD("entry_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxau_awb_offset32={UINT32_C(0x602C0005),"awb_offset32",sxau_awb_offset32_fields,SX_COUNT(sxau_awb_offset32_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_awb(sxau_view*v)
{if(!SA_ROW(awb_header,0,v->n))return false;unsigned ow=v->p[5],iw=sxau_u16(v->p+6,false);uint64_t n=sxau_u32(v->p+8,false);if((ow!=2&&ow!=4)||(iw!=2&&iw!=4)||n>1000000)return false;return sxau_table(v,iw==2?&sxau_awb_id16:&sxau_awb_id32,16,n,v->n)&&sxau_table(v,ow==2?&sxau_awb_offset16:&sxau_awb_offset32,16+(size_t)n*iw,n+1,v->n);}
bool sx_cri_awb_build(sxau_view*v)
{
 return sxau_awb(v);
}
#undef SA_ROW
