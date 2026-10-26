/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LHPAK_SFX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_lhpak_sfx_position_fields[]={
 SX_FIELD("archive_offset_longs","uint32",0,4,SX_NONE),
};
const sx_layout sxaend_lhpak_sfx_position={UINT32_C(0x60840004),"lhpak_sfx_position",sxaend_lhpak_sfx_position_fields,SX_COUNT(sxaend_lhpak_sfx_position_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhpak_sfx_member_fields[]={
 SX_FIELD("next_block_displacement","uint32",0,4,SX_OFFSET),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_number","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_block_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unknown_20","uint8[4]",20,4,SX_NONE),
 SX_FIELD("uncompressed_file_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown_28","uint8[14]",28,14,SX_NONE),
 SX_FIELD("name_longs","uint8",42,1,SX_NONE),
 SX_FIELD("comment_longs","uint8",43,1,SX_NONE),
};
const sx_layout sxaend_lhpak_sfx_member={UINT32_C(0x60840005),"lhpak_sfx_member",sxaend_lhpak_sfx_member_fields,SX_COUNT(sxaend_lhpak_sfx_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhpak_sfx_block_fields[]={
 SX_FIELD("next_block_displacement","uint32",0,4,SX_OFFSET),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_number","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_block_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxaend_lhpak_sfx_block={UINT32_C(0x60840006),"lhpak_sfx_block",sxaend_lhpak_sfx_block_fields,SX_COUNT(sxaend_lhpak_sfx_block_fields),SX_BE};
#define SXAEND_LIMIT 20000U
static bool sxaend_lhpak(sx_context*c){uint64_t p,x;if(!sxaend_word(c,20,4,true,&x)||x>(UINT64_MAX-128)/4||!sxaend_add(c,&sxaend_lhpak_sfx_position,20))return false;p=128+4*x;for(unsigned i=0;i<SXAEND_LIMIT;i++){uint8_t h[44];if(!sxaend_read(c,p,h,44))return false;uint64_t total=sxaend_uint(h+24,4,true),done=0,hs=44+4*(h[42]+h[43]),header=p;if(!sxaend_span(c,p,hs)||!sxaend_add(c,&sxaend_lhpak_sfx_member,p)||!sxaend_name(c,p+44,4*h[42])||!sxaend_text(c,&sxaend_archiveend_comment,p+44+4*h[42],4*h[43],false))return false;for(unsigned j=0;j<SXAEND_LIMIT;j++){uint8_t b[20];if(!sxaend_read(c,header,b,20))return false;uint64_t step=sxaend_uint(b,4,true),packed=sxaend_uint(b+4,2,true),plain=sxaend_uint(b+8,4,true);if(!plain||done>total||plain>total-done||!sxaend_span(c,header+hs,packed))return false;done+=plain;uint64_t next=header+hs+packed;if(step){if(step<hs||packed>step-hs||!sxaend_span(c,header,step))return false;next=header+step;}if(done==total){if(!step)return true;p=next;break;}if(!step||!sxaend_add(c,&sxaend_lhpak_sfx_block,next))return false;header=next;hs=20;if(j+1==SXAEND_LIMIT)return true;}}return true;}
bool sx_lhpak_sfx_build(sx_context*c)
{
 return sxaend_lhpak(c);
}
