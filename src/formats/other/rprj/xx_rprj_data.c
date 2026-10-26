/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Radare project data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_rprj_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32le",4,4,SX_NONE),
};
const sx_layout sxdw_rprj_header={0x6074001aU,"documentwire_rprj_header",sxdw_rprj_header_fields,SX_COUNT(sxdw_rprj_header_fields),SX_LE};
bool sx_rprj_build(sxdw_cursor*q)
{
 return sxdw_emit(q,&sxdw_rprj_header,0,8);
}
