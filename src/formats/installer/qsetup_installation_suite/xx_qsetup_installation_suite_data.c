/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QSetup data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_qsetup_length_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_qsetup_length = {0x60850032U,"qsetup_length",sxil_qsetup_length_fields,SX_COUNT(sxil_qsetup_length_fields),SX_LE};
static const xx_data_struct_field_desc sxil_qsetup_record_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_qsetup_record = {0x60850033U,"qsetup_record",sxil_qsetup_record_fields,SX_COUNT(sxil_qsetup_record_fields),SX_LE};
static const xx_data_struct_field_desc sxil_qsetup_trailer_fields[] = {
    SX_FIELD("unknown1","byte[4]",0,4,SX_NONE),
    SX_FIELD("container_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("record_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("signature","uint32",12,4,SX_SIGNATURE),
    SX_FIELD("unknown2","byte[54]",16,54,SX_NONE),
    SX_FIELD("trailer_size","uint32",70,4,SX_SIZE),
};
const sx_layout sxil_qsetup_trailer = {0x60850034U,"qsetup_trailer",sxil_qsetup_trailer_fields,SX_COUNT(sxil_qsetup_trailer_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_qsetup(sx_context*c){uint64_t p;if(!sxil_pe(c,&p))return true;for(unsigned k=0;k<2;k++){uint32_t n;if(!sxil_u32(c,p,&n)||n>4096||!sxil_span(c,p+4,n))return true;if(!SXIL_ADD(c,qsetup_length,p)||!sxil_name(c,p+4,n))return false;p+=4+(uint64_t)n;}
 for(size_t k=0;k<100000&&sxil_span(c,p,4);k++){uint32_t n;if(sxil_span(c,p,74)&&sxil_eq(c,p+12,"\x1d\x2c\x3b\x4a",4))return SXIL_ADD(c,qsetup_trailer,p);if(!sxil_u32(c,p,&n)||!n||!sxil_span(c,p+4,n))return true;if(!SXIL_ADD(c,qsetup_record,p))return false;p+=4+(uint64_t)n;}return true;}
bool sx_qsetup_installation_suite_build(sx_context*c)
{
 return sxil_qsetup(c);
}
#undef SXIL_ADD
