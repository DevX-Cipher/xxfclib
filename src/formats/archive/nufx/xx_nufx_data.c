/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NuFX (ShrinkIt) archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_nufx_master_fields[] = {
    SX_FIELD("magic","uint8[6]",0,6,SX_SIGNATURE),
    SX_FIELD("master_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("record_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("created_second","uint8",12,1,SX_NONE),
    SX_FIELD("created_minute","uint8",13,1,SX_NONE),
    SX_FIELD("created_hour","uint8",14,1,SX_NONE),
    SX_FIELD("created_year_since_1900","uint8",15,1,SX_NONE),
    SX_FIELD("created_day_zero_based","uint8",16,1,SX_NONE),
    SX_FIELD("created_month_zero_based","uint8",17,1,SX_NONE),
    SX_FIELD("created_reserved","uint8",18,1,SX_RESERVED),
    SX_FIELD("created_weekday","uint8",19,1,SX_ID),
    SX_FIELD("modified_second","uint8",20,1,SX_NONE),
    SX_FIELD("modified_minute","uint8",21,1,SX_NONE),
    SX_FIELD("modified_hour","uint8",22,1,SX_NONE),
    SX_FIELD("modified_year_since_1900","uint8",23,1,SX_NONE),
    SX_FIELD("modified_day_zero_based","uint8",24,1,SX_NONE),
    SX_FIELD("modified_month_zero_based","uint8",25,1,SX_NONE),
    SX_FIELD("modified_reserved","uint8",26,1,SX_RESERVED),
    SX_FIELD("modified_weekday","uint8",27,1,SX_ID),
    SX_FIELD("version","uint16",28,2,SX_ID),
    SX_FIELD("reserved30","uint8[8]",30,8,SX_RESERVED),
    SX_FIELD("archive_size","uint32",38,4,SX_SIZE),
    SX_FIELD("reserved42","uint8[6]",42,6,SX_RESERVED),
};
const sx_layout sxar_nufx_master = {UINT32_C(0x601c0012),"nufx_master",sxar_nufx_master_fields,SX_COUNT(sxar_nufx_master_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_record_fields[] = {
    SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_crc16","uint16",4,2,SX_CHECKSUM),
    SX_FIELD("attribute_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint16",8,2,SX_ID),
    SX_FIELD("thread_count","uint32",10,4,SX_COUNT_PROP),
    SX_FIELD("filesystem_id","uint16",14,2,SX_ID),
    SX_FIELD("filesystem_info","uint16",16,2,SX_NONE),
    SX_FIELD("access","uint32",18,4,SX_FLAGS),
    SX_FIELD("file_type","uint32",22,4,SX_ID),
    SX_FIELD("auxiliary_type_or_block_count","uint32",26,4,SX_NONE),
    SX_FIELD("storage_type_or_block_size","uint16",30,2,SX_NONE),
    SX_FIELD("created_second","uint8",32,1,SX_NONE),
    SX_FIELD("created_minute","uint8",33,1,SX_NONE),
    SX_FIELD("created_hour","uint8",34,1,SX_NONE),
    SX_FIELD("created_year_since_1900","uint8",35,1,SX_NONE),
    SX_FIELD("created_day_zero_based","uint8",36,1,SX_NONE),
    SX_FIELD("created_month_zero_based","uint8",37,1,SX_NONE),
    SX_FIELD("created_reserved","uint8",38,1,SX_RESERVED),
    SX_FIELD("created_weekday","uint8",39,1,SX_ID),
    SX_FIELD("modified_second","uint8",40,1,SX_NONE),
    SX_FIELD("modified_minute","uint8",41,1,SX_NONE),
    SX_FIELD("modified_hour","uint8",42,1,SX_NONE),
    SX_FIELD("modified_year_since_1900","uint8",43,1,SX_NONE),
    SX_FIELD("modified_day_zero_based","uint8",44,1,SX_NONE),
    SX_FIELD("modified_month_zero_based","uint8",45,1,SX_NONE),
    SX_FIELD("modified_reserved","uint8",46,1,SX_RESERVED),
    SX_FIELD("modified_weekday","uint8",47,1,SX_ID),
    SX_FIELD("archived_second","uint8",48,1,SX_NONE),
    SX_FIELD("archived_minute","uint8",49,1,SX_NONE),
    SX_FIELD("archived_hour","uint8",50,1,SX_NONE),
    SX_FIELD("archived_year_since_1900","uint8",51,1,SX_NONE),
    SX_FIELD("archived_day_zero_based","uint8",52,1,SX_NONE),
    SX_FIELD("archived_month_zero_based","uint8",53,1,SX_NONE),
    SX_FIELD("archived_reserved","uint8",54,1,SX_RESERVED),
    SX_FIELD("archived_weekday","uint8",55,1,SX_ID),
};
const sx_layout sxar_nufx_record = {UINT32_C(0x601c0013),"nufx_record",sxar_nufx_record_fields,SX_COUNT(sxar_nufx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_option_size_fields[] = {
    SX_FIELD("option_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxar_nufx_option_size = {UINT32_C(0x601c0014),"nufx_option_size",sxar_nufx_option_size_fields,SX_COUNT(sxar_nufx_option_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_name_size_fields[] = {
    SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxar_nufx_name_size = {UINT32_C(0x601c0015),"nufx_name_size",sxar_nufx_name_size_fields,SX_COUNT(sxar_nufx_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_thread_fields[] = {
    SX_FIELD("thread_class","uint16",0,2,SX_ID),
    SX_FIELD("method","uint16",2,2,SX_ID),
    SX_FIELD("thread_kind","uint16",4,2,SX_ID),
    SX_FIELD("thread_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxar_nufx_thread = {UINT32_C(0x601c0016),"nufx_thread",sxar_nufx_thread_fields,SX_COUNT(sxar_nufx_thread_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_nufx(sx_context *c){uint8_t b[58];if(!sxar_read(c,0,b,48)||!sxar_add(c,&sxar_nufx_master,0))return false;uint32_t n=sxar32(b+8,false);uint64_t p=48;if(n>SXAR_LIMIT)return true;
 for(uint32_t i=0;i<n;i++){if(!sxar_read(c,p,b,56))break;uint16_t size=sxar16(b+6,false),v=sxar16(b+8,false),name;uint32_t threads=sxar32(b+10,false);if(size<(v?60:58)||size>4096||threads>SXAR_LIMIT||!sxar_span(c,p,size))break;
  if(!sx_u16(c,(int64_t)p+size-2,false,&name)||!sxar_span(c,p+size,name+(uint64_t)threads*16))break;
  if(!sxar_add(c,&sxar_nufx_record,p)||(v&&!sxar_add(c,&sxar_nufx_option_size,p+56))||!sxar_add(c,&sxar_nufx_name_size,p+size-2))return false;
  uint64_t table=p+size+name;if(threads&&!sx_table(c,&sxar_nufx_thread,(int64_t)table,16,threads))return false;p=table+(uint64_t)threads*16;
  for(uint32_t j=0;j<threads;j++){uint32_t z;if(!sx_u32(c,(int64_t)(table+(uint64_t)j*16+12),false,&z)||!sxar_span(c,p,z))return true;p+=z;}
 }return true;}
bool sx_nufx_build(sx_context*c)
{
 return sxar_nufx(c);
}
