/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XAMARIN_COMPRESSED_ASSEMBLY data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_xalz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("descriptor_index","uint32",4,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxexm_xalz_header = {UINT32_C(0x602b0002),"xalz_header",sxexm_xalz_header_fields,SX_COUNT(sxexm_xalz_header_fields),SX_LE};
bool sx_xamarin_compressed_assembly_build(sx_context*c)
{
bool ok=false;
ok=sxexm_add(c,&sxexm_xalz_header,0);
return ok&&sxexm_finish(c);
}
