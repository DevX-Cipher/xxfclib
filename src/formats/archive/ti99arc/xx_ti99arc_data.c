/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TI-99/4A ARC (.ARK) archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_ti99_tifiles_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("sector_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",12,1,SX_NONE),
 SX_FIELD("record_size","uint8",13,1,SX_SIZE),
};
const sx_layout sxag_ti99_tifiles = {UINT32_C(0x60250010),"ti99_tifiles",sxag_ti99_tifiles_fields,SX_COUNT(sxag_ti99_tifiles_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_fiad_fields[] = {
 SX_FIELD("name","char[10]",0,10,SX_STRING),
 SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
 SX_FIELD("flags","uint8",12,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",16,1,SX_NONE),
 SX_FIELD("record_size","uint8",17,1,SX_SIZE),
};
const sx_layout sxag_ti99_fiad = {UINT32_C(0x60250011),"ti99_fiad",sxag_ti99_fiad_fields,SX_COUNT(sxag_ti99_fiad_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_record_count_fields[] = {
 SX_FIELD("record_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxag_ti99_record_count = {UINT32_C(0x60250012),"ti99_record_count",sxag_ti99_record_count_fields,SX_COUNT(sxag_ti99_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ti99_fiad_times_fields[] = {
 SX_FIELD("created","uint8[4]",0,4,SX_NONE),
 SX_FIELD("modified","uint8[4]",4,4,SX_NONE),
 SX_FIELD("reserved","uint8[100]",8,100,SX_RESERVED),
};
const sx_layout sxag_ti99_fiad_times = {UINT32_C(0x60250013),"ti99_fiad_times",sxag_ti99_fiad_times_fields,SX_COUNT(sxag_ti99_fiad_times_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ti99_entry_fields[] = {
 SX_FIELD("name","char[10]",0,10,SX_STRING),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("sector_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",14,1,SX_NONE),
 SX_FIELD("record_size","uint8",15,1,SX_SIZE),
};
const sx_layout sxag_ti99_entry = {UINT32_C(0x60250014),"ti99_entry",sxag_ti99_entry_fields,SX_COUNT(sxag_ti99_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_catalog_end_fields[] = {
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxag_ti99_catalog_end = {UINT32_C(0x60250015),"ti99_catalog_end",sxag_ti99_catalog_end_fields,SX_COUNT(sxag_ti99_catalog_end_fields),SX_LE};
static bool sxag_ti99(sx_context *c){uint8_t b[128];uint64_t p=0;bool compressed=false;if(!sxag_read(c,0,b,128))return false;
 if(!xx_rt_memcmp(b,"\7TIFILES",8)){if(!sxag_add(c,&sxag_ti99_tifiles,0)||!sxag_add(c,&sxag_ti99_record_count,14))return false;compressed=(b[10]&2)!=0;p=128;}
 else{bool fiad=b[10]==0&&b[11]==0&&sxag16(b+14,true)!=0;for(unsigned i=28;i<128&&fiad;i++)if(b[i])fiad=false;uint64_t size=(uint64_t)sxag16(b+14,true)*256+128;if(fiad&&size==(uint64_t)c->size){if(!sxag_add(c,&sxag_ti99_fiad,0)||!sxag_add(c,&sxag_ti99_record_count,18)||!sxag_add(c,&sxag_ti99_fiad_times,20))return false;compressed=(b[12]&2)!=0;p=128;}}
 if(compressed)return true;for(unsigned sector=0;sector<1024&&sxag_span(c,p,256);sector++,p+=256){for(unsigned i=0;i<14;i++){uint8_t e[18];uint64_t at=p+i*18;if(!sxag_read(c,at,e,18))return false;bool empty=true;for(unsigned j=0;j<18;j++)if(e[j])empty=false;if(empty)continue;if(!sxag_add(c,&sxag_ti99_entry,at)||!sxag_add(c,&sxag_ti99_record_count,at+16))return false;}if(!sxag_read(c,p+252,b,4)||!sxag_add(c,&sxag_ti99_catalog_end,p+252))return false;if(!xx_rt_memcmp(b,"END!",4))break;if(sxag32(b,false))break;}return c->count!=0;}
bool sx_ti99arc_build(sx_context*c)
{
 return sxag_ti99(c);
}
