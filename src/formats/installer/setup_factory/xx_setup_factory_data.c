/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SETUP_FACTORY data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_setup_factory_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("engine_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxan_setup_factory_header = {UINT32_C(0x60770026),"setup_factory_header",sxan_setup_factory_header_fields,SX_COUNT(sxan_setup_factory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_setup_factory_engine_16_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxan_setup_factory_engine_16 = {UINT32_C(0x60770027),"setup_factory_engine_16",sxan_setup_factory_engine_16_fields,SX_COUNT(sxan_setup_factory_engine_16_fields),SX_LE};
static const xx_data_struct_field_desc sxan_setup_factory_engine_260_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_NONE),
 SX_FIELD("compressed_size","uint32",260,4,SX_SIZE),
 SX_FIELD("crc32","uint32",264,4,SX_CHECKSUM),
};
const sx_layout sxan_setup_factory_engine_260 = {UINT32_C(0x60770028),"setup_factory_engine_260",sxan_setup_factory_engine_260_fields,SX_COUNT(sxan_setup_factory_engine_260_fields),SX_LE};
static bool sxan_sf_name(const uint8_t*h,unsigned width){unsigned i=0;for(;i<width&&h[i];i++)if(h[i]<32||h[i]>126||h[i]=='/'||h[i]=='\\'||h[i]==':')return false;if(!i||i==width)return false;for(;i<width;i++)if(h[i])return false;return true;}
static bool sxan_setup_factory(sx_context*c){uint64_t p,n,z;uint8_t h[268];if(!sxan_pe_overlay(c,&p)||!sxan_add(c,&sxan_setup_factory_header,p)||!sxan_word(c,p+8,4,false,&n))return false;p+=12;unsigned width=0;for(uint64_t i=0;i<n;i++){if(!width){if(sxan_read(c,p,h,268)&&sxan_sf_name(h,260)&&sxan_uint(h+260,4,false))width=260;else width=16;}if(!sxan_word(c,p+width,4,false,&z)||!z||!sxan_add(c,width==260?&sxan_setup_factory_engine_260:&sxan_setup_factory_engine_16,p))return false;p+=width+8;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_setup_factory_build(sx_context*c)
{
bool ok=false;
ok=sxan_setup_factory(c);
(void)ok;return c->count&&sxan_finish(c);
}
