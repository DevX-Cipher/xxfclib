/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FDX68_FDX data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_fdx68_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("revision","uint8",3,1,SX_ID),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
    SX_FIELD("padding","byte[4]",64,4,SX_RESERVED),
    SX_FIELD("type","int32",68,4,SX_ID),
    SX_FIELD("cylinders","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("heads","int32",76,4,SX_COUNT_PROP),
    SX_FIELD("transfer_rate","int32",80,4,SX_NONE),
    SX_FIELD("rpm","int32",84,4,SX_NONE),
    SX_FIELD("write_protected","int32",88,4,SX_FLAGS),
    SX_FIELD("options","uint32",92,4,SX_FLAGS),
    SX_FIELD("unused","uint32",96,4,SX_RESERVED),
    SX_FIELD("track_block_size","int32",100,4,SX_SIZE),
    SX_FIELD("reserved","byte[152]",104,152,SX_RESERVED),
};
const sx_layout sxst_fdx68_header = {0x60370038U,"fdx68_header",sxst_fdx68_header_fields,SX_COUNT(sxst_fdx68_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_fdx68_track_fields[] = {
    SX_FIELD("cylinder","int32",0,4,SX_NONE),
    SX_FIELD("head","int32",4,4,SX_NONE),
    SX_FIELD("index_bit_position","int32",8,4,SX_NONE),
    SX_FIELD("bit_count","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxst_fdx68_track = {0x60370039U,"fdx68_track",sxst_fdx68_track_fields,SX_COUNT(sxst_fdx68_track_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_fdx(sx_context*c){uint8_t h[104];if(!sxst_read(c,0,h,104)||!SXST_ADD(c,fdx68_header,0))return false;uint64_t cyl=sxst32(h+72),heads=sxst32(h+76),block=sxst32(h+100);if(!cyl||cyl>256||!heads||heads>2||block<=16||block>1048576)return true;for(uint64_t i=0;i<cyl*heads;i++){uint64_t p=256+i*block;if(!sxst_span(c,p,block)||!SXST_ADD(c,fdx68_track,p))break;}return true;}
bool sx_fdx68_fdx_build(sx_context*c)
{
 return sxst_fdx(c);
}
#undef SXST_ADD
