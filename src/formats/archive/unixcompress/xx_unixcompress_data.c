/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UNIX COMPRESS data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_unixcompress_build(sx_context*c)
{
    uint8_t b[16];return sx_read(c,0,b,3)&&b[0]==0x1f&&b[1]==0x9d&&(b[2]&31)>=9&&(b[2]&31)<=16&&!(b[2]&0x60)&&sx_add(c,&sx_p_unix_compress_header,0,3);
}
