/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ESCHALON_SETUP_EPSF data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_epsf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("runtime_size","uint32",6,4,SX_SIZE),
 SX_FIELD("runtime_packed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("runtime_byte_sum","uint32",14,4,SX_CHECKSUM),
};
const sx_layout sxan_epsf_header = {UINT32_C(0x60770025),"epsf_header",sxan_epsf_header_fields,SX_COUNT(sxan_epsf_header_fields),SX_LE};
static bool sxan_epsf(sx_context*c){uint64_t p;return sxan_pe_overlay(c,&p)&&sxan_add(c,&sxan_epsf_header,p);}
bool sx_eschalon_setup_epsf_build(sx_context*c)
{
bool ok=false;
ok=sxan_epsf(c);
(void)ok;return c->count&&sxan_finish(c);
}
