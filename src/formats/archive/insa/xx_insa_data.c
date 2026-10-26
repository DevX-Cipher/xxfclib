/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * INSA data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_insa_version_fields[] = {
 SX_FIELD("version","uint16",0,2,SX_NONE),
};
const sx_layout sxaf_insa_version = {UINT32_C(0x603c002d),"insa_version",sxaf_insa_version_fields,SX_COUNT(sxaf_insa_version_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_insa_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxaf_insa_member = {UINT32_C(0x603c002e),"insa_member",sxaf_insa_member_fields,SX_COUNT(sxaf_insa_member_fields),SX_LE};
static bool sxaf_insa(sx_context*c){if(!sxaf_add(c,&sxaf_insa_version,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<1024;i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==4&&r->data_offset==r->header_offset+4&&r->compressed_size>=0){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(!sxaf_span(c,p+4,(uint64_t)r->compressed_size)||!sxaf_add(c,&sxaf_insa_member,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_insa_build(sx_context*c)
{
 return sxaf_insa(c);
}
