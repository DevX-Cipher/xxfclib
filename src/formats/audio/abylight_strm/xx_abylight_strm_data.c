/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * abylight_strm data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_abylight_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("sample_rate","uint32",8,4,SX_NONE),
 SX_FIELD("unknown_c","bytes",12,4,SX_NONE),
 SX_FIELD("stream_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("unknown_14","bytes",20,4,SX_NONE),
 SX_FIELD("stream_bytes_copy","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown_1c","bytes",28,2,SX_NONE),
};
const sx_layout sxau_abylight_header={UINT32_C(0x602C006F),"abylight_header",sxau_abylight_header_fields,SX_COUNT(sxau_abylight_header_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sx_abylight_strm_build(sxau_view*v)
{
 return SA_ROW(abylight_header,0,v->n)&&sxau_adts(v,30,v->n);
}
#undef SA_ROW
