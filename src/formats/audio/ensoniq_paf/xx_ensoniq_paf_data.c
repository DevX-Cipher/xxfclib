/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ensoniq_paf data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_paf_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sample_byte_order","int32",8,4,SX_ID),
 SX_FIELD("sample_rate","int32",12,4,SX_NONE),
 SX_FIELD("encoding","int32",16,4,SX_ID),
 SX_FIELD("channels","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("source","int32",24,4,SX_ID),
};
const sx_layout sxau_paf_header_le={UINT32_C(0x602C0069),"paf_header_le",sxau_paf_header_le_fields,SX_COUNT(sxau_paf_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_paf_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sample_byte_order","int32",8,4,SX_ID),
 SX_FIELD("sample_rate","int32",12,4,SX_NONE),
 SX_FIELD("encoding","int32",16,4,SX_ID),
 SX_FIELD("channels","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("source","int32",24,4,SX_ID),
};
const sx_layout sxau_paf_header_be={UINT32_C(0x602C006E),"paf_header_be",sxau_paf_header_be_fields,SX_COUNT(sxau_paf_header_be_fields),SX_BE};
bool sx_ensoniq_paf_build(sxau_view*v)
{
 return sxau_need(v,0,4,v->n)&&sxau_row(v,v->p[0]==' '?&sxau_paf_header_be:&sxau_paf_header_le,0,v->n);
}
