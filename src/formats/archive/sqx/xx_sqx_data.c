/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQX data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_sqx_main_fields[] = {
    SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("flags","uint16",3,2,SX_FLAGS),
    SX_FIELD("header_size","uint16",5,2,SX_SIZE),
    SX_FIELD("signature","char[5]",7,5,SX_SIGNATURE),
    SX_FIELD("writer_and_reserved","uint8[13]",12,13,SX_NONE),
};
const sx_layout sxae_sqx_main = {UINT32_C(0x60170018),"sqx_main",sxae_sqx_main_fields,SX_COUNT(sxae_sqx_main_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_record_fields[] = {
    SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("flags","uint16",3,2,SX_FLAGS),
    SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
const sx_layout sxae_sqx_record = {UINT32_C(0x60170019),"sqx_record",sxae_sqx_record_fields,SX_COUNT(sxae_sqx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_file32_fields[] = {
    SX_FIELD("filter","uint8",0,1,SX_ID),
    SX_FIELD("filter_parameters","uint8[4]",1,4,SX_NONE),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("attributes","uint32",10,4,SX_FLAGS),
    SX_FIELD("modified","uint32",14,4,SX_NONE),
    SX_FIELD("packed_size_low","uint32",18,4,SX_SIZE),
    SX_FIELD("unpacked_size_low","uint32",22,4,SX_SIZE),
    SX_FIELD("name_size","uint16",26,2,SX_SIZE),
};
const sx_layout sxae_sqx_file32 = {UINT32_C(0x6017001a),"sqx_file32",sxae_sqx_file32_fields,SX_COUNT(sxae_sqx_file32_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_file64_fields[] = {
    SX_FIELD("filter","uint8",0,1,SX_ID),
    SX_FIELD("filter_parameters","uint8[4]",1,4,SX_NONE),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("attributes","uint32",10,4,SX_FLAGS),
    SX_FIELD("modified","uint32",14,4,SX_NONE),
    SX_FIELD("packed_size_low","uint32",18,4,SX_NONE),
    SX_FIELD("unpacked_size_low","uint32",22,4,SX_NONE),
    SX_FIELD("packed_size_high","uint32",26,4,SX_NONE),
    SX_FIELD("unpacked_size_high","uint32",30,4,SX_NONE),
    SX_FIELD("name_size","uint16",34,2,SX_SIZE),
};
const sx_layout sxae_sqx_file64 = {UINT32_C(0x6017001b),"sqx_file64",sxae_sqx_file64_fields,SX_COUNT(sxae_sqx_file64_fields),SX_LE};
static bool sxae_sqx(sx_context *c)
{
 uint8_t b[36];int64_t p=25;if(!sx_read(c,0,b,25)||b[2]!='R'||sxae16(b+5)!=25||xx_rt_memcmp(b+7,"-sqx-",5)||!sxae_add(c,&sxae_sqx_main,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sxae_bound(c,p,7))return true;if(!sx_read(c,p,b,7))return false;uint8_t kind=b[2];uint16_t fl=sxae16(b+3),z=sxae16(b+5);uint64_t packed=0;
 if(z<7||!sxae_bound(c,p,z))return true;if(!sxae_add(c,&sxae_sqx_record,p))return false;
 if(kind=='A'||kind=='S'||kind=='X')return true;
 if(kind=='D'){unsigned n=fl&0x80?36:28;if(fl&8)return true;if(z<7+n||!sx_read(c,p+7,b,n)||!sxae_add(c,fl&0x80?&sxae_sqx_file64:&sxae_sqx_file32,p+7))return false;
 packed=sxae32(b+18);if(fl&0x80)packed|=(uint64_t)sxae32(b+26)<<32;}
 p+=z;while(fl&0x8000){if(++i>=20000||!sxae_bound(c,p,7))return true;if(!sx_read(c,p,b,7))return false;fl=sxae16(b+3);z=sxae16(b+5);if(z<7||!sxae_bound(c,p,z))return true;if(!sxae_add(c,&sxae_sqx_record,p))return false;p+=z;}
 if(!sxae_data(c,p,packed))return false;p+=(int64_t)packed;}return p==c->size;
}
bool sx_sqx_build(sx_context*c)
{
 return sxae_sqx(c);
}
