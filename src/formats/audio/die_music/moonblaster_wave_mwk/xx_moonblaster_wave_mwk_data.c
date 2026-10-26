/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * R.Schrijvers & M.Delorme's MoonBlaster Wave for MoonSound wave kit (.MWK) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_mwk_name_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
const sx_layout sxchip_chip_mwk_name={UINT32_C(0x608F004E),"chip_mwk_name",sxchip_chip_mwk_name_fields,SX_COUNT(sxchip_chip_mwk_name_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_mwk(sx_context*c){
 uint8_t h[74];if(!sxchip_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"MBMS\x10",5)||(h[5]!=12&&h[5]!=13))return true;
 if(!SXCHIP_ADD(c,chip_mwk_header,0))return false;
 unsigned patches=h[9];if(patches>48)return true;
 uint64_t p=74;if(!sxchip_span(c,p,(uint64_t)patches*25))return true;
 if(!sxchip_put(c,&sxchip_chip_mwk_patch,p,patches))return false;p+=(uint64_t)patches*25;
 if(h[5]==12){if(!sxchip_span(c,p,(uint64_t)patches*16))return true;if(!sxchip_put(c,&sxchip_chip_mwk_name,p,patches))return false;p+=(uint64_t)patches*16;}
 for(unsigned i=0;i<64;i++)if(h[10+i]&1){
  if(h[5]==12){if(!sxchip_span(c,p,16))return true;if(!SXCHIP_ADD(c,chip_mwk_name,p))return false;p+=16;}
  uint8_t t[13];if(!sxchip_read(c,p,t,13))return true;bool rom=(h[10+i]&32)!=0;
  if(!sxchip_put(c,rom?&sxchip_chip_mwk_rom_tone:&sxchip_chip_mwk_ram_tone,p,1))return false;p+=13;
  if(!rom){uint16_t n=sxchip16(t+11);if(!sxchip_span(c,p,n))return true;p+=n;}
 }
 return true;
}
bool sx_moonblaster_wave_mwk_build(sx_context*c)
{
 return sxchip_mwk(c);
}
