/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Garmin FIT data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_fit_file_header_fields[] = {
    SX_FIELD("header_size","uint8",0,1,SX_SIZE),
    SX_FIELD("protocol_version","uint8",1,1,SX_ID),
    SX_FIELD("profile_version","uint16",2,2,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("signature","char[4]",8,4,SX_SIGNATURE),
};
const sx_layout sxsc_fit_file_header = {UINT32_C(0x6028001a),"fit_file_header",sxsc_fit_file_header_fields,SX_COUNT(sxsc_fit_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_crc16_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxsc_fit_crc16 = {UINT32_C(0x6028001b),"fit_crc16",sxsc_fit_crc16_fields,SX_COUNT(sxsc_fit_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_record_header_fields[] = {
    SX_FIELD("record_header","uint8",0,1,SX_FLAGS),
};
const sx_layout sxsc_fit_record_header = {UINT32_C(0x6028001c),"fit_record_header",sxsc_fit_record_header_fields,SX_COUNT(sxsc_fit_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_definition_le_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("architecture","uint8",1,1,SX_ID),
    SX_FIELD("global_message_number","uint16",2,2,SX_ID),
    SX_FIELD("field_count","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxsc_fit_definition_le = {UINT32_C(0x6028001d),"fit_definition_le",sxsc_fit_definition_le_fields,SX_COUNT(sxsc_fit_definition_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_definition_be_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("architecture","uint8",1,1,SX_ID),
    SX_FIELD("global_message_number","uint16",2,2,SX_ID),
    SX_FIELD("field_count","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxsc_fit_definition_be = {UINT32_C(0x6028001e),"fit_definition_be",sxsc_fit_definition_be_fields,SX_COUNT(sxsc_fit_definition_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_fit_developer_count_fields[] = {
    SX_FIELD("developer_field_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxsc_fit_developer_count = {UINT32_C(0x60280020),"fit_developer_count",sxsc_fit_developer_count_fields,SX_COUNT(sxsc_fit_developer_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_developer_field_fields[] = {
    SX_FIELD("field_definition_number","uint8",0,1,SX_ID),
    SX_FIELD("size","uint8",1,1,SX_SIZE),
    SX_FIELD("developer_data_index","uint8",2,1,SX_ID),
};
const sx_layout sxsc_fit_developer_field = {UINT32_C(0x60280021),"fit_developer_field",sxsc_fit_developer_field_fields,SX_COUNT(sxsc_fit_developer_field_fields),SX_LE};
static bool sxsc_fit(sx_context *c)
{
 uint8_t b[16];uint32_t sizes[16]={0};if(!sx_read(c,0,b,12)||(b[0]!=12&&b[0]!=14)||xx_rt_memcmp(b+8,".FIT",4)||!sxsc_add(c,&sxsc_fit_file_header,0,12))return false;
 int64_t at=b[0],end=at+(int64_t)sxsc32(b+4,false);if(!sxsc_span(c,end,2))return false;if(at==14&&!sxsc_add(c,&sxsc_fit_crc16,12,2))return false;
 for(unsigned n=0;at<end;n++){
  if(n>=4094||!sx_read(c,at,b,1)||!sxsc_add(c,&sxsc_fit_record_header,at,1))return false;unsigned code=b[0],local=code&15;at++;
  if(code&128){local=(code>>5)&3;if(sizes[local]<4||sizes[local]-4>(uint64_t)(end-at))return false;at+=sizes[local]-4;}
  else if(code&64){
   if(end-at<5||!sx_read(c,at,b,5)||b[1]>1)return false;bool be=b[1]!=0;unsigned count=b[4];if(!sxsc_add(c,be?&sxsc_fit_definition_be:&sxsc_fit_definition_le,at,5))return false;at+=5;uint32_t size=0;
   if(!count||count*3U>(uint64_t)(end-at))return false;
   for(unsigned i=0;i<count;i++){if(!sx_read(c,at,b,3)||!b[1]||!sxsc_add(c,&sxsc_fit_field_definition,at,3))return false;size+=b[1];at+=3;}
   if(code&32){if(at>=end||!sx_read(c,at,b,1)||!sxsc_add(c,&sxsc_fit_developer_count,at,1))return false;count=b[0];at++;if(count*3U>(uint64_t)(end-at))return false;for(unsigned i=0;i<count;i++){if(!sx_read(c,at,b,3)||!b[1]||!sxsc_add(c,&sxsc_fit_developer_field,at,3))return false;size+=b[1];at+=3;}}
   sizes[local]=size;
  }else{if(!sizes[local]||sizes[local]>(uint64_t)(end-at))return false;at+=sizes[local];}
 }return at==end&&sxsc_add(c,&sxsc_fit_crc16,end,2);
}
bool sx_garmin_fit_build(sx_context*c)
{
 return sxsc_fit(c);
}
