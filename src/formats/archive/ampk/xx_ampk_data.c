/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMPK data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_ampk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("reserved5","uint8",5,1,SX_RESERVED),
 SX_FIELD("directory_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("file_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("unpacked_size","uint32",10,4,SX_SIZE),
 SX_FIELD("packed_size_hint","uint32",14,4,SX_SIZE),
 SX_FIELD("unused","uint8[2]",18,2,SX_NONE),
};
const sx_layout sxal_ampk_header = {UINT32_C(0x60200005),"ampk_header",sxal_ampk_header_fields,SX_COUNT(sxal_ampk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ampk_record_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("name_size","uint8",1,1,SX_SIZE),
 SX_FIELD("directory_size_plus3","uint32",2,4,SX_NONE),
};
const sx_layout sxal_ampk_record = {UINT32_C(0x60200006),"ampk_record",sxal_ampk_record_fields,SX_COUNT(sxal_ampk_record_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ampk_file_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size_hint","uint32",4,4,SX_SIZE),
 SX_FIELD("method","uint8",8,1,SX_ID),
 SX_FIELD("padding9","uint8",9,1,SX_RESERVED),
 SX_FIELD("protection","uint32",10,4,SX_FLAGS),
 SX_FIELD("padding14","uint8[2]",14,2,SX_RESERVED),
 SX_FIELD("comment_size","uint8",16,1,SX_SIZE),
 SX_FIELD("padding17","uint8",17,1,SX_RESERVED),
};
const sx_layout sxal_ampk_file = {UINT32_C(0x60200007),"ampk_file",sxal_ampk_file_fields,SX_COUNT(sxal_ampk_file_fields),SX_BE};
static bool sxal_ampk(sx_context *c){uint8_t b[24];if(!sxal_read(c,0,b,20)||!sxal_add(c,&sxal_ampk_header,0))return false;uint64_t p=20;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,6)||b[0]>2)break;unsigned kind=b[0],name=b[1];if(!sxal_span(c,p+6,name))break;if(!sxal_add(c,&sxal_ampk_record,p))return false;p+=6+name;if(kind!=2)continue;if(!sxal_read(c,p,b,18))break;uint64_t n=b[8]?sxal32(b+4,true):sxal32(b,true);unsigned comment=b[16],method=b[8];if(method>3)break;if(!sxal_add(c,&sxal_ampk_file,p))return false;p+=18;if(!sxal_span(c,p,comment))break;p+=comment;if(method==3&&!n&&sxal32(b,true))break;if(!sxal_span(c,p,n))break;p+=n;}return true;}
bool sx_ampk_build(sx_context*c)
{
 return sxal_ampk(c);
}
