/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EGG archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_egg_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("header_id","uint32",6,4,SX_ID),
    SX_FIELD("reserved","uint32",10,4,SX_RESERVED),
    SX_FIELD("terminator","uint32",14,4,SX_SIGNATURE),
};
const sx_layout sxar_egg_header = {UINT32_C(0x601c0021),"egg_header",sxar_egg_header_fields,SX_COUNT(sxar_egg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_file_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("file_id","uint32",4,4,SX_ID),
    SX_FIELD("unpacked_size","uint64",8,8,SX_SIZE),
};
const sx_layout sxar_egg_file = {UINT32_C(0x601c0022),"egg_file",sxar_egg_file_fields,SX_COUNT(sxar_egg_file_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_extra_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_size","uint16",5,2,SX_SIZE),
};
const sx_layout sxar_egg_extra = {UINT32_C(0x601c0023),"egg_extra",sxar_egg_extra_fields,SX_COUNT(sxar_egg_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_block_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("method","uint8",4,1,SX_ID),
    SX_FIELD("encryption","uint8",5,1,SX_ID),
    SX_FIELD("unpacked_size","uint32",6,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
    SX_FIELD("terminator","uint32",18,4,SX_SIGNATURE),
};
const sx_layout sxar_egg_block = {UINT32_C(0x601c0024),"egg_block",sxar_egg_block_fields,SX_COUNT(sxar_egg_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_end_fields[] = {
    SX_FIELD("terminator","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxar_egg_end = {UINT32_C(0x601c0025),"egg_end",sxar_egg_end_fields,SX_COUNT(sxar_egg_end_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_egg(sx_context *c){uint8_t b[22];if(!sxar_read(c,0,b,18)||!sxar_add(c,&sxar_egg_header,0))return false;uint64_t p=18;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,4))break;uint32_t tag=sxar32(b,false);uint64_t n=0;const sx_layout *l=NULL;
 if(tag==0x08e28222){l=&sxar_egg_end;n=4;}else if(tag==0x0a8590e3){l=&sxar_egg_file;n=16;}else if(tag==0x0a8591ac||tag==0x04c63672){if(!sxar_read(c,p,b,7))break;l=&sxar_egg_extra;n=7+(uint64_t)sxar16(b+5,false);}else if(tag==0x02b50c13){if(!sxar_read(c,p,b,22))break;l=&sxar_egg_block;n=22+(uint64_t)sxar32(b+10,false);}else break;
 if(!sxar_span(c,p,n))break;if(!sxar_add(c,l,p))return false;p+=n;}return true;}
bool sx_egg_build(sx_context*c)
{
 return sxar_egg(c);
}
