/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PPMD data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_ppmd_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("model_info","uint16",8,2,SX_FLAGS),
 SX_FIELD("name_size_and_restore","uint16",10,2,SX_NONE),
 SX_FIELD("modified","uint32",12,4,SX_NONE),
};
const sx_layout sxal_ppmd_header = {UINT32_C(0x60200033),"ppmd_header",sxal_ppmd_header_fields,SX_COUNT(sxal_ppmd_header_fields),SX_LE};
static bool sxal_ppmd(sx_context *c){if(!sxal_add(c,&sxal_ppmd_header,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;
 xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;uint64_t last=0;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>c->f->base_address){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);uint8_t b[16];if(p>last&&sxal_read(c,p,b,16)&&sxal32(b,false)==0x84acaf8fU){if(!sxal_add(c,&sxal_ppmd_header,p)){ok=false;break;}last=p;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_ppmd_build(sx_context*c)
{
 return sxal_ppmd(c);
}
