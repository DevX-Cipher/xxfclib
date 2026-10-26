/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PowerBoard BBS data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_powerbbs_name_fields[] = {
 SX_FIELD("encoded_name_length","uint8",0,1,SX_NONE),
};
const sx_layout sxasy_powerbbs_name = {UINT32_C(0x6044000c),"powerbbs_name",sxasy_powerbbs_name_fields,SX_COUNT(sxasy_powerbbs_name_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size1_fields[] = {
 SX_FIELD("payload_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxasy_powerbbs_size1 = {UINT32_C(0x6044000d),"powerbbs_size1",sxasy_powerbbs_size1_fields,SX_COUNT(sxasy_powerbbs_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size2_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxasy_powerbbs_size2 = {UINT32_C(0x6044000e),"powerbbs_size2",sxasy_powerbbs_size2_fields,SX_COUNT(sxasy_powerbbs_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size4_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxasy_powerbbs_size4 = {UINT32_C(0x6044000f),"powerbbs_size4",sxasy_powerbbs_size4_fields,SX_COUNT(sxasy_powerbbs_size4_fields),SX_LE};
/* The native backtracking parser is authoritative for ambiguous 16/32-bit sizes. */
static bool sxasy_power(sx_context*c){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return false;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXASY_LIMIT;i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;uint8_t lead;uint64_t p,ns,width;if(r->header_offset<c->f->base_address||r->header_size<5||r->compressed_size<0||r->data_offset!=r->header_offset+r->header_size){ok=false;break;}p=(uint64_t)(r->header_offset-c->f->base_address);if(!sxasy_read(c,p,&lead,1)){ok=false;break;}ns=(lead>=11&&lead<=18?lead-10:lead)+3;width=(uint64_t)r->header_size-1-ns;if(!((lead>=11&&lead<=18&&width==1)||(lead>=1&&lead<=8&&(width==2||width==4)))||!sxasy_span(c,p,(uint64_t)r->header_size+(uint64_t)r->compressed_size)||!sxasy_add(c,&sxasy_powerbbs_name,p)||!sxasy_add(c,width==1?&sxasy_powerbbs_size1:width==2?&sxasy_powerbbs_size2:&sxasy_powerbbs_size4,p+1+ns)){ok=false;break;}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_powerboardbbs_build(sx_context*c)
{
 return sxasy_power(c);
}
