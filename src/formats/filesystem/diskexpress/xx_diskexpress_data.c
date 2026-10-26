/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DiskExpress data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_diskexpress_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("major","uint8",2,1,SX_NONE),
    SX_FIELD("minor","uint8",3,1,SX_NONE),
    SX_FIELD("release","uint8",4,1,SX_NONE),
    SX_FIELD("disk_type","uint8",5,1,SX_ID),
    SX_FIELD("image_crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("method","uint8",10,1,SX_ID),
    SX_FIELD("last_cylinder","uint8",11,1,SX_NONE),
    SX_FIELD("last_head","uint8",12,1,SX_NONE),
    SX_FIELD("unused","uint8",13,1,SX_RESERVED),
    SX_FIELD("flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[289]",15,289,SX_RESERVED),
    SX_FIELD("header_crc32","uint32",304,4,SX_CHECKSUM),
    SX_FIELD("description","char[200]",308,200,SX_STRING),
    SX_FIELD("description_crc32","uint32",508,4,SX_CHECKSUM),
};
const sx_layout sxae_diskexpress_header = {UINT32_C(0x60170031),"diskexpress_header",sxae_diskexpress_header_fields,SX_COUNT(sxae_diskexpress_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_diskexpress_track_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxae_diskexpress_track = {UINT32_C(0x60170032),"diskexpress_track",sxae_diskexpress_track_fields,SX_COUNT(sxae_diskexpress_track_fields),SX_LE};
static bool sxae_diskexpress(sx_context *c)
{
 uint8_t b[15];if(!sx_read(c,0,b,15)||xx_rt_memcmp(b,"AS",2)||!sxae_add(c,&sxae_diskexpress_header,0))return false;if(!b[10])return true;unsigned n=(unsigned)b[11]*2+(b[12]>1?1:b[12])+1;int64_t p=512;
 if(n>200)return false;for(unsigned i=0;i<n;i++){uint16_t z;if(!sx_u16(c,p,false,&z)||!z||!sxae_add(c,&sxae_diskexpress_track,p)||!sxae_data(c,p+2,z))return false;p+=2+z;}return p==c->size;
}
bool sx_diskexpress_build(sx_context*c)
{
 return sxae_diskexpress(c);
}
