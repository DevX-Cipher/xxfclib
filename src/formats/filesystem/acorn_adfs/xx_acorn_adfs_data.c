/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ADFS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_adfs_map0_fields[] = {
    SX_FIELD("free_start_sector_triplets","byte[246]",0,246,SX_NONE),
    SX_FIELD("reserved246","uint8",246,1,SX_RESERVED),
    SX_FIELD("disk_name_even_characters","byte[5]",247,5,SX_NONE),
    SX_FIELD("total_sectors","uint24",252,3,SX_COUNT_PROP),
    SX_FIELD("checksum","uint8",255,1,SX_CHECKSUM),
};
const sx_layout sxrfs_adfs_map0 = {0x60650014U,"adfs_map0",sxrfs_adfs_map0_fields,SX_COUNT(sxrfs_adfs_map0_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_adfs_map1_fields[] = {
    SX_FIELD("free_length_sector_triplets","byte[246]",0,246,SX_NONE),
    SX_FIELD("disk_name_odd_characters","byte[5]",246,5,SX_NONE),
    SX_FIELD("disk_identifier","uint16",251,2,SX_ID),
    SX_FIELD("boot_option","uint8",253,1,SX_ID),
    SX_FIELD("free_list_bytes","uint8",254,1,SX_SIZE),
    SX_FIELD("checksum","uint8",255,1,SX_CHECKSUM),
};
const sx_layout sxrfs_adfs_map1 = {0x60650015U,"adfs_map1",sxrfs_adfs_map1_fields,SX_COUNT(sxrfs_adfs_map1_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_adfs_directory_start_fields[] = {
    SX_FIELD("sequence","uint8",0,1,SX_NONE),
    SX_FIELD("signature","char[4]",1,4,SX_SIGNATURE),
};
const sx_layout sxrfs_adfs_directory_start = {0x60650016U,"adfs_directory_start",sxrfs_adfs_directory_start_fields,SX_COUNT(sxrfs_adfs_directory_start_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_adfs_directory_entry_fields[] = {
    SX_FIELD("name_and_attributes","byte[10]",0,10,SX_FLAGS),
    SX_FIELD("load_address","uint32",10,4,SX_ADDRESS),
    SX_FIELD("execution_address","uint32",14,4,SX_ADDRESS),
    SX_FIELD("byte_size","uint32",18,4,SX_SIZE),
    SX_FIELD("first_sector","uint24",22,3,SX_NONE),
    SX_FIELD("sequence","uint8",25,1,SX_NONE),
};
const sx_layout sxrfs_adfs_directory_entry = {0x60650017U,"adfs_directory_entry",sxrfs_adfs_directory_entry_fields,SX_COUNT(sxrfs_adfs_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_adfs_directory_tail_fields[] = {
    SX_FIELD("terminator","uint8",0,1,SX_RESERVED),
    SX_FIELD("directory_name","byte[10]",1,10,SX_NONE),
    SX_FIELD("parent_sector","uint24",11,3,SX_NONE),
    SX_FIELD("title","byte[19]",14,19,SX_NONE),
    SX_FIELD("reserved","byte[14]",33,14,SX_RESERVED),
    SX_FIELD("sequence","uint8",47,1,SX_NONE),
    SX_FIELD("signature","char[4]",48,4,SX_SIGNATURE),
    SX_FIELD("reserved_last","uint8",52,1,SX_RESERVED),
};
const sx_layout sxrfs_adfs_directory_tail = {0x6065004cU,"adfs_directory_tail",sxrfs_adfs_directory_tail_fields,SX_COUNT(sxrfs_adfs_directory_tail_fields),SX_LE};
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
static bool sxrfs_adfs(sx_context*c){uint8_t h[256];if(!sxrfs_read(c,0,h,256)||h[246])return false;unsigned n=sxrfs24(h+252,false);if(n!=640&&n!=1280&&n!=2560)return false;if(!sxrfs_span(c,0,(uint64_t)n*256)||!SXRFS_ADD(c,adfs_map0,0)||!SXRFS_ADD(c,adfs_map1,256)||!SXRFS_ADD(c,adfs_directory_start,512)||!SXRFS_ADD(c,adfs_directory_tail,512+1227))return false;
 /* Archive callbacks return authenticated physical entry coordinates for both
  * linear and interleaved L images. Each interleaved physical run is
  * 16 sectors (4 KiB); only entries crossing such a run remain raw. */
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<24000&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==26){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if((n!=2560||p%4096+26<=4096)&&sxrfs_span(c,p,26)&&!SXRFS_ADD(c,adfs_directory_entry,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_acorn_adfs_build(sx_context*c)
{
 return sxrfs_adfs(c);
}
#undef SXRFS_ADD
