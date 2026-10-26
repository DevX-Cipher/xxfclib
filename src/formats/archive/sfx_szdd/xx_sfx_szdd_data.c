/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx szdd data structures, moved out of the carriermeta schema family. */
#include "../../xx_format_schema_carriermeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_cm_sfx_szdd_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("compression_mode","uint8",8,1,SX_ID),
    SX_FIELD("original_last_character","uint8",9,1,SX_NONE),
    SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
const sx_layout sx_cm_sfx_szdd_header = {0x60240001U,"sfx_szdd_header",sx_cm_sfx_szdd_header_fields,SX_COUNT(sx_cm_sfx_szdd_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_cm_sfx_szdd_legacy_header_fields[] = {
    SX_FIELD("magic","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("compression_mode","uint8",7,1,SX_ID),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sx_cm_sfx_szdd_legacy_header = {0x60240002U,"sfx_szdd_legacy_header",sx_cm_sfx_szdd_legacy_header_fields,SX_COUNT(sx_cm_sfx_szdd_legacy_header_fields),SX_LE};
static bool sx_cm_szdd(sx_context*c){xx_archive_record_state*s=sx_cm_records(c);if(!s)return false;const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);bool ok=false;
 if(r&&r->data_offset>=c->f->base_address&&r->compressed_size>=14){int64_t p=r->data_offset-c->f->base_address;uint8_t h[14];if(sx_cm_span(c,p,(uint64_t)r->compressed_size)&&sx_cm_read(c,p,h,14)){
  if(!xx_rt_memcmp(h,"SZDD\x88\xf0\x27\x33",8)&&h[8]=='A')ok=sx_cm_add(c,&sx_cm_sfx_szdd_header,p,14);
  else if(!xx_rt_memcmp(h,"ZDD\x88\xf0\x27\x33" "A",8))ok=sx_cm_add(c,&sx_cm_sfx_szdd_legacy_header,p,12);
 }}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_sfx_szdd_build(sx_context*c)
{
 return sx_cm_szdd(c);
}
