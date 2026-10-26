/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DISKDOUBLER data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_diskdoubler_file_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("data_unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("resource_unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("resource_packed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("data_method","uint8",20,1,SX_ID),
 SX_FIELD("resource_method","uint8",21,1,SX_ID),
 SX_FIELD("generation","uint8",22,1,SX_ID),
 SX_FIELD("finder_metadata23","uint8[25]",23,25,SX_NONE),
 SX_FIELD("data_sum16","uint16",48,2,SX_CHECKSUM),
 SX_FIELD("resource_sum16","uint16",50,2,SX_CHECKSUM),
 SX_FIELD("lzw_info","uint8",52,1,SX_NONE),
 SX_FIELD("padding","uint8",53,1,SX_NONE),
 SX_FIELD("data_delta_filter","uint16",54,2,SX_ID),
 SX_FIELD("resource_delta_filter","uint16",56,2,SX_ID),
 SX_FIELD("finder_metadata58","uint8[24]",58,24,SX_NONE),
 SX_FIELD("header_crc16","uint16",82,2,SX_CHECKSUM),
};
const sx_layout sxal_diskdoubler_file = {UINT32_C(0x60200025),"diskdoubler_file",sxal_diskdoubler_file_fields,SX_COUNT(sxal_diskdoubler_file_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("metadata6","uint8[22]",6,22,SX_NONE),
 SX_FIELD("unpacked_size","uint32",28,4,SX_SIZE),
 SX_FIELD("metadata32","uint8[4]",32,4,SX_NONE),
 SX_FIELD("archive_size","uint32",36,4,SX_SIZE),
 SX_FIELD("end_record_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("metadata44","uint8[16]",44,16,SX_NONE),
 SX_FIELD("header_crc16","uint16",60,2,SX_CHECKSUM),
};
const sx_layout sxal_dda2_header = {UINT32_C(0x60200026),"dda2_header",sxal_dda2_header_fields,SX_COUNT(sxal_dda2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_packed_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[8]",46,8,SX_NONE),
 SX_FIELD("header_crc16","uint16",54,2,SX_CHECKSUM),
};
const sx_layout sxal_dda2_packed = {UINT32_C(0x60200027),"dda2_packed",sxal_dda2_packed_fields,SX_COUNT(sxal_dda2_packed_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_folder_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[16]",46,16,SX_NONE),
 SX_FIELD("folder_id","uint32",62,4,SX_ID),
 SX_FIELD("metadata66","uint8[20]",66,20,SX_NONE),
 SX_FIELD("header_crc16","uint16",86,2,SX_CHECKSUM),
};
const sx_layout sxal_dda2_folder = {UINT32_C(0x60200028),"dda2_folder",sxal_dda2_folder_fields,SX_COUNT(sxal_dda2_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_stored_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[32]",46,32,SX_NONE),
 SX_FIELD("data_size","uint32",78,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",82,4,SX_SIZE),
 SX_FIELD("data_xor8","uint8",86,1,SX_SIGNATURE),
 SX_FIELD("resource_xor8","uint8",87,1,SX_SIGNATURE),
 SX_FIELD("header_crc16","uint16",88,2,SX_CHECKSUM),
};
const sx_layout sxal_dda2_stored = {UINT32_C(0x60200029),"dda2_stored",sxal_dda2_stored_fields,SX_COUNT(sxal_dda2_stored_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_end_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_SIGNATURE),
};
const sx_layout sxal_dda2_end = {UINT32_C(0x6020002a),"dda2_end",sxal_dda2_end_fields,SX_COUNT(sxal_dda2_end_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_footer_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("index_size","uint32",2,4,SX_SIZE),
 SX_FIELD("index_crc16","uint16",6,2,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[8]",8,8,SX_RESERVED),
};
const sx_layout sxal_dda2_footer = {UINT32_C(0x6020002b),"dda2_footer",sxal_dda2_footer_fields,SX_COUNT(sxal_dda2_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_index_word_fields[] = {
 SX_FIELD("folder_id_or_record_offset","uint32",0,4,SX_NONE),
};
const sx_layout sxal_dda2_index_word = {UINT32_C(0x6020002c),"dda2_index_word",sxal_dda2_index_word_fields,SX_COUNT(sxal_dda2_index_word_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ddar_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("archive_metadata","uint8[72]",4,72,SX_NONE),
 SX_FIELD("header_crc16","uint16",76,2,SX_CHECKSUM),
};
const sx_layout sxal_ddar_header = {UINT32_C(0x6020002d),"ddar_header",sxal_ddar_header_fields,SX_COUNT(sxal_ddar_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ddar_member_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown4","uint8[4]",4,4,SX_NONE),
 SX_FIELD("name_size","uint8",8,1,SX_SIZE),
 SX_FIELD("name","char[63]",9,63,SX_STRING),
 SX_FIELD("folder_start","uint8",72,1,SX_FLAGS),
 SX_FIELD("folder_end","uint8",73,1,SX_FLAGS),
 SX_FIELD("data_size","uint32",74,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",78,4,SX_SIZE),
 SX_FIELD("finder_metadata","uint8[36]",82,36,SX_NONE),
 SX_FIELD("data_sum16","uint16",118,2,SX_CHECKSUM),
 SX_FIELD("resource_sum16","uint16",120,2,SX_CHECKSUM),
 SX_FIELD("header_crc16","uint16",122,2,SX_CHECKSUM),
};
const sx_layout sxal_ddar_member = {UINT32_C(0x6020002e),"ddar_member",sxal_ddar_member_fields,SX_COUNT(sxal_ddar_member_fields),SX_BE};
static uint16_t sxal_ccitt(const uint8_t *b,size_t n){uint16_t crc=0;for(size_t i=0;i<n;i++){crc^=(uint16_t)b[i]<<8;for(unsigned j=0;j<8;j++)crc=(uint16_t)((crc<<1)^((crc&32768)?0x1021:0));}return crc;}
static bool sxal_dd_method(unsigned v){v&=127;return v==0||v==1||v==6||v==8||v==9||v==10;}
static bool sxal_dd_single(sx_context *c,uint64_t p,uint64_t room){uint8_t b[84];if(room<84||!sxal_read(c,p,b,84)||sxal32(b,true)!=0xabcd0054U)return true;uint64_t size=84+(uint64_t)sxal32(b+8,true)+sxal32(b+16,true);unsigned crc=sxal16(b+82,true);if(size>room||(crc&&crc!=sxal_ccitt(b,82))||sxal16(b+54,true)||sxal16(b+56,true))return true;uint32_t plain=sxal32(b+4,true),resource=sxal32(b+12,true);if((plain&&!sxal_dd_method(b[20]))||(resource&&!sxal_dd_method(b[21]))||(!(b[20]&127)&&plain!=sxal32(b+8,true))||(!(b[21]&127)&&resource!=sxal32(b+16,true)))return true;return sxal_add(c,&sxal_diskdoubler_file,p);}
static bool sxal_diskdoubler(sx_context *c){uint8_t b[124];if(!sxal_read(c,0,b,4))return false;
 if(sxal32(b,true)==0xabcd0054U){if(!sxal_read(c,0,b,84)||!sxal_add(c,&sxal_diskdoubler_file,0))return false;uint64_t n=84+(uint64_t)sxal32(b+8,true)+sxal32(b+16,true);if(sxal_span(c,n,84)){uint8_t copy[84];if(sxal_read(c,n,copy,84)&&!xx_rt_memcmp(b,copy,84)&&!sxal_add(c,&sxal_diskdoubler_file,n))return false;}return true;}
 bool dda=!xx_rt_memcmp(b,"DDA2",4);if(!dda&&xx_rt_memcmp(b,"DDAR",4))return false;uint64_t p=dda?62:78;if(!sxal_add(c,dda?&sxal_dda2_header:&sxal_ddar_header,0))return false;
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){
  if(dda){if(!sxal_read(c,p,b,6)||xx_rt_memcmp(b,"DDA2",4))break;unsigned type=sxal16(b+4,true);if(type==0xbbbb){if(!sxal_add(c,&sxal_dda2_end,p))return false;p+=6;if(sxal_read(c,p,b,16)&&sxal16(b,true)==0xbecd){uint64_t n=sxal32(b+2,true);if(sxal_span(c,p+16,n)&&!sxal_add(c,&sxal_dda2_footer,p))return false;if(n&&!(n&3)&&n/4<=SXAL_LIMIT&&sxal_span(c,p+16,n)&&!sx_table(c,&sxal_dda2_index_word,(int64_t)p+16,4,n/4))return false;}break;}
   unsigned h=type&0x8000?88:type&0x4000?56:90;if(h==90&&(!sxal_read(c,p,b,90)||sxal16(b+88,true)!=sxal_ccitt(b,88)))h=56;if(!sxal_read(c,p,b,h)||sxal16(b+h-2,true)!=sxal_ccitt(b,h-2))break;uint64_t n=sxal32(b+42,true);if(n<h||!sxal_span(c,p,n))break;if(!sxal_add(c,h==88?&sxal_dda2_folder:h==56?&sxal_dda2_packed:&sxal_dda2_stored,p))return false;if(h==56&&!sxal_dd_single(c,p+h,n-h))return false;p+=n;
  }else{if(!sxal_read(c,p,b,124)||xx_rt_memcmp(b,"DDAR",4)||sxal16(b+122,true)!=sxal_ccitt(b,122))break;uint64_t data=sxal32(b+74,true),resource=sxal32(b+78,true),n=b[73]?0:data+resource;if(!sxal_span(c,p+124,n))break;if(!sxal_add(c,&sxal_ddar_member,p))return false;if(!b[72]&&!b[73]&&!resource&&!sxal_dd_single(c,p+124,data))return false;p+=124+n;}
 }return true;}
bool sx_diskdoubler_build(sx_context*c)
{
 return sxal_diskdoubler(c);
}
