/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ACT_APRICOT_PC_XI_RAW data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_apricot_label_prefix_fields[] = {
    SX_FIELD("version","char[8]",0,8,SX_NONE),
    SX_FIELD("unknown","byte[6]",8,6,SX_NONE),
    SX_FIELD("sector_size","uint16",14,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",22,1,SX_COUNT_PROP),
};
const sx_layout sxdt_apricot_label_prefix = {0x607a0009U,"apricot_label_prefix",sxdt_apricot_label_prefix_fields,SX_COUNT(sxdt_apricot_label_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_apricot_bpb_fields[] = {
    SX_FIELD("bytes_per_sector","uint16",0,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("root_directory_entries","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",10,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",11,2,SX_COUNT_PROP),
};
const sx_layout sxdt_apricot_bpb = {0x607a000aU,"apricot_bpb",sxdt_apricot_bpb_fields,SX_COUNT(sxdt_apricot_bpb_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_apricot_fat12_pair_fields[] = {
    SX_FIELD("packed_cluster_links","uint24",0,3,SX_NONE),
};
const sx_layout sxdt_apricot_fat12_pair = {0x607a0078U,"apricot_fat12_pair",sxdt_apricot_fat12_pair_fields,SX_COUNT(sxdt_apricot_fat12_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_apricot_directory_entry_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[3]",8,3,SX_NONE),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("reserved_legacy","byte[10]",12,10,SX_NONE),
    SX_FIELD("modification_time_packed","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date_packed","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster","uint16",26,2,SX_NONE),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxdt_apricot_directory_entry = {0x607a0079U,"apricot_directory_entry",sxdt_apricot_directory_entry_fields,SX_COUNT(sxdt_apricot_directory_entry_fields),SX_LE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
static bool sxdt_apricot(sx_context*c){uint8_t b[13];if(!sxdt_read(c,80,b,13)||sxdt16(b,0)!=512||!SXDT_ADD(c,apricot_label_prefix,0)||!SXDT_ADD(c,apricot_bpb,80))return false;unsigned reserved=sxdt16(b+3,0),fats=b[5],fatsectors=sxdt16(b+11,0),entries=sxdt16(b+6,0);if(!reserved||!fats||fats>2||!fatsectors||fatsectors>16||entries>1024)return true;for(unsigned i=0;i<fats;i++){uint64_t p=(uint64_t)(reserved+i*fatsectors)*512;if(sxdt_span(c,p,(uint64_t)fatsectors*512)&&!SXDT_TABLE(c,apricot_fat12_pair,p,fatsectors*512/3))return false;}uint64_t root=(uint64_t)(reserved+fats*fatsectors)*512;for(unsigned i=0;i<entries;i++){uint8_t e[32];uint64_t p=root+i*32;if(!sxdt_read(c,p,e,32)||!e[0])break;if(e[0]!=229&&(e[11]&63)!=15&&!SXDT_ADD(c,apricot_directory_entry,p))return false;}/* Native archive header extents authenticate subdirectory entries as well. */if(c->f->create_archive_records_reading&&c->f->get_current_archive_record&&c->f->archive_record_move_to_next&&c->f->free_archive_records_reading){xx_archive_record_state*state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(state){bool ok=true;for(unsigned i=0;i<24000&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==32){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(sxdt_span(c,p,32)&&!SXDT_ADD(c,apricot_directory_entry,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;}(c->f->free_archive_records_reading)(c->f,state);if(!ok)return false;}}return true;}
bool sx_act_apricot_pc_xi_raw_build(sx_context*c)
{
bool ok=false;
ok=sxdt_apricot(c);
return ok&&c->count&&sxdt_finish(c);
}
