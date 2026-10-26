/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari LARC PFX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_pfx_gemdos_header_fields[]={
 SX_FIELD("branch","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("text_size","uint32",2,4,SX_SIZE),
 SX_FIELD("data_size","uint32",6,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",10,4,SX_SIZE),
 SX_FIELD("symbol_size","uint32",14,4,SX_SIZE),
 SX_FIELD("reserved","uint32",18,4,SX_RESERVED),
 SX_FIELD("flags","uint32",22,4,SX_FLAGS),
 SX_FIELD("absolute_flag","uint16",26,2,SX_FLAGS),
};
const sx_layout sxaend_pfx_gemdos_header={UINT32_C(0x6084003f),"pfx_gemdos_header",sxaend_pfx_gemdos_header_fields,SX_COUNT(sxaend_pfx_gemdos_header_fields),SX_BE};
bool sx_larc_pfx_build(sx_context*c)
{
 return sxaend_add(c,&sxaend_pfx_gemdos_header,0)&&sxaend_carrier_records(c);
}
