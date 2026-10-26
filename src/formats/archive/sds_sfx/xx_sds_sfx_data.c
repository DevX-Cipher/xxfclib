/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SDS_SFX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_sds_sfx_member_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_STRING),
 SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("data_checksum","uint16",28,2,SX_CHECKSUM),
};
const sx_layout sxaend_sds_sfx_member={UINT32_C(0x60840003),"sds_sfx_member",sxaend_sds_sfx_member_fields,SX_COUNT(sxaend_sds_sfx_member_fields),SX_BE};
#define SXAEND_LIMIT 20000U
static bool sxaend_sds(sx_context*c){uint64_t p=0x41c;for(unsigned i=0;i<SXAEND_LIMIT;i++){uint8_t h[30];if(!sxaend_read(c,p,h,30)||!sxaend_add(c,&sxaend_sds_sfx_member,p))return false;if(!h[0])return true;uint64_t z=sxaend_uint(h+20,4,true);if(!sxaend_span(c,p+30,z))return false;p+=30+z;}return true;}
bool sx_sds_sfx_build(sx_context*c)
{
 return sxaend_sds(c);
}
