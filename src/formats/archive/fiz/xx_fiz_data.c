/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Maximus FIZ archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_fiz_member_fields[] = {
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("method","uint8",4,1,SX_ID),
 SX_FIELD("name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("crc16","uint16",6,2,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("time","uint16",16,2,SX_NONE),
 SX_FIELD("date","uint16",18,2,SX_NONE),
};
const sx_layout sxag_fiz_member = {UINT32_C(0x60250037),"fiz_member",sxag_fiz_member_fields,SX_COUNT(sxag_fiz_member_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_fiz(sx_context *c){uint8_t b[20];uint64_t p=0;for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,20)||xx_rt_memcmp(b,"FIZ\32",4))break;uint64_t n=sxag32(b+12,false),name=b[5];if(!name||name>12||!sxag_span(c,p+20,name+n))break;if(!sxag_add(c,&sxag_fiz_member,p))return false;p+=20+name+n;}return c->count!=0;}
bool sx_fiz_build(sx_context*c)
{
 return sxag_fiz(c);
}
