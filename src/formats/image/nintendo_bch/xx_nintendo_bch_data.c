/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NINTENDO_BCH data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_bch21_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("backward_compatibility","uint8",4,1,SX_ID),
    SX_FIELD("forward_compatibility","uint8",5,1,SX_ID),
    SX_FIELD("converter_version","uint16",6,2,SX_ID),
    SX_FIELD("contents_offset","int32",8,4,SX_OFFSET),
    SX_FIELD("strings_offset","int32",12,4,SX_OFFSET),
    SX_FIELD("commands_offset","int32",16,4,SX_OFFSET),
    SX_FIELD("raw_data_offset","int32",20,4,SX_OFFSET),
    SX_FIELD("raw_extra_offset","int32",24,4,SX_OFFSET),
    SX_FIELD("relocations_offset","int32",28,4,SX_OFFSET),
    SX_FIELD("contents_size","int32",32,4,SX_SIZE),
    SX_FIELD("strings_size","int32",36,4,SX_SIZE),
    SX_FIELD("commands_size","int32",40,4,SX_SIZE),
    SX_FIELD("raw_data_size","int32",44,4,SX_SIZE),
    SX_FIELD("raw_extra_size","int32",48,4,SX_SIZE),
    SX_FIELD("relocations_size","int32",52,4,SX_SIZE),
    SX_FIELD("uninitialized_data_size","int32",56,4,SX_SIZE),
    SX_FIELD("uninitialized_commands_size","int32",60,4,SX_SIZE),
    SX_FIELD("flags","uint8",64,1,SX_FLAGS),
    SX_FIELD("padding","uint8",65,1,SX_RESERVED),
    SX_FIELD("address_count","uint16",66,2,SX_COUNT_PROP),
};
const sx_layout sxmo_bch21_header = {UINT32_C(0x6021001b),"bch21_header",sxmo_bch21_header_fields,SX_COUNT(sxmo_bch21_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_bch_relocation_fields[] = {
    SX_FIELD("encoded_relocation","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmo_bch_relocation = {UINT32_C(0x6021001c),"bch_relocation",sxmo_bch_relocation_fields,SX_COUNT(sxmo_bch_relocation_fields),SX_LE};
static bool sxmo_bch(sx_context*c){uint8_t h[68];if(!sxmo_read(c,0,h,68)||xx_rt_memcmp(h,"BCH\0",4)||h[4]!=0x21||h[5]!=0x21||!sxmo_add(c,&sxmo_bch21_header,0))return false;uint64_t p=sxmo32(h+28,false),z=sxmo32(h+52,false);if(p>=68&&z%4==0&&z/4<=4096&&sxmo_span(c,p,z)&&!sxmo_table(c,&sxmo_bch_relocation,p,z/4))return false;return true;}
bool sx_nintendo_bch_build(sx_context*c)
{
bool ok=false;
ok=sxmo_bch(c);
return ok&&c->count>0&&sxmo_finish(c);
}
