/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ACORN_ATOM_DISK data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_atom_catalog_name_header_fields[] = {
    SX_FIELD("title_part1","char[8]",0,8,SX_NONE),
};
const sx_layout sxdt_atom_catalog_name_header = {0x607a000dU,"atom_catalog_name_header",sxdt_atom_catalog_name_header_fields,SX_COUNT(sxdt_atom_catalog_name_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_atom_catalog_info_header_fields[] = {
    SX_FIELD("title_part2","char[4]",0,4,SX_NONE),
    SX_FIELD("write_cycle","uint8",4,1,SX_NONE),
    SX_FIELD("file_count_times8","uint8",5,1,SX_NONE),
    SX_FIELD("disk_size_high_and_boot","uint8",6,1,SX_FLAGS),
    SX_FIELD("disk_sectors_low","uint8",7,1,SX_NONE),
};
const sx_layout sxdt_atom_catalog_info_header = {0x607a000eU,"atom_catalog_info_header",sxdt_atom_catalog_info_header_fields,SX_COUNT(sxdt_atom_catalog_info_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_atom_catalog_name_fields[] = {
    SX_FIELD("filename","char[7]",0,7,SX_NONE),
    SX_FIELD("directory_and_lock","uint8",7,1,SX_FLAGS),
};
const sx_layout sxdt_atom_catalog_name = {0x607a000fU,"atom_catalog_name",sxdt_atom_catalog_name_fields,SX_COUNT(sxdt_atom_catalog_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_atom_catalog_info_fields[] = {
    SX_FIELD("load_address_low","uint16",0,2,SX_NONE),
    SX_FIELD("execution_address_low","uint16",2,2,SX_NONE),
    SX_FIELD("file_length_low","uint16",4,2,SX_NONE),
    SX_FIELD("high_bits","uint8",6,1,SX_FLAGS),
    SX_FIELD("start_sector_low","uint8",7,1,SX_NONE),
};
const sx_layout sxdt_atom_catalog_info = {0x607a0010U,"atom_catalog_info",sxdt_atom_catalog_info_fields,SX_COUNT(sxdt_atom_catalog_info_fields),SX_LE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
static bool sxdt_atom(sx_context*c){uint8_t h[8];if(c->size!=102400||!sxdt_read(c,256,h,8)||h[5]%8||h[5]>248)return false;return SXDT_ADD(c,atom_catalog_name_header,0)&&SXDT_ADD(c,atom_catalog_info_header,256)&&SXDT_TABLE(c,atom_catalog_name,8,h[5]/8)&&SXDT_TABLE(c,atom_catalog_info,264,h[5]/8);}
bool sx_acorn_atom_disk_build(sx_context*c)
{
bool ok=false;
ok=sxdt_atom(c);
return ok&&c->count&&sxdt_finish(c);
}
