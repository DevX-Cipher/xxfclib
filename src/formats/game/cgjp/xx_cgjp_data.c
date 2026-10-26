/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CGJP data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_cgjp_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxan_cgjp_signature = {UINT32_C(0x60770037),"cgjp_signature",sxan_cgjp_signature_fields,SX_COUNT(sxan_cgjp_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_cgjp_block_fields[] = {
 SX_FIELD("uncompressed_size","uint16",0,2,SX_SIZE),
 SX_FIELD("compressed_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxan_cgjp_block = {UINT32_C(0x60770038),"cgjp_block",sxan_cgjp_block_fields,SX_COUNT(sxan_cgjp_block_fields),SX_LE};
static bool sxan_cgjp(sx_context*c){uint64_t p=0,z,plain;uint8_t h[4];while(sxan_read(c,p,h,4)){if(!xx_rt_memcmp(h,"CGJP",4)){if(!sxan_add(c,&sxan_cgjp_signature,p))return false;p+=4;continue;}plain=sxan_uint(h,2,false);z=sxan_uint(h+2,2,false);if(!plain||plain>32768||z>32768||!sxan_add(c,&sxan_cgjp_block,p))return false;p+=4;if(!z)z=plain;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_cgjp_build(sx_context*c)
{
bool ok=false;
ok=sxan_cgjp(c);
(void)ok;return c->count&&sxan_finish(c);
}
