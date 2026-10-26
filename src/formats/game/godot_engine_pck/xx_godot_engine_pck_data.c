/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * godot_engine_pck data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_godot_pck_v1_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("reserved","uint32[16]",20,64,SX_RESERVED),
};
const sx_layout sxgm_godot_pck_v1 = {UINT32_C(0x60270006),"godot_pck_v1",sxgm_godot_pck_v1_fields,SX_COUNT(sxgm_godot_pck_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v2_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("reserved","uint32[16]",32,64,SX_RESERVED),
};
const sx_layout sxgm_godot_pck_v2 = {UINT32_C(0x60270007),"godot_pck_v2",sxgm_godot_pck_v2_fields,SX_COUNT(sxgm_godot_pck_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v3_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("directory_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("reserved","uint32[16]",40,64,SX_RESERVED),
};
const sx_layout sxgm_godot_pck_v3 = {UINT32_C(0x60270008),"godot_pck_v3",sxgm_godot_pck_v3_fields,SX_COUNT(sxgm_godot_pck_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v4_salted_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("directory_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("salt","uint8[32]",40,32,SX_NONE),
 SX_FIELD("reserved","uint8[32]",72,32,SX_RESERVED),
};
const sx_layout sxgm_godot_pck_v4_salted = {UINT32_C(0x60270009),"godot_pck_v4_salted",sxgm_godot_pck_v4_salted_fields,SX_COUNT(sxgm_godot_pck_v4_salted_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_file_count_fields[] = {
 SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgm_godot_file_count = {UINT32_C(0x6027000a),"godot_file_count",sxgm_godot_file_count_fields,SX_COUNT(sxgm_godot_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_path_length_fields[] = {
 SX_FIELD("path_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxgm_godot_path_length = {UINT32_C(0x6027000b),"godot_path_length",sxgm_godot_path_length_fields,SX_COUNT(sxgm_godot_path_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_entry_v1_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("md5","uint8[16]",16,16,SX_CHECKSUM),
};
const sx_layout sxgm_godot_entry_v1 = {UINT32_C(0x6027000c),"godot_entry_v1",sxgm_godot_entry_v1_fields,SX_COUNT(sxgm_godot_entry_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_entry_v2_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("md5","uint8[16]",16,16,SX_CHECKSUM),
 SX_FIELD("flags","uint32",32,4,SX_FLAGS),
};
const sx_layout sxgm_godot_entry_v2 = {UINT32_C(0x6027000d),"godot_entry_v2",sxgm_godot_entry_v2_fields,SX_COUNT(sxgm_godot_entry_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_encrypted_block_fields[] = {
 SX_FIELD("md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("plain_size","uint64",16,8,SX_SIZE),
 SX_FIELD("iv","uint8[16]",24,16,SX_NONE),
};
const sx_layout sxgm_godot_encrypted_block = {UINT32_C(0x6027000e),"godot_encrypted_block",sxgm_godot_encrypted_block_fields,SX_COUNT(sxgm_godot_encrypted_block_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_trailer_fields[] = {
 SX_FIELD("pack_size","uint64",0,8,SX_SIZE),
 SX_FIELD("signature","char[4]",8,4,SX_SIGNATURE),
};
const sx_layout sxgm_godot_trailer = {UINT32_C(0x6027000f),"godot_trailer",sxgm_godot_trailer_fields,SX_COUNT(sxgm_godot_trailer_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_godot_locate(sx_context *c,uint64_t *pack,uint64_t *end){uint8_t b[64];*pack=0;*end=(uint64_t)c->size;if(!sxgm_read(c,0,b,4))return false;if(!xx_rt_memcmp(b,"GDPC",4))return true;
 if(*end>=100&&sxgm_read(c,*end-12,b,12)&&!xx_rt_memcmp(b+8,"GDPC",4)){uint64_t n=sxgm_uint(b,8,false);if(n>=88&&n<=*end-12&&sxgm_read(c,*end-12-n,b,4)&&!xx_rt_memcmp(b,"GDPC",4)){*pack=*end-12-n;*end-=12;return sxgm_add(c,&sxgm_godot_trailer,*end);}}
 if(!sxgm_read(c,0,b,64)||xx_rt_memcmp(b,"MZ",2))return false;uint64_t pe=sxgm32(b+60,false);if(pe>0x10000000||!sxgm_read(c,pe,b,24)||xx_rt_memcmp(b,"PE\0\0",4))return false;unsigned n=sxgm16(b+6,false);uint64_t p=pe+24+sxgm16(b+20,false);if(!n||n>96||!sxgm_span(c,p,(uint64_t)n*40))return false;
 for(unsigned i=0;i<n;i++){if(!sxgm_read(c,p+i*40,b,40))return false;if(xx_rt_memcmp(b,"pck\0\0\0\0\0",8))continue;uint64_t at=sxgm32(b+20,false),z=sxgm32(b+16,false);if(at>*end)continue;uint64_t limit=z>*end-at?*end:at+z;for(unsigned slack=0;slack<8&&limit-at>=88+slack;slack++){if(sxgm_read(c,at+slack,b,4)&&!xx_rt_memcmp(b,"GDPC",4)){*pack=at+slack;*end=limit;return true;}}}return false;}
static bool sxgm_godot(sx_context *c){uint8_t b[104];uint64_t pack,end;if(!sxgm_godot_locate(c,&pack,&end)||end-pack<20||!sxgm_read(c,pack,b,20))return false;uint32_t v=sxgm32(b+4,false),flags=0;unsigned h=v<=1?84:v==2?96:104;if(v>4||end-pack<h||!sxgm_read(c,pack,b,h))return false;if(v>=2)flags=sxgm32(b+20,false);const sx_layout *l=v<=1?&sxgm_godot_pck_v1:v==2?&sxgm_godot_pck_v2:v==4&&(flags&5)==5?&sxgm_godot_pck_v4_salted:&sxgm_godot_pck_v3;if(!sxgm_add(c,l,pack))return false;
 uint64_t rel=v>=3?sxgm_uint(b+32,8,false):h;if(rel>end-pack||end-pack-rel<4)return true;uint64_t p=pack+rel,n;if(!sxgm_word(c,p,4,false,&n)||!sxgm_add(c,&sxgm_godot_file_count,p))return false;p+=4;if(flags&1){if(end-p>=40&&!sxgm_add(c,&sxgm_godot_encrypted_block,p))return false;return true;}unsigned tail=v>=2?36:32;
 for(uint64_t i=0;i<n&&i<SXGM_LIMIT&&c->count<SXGM_LIMIT;i++){uint64_t z;if(end-p<4||!sxgm_word(c,p,4,false,&z)||!z||z>end-p-4||end-p-4-z<tail)break;if(!sxgm_add(c,&sxgm_godot_path_length,p)||!sxgm_add(c,v>=2?&sxgm_godot_entry_v2:&sxgm_godot_entry_v1,p+4+z))return false;p+=4+z+tail;}return true;}
bool sx_godot_engine_pck_build(sx_context*c)
{
 return sxgm_godot(c);
}
