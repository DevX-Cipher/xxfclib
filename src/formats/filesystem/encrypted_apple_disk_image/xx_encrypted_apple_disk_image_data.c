/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Encrypted Apple disk image data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_encrypted_dmg_v2_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint32",8,4,SX_NONE),
    SX_FIELD("block_iv_length","uint32",12,4,SX_SIZE),
    SX_FIELD("block_mode","uint32",16,4,SX_ID),
    SX_FIELD("block_algorithm","uint32",20,4,SX_ID),
    SX_FIELD("key_bits","uint32",24,4,SX_NONE),
    SX_FIELD("iv_key_algorithm","uint32",28,4,SX_ID),
    SX_FIELD("iv_key_bits","uint32",32,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",36,16,SX_ID),
    SX_FIELD("block_size","uint32",52,4,SX_SIZE),
    SX_FIELD("plaintext_length","uint64",56,8,SX_SIZE),
    SX_FIELD("data_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("key_count","uint32",72,4,SX_COUNT_PROP),
};
const sx_layout sx_dm_encrypted_dmg_v2_header = {0x6029002fU,"encrypted_dmg_v2_header",sx_dm_encrypted_dmg_v2_header_fields,SX_COUNT(sx_dm_encrypted_dmg_v2_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_encrypted_dmg_key_pointer_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("size","uint64",12,8,SX_SIZE),
};
const sx_layout sx_dm_encrypted_dmg_key_pointer = {0x60290030U,"encrypted_dmg_key_pointer",sx_dm_encrypted_dmg_key_pointer_fields,SX_COUNT(sx_dm_encrypted_dmg_key_pointer_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_encrypted_dmg_v1_trailer_fields[] = {
    SX_FIELD("unknown_prefix","byte[48]",0,48,SX_NONE),
    SX_FIELD("kdf_iterations","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("salt_length","uint32",52,4,SX_SIZE),
    SX_FIELD("salt","byte[48]",56,48,SX_NONE),
    SX_FIELD("unknown1","byte[32]",104,32,SX_NONE),
    SX_FIELD("wrapped_aes_key_length","uint32",136,4,SX_SIZE),
    SX_FIELD("wrapped_aes_key","byte[296]",140,296,SX_NONE),
    SX_FIELD("wrapped_hmac_key_length","uint32",436,4,SX_SIZE),
    SX_FIELD("wrapped_hmac_key","byte[300]",440,300,SX_NONE),
    SX_FIELD("integrity_key_length","uint32",740,4,SX_SIZE),
    SX_FIELD("integrity_key","byte[48]",744,48,SX_NONE),
    SX_FIELD("unknown2","byte[476]",792,476,SX_NONE),
    SX_FIELD("signature","byte[8]",1268,8,SX_SIGNATURE),
};
const sx_layout sx_dm_encrypted_dmg_v1_trailer = {0x60290031U,"encrypted_dmg_v1_trailer",sx_dm_encrypted_dmg_v1_trailer_fields,SX_COUNT(sx_dm_encrypted_dmg_v1_trailer_fields),SX_BE};
static bool sx_dm_encrypted(sx_context*c){uint8_t h[76];if(sx_dm_read(c,0,h,76)&&!xx_rt_memcmp(h,"encrcdsa",8)){if(!sx_dm_add(c,&sx_dm_encrypted_dmg_v2_header,0,76))return false;uint64_t n=sx_dm_u32(h,72,true);return n>32||!sx_dm_span(c,76,n*20)||sx_dm_table(c,&sx_dm_encrypted_dmg_key_pointer,76,20,n);}return c->size>=1276&&sx_dm_add(c,&sx_dm_encrypted_dmg_v1_trailer,(uint64_t)c->size-1276,1276);}
bool sx_encrypted_apple_disk_image_build(sx_context*c)
{
 return sx_dm_encrypted(c);
}
