/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * urwani_soundfactory_psf data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_psf_header_fields[]={
 SX_FIELD("module_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnextm_psf_header={UINT32_C(0x608B0050),"psf_header",sxnextm_psf_header_fields,SX_COUNT(sxnextm_psf_header_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_psf(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,n;if(!sxnextm_be(v,0,4,&n,e)||n<276||!sxnextm_span(v,0,n,e)||!NX_ROW(psf_header,0,e)||!sxnextm_table(v,&sxnextm_psf_channels,4,16,n)||!sxnextm_table(v,&sxnextm_offset32be,20,64,n))return false;return true;}
bool sx_urwani_soundfactory_psf_build(sxnextm_view*v)
{
 return sxnextm_psf(v);
}
#undef NX_ROW
