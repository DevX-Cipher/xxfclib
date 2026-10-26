/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LHA data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_crc16_fields[] = {
    SX_FIELD("crc16", "uint16", 0, 2, SX_CHECKSUM),
};
const sx_layout sx_p_crc16 = { UINT32_C(0x60070005), "crc16", sx_p_crc16_fields, SX_COUNT(sx_p_crc16_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_level0_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 1, 1, SX_CHECKSUM),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("name_size", "uint8", 21, 1, SX_SIZE),
};
const sx_layout sx_p_lha_level0 = { UINT32_C(0x6007001B), "lha_level0", sx_p_lha_level0_fields, SX_COUNT(sx_p_lha_level0_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_level1_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 1, 1, SX_CHECKSUM),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("name_size", "uint8", 21, 1, SX_SIZE),
};
const sx_layout sx_p_lha_level1 = { UINT32_C(0x6007001C), "lha_level1", sx_p_lha_level1_fields, SX_COUNT(sx_p_lha_level1_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_level2_fields[] = {
    SX_FIELD("header_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("crc16", "uint16", 21, 2, SX_CHECKSUM),
    SX_FIELD("host_os", "uint8", 23, 1, SX_ID),
};
const sx_layout sx_p_lha_level2 = { UINT32_C(0x6007001D), "lha_level2", sx_p_lha_level2_fields, SX_COUNT(sx_p_lha_level2_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_level3_fields[] = {
    SX_FIELD("word_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("crc16", "uint16", 21, 2, SX_CHECKSUM),
    SX_FIELD("host_os", "uint8", 23, 1, SX_ID),
    SX_FIELD("total_header_size", "uint32", 24, 4, SX_SIZE),
};
const sx_layout sx_p_lha_level3 = { UINT32_C(0x6007001E), "lha_level3", sx_p_lha_level3_fields, SX_COUNT(sx_p_lha_level3_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_extension2_fields[] = {
    SX_FIELD("next_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("type", "uint8", 2, 1, SX_ID),
};
const sx_layout sx_p_lha_extension2 = { UINT32_C(0x6007001F), "lha_extension2", sx_p_lha_extension2_fields, SX_COUNT(sx_p_lha_extension2_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_extension4_fields[] = {
    SX_FIELD("next_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
};
const sx_layout sx_p_lha_extension4 = { UINT32_C(0x60070020), "lha_extension4", sx_p_lha_extension4_fields, SX_COUNT(sx_p_lha_extension4_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_os_fields[] = {
    SX_FIELD("host_os", "uint8", 0, 1, SX_ID),
};
const sx_layout sx_p_lha_os = { UINT32_C(0x60070021), "lha_os", sx_p_lha_os_fields, SX_COUNT(sx_p_lha_os_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_length32_fields[] = {
    SX_FIELD("data_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_p_length32 = { UINT32_C(0x60070022), "length32", sx_p_length32_fields, SX_COUNT(sx_p_length32_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_unix_mode_fields[] = {
    SX_FIELD("mode", "uint16", 0, 2, SX_FLAGS),
};
const sx_layout sx_p_lha_unix_mode = { UINT32_C(0x60070050), "lha_unix_mode", sx_p_lha_unix_mode_fields, SX_COUNT(sx_p_lha_unix_mode_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_lha_sizes64_fields[] = {
    SX_FIELD("packed_size", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 8, 8, SX_SIZE),
};
const sx_layout sx_p_lha_sizes64 = { UINT32_C(0x60070051), "lha_sizes64", sx_p_lha_sizes64_fields, SX_COUNT(sx_p_lha_sizes64_fields), SX_LE };
static bool sx_p_lha(sx_context *c)
{
    int64_t off=0;while(off<c->size){uint8_t h[28],first;if(!sx_p_byte(c,off,&first))return false;if(!first&&c->size-off<22)return true;if(!sx_read(c,off,h,22)||h[2]!='-'||h[6]!='-')return false;
        unsigned level=h[20],word=2;uint32_t packed=xx_data_get_u32(h,22,7,false);int64_t base,chain=-1,end;
        const sx_layout *l;int fixed;
        if(level<2){base=h[0]+2;fixed=22;l=level?&sx_p_lha_level1:&sx_p_lha_level0;if(base<24+h[21]+(level?3:0)||!sx_p_span(c,off,base)||!sx_add(c,&sx_p_crc16,off+22+h[21],2))return false;if(level){if(!sx_add(c,&sx_p_lha_os,off+24+h[21],1))return false;chain=base-2;}}
        else {if(!sx_read(c,off,h,level==3?28:24))return false;fixed=level==2?24:28;l=level==2?&sx_p_lha_level2:&sx_p_lha_level3;if(level==2){base=xx_data_get_u16(h,28,0,false)+(h[23]=='K'?2:0);chain=24;}else if(level==3&&xx_data_get_u16(h,28,0,false)==4){base=xx_data_get_u32(h,28,24,false);chain=28;word=4;}else return false;if(base<fixed+word||!sx_p_span(c,off,base))return false;}
        if(!sx_add(c,l,off,fixed))return false;end=base;
        if(chain>=0)for(;;){uint64_t n;if(!sx_p_uint(c,off+chain,word,&n))return false;if(!n){if(!sx_add(c,word==2?&sx_p_length16:&sx_p_length32,off+chain,word))return false;break;}if(n<word+1||n>INT32_MAX)return false;if(level==1){if(n>packed||!sx_p_span(c,off+end,n))return false;packed-=(uint32_t)n;end+=(int64_t)n;}else if(n>(uint64_t)(base-chain-word))return false;if(!sx_add(c,word==2?&sx_p_lha_extension2:&sx_p_lha_extension4,off+chain,word+1))return false;
        uint8_t type;if(!sx_p_byte(c,off+chain+word,&type))return false;int64_t data=off+chain+word+1;uint64_t amount=n-word-1;
        if(type==0&&amount>=2){if(!sx_add(c,&sx_p_crc16,data,2))return false;}else if(type==0x50&&amount>=2){if(!sx_add(c,&sx_p_lha_unix_mode,data,2))return false;}else if(type==0x42&&amount>=16){if(!sx_add(c,&sx_p_lha_sizes64,data,16))return false;}
        chain+=(int64_t)n;}
        if(!sx_p_span(c,off+end,packed))return false;off+=end+packed;
    }return true;
}
bool sx_lha_build(sx_context*c)
{
    return sx_p_lha(c);
}
