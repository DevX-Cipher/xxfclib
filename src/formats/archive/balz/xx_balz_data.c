/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BALZ data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_balz_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint64",1,8,SX_SIZE),
};
const sx_layout sxarm_balz_header={UINT32_C(0x607c001a),"balz_header",sxarm_balz_header_fields,SX_COUNT(sxarm_balz_header_fields),SX_LE};
bool sx_balz_build(sx_context*c)
{
 bool ok=false;uint8_t b[2];if(sxarm_read(c,0,b,1)&&b[0]==0xba)ok=sxarm_add(c,&sxarm_balz_header,0);return ok;
}
