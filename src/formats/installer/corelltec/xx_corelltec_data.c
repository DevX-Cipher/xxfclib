/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CORELLTEC data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_corelltec_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("zero","uint8",8,1,SX_NONE),
};
const sx_layout sxao_corelltec_header = {UINT32_C(0x60700018),"corelltec_header",sxao_corelltec_header_fields,SX_COUNT(sxao_corelltec_header_fields),SX_LE};
bool sx_corelltec_build(sx_context*c)
{
 return sxao_add(c,&sxao_corelltec_header,0)&&sxao_native_members(c);
}
