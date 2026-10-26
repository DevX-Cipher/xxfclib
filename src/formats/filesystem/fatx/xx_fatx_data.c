/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Xbox FATX filesystem data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_fatx_superblock_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_directory_cluster","uint32",12,4,SX_NONE),
    SX_FIELD("partition_name","uint16[32]",16,64,SX_NONE),
};
const sx_layout sxdleg_fatx_superblock = {0x6075003cU,"fatx_superblock",sxdleg_fatx_superblock_fields,SX_COUNT(sxdleg_fatx_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_fatx_fat16_entry_fields[] = {
    SX_FIELD("next_cluster","uint16",0,2,SX_NONE),
};
const sx_layout sxdleg_fatx_fat16_entry = {0x6075003dU,"fatx_fat16_entry",sxdleg_fatx_fat16_entry_fields,SX_COUNT(sxdleg_fatx_fat16_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_fatx_fat32_entry_fields[] = {
    SX_FIELD("next_cluster","uint32",0,4,SX_NONE),
};
const sx_layout sxdleg_fatx_fat32_entry = {0x6075003eU,"fatx_fat32_entry",sxdleg_fatx_fat32_entry_fields,SX_COUNT(sxdleg_fatx_fat32_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_fatx_directory_entry_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("attributes","uint8",1,1,SX_FLAGS),
    SX_FIELD("name","char[42]",2,42,SX_NONE),
    SX_FIELD("first_cluster","uint32",44,4,SX_NONE),
    SX_FIELD("file_size","uint32",48,4,SX_SIZE),
    SX_FIELD("modification_time","uint16",52,2,SX_NONE),
    SX_FIELD("modification_date","uint16",54,2,SX_NONE),
    SX_FIELD("creation_time","uint16",56,2,SX_NONE),
    SX_FIELD("creation_date","uint16",58,2,SX_NONE),
    SX_FIELD("access_time","uint16",60,2,SX_NONE),
    SX_FIELD("access_date","uint16",62,2,SX_NONE),
};
const sx_layout sxdleg_fatx_directory_entry = {0x6075003fU,"fatx_directory_entry",sxdleg_fatx_directory_entry_fields,SX_COUNT(sxdleg_fatx_directory_entry_fields),SX_LE};
#define SXDLEG_LIMIT 24000U
static bool sxdleg_pow(uint64_t v){return v&&!(v&(v-1));}
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
/* Archive callbacks authenticate physical directory entry coordinates without
 * assuming that an Abstractformat is a specific native-reader allocation. */
static bool sxdleg_archive_entries(sx_context*c,const sx_layout*l,uint64_t width){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<65536&&c->count<SXDLEG_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==(int64_t)width){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(sxdleg_span(c,p,width)&&!sxdleg_put(c,l,p,1)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxdleg_fatx(sx_context*c){uint8_t h[16];if(!sxdleg_read(c,0,h,16)||xx_rt_memcmp(h,"FATX",4)||c->size<8704||!SXDLEG_ADD(c,fatx_superblock,0))return false;uint64_t sectors=sxdleg32(h+8,0);if(!sectors||sectors>1024||!sxdleg_pow(sectors))return true;uint64_t cb=sectors*512,nominal=(uint64_t)c->size/cb+1,width=nominal<0xfff0?2:4;if(nominal>UINT64_MAX/width)return true;uint64_t fat=(nominal*width+4095)&~UINT64_C(4095),data=4096+fat;if(data>=(uint64_t)c->size)return true;uint64_t n=((uint64_t)c->size-data)/cb+1;if(n>8000001||n>fat/width)return true;if(n>1048576)n=1048576;if(!sxdleg_put(c,width==2?&sxdleg_fatx_fat16_entry:&sxdleg_fatx_fat32_entry,4096,n))return false;return sxdleg_archive_entries(c,&sxdleg_fatx_directory_entry,64);}
#undef SXDLEG_LIMIT
#undef SXDLEG_ADD
bool sx_fatx_build(sx_context*c)
{
 return sxdleg_fatx(c);
}
