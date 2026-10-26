/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Msx Cas data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_msx_cas_binary_header_fields[] = {
    SX_FIELD("marker","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("binary_file_marker","byte[10]",8,10,SX_SIGNATURE),
    SX_FIELD("filename","char[6]",18,6,SX_NONE),
    SX_FIELD("data_marker","byte[8]",24,8,SX_SIGNATURE),
    SX_FIELD("load_address","uint16",32,2,SX_ADDRESS),
    SX_FIELD("inclusive_end_address","uint16",34,2,SX_ADDRESS),
    SX_FIELD("execution_address","uint16",36,2,SX_ADDRESS),
};
const sx_layout sxdn_msx_cas_binary_header = {0x60780002U,"msx_cas_binary_header",sxdn_msx_cas_binary_header_fields,SX_COUNT(sxdn_msx_cas_binary_header_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_msx(sx_context*c){uint64_t p=0;for(unsigned i=0;i<1024&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;i++){uint8_t h[38];if(!sxdn_read(c,p,h,38))break;uint64_t start=sxdn16(h+32,0),end=sxdn16(h+34,0);if(end<start||!SXDN_ADD(c,msx_cas_binary_header,p)||!sxdn_span(c,p+38,end-start+1))break;p+=38+end-start+1;uint8_t b;while(p<(uint64_t)c->size&&sxdn_read(c,p,&b,1)&&b==0)p++;}return c->count!=0;}
bool sx_msx_cas_build(sx_context*c)
{
 return sxdn_msx(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
