/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFX RSFX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_rsfx_rar_signature_fields[]={
 SX_FIELD("signature","uint8[7]",0,7,SX_SIGNATURE),
};
const sx_layout sxaend_rsfx_rar_signature={UINT32_C(0x60840046),"rsfx_rar_signature",sxaend_rsfx_rar_signature_fields,SX_COUNT(sxaend_rsfx_rar_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_block_fields[]={
 SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("block_type","uint8",2,1,SX_ID),
 SX_FIELD("flags","uint16",3,2,SX_FLAGS),
 SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
const sx_layout sxaend_rsfx_rar_block={UINT32_C(0x60840047),"rsfx_rar_block",sxaend_rsfx_rar_block_fields,SX_COUNT(sxaend_rsfx_rar_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_main_fields[]={
 SX_FIELD("reserved_low","uint16",0,2,SX_RESERVED),
 SX_FIELD("reserved_high","uint32",2,4,SX_RESERVED),
};
const sx_layout sxaend_rsfx_rar_main={UINT32_C(0x60840048),"rsfx_rar_main",sxaend_rsfx_rar_main_fields,SX_COUNT(sxaend_rsfx_rar_main_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_file_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("host_os","uint8",8,1,SX_ID),
 SX_FIELD("file_crc32","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("dos_timestamp","uint32",13,4,SX_NONE),
 SX_FIELD("unpack_version","uint8",17,1,SX_NONE),
 SX_FIELD("method","uint8",18,1,SX_ID),
 SX_FIELD("name_size","uint16",19,2,SX_SIZE),
 SX_FIELD("attributes","uint32",21,4,SX_FLAGS),
};
const sx_layout sxaend_rsfx_rar_file={UINT32_C(0x60840049),"rsfx_rar_file",sxaend_rsfx_rar_file_fields,SX_COUNT(sxaend_rsfx_rar_file_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_service_size_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxaend_rsfx_rar_service_size={UINT32_C(0x6084004a),"rsfx_rar_service_size",sxaend_rsfx_rar_service_size_fields,SX_COUNT(sxaend_rsfx_rar_service_size_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_rsfx(sx_context*c){uint64_t lx,p,cap=(uint64_t)c->size<1048576?(uint64_t)c->size:1048576;uint8_t h[32];if(!sxaend_word(c,60,4,false,&lx)||lx<64||lx+2>cap||!sxaend_read(c,lx,h,2)||xx_rt_memcmp(h,"LX",2))return false;for(p=lx+2;p+7<=cap;p++){if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,7))return false;if(!xx_rt_memcmp(h,"Rar!\032\7\0",7))break;}if(p+7>cap||!sxaend_add(c,&sxaend_rsfx_rar_signature,p))return false;p+=7;for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){if(!sxaend_read(c,p,h,7))return false;uint64_t flags=sxaend_uint(h+3,2,false),z=sxaend_uint(h+5,2,false),packed=0;if(z<7||!sxaend_span(c,p,z)||!sxaend_add(c,&sxaend_rsfx_rar_block,p))return false;if(flags&0x8000){if(z<11||!sxaend_word(c,p+7,4,false,&packed))return false;}if(h[2]==0x73){if(z<13||!sxaend_add(c,&sxaend_rsfx_rar_main,p+7))return false;}else if(h[2]==0x74){uint64_t names;if(z<32||!sxaend_word(c,p+26,2,false,&names)||names>z-32||!sxaend_add(c,&sxaend_rsfx_rar_file,p+7)||!sxaend_name(c,p+32,names))return false;}else if((flags&0x8000)&&!sxaend_add(c,&sxaend_rsfx_rar_service_size,p+7))return false;if(!sxaend_span(c,p+z,packed))return false;p+=z+packed;}return true;}
bool sx_sfx_rsfx_build(sx_context*c)
{
 return sxaend_rsfx(c);
}
