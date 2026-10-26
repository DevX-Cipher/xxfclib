/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Undergroundsystems Digitalstudio data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_digitalstudio_order_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_digitalstudio_order={UINT32_C(0x608A006E),"digitalstudio_order",sxzxm_digitalstudio_order_fields,SX_COUNT(sxzxm_digitalstudio_order_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_event_fields[]={
 SX_FIELD("note_or_command","uint8",0,1,SX_ID),
 SX_FIELD("sample_or_parameter","uint8",1,1,SX_NONE),
};
const sx_layout sxzxm_digitalstudio_event={UINT32_C(0x608A0071),"digitalstudio_event",sxzxm_digitalstudio_event_fields,SX_COUNT(sxzxm_digitalstudio_event_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_ds(sx_context*c){
 if(!SXZXM_ADD(c,digitalstudio_order,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,1,99)||!sxzxm_opt(c,&sxzxm_digitalstudio_header,100,1)||!sxzxm_opt(c,&sxzxm_digitalstudio_sample,256,16))return false;
 /* Both variants define exactly32 physical pattern objects here. The
  * compiled variant's additional0x1000 bytes do not become invented events. */
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_digitalstudio_event,0x4200+384U*i,192))return false;return true;
}
bool sx_undergroundsystems_digitalstudio_build(sx_context*c)
{
 return sxzxm_ds(c);
}
