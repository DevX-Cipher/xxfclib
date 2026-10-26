/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari ST module (.SND,.SNDH) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxportable_ice(sx_context*c)
{
    uint8_t h[12];uint64_t end=(uint64_t)c->size;
    if(!sxportable_read(c,0,h,12,end)||(xx_rt_memcmp(h,"Ice!",4)&&xx_rt_memcmp(h,"ICE!",4)))return false;
    uint32_t packed=xx_data_get_u32(h,12,4,true),unpacked=xx_data_get_u32(h,12,8,true);
    return packed>=12&&packed<=end&&unpacked&&sxportable_row(c,&sxportable_ice_music_header,0,12,end);
}
bool sx_atarist_sndh_build(sx_context*c)
{
    return sxportable_ice(c);
}
