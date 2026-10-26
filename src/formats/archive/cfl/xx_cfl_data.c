/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CFL (version 3) archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_cfl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("directory_unpacked_size","int32",8,4,SX_SIZE),
};
const sx_layout sxag_cfl_header = {UINT32_C(0x60250022),"cfl_header",sxag_cfl_header_fields,SX_COUNT(sxag_cfl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_directory_block_fields[] = {
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("packed_size","int32",4,4,SX_SIZE),
};
const sx_layout sxag_cfl_directory_block = {UINT32_C(0x60250023),"cfl_directory_block",sxag_cfl_directory_block_fields,SX_COUNT(sxag_cfl_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_directory_size_fields[] = {
 SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
};
const sx_layout sxag_cfl_directory_size = {UINT32_C(0x60250024),"cfl_directory_size",sxag_cfl_directory_size_fields,SX_COUNT(sxag_cfl_directory_size_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_entry_fields[] = {
 SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
 SX_FIELD("data_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("method","uint16",8,2,SX_ID),
 SX_FIELD("unused","uint16",10,2,SX_NONE),
 SX_FIELD("name_size","uint16",12,2,SX_SIZE),
};
const sx_layout sxag_cfl_entry = {UINT32_C(0x60250025),"cfl_entry",sxag_cfl_entry_fields,SX_COUNT(sxag_cfl_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_member_block_fields[] = {
 SX_FIELD("block_size","int32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
const sx_layout sxag_cfl_member_block = {UINT32_C(0x60250026),"cfl_member_block",sxag_cfl_member_block_fields,SX_COUNT(sxag_cfl_member_block_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_cfl_member_blocks(sx_context *c){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(xx_archive_record_get_meta_u64(r,XX_META_ID_COMPRESSION_METHOD,UINT64_MAX)==1&&r->data_offset>=c->f->base_address&&r->data_offset-c->f->base_address>=10){uint64_t p=(uint64_t)(r->data_offset-c->f->base_address)-10;uint8_t b[8];if(sxag_read(c,p,b,8)&&!sxag_add(c,&sxag_cfl_member_block,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxag_cfl(sx_context *c){uint8_t b[14];if(!sxag_read(c,0,b,12)||!sxag_add(c,&sxag_cfl_header,0))return false;uint64_t p=sxag32(b+4,false);if(p<12||!sxag_read(c,p,b,8))return true;uint64_t method=sxag32(b,false),n=sxag32(b+4,false);if(method>1||n>INT32_MAX||!sxag_span(c,p+8,n))return true;if(!sxag_add(c,&sxag_cfl_directory_block,p))return false;p+=8;
 if(method){if(n>=4&&!sxag_add(c,&sxag_cfl_directory_size,p))return false;return sxag_cfl_member_blocks(c);}uint64_t end=p+n;for(unsigned i=0;i<SXAG_LIMIT&&end-p>=14;i++){if(!sxag_read(c,p,b,14))break;uint64_t z=sxag16(b+12,false),data=sxag32(b+4,false),plain=sxag32(b,false);if(!z||z>end-p-14||data<12||data>INT32_MAX||plain>INT32_MAX)break;if(!sxag_add(c,&sxag_cfl_entry,p))return false;p+=14+z;}return sxag_cfl_member_blocks(c);}
bool sx_cfl_build(sx_context*c)
{
 return sxag_cfl(c);
}
