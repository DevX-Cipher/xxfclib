/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * interplay_acm data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_acm_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint16",10,2,SX_NONE),
 SX_FIELD("levels_and_subblocks","uint16",12,2,SX_FLAGS),
};
const sx_layout sxau_acm_header={UINT32_C(0x602C0060),"acm_header",sxau_acm_header_fields,SX_COUNT(sxau_acm_header_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sx_interplay_acm_build(sxau_view*v)
{
 return SA_ROW(acm_header,0,v->n);
}
#undef SA_ROW
