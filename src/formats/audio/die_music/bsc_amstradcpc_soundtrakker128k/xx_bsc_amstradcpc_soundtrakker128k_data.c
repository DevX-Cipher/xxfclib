/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Oliver 'BSC' Mayer's Amstrad CPC Soundtrakker 128K module (.128) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_bsc128_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_bsc128_position={UINT32_C(0x608F002B),"chip_bsc128_position",sxchip_chip_bsc128_position_fields,SX_COUNT(sxchip_chip_bsc128_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
const sx_layout sxchip_chip_bsc128_name={UINT32_C(0x608F002C),"chip_bsc128_name",sxchip_chip_bsc128_name_fields,SX_COUNT(sxchip_chip_bsc128_name_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_bsc128(sx_context*c){
 const uint64_t b=128;if(!sxchip_span(c,0,b+0xB80))return false;
 if(!SXCHIP_ADD(c,chip_amsdos_header,0))return false;
 for(unsigned i=0;i<16;i++){uint64_t p=b+130U*i;
  if(!sxchip_put(c,&sxchip_chip_bsc128_volume,p,32)||!sxchip_put(c,&sxchip_chip_bsc128_noise,p+32,32)||!sxchip_put(c,&sxchip_chip_bsc128_tone,p+64,32)||!SXCHIP_ADD(c,chip_bsc128_loop,p+128))return false;}
 if(!sxchip_put(c,&sxchip_chip_note_step,b+0x820,512)||!sxchip_put(c,&sxchip_chip_bsc128_position,b+0xA30,96)||!SXCHIP_ADD(c,chip_bsc128_name,b+0xA90)||!sxchip_put(c,&sxchip_chip_bsc128_name,b+0xA98,16)||!sxchip_put(c,&sxchip_chip_note_step,b+0xB18,96)||!SXCHIP_ADD(c,chip_bsc128_settings,b+0xB7B))return false;
 uint8_t count,rows;if(!sxchip_u8(c,b+0xB7F,&count)||!sxchip_u8(c,b+0xB7D,&rows)||count>96||!rows)return true;
 unsigned max=0;for(unsigned i=0;i<count;i++){uint8_t n;if(!sxchip_u8(c,b+0xA30+i,&n))return true;if(n>max)max=n;}
 uint64_t patterns=(uint64_t)max+1;if(patterns>96)return true;
 return sxchip_opt(c,&sxchip_chip_bsc128_event,b+0xB80,patterns*rows*3);
}
bool sx_bsc_amstradcpc_soundtrakker128k_build(sx_context*c)
{
 return sxchip_bsc128(c);
}
