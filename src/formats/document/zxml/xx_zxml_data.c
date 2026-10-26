/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZXML documents data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_zxml_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxdm_zxml_header={UINT32_C(0x60230004),"zxml_header",sxdm_zxml_header_fields,SX_COUNT(sxdm_zxml_header_fields),SX_LE};
bool sx_zxml_build(sx_context*c)
{
 return sxdm_add(c,&sxdm_zxml_header,0,12);
}
