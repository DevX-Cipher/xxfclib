/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bzip 0.21 (bzip1) data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_bzip1_header_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("format_version","char[1]",2,1,SX_ID),
 SX_FIELD("block_size_digit","char[1]",3,1,SX_NONE),
};
const sx_layout sxarm_bzip1_header={UINT32_C(0x607c001b),"bzip1_header",sxarm_bzip1_header_fields,SX_COUNT(sxarm_bzip1_header_fields),SX_LE};
bool sx_bzip1_build(sx_context*c)
{
 bool ok=false;uint8_t b[4];if(sxarm_read(c,0,b,4)&&!xx_rt_memcmp(b,"BZ0",3)&&b[3]>='1'&&b[3]<='9')ok=sxarm_add(c,&sxarm_bzip1_header,0);return ok;
}
