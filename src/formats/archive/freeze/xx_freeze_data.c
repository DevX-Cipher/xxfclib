/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Freeze 2 data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_freeze2_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("format_version","uint8",1,1,SX_ID),
 SX_FIELD("distance_counts_1_to_5","uint16",2,2,SX_NONE),
 SX_FIELD("distance_count_6","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxarm_freeze2_header={UINT32_C(0x607c001c),"freeze2_header",sxarm_freeze2_header_fields,SX_COUNT(sxarm_freeze2_header_fields),SX_LE};
bool sx_freeze_build(sx_context*c)
{
 bool ok=false;uint64_t v;if(sxarm_word(c,0,2,true,&v)&&v==0x1f9f)ok=sxarm_add(c,&sxarm_freeze2_header,0);return ok;
}
