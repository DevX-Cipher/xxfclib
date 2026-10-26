/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * R.Schrijvers & M.Delorme's MoonBlaster module (.MBM) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_mbm_edit_marker_fields[]={
 SX_FIELD("edit_marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxchip_chip_mbm_edit_marker={UINT32_C(0x608F0043),"chip_mbm_edit_marker",sxchip_chip_mbm_edit_marker_fields,SX_COUNT(sxchip_chip_mbm_edit_marker_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
/* Physical MSX file reads mirror the retained RoboPlay loaders; segmented
 * runtime pointers and decoded patterns never become invented file offsets. */
static bool sxchip_mbm(sx_context*c){
 uint8_t first,h[376],orders[220];if(!sxchip_u8(c,0,&first))return true;
 uint64_t start=first==255?1:0,p=start+376;bool edit=start!=0;
 if(!sxchip_read(c,start,h,sizeof(h)))return true;
 if(edit&&!SXCHIP_ADD(c,chip_mbm_edit_marker,0))return false;
 if(!SXCHIP_ADD(c,chip_mbm_header,start))return false;
 unsigned active=(unsigned)h[0]+1U,count=edit?201U:active;
 if(count>220||active>count||!sxchip_read(c,p,orders,count))return true;
 if(!sxchip_put(c,&sxchip_chip_moon_position,p,count))return false;p+=count;
 unsigned high=0;for(unsigned i=0;i<active;i++)if(orders[i]>high)high=orders[i];
 return high>0&&high<=80?sxchip_opt(c,&sxchip_chip_mbm_pattern_pointer,p,high):true;
}
bool sx_schrijvers_moonblaster_mbm_build(sx_context*c)
{
 return sxchip_mbm(c);
}
