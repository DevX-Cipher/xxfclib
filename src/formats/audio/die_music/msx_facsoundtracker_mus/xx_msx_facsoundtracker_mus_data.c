/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Federation Against Commodore's FAC Soundtracker module (.MUS) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_msx_bload_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("start_address","uint16",1,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",3,2,SX_ADDRESS),
 SX_FIELD("execution_address","uint16",5,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_msx_bload={UINT32_C(0x608F0051),"chip_msx_bload",sxchip_chip_msx_bload_fields,SX_COUNT(sxchip_chip_msx_bload_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_fac(sx_context*c){
 uint8_t b[7],version,last;if(!sxchip_read(c,0,b,7)||b[0]!=254||sxchip16(b+1)!=0x8000||sxchip16(b+3)!=0xbfff)return true;
 if(!SXCHIP_ADD(c,chip_msx_bload,0))return false;
 const uint64_t p=7+0x3f00;if(!sxchip_u8(c,p+0x8c,&version)||!sxchip_u8(c,p+0xf8,&last)||!sxchip_span(c,p,256))return true;
 if(!sxchip_put(c,version==3?&sxchip_chip_fac_pro_footer:&sxchip_chip_fac_footer,p,1))return false;
 /* Version3 XORs the physical pattern bytes by address. Keep that region raw. */
 if(version!=3&&last<84)return sxchip_opt(c,&sxchip_chip_fac_row,7,((unsigned)last+1)*16);
 return true;
}
bool sx_msx_facsoundtracker_mus_build(sx_context*c)
{
 return sxchip_fac(c);
}
