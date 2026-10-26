/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WII_WAD data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_wad_header_fields[] = {
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","char[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("certificate_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crl_size","uint32",12,4,SX_SIZE),
 SX_FIELD("ticket_size","uint32",16,4,SX_SIZE),
 SX_FIELD("tmd_size","uint32",20,4,SX_SIZE),
 SX_FIELD("data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("footer_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxan_wad_header = {UINT32_C(0x6077004a),"wad_header",sxan_wad_header_fields,SX_COUNT(sxan_wad_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_rsa2048_fields[] = {
 SX_FIELD("signature_type","uint32",0,4,SX_NONE),
 SX_FIELD("signature","uint8[256]",4,256,SX_NONE),
 SX_FIELD("padding","uint8[60]",260,60,SX_NONE),
};
const sx_layout sxan_wad_rsa2048 = {UINT32_C(0x6077004b),"wad_rsa2048",sxan_wad_rsa2048_fields,SX_COUNT(sxan_wad_rsa2048_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_ticket_fields[] = {
 SX_FIELD("issuer","char[64]",0,64,SX_NONE),
 SX_FIELD("unknown","uint8[63]",64,63,SX_NONE),
 SX_FIELD("encrypted_title_key","uint8[16]",127,16,SX_NONE),
 SX_FIELD("reserved1","uint8",143,1,SX_NONE),
 SX_FIELD("ticket_id","uint64",144,8,SX_NONE),
 SX_FIELD("device_type","uint32",152,4,SX_NONE),
 SX_FIELD("title_id","uint64",156,8,SX_NONE),
 SX_FIELD("access_mask","uint16",164,2,SX_FLAGS),
 SX_FIELD("reserved2","uint8[60]",166,60,SX_NONE),
 SX_FIELD("content_index_mask","uint8[64]",226,64,SX_FLAGS),
 SX_FIELD("padding","uint16",290,2,SX_NONE),
};
const sx_layout sxan_wad_ticket = {UINT32_C(0x6077004c),"wad_ticket",sxan_wad_ticket_fields,SX_COUNT(sxan_wad_ticket_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_limit_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_NONE),
 SX_FIELD("value","uint32",4,4,SX_NONE),
};
const sx_layout sxan_wad_limit = {UINT32_C(0x6077004d),"wad_limit",sxan_wad_limit_fields,SX_COUNT(sxan_wad_limit_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_tmd_fields[] = {
 SX_FIELD("issuer","char[64]",0,64,SX_NONE),
 SX_FIELD("version","uint8",64,1,SX_NONE),
 SX_FIELD("ca_crl_version","uint8",65,1,SX_NONE),
 SX_FIELD("signer_crl_version","uint8",66,1,SX_NONE),
 SX_FIELD("vwii_title","uint8",67,1,SX_NONE),
 SX_FIELD("system_version","uint64",68,8,SX_NONE),
 SX_FIELD("title_id","uint64",76,8,SX_NONE),
 SX_FIELD("title_type","uint32",84,4,SX_FLAGS),
 SX_FIELD("group_id","uint16",88,2,SX_NONE),
 SX_FIELD("zero","uint16",90,2,SX_NONE),
 SX_FIELD("region","uint16",92,2,SX_NONE),
 SX_FIELD("ratings","uint8[16]",94,16,SX_NONE),
 SX_FIELD("reserved1","uint8[12]",110,12,SX_NONE),
 SX_FIELD("ipc_mask","uint8[12]",122,12,SX_FLAGS),
 SX_FIELD("reserved2","uint8[18]",134,18,SX_NONE),
 SX_FIELD("access_rights","uint32",152,4,SX_FLAGS),
 SX_FIELD("title_version","uint16",156,2,SX_NONE),
 SX_FIELD("content_count","uint16",158,2,SX_COUNT_PROP),
 SX_FIELD("boot_index","uint16",160,2,SX_NONE),
 SX_FIELD("padding","uint16",162,2,SX_NONE),
};
const sx_layout sxan_wad_tmd = {UINT32_C(0x6077004e),"wad_tmd",sxan_wad_tmd_fields,SX_COUNT(sxan_wad_tmd_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_content_fields[] = {
 SX_FIELD("content_id","uint32",0,4,SX_NONE),
 SX_FIELD("content_index","uint16",4,2,SX_NONE),
 SX_FIELD("type","uint16",6,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("sha1","uint8[20]",16,20,SX_CHECKSUM),
};
const sx_layout sxan_wad_content = {UINT32_C(0x6077004f),"wad_content",sxan_wad_content_fields,SX_COUNT(sxan_wad_content_fields),SX_BE};
static bool sxan_wad(sx_context*c){uint8_t h[32];uint64_t p=64,n;if(!sxan_read(c,0,h,32)||!sxan_add(c,&sxan_wad_header,0))return false;for(unsigned i=0;i<6;i++){uint64_t z=sxan_uint(h+8+4*i,4,true);if(!z)continue;if(!sxan_span(c,p,z))return true;if(i==2&&z>=676){if(!sxan_add(c,&sxan_wad_rsa2048,p)||!sxan_add(c,&sxan_wad_ticket,p+320)||!sxan_table(c,&sxan_wad_limit,p+612,8,8))return false;}if(i==3&&z>=484){if(!sxan_add(c,&sxan_wad_rsa2048,p)||!sxan_add(c,&sxan_wad_tmd,p+320)||!sxan_word(c,p+478,2,true,&n)||n>(z-484)/36||!sxan_table(c,&sxan_wad_content,p+484,36,n))return false;}p=(p+z+63)&~UINT64_C(63);}return true;}
bool sx_wii_wad_build(sx_context*c)
{
bool ok=false;
ok=sxan_wad(c);
(void)ok;return c->count&&sxan_finish(c);
}
