/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cloop / geom_uzip data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_cloop_header_fields[] = {
    SX_FIELD("preamble","char[128]",0,128,SX_NONE),
    SX_FIELD("block_size","uint32",128,4,SX_SIZE),
    SX_FIELD("block_count","uint32",132,4,SX_COUNT_PROP),
};
const sx_layout sx_dm_cloop_header = {0x6029002dU,"cloop_header",sx_dm_cloop_header_fields,SX_COUNT(sx_dm_cloop_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_cloop_block_offset_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sx_dm_cloop_block_offset = {0x6029002eU,"cloop_block_offset",sx_dm_cloop_block_offset_fields,SX_COUNT(sx_dm_cloop_block_offset_fields),SX_BE};
static bool sx_dm_cloop(sx_context*c){uint8_t h[136];if(!sx_dm_read(c,0,h,136)||!sx_dm_add(c,&sx_dm_cloop_header,0,136))return false;uint64_t n=(uint64_t)sx_dm_u32(h,132,true)+1;return !sx_dm_span(c,136,n*8)||sx_dm_table(c,&sx_dm_cloop_block_offset,136,8,n);}
bool sx_cloop_build(sx_context*c)
{
 return sx_dm_cloop(c);
}
