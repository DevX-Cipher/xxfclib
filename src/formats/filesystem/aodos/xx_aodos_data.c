/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AODOS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_aodos_directory_entry_fields[] = {
    SX_FIELD("status_and_folder_ids","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_koi8r","byte[14]",2,14,SX_NONE),
    SX_FIELD("first_block","uint16",16,2,SX_NONE),
    SX_FIELD("block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("load_address","uint16",20,2,SX_ADDRESS),
    SX_FIELD("byte_size","uint16",22,2,SX_SIZE),
};
const sx_layout sxrfs_aodos_directory_entry = {0x60650001U,"aodos_directory_entry",sxrfs_aodos_directory_entry_fields,SX_COUNT(sxrfs_aodos_directory_entry_fields),SX_LE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
static bool sxrfs_aodos(sx_context*c){uint8_t e[24];if(c->size<10752)return false;for(unsigned i=0;i<413&&c->count<SXRFS_LIMIT;i++){uint64_t p=320+(uint64_t)i*24;if(!sxrfs_read(c,p,e,24))break;bool empty=true;for(unsigned j=2;j<16;j++)if(e[j]&&e[j]!=0xf6)empty=false;if(empty)break;if(!SXRFS_ADD(c,aodos_directory_entry,p))return false;}return c->count!=0;}
bool sx_aodos_build(sx_context*c)
{
 return sxrfs_aodos(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
