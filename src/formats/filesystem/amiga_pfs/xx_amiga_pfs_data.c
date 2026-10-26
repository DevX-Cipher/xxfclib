/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGA_PFS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_pfs_root_block_fields[] = {
    SX_FIELD("disk_type","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("options","uint32",4,4,SX_FLAGS),
    SX_FIELD("datestamp","uint32",8,4,SX_NONE),
    SX_FIELD("creation_day","uint16",12,2,SX_NONE),
    SX_FIELD("creation_minute","uint16",14,2,SX_NONE),
    SX_FIELD("creation_tick","uint16",16,2,SX_NONE),
    SX_FIELD("protection","uint16",18,2,SX_FLAGS),
    SX_FIELD("name_size","uint8",20,1,SX_SIZE),
    SX_FIELD("name","char[31]",21,31,SX_NONE),
    SX_FIELD("last_reserved_block","uint32",52,4,SX_NONE),
    SX_FIELD("first_reserved_block","uint32",56,4,SX_NONE),
    SX_FIELD("free_reserved_blocks","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("reserved_block_size","uint16",64,2,SX_SIZE),
    SX_FIELD("root_block_sectors","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("minimum_free_blocks","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_word","uint32",76,4,SX_NONE),
    SX_FIELD("deleted_directory_block","uint32",80,4,SX_NONE),
    SX_FIELD("sector_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("extension_block","uint32",88,4,SX_NONE),
    SX_FIELD("unused","uint32",92,4,SX_RESERVED),
};
const sx_layout sxcf_pfs_root_block = {0x603d0047U,"pfs_root_block",sxcf_pfs_root_block_fields,SX_COUNT(sxcf_pfs_root_block_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_root_small_indexes_fields[] = {
    SX_FIELD("bitmap_index_blocks","uint32[5]",0,20,SX_NONE),
    SX_FIELD("anode_index_blocks","uint32[99]",20,396,SX_NONE),
};
const sx_layout sxcf_pfs_root_small_indexes = {0x603d0048U,"pfs_root_small_indexes",sxcf_pfs_root_small_indexes_fields,SX_COUNT(sxcf_pfs_root_small_indexes_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_root_large_indexes_fields[] = {
    SX_FIELD("bitmap_index_blocks","uint32[104]",0,416,SX_NONE),
};
const sx_layout sxcf_pfs_root_large_indexes = {0x603d0049U,"pfs_root_large_indexes",sxcf_pfs_root_large_indexes_fields,SX_COUNT(sxcf_pfs_root_large_indexes_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_index_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_number","uint32",8,4,SX_NONE),
};
const sx_layout sxcf_pfs_index_header = {0x603d004aU,"pfs_index_header",sxcf_pfs_index_header_fields,SX_COUNT(sxcf_pfs_index_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_anode_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_number","uint32",8,4,SX_NONE),
    SX_FIELD("reserved1","uint32",12,4,SX_RESERVED),
};
const sx_layout sxcf_pfs_anode_header = {0x603d004bU,"pfs_anode_header",sxcf_pfs_anode_header_fields,SX_COUNT(sxcf_pfs_anode_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_anode_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
    SX_FIELD("next_anode","uint32",8,4,SX_NONE),
};
const sx_layout sxcf_pfs_anode = {0x603d004cU,"pfs_anode",sxcf_pfs_anode_fields,SX_COUNT(sxcf_pfs_anode_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_directory_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("reserved1","byte[4]",8,4,SX_RESERVED),
    SX_FIELD("anode_number","uint32",12,4,SX_NONE),
    SX_FIELD("parent_anode","uint32",16,4,SX_NONE),
};
const sx_layout sxcf_pfs_directory_header = {0x603d004dU,"pfs_directory_header",sxcf_pfs_directory_header_fields,SX_COUNT(sxcf_pfs_directory_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_directory_entry_fields[] = {
    SX_FIELD("record_size","uint8",0,1,SX_SIZE),
    SX_FIELD("type","int8",1,1,SX_ID),
    SX_FIELD("anode_number","uint32",2,4,SX_NONE),
    SX_FIELD("file_size_low","uint32",6,4,SX_NONE),
    SX_FIELD("creation_day","uint16",10,2,SX_NONE),
    SX_FIELD("creation_minute","uint16",12,2,SX_NONE),
    SX_FIELD("creation_tick","uint16",14,2,SX_NONE),
    SX_FIELD("protection","uint8",16,1,SX_FLAGS),
    SX_FIELD("name_size","uint8",17,1,SX_SIZE),
};
const sx_layout sxcf_pfs_directory_entry = {0x603d004eU,"pfs_directory_entry",sxcf_pfs_directory_entry_fields,SX_COUNT(sxcf_pfs_directory_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_pfs_extension_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("options","uint32",4,4,SX_FLAGS),
    SX_FIELD("datestamp","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint32",12,4,SX_ID),
    SX_FIELD("root_date_components","uint16[3]",16,6,SX_NONE),
    SX_FIELD("volume_date_components","uint16[3]",22,6,SX_NONE),
    SX_FIELD("postponed_operation","uint32",28,4,SX_ID),
    SX_FIELD("postponed_arguments","uint32[3]",32,12,SX_NONE),
    SX_FIELD("reserved_allocation_cursor","uint32",44,4,SX_NONE),
    SX_FIELD("allocation_bit","uint16",48,2,SX_NONE),
    SX_FIELD("current_anode_sequence","uint16",50,2,SX_NONE),
    SX_FIELD("deleted_directory_cursor","uint16",52,2,SX_NONE),
    SX_FIELD("deleted_directory_size","uint16",54,2,SX_COUNT_PROP),
    SX_FIELD("filename_size","uint16",56,2,SX_SIZE),
    SX_FIELD("reserved1","byte[6]",58,6,SX_RESERVED),
    SX_FIELD("super_indexes","uint32[16]",64,64,SX_NONE),
    SX_FIELD("deleted_user_id","uint16",128,2,SX_ID),
    SX_FIELD("deleted_group_id","uint16",130,2,SX_ID),
    SX_FIELD("deleted_protection","uint32",132,4,SX_FLAGS),
    SX_FIELD("deleted_creation_date","uint16[3]",136,6,SX_NONE),
    SX_FIELD("reserved2","uint16",142,2,SX_RESERVED),
    SX_FIELD("deleted_directory_blocks","uint32[32]",144,128,SX_NONE),
};
const sx_layout sxcf_pfs_extension = {0x603d004fU,"pfs_extension",sxcf_pfs_extension_fields,SX_COUNT(sxcf_pfs_extension_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
typedef struct sxcf_pfs_state{sx_context*c;uint32_t first,last,unit,options,extension;unsigned visits;uint8_t root[512];}sxcf_pfs_state;
static bool sxcf_pfs_block(sxcf_pfs_state*g,uint32_t nr,uint8_t*b){return nr>=g->first&&nr<=g->last&&g->unit/512<=g->last-nr+1&&sxcf_read(g->c,(uint64_t)nr*512,b,g->unit);}
static bool sxcf_pfs_lookup_anode(sxcf_pfs_state*g,uint32_t nr,uint32_t*count,uint32_t*block,uint32_t*next){
 uint8_t b[4096];uint32_t per=(g->unit-16)/12,ip=(g->unit-12)/4,seq=(g->options&2)?nr>>16:nr/per,slot=(g->options&2)?nr&65535:nr%per,which=seq/ip,idx=seq%ip,addr;
 if(slot>=per||++g->visits>4096)return false;
 if(g->options&128){unsigned super=which/ip;if(super>=16||!sxcf_pfs_block(g,g->extension,b)||sxcf16(b,1)!=0x4558)return false;if(!SXCF_ADD(g->c,pfs_extension,(uint64_t)g->extension*512))return false;addr=sxcf32(b+64+super*4,1);
  if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x5342||sxcf32(b+8,1)!=super)return false;if(!SXCF_ADD(g->c,pfs_index_header,(uint64_t)addr*512)||!sxcf_put(g->c,&sxcf_classic_block_number32_be,(uint64_t)addr*512+12,ip))return false;addr=sxcf32(b+12+(which%ip)*4,1);
 }else{if(which>=99)return false;addr=sxcf32(g->root+116+which*4,1);}
 if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x4942||sxcf32(b+8,1)!=which)return false;if(!SXCF_ADD(g->c,pfs_index_header,(uint64_t)addr*512)||!sxcf_put(g->c,&sxcf_classic_block_number32_be,(uint64_t)addr*512+12,ip))return false;addr=sxcf32(b+12+idx*4,1);
 if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x4142||sxcf32(b+8,1)!=seq)return false;if(!SXCF_ADD(g->c,pfs_anode_header,(uint64_t)addr*512)||!SXCF_TABLE(g->c,pfs_anode,(uint64_t)addr*512+16,per))return false;
 *count=sxcf32(b+16+12*slot,1);*block=sxcf32(b+20+12*slot,1);*next=sxcf32(b+24+12*slot,1);return true;
}
static bool sxcf_pfs_dir(sxcf_pfs_state*g,uint32_t nr,unsigned depth){
 if(depth>24)return true;uint8_t b[4096];while(nr&&g->visits<4096&&g->c->count<SXCF_LIMIT){uint32_t count,block,next;if(!sxcf_pfs_lookup_anode(g,nr,&count,&block,&next)||!count||count>262144||!sxcf_span(g->c,(uint64_t)block*512,(uint64_t)count*512))break;
  for(uint32_t j=0;j+g->unit/512<=count&&g->c->count<SXCF_LIMIT;j+=g->unit/512){uint64_t p=((uint64_t)block+j)*512;if(!sxcf_read(g->c,p,b,g->unit)||sxcf16(b,1)!=0x4442)break;if(!SXCF_ADD(g->c,pfs_directory_header,p))return false;
   for(unsigned at=20;at<g->unit;){unsigned z=b[at];if(!z)break;if(z<20||(z&1)||z>g->unit-at||!b[at+17]||19U+b[at+17]>z||19U+b[at+17]+b[at+18+b[at+17]]>z)break;
    if(!SXCF_ADD(g->c,pfs_directory_entry,p+at))return false;if(b[at+1]==2&&!sxcf_pfs_dir(g,sxcf32(b+at+2,1),depth+1))return false;at+=z;
   }
  }if(next==nr)break;nr=next;
 }return true;
}
static bool sxcf_pfs(sx_context*c){sxcf_pfs_state g;xx_rt_memset(&g,0,sizeof(g));g.c=c;if(!sxcf_read(c,1024,g.root,512))return false;uint32_t m=sxcf32(g.root,1);if(m!=0x41465301&&m!=0x50465301&&m!=0x50465302&&m!=0x6d754146&&m!=0x6d755046)return false;g.options=sxcf32(g.root+4,1);g.first=sxcf32(g.root+56,1);g.last=sxcf32(g.root+52,1);g.unit=sxcf16(g.root+64,1);g.extension=sxcf32(g.root+88,1);if(g.first>g.last||g.last>=(uint64_t)c->size/512||g.unit<512||g.unit>4096||!sxcf_pow(g.unit)||!SXCF_ADD(c,pfs_root_block,1024)||!sxcf_put(c,(g.options&128)?&sxcf_pfs_root_large_indexes:&sxcf_pfs_root_small_indexes,1120,1))return false;return sxcf_pfs_dir(&g,5,0);}
bool sx_amiga_pfs_build(sx_context*c)
{
 return sxcf_pfs(c);
}
