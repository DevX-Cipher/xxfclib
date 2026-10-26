/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DCLMultiStream data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_dclraw_stream_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_selector","uint8",1,1,SX_NONE),
};
const sx_layout sxaend_dclraw_stream={UINT32_C(0x60840013),"dclraw_stream",sxaend_dclraw_stream_fields,SX_COUNT(sxaend_dclraw_stream_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_dcl(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXAEND_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset<f->base_address||r->compressed_size<2||!sxaend_span(c,(uint64_t)(r->header_offset-f->base_address),(uint64_t)r->compressed_size)||!sxaend_add(c,&sxaend_dclraw_stream,(uint64_t)(r->header_offset-f->base_address))){ok=false;break;}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
bool sx_dclraw_build(sx_context*c)
{
 return sxaend_dcl(c);
}
