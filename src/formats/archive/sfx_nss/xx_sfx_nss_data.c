/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFX NSS data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_nss_member_fields[]={
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("unknown_10","uint8[14]",10,14,SX_NONE),
 SX_FIELD("compression","uint16",24,2,SX_ID),
 SX_FIELD("unknown_26","uint8[4]",26,4,SX_NONE),
 SX_FIELD("signature","char[8]",30,8,SX_SIGNATURE),
 SX_FIELD("initialization_vector","uint8[8]",38,8,SX_NONE),
 SX_FIELD("name","char[256]",46,256,SX_STRING),
 SX_FIELD("unknown_302","uint8[14]",302,14,SX_NONE),
};
const sx_layout sxaend_nss_member={UINT32_C(0x6084001b),"nss_member",sxaend_nss_member_fields,SX_COUNT(sxaend_nss_member_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_nss(sx_context*c){uint8_t h[64];if(!sxaend_read(c,0,h,64)||h[0]!='M'||h[1]!='Z')return false;uint64_t pages=sxaend_uint(h+4,2,false),last=sxaend_uint(h+2,2,false);if(!pages||last>511)return false;uint64_t p=(pages-1)*512+(last?last:512);for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){uint8_t b[316];if(!sxaend_read(c,p,b,316)||sxaend_uint(b,2,false)!=316||xx_rt_memcmp(b+30,"CCRITTER",8)||!sxaend_add(c,&sxaend_nss_member,p))return false;uint64_t z=sxaend_uint(b+2,4,false);if(!z||!sxaend_span(c,p+316,z))return false;p+=316+z;}return true;}
bool sx_sfx_nss_build(sx_context*c)
{
 return sxaend_nss(c);
}
