/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bethesda_bsa data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_bsa_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("folders_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("archive_flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("folder_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("file_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("folder_names_size","uint32",24,4,SX_SIZE),
 SX_FIELD("file_names_size","uint32",28,4,SX_SIZE),
 SX_FIELD("file_flags","uint32",32,4,SX_FLAGS),
};
const sx_layout sxgm_bsa_header = {UINT32_C(0x6027003b),"bsa_header",sxgm_bsa_header_fields,SX_COUNT(sxgm_bsa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_folder_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("block_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxgm_bsa_folder = {UINT32_C(0x6027003c),"bsa_folder",sxgm_bsa_folder_fields,SX_COUNT(sxgm_bsa_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_folder105_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown12","uint32",12,4,SX_NONE),
 SX_FIELD("block_offset","uint64",16,8,SX_OFFSET),
};
const sx_layout sxgm_bsa_folder105 = {UINT32_C(0x6027003d),"bsa_folder105",sxgm_bsa_folder105_fields,SX_COUNT(sxgm_bsa_folder105_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_file_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("size_flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxgm_bsa_file = {UINT32_C(0x6027003e),"bsa_file",sxgm_bsa_file_fields,SX_COUNT(sxgm_bsa_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_game_name_length8_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxgm_game_name_length8 = {UINT32_C(0x6027003f),"game_name_length8",sxgm_game_name_length8_fields,SX_COUNT(sxgm_game_name_length8_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_bsa(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,36)||!sxgm_add(c,&sxgm_bsa_header,0))return false;unsigned v=sxgm32(b+4,false),stride=v==105?24:16;uint64_t table=sxgm32(b+8,false),flags=sxgm32(b+12,false),n=sxgm32(b+16,false);if((v<103||v>105)||n>SXGM_LIMIT||!sxgm_span(c,table,n*stride))return true;if(!sxgm_table(c,v==105?&sxgm_bsa_folder105:&sxgm_bsa_folder,table,n))return false;uint64_t p=table+n*stride;
 for(uint64_t i=0;i<n&&c->count<SXGM_LIMIT;i++){uint64_t files;if(!sxgm_word(c,table+i*stride+8,4,false,&files)||files>SXGM_LIMIT)break;if(flags&1){uint64_t z;if(!sxgm_word(c,p,1,false,&z)||!sxgm_span(c,p+1,z))break;if(!sxgm_add(c,&sxgm_game_name_length8,p))return false;p+=1+z;}if(!sxgm_span(c,p,files*16))break;if(!sxgm_table(c,&sxgm_bsa_file,p,files))return false;
 if(v>=104&&(flags&0x100)){for(uint64_t j=0;j<files&&c->count<SXGM_LIMIT;j++){uint8_t e[16];if(!sxgm_read(c,p+j*16,e,16))break;uint64_t at=sxgm32(e+12,false),sz=sxgm32(e+8,false)&0x3fffffffU,z;if(sz&&sxgm_word(c,at,1,false,&z)&&z<sz&&sxgm_span(c,at,sz)&&!sxgm_add(c,&sxgm_game_name_length8,at))return false;}}p+=files*16;}return true;}
bool sx_bethesda_bsa_build(sx_context*c)
{
 return sxgm_bsa(c);
}
