/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lego_alp data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_alp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_bytes_after_prefix","uint32",4,4,SX_SIZE),
 SX_FIELD("encoding","char[6]",8,6,SX_ID),
 SX_FIELD("unknown","uint8",14,1,SX_NONE),
 SX_FIELD("channels","uint8",15,1,SX_COUNT_PROP),
};
const sx_layout sxau_alp_header={UINT32_C(0x602C0070),"alp_header",sxau_alp_header_fields,SX_COUNT(sxau_alp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_alp_sample_rate_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
};
const sx_layout sxau_alp_sample_rate={UINT32_C(0x602C0071),"alp_sample_rate",sxau_alp_sample_rate_fields,SX_COUNT(sxau_alp_sample_rate_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sx_lego_alp_build(sxau_view*v)
{
 bool ok=false;ok=SA_ROW(alp_header,0,v->n);if(ok&&sxau_u32(v->p+4,false)==12)ok=SA_ROW(alp_sample_rate,16,v->n);return ok;
}
#undef SA_ROW
