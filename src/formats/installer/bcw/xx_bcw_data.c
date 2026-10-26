/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BCW data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_bcw_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxao_bcw_header = {UINT32_C(0x60700021),"bcw_header",sxao_bcw_header_fields,SX_COUNT(sxao_bcw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bcw_record_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_NONE),
};
const sx_layout sxao_bcw_record = {UINT32_C(0x60700022),"bcw_record",sxao_bcw_record_fields,SX_COUNT(sxao_bcw_record_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bcw_time_fields[] = {
 SX_FIELD("dos_date","uint16",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
};
const sx_layout sxao_bcw_time = {UINT32_C(0x60700023),"bcw_time",sxao_bcw_time_fields,SX_COUNT(sxao_bcw_time_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_bcw(sx_context*c){if(!sxao_add(c,&sxao_bcw_header,0))return false;xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;uint64_t p=4;bool ok=true;while(p<(uint64_t)c->size&&c->count<SXAO_LIMIT){uint64_t kind,name;if(!sxao_word(c,p,1,false,&kind)||kind>3||!sxao_add(c,&sxao_bcw_record,p++)){ok=false;break;}if(!kind)break;if(kind==3)continue;if(!sxao_zlen(c,p,(uint64_t)c->size,&name)||!sxao_text(c,&sxao_archiveobsolete_name,p,name,false)){ok=false;break;}p+=name;if(kind==2)continue;if(!sxao_add(c,&sxao_bcw_time,p)){ok=false;break;}p+=4;const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);if(!r||r->data_offset<c->f->base_address||r->compressed_size<0||(uint64_t)(r->data_offset-c->f->base_address)!=p||!sxao_span(c,p,(uint64_t)r->compressed_size)){ok=false;break;}p+=(uint64_t)r->compressed_size;(void)xx_format_archive_record_move_to_next(c->f,s,c->pd);}xx_format_free_archive_records_reading(c->f,s);return ok;}
bool sx_bcw_build(sx_context*c)
{
 return sxao_bcw(c);
}
