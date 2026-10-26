/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Rsdos Fs data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_rsdos_vdk_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("minimum_version","uint8",5,1,SX_ID),
    SX_FIELD("source_id","uint8",6,1,SX_ID),
    SX_FIELD("source_version","uint8",7,1,SX_ID),
    SX_FIELD("cylinders","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("compression_and_name_length","uint8",11,1,SX_NONE),
};
const sx_layout sxdn_rsdos_vdk_header = {0x6078000dU,"rsdos_vdk_header",sxdn_rsdos_vdk_header_fields,SX_COUNT(sxdn_rsdos_vdk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_rsdos_granule_fields[] = {
    SX_FIELD("next_or_terminal","uint8",0,1,SX_NONE),
};
const sx_layout sxdn_rsdos_granule = {0x6078000eU,"rsdos_granule",sxdn_rsdos_granule_fields,SX_COUNT(sxdn_rsdos_granule_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_rsdos_directory_entry_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[3]",8,3,SX_NONE),
    SX_FIELD("file_type","uint8",11,1,SX_ID),
    SX_FIELD("ascii_flag","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_granule","uint8",13,1,SX_NONE),
    SX_FIELD("last_sector_bytes","uint16",14,2,SX_SIZE),
    SX_FIELD("reserved","byte[16]",16,16,SX_NONE),
};
const sx_layout sxdn_rsdos_directory_entry = {0x6078000fU,"rsdos_directory_entry",sxdn_rsdos_directory_entry_fields,SX_COUNT(sxdn_rsdos_directory_entry_fields),SX_BE};
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)
static bool sxdn_rsdos(sx_context*c){uint64_t h=(uint64_t)c->size%256,heads=1,declared_tracks=0;uint8_t b[12];if(h){if(!sxdn_read(c,0,b,h<12?h:12))return false;if(h>=12&&b[0]=='d'&&b[1]=='k'&&sxdn16(b+2,0)==h){heads=b[9];declared_tracks=b[8];if(!SXDN_ADD(c,rsdos_vdk_header,0))return false;}else{heads=h>1?b[1]:1;if(!sxdn_jvc_header(c,h))return false;}}if(heads<1||heads>2)return c->count!=0;uint64_t tracks=((uint64_t)c->size-h)/(heads*18*256),n=(declared_tracks?declared_tracks:tracks)>1?((declared_tracks?declared_tracks:tracks)-1)*2:0;if(n>255)n=255;if(n<68)n=68;uint64_t p=h+(17*heads*18+1)*256;if(!sxdn_span(c,p,256+72*32))return c->count!=0;return SXDN_TABLE(c,rsdos_granule,p,n)&&SXDN_TABLE(c,rsdos_directory_entry,p+256,72);}
bool sx_rsdos_fs_build(sx_context*c)
{
 return sxdn_rsdos(c);
}
#undef SXDN_ADD
#undef SXDN_TABLE
