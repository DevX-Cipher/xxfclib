/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LISA_FS data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_lisa_dc42_header_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("encoding","uint8",80,1,SX_ID),
    SX_FIELD("format","uint8",81,1,SX_ID),
    SX_FIELD("magic","uint16",82,2,SX_SIGNATURE),
};
const sx_layout sxdt_lisa_dc42_header = {0x607a0067U,"lisa_dc42_header",sxdt_lisa_dc42_header_fields,SX_COUNT(sxdt_lisa_dc42_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_microfloppy_loader_fields[] = {
    SX_FIELD("jump_instruction","byte[4]",0,4,SX_NONE),
    SX_FIELD("boot_id","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("loader_version","uint16",6,2,SX_ID),
    SX_FIELD("global_data_size","int16",8,2,SX_SIZE),
    SX_FIELD("code_size","int16",10,2,SX_SIZE),
    SX_FIELD("entry_offset","int16",12,2,SX_OFFSET),
    SX_FIELD("mddf_block","int16",14,2,SX_NONE),
};
const sx_layout sxdt_lisa_microfloppy_loader = {0x607a0068U,"lisa_microfloppy_loader",sxdt_lisa_microfloppy_loader_fields,SX_COUNT(sxdt_lisa_microfloppy_loader_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_microfloppy_tag_fields[] = {
    SX_FIELD("version","int16",0,2,SX_NONE),
    SX_FIELD("volume_id","int16",2,2,SX_ID),
    SX_FIELD("file_id","int16",4,2,SX_ID),
    SX_FIELD("relative_page","int16",6,2,SX_NONE),
    SX_FIELD("forward_link_and_used_high","uint16",8,2,SX_NONE),
    SX_FIELD("backward_link_and_used_low","uint16",10,2,SX_NONE),
};
const sx_layout sxdt_lisa_microfloppy_tag = {0x607a0069U,"lisa_microfloppy_tag",sxdt_lisa_microfloppy_tag_fields,SX_COUNT(sxdt_lisa_microfloppy_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_mddf_fields[] = {
    SX_FIELD("filesystem_version","int16",0,2,SX_ID),
    SX_FIELD("volume_id","uint32[2]",2,8,SX_ID),
    SX_FIELD("volume_number","int16",10,2,SX_NONE),
    SX_FIELD("volume_name_pascal","char[33]",12,33,SX_NONE),
    SX_FIELD("padc1","byte[1]",45,1,SX_NONE),
    SX_FIELD("password","char[33]",46,33,SX_NONE),
    SX_FIELD("padc2","byte[1]",79,1,SX_NONE),
    SX_FIELD("init_machine_id","int32",80,4,SX_NONE),
    SX_FIELD("master_machine_id","int32",84,4,SX_NONE),
    SX_FIELD("creation_time","uint32",88,4,SX_TIME),
    SX_FIELD("copy_creation_time","uint32",92,4,SX_TIME),
    SX_FIELD("copy_time","uint32",96,4,SX_TIME),
    SX_FIELD("scavenge_time","uint32",100,4,SX_TIME),
    SX_FIELD("copy_thread","int32",104,4,SX_NONE),
    SX_FIELD("firstblock","int32",108,4,SX_NONE),
    SX_FIELD("lastblock","int32",112,4,SX_NONE),
    SX_FIELD("lastfspage","int32",116,4,SX_NONE),
    SX_FIELD("block_count","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int16",124,2,SX_SIZE),
    SX_FIELD("data_size","int16",126,2,SX_SIZE),
    SX_FIELD("cluster_size","int16",128,2,SX_NONE),
    SX_FIELD("mddf_page","int32",130,4,SX_NONE),
    SX_FIELD("mddf_size","int16",134,2,SX_SIZE),
    SX_FIELD("bitmap_addr","int32",136,4,SX_NONE),
    SX_FIELD("bitmap_size","int32",140,4,SX_NONE),
    SX_FIELD("bitmap_bytes","int16",144,2,SX_SIZE),
    SX_FIELD("bitmap_pages","int16",146,2,SX_COUNT_PROP),
    SX_FIELD("slist_addr","int32",148,4,SX_NONE),
    SX_FIELD("slist_entries_per_block","int16",152,2,SX_COUNT_PROP),
    SX_FIELD("slist_block_count","int16",154,2,SX_COUNT_PROP),
    SX_FIELD("first_file","int16",156,2,SX_ID),
    SX_FIELD("empty_file","int16",158,2,SX_ID),
    SX_FIELD("maximum_files","int16",160,2,SX_COUNT_PROP),
    SX_FIELD("hint_size","int16",162,2,SX_SIZE),
    SX_FIELD("leader_offset","int16",164,2,SX_OFFSET),
    SX_FIELD("leader_pages","int16",166,2,SX_COUNT_PROP),
    SX_FIELD("flabel_offset","int16",168,2,SX_OFFSET),
    SX_FIELD("unusedi1","int16",170,2,SX_NONE),
    SX_FIELD("map_offset","int16",172,2,SX_OFFSET),
    SX_FIELD("map_size","int16",174,2,SX_NONE),
    SX_FIELD("file_count","int16",176,2,SX_COUNT_PROP),
    SX_FIELD("freestart","int32",178,4,SX_NONE),
    SX_FIELD("unusedl1","int32",182,4,SX_NONE),
    SX_FIELD("free_page_count","int32",186,4,SX_COUNT_PROP),
    SX_FIELD("rootsnum","int16",190,2,SX_ID),
    SX_FIELD("rootmaxentries","int16",192,2,SX_COUNT_PROP),
    SX_FIELD("mountinfo","int8",194,1,SX_ID),
    SX_FIELD("mountinfo_pad","int8",195,1,SX_NONE),
    SX_FIELD("overmount_stamp","uint32[2]",196,8,SX_ID),
    SX_FIELD("pmem_id","int32",204,4,SX_NONE),
    SX_FIELD("pmem","int16[32]",208,64,SX_NONE),
    SX_FIELD("vol_scavenged","int16",272,2,SX_FLAGS),
    SX_FIELD("tbt_copied","int16",274,2,SX_FLAGS),
    SX_FIELD("smallmap_offset","int16",276,2,SX_OFFSET),
    SX_FIELD("hentry_offset","int16",278,2,SX_OFFSET),
    SX_FIELD("backup_volid","uint32[2]",280,8,SX_ID),
    SX_FIELD("file_label_size","int16",288,2,SX_SIZE),
    SX_FIELD("fs_overhead","int16",290,2,SX_COUNT_PROP),
    SX_FIELD("result_scavenge","int16",292,2,SX_NONE),
    SX_FIELD("boot_code","int16",294,2,SX_NONE),
    SX_FIELD("boot_environ","int16",296,2,SX_NONE),
    SX_FIELD("oem_id","int32",298,4,SX_NONE),
    SX_FIELD("root_page","int32",302,4,SX_NONE),
    SX_FIELD("tree_depth","int16",306,2,SX_NONE),
    SX_FIELD("node_id","int16",308,2,SX_NONE),
    SX_FIELD("vol_seq_no","int16",310,2,SX_NONE),
    SX_FIELD("volume_mounted","int16",312,2,SX_FLAGS),
};
const sx_layout sxdt_lisa_mddf = {0x607a006aU,"lisa_mddf",sxdt_lisa_mddf_fields,SX_COUNT(sxdt_lisa_mddf_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_sfile_entry_fields[] = {
    SX_FIELD("hintaddr","int32",0,4,SX_NONE),
    SX_FIELD("fileaddr","int32",4,4,SX_NONE),
    SX_FIELD("filesize","int32",8,4,SX_SIZE),
    SX_FIELD("version","int16",12,2,SX_NONE),
};
const sx_layout sxdt_lisa_sfile_entry = {0x607a006bU,"lisa_sfile_entry",sxdt_lisa_sfile_entry_fields,SX_COUNT(sxdt_lisa_sfile_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_hint_entry_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_NONE),
    SX_FIELD("name_pad","byte[1]",33,1,SX_NONE),
    SX_FIELD("UID","uint32[2]",34,8,SX_ID),
    SX_FIELD("version","int16",42,2,SX_NONE),
    SX_FIELD("ftype","int8",44,1,SX_ID),
    SX_FIELD("ftype_pad","int8",45,1,SX_NONE),
    SX_FIELD("date_created","uint32",46,4,SX_TIME),
    SX_FIELD("date_accessed","uint32",50,4,SX_TIME),
    SX_FIELD("date_modified","uint32",54,4,SX_TIME),
    SX_FIELD("date_backup","uint32",58,4,SX_TIME),
    SX_FIELD("date_scavenged","uint32",62,4,SX_TIME),
    SX_FIELD("machine_id","int32",66,4,SX_NONE),
    SX_FIELD("killed","int8",70,1,SX_FLAGS),
    SX_FIELD("safety_on","int8",71,1,SX_FLAGS),
    SX_FIELD("protected","int8",72,1,SX_FLAGS),
    SX_FIELD("master","int8",73,1,SX_FLAGS),
    SX_FIELD("close_by_OS","int8",74,1,SX_FLAGS),
    SX_FIELD("file_open","int8",75,1,SX_FLAGS),
    SX_FIELD("result_scavenge","int16",76,2,SX_NONE),
    SX_FIELD("unusedi1","int16",78,2,SX_NONE),
    SX_FIELD("system_type","int16",80,2,SX_NONE),
    SX_FIELD("user_type","int16",82,2,SX_NONE),
    SX_FIELD("user_subtype","int16",84,2,SX_NONE),
    SX_FIELD("build_info","int16[4]",86,8,SX_NONE),
    SX_FIELD("file_portion","int16",94,2,SX_NONE),
    SX_FIELD("password","char[9]",96,9,SX_NONE),
    SX_FIELD("password_pad","char[3]",105,3,SX_NONE),
    SX_FIELD("parent_id","int16",108,2,SX_ID),
    SX_FIELD("filesystem_overhead","int16",110,2,SX_NONE),
};
const sx_layout sxdt_lisa_hint_entry = {0x607a006cU,"lisa_hint_entry",sxdt_lisa_hint_entry_fields,SX_COUNT(sxdt_lisa_hint_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_filemap_header_fields[] = {
    SX_FIELD("block_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("maximum_entries","int16",4,2,SX_COUNT_PROP),
    SX_FIELD("extent_count","int16",6,2,SX_COUNT_PROP),
};
const sx_layout sxdt_lisa_filemap_header = {0x607a006dU,"lisa_filemap_header",sxdt_lisa_filemap_header_fields,SX_COUNT(sxdt_lisa_filemap_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_filemap_extent_fields[] = {
    SX_FIELD("first_page","int32",0,4,SX_NONE),
    SX_FIELD("page_count","int16",4,2,SX_COUNT_PROP),
};
const sx_layout sxdt_lisa_filemap_extent = {0x607a006eU,"lisa_filemap_extent",sxdt_lisa_filemap_extent_fields,SX_COUNT(sxdt_lisa_filemap_extent_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_flat_catalog_entry_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_NONE),
    SX_FIELD("name_pad","byte[1]",33,1,SX_NONE),
    SX_FIELD("cetype","int8",34,1,SX_ID),
    SX_FIELD("cetype_pad","int8",35,1,SX_NONE),
    SX_FIELD("file_id","int16",36,2,SX_ID),
    SX_FIELD("attributes","int32",38,4,SX_NONE),
    SX_FIELD("readpage","int32",42,4,SX_NONE),
    SX_FIELD("readoffset","int16",46,2,SX_OFFSET),
    SX_FIELD("writepage","int32",48,4,SX_NONE),
    SX_FIELD("writeoffset","int16",52,2,SX_OFFSET),
};
const sx_layout sxdt_lisa_flat_catalog_entry = {0x607a006fU,"lisa_flat_catalog_entry",sxdt_lisa_flat_catalog_entry_fields,SX_COUNT(sxdt_lisa_flat_catalog_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_key_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("parent_id","int16",1,2,SX_ID),
    SX_FIELD("name","char[33]",3,33,SX_NONE),
    SX_FIELD("entry_type","int8",36,1,SX_ID),
    SX_FIELD("stored_padding","int8",37,1,SX_NONE),
};
const sx_layout sxdt_lisa_btree_key = {0x607a0070U,"lisa_btree_key",sxdt_lisa_btree_key_fields,SX_COUNT(sxdt_lisa_btree_key_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_directory_fields[] = {
    SX_FIELD("directory_id","int16",0,2,SX_ID),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("unused","int32",6,4,SX_NONE),
};
const sx_layout sxdt_lisa_btree_directory = {0x607a0071U,"lisa_btree_directory",sxdt_lisa_btree_directory_fields,SX_COUNT(sxdt_lisa_btree_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_object_fields[] = {
    SX_FIELD("file_id","int16",0,2,SX_ID),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("logical_size","int32",10,4,SX_SIZE),
    SX_FIELD("physical_size","int32",14,4,SX_SIZE),
    SX_FIELD("filesystem_overhead","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","int16",20,2,SX_FLAGS),
    SX_FIELD("unused","int32",22,4,SX_NONE),
};
const sx_layout sxdt_lisa_btree_object = {0x607a0072U,"lisa_btree_object",sxdt_lisa_btree_object_fields,SX_COUNT(sxdt_lisa_btree_object_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_thread_fields[] = {
    SX_FIELD("parent_id","int16",0,2,SX_ID),
    SX_FIELD("name","char[33]",2,33,SX_NONE),
    SX_FIELD("stored_padding","byte[1]",35,1,SX_NONE),
    SX_FIELD("unused","int32",36,4,SX_NONE),
};
const sx_layout sxdt_lisa_btree_thread = {0x607a0073U,"lisa_btree_thread",sxdt_lisa_btree_thread_fields,SX_COUNT(sxdt_lisa_btree_thread_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_footer_fields[] = {
    SX_FIELD("record_count","int16",0,2,SX_COUNT_PROP),
    SX_FIELD("previous_node","int32",2,4,SX_NONE),
    SX_FIELD("next_node","int32",6,4,SX_NONE),
    SX_FIELD("kind","int8",10,1,SX_ID),
    SX_FIELD("checksum","int8",11,1,SX_CHECKSUM),
};
const sx_layout sxdt_lisa_btree_footer = {0x607a0074U,"lisa_btree_footer",sxdt_lisa_btree_footer_fields,SX_COUNT(sxdt_lisa_btree_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_offset_fields[] = {
    SX_FIELD("record_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxdt_lisa_btree_offset = {0x607a0075U,"lisa_btree_offset",sxdt_lisa_btree_offset_fields,SX_COUNT(sxdt_lisa_btree_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_lisa_btree_child_fields[] = {
    SX_FIELD("child_page","int32",0,4,SX_NONE),
};
const sx_layout sxdt_lisa_btree_child = {0x607a0076U,"lisa_btree_child",sxdt_lisa_btree_child_fields,SX_COUNT(sxdt_lisa_btree_child_fields),SX_BE};
#define SXDT_LIMIT 24000U
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
typedef struct sxdt_lisa {sx_context*c;uint64_t data,tags;uint32_t blocks,base,version;} sxdt_lisa_view;
static bool sxdt_lisa_page(sxdt_lisa_view*l,uint32_t page,uint64_t*p){if(page>=l->blocks-l->base)return false;*p=84+(uint64_t)(l->base+page)*512;return sxdt_span(l->c,*p,512);}
static bool sxdt_lisa_tag(sxdt_lisa_view*l,uint32_t page,uint8_t*t){return page<l->blocks-l->base&&sxdt_read(l->c,l->tags+(uint64_t)(l->base+page)*12,t,12);}
static bool sxdt_lisa_filemap(sxdt_lisa_view*l,unsigned id,const uint8_t*sr){uint32_t page=sxdt32(sr,1),size=sxdt32(sr+8,1);uint64_t p;uint8_t tag[12],h[512],mddf[280];if(!sxdt_lisa_page(l,page,&p)||!sxdt_lisa_tag(l,page,tag)||(int16_t)sxdt16(tag+4,1)!=-(int32_t)id||sxdt16(tag+6,1)||!sxdt_read(l->c,p,h,512))return true;
 uint64_t m=84+(uint64_t)l->base*512;if(sxdt_read(l->c,m,mddf,280)){unsigned hint=sxdt16(mddf+278,1);if(hint<=512-112&&!SXDT_ADD(l->c,lisa_hint_entry,p+hint))return false;}
 unsigned map=128,max=41;if(l->version==14){uint32_t next=sxdt16(tag+8,1)&2047;uint8_t nt[12];if(next==2047||!sxdt_lisa_page(l,next,&p)||!sxdt_lisa_tag(l,next,nt)||(int16_t)sxdt16(nt+4,1)!=-(int32_t)id||(sxdt16(nt+10,1)&2047)!=page||!sxdt_read(l->c,p,h,512))return true;map=0;max=84;}
 if(!SXDT_ADD(l->c,lisa_filemap_header,p+map))return false;/* The native microfloppy reader fixes the physical map position and accepts a zero-terminated list. The serialized header additionally limits live entries: never promote unused nonzero slots beyond its count to metadata. Relocated/multipage map variants are outside this physical view. */unsigned capacity=sxdt16(h+map+4,1),declared=sxdt16(h+map+6,1),count=0;if(!capacity||capacity>max||declared>capacity)return true;for(;count<declared;count++){uint8_t*e=h+map+8+count*6;unsigned n=sxdt16(e+4,1);uint32_t start=sxdt32(e,1);if(!n)break;if(start>=l->blocks-l->base||n>l->blocks-l->base-start)break;}if(!SXDT_TABLE(l->c,lisa_filemap_extent,p+map+8,count))return false;
 if(id==4&&l->version!=17){/* Flat catalog bytes are exposed only if the complete54-byte record is physically contiguous in this extent. */uint64_t logical=0;for(unsigned i=0;i<count;i++){const uint8_t*e=h+map+8+i*6;uint32_t start=sxdt32(e,1),n=sxdt16(e+4,1);uint64_t at;if(!n||!sxdt_lisa_page(l,start,&at)||n>l->blocks-l->base-start)break;uint64_t bytes=(uint64_t)n*512;if(logical>=size)break;if(bytes>size-logical)bytes=size-logical;uint64_t q=logical%54?54-logical%54:0;for(;q+54<=bytes&&l->c->count<SXDT_LIMIT;q+=54)if(!SXDT_ADD(l->c,lisa_flat_catalog_entry,at+q))return false;logical+=bytes;}}
 return true;}
static bool sxdt_lisa_node_put(sxdt_lisa_view*l,const uint64_t*pages,const sx_layout*layout,unsigned at,unsigned n){const xx_data_struct_field_desc*f=layout->fields+layout->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||at>=2048||n>(2048-at)/z)return false;for(unsigned i=0;i<n;i++){uint64_t a=at+(uint64_t)i*z,p=pages[a/512]+a%512;bool contiguous=true;for(uint64_t q=0;q<z;){if(pages[(a+q)/512]+(a+q)%512!=p+q){contiguous=false;break;}uint64_t take=512-(a+q)%512;if(take>z-q)take=z-q;q+=take;}if(contiguous&&!sxdt_put(l->c,layout,p,1))return false;}return true;}
static bool sxdt_lisa_tree(sxdt_lisa_view*l,uint32_t root){uint32_t limit=l->blocks-l->base;uint8_t*seen=xx_rt_calloc(limit,1);uint32_t*q=xx_rt_calloc(limit,sizeof(*q));if(!seen||!q){xx_rt_free(seen);xx_rt_free(q);return false;}unsigned head=0,tail=0;bool ok=true;if(root<limit){seen[root]=1;q[tail++]=root;}while(head<tail&&l->c->count<SXDT_LIMIT&&!xx_pd_is_stopped(l->c->pd)){uint32_t start=q[head++],page=start,prior=UINT32_MAX;uint64_t pages[4];uint8_t node[2048],tag[12];bool valid=true;for(unsigned i=0;i<4;i++){if(!sxdt_lisa_page(l,page,&pages[i])||!sxdt_lisa_tag(l,page,tag)||sxdt16(tag+4,1)!=4||(i&&(sxdt16(tag+10,1)&2047)!=prior)||!sxdt_read(l->c,pages[i],node+i*512,512)){valid=false;break;}prior=page;page=sxdt16(tag+8,1)&2047;}if(!valid)continue;unsigned count=sxdt16(node+2036,1),kind=node[2046];if(count>128||kind>1)continue;if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_footer,2036,1)||!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_offset,2036-count*2,count)){ok=false;break;}uint32_t next=sxdt32(node+2042,1);if(next&&next<limit&&!seen[next]){seen[next]=1;q[tail++]=next;}if(kind){uint32_t child=sxdt32(node,1);if(child<limit&&!seen[child]){seen[child]=1;q[tail++]=child;}if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_child,0,1)){ok=false;break;}}
 for(unsigned i=0;i<count;i++){unsigned at=sxdt16(node+2034-i*2,1)+(kind?4:0),end=2036-count*2;if(at>end||end-at<38||node[at]!=36)continue;unsigned type=node[at+36],len=type==1?48:(type>=2&&type<=5)?64:type==8?78:38;if(len>end-at)continue;if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_key,at,1)){ok=false;break;}const sx_layout*row=type==1?&sxdt_lisa_btree_directory:(type>=2&&type<=5)?&sxdt_lisa_btree_object:type==8?&sxdt_lisa_btree_thread:NULL;if(row&&!sxdt_lisa_node_put(l,pages,row,at+38,1)){ok=false;break;}}if(!ok)break;
 }xx_rt_free(seen);xx_rt_free(q);return ok;}
static bool sxdt_lisa(sx_context*c){uint8_t h[84],boot[16],m[314];if(!sxdt_read(c,0,h,84)||h[0]>63||sxdt16(h+82,1)!=256)return false;sxdt_lisa_view l={c,sxdt32(h+64,1),0,0,0,0};if(!l.data||l.data%512||l.data/512>1000000)return false;l.blocks=(uint32_t)(l.data/512);l.tags=84+l.data;if(sxdt32(h+68,1)!=(uint64_t)l.blocks*12||!sxdt_span(c,l.tags,(uint64_t)l.blocks*12)||!sxdt_read(c,84,boot,16)||sxdt16(boot+4,1)!=43690||sxdt16(boot+6,1)!=2128)return false;l.base=sxdt16(boot+14,1);if(l.base>=l.blocks||!sxdt_read(c,84+(uint64_t)l.base*512,m,sizeof(m)))return false;l.version=sxdt16(m,1);if((l.version!=14&&l.version!=15&&l.version!=17)||sxdt16(m+126,1)!=512||!SXDT_ADD(c,lisa_dc42_header,0)||!SXDT_ADD(c,lisa_microfloppy_loader,84)||!SXDT_TABLE(c,lisa_microfloppy_tag,l.tags,l.blocks)||!SXDT_ADD(c,lisa_mddf,84+(uint64_t)l.base*512))return false;unsigned packing=sxdt16(m+152,1),blocks=sxdt16(m+154,1),files=sxdt16(m+160,1);uint32_t slist=sxdt32(m+148,1);if(!packing||packing>36||!files||files>32766||files>packing*blocks||slist>=l.blocks-l.base||blocks>l.blocks-l.base-slist)return true;
 for(unsigned b=0,id=0;b<blocks&&id<files&&c->count<SXDT_LIMIT;b++){uint64_t p;uint8_t t[12];if(!sxdt_lisa_page(&l,slist+b,&p)||!sxdt_lisa_tag(&l,slist+b,t)||sxdt16(t+4,1)!=3)break;unsigned n=files-id;if(n>packing)n=packing;if(!SXDT_TABLE(c,lisa_sfile_entry,p,n))return false;for(unsigned i=0;i<n;i++,id++){uint8_t sr[14];if(id<4)continue;if(!sxdt_read(c,p+i*14,sr,14)||!sxdt_lisa_filemap(&l,id,sr))return false;}}
 return l.version!=17||sxdt_lisa_tree(&l,sxdt32(m+302,1));}
bool sx_lisa_fs_build(sx_context*c)
{
bool ok=false;
ok=sxdt_lisa(c);
return ok&&c->count&&sxdt_finish(c);
}
