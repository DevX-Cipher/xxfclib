/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cri_ahx data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_cri_ahx_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("data_offset_minus_four","uint16",2,2,SX_OFFSET),
 SX_FIELD("encoding","uint8",4,1,SX_ID),
 SX_FIELD("block_size","uint8",5,1,SX_SIZE),
 SX_FIELD("sample_bit_depth","uint8",6,1,SX_NONE),
 SX_FIELD("channels","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint32",8,4,SX_NONE),
 SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("highpass_frequency","uint16",16,2,SX_NONE),
 SX_FIELD("version","uint8",18,1,SX_ID),
 SX_FIELD("encryption_type","uint8",19,1,SX_ID),
 SX_FIELD("unknown","bytes",20,4,SX_NONE),
};
const sx_layout sxau_cri_ahx_header={UINT32_C(0x602C0061),"cri_ahx_header",sxau_cri_ahx_header_fields,SX_COUNT(sxau_cri_ahx_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_cri_ahx_copyright_fields[]={
 SX_FIELD("copyright","char[6]",0,6,SX_SIGNATURE),
};
const sx_layout sxau_cri_ahx_copyright={UINT32_C(0x602C0062),"cri_ahx_copyright",sxau_cri_ahx_copyright_fields,SX_COUNT(sxau_cri_ahx_copyright_fields),SX_BE};
static const xx_data_struct_field_desc sxau_cri_ahx_footer_fields[]={
 SX_FIELD("marker","char[10]",0,10,SX_SIGNATURE),
};
const sx_layout sxau_cri_ahx_footer={UINT32_C(0x602C0063),"cri_ahx_footer",sxau_cri_ahx_footer_fields,SX_COUNT(sxau_cri_ahx_footer_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sx_cri_ahx_build(sxau_view*v)
{
 bool ok=false;if(SA_ROW(cri_ahx_header,0,v->n)){size_t start=(size_t)sxau_u16(v->p+2,true)+4;ok=start>=24&&SA_ROW(cri_ahx_copyright,start-6,v->n);if(ok&&v->n>=10&&!xx_rt_memcmp(v->p+v->n-10,"AHXE(c)CRI",10))ok=SA_ROW(cri_ahx_footer,v->n-10,v->n);}return ok;
}
#undef SA_ROW
