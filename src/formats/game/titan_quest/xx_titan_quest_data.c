/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TITAN_QUEST data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_titan_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("block_table_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_table_size","uint32",20,4,SX_SIZE),
 SX_FIELD("block_table_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("unknown","uint32",28,4,SX_NONE),
};
const sx_layout sxan_titan_header = {UINT32_C(0x60770034),"titan_header",sxan_titan_header_fields,SX_COUNT(sxan_titan_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_titan_block_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxan_titan_block = {UINT32_C(0x60770035),"titan_block",sxan_titan_block_fields,SX_COUNT(sxan_titan_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_titan_member_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_NONE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unknown","uint8[8]",20,8,SX_NONE),
 SX_FIELD("block_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("first_block_index","uint32",32,4,SX_NONE),
 SX_FIELD("name_size","uint32",36,4,SX_SIZE),
 SX_FIELD("name_offset","uint32",40,4,SX_OFFSET),
};
const sx_layout sxan_titan_member = {UINT32_C(0x60770036),"titan_member",sxan_titan_member_fields,SX_COUNT(sxan_titan_member_fields),SX_LE};
static bool sxan_titan(sx_context*c){uint64_t n,blocks,p,z,names,namesz,rows,off,len;if(!sxan_add(c,&sxan_titan_header,0)||!sxan_word(c,8,4,false,&n)||!sxan_word(c,12,4,false,&blocks)||!sxan_word(c,16,4,false,&z)||!sxan_word(c,20,4,false,&namesz)||!sxan_word(c,24,4,false,&p))return false;names=p+z;rows=names+namesz;if(!sxan_span(c,names,namesz)||!sxan_table(c,&sxan_titan_block,p,12,blocks)||!sxan_table(c,&sxan_titan_member,rows,44,n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,rows+44*i+36,4,false,&len)||!sxan_word(c,rows+44*i+40,4,false,&off)||off>=namesz||len>=namesz-off||!sxan_named(c,names+off,len+1))return false;}return true;}
bool sx_titan_quest_build(sx_context*c)
{
bool ok=false;
ok=sxan_titan(c);
(void)ok;return c->count&&sxan_finish(c);
}
