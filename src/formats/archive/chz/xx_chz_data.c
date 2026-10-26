/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ChArc archive data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_chz_file_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("record_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("opaque_metadata","uint8[8]",12,8,SX_NONE),
    SX_FIELD("method","uint8",20,1,SX_ID),
    SX_FIELD("unknown21","uint8",21,1,SX_NONE),
    SX_FIELD("name_size","uint16",22,2,SX_SIZE),
};
const sx_layout sxae_chz_file = {UINT32_C(0x60170024),"chz_file",sxae_chz_file_fields,SX_COUNT(sxae_chz_file_fields),SX_LE};
static const xx_data_struct_field_desc sxae_chz_directory_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_metadata","uint8[4]",4,4,SX_NONE),
    SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
    SX_FIELD("name_size","uint8",9,1,SX_SIZE),
};
const sx_layout sxae_chz_directory = {UINT32_C(0x60170025),"chz_directory",sxae_chz_directory_fields,SX_COUNT(sxae_chz_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxae_chz_directory_end_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxae_chz_directory_end = {UINT32_C(0x60170026),"chz_directory_end",sxae_chz_directory_end_fields,SX_COUNT(sxae_chz_directory_end_fields),SX_LE};
static bool sxae_chz(sx_context *c)
{
 int64_t p=0;uint8_t b[24];unsigned depth=0;for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,4))return false;uint32_t tag=sxae32(b);
 if(tag==UINT32_C(0x46684353)){if(!sx_read(c,p,b,24))return false;uint32_t z=sxae32(b+4);uint16_t n=sxae16(b+22);if(z<24u+n||!sxae_bound(c,p,z)||!sxae_add(c,&sxae_chz_file,p)||!sxae_data(c,p+24+n,z-24-n))return false;p+=z;}
 else if(tag==UINT32_C(0x44684353)){if(depth++>=64||!sx_read(c,p,b,10)||!sxae_bound(c,p,10u+b[9])||!sxae_add(c,&sxae_chz_directory,p))return false;p+=10+b[9];}
 else if(tag==UINT32_C(0x64684353)){if(!depth--||!sxae_add(c,&sxae_chz_directory_end,p))return false;p+=4;}
 else return false;}return p==c->size;
}
bool sx_chz_build(sx_context*c)
{
 return sxae_chz(c);
}
