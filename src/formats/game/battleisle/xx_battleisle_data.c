/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * battleisle data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_battle_tct_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("unknown","bytes",6,2,SX_NONE),
};
const sx_layout sxgco_battle_tct={UINT32_C(0x60400013),"battle_tct",sxgco_battle_tct_fields,SX_COUNT(sxgco_battle_tct_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_battle(sxgco_view*v)
{uint64_t e=v->c->size,at;uint8_t h[4];if(!GC_ROW(offset32,0,e)||!sxgco_word(v,0,4,false,&at,e)||at>e||(e-at)%12)return false;if(sxgco_read(v,4,h,4,e)&&!xx_rt_memcmp(h,"TCT ",4)&&!GC_ROW(battle_tct,4,e))return false;return sxgco_table(v,&sxgco_battle_entry,at,(e-at)/12,e);}
bool sx_battleisle_build(sxgco_view*v)
{
 return sxgco_battle(v);
}
#undef GC_ROW
