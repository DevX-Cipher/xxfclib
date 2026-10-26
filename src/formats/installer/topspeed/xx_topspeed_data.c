/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TOPSPEED data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_topspeed_block_fields[] = {
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("compressed_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxao_topspeed_block = {UINT32_C(0x6070000a),"topspeed_block",sxao_topspeed_block_fields,SX_COUNT(sxao_topspeed_block_fields),SX_LE};
static bool sxao_topspeed(sx_context*c){uint64_t p=0;while(sxao_span(c,p,6)){uint8_t h[6];if(!sxao_read(c,p,h,6)||!sxao_add(c,&sxao_topspeed_block,p))return false;uint64_t a=sxao_uint(h+2,2,false),b=sxao_uint(h+4,2,false),z=a<b?a:b;p+=6;if(!sxao_span(c,p,z))return true;p+=z;}return true;}
bool sx_topspeed_build(sx_context*c)
{
 return sxao_topspeed(c);
}
