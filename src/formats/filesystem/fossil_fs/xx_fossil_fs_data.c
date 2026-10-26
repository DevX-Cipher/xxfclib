/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FOSSIL FS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_fossil_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("block_size","uint16",6,2,SX_SIZE),
    SX_FIELD("super_block","uint32",8,4,SX_NONE),
    SX_FIELD("label_block","uint32",12,4,SX_NONE),
    SX_FIELD("data_block","uint32",16,4,SX_NONE),
    SX_FIELD("end_block","uint32",20,4,SX_NONE),
};
const sx_layout sxmf_fossil_header = {0x60420002U,"fossil_header",sxmf_fossil_header_fields,SX_COUNT(sxmf_fossil_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_fossil_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("epoch_low","uint32",6,4,SX_NONE),
    SX_FIELD("epoch_high","uint32",10,4,SX_NONE),
    SX_FIELD("next_qid","uint64",14,8,SX_ID),
    SX_FIELD("active_root_block","int32",22,4,SX_NONE),
    SX_FIELD("next_archive_root_block","int32",26,4,SX_NONE),
    SX_FIELD("current_archive_root_block","int32",30,4,SX_NONE),
    SX_FIELD("last_archive_score","byte[20]",34,20,SX_SIGNATURE),
    SX_FIELD("name","char[128]",54,128,SX_STRING),
};
const sx_layout sxmf_fossil_superblock = {0x60420003U,"fossil_superblock",sxmf_fossil_superblock_fields,SX_COUNT(sxmf_fossil_superblock_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_fossil_label_fields[] = {
    SX_FIELD("state","uint8",0,1,SX_FLAGS),
    SX_FIELD("type","uint8",1,1,SX_ID),
    SX_FIELD("epoch","uint32",2,4,SX_NONE),
    SX_FIELD("epoch_close","uint32",6,4,SX_NONE),
    SX_FIELD("tag","uint32",10,4,SX_ID),
};
const sx_layout sxmf_fossil_label = {0x60420004U,"fossil_label",sxmf_fossil_label_fields,SX_COUNT(sxmf_fossil_label_fields),SX_BE};
#define SXMF_LIMIT 24000U
#define SXMF_INODES 262144U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_fossil(sx_context*c){uint8_t h[24],b[182];if(!sxmf_read(c,131072,h,24)||sxmf32(h,1)!=0x3776ae89U||!SXMF_ADD(c,fossil_header,131072))return false;uint64_t bs=sxmf16(h+6,1),sb=sxmf32(h+8,1),labels=sxmf32(h+12,1),data=sxmf32(h+16,1),end=sxmf32(h+20,1);if(bs<512||!sxmf_pow(bs)||end>(uint64_t)c->size/bs||sb>=end)return true;
 if(sxmf_read(c,sb*bs,b,182)&&sxmf32(b,1)==0x2340a3b1&&!SXMF_ADD(c,fossil_superblock,sb*bs))return false;
 if(labels<data&&data<end){uint64_t slots=bs/14,total=end-data,limit=(data-labels)*slots;if(total>limit)total=limit;if(total>SXMF_INODES)total=SXMF_INODES;for(uint64_t i=0;i<total&&c->count<SXMF_LIMIT;){uint64_t n=total-i;if(n>slots)n=slots;if(!SXMF_TABLE(c,fossil_label,(labels+i/slots)*bs,n))return false;i+=n;}}
 return true;
}
bool sx_fossil_fs_build(sx_context*c)
{
 return sxmf_fossil(c);
}
#undef SXMF_LIMIT
#undef SXMF_INODES
#undef SXMF_ADD
#undef SXMF_TABLE
