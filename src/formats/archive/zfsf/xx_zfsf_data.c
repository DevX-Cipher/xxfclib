/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZFSF archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_zfsf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("constant8","uint32",8,4,SX_NONE),
 SX_FIELD("group_capacity","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("entry_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("unknown20","uint32",20,4,SX_NONE),
 SX_FIELD("first_group_offset","uint32",24,4,SX_OFFSET),
};
const sx_layout sxag_zfsf_header = {UINT32_C(0x60250016),"zfsf_header",sxag_zfsf_header_fields,SX_COUNT(sxag_zfsf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_zfsf_group_fields[] = {
 SX_FIELD("next_group_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxag_zfsf_group = {UINT32_C(0x60250017),"zfsf_group",sxag_zfsf_group_fields,SX_COUNT(sxag_zfsf_group_fields),SX_LE};
static const xx_data_struct_field_desc sxag_zfsf_entry_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("data_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("unknown20","uint32",20,4,SX_NONE),
 SX_FIELD("data_size","int32",24,4,SX_SIZE),
 SX_FIELD("unknown28","uint8[8]",28,8,SX_NONE),
};
const sx_layout sxag_zfsf_entry = {UINT32_C(0x60250018),"zfsf_entry",sxag_zfsf_entry_fields,SX_COUNT(sxag_zfsf_entry_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_zfsf(sx_context *c){uint8_t b[28];if(!sxag_read(c,0,b,28)||!sxag_add(c,&sxag_zfsf_header,0))return false;uint64_t cap=sxag32(b+12,false),left=sxag32(b+16,false),p=sxag32(b+24,false);if(!cap||cap>INT32_MAX||left>INT32_MAX)return true;
 for(unsigned i=0;left&&i<1024;i++){uint64_t n=left<cap?left:cap;if(p<28||n>SXAG_LIMIT||!sxag_span(c,p,4+n*36)||!sxag_free(c,p,4+n*36)||!sxag_read(c,p,b,4))break;uint64_t next=sxag32(b,false);if(!sxag_add(c,&sxag_zfsf_group,p)||!sxag_table(c,&sxag_zfsf_entry,p+4,n))return false;left-=n;p=next;}return true;}
bool sx_zfsf_build(sx_context*c)
{
 return sxag_zfsf(c);
}
