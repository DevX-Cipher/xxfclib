/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * daemon_tools_mdx data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_mds2_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("copyright","char[26]",18,26,SX_NONE),
    SX_FIELD("key_header_offset","uint32",44,4,SX_OFFSET),
};
const sx_layout sxdleg_mds2_header = {0x60750007U,"mds2_header",sxdleg_mds2_header_fields,SX_COUNT(sxdleg_mds2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_mdx_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("copyright","char[26]",18,26,SX_NONE),
    SX_FIELD("mdx_marker","uint32",44,4,SX_ID),
    SX_FIELD("descriptor_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("descriptor_span","uint64",56,8,SX_SIZE),
};
const sx_layout sxdleg_mdx_header = {0x60750008U,"mdx_header",sxdleg_mdx_header_fields,SX_COUNT(sxdleg_mdx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_mdx_key_salt_fields[] = {
    SX_FIELD("salt","byte[64]",0,64,SX_NONE),
};
const sx_layout sxdleg_mdx_key_salt = {0x60750009U,"mdx_key_salt",sxdleg_mdx_key_salt_fields,SX_COUNT(sxdleg_mdx_key_salt_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static uint64_t sxdleg64(const uint8_t*b){return (uint64_t)sxdleg32(b+4,0)<<32|sxdleg32(b,0);}
static bool sxdleg_mdx(sx_context*c){uint8_t h[64];if(!sxdleg_read(c,0,h,48)||xx_rt_memcmp(h,"MEDIA DESCRIPTOR",16)||h[16]!=2)return false;uint64_t key=sxdleg32(h+44,0);if(key==UINT32_MAX){if(!sxdleg_read(c,48,h+48,16)||!SXDLEG_ADD(c,mdx_header,0))return false;uint64_t p=sxdleg64(h+48),n=sxdleg64(h+56);if(p<64||n<=64||n>16777280||!sxdleg_span(c,p,n)||!sxdleg_span(c,p+n-64,512))return true;key=p+n-64;
 }else if(!SXDLEG_ADD(c,mds2_header,0))return false;if(key>=48&&sxdleg_span(c,key,512))return SXDLEG_ADD(c,mdx_key_salt,key);return true;}
#undef SXDLEG_ADD
bool sx_daemon_tools_mdx_build(sx_context*c)
{
 return sxdleg_mdx(c);
}
