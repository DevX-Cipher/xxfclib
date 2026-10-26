/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VTECH_VZ data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_vz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[17]",4,17,SX_STRING),
 SX_FIELD("file_type","uint8",21,1,SX_ID),
 SX_FIELD("load_address","uint16",22,2,SX_ADDRESS),
};
const sx_layout sxexm_vz_header = {UINT32_C(0x602b0001),"vz_header",sxexm_vz_header_fields,SX_COUNT(sxexm_vz_header_fields),SX_LE};
bool sx_vtech_vz_build(sx_context*c)
{
bool ok=false;
ok=sxexm_add(c,&sxexm_vz_header,0);
return ok&&sxexm_finish(c);
}
