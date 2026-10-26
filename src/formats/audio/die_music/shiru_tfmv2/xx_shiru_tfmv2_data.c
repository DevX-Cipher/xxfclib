/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shiru's TFM Music Maker module (.TFE) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_tfm_rle_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
};
const sx_layout sxmw_tfm_rle_header={UINT32_C(0x6087002D),"tfm_rle_header",sxmw_tfm_rle_header_fields,SX_COUNT(sxmw_tfm_rle_header_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
static bool sxmw_tfm(sxmw_view*v)
{uint64_t end=v->c->size;return sxmw_eq(v,0,"TFMfmtV2",8,end)&&MW_ROW(tfm_rle_header,0,end)&&sxmw_rle(v,8,end);}
bool sx_shiru_tfmv2_build(sxmw_view*v)
{
 return sxmw_tfm(v);
}
#undef MW_ROW
