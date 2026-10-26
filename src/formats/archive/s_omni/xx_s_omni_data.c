/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * S_OMNI data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_omni_mode_fields[]={
 SX_FIELD("mode","uint16",0,2,SX_ID),
};
const sx_layout sxaend_omni_mode={UINT32_C(0x60840009),"omni_mode",sxaend_omni_mode_fields,SX_COUNT(sxaend_omni_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_comment_size_fields[]={
 SX_FIELD("comment_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxaend_omni_comment_size={UINT32_C(0x6084000a),"omni_comment_size",sxaend_omni_comment_size_fields,SX_COUNT(sxaend_omni_comment_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_name_size_fields[]={
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxaend_omni_name_size={UINT32_C(0x6084000b),"omni_name_size",sxaend_omni_name_size_fields,SX_COUNT(sxaend_omni_name_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_data_size_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxaend_omni_data_size={UINT32_C(0x6084000c),"omni_data_size",sxaend_omni_data_size_fields,SX_COUNT(sxaend_omni_data_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_member_tail_fields[]={
 SX_FIELD("unknown_tail","uint8[2]",0,2,SX_NONE),
};
const sx_layout sxaend_omni_member_tail={UINT32_C(0x6084000d),"omni_member_tail",sxaend_omni_member_tail_fields,SX_COUNT(sxaend_omni_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_omni_lh_block_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("packed_raw_crc32","uint32",10,4,SX_CHECKSUM),
};
const sx_layout sxaend_omni_lh_block={UINT32_C(0x6084000e),"omni_lh_block",sxaend_omni_lh_block_fields,SX_COUNT(sxaend_omni_lh_block_fields),SX_BE};
#define SXAEND_LIMIT 20000U
static bool sxaend_omni(sx_context*c){uint64_t tag,p,mode,z;if(!sxaend_word(c,0x208,4,true,&tag))return false;p=tag==0x51cdfffc?0x7a8:tag==0x76002c7a?0x744:0;if(!p||!sxaend_word(c,p,2,true,&mode)||!sxaend_add(c,&sxaend_omni_mode,p))return false;p+=2;if(mode==1){if(!sxaend_word(c,p,2,true,&z)||!sxaend_add(c,&sxaend_omni_comment_size,p)||!sxaend_span(c,p+2,z)||!sxaend_text(c,&sxaend_archiveend_comment,p+2,z,false))return false;p+=2+z;}for(unsigned i=0;i<SXAEND_LIMIT;i++){if(!sxaend_word(c,p,2,true,&z)||!sxaend_add(c,&sxaend_omni_name_size,p))return false;p+=2;if(!z)return true;if(!sxaend_span(c,p,z)||!sxaend_name(c,p,z))return false;p+=z;if(!sxaend_word(c,p,4,true,&z)||!sxaend_add(c,&sxaend_omni_data_size,p)||!sxaend_span(c,p+4,z+2))return false;p+=4;uint8_t h[14];if(z>=14&&sxaend_read(c,p,h,14)&&h[0]=='L'&&h[1]=='H'&&!h[2]&&!h[6]&&sxaend_uint(h+6,4,true)==z-14&&!sxaend_add(c,&sxaend_omni_lh_block,p))return false;p+=z;if(!sxaend_add(c,&sxaend_omni_member_tail,p))return false;p+=2;}return true;}
bool sx_s_omni_build(sx_context*c)
{
 return sxaend_omni(c);
}
