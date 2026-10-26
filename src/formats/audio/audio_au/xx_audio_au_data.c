/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_AU data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sx_c_au(sx_context *c)
{
    uint8_t h[24];uint32_t off,n;
    if(!sx_read(c,0,h,24)||xx_rt_memcmp(h,".snd",4))return false;
    off=xx_data_get_u32(h+4,4,0,true);n=xx_data_get_u32(h+8,4,0,true);
    if(off<24||off>c->size||(n!=UINT32_MAX&&!sx_c_bounds(c,off,n))||!sx_add(c,&sx_c_au_header,0,24)||!sx_raw(c,24,off-24))return false;
    return sx_raw(c,off,c->size-off);
}
bool sx_audio_au_build(sx_context*c)
{
    return sx_c_au(c);
}
