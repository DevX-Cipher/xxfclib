/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * KPCK data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_kpck_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("method_flags","uint32",8,4,SX_FLAGS),
};
const sx_layout sxap_kpck_header = {UINT32_C(0x60720001),"kpck_header",sxap_kpck_header_fields,SX_COUNT(sxap_kpck_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kpck_filter_fields[] = {
 SX_FIELD("call_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("marker","uint8",4,1,SX_NONE),
};
const sx_layout sxap_kpck_filter = {UINT32_C(0x60720002),"kpck_filter",sxap_kpck_filter_fields,SX_COUNT(sxap_kpck_filter_fields),SX_LE};
static bool sxap_kpck(sx_context*c){uint64_t flags;if(!sxap_add(c,&sxap_kpck_header,0)||!sxap_word(c,8,4,false,&flags))return false;return !(flags&0xc0U)||c->size<17||sxap_add(c,&sxap_kpck_filter,(uint64_t)c->size-5);}
bool sx_kpck_build(sx_context*c)
{
 return sxap_kpck(c);
}
