/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQZ data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_sqz_header_fields[] = {
    SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",5,1,SX_NONE),
    SX_FIELD("unknown","uint8[2]",6,2,SX_NONE),
};
const sx_layout sxae_sqz_header = {UINT32_C(0x60170012),"sqz_header",sxae_sqz_header_fields,SX_COUNT(sxae_sqz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_member_fields[] = {
    SX_FIELD("header_length","uint8",0,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("packed_size","uint32",3,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("time","uint16",11,2,SX_NONE),
    SX_FIELD("date","uint16",13,2,SX_NONE),
    SX_FIELD("attributes","uint8",15,1,SX_FLAGS),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxae_sqz_member = {UINT32_C(0x60170013),"sqz_member",sxae_sqz_member_fields,SX_COUNT(sxae_sqz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_block_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("extra_size","uint16",1,2,SX_SIZE),
};
const sx_layout sxae_sqz_block = {UINT32_C(0x60170014),"sqz_block",sxae_sqz_block_fields,SX_COUNT(sxae_sqz_block_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_block4_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("extra_size","uint16",1,2,SX_SIZE),
    SX_FIELD("unknown","uint8[2]",3,2,SX_NONE),
};
const sx_layout sxae_sqz_block4 = {UINT32_C(0x60170015),"sqz_block4",sxae_sqz_block4_fields,SX_COUNT(sxae_sqz_block4_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_comment_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("legacy_size","uint16",1,2,SX_NONE),
    SX_FIELD("extra_size","uint16",3,2,SX_SIZE),
    SX_FIELD("unknown","uint8[5]",5,5,SX_NONE),
};
const sx_layout sxae_sqz_comment = {UINT32_C(0x60170016),"sqz_comment",sxae_sqz_comment_fields,SX_COUNT(sxae_sqz_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxae_sqz_end = {UINT32_C(0x60170017),"sqz_end",sxae_sqz_end_fields,SX_COUNT(sxae_sqz_end_fields),SX_LE};
static bool sxae_sqz(sx_context *c)
{
 uint8_t b[20];int64_t p=8;if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"HLSQZ",5)||!sxae_add(c,&sxae_sqz_header,0))return false;
 for(unsigned i=0;i<20000;i++){if(!sx_read(c,p,b,1))return false;if(!b[0])return sxae_add(c,&sxae_sqz_end,p);
 if(b[0]<19){int n=b[0]==1?10:b[0]==4?5:3;if(!sx_read(c,p,b,n))return false;uint16_t z=sxae16(b+(b[0]==1?3:1));if(!sxae_add(c,n==10?&sxae_sqz_comment:n==5?&sxae_sqz_block4:&sxae_sqz_block,p)||!sxae_data(c,p+n,z))return false;p+=n+z;}
 else {unsigned n=b[0]+2;if(!sx_read(c,p,b,20)||!sxae_bound(c,p,n)||!sxae_add(c,&sxae_sqz_member,p))return false;uint32_t z=sxae32(b+3);if(!sxae_data(c,p+n,z))return false;p+=n+z;}}return false;
}
bool sx_sqz_build(sx_context*c)
{
 return sxae_sqz(c);
}
