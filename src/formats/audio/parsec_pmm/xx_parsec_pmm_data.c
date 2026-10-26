/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * parsec_pmm data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_pmm_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("instrument_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("sample_offset0","uint32",20,4,SX_OFFSET),
 SX_FIELD("sample_offset1","uint32",24,4,SX_OFFSET),
 SX_FIELD("sample_offset2","uint32",28,4,SX_OFFSET),
 SX_FIELD("sample_offset3","uint32",32,4,SX_OFFSET),
 SX_FIELD("sample_offset4","uint32",36,4,SX_OFFSET),
 SX_FIELD("sample_offset5","uint32",40,4,SX_OFFSET),
 SX_FIELD("sample_offset6","uint32",44,4,SX_OFFSET),
 SX_FIELD("sample_offset7","uint32",48,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",52,4,SX_RESERVED),
 SX_FIELD("metadata_magic","char[4]",56,4,SX_SIGNATURE),
 SX_FIELD("unknown_3c","bytes",60,2,SX_NONE),
 SX_FIELD("track_relative_offset","uint16",62,2,SX_OFFSET),
 SX_FIELD("sample_count","uint8",64,1,SX_COUNT_PROP),
};
const sx_layout sxau_pmm_header={UINT32_C(0x602C0072),"pmm_header",sxau_pmm_header_fields,SX_COUNT(sxau_pmm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_pmm_sample_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("pcm_bytes","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown","bytes",8,2,SX_NONE),
};
const sx_layout sxau_pmm_sample={UINT32_C(0x602C0073),"pmm_sample",sxau_pmm_sample_fields,SX_COUNT(sxau_pmm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_pmm_instrument_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxau_pmm_instrument={UINT32_C(0x602C0074),"pmm_instrument",sxau_pmm_instrument_fields,SX_COUNT(sxau_pmm_instrument_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_pmm(sxau_view*v)
{if(!SA_ROW(pmm_header,0,v->n))return false;unsigned n=v->p[64];if(n>8||!SA_ROW(pmm_instrument,sxau_u32(v->p+16,false),v->n))return false;for(unsigned i=0;i<n;i++)if(!SA_ROW(pmm_sample,sxau_u32(v->p+20+4*i,false),v->n))return false;return true;}
bool sx_parsec_pmm_build(sxau_view*v)
{
 return sxau_pmm(v);
}
#undef SA_ROW
