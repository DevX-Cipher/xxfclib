/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tarma Installer data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_tarma_section_fields[] = {
    SX_FIELD("unknown","byte[16]",0,16,SX_NONE),
    SX_FIELD("signature","char[4]",16,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint16",20,2,SX_ID),
    SX_FIELD("major_version","uint16",22,2,SX_ID),
    SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
    SX_FIELD("section_size","uint64",32,8,SX_SIZE),
    SX_FIELD("reserved2","byte[8]",40,8,SX_RESERVED),
    SX_FIELD("database_identifier","byte[16]",48,16,SX_NONE),
    SX_FIELD("check_word_a","uint32",64,4,SX_NONE),
    SX_FIELD("check_word_b","uint32",68,4,SX_NONE),
};
const sx_layout sxil_tarma_section = {0x60850035U,"tarma_section",sxil_tarma_section_fields,SX_COUNT(sxil_tarma_section_fields),SX_LE};
static const xx_data_struct_field_desc sxil_tarma_lzma_properties_fields[] = {
    SX_FIELD("properties","uint8",0,1,SX_NONE),
    SX_FIELD("dictionary_size","uint32",1,4,SX_SIZE),
};
const sx_layout sxil_tarma_lzma_properties = {0x60850036U,"tarma_lzma_properties",sxil_tarma_lzma_properties_fields,SX_COUNT(sxil_tarma_lzma_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxil_tarma_separator_fields[] = {
    SX_FIELD("value","uint32",0,4,SX_NONE),
    SX_FIELD("complemented_value","uint32",4,4,SX_NONE),
    SX_FIELD("reserved","uint64",8,8,SX_RESERVED),
};
const sx_layout sxil_tarma_separator = {0x60850037U,"tarma_separator",sxil_tarma_separator_fields,SX_COUNT(sxil_tarma_separator_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_tarma(sx_context*c){uint64_t p;if(!sxil_pe(c,&p))return true;for(size_t k=0;k<100000&&sxil_span(c,p,72);k++){uint8_t b[72];if(!sxil_read(c,p,b,72))return true;
 if(xx_rt_memcmp(b+16,"tiz3",4)){if(sxil32(b,false)==~sxil32(b+4,false)&&!sxil32(b+8,false)&&!sxil32(b+12,false)){if(!SXIL_ADD(c,tarma_separator,p))return false;p+=16;continue;}return true;}
 if(!SXIL_ADD(c,tarma_section,p))return false;uint64_t z=(uint64_t)sxil32(b+32,false)|((uint64_t)sxil32(b+36,false)<<32);if(z<77||!sxil_span(c,p,77))return true;if(!SXIL_ADD(c,tarma_lzma_properties,p+72))return false;if(!sxil_span(c,p,z))return true;p+=z;}return true;}
bool sx_tarma_installer_build(sx_context*c)
{
 return sxil_tarma(c);
}
#undef SXIL_ADD
