/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PIRS data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_stfs_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxan_stfs_signature = {UINT32_C(0x60770050),"stfs_signature",sxan_stfs_signature_fields,SX_COUNT(sxan_stfs_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_metadata_digest_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("header_size","uint32",20,4,SX_SIZE),
};
const sx_layout sxan_stfs_metadata_digest = {UINT32_C(0x60770051),"stfs_metadata_digest",sxan_stfs_metadata_digest_fields,SX_COUNT(sxan_stfs_metadata_digest_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_volume_le_fields[] = {
 SX_FIELD("descriptor_size","uint8",0,1,SX_SIZE),
 SX_FIELD("reserved","uint8",1,1,SX_NONE),
 SX_FIELD("block_separation","uint8",2,1,SX_FLAGS),
 SX_FIELD("file_table_blocks","uint16",3,2,SX_NONE),
 SX_FIELD("first_file_table_block","uint24",5,3,SX_NONE),
};
const sx_layout sxan_stfs_volume_le = {UINT32_C(0x60770052),"stfs_volume_le",sxan_stfs_volume_le_fields,SX_COUNT(sxan_stfs_volume_le_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_volume_be_fields[] = {
 SX_FIELD("top_sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("allocated_blocks","uint32",20,4,SX_NONE),
 SX_FIELD("unallocated_blocks","uint32",24,4,SX_NONE),
};
const sx_layout sxan_stfs_volume_be = {UINT32_C(0x60770053),"stfs_volume_be",sxan_stfs_volume_be_fields,SX_COUNT(sxan_stfs_volume_be_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_data_file_count_fields[] = {
 SX_FIELD("data_file_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxan_stfs_data_file_count = {UINT32_C(0x60770054),"stfs_data_file_count",sxan_stfs_data_file_count_fields,SX_COUNT(sxan_stfs_data_file_count_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_hash_entry_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("status","uint8",20,1,SX_FLAGS),
 SX_FIELD("next_block","uint24",21,3,SX_NONE),
};
const sx_layout sxan_stfs_hash_entry = {UINT32_C(0x60770055),"stfs_hash_entry",sxan_stfs_hash_entry_fields,SX_COUNT(sxan_stfs_hash_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_file_le_fields[] = {
 SX_FIELD("name","char[40]",0,40,SX_NONE),
 SX_FIELD("name_length_flags","uint8",40,1,SX_FLAGS),
 SX_FIELD("allocated_blocks","uint24",41,3,SX_NONE),
 SX_FIELD("repeated_allocated_blocks","uint24",44,3,SX_NONE),
 SX_FIELD("first_block","uint24",47,3,SX_NONE),
};
const sx_layout sxan_stfs_file_le = {UINT32_C(0x60770056),"stfs_file_le",sxan_stfs_file_le_fields,SX_COUNT(sxan_stfs_file_le_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_file_be_fields[] = {
 SX_FIELD("parent_index","uint16",0,2,SX_NONE),
 SX_FIELD("payload_size","uint32",2,4,SX_SIZE),
 SX_FIELD("creation_time","uint32",6,4,SX_NONE),
 SX_FIELD("access_time","uint32",10,4,SX_NONE),
};
const sx_layout sxan_stfs_file_be = {UINT32_C(0x60770057),"stfs_file_be",sxan_stfs_file_be_fields,SX_COUNT(sxan_stfs_file_be_fields),SX_BE};
typedef struct sxan_stfs{uint64_t first;uint32_t allocated;unsigned sex,level;uint64_t top;}sxan_stfs;
static uint64_t sxan_stfs_data(const sxan_stfs*v,uint32_t b){uint64_t p=b+(((uint64_t)b+170)/170<<v->sex);if(b>=170)p+=((uint64_t)b+28900)/28900<<v->sex;if(b>=28900)p+=UINT64_C(1)<<v->sex;return v->first+p*4096;}
static uint64_t sxan_stfs_table(const sxan_stfs*v,uint32_t b,unsigned level){uint64_t copies=UINT64_C(1)<<v->sex,step0=170+copies,step1=28900+171*copies,p;if(level==2)p=step1;else if(level==1)p=b<28900?step0:copies+(uint64_t)(b/28900)*step1;else if(b<170)p=0;else p=(uint64_t)(b/170)*step0+(((uint64_t)b/28900+1)<<v->sex)+(b>=28900?copies:0);return v->first+p*4096;}
static bool sxan_stfs_bottom(sx_context*c,const sxan_stfs*v,uint32_t block,uint64_t*out){uint8_t h[24];uint64_t parent;if(!v->level){*out=v->top;return true;}if(v->level==1)parent=v->top+(block/170)*24;else{uint64_t upper=v->top+(block/28900)*24;if(!sxan_read(c,upper,h,24)||!sxan_add(c,&sxan_stfs_hash_entry,upper))return false;uint64_t middle=sxan_stfs_table(v,block,1)+(v->sex?(uint64_t)(h[20]&64)*64:0);parent=middle+((block/170)%170)*24;}if(!sxan_read(c,parent,h,24)||!sxan_add(c,&sxan_stfs_hash_entry,parent))return false;*out=sxan_stfs_table(v,block,0)+(v->sex?(uint64_t)(h[20]&64)*64:0);return sxan_span(c,*out,4096);}
static bool sxan_pirs(sx_context*c){sxan_stfs v;uint64_t hs,blocks,start,allocated,flags;if(!sxan_add(c,&sxan_stfs_signature,0)||!sxan_add(c,&sxan_stfs_metadata_digest,0x32c)||!sxan_add(c,&sxan_stfs_volume_le,0x379)||!sxan_add(c,&sxan_stfs_volume_be,0x381)||!sxan_add(c,&sxan_stfs_data_file_count,0x3a9)||!sxan_word(c,0x340,4,true,&hs)||!sxan_word(c,0x395,4,true,&allocated)||!sxan_word(c,0x37b,1,false,&flags)||!sxan_word(c,0x37c,2,false,&blocks)||!sxan_word(c,0x37e,3,false,&start))return false;if(!allocated||allocated>1000000||start>=allocated||blocks>allocated)return true;v.first=(hs+4095)&~UINT64_C(4095);v.allocated=(uint32_t)allocated;v.sex=(unsigned)(~flags)&1;v.level=allocated<=170?0:allocated<=28900?1:2;v.top=sxan_stfs_table(&v,0,v.level)+(flags&2)*2048;if(!sxan_span(c,v.top,4096))return true;
 for(uint32_t block=0;block<v.allocated;block+=170){uint64_t bottom;if(!sxan_stfs_bottom(c,&v,block,&bottom)||!sxan_table(c,&sxan_stfs_hash_entry,bottom,24,v.allocated-block<170?v.allocated-block:170))return false;}
 uint32_t block=(uint32_t)start;for(uint64_t i=0;i<blocks;i++){uint64_t bottom,next,p;if(block>=v.allocated||!sxan_stfs_bottom(c,&v,block,&bottom)||!sxan_word(c,bottom+(block%170)*24+21,3,true,&next))return true;p=sxan_stfs_data(&v,block);if(!sxan_span(c,p,4096))return true;for(unsigned j=0;j<64;j++){uint64_t len;if(!sxan_word(c,p+64*j+40,1,false,&len))return false;if(!(len&63))continue;if((len&63)>40)return true;if(!sxan_add(c,&sxan_stfs_file_le,p+64*j)||!sxan_add(c,&sxan_stfs_file_be,p+64*j+50))return false;}block=(uint32_t)next;}return true;}
bool sx_pirs_build(sx_context*c)
{
bool ok=false;
ok=sxan_pirs(c);
(void)ok;return c->count&&sxan_finish(c);
}
