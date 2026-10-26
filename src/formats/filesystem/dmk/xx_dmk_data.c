/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DMK data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_dmk_header_fields[] = {
    SX_FIELD("write_protected","uint8",0,1,SX_FLAGS),
    SX_FIELD("cylinder_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("track_size","uint16",2,2,SX_SIZE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("reserved","byte[7]",5,7,SX_RESERVED),
    SX_FIELD("real_disk_flags","uint32",12,4,SX_FLAGS),
};
const sx_layout sxsl_dmk_header = {0x60330023U,"dmk_header",sxsl_dmk_header_fields,SX_COUNT(sxsl_dmk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_dmk_idam_pointer_fields[] = {
    SX_FIELD("offset_and_density","uint16",0,2,SX_FLAGS),
};
const sx_layout sxsl_dmk_idam_pointer = {0x60330024U,"dmk_idam_pointer",sxsl_dmk_idam_pointer_fields,SX_COUNT(sxsl_dmk_idam_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_dmk_idam_fields[] = {
    SX_FIELD("id_address_mark","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("cylinder","uint8",1,1,SX_NONE),
    SX_FIELD("head","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
    SX_FIELD("size_code","uint8",4,1,SX_NONE),
    SX_FIELD("crc16","uint16be",5,2,SX_CHECKSUM),
};
const sx_layout sxsl_dmk_idam = {0x60330025U,"dmk_idam",sxsl_dmk_idam_fields,SX_COUNT(sxsl_dmk_idam_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_dmk_idam_doubled_fields[] = {
    SX_FIELD("id_address_mark","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("id_address_mark_copy","uint8",1,1,SX_NONE),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder_copy","uint8",3,1,SX_NONE),
    SX_FIELD("head","uint8",4,1,SX_NONE),
    SX_FIELD("head_copy","uint8",5,1,SX_NONE),
    SX_FIELD("sector","uint8",6,1,SX_NONE),
    SX_FIELD("sector_copy","uint8",7,1,SX_NONE),
    SX_FIELD("size_code","uint8",8,1,SX_NONE),
    SX_FIELD("size_code_copy","uint8",9,1,SX_NONE),
    SX_FIELD("crc_high","uint8",10,1,SX_CHECKSUM),
    SX_FIELD("crc_high_copy","uint8",11,1,SX_CHECKSUM),
    SX_FIELD("crc_low","uint8",12,1,SX_CHECKSUM),
    SX_FIELD("crc_low_copy","uint8",13,1,SX_CHECKSUM),
};
const sx_layout sxsl_dmk_idam_doubled = {0x60330053U,"dmk_idam_doubled",sxsl_dmk_idam_doubled_fields,SX_COUNT(sxsl_dmk_idam_doubled_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_dmk(sx_context*c){uint8_t h[16];if(!sxsl_read(c,0,h,16)||!SXSL_ADD(c,dmk_header,0))return false;uint64_t z=sxsl16(h+2),n=(uint64_t)h[1]*((h[4]&16)?1:2);if(z<=128||z>=16384)return true;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t p=16+i*z;if(!sxsl_span(c,p,z))break;if(!SXSL_TABLE(c,dmk_idam_pointer,p,64))return false;for(unsigned j=0;j<64&&c->count<SXSL_LIMIT;j++){uint64_t w;if(!sxsl_word(c,p+2*j,2,false,&w)||!w)break;uint64_t q=w&0x3fff,step=(w&0x8000)||(h[4]&64)?1:2;if(q<128||q+7*step>z)continue;if(!sxsl_put(c,step==1?&sxsl_dmk_idam:&sxsl_dmk_idam_doubled,p+q,1))return false;}}return true;}
bool sx_dmk_build(sx_context*c)
{
bool ok=false;
ok=sxsl_dmk(c);
return ok&&sxsl_finish(c);
}
