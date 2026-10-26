/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CMS XEDIT PACK / COPYFILE PACK containers data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_xeditpack_header_fields[] = {
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
 SX_FIELD("ebcdic_blank","uint8",2,1,SX_SIGNATURE),
 SX_FIELD("record_format","uint8",3,1,SX_NONE),
 SX_FIELD("opaque","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxafr_xeditpack_header = {UINT32_C(0x60540029),"xeditpack_header",sxafr_xeditpack_header_fields,SX_COUNT(sxafr_xeditpack_header_fields),SX_LE};
bool sx_xeditpack_build(sx_context*c)
{
 return sxafr_add(c,&sxafr_xeditpack_header,0);
}
