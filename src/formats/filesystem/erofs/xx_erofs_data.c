/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EROFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_erofs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("features_compat","uint32",8,4,SX_FLAGS),
    SX_FIELD("block_size_bits","uint8",12,1,SX_NONE),
    SX_FIELD("extension_slots","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("root_inode","uint16",14,2,SX_ID),
    SX_FIELD("inode_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("build_time","uint64",24,8,SX_TIME),
    SX_FIELD("build_nanoseconds","uint32",32,4,SX_NONE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("metadata_block","uint32",40,4,SX_NONE),
    SX_FIELD("xattr_block","uint32",44,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("volume_name","char[16]",64,16,SX_STRING),
    SX_FIELD("features_incompat","uint32",80,4,SX_FLAGS),
    SX_FIELD("compression_algorithms_or_lz4_distance","uint16",84,2,SX_NONE),
    SX_FIELD("extra_device_count","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("device_table_slot","uint16",88,2,SX_NONE),
    SX_FIELD("directory_block_bits","uint8",90,1,SX_NONE),
    SX_FIELD("xattr_prefix_count","uint8",91,1,SX_COUNT_PROP),
    SX_FIELD("xattr_prefix_start","uint32",92,4,SX_NONE),
    SX_FIELD("packed_inode","uint64",96,8,SX_ID),
    SX_FIELD("reserved_or_extension","byte[24]",104,24,SX_NONE),
};
const sx_layout sxmf_erofs_superblock = {0x60420045U,"erofs_superblock",sxmf_erofs_superblock_fields,SX_COUNT(sxmf_erofs_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_erofs_inode_compact_fields[] = {
    SX_FIELD("format","uint16",0,2,SX_FLAGS),
    SX_FIELD("xattr_count","uint16",2,2,SX_NONE),
    SX_FIELD("mode","uint16",4,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("block_or_device_or_chunk_info","uint32",16,4,SX_NONE),
    SX_FIELD("inode_number","uint32",20,4,SX_ID),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
const sx_layout sxmf_erofs_inode_compact = {0x60420046U,"erofs_inode_compact",sxmf_erofs_inode_compact_fields,SX_COUNT(sxmf_erofs_inode_compact_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_erofs_inode_extended_fields[] = {
    SX_FIELD("format","uint16",0,2,SX_FLAGS),
    SX_FIELD("xattr_count","uint16",2,2,SX_NONE),
    SX_FIELD("mode","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("block_or_device_or_chunk_info","uint32",16,4,SX_NONE),
    SX_FIELD("inode_number","uint32",20,4,SX_ID),
    SX_FIELD("uid","uint32",24,4,SX_ID),
    SX_FIELD("gid","uint32",28,4,SX_ID),
    SX_FIELD("modification_time","uint64",32,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","uint32",40,4,SX_NONE),
    SX_FIELD("link_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[16]",48,16,SX_RESERVED),
};
const sx_layout sxmf_erofs_inode_extended = {0x60420047U,"erofs_inode_extended",sxmf_erofs_inode_extended_fields,SX_COUNT(sxmf_erofs_inode_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_erofs_directory_entry_fields[] = {
    SX_FIELD("inode_id","uint64",0,8,SX_ID),
    SX_FIELD("name_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("type","uint8",10,1,SX_ID),
    SX_FIELD("reserved","uint8",11,1,SX_RESERVED),
};
const sx_layout sxmf_erofs_directory_entry = {0x60420048U,"erofs_directory_entry",sxmf_erofs_directory_entry_fields,SX_COUNT(sxmf_erofs_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_erofs_device_slot_fields[] = {
    SX_FIELD("tag","char[64]",0,64,SX_STRING),
    SX_FIELD("block_count","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("mapped_block","uint32",68,4,SX_NONE),
    SX_FIELD("reserved","byte[56]",72,56,SX_RESERVED),
};
const sx_layout sxmf_erofs_device_slot = {0x60420049U,"erofs_device_slot",sxmf_erofs_device_slot_fields,SX_COUNT(sxmf_erofs_device_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_erofs_chunk_block_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
};
const sx_layout sxmf_erofs_chunk_block = {0x6042004aU,"erofs_chunk_block",sxmf_erofs_chunk_block_fields,SX_COUNT(sxmf_erofs_chunk_block_fields),SX_LE};
#define SXMF_LIMIT 24000U
#define SXMF_INODES 262144U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_erofs(sx_context*c){uint8_t h[128],in[64];if(!sxmf_read(c,1024,h,128)||sxmf32(h,0)!=0xe0f5e1e2U||!SXMF_ADD(c,erofs_superblock,1024))return false;unsigned shift=h[12];if(shift<9||shift>16)return true;uint64_t bs=UINT64_C(1)<<shift,meta=(uint64_t)sxmf32(h+40,0)*bs,devices=sxmf16(h+86,0),slots=(uint64_t)sxmf16(h+88,0)*128;if(devices<=256&&sxmf_span(c,slots,devices*128)&&!SXMF_TABLE(c,erofs_device_slot,slots,devices))return false;sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));uint8_t*b=xx_rt_malloc((size_t)bs);if(!q||!b){xx_rt_free(q);xx_rt_free(b);return false;}bool ok=true;uint64_t root=sxmf16(h+14,0);/* Encode NID+1 so the generic work queue can retain NID zero. */sxmf_queue_add(q,root+1,0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){sxmf_task t=q->items[q->index++];uint64_t nid=t.p-1;if(nid>(UINT64_MAX-meta)/32)continue;uint64_t p=meta+nid*32;if(!sxmf_read(c,p,in,32))continue;unsigned format=sxmf16(in,0),layout=(format>>1)&7,iz=(format&1)?64:32,mode=sxmf16(in+4,0);if(format&0xfff0||layout>4||!sxmf_read(c,p,in,iz))continue;if(!sxmf_put(c,iz==64?&sxmf_erofs_inode_extended:&sxmf_erofs_inode_compact,p,1)){ok=false;break;}uint64_t size=iz==64?sxmf64(in+8,0):sxmf32(in+8,0),block=sxmf32(in+16,0);if(sxmf16(in+2,0))continue;
  if(layout==4){if(block<=16){uint64_t chunk=bs<<block,n=size/chunk+(size%chunk!=0);if(n<=SXMF_INODES&&sxmf_span(c,p+iz,n*4)&&!SXMF_TABLE(c,erofs_chunk_block,p+iz,n)){ok=false;break;}}continue;}
  if((mode&0170000)!=0040000||(layout!=0&&layout!=2)||size>UINT64_C(16777216))continue;uint64_t whole=layout==2?size/bs*bs:size;
  for(uint64_t pos=0;pos<size&&ok&&c->count<SXMF_LIMIT;pos+=bs){uint64_t n=size-pos;if(n>bs)n=bs;uint64_t at=pos<whole?block*bs+pos:p+iz+pos-whole;if(!sxmf_read(c,at,b,(size_t)n)||n<12)break;uint64_t first=sxmf16(b+8,0);if(!first||first%12||first>n)break;for(uint64_t j=0;j<first;j+=12){uint64_t no=sxmf16(b+j+8,0),end=j+12<first?sxmf16(b+j+20,0):n;if(no<first||end<no||end>n)break;if(!SXMF_ADD(c,erofs_directory_entry,at+j)){ok=false;break;}uint64_t child=sxmf64(b+j,0);if(child!=UINT64_MAX)sxmf_queue_add(q,child+1,0,t.depth+1);}}
 }
 xx_rt_free(q);xx_rt_free(b);return ok;
}
bool sx_erofs_build(sx_context*c)
{
 return sxmf_erofs(c);
}
#undef SXMF_LIMIT
#undef SXMF_INODES
#undef SXMF_ADD
#undef SXMF_TABLE
