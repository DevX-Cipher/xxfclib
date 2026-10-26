/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XAR data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_xar_build(sx_context*c)
{
    uint64_t length;
    uint16_t hs,v;return sx_p_sig(c,0,"xar!",4)&&sx_u16(c,4,true,&hs)&&hs>=28&&sx_u16(c,6,true,&v)&&v<=1&&hs<=1024&&sx_u64(c,8,true,&length)&&sx_p_span(c,hs,length)&&sx_add(c,&sx_p_xar_header,0,28);
}
