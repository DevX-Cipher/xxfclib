/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Redlimited Extremetracker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_extremetracker_pattern_size_fields[]={
 SX_FIELD("row_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_extremetracker_pattern_size={UINT32_C(0x608A0073),"extremetracker_pattern_size",sxzxm_extremetracker_pattern_size_fields,SX_COUNT(sxzxm_extremetracker_pattern_size_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_et(sx_context*c){
 if(!SXZXM_ADD(c,extremetracker_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,34,100)||!sxzxm_opt(c,&sxzxm_extremetracker_pattern_size,134,32)||!sxzxm_opt(c,&sxzxm_extremetracker_memory,168,5)||!sxzxm_opt(c,&sxzxm_extremetracker_sample,256,16))return false;
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_extremetracker_event,512+512U*i,256))return false;return true;
}
bool sx_redlimited_extremetracker_build(sx_context*c)
{
 return sxzxm_et(c);
}
