/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LHSFX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_lhsfx_control_fields[]={
 SX_FIELD("control","uint32",0,4,SX_NONE),
};
const sx_layout sxaend_lhsfx_control={UINT32_C(0x60840007),"lhsfx_control",sxaend_lhsfx_control_fields,SX_COUNT(sxaend_lhsfx_control_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhsfx_member_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown_8","uint8[4]",8,4,SX_NONE),
 SX_FIELD("name","char[48]",12,48,SX_STRING),
};
const sx_layout sxaend_lhsfx_member={UINT32_C(0x60840008),"lhsfx_member",sxaend_lhsfx_member_fields,SX_COUNT(sxaend_lhsfx_member_fields),SX_BE};
#define SXAEND_LIMIT 20000U
static bool sxaend_lhsfx(sx_context*c){uint64_t p=0x918,z,t;for(unsigned i=0;i<SXAEND_LIMIT;i++){if(!sxaend_word(c,p,4,true,&t)||!sxaend_add(c,&sxaend_lhsfx_control,p))return false;p+=4;if(t==UINT32_MAX)return true;if(!sxaend_add(c,&sxaend_lhsfx_member,p)||!sxaend_word(c,p+4,4,true,&z)||!sxaend_span(c,p+60,z))return false;p+=60+z;}return true;}
bool sx_lhsfx_build(sx_context*c)
{
 return sxaend_lhsfx(c);
}
