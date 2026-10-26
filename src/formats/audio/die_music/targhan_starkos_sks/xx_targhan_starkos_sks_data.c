/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Julien 'Targhan' Nevo's STarKos module (.SKS) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_sks_end_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
const sx_layout sxchip_chip_sks_end={UINT32_C(0x608F0031),"chip_sks_end",sxchip_chip_sks_end_fields,SX_COUNT(sxchip_chip_sks_end_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_sks(sx_context*c){
 uint8_t h[60];if(!sxchip_read(c,0,h,60)||xx_rt_memcmp(h,"STK1.0SONG",10))return false;
 if(!SXCHIP_ADD(c,chip_sks_header,0))return false;if(h[59])return true;
 uint64_t count=(uint64_t)h[58]+1,p=60+8*count;
 if(!sxchip_span(c,60,8*count))return true;
 if(!sxchip_put(c,&sxchip_chip_sks_position,60,count))return false;
 /* Record extents include their size word/byte but exclude the preceding ID.
  * Packed musical commands are raw; no decompression or playback is needed. */
 for(unsigned kind=0;kind<3;kind++){
  bool ended=false;
  for(unsigned records=0;records<2048;records++){
   uint16_t id;if(!sxchip_u16(c,p,&id))return true;
   if(id==65535){if(!SXCHIP_ADD(c,chip_sks_end,p))return false;p+=2;ended=true;break;}
   uint16_t size=0;if(kind==1){uint8_t b;if(!sxchip_u8(c,p+2,&b))return true;size=b;}else if(!sxchip_u16(c,p+2,&size))return true;
   unsigned min=kind==0?17:kind==1?1:2;
   if(size<min||!sxchip_span(c,p,2U+size))return true;
   const sx_layout*l=kind==0?&sxchip_chip_sks_instrument:kind==1?&sxchip_chip_sks_special:&sxchip_chip_sks_track;
   if(!sxchip_put(c,l,p,1))return false;p+=2U+size;
  }
  if(!ended)return true;
 }
 return true;
}
bool sx_targhan_starkos_sks_build(sx_context*c)
{
 return sxchip_sks(c);
}
