/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * X68000 DIM floppy image data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_x68000_dim_header_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("track_present","uint8[170]",1,170,SX_NONE),
    SX_FIELD("signature","char[11]",171,11,SX_SIGNATURE),
    SX_FIELD("producer_metadata","byte[73]",182,73,SX_NONE),
    SX_FIELD("overtrack_flag","uint8",255,1,SX_FLAGS),
};
const sx_layout sxdleg_x68000_dim_header = {0x60750004U,"x68000_dim_header",sxdleg_x68000_dim_header_fields,SX_COUNT(sxdleg_x68000_dim_header_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_xdim(sx_context*c){uint8_t h[256];return sxdleg_read(c,0,h,256)&&!xx_rt_memcmp(h+171,"DIFC HEADER",11)&&SXDLEG_ADD(c,x68000_dim_header,0);}
#undef SXDLEG_ADD
bool sx_x68000_dim_build(sx_context*c)
{
 return sxdleg_xdim(c);
}
