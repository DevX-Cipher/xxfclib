/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC FUXOFT AYLANGUAGE FXM data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_fxm_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("load_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_fxm_header={UINT32_C(0x608F0002),"chip_fxm_header",sxchip_chip_fxm_header_fields,SX_COUNT(sxchip_chip_fxm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_fxm_channels_fields[]={
 SX_FIELD("channel_a_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("channel_b_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("channel_c_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_fxm_channels={UINT32_C(0x608F0003),"chip_fxm_channels",sxchip_chip_fxm_channels_fields,SX_COUNT(sxchip_chip_fxm_channels_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_fxm(sx_context*c){
 if(!sxchip_eq(c,0,"FXSM",4)||!sxchip_span(c,0,6))return false;
 return SXCHIP_ADD(c,chip_fxm_header,0)&&sxchip_opt(c,&sxchip_chip_fxm_channels,6,1);
}
bool sx_fuxoft_aylanguage_fxm_build(sx_context*c)
{
 return sxchip_fxm(c);
}
