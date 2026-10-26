/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GNU gettext MO / Qt QM data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_mo_header_le_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("string_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("originals_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("translations_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("hash_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("hash_offset", "uint32", 24, 4, SX_OFFSET),
};
const sx_layout sxl_mo_header_le = { UINT32_C(0x600A0021), "mo_header_le", sxl_mo_header_le_fields, SX_COUNT(sxl_mo_header_le_fields), SX_LE };
static const xx_data_struct_field_desc sxl_mo_string_le_fields[] = {
    SX_FIELD("string_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("string_offset", "uint32", 4, 4, SX_OFFSET),
};
const sx_layout sxl_mo_string_le = { UINT32_C(0x600A0022), "mo_string_le", sxl_mo_string_le_fields, SX_COUNT(sxl_mo_string_le_fields), SX_LE };
static const xx_data_struct_field_desc sxl_mo_hash_le_fields[] = {
    SX_FIELD("string_index", "uint32", 0, 4, SX_ID),
};
const sx_layout sxl_mo_hash_le = { UINT32_C(0x600A0023), "mo_hash_le", sxl_mo_hash_le_fields, SX_COUNT(sxl_mo_hash_le_fields), SX_LE };
static const xx_data_struct_field_desc sxl_mo_header_be_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("string_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("originals_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("translations_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("hash_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("hash_offset", "uint32", 24, 4, SX_OFFSET),
};
const sx_layout sxl_mo_header_be = { UINT32_C(0x600A0024), "mo_header_be", sxl_mo_header_be_fields, SX_COUNT(sxl_mo_header_be_fields), SX_BE };
static const xx_data_struct_field_desc sxl_mo_string_be_fields[] = {
    SX_FIELD("string_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("string_offset", "uint32", 4, 4, SX_OFFSET),
};
const sx_layout sxl_mo_string_be = { UINT32_C(0x600A0025), "mo_string_be", sxl_mo_string_be_fields, SX_COUNT(sxl_mo_string_be_fields), SX_BE };
static const xx_data_struct_field_desc sxl_mo_hash_be_fields[] = {
    SX_FIELD("string_index", "uint32", 0, 4, SX_ID),
};
const sx_layout sxl_mo_hash_be = { UINT32_C(0x600A0026), "mo_hash_be", sxl_mo_hash_be_fields, SX_COUNT(sxl_mo_hash_be_fields), SX_BE };
static const xx_data_struct_field_desc sxl_qm_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 16, SX_SIGNATURE),
};
const sx_layout sxl_qm_header = { UINT32_C(0x600A0027), "qm_header", sxl_qm_header_fields, SX_COUNT(sxl_qm_header_fields), SX_BE };
static const xx_data_struct_field_desc sxl_qm_hash_fields[] = {
    SX_FIELD("hash", "uint32", 0, 4, SX_ID),
    SX_FIELD("message_offset", "uint32", 4, 4, SX_OFFSET),
};
const sx_layout sxl_qm_hash = { UINT32_C(0x600A0029), "qm_hash", sxl_qm_hash_fields, SX_COUNT(sxl_qm_hash_fields), SX_BE };
static bool sxl_mo(sx_context *c)
{
    uint32_t magic,rev,count,a,b,hc,ho;bool be;
    if(!sx_u32(c,0,false,&magic)||(magic!=0x950412deU&&magic!=0xde120495U))return false;be=magic==0xde120495U;
    if(!sx_u32(c,4,be,&rev)||(rev>>16)||!sx_u32(c,8,be,&count)||count>1000000||!sx_u32(c,12,be,&a)||!sx_u32(c,16,be,&b)||!sx_u32(c,20,be,&hc)||!sx_u32(c,24,be,&ho)||!sxl_span(c,a,(uint64_t)count*8)||!sxl_span(c,b,(uint64_t)count*8)||(hc&&!sxl_span(c,ho,(uint64_t)hc*4)))return false;
    if(!sx_add(c,be?&sxl_mo_header_be:&sxl_mo_header_le,0,28)||!sx_table(c,be?&sxl_mo_string_be:&sxl_mo_string_le,a,8,count)||!sx_table(c,be?&sxl_mo_string_be:&sxl_mo_string_le,b,8,count)||!sx_table(c,be?&sxl_mo_hash_be:&sxl_mo_hash_le,ho,4,hc))return false;
    for(unsigned table=0;table<2;table++)for(uint32_t i=0;i<count;i++){uint32_t size,off;uint8_t z;int64_t at=(table?b:a)+(int64_t)i*8;if(!sx_u32(c,at,be,&size)||!sx_u32(c,at+4,be,&off)||!sxl_span(c,off,(uint64_t)size+1)||!sxl_byte(c,(int64_t)off+size,&z)||z)return false;}
    for(uint32_t i=0;i<hc;i++){uint32_t v;if(!sx_u32(c,(int64_t)ho+(int64_t)i*4,be,&v)||v>count)return false;}return true;
}
static bool sxl_qm(sx_context *c)
{
    int64_t at=16,hash_at=-1,message_at=-1;uint32_t hash_size=0,message_size=0;
    if(!sxl_sig(c,0,"\x3c\xb8\x64\x18\xca\xef\x9c\x95\xcd\x21\x1c\xbf\x60\xa1\xbd\xdd",16)||!sx_add(c,&sxl_qm_header,0,16))return false;
    while(at<c->size){uint8_t tag;uint32_t size;if(!sxl_byte(c,at,&tag)||!tag||!sx_u32(c,at+1,true,&size)||!sxl_span(c,at+5,size)||!sx_add(c,&sxl_qm_block,at,5))return false;at+=5;
        if(tag==0x42){if(hash_at>=0||size%8||!sx_table(c,&sxl_qm_hash,at,8,size/8))return false;hash_at=at;hash_size=size;}
        else if(tag==0x69){if(message_at>=0)return false;message_at=at;message_size=size;int64_t p=at,end=at+size;
            while(p<end){uint8_t field;uint32_t length;if(!sxl_byte(c,p,&field))return false;if(field==1){if(!sx_add(c,&sxl_qm_message_end,p++,1))return false;continue;}
                if(end-p<5||!sx_u32(c,p+1,true,&length)||!sx_add(c,field==5?&sxl_qm_message_obsolete:&sxl_qm_message_field,p,5))return false;p+=5;if(field==5)continue;if(length==UINT32_MAX)length=0;if(length>(uint64_t)(end-p))return false;p+=length;
            }
        }at+=size;
    }
    if(hash_size&&message_at<0)return false;
    for(uint32_t i=0;i<hash_size/8;i++){uint32_t off;if(!sx_u32(c,hash_at+(int64_t)i*8+4,true,&off)||off>=message_size)return false;}
    return true;
}
bool sx_ue2_documents_schema_build(sx_context*c)
{
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_GNU_GETTEXT_MO:ok=sxl_mo(c);break;
    case XX_FILE_TYPE_QT_QM:ok=sxl_qm(c);break;
    default:break;
    }return ok;
}
