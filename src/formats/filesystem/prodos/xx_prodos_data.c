/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PRODOS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_prodos_directory_links_fields[] = {
    SX_FIELD("previous_block","uint16",0,2,SX_NONE),
    SX_FIELD("next_block","uint16",2,2,SX_NONE),
};
const sx_layout sxrfs_prodos_directory_links = {0x60650002U,"prodos_directory_links",sxrfs_prodos_directory_links_fields,SX_COUNT(sxrfs_prodos_directory_links_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_volume_header_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("volume_name","char[15]",1,15,SX_NONE),
    SX_FIELD("reserved","byte[2]",16,2,SX_RESERVED),
    SX_FIELD("modification_packed","uint32",18,4,SX_NONE),
    SX_FIELD("lowercase_flags","uint16",22,2,SX_FLAGS),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version","uint8",28,1,SX_ID),
    SX_FIELD("minimum_version","uint8",29,1,SX_ID),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("entry_length","uint8",31,1,SX_SIZE),
    SX_FIELD("entries_per_block","uint8",32,1,SX_COUNT_PROP),
    SX_FIELD("active_entries","uint16",33,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block","uint16",35,2,SX_NONE),
    SX_FIELD("total_blocks","uint16",37,2,SX_COUNT_PROP),
};
const sx_layout sxrfs_prodos_volume_header = {0x60650003U,"prodos_volume_header",sxrfs_prodos_volume_header_fields,SX_COUNT(sxrfs_prodos_volume_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_subdirectory_header_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("directory_name","char[15]",1,15,SX_NONE),
    SX_FIELD("reserved_75","uint8",16,1,SX_RESERVED),
    SX_FIELD("reserved","byte[7]",17,7,SX_RESERVED),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version","uint8",28,1,SX_ID),
    SX_FIELD("minimum_version","uint8",29,1,SX_ID),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("entry_length","uint8",31,1,SX_SIZE),
    SX_FIELD("entries_per_block","uint8",32,1,SX_COUNT_PROP),
    SX_FIELD("active_entries","uint16",33,2,SX_COUNT_PROP),
    SX_FIELD("parent_block","uint16",35,2,SX_NONE),
    SX_FIELD("parent_entry_number","uint8",37,1,SX_NONE),
    SX_FIELD("parent_entry_length","uint8",38,1,SX_SIZE),
};
const sx_layout sxrfs_prodos_subdirectory_header = {0x60650004U,"prodos_subdirectory_header",sxrfs_prodos_subdirectory_header_fields,SX_COUNT(sxrfs_prodos_subdirectory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_file_entry_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("name","char[15]",1,15,SX_NONE),
    SX_FIELD("file_type","uint8",16,1,SX_ID),
    SX_FIELD("key_block","uint16",17,2,SX_NONE),
    SX_FIELD("blocks_used","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("eof","uint24",21,3,SX_SIZE),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version_and_case","uint16",28,2,SX_FLAGS),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("auxiliary_type","uint16",31,2,SX_ID),
    SX_FIELD("modification_packed","uint32",33,4,SX_NONE),
    SX_FIELD("header_block","uint16",37,2,SX_NONE),
};
const sx_layout sxrfs_prodos_file_entry = {0x60650005U,"prodos_file_entry",sxrfs_prodos_file_entry_fields,SX_COUNT(sxrfs_prodos_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_fork_descriptor_fields[] = {
    SX_FIELD("storage_type","uint8",0,1,SX_ID),
    SX_FIELD("key_block","uint16",1,2,SX_NONE),
    SX_FIELD("blocks_used","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("eof","uint24",5,3,SX_SIZE),
};
const sx_layout sxrfs_prodos_fork_descriptor = {0x60650006U,"prodos_fork_descriptor",sxrfs_prodos_fork_descriptor_fields,SX_COUNT(sxrfs_prodos_fork_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_index_low_fields[] = {
    SX_FIELD("block_number_low_bytes","byte[256]",0,256,SX_NONE),
};
const sx_layout sxrfs_prodos_index_low = {0x60650007U,"prodos_index_low",sxrfs_prodos_index_low_fields,SX_COUNT(sxrfs_prodos_index_low_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_prodos_index_high_fields[] = {
    SX_FIELD("block_number_high_bytes","byte[256]",0,256,SX_NONE),
};
const sx_layout sxrfs_prodos_index_high = {0x60650008U,"prodos_index_high",sxrfs_prodos_index_high_fields,SX_COUNT(sxrfs_prodos_index_high_fields),SX_LE};
#define SXRFS_LIMIT 24000U
static bool sxrfs_pd_header(const uint8_t*h){return !sxrfs16(h,0)&&(h[4]>>4)==15&&(h[4]&15)&&h[35]==39&&h[36]==13&&sxrfs16(h+41,0)>=5;}
static bool sxrfs_prodos(sx_context*c){uint8_t h[512];bool dos=false;if(!sxrfs_read(c,1024,h,512))return false;if(!sxrfs_pd_header(h)){dos=true;if(c->size<143360||!sxrfs_apple_read(c,1024,h,512,true)||!sxrfs_pd_header(h))return false;}
 uint32_t blocks=sxrfs16(h+41,0);uint8_t*seen=xx_rt_calloc(blocks,1);uint16_t*queue=xx_rt_calloc(blocks,sizeof(*queue));if(!seen||!queue){xx_rt_free(seen);xx_rt_free(queue);return false;}size_t n=1,i=0;queue[0]=2;seen[2]=1;bool ok=true;
 while(i<n&&c->count<SXRFS_LIMIT&&!xx_pd_is_stopped(c->pd)){uint32_t b=queue[i++];uint64_t p=(uint64_t)b*512;if(!sxrfs_apple_read(c,p,h,512,dos))break;if(!sxrfs_apple_put(c,&sxrfs_prodos_directory_links,p,dos)){ok=false;break;}unsigned next=sxrfs16(h+2,0);if(next>=3&&next<blocks&&!seen[next]){seen[next]=1;queue[n++]=(uint16_t)next;}
  for(unsigned j=0;j<13;j++){uint8_t*e=h+4+j*39;unsigned t=e[0]>>4;uint64_t at=p+4+j*39;const sx_layout*l=t==15?&sxrfs_prodos_volume_header:t==14?&sxrfs_prodos_subdirectory_header:t?&sxrfs_prodos_file_entry:NULL;if(!l)continue;if(!sxrfs_apple_put(c,l,at,dos)){ok=false;break;}unsigned key=sxrfs16(e+17,0);if(t==13&&key>=3&&key<blocks&&!seen[key]){seen[key]=1;queue[n++]=(uint16_t)key;}if((t==2||t==3)&&key<blocks&&key>=3){if(!sxrfs_apple_put(c,&sxrfs_prodos_index_low,(uint64_t)key*512,dos)||!sxrfs_apple_put(c,&sxrfs_prodos_index_high,(uint64_t)key*512+256,dos)){ok=false;break;}}if(t==5&&key>=3&&key<blocks){if(!sxrfs_apple_put(c,&sxrfs_prodos_fork_descriptor,(uint64_t)key*512,dos)||!sxrfs_apple_put(c,&sxrfs_prodos_fork_descriptor,(uint64_t)key*512+256,dos)){ok=false;break;}}}
 }xx_rt_free(seen);xx_rt_free(queue);return ok;}
bool sx_prodos_build(sx_context*c)
{
 return sxrfs_prodos(c);
}
#undef SXRFS_LIMIT
