/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BOCHS_GROWING data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_bochs_growing_v1_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("type","char[16]",32,16,SX_ID),
    SX_FIELD("subtype","char[16]",48,16,SX_ID),
    SX_FIELD("version","uint32",64,4,SX_NONE),
    SX_FIELD("header_size","uint32",68,4,SX_SIZE),
    SX_FIELD("catalog_count","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint32",76,4,SX_SIZE),
    SX_FIELD("extent_size","uint32",80,4,SX_SIZE),
    SX_FIELD("disk_size","uint64",84,8,SX_SIZE),
    SX_FIELD("reserved","byte[420]",92,420,SX_RESERVED),
};
const sx_layout sxsl_bochs_growing_v1 = {0x60330033U,"bochs_growing_v1",sxsl_bochs_growing_v1_fields,SX_COUNT(sxsl_bochs_growing_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_bochs_growing_v2_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("type","char[16]",32,16,SX_ID),
    SX_FIELD("subtype","char[16]",48,16,SX_ID),
    SX_FIELD("version","uint32",64,4,SX_NONE),
    SX_FIELD("header_size","uint32",68,4,SX_SIZE),
    SX_FIELD("catalog_count","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint32",76,4,SX_SIZE),
    SX_FIELD("extent_size","uint32",80,4,SX_SIZE),
    SX_FIELD("reserved_timestamp","uint32",84,4,SX_NONE),
    SX_FIELD("disk_size","uint64",88,8,SX_SIZE),
    SX_FIELD("reserved","byte[416]",96,416,SX_RESERVED),
};
const sx_layout sxsl_bochs_growing_v2 = {0x60330034U,"bochs_growing_v2",sxsl_bochs_growing_v2_fields,SX_COUNT(sxsl_bochs_growing_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_bochs_catalog_entry_fields[] = {
    SX_FIELD("extent_index","uint32",0,4,SX_NONE),
};
const sx_layout sxsl_bochs_catalog_entry = {0x60330035U,"bochs_catalog_entry",sxsl_bochs_catalog_entry_fields,SX_COUNT(sxsl_bochs_catalog_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_bochs_bitmap_byte_fields[] = {
    SX_FIELD("allocated_sector_bits","uint8",0,1,SX_FLAGS),
};
const sx_layout sxsl_bochs_bitmap_byte = {0x60330036U,"bochs_bitmap_byte",sxsl_bochs_bitmap_byte_fields,SX_COUNT(sxsl_bochs_bitmap_byte_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_bochs(sx_context*c){uint8_t h[96];if(!sxsl_read(c,0,h,96))return false;uint32_t v=sxsl32(h+64);if(v!=0x10000&&v!=0x20000)return false;if(!sxsl_put(c,v==0x10000?&sxsl_bochs_growing_v1:&sxsl_bochs_growing_v2,0,1))return false;uint64_t n=sxsl32(h+72),bitmap=sxsl32(h+76),extent=sxsl32(h+80);if(n>SXSL_ROWS||!bitmap||bitmap>4096||extent!=bitmap*4096||!sxsl_span(c,512,n*4)||!SXSL_TABLE(c,bochs_catalog_entry,512,n))return true;uint64_t base=512+n*4,slot=((bitmap+511)/512)*512+extent;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t index;if(!sxsl_word(c,512+4*i,4,false,&index))return false;if(index==UINT32_MAX)continue;if(index>((uint64_t)c->size-base)/slot)continue;uint64_t p=base+index*slot;if(sxsl_span(c,p,bitmap)&&!SXSL_TABLE(c,bochs_bitmap_byte,p,bitmap))return false;}return true;}
bool sx_bochs_growing_build(sx_context*c)
{
bool ok=false;
ok=sxsl_bochs(c);
return ok&&sxsl_finish(c);
}
