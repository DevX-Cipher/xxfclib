/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_red data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_sfx_red_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("version","uint8",2,1,SX_ID),
    SX_FIELD("header_size","uint8",3,1,SX_SIZE),
    SX_FIELD("dos_time","uint16",4,2,SX_NONE),
    SX_FIELD("dos_date","uint16",6,2,SX_NONE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
    SX_FIELD("crc1","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("crc2","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("fragment_index","uint16",20,2,SX_NONE),
    SX_FIELD("last_fragment_index","uint16",22,2,SX_NONE),
    SX_FIELD("method","uint16",24,2,SX_ID),
};
const sx_layout sxiex_sfx_red_header = {0x60820058U,"sfx_red_header",sxiex_sfx_red_header_fields,SX_COUNT(sxiex_sfx_red_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfx_red_name_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
};
const sx_layout sxiex_sfx_red_name = {0x60820059U,"sfx_red_name",sxiex_sfx_red_name_fields,SX_COUNT(sxiex_sfx_red_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfx_red_short_name_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_NONE),
};
const sx_layout sxiex_sfx_red_short_name = {0x6082005aU,"sfx_red_short_name",sxiex_sfx_red_short_name_fields,SX_COUNT(sxiex_sfx_red_short_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfx_red_crc16_fields[] = {
    SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxiex_sfx_red_crc16 = {0x6082005bU,"sfx_red_crc16",sxiex_sfx_red_crc16_fields,SX_COUNT(sxiex_sfx_red_crc16_fields),SX_BE};
#define SXIEX_LIMIT 24000U
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_red(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){uint64_t p=r->items[i].data,end=p+r->items[i].packed;unsigned rows=0;while(end-p>=39&&rows++<SXIEX_LIMIT){uint8_t h[26];if(!sxiex_read(c,p,h,26)||xx_rt_memcmp(h,"RR\1",3))break;uint64_t hs=h[3],packed=sxiex32(h+8,false);unsigned method=sxiex16(h+24,false);if(hs<39||hs>end-p||packed>end-p-hs)break;
  if(!SXIEX_ADD(c,sfx_red_header,p)||!sxiex_put(c,hs==39?&sxiex_sfx_red_short_name:&sxiex_sfx_red_name,p+26,1)||!SXIEX_ADD(c,sfx_red_crc16,p+hs-2))return false;
  uint64_t data=p+hs;if(method==11){uint64_t q=data,remaining=packed;while(remaining){uint64_t z=remaining>4096?4096:remaining;if(z>=2&&!SXIEX_ADD(c,sfx_red_crc16,q+z-2))return false;q+=z;remaining-=z;}}p=data+packed;
 }}return true;
}
bool sx_sfx_red_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_red(c,records);
}
#undef SXIEX_LIMIT
#undef SXIEX_ADD
