/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SEAARC data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_arc_member_old_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
    SX_FIELD("name","char[13]",2,13,SX_STRING),
    SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
    SX_FIELD("date","uint16",19,2,SX_NONE),
    SX_FIELD("time","uint16",21,2,SX_NONE),
    SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
};
const sx_layout sxae_arc_member_old = {UINT32_C(0x60170001),"arc_member_old",sxae_arc_member_old_fields,SX_COUNT(sxae_arc_member_old_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arc_member_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
    SX_FIELD("name","char[13]",2,13,SX_STRING),
    SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
    SX_FIELD("date","uint16",19,2,SX_NONE),
    SX_FIELD("time","uint16",21,2,SX_NONE),
    SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",25,4,SX_SIZE),
};
const sx_layout sxae_arc_member = {UINT32_C(0x60170002),"arc_member",sxae_arc_member_fields,SX_COUNT(sxae_arc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arc_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
};
const sx_layout sxae_arc_end = {UINT32_C(0x60170003),"arc_end",sxae_arc_end_fields,SX_COUNT(sxae_arc_end_fields),SX_LE};
static bool sxae_arc(sx_context *c)
{
 int64_t p=0;uint8_t b[29];for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,2)||b[0]!=0x1a)return false;if(!b[1])return sxae_add(c,&sxae_arc_end,p);
 int n=b[1]==1?25:29;if(!sx_read(c,p,b,n)||!sxae_add(c,n==25?&sxae_arc_member_old:&sxae_arc_member,p))return false;uint32_t z=sxae32(b+15);if(!sxae_data(c,p+n,z))return false;p+=n+z;}return false;
}
bool sx_seaarc_build(sx_context*c)
{
 return sxae_arc(c);
}
