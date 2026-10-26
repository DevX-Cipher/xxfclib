/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SWAG data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_swag_member_fields[] = {
    SX_FIELD("header_length","uint8",0,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
    SX_FIELD("method","char[5]",2,5,SX_ID),
    SX_FIELD("packed_size","int32",7,4,SX_SIZE),
    SX_FIELD("unpacked_size","int32",11,4,SX_SIZE),
    SX_FIELD("time","uint16",15,2,SX_NONE),
    SX_FIELD("date","uint16",17,2,SX_NONE),
    SX_FIELD("attributes","uint16",19,2,SX_FLAGS),
    SX_FIELD("crc32_register","uint32",21,4,SX_CHECKSUM),
    SX_FIELD("archive_name_size","uint8",25,1,SX_SIZE),
    SX_FIELD("archive_name","char[39]",26,39,SX_STRING),
    SX_FIELD("unused","uint8[121]",65,121,SX_RESERVED),
    SX_FIELD("name_size","uint8",186,1,SX_SIZE),
};
const sx_layout sxae_swag_member = {UINT32_C(0x60170027),"swag_member",sxae_swag_member_fields,SX_COUNT(sxae_swag_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_swag_member_crc_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxae_swag_member_crc = {UINT32_C(0x60170028),"swag_member_crc",sxae_swag_member_crc_fields,SX_COUNT(sxae_swag_member_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxae_swag_footer_fields[] = {
    SX_FIELD("copyright_size","uint8",0,1,SX_SIZE),
    SX_FIELD("copyright","char[60]",1,60,SX_STRING),
    SX_FIELD("collection_size","uint8",61,1,SX_SIZE),
    SX_FIELD("collection","char[65]",62,65,SX_STRING),
    SX_FIELD("member_count","uint16",127,2,SX_COUNT_PROP),
};
const sx_layout sxae_swag_footer = {UINT32_C(0x60170029),"swag_footer",sxae_swag_footer_fields,SX_COUNT(sxae_swag_footer_fields),SX_LE};
static bool sxae_swag(sx_context *c)
{
 uint16_t count;int64_t p=0,foot=c->size-129;if(foot<0||!sx_u16(c,foot+127,false,&count)||!count||!sxae_add(c,&sxae_swag_footer,foot))return false;
 for(unsigned i=0;i<count&&i<20000;i++){uint8_t b[187];if(p>foot-187)break;if(!sx_read(c,p,b,187))return false;uint32_t z=sxae32(b+7);if(b[0]!=187u+b[186]||!b[186]||b[186]>12||xx_rt_memcmp(b+2,"-sw1-",5)||z>INT32_MAX||!sxae_bound(c,p,2u+b[0]+z)||p+2+b[0]+z>foot)break;
 if(!sxae_add(c,&sxae_swag_member,p)||!sxae_add(c,&sxae_swag_member_crc,p+b[0])||!sxae_data(c,p+2+b[0],z))return false;p+=2+b[0]+z;}
 if(foot-p==129||foot-p==130){uint8_t a[129],b[129];if(!sx_read(c,foot-129,a,129)||!sx_read(c,foot,b,129))return false;if(!xx_rt_memcmp(a,b,129)&&!sxae_add(c,&sxae_swag_footer,foot-129))return false;}return true;
}
bool sx_swag_build(sx_context*c)
{
 return sxae_swag(c);
}
