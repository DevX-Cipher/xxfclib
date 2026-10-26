/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stanislav 'KSA' Kuzin's Sound Tracker Pro module (.STF,.F) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_stf_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_volume={UINT32_C(0x608F0007),"chip_stf_volume",sxchip_chip_stf_volume_fields,SX_COUNT(sxchip_chip_stf_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_position_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_position={UINT32_C(0x608F000B),"chip_stf_position",sxchip_chip_stf_position_fields,SX_COUNT(sxchip_chip_stf_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_settings_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_settings={UINT32_C(0x608F000F),"chip_stf_settings",sxchip_chip_stf_settings_fields,SX_COUNT(sxchip_chip_stf_settings_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_pattern_length_fields[]={
 SX_FIELD("row_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_stf_pattern_length={UINT32_C(0x608F0010),"chip_stf_pattern_length",sxchip_chip_stf_pattern_length_fields,SX_COUNT(sxchip_chip_stf_pattern_length_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_song_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
 SX_FIELD("title","char[25]",1,25,SX_NONE),
};
const sx_layout sxchip_chip_stf_song={UINT32_C(0x608F0011),"chip_stf_song",sxchip_chip_stf_song_fields,SX_COUNT(sxchip_chip_stf_song_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_stf(sx_context*c){
 if(!sxchip_span(c,0,3065))return false;
 for(unsigned i=0;i<15;i++){uint64_t p=130U*i;
  if(!sxchip_put(c,&sxchip_chip_stf_volume,p,32)||!sxchip_put(c,&sxchip_chip_stf_noise,p+32,32)||!sxchip_put(c,&sxchip_chip_stf_tone,p+64,32)||!SXCHIP_ADD(c,chip_stf_sample_loop,p+128))return false;}
 if(!sxchip_put(c,&sxchip_chip_stf_position,1950,256)||!SXCHIP_ADD(c,chip_stf_positions_end,2462))return false;
 /* The seventeenth 32-byte block is undocumented by the original converter;
  * its bytes stay raw rather than asserting another ornament. */
 for(unsigned i=0;i<16;i++){uint64_t p=2463U+32U*i;if(!SXCHIP_ADD(c,chip_stf_ornament,p)||!sxchip_put(c,&sxchip_chip_note_step,p+2,30))return false;}
 if(!SXCHIP_ADD(c,chip_stf_settings,3007)||!sxchip_put(c,&sxchip_chip_stf_pattern_length,3008,31)||!SXCHIP_ADD(c,chip_stf_song,3039))return false;
 uint64_t n=((uint64_t)c->size-3065)/576;if(n>31)n=31;
 return !n||sxchip_put(c,&sxchip_chip_stf_event,3065,n*192);
}
bool sx_ksa_soundtrackerpro_stf_project_co_build(sx_context*c)
{
 return sxchip_stf(c);
}
