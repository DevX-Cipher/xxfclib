/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TPWM data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_tpwm_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxas_tpwm_header = {UINT32_C(0x60430024),"tpwm_header",sxas_tpwm_header_fields,SX_COUNT(sxas_tpwm_header_fields),SX_BE};
bool sx_tpwm_build(sx_context*c)
{
 return sxas_add(c,&sxas_tpwm_header,0);
}
