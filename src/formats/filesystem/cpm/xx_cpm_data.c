/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CPM data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_cpm_extent16_fields[] = {
    SX_FIELD("user_or_status","uint8",0,1,SX_ID),
    SX_FIELD("filename_and_attributes","byte[8]",1,8,SX_NONE),
    SX_FIELD("extension_and_attributes","byte[3]",9,3,SX_NONE),
    SX_FIELD("extent_low","uint8",12,1,SX_NONE),
    SX_FIELD("s1","uint8",13,1,SX_NONE),
    SX_FIELD("extent_high","uint8",14,1,SX_NONE),
    SX_FIELD("record_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("allocation_blocks","uint16[8]",16,16,SX_NONE),
};
const sx_layout sxdt_cpm_extent16 = {0x607a000cU,"cpm_extent16",sxdt_cpm_extent16_fields,SX_COUNT(sxdt_cpm_extent16_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_cpm3_volume_label_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("label","char[11]",1,11,SX_NONE),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("password_and_reserved","byte[11]",13,11,SX_NONE),
    SX_FIELD("creation_days","uint16",24,2,SX_NONE),
    SX_FIELD("creation_hour_bcd","uint8",26,1,SX_NONE),
    SX_FIELD("creation_minute_bcd","uint8",27,1,SX_NONE),
    SX_FIELD("modification_days","uint16",28,2,SX_NONE),
    SX_FIELD("modification_hour_bcd","uint8",30,1,SX_NONE),
    SX_FIELD("modification_minute_bcd","uint8",31,1,SX_NONE),
};
const sx_layout sxdt_cpm3_volume_label = {0x607a0035U,"cpm3_volume_label",sxdt_cpm3_volume_label_fields,SX_COUNT(sxdt_cpm3_volume_label_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_cpm3_timestamp_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
};
const sx_layout sxdt_cpm3_timestamp_status = {0x607a0036U,"cpm3_timestamp_status",sxdt_cpm3_timestamp_status_fields,SX_COUNT(sxdt_cpm3_timestamp_status_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_cpm3_timestamp_record_fields[] = {
    SX_FIELD("first_stamp_days","uint16",0,2,SX_NONE),
    SX_FIELD("first_stamp_hour_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("first_stamp_minute_bcd","uint8",3,1,SX_NONE),
    SX_FIELD("modification_days","uint16",4,2,SX_NONE),
    SX_FIELD("modification_hour_bcd","uint8",6,1,SX_NONE),
    SX_FIELD("modification_minute_bcd","uint8",7,1,SX_NONE),
    SX_FIELD("password_mode","uint8",8,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",9,1,SX_RESERVED),
};
const sx_layout sxdt_cpm3_timestamp_record = {0x607a0037U,"cpm3_timestamp_record",sxdt_cpm3_timestamp_record_fields,SX_COUNT(sxdt_cpm3_timestamp_record_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_cpm3_timestamp_tail_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
};
const sx_layout sxdt_cpm3_timestamp_tail = {0x607a0038U,"cpm3_timestamp_tail",sxdt_cpm3_timestamp_tail_fields,SX_COUNT(sxdt_cpm3_timestamp_tail_fields),SX_LE};
#define SXDT_LIMIT 24000U
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
#if SX_ALIAS_READER_FACTORY && defined(CPM)
static bool sxdt_cpm(sx_context*c){
 if(c->f->create_archive_records_reading!=xx_cpm_create_archive_records_reading||c->f->free_archive_records_reading!=xx_cpm_free_archive_records_reading)return false;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return false;
 xx_cpm_directory_slot slot;bool ok=xx_cpm_get_directory_slot(c->f,s,0,&slot);uint32_t count=ok?slot.entry_count:0;
 for(uint32_t i=0;ok&&i<count&&c->count<SXDT_LIMIT;i++){
  if(xx_pd_is_stopped(c->pd)||!xx_cpm_get_directory_slot(c->f,s,i,&slot)||slot.offset<c->f->base_address){ok=false;break;}
  uint64_t p=(uint64_t)(slot.offset-c->f->base_address);uint8_t b[32];if(!sxdt_read(c,p,b,32)){ok=false;break;}
  if(b[0]==229)ok=SXDT_ADD(c,cpm_deleted_entry,p);
  else if(slot.version==XX_CPM_VERSION_3&&b[0]==32)ok=SXDT_ADD(c,cpm3_volume_label,p);
  else if(slot.version==XX_CPM_VERSION_3&&b[0]==33)ok=SXDT_ADD(c,cpm3_timestamp_status,p)&&SXDT_TABLE(c,cpm3_timestamp_record,p+1,3)&&SXDT_ADD(c,cpm3_timestamp_tail,p+31);
  else ok=sxdt_put(c,slot.allocation_pointer_size==1?&sxdt_cpm_extent8:&sxdt_cpm_extent16,p,1);
 }
 (c->f->free_archive_records_reading)(c->f,s);return ok&&c->count!=0;
}
#endif
bool sx_cpm_build(sx_context*c)
{
bool ok=false;
#if SX_ALIAS_READER_FACTORY && defined(CPM)
ok=sxdt_cpm(c);
#endif
return ok&&c->count&&sxdt_finish(c);
}
