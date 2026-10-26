/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * olympus_dss data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_dss_header_fields[]={
 SX_FIELD("header_512byte_blocks","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("signature","char[3]",1,3,SX_SIGNATURE),
 SX_FIELD("opaque_metadata","bytes",4,34,SX_NONE),
 SX_FIELD("recording_start","char[12]",38,12,SX_STRING),
 SX_FIELD("recording_end","char[12]",50,12,SX_STRING),
 SX_FIELD("duration_hhmmss","char[6]",62,6,SX_STRING),
};
const sx_layout sxau_dss_header={UINT32_C(0x602C0064),"dss_header",sxau_dss_header_fields,SX_COUNT(sxau_dss_header_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
bool sx_olympus_dss_build(sxau_view*v)
{
 return SA_ROW(dss_header,0,v->n);
}
#undef SA_ROW
