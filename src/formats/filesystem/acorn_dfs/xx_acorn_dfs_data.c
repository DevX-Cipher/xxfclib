/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ACORN DFS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_acorn_dfs_title_fields[] = {
    SX_FIELD("disk_title_first","byte[8]",0,8,SX_NONE),
};
const sx_layout sxrfs_acorn_dfs_title = {0x60650018U,"acorn_dfs_title",sxrfs_acorn_dfs_title_fields,SX_COUNT(sxrfs_acorn_dfs_title_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_acorn_dfs_name_fields[] = {
    SX_FIELD("name","byte[7]",0,7,SX_NONE),
    SX_FIELD("directory_and_locked","uint8",7,1,SX_FLAGS),
};
const sx_layout sxrfs_acorn_dfs_name = {0x60650019U,"acorn_dfs_name",sxrfs_acorn_dfs_name_fields,SX_COUNT(sxrfs_acorn_dfs_name_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_acorn_dfs_catalog_header_fields[] = {
    SX_FIELD("disk_title_last","byte[4]",0,4,SX_NONE),
    SX_FIELD("write_cycle","uint8",4,1,SX_NONE),
    SX_FIELD("file_entry_bytes","uint8",5,1,SX_SIZE),
    SX_FIELD("boot_and_sector_high","uint8",6,1,SX_FLAGS),
    SX_FIELD("total_sector_low","uint8",7,1,SX_NONE),
};
const sx_layout sxrfs_acorn_dfs_catalog_header = {0x6065001aU,"acorn_dfs_catalog_header",sxrfs_acorn_dfs_catalog_header_fields,SX_COUNT(sxrfs_acorn_dfs_catalog_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_acorn_dfs_file_metadata_fields[] = {
    SX_FIELD("load_address_low","uint16",0,2,SX_ID),
    SX_FIELD("execution_address_low","uint16",2,2,SX_ID),
    SX_FIELD("length_low","uint16",4,2,SX_NONE),
    SX_FIELD("packed_high","uint8",6,1,SX_FLAGS),
    SX_FIELD("start_sector_low","uint8",7,1,SX_NONE),
};
const sx_layout sxrfs_acorn_dfs_file_metadata = {0x6065001bU,"acorn_dfs_file_metadata",sxrfs_acorn_dfs_file_metadata_fields,SX_COUNT(sxrfs_acorn_dfs_file_metadata_fields),SX_LE};
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
static bool sxrfs_dfs(sx_context*c){uint8_t h[8];unsigned sides=1;if(sxrfs_read(c,256,h,8)){uint64_t sectors=((h[6]&3)<<8)|h[7],extent=c->f->format_size>0?(uint64_t)c->f->format_size:(uint64_t)c->size;if((sectors==400||sectors==800)&&extent==sectors*512)sides=2;}for(unsigned side=0;side<sides;side++){uint64_t base=side*2560;if(!sxrfs_read(c,base+256,h,8))break;unsigned n=h[5]/8,sectors=((h[6]&3)<<8)|h[7];if(h[5]%8||n>31||(sectors!=400&&sectors!=800)||!sxrfs_span(c,base+256,256))continue;if(!SXRFS_ADD(c,acorn_dfs_title,base)||!SXRFS_ADD(c,acorn_dfs_catalog_header,base+256)||!SXRFS_TABLE(c,acorn_dfs_name,base+8,n)||!SXRFS_TABLE(c,acorn_dfs_file_metadata,base+264,n))return false;}return c->count!=0;}
bool sx_acorn_dfs_build(sx_context*c)
{
 return sxrfs_dfs(c);
}
#undef SXRFS_ADD
#undef SXRFS_TABLE
