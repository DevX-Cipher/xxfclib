/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMARC archives (John Fisher, Rice University) data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_vmarc_member_fields[] = {
 SX_FIELD("signature","uint8[9]",0,9,SX_SIGNATURE),
 SX_FIELD("unknown9","uint8",9,1,SX_NONE),
 SX_FIELD("name_ebcdic","uint8[8]",10,8,SX_STRING),
 SX_FIELD("type_ebcdic","uint8[8]",18,8,SX_STRING),
 SX_FIELD("unknown26","uint16",26,2,SX_NONE),
 SX_FIELD("logical_record_size","uint16",28,2,SX_SIZE),
 SX_FIELD("unknown30","uint8[6]",30,6,SX_NONE),
 SX_FIELD("record_format","uint8",36,1,SX_ID),
 SX_FIELD("flags","uint8",37,1,SX_FLAGS),
};
const sx_layout sxag_vmarc_member = {UINT32_C(0x6025000e),"vmarc_member",sxag_vmarc_member_fields,SX_COUNT(sxag_vmarc_member_fields),SX_BE};
static const xx_data_struct_field_desc sxag_vmarc_record_fields[] = {
 SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxag_vmarc_record = {UINT32_C(0x6025000f),"vmarc_record",sxag_vmarc_record_fields,SX_COUNT(sxag_vmarc_record_fields),SX_BE};
#define SXAG_LIMIT 20000U
static bool sxag_vmarc_stored(sx_context *c,uint64_t p,uint64_t end){uint8_t b[2];for(unsigned i=0;i<SXAG_LIMIT&&p+2<=end;i++){if(!sxag_read(c,p,b,2))break;unsigned n=sxag16(b,true);if(n>end-p-2)break;if(!sxag_add(c,&sxag_vmarc_record,p))return false;p+=2+n;if(!n)break;}return true;}
static bool sxag_vmarc(sx_context *c){if(!sxag_add(c,&sxag_vmarc_member,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->data_offset>=r->header_offset&&r->compressed_size>=0){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address),data=(uint64_t)(r->data_offset-c->f->base_address),n=(uint64_t)r->compressed_size;uint8_t b[38];if(sxag_read(c,p,b,38)&&sxag_span(c,data,n)){if(!sxag_add(c,&sxag_vmarc_member,p)||((b[37]&64)&&!sxag_vmarc_stored(c,data,data+n))){ok=false;break;}}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_vmarc_build(sx_context*c)
{
 return sxag_vmarc(c);
}
