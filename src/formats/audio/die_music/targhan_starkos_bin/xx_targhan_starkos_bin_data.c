/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Julien 'Targhan' Nevo's STarKos module (.BIN) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_starkos_bin(sx_context*c){
 if(!sxchip_span(c,0,137)||!sxchip_eq(c,128,"SK10",4))return false;
 return SXCHIP_ADD(c,chip_amsdos_header,0)&&SXCHIP_ADD(c,chip_starkos_binary_header,128);
}
bool sx_targhan_starkos_bin_build(sx_context*c)
{
 return sxchip_starkos_bin(c);
}
