/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IMP archives (Technelysium's IMP archiver) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_imp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[26]",12,26,SX_NONE),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
 SX_FIELD("header_crc16","uint16",40,2,SX_CHECKSUM),
};
const sx_layout sxafr_imp_header = {UINT32_C(0x60540015),"imp_header",sxafr_imp_header_fields,SX_COUNT(sxafr_imp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_imp_directory_block_fields[] = {
 SX_FIELD("signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("method_and_lengths","uint48",6,6,SX_FLAGS),
};
const sx_layout sxafr_imp_directory_block = {UINT32_C(0x60540016),"imp_directory_block",sxafr_imp_directory_block_fields,SX_COUNT(sxafr_imp_directory_block_fields),SX_LE};
#define SXAFR_LIMIT 20000U
static bool sxafr_imp(sx_context*c){uint64_t p,n;if(!sxafr_word(c,4,4,false,&p)||!sxafr_word(c,8,4,false,&n)||!sxafr_add(c,&sxafr_imp_header,0))return false;uint64_t decoded=0;for(unsigned i=0;n&&i<SXAFR_LIMIT;i++){uint8_t h[12];if(!sxafr_read(c,p,h,12)||xx_rt_memcmp(h,"IMPDE\0",6))return false;uint64_t bits=sxafr_uint(h+6,6,false),plain=(bits>>5)&0xfffff,z=(bits>>25)&0xfffff;if((bits&15)>1||plain>8192||!sxafr_add(c,&sxafr_imp_directory_block,p))return false;decoded+=plain;if(!z||decoded>=n*38)return true;if(z<6||!sxafr_span(c,p+6,z))return false;p+=6+z;}return true;}
bool sx_imp_build(sx_context*c)
{
 return sxafr_imp(c);
}
