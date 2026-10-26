/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Sydex diskette image data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_sydex_wb_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
    SX_FIELD("page_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("decoded_text_bytes","uint16",6,2,SX_SIZE),
};
const sx_layout sxdr_sydex_wb_header = {0x607f0001U,"sydex_wb_header",sxdr_sydex_wb_header_fields,SX_COUNT(sxdr_sydex_wb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_sydex_image_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("track_bytes","uint16",3,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("stored_cylinders","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("unknown_09","byte[6]",9,6,SX_NONE),
    SX_FIELD("encryption","int16",15,2,SX_NONE),
    SX_FIELD("unknown_11","byte[2]",17,2,SX_NONE),
    SX_FIELD("description_bytes","int16",19,2,SX_SIZE),
    SX_FIELD("description_crc16","uint16",21,2,SX_CHECKSUM),
    SX_FIELD("serial_marker","char[4]",23,4,SX_SIGNATURE),
    SX_FIELD("serial_number","uint32",27,4,SX_ID),
    SX_FIELD("header_crc16","uint16",31,2,SX_CHECKSUM),
};
const sx_layout sxdr_sydex_image_header = {0x607f0002U,"sydex_image_header",sxdr_sydex_image_header_fields,SX_COUNT(sxdr_sydex_image_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_sydex_track_header_fields[] = {
    SX_FIELD("decoded_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("signed_packed_length","int16",2,2,SX_NONE),
};
const sx_layout sxdr_sydex_track_header = {0x607f0003U,"sydex_track_header",sxdr_sydex_track_header_fields,SX_COUNT(sxdr_sydex_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_sydex_description_fields[] = {
    SX_FIELD("description","utf8",0,0,SX_NONE),
};
const sx_layout sxdr_sydex_description = {0x607f0028U,"sydex_description",sxdr_sydex_description_fields,SX_COUNT(sxdr_sydex_description_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static uint16_t sxdr_crc16arc(const uint8_t*b,size_t n){uint16_t v=0;for(size_t i=0;i<n;i++){v^=b[i];for(unsigned j=0;j<8;j++)v=(v&1)?(v>>1)^0xa001:v>>1;}return v;}
static bool sxdr_sydex_header(sx_context*c,uint64_t p,uint8_t*h){if(!sxdr_read(c,p,h,33)||xx_rt_memcmp(h,"SXD",3)||sxdr_crc16arc(h,31)!=sxdr16(h+31,false)||sxdr16(h+15,false)||sxdr16(h+3,false)<128||sxdr16(h+3,false)>32768||!h[5]||!h[6]||!h[7]||!h[8]||h[8]>h[7]||sxdr16(h+19,false)>32767)return false;return true;}
static bool sxdr_sydex(sx_context*c){uint8_t mz[6],wb[10],h[33];uint64_t overlay,stage,p;uint32_t pages,last;
 if(!sxdr_read(c,0,mz,6)||xx_rt_memcmp(mz,"MZ",2)||(pages=sxdr16(mz+4,false))==0||(last=sxdr16(mz+2,false))>=512)return false;overlay=(uint64_t)(pages-1)*512+(last?last:512);if(overlay<64||!sxdr_read(c,overlay,wb,10)||xx_rt_memcmp(wb,"WB",2)||(pages=sxdr16(wb+4,false))==0||(last=sxdr16(wb+2,false))>=512||!sxdr16(wb+6,false)||(sxdr16(wb+8,false)!=0xe4d5U&&sxdr16(wb+8,false)!=0xe5ccU))return false;
 stage=(uint64_t)(pages-1)*512+(last?last:512);p=overlay+stage;if(stage<10||!sxdr_sydex_header(c,p,h)){bool found=false;for(uint64_t i=10;i<=0x20000&&sxdr_span(c,overlay+i,33);i++){uint8_t b;if(!sxdr_read(c,overlay+i,&b,1))return false;if(b=='S'&&sxdr_sydex_header(c,overlay+i,h)){p=overlay+i;found=true;break;}}if(!found)return false;}
 if(!SXDR_ADD(c,sydex_wb_header,overlay)||!SXDR_ADD(c,sydex_image_header,p))return false;uint64_t n=sxdr16(h+19,false),count=(uint64_t)h[6]*h[8];if(!sxdr_span(c,p+33,n))return true;if(!sxdr_text(c,&sxdr_sydex_description,p+33,n))return false;p+=33+n;
 for(uint64_t i=0;i<count;i++){uint8_t q[4];if(!sxdr_read(c,p,q,4))break;int32_t len=(int16_t)sxdr16(q+2,false);if(!len)break;if(!SXDR_ADD(c,sydex_track_header,p))return false;p+=4;uint32_t z=(uint32_t)(len<0?-len:len);if(!sxdr_span(c,p,z))break;p+=z;}return true;}
#undef SXDR_ADD
bool sx_sfx_sydex_diskette_image_build(sx_context*c)
{
 return sxdr_sydex(c);
}
