/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * U-Boot environment data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_uboot_env_le_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxbrs_uboot_env_le = {UINT32_C(0x603e001f),"uboot_env_le",sxbrs_uboot_env_le_fields,SX_COUNT(sxbrs_uboot_env_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_redundant_env_le_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
const sx_layout sxbrs_uboot_redundant_env_le = {UINT32_C(0x603e0020),"uboot_redundant_env_le",sxbrs_uboot_redundant_env_le_fields,SX_COUNT(sxbrs_uboot_redundant_env_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_env_be_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxbrs_uboot_env_be = {UINT32_C(0x603e0021),"uboot_env_be",sxbrs_uboot_env_be_fields,SX_COUNT(sxbrs_uboot_env_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_uboot_redundant_env_be_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
const sx_layout sxbrs_uboot_redundant_env_be = {UINT32_C(0x603e0022),"uboot_redundant_env_be",sxbrs_uboot_redundant_env_be_fields,SX_COUNT(sxbrs_uboot_redundant_env_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_uboot_key_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
const sx_layout sxbrs_uboot_key_byte = {UINT32_C(0x603e0023),"uboot_key_byte",sxbrs_uboot_key_byte_fields,SX_COUNT(sxbrs_uboot_key_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_value_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
const sx_layout sxbrs_uboot_value_byte = {UINT32_C(0x603e0024),"uboot_value_byte",sxbrs_uboot_value_byte_fields,SX_COUNT(sxbrs_uboot_value_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_separator_fields[] = {
    SX_FIELD("separator","uint8",0,1,SX_NONE),
};
const sx_layout sxbrs_uboot_separator = {UINT32_C(0x603e0025),"uboot_separator",sxbrs_uboot_separator_fields,SX_COUNT(sxbrs_uboot_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_terminator_fields[] = {
    SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
const sx_layout sxbrs_uboot_terminator = {UINT32_C(0x603e0026),"uboot_terminator",sxbrs_uboot_terminator_fields,SX_COUNT(sxbrs_uboot_terminator_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
#define B(p,w) sxbrs_num(c,(p),(w),true)
static bool sxbrs_uboot(sx_context*c){
 if(c->size<256||c->size>1048576)return false;uint8_t chunk[4096];uint32_t want=(uint32_t)N(0,4);unsigned prefix=0;bool be=false;
 for(unsigned h=4;h<=5&&!prefix;h++){uint32_t crc=0;for(int64_t at=h;at<c->size;){size_t n=(uint64_t)(c->size-at)>sizeof(chunk)?sizeof(chunk):(size_t)(c->size-at);if(!sx_read(c,at,chunk,n)||xx_pd_is_stopped(c->pd))return false;crc=xx_crc32_calc(crc,chunk,n);at+=(int64_t)n;}if(crc==want){prefix=h;be=false;}else if(crc==(uint32_t)B(0,4)){prefix=h;be=true;}}
 if(!prefix)return false;const sx_layout*header=prefix==4?(be?&sxbrs_uboot_env_be:&sxbrs_uboot_env_le):(be?&sxbrs_uboot_redundant_env_be:&sxbrs_uboot_redundant_env_le);if(!sxbrs_add(c,header,0))return false;
 int64_t at=prefix,end=c->size;unsigned count=0;while(at<end&&N(at,1)){int64_t key=at;while(at<end&&N(at,1)&&N(at,1)!='='){if(at-key>=128)return false;at++;}if(at==key||at==end||N(at,1)!='='||++count>4096)return false;int64_t p=key;if(!sxbrs_take(c,&sxbrs_uboot_key_byte,&p,at,(uint64_t)(at-key)))return false;AL(uboot_separator,1);int64_t value=at;while(at<end&&N(at,1)){if(at-value>=32768)return false;at++;}p=value;if(!sxbrs_take(c,&sxbrs_uboot_value_byte,&p,at,(uint64_t)(at-value)))return false;AL(uboot_terminator,1);}
 if(!count||at>=end)return false;AL(uboot_terminator,1);return !c->failed;
}
bool sx_uboot_build(sx_context*c)
{
 return sxbrs_uboot(c);
}
#undef AL
#undef N
#undef B
