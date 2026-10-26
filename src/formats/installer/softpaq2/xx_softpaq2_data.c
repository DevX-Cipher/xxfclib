/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SOFTPAQ2 data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_softpaq2_locator_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown1","uint8[8]",8,8,SX_NONE),
 SX_FIELD("self_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("directory_offset","int32",20,4,SX_OFFSET),
 SX_FIELD("split_offset","int32",24,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8[9]",28,9,SX_NONE),
};
const sx_layout sxao_softpaq2_locator = {UINT32_C(0x6070003c),"softpaq2_locator",sxao_softpaq2_locator_fields,SX_COUNT(sxao_softpaq2_locator_fields),SX_LE};
static const xx_data_struct_field_desc sxao_softpaq2_stored_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("zero1","uint8",8,1,SX_NONE),
 SX_FIELD("extension","char[4]",9,4,SX_NONE),
 SX_FIELD("zero2","uint8",13,1,SX_NONE),
 SX_FIELD("payload_size","int32",14,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",18,4,SX_OFFSET),
 SX_FIELD("published","uint8",22,1,SX_NONE),
};
const sx_layout sxao_softpaq2_stored = {UINT32_C(0x6070003d),"softpaq2_stored",sxao_softpaq2_stored_fields,SX_COUNT(sxao_softpaq2_stored_fields),SX_LE};
static const xx_data_struct_field_desc sxao_softpaq2_compressed_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("zero1","uint8",8,1,SX_NONE),
 SX_FIELD("extension","char[4]",9,4,SX_NONE),
 SX_FIELD("zero2","uint8",13,1,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("dos_date","uint16",18,2,SX_NONE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("attributes","uint16",32,2,SX_FLAGS),
 SX_FIELD("payload_offset","int32",34,4,SX_OFFSET),
};
const sx_layout sxao_softpaq2_compressed = {UINT32_C(0x6070003e),"softpaq2_compressed",sxao_softpaq2_compressed_fields,SX_COUNT(sxao_softpaq2_compressed_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_softpaq(sx_context*c){uint64_t size=(uint64_t)c->size;uint8_t h[37];uint8_t block[4096];for(uint64_t base=0;size>=37&&base<=size-37;){size_t amount=(size_t)((size-36-base)>sizeof(block)?sizeof(block):(size-36-base));if(xx_pd_is_stopped(c->pd)||!sxao_read(c,base,block,amount))return false;for(size_t i=0;i<amount;i++){uint64_t p=base+i;if(block[i]!='[')continue;if(!sxao_read(c,p,h,37)||xx_rt_memcmp(h,"[FIT]\0\1\0",8))continue;uint64_t self=sxao_uint(h+16,4,false),dir=sxao_uint(h+20,4,false),split=sxao_uint(h+24,4,false);if(self!=p||dir>INT32_MAX||split>INT32_MAX||dir>split||split>size||(split-dir)%23||(size-split)%38)continue;if(!sxao_add(c,&sxao_softpaq2_locator,p)||!sxao_table(c,&sxao_softpaq2_stored,dir,23,(split-dir)/23)||!sxao_table(c,&sxao_softpaq2_compressed,split,38,(size-split)/38))return false;for(uint64_t q=split;q+38<=size&&c->count<SXAO_LIMIT;q+=38){uint64_t method,off,z;if(!sxao_word(c,q+14,2,false,&method)||!sxao_word(c,q+34,4,false,&off)||!sxao_word(c,q+28,4,false,&z))return false;if(method==6&&sxao_span(c,off,z)&&!sxao_dcl(c,off,z))return false;}return true;}base+=amount;}return false;}
bool sx_softpaq2_build(sx_context*c)
{
 return sxao_softpaq(c);
}
