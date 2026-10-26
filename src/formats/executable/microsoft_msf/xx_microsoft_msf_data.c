/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MICROSOFT_MSF data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_msf7_superblock_fields[] = {
 SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",32,4,SX_SIZE),
 SX_FIELD("free_block_map_block","uint32",36,4,SX_ID),
 SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32",44,4,SX_SIZE),
 SX_FIELD("reserved","uint32",48,4,SX_RESERVED),
 SX_FIELD("block_map_block","uint32",52,4,SX_ID),
};
const sx_layout sxexm_msf7_superblock = {UINT32_C(0x602b0007),"msf7_superblock",sxexm_msf7_superblock_fields,SX_COUNT(sxexm_msf7_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_directory_block_fields[] = {
 SX_FIELD("directory_block_index","uint32",0,4,SX_ID),
};
const sx_layout sxexm_msf7_directory_block = {UINT32_C(0x602b0008),"msf7_directory_block",sxexm_msf7_directory_block_fields,SX_COUNT(sxexm_msf7_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_count_fields[] = {
 SX_FIELD("stream_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxexm_msf7_stream_count = {UINT32_C(0x602b0009),"msf7_stream_count",sxexm_msf7_stream_count_fields,SX_COUNT(sxexm_msf7_stream_count_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_size_fields[] = {
 SX_FIELD("stream_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxexm_msf7_stream_size = {UINT32_C(0x602b000a),"msf7_stream_size",sxexm_msf7_stream_size_fields,SX_COUNT(sxexm_msf7_stream_size_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_block_fields[] = {
 SX_FIELD("stream_block_index","uint32",0,4,SX_ID),
};
const sx_layout sxexm_msf7_stream_block = {UINT32_C(0x602b000b),"msf7_stream_block",sxexm_msf7_stream_block_fields,SX_COUNT(sxexm_msf7_stream_block_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_msf_word(sx_context *c,uint64_t map,uint64_t bs,uint64_t bytes,uint64_t logical,const sx_layout *l,uint64_t *value){uint64_t id;if(logical>bytes||bytes-logical<4||logical%4||!sxexm_word(c,map+(logical/bs)*4,4,false,&id)||id>(uint64_t)c->size/bs)return false;uint64_t p=id*bs+logical%bs;return sxexm_word(c,p,4,false,value)&&sxexm_add(c,l,p);}
static bool sxexm_msf(sx_context *c){uint8_t b[56];if(!sxexm_read(c,0,b,56)||!sxexm_add(c,&sxexm_msf7_superblock,0))return false;uint64_t bs=sxexm32(b+32,false),dn=sxexm32(b+44,false),map=sxexm32(b+52,false);if((bs!=512&&bs!=1024&&bs!=2048&&bs!=4096)||dn<4||dn>4194304||map>(uint64_t)c->size/bs)return true;map*=bs;uint64_t pages=(dn+bs-1)/bs;if(pages*4>bs||!sxexm_span(c,map,pages*4)||!sxexm_table(c,&sxexm_msf7_directory_block,map,pages))return true;uint64_t count;if(!sxexm_msf_word(c,map,bs,dn,0,&sxexm_msf7_stream_count,&count)||count>4093||count*4+4>dn)return true;uint64_t at=4+count*4;
 for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){uint64_t z;if(!sxexm_msf_word(c,map,bs,dn,4+i*4,&sxexm_msf7_stream_size,&z))break;if(z==UINT32_MAX)continue;uint64_t n=(z+bs-1)/bs;if(n>(dn-at)/4)break;for(uint64_t j=0;j<n&&c->count<SXEXM_LIMIT;j++){uint64_t id;if(!sxexm_msf_word(c,map,bs,dn,at,&sxexm_msf7_stream_block,&id))return true;at+=4;}if(c->count>=SXEXM_LIMIT)break;}return true;}
bool sx_microsoft_msf_build(sx_context*c)
{
bool ok=false;
ok=sxexm_msf(c);
return ok&&sxexm_finish(c);
}
