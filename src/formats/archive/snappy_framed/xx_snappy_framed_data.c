/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * snappy framed data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_snappy_crc_fields[] = {
    SX_FIELD("masked_crc32c", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_p_snappy_crc = { UINT32_C(0x60070040), "snappy_crc", sx_p_snappy_crc_fields, SX_COUNT(sx_p_snappy_crc_fields), SX_LE };
static bool sx_p_snappy(sx_context *c)
{
    int64_t off=0;bool first=true;while(off<c->size){uint8_t type,b[3];if(!sx_p_byte(c,off,&type)||!sx_read(c,off+1,b,3))return false;uint32_t n=b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16;if(!sx_add(c,&sx_p_snappy_chunk,off,4)||!sx_p_span(c,off+4,n)||(first&&type!=255))return false;off+=4;if(type==255){if(n!=6||!sx_p_sig(c,off,"sNaPpY",6))return false;}else if(type<=1){if(n<4||!sx_add(c,&sx_p_snappy_crc,off,4))return false;}else if(type<128)return false;off+=n;first=false;}return !first;
}
bool sx_snappy_framed_build(sx_context*c)
{
    return sx_p_snappy(c);
}
