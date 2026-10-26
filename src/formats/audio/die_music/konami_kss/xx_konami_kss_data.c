/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Konami's KSS chiptune (.KSS) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_kss_extended_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
 SX_FIELD("first_track","uint16",8,2,SX_ID),
 SX_FIELD("last_track","uint16",10,2,SX_ID),
 SX_FIELD("psg_volume","uint8",12,1,SX_NONE),
 SX_FIELD("scc_volume","uint8",13,1,SX_NONE),
 SX_FIELD("msx_music_volume","uint8",14,1,SX_NONE),
 SX_FIELD("msx_audio_volume","uint8",15,1,SX_NONE),
};
const sx_layout sxmn_kss_extended={UINT32_C(0x60760012),"kss_extended",sxmn_kss_extended_fields,SX_COUNT(sxmn_kss_extended_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_kss(sxmn_view*v)
{uint64_t end=v->c->size,extra,z,bank;if(!MN_ROW(kss_header,0,end)||!sxmn_word(v,14,1,false,&extra,end)||!sxmn_word(v,6,2,false,&z,end)||!sxmn_word(v,13,1,false,&bank,end)||!sxmn_span(v,16,extra,end)||!sxmn_span(v,16+extra,z,end))return false;if(extra>=16&&!MN_ROW(kss_extended,16,end))return false;uint64_t banksize=(bank&128)?8192:16384;return sxmn_span(v,16+extra+z,(bank&127)*banksize,end);}
bool sx_konami_kss_build(sxmn_view*v)
{
 return sxmn_kss(v);
}
#undef MN_ROW
