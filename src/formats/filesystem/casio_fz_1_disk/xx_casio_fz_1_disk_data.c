/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CASIO_FZ_1_DISK data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_casio_disk_header_fields[] = {
    SX_FIELD("disk_name","char[12]",0,12,SX_NONE),
    SX_FIELD("signature","byte[4]",12,4,SX_SIGNATURE),
    SX_FIELD("password","char[12]",16,12,SX_NONE),
    SX_FIELD("reserved","byte[4]",28,4,SX_RESERVED),
};
const sx_layout sxdt_casio_disk_header = {0x607a0011U,"casio_disk_header",sxdt_casio_disk_header_fields,SX_COUNT(sxdt_casio_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_casio_allocation_byte_fields[] = {
    SX_FIELD("sector_bitmap","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdt_casio_allocation_byte = {0x607a0012U,"casio_allocation_byte",sxdt_casio_allocation_byte_fields,SX_COUNT(sxdt_casio_allocation_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_casio_directory_entry_fields[] = {
    SX_FIELD("filename","char[12]",0,12,SX_NONE),
    SX_FIELD("content_type","uint8",12,1,SX_ID),
    SX_FIELD("continuation","uint8",13,1,SX_FLAGS),
    SX_FIELD("head_sector","uint16",14,2,SX_NONE),
};
const sx_layout sxdt_casio_directory_entry = {0x607a0013U,"casio_directory_entry",sxdt_casio_directory_entry_fields,SX_COUNT(sxdt_casio_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_casio_file_extent_fields[] = {
    SX_FIELD("start_sector","uint16",0,2,SX_NONE),
    SX_FIELD("end_sector","uint16",2,2,SX_NONE),
};
const sx_layout sxdt_casio_file_extent = {0x607a0014U,"casio_file_extent",sxdt_casio_file_extent_fields,SX_COUNT(sxdt_casio_file_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_casio_file_counts_fields[] = {
    SX_FIELD("bank_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("voice_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("wave_block_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxdt_casio_file_counts = {0x607a0015U,"casio_file_counts",sxdt_casio_file_counts_fields,SX_COUNT(sxdt_casio_file_counts_fields),SX_LE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
static bool sxdt_casio(sx_context*c){uint8_t d[1024],h[1024];if(c->size!=1310720||!sxdt_read(c,1024,d,1024)||!SXDT_ADD(c,casio_disk_header,0)||!SXDT_TABLE(c,casio_allocation_byte,128,768)||!SXDT_TABLE(c,casio_directory_entry,1024,64))return false;for(unsigned i=0;i<64;i++){const uint8_t*e=d+i*16;unsigned sector=sxdt16(e+14,0);if(!e[0]||e[12]>5||e[13]>1||sector<2||sector>=1280)continue;bool valid=true;for(unsigned j=0;j<12&&e[j];j++)if(e[j]<32||e[j]==127)valid=false;uint64_t p=(uint64_t)sector*1024;if(!valid||!sxdt_read(c,p,h,sizeof(h)))continue;if(e[12]!=4&&(sxdt16(h+1018,0)>8||sxdt16(h+1020,0)>64))continue;uint8_t seen[160]={0};unsigned n=0;bool any=false;for(;n<64;n++){unsigned a=sxdt16(h+n*4,0),b=sxdt16(h+n*4+2,0);if(!a&&!b){n++;break;}if(a<2||a>b||b>=1280){valid=false;break;}any=true;for(unsigned k=a;k<=b;k++){if(seen[k/8]&(1U<<(k%8)))valid=false;seen[k/8]|=(uint8_t)(1U<<(k%8));}}if(!valid||!any||(sxdt16(h,0)!=sector&&(seen[sector/8]&(1U<<(sector%8)))))continue;if(!SXDT_TABLE(c,casio_file_extent,p,n)||!SXDT_ADD(c,casio_file_counts,p+1018))return false;}return true;}
bool sx_casio_fz_1_disk_build(sx_context*c)
{
bool ok=false;
ok=sxdt_casio(c);
return ok&&c->count&&sxdt_finish(c);
}
