/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APPLE PASCAL data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_pascal_volume_header_fields[] = {
    SX_FIELD("first_block","uint16",0,2,SX_NONE),
    SX_FIELD("directory_end_block","uint16",2,2,SX_NONE),
    SX_FIELD("file_type","uint16",4,2,SX_ID),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
    SX_FIELD("volume_name","char[7]",7,7,SX_NONE),
    SX_FIELD("total_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("last_access_time","uint16",18,2,SX_NONE),
    SX_FIELD("last_set_date","uint16",20,2,SX_NONE),
    SX_FIELD("reserved","byte[4]",22,4,SX_RESERVED),
};
const sx_layout sxrfs_pascal_volume_header = {0x60650009U,"pascal_volume_header",sxrfs_pascal_volume_header_fields,SX_COUNT(sxrfs_pascal_volume_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_pascal_file_entry_fields[] = {
    SX_FIELD("first_block","uint16",0,2,SX_NONE),
    SX_FIELD("end_block","uint16",2,2,SX_NONE),
    SX_FIELD("kind_and_flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
    SX_FIELD("name","char[15]",7,15,SX_NONE),
    SX_FIELD("last_block_bytes","uint16",22,2,SX_SIZE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
};
const sx_layout sxrfs_pascal_file_entry = {0x6065000aU,"pascal_file_entry",sxrfs_pascal_file_entry_fields,SX_COUNT(sxrfs_pascal_file_entry_fields),SX_LE};
static bool sxrfs_pascal(sx_context*c){uint8_t h[26];bool dos=false;if(!sxrfs_read(c,1024,h,26))return false;unsigned count=sxrfs16(h+16,0),blocks=sxrfs16(h+14,0);if(sxrfs16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks<6||blocks>(uint64_t)c->size/512){dos=true;if(c->size<143360||!sxrfs_apple_read(c,1024,h,26,true))return false;count=sxrfs16(h+16,0);blocks=sxrfs16(h+14,0);if(sxrfs16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks!=280)return false;}
 if(!sxrfs_apple_put(c,&sxrfs_pascal_volume_header,1024,dos))return false;for(unsigned i=0;i<count;i++)if(!sxrfs_apple_put(c,&sxrfs_pascal_file_entry,1024+(uint64_t)(i+1)*26,dos))return false;return true;}
bool sx_apple_pascal_build(sx_context*c)
{
 return sxrfs_pascal(c);
}
