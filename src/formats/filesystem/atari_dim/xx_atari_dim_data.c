/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * atari dim data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_atari_dim_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint8",2,1,SX_RESERVED),
    SX_FIELD("used_sectors_only","uint8",3,1,SX_FLAGS),
    SX_FIELD("reserved1","uint16",4,2,SX_RESERVED),
    SX_FIELD("sides_minus_one","uint8",6,1,SX_NONE),
    SX_FIELD("reserved2","uint8",7,1,SX_RESERVED),
    SX_FIELD("sectors_per_track","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint8",9,1,SX_RESERVED),
    SX_FIELD("first_track","uint8",10,1,SX_NONE),
    SX_FIELD("reserved4","uint8",11,1,SX_RESERVED),
    SX_FIELD("last_track","uint8",12,1,SX_NONE),
    SX_FIELD("density","uint8",13,1,SX_ID),
    SX_FIELD("sector_size","uint16",14,2,SX_SIZE),
    SX_FIELD("opaque_extension","byte[16]",16,16,SX_NONE),
};
const sx_layout sxdleg_atari_dim_header = {0x60750012U,"atari_dim_header",sxdleg_atari_dim_header_fields,SX_COUNT(sxdleg_atari_dim_header_fields),SX_BE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_dim(sx_context*c){uint8_t h[32];return sxdleg_read(c,0,h,32)&&sxdleg16(h,1)==0x4242&&SXDLEG_ADD(c,atari_dim_header,0);}
#undef SXDLEG_ADD
bool sx_atari_dim_build(sx_context*c)
{
 return sxdleg_dim(c);
}
