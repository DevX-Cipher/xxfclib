/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Cfd data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_cfd_header_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_NONE),
    SX_FIELD("reserved1","uint16",4,2,SX_NONE),
    SX_FIELD("reserved2","uint8",6,1,SX_NONE),
    SX_FIELD("sector_size","uint16",7,2,SX_SIZE),
    SX_FIELD("unknown0","byte[3]",9,3,SX_NONE),
    SX_FIELD("format_marker","uint8",12,1,SX_ID),
    SX_FIELD("unknown1","byte[2]",13,2,SX_NONE),
    SX_FIELD("total_sectors","uint16",15,2,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[5]",17,5,SX_NONE),
    SX_FIELD("head_count","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint16",24,2,SX_NONE),
    SX_FIELD("flags","uint16",26,2,SX_FLAGS),
    SX_FIELD("unknown3","byte[4]",28,4,SX_NONE),
};
const sx_layout sxdn_cfd_header = {0x60780013U,"cfd_header",sxdn_cfd_header_fields,SX_COUNT(sxdn_cfd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cfd_block_fields[] = {
    SX_FIELD("total_block_size","uint16",0,2,SX_SIZE),
    SX_FIELD("index_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxdn_cfd_block = {0x60780014U,"cfd_block",sxdn_cfd_block_fields,SX_COUNT(sxdn_cfd_block_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cfd_repeat_fields[] = {
    SX_FIELD("last_literal_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("repeat_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxdn_cfd_repeat = {0x60780015U,"cfd_repeat",sxdn_cfd_repeat_fields,SX_COUNT(sxdn_cfd_repeat_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)
static bool sxdn_cfd(sx_context*c){uint8_t h[32];if(!sxdn_read(c,0,h,32)||!SXDN_ADD(c,cfd_header,0))return false;if(sxdn16(h+26,0)&0x800)return true;for(uint64_t p=32;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,4))break;uint64_t z=sxdn16(h,0),n=sxdn16(h+2,0);if(z<4||n<2||n>z-2||(n-2)%4||!sxdn_span(c,p,z))break;if(!SXDN_ADD(c,cfd_block,p)||!SXDN_TABLE(c,cfd_repeat,p+4,(n-2)/4))return false;p+=z;}return true;}
bool sx_cfd_build(sx_context*c)
{
 return sxdn_cfd(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
#undef SXDN_TABLE
