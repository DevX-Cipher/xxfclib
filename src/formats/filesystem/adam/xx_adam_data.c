/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * adam data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_adam_volume_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("directory_blocks_and_protection","uint8",12,1,SX_FLAGS),
    SX_FIELD("directory_check","uint32",13,4,SX_SIGNATURE),
    SX_FIELD("volume_blocks","uint32",17,4,SX_COUNT_PROP),
    SX_FIELD("unknown_15","byte[2]",21,2,SX_NONE),
    SX_FIELD("year_bcd","uint8",23,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",24,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",25,1,SX_NONE),
};
const sx_layout sxst_adam_volume = {0x60370012U,"adam_volume",sxst_adam_volume_fields,SX_COUNT(sxst_adam_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxst_adam_entry_fields[] = {
    SX_FIELD("name_and_type","char[12]",0,12,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_block","uint32",13,4,SX_NONE),
    SX_FIELD("allocated_blocks","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("used_blocks","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("last_block_used_bytes","uint16",21,2,SX_SIZE),
    SX_FIELD("year_bcd","uint8",23,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",24,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",25,1,SX_NONE),
};
const sx_layout sxst_adam_entry = {0x60370013U,"adam_entry",sxst_adam_entry_fields,SX_COUNT(sxst_adam_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxst_adam_entry_split_prefix_fields[] = {
    SX_FIELD("name_and_type","char[12]",0,12,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_block","uint32",13,4,SX_NONE),
    SX_FIELD("allocated_blocks_low","uint8",17,1,SX_NONE),
};
const sx_layout sxst_adam_entry_split_prefix = {0x60370014U,"adam_entry_split_prefix",sxst_adam_entry_split_prefix_fields,SX_COUNT(sxst_adam_entry_split_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxst_adam_entry_split_tail_fields[] = {
    SX_FIELD("allocated_blocks_high","uint8",0,1,SX_NONE),
    SX_FIELD("used_blocks","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("last_block_used_bytes","uint16",3,2,SX_SIZE),
    SX_FIELD("year_bcd","uint8",5,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",6,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",7,1,SX_NONE),
};
const sx_layout sxst_adam_entry_split_tail = {0x60370015U,"adam_entry_split_tail",sxst_adam_entry_split_tail_fields,SX_COUNT(sxst_adam_entry_split_tail_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_adam(sx_context*c){uint8_t b;if(!sxst_read(c,1036,&b,1)||!SXST_ADD(c,adam_volume,1024))return false;unsigned n=b&127;for(unsigned i=1;i<=n;i++){uint64_t p=(uint64_t)i*1024,q=((uint64_t)i*2^5)*512;if(!sxst_span(c,p,512)||!sxst_span(c,q,512))break;if(i==1){if(!SXST_TABLE(c,adam_entry,p+26,18))return false;}else if(!SXST_TABLE(c,adam_entry,p,19))return false;if(!SXST_ADD(c,adam_entry_split_prefix,p+494)||!SXST_ADD(c,adam_entry_split_tail,q)||!SXST_TABLE(c,adam_entry,q+8,19))return false;}return true;}
bool sx_adam_build(sx_context*c)
{
 return sxst_adam(c);
}
#undef SXST_ADD
#undef SXST_TABLE
