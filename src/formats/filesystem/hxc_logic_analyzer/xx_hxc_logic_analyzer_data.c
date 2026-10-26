/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HxC logic analyzer samples data structures, moved out of the logicsamples schema family. */
#include "../../xx_format_schema_logicsamples.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlogic_logic_signal_sample_fields[]={
 SX_FIELD("channel_levels","uint8",0,1,SX_FLAGS),
};
const sx_layout sxlogic_logic_signal_sample={0x60a00001U,"logic_signal_sample",sxlogic_logic_signal_sample_fields,SX_COUNT(sxlogic_logic_signal_sample_fields),SX_LE};
bool sx_hxc_logic_analyzer_build(sx_context*c)
{
 return sx_table(c,&sxlogic_logic_signal_sample,0,1,(uint64_t)c->size);
}
