/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shiru's VGM Music Maker module (.VGE) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_vge_header_fields[]={
 SX_FIELD("magic","bytes",0,7,SX_SIGNATURE),
 SX_FIELD("version_ascii","char[1]",7,1,SX_NONE),
 SX_FIELD("packed_song_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_sample_table_bytes","uint32",12,4,SX_SIZE),
};
const sx_layout sxmw_vge_header={UINT32_C(0x60870031),"vge_header",sxmw_vge_header_fields,SX_COUNT(sxmw_vge_header_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
static bool sxmw_vge(sxmw_view*v)
{uint64_t end=v->c->size,a,b,ver;if(!sxmw_eq(v,0,"VGEfmtV",7,end)||!sxmw_u(v,7,1,&ver,end)||ver<'1'||ver>'3'||!sxmw_u(v,8,4,&a,end)||!sxmw_u(v,12,4,&b,end)||a>INT32_MAX||b>INT32_MAX||!sxmw_span(v,16,a+b,end)||!MW_ROW(vge_header,0,end))return false;
 if(ver=='1')return true;return sxmw_rle(v,16,16+a)&&sxmw_rle(v,16+a,16+a+b);}
bool sx_shiru_vge_build(sxmw_view*v)
{
 return sxmw_vge(v);
}
#undef MW_ROW
