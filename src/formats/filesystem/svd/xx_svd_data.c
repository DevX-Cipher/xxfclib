/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Svd data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_svd_version_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
const sx_layout sxdn_svd_version = {0x6078002dU,"svd_version",sxdn_svd_version_fields,SX_COUNT(sxdn_svd_version_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_svd_sectors_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxdn_svd_sectors = {0x6078002eU,"svd_sectors",sxdn_svd_sectors_fields,SX_COUNT(sxdn_svd_sectors_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_svd_cylinders_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxdn_svd_cylinders = {0x6078002fU,"svd_cylinders",sxdn_svd_cylinders_fields,SX_COUNT(sxdn_svd_cylinders_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_svd_sides_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxdn_svd_sides = {0x60780030U,"svd_sides",sxdn_svd_sides_fields,SX_COUNT(sxdn_svd_sides_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_svd_sector_size_code_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdn_svd_sector_size_code = {0x60780031U,"svd_sector_size_code",sxdn_svd_sector_size_code_fields,SX_COUNT(sxdn_svd_sector_size_code_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_svd_write_protect_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_FLAGS),
};
const sx_layout sxdn_svd_write_protect = {0x60780032U,"svd_write_protect",sxdn_svd_write_protect_fields,SX_COUNT(sxdn_svd_write_protect_fields),SX_LE};
static bool sxdn_svd(sx_context*c){uint8_t b[512];size_t n=(uint64_t)c->size<sizeof(b)?(size_t)c->size:sizeof(b);if(!sxdn_read(c,0,b,n))return false;sxdn_text t={c,b,n};static const sx_layout*const fields[]={&sxdn_svd_version,&sxdn_svd_sectors,&sxdn_svd_cylinders,&sxdn_svd_sides,&sxdn_svd_sector_size_code,&sxdn_svd_write_protect};size_t p=0;unsigned count=b[0]=='2'?6:3;for(unsigned i=0;i<count;i++){size_t a=p;while(p<n&&b[p]!='\n')p++;if(p==n)return c->count!=0;if(!sxdn_text_value(&t,fields[i],a,p))return false;p++;}return true;}
bool sx_svd_build(sx_context*c)
{
 return sxdn_svd(c);
}
