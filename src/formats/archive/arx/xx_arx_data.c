/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARX data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_arx_member_fields[] = {
 SX_FIELD("header_size_minus2","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("zero7","uint8",7,1,SX_RESERVED),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("time","uint16",16,2,SX_NONE),
 SX_FIELD("date","uint16",18,2,SX_NONE),
 SX_FIELD("unknown20","uint8[2]",20,2,SX_NONE),
 SX_FIELD("name_size","uint8",22,1,SX_SIZE),
};
const sx_layout sxal_arx_member = {UINT32_C(0x60200008),"arx_member",sxal_arx_member_fields,SX_COUNT(sxal_arx_member_fields),SX_LE};
static const xx_data_struct_field_desc sxal_arx_end_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxal_arx_end = {UINT32_C(0x60200009),"arx_end",sxal_arx_end_fields,SX_COUNT(sxal_arx_end_fields),SX_LE};
static bool sxal_arx(sx_context *c){uint8_t b[23];uint64_t p=0;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,1))break;if(!b[0])return sxal_add(c,&sxal_arx_end,p);uint64_t h=b[0]+2U;if(h<24||!sxal_read(c,p,b,23)||!sxal_span(c,p,h)||23U+b[22]>h)break;uint64_t n=sxal32(b+8,false);if(!n)n=sxal32(b+12,false);if(!sxal_add(c,&sxal_arx_member,p))return false;if(!sxal_span(c,p+h,n))break;p+=h+n;}return c->count!=0;}
bool sx_arx_build(sx_context*c)
{
 return sxal_arx(c);
}
