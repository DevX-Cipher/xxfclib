/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HPFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_hpfs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",8,1,SX_ID),
    SX_FIELD("functional_version","uint8",9,1,SX_ID),
    SX_FIELD("reserved0","uint16",10,2,SX_RESERVED),
    SX_FIELD("root_fnode_sector","uint32",12,4,SX_NONE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("bad_sector_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_directory_sector","uint32",24,4,SX_NONE),
    SX_FIELD("reserved1","uint32",28,4,SX_RESERVED),
    SX_FIELD("bad_block_directory_sector","uint32",32,4,SX_NONE),
    SX_FIELD("reserved2","uint32",36,4,SX_RESERVED),
    SX_FIELD("last_check","uint32",40,4,SX_TIME),
    SX_FIELD("last_optimization","uint32",44,4,SX_TIME),
    SX_FIELD("directory_band_sectors","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("directory_band_first_sector","uint32",52,4,SX_NONE),
    SX_FIELD("directory_band_last_sector","uint32",56,4,SX_NONE),
    SX_FIELD("directory_band_bitmap_sector","uint32",60,4,SX_NONE),
    SX_FIELD("unused_volume_name","char[32]",64,32,SX_STRING),
    SX_FIELD("user_id_table_sector","uint32",96,4,SX_NONE),
    SX_FIELD("reserved3","byte[412]",100,412,SX_RESERVED),
};
const sx_layout sxmf_hpfs_superblock = {0x6042002cU,"hpfs_superblock",sxmf_hpfs_superblock_fields,SX_COUNT(sxmf_hpfs_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_spareblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("hpfs386_flags","uint8",9,1,SX_FLAGS),
    SX_FIELD("multimedia_contiguity","uint8",10,1,SX_NONE),
    SX_FIELD("reserved0","uint8",11,1,SX_RESERVED),
    SX_FIELD("hotfix_map_sector","uint32",12,4,SX_NONE),
    SX_FIELD("hotfix_used_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("hotfix_capacity","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("free_spare_dnodes","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("spare_dnode_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("code_page_directory_sector","uint32",32,4,SX_NONE),
    SX_FIELD("code_page_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("superblock_crc","uint32",40,4,SX_CHECKSUM),
    SX_FIELD("spareblock_crc","uint32",44,4,SX_CHECKSUM),
    SX_FIELD("reserved1","byte[60]",48,60,SX_RESERVED),
    SX_FIELD("spare_dnode_sectors","uint32[100]",108,400,SX_NONE),
    SX_FIELD("reserved2","uint32",508,4,SX_RESERVED),
};
const sx_layout sxmf_hpfs_spareblock = {0x6042002dU,"hpfs_spareblock",sxmf_hpfs_spareblock_fields,SX_COUNT(sxmf_hpfs_spareblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_fnode_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("read_history","uint32[2]",4,8,SX_NONE),
    SX_FIELD("name_length","uint8",12,1,SX_SIZE),
    SX_FIELD("truncated_name","char[15]",13,15,SX_STRING),
    SX_FIELD("parent_fnode_sector","uint32",28,4,SX_NONE),
    SX_FIELD("external_acl_size","uint32",32,4,SX_SIZE),
    SX_FIELD("acl_sector","uint32",36,4,SX_NONE),
    SX_FIELD("inline_acl_size","uint16",40,2,SX_SIZE),
    SX_FIELD("acl_anode","uint8",42,1,SX_FLAGS),
    SX_FIELD("history_bit_count","uint8",43,1,SX_COUNT_PROP),
    SX_FIELD("external_ea_size","uint32",44,4,SX_SIZE),
    SX_FIELD("ea_sector","uint32",48,4,SX_NONE),
    SX_FIELD("inline_ea_size","uint16",52,2,SX_SIZE),
    SX_FIELD("flags","uint16",54,2,SX_FLAGS),
};
const sx_layout sxmf_hpfs_fnode_prefix = {0x6042002eU,"hpfs_fnode_prefix",sxmf_hpfs_fnode_prefix_fields,SX_COUNT(sxmf_hpfs_fnode_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_btree_header_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("reserved","byte[3]",1,3,SX_RESERVED),
    SX_FIELD("free_nodes","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("used_nodes","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("first_free","uint16",6,2,SX_OFFSET),
};
const sx_layout sxmf_hpfs_btree_header = {0x6042002fU,"hpfs_btree_header",sxmf_hpfs_btree_header_fields,SX_COUNT(sxmf_hpfs_btree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_extent_fields[] = {
    SX_FIELD("file_sector","uint32",0,4,SX_NONE),
    SX_FIELD("sector_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("disk_sector","uint32",8,4,SX_NONE),
};
const sx_layout sxmf_hpfs_extent = {0x60420030U,"hpfs_extent",sxmf_hpfs_extent_fields,SX_COUNT(sxmf_hpfs_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_btree_child_fields[] = {
    SX_FIELD("file_sector_limit","uint32",0,4,SX_NONE),
    SX_FIELD("anode_sector","uint32",4,4,SX_NONE),
};
const sx_layout sxmf_hpfs_btree_child = {0x60420031U,"hpfs_btree_child",sxmf_hpfs_btree_child_fields,SX_COUNT(sxmf_hpfs_btree_child_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_fnode_tail_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("required_ea_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("user_id","byte[16]",8,16,SX_NONE),
    SX_FIELD("ea_offset","uint16",24,2,SX_OFFSET),
    SX_FIELD("dasd_limit_threshold","uint8",26,1,SX_NONE),
    SX_FIELD("dasd_limit_delta","uint8",27,1,SX_NONE),
    SX_FIELD("dasd_limit","uint32",28,4,SX_NONE),
    SX_FIELD("dasd_usage","uint32",32,4,SX_NONE),
};
const sx_layout sxmf_hpfs_fnode_tail = {0x60420032U,"hpfs_fnode_tail",sxmf_hpfs_fnode_tail_fields,SX_COUNT(sxmf_hpfs_fnode_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_anode_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_sector","uint32",4,4,SX_NONE),
    SX_FIELD("parent_sector","uint32",8,4,SX_NONE),
};
const sx_layout sxmf_hpfs_anode_header = {0x60420033U,"hpfs_anode_header",sxmf_hpfs_anode_header_fields,SX_COUNT(sxmf_hpfs_anode_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_dnode_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("first_free","uint32",4,4,SX_OFFSET),
    SX_FIELD("root_and_activity","uint8",8,1,SX_FLAGS),
    SX_FIELD("activity","byte[3]",9,3,SX_NONE),
    SX_FIELD("parent_sector","uint32",12,4,SX_NONE),
    SX_FIELD("self_sector","uint32",16,4,SX_NONE),
};
const sx_layout sxmf_hpfs_dnode_header = {0x60420034U,"hpfs_dnode_header",sxmf_hpfs_dnode_header_fields,SX_COUNT(sxmf_hpfs_dnode_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_directory_entry_fields[] = {
    SX_FIELD("length","uint16",0,2,SX_SIZE),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("attributes","uint8",3,1,SX_FLAGS),
    SX_FIELD("fnode_sector","uint32",4,4,SX_NONE),
    SX_FIELD("write_time","uint32",8,4,SX_TIME),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("creation_time","uint32",20,4,SX_TIME),
    SX_FIELD("ea_size","uint32",24,4,SX_SIZE),
    SX_FIELD("acl_count_bits","uint8",28,1,SX_FLAGS),
    SX_FIELD("code_page_index","uint8",29,1,SX_NONE),
    SX_FIELD("name_length","uint8",30,1,SX_SIZE),
};
const sx_layout sxmf_hpfs_directory_entry = {0x60420035U,"hpfs_directory_entry",sxmf_hpfs_directory_entry_fields,SX_COUNT(sxmf_hpfs_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hpfs_down_pointer_fields[] = {
    SX_FIELD("dnode_sector","uint32",0,4,SX_NONE),
};
const sx_layout sxmf_hpfs_down_pointer = {0x60420036U,"hpfs_down_pointer",sxmf_hpfs_down_pointer_fields,SX_COUNT(sxmf_hpfs_down_pointer_fields),SX_LE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
static bool sxmf_hpfs(sx_context*c){
 uint8_t b[2048],sb[512];if(!sxmf_read(c,8192,sb,512)||sxmf32(sb,0)!=0xf995e849U||sxmf32(sb+4,0)!=0xfa53e9c5U||!SXMF_ADD(c,hpfs_superblock,8192))return false;
 if(sxmf_read(c,8704,b,512)&&sxmf32(b,0)==0xf9911849U&&sxmf32(b+4,0)==0xfa5229c5U&&!SXMF_ADD(c,hpfs_spareblock,8704))return false;
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;sxmf_queue_add(q,(uint64_t)sxmf32(sb+12,0)*512,0,0);bool ok=true;
 while(q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){
  sxmf_task t=q->items[q->index++];if(!sxmf_read(c,t.p,b,t.kind==2?2048:512))continue;uint64_t off=0,capacity=0;
  if(t.kind==0){if(sxmf32(b,0)!=0xf7e40aaeU)continue;if(!SXMF_ADD(c,hpfs_fnode_prefix,t.p)||!SXMF_ADD(c,hpfs_btree_header,t.p+56)||!SXMF_ADD(c,hpfs_fnode_tail,t.p+160)){ok=false;break;}off=64;capacity=96;}
  else if(t.kind==1){if(sxmf32(b,0)!=0x37e40aaeU)continue;if(!SXMF_ADD(c,hpfs_anode_header,t.p)||!SXMF_ADD(c,hpfs_btree_header,t.p+12)){ok=false;break;}off=20;capacity=480;}
  else{if(sxmf32(b,0)!=0x77e40aaeU)continue;uint64_t end=sxmf32(b+4,0);if(end<20||end>2048)continue;if(!SXMF_ADD(c,hpfs_dnode_header,t.p)){ok=false;break;}
   for(uint64_t p=20;p+31<=end;){uint64_t z=sxmf16(b+p,0),n=b[p+30];unsigned flags=b[p+2];if(z<31||z>end-p||n>z-31||(flags&4&&z<35+n))break;if(!SXMF_ADD(c,hpfs_directory_entry,t.p+p)){ok=false;break;}if(flags&4){if(!SXMF_ADD(c,hpfs_down_pointer,t.p+p+z-4)){ok=false;break;}sxmf_queue_add(q,(uint64_t)sxmf32(b+p+z-4,0)*512,2,t.depth+1);}if(!(flags&8))sxmf_queue_add(q,(uint64_t)sxmf32(b+p+4,0)*512,0,t.depth+1);p+=z;if(flags&8)break;}if(!ok)break;continue;
  }
  unsigned internal=b[off-8]&0x80,used=b[off-3];uint64_t stride=internal?8:12;if(used>capacity/stride)continue;
  if(!sxmf_put(c,internal?&sxmf_hpfs_btree_child:&sxmf_hpfs_extent,t.p+off,used)){ok=false;break;}
  for(unsigned i=0;i<used;i++){uint8_t*r=b+off+i*stride;if(internal)sxmf_queue_add(q,(uint64_t)sxmf32(r+4,0)*512,1,t.depth+1);else if(t.kind==0&&(sxmf16(b+54,0)&0x100)){uint64_t sector=sxmf32(r+8,0),count=sxmf32(r+4,0);for(uint64_t j=0;j+4<=count&&j<4096;j+=4)sxmf_queue_add(q,(sector+j)*512,2,t.depth+1);}}
 }
 xx_rt_free(q);return ok;
}
bool sx_hpfs_build(sx_context*c)
{
 return sxmf_hpfs(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
