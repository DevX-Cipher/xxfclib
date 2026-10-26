/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Hsf data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_hsf_volume_prefix_fields[] = {
    SX_FIELD("descriptor_sector_le","uint32le",0,4,SX_NONE),
    SX_FIELD("descriptor_sector_be","uint32be",4,4,SX_NONE),
    SX_FIELD("type","uint8",8,1,SX_ID),
    SX_FIELD("signature","char[5]",9,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
    SX_FIELD("unused0","uint8",15,1,SX_RESERVED),
    SX_FIELD("system_identifier","char[32]",16,32,SX_STRING),
    SX_FIELD("volume_identifier","char[32]",48,32,SX_STRING),
    SX_FIELD("unused1","byte[8]",80,8,SX_RESERVED),
    SX_FIELD("volume_blocks_le","uint32le",88,4,SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be","uint32be",92,4,SX_COUNT_PROP),
    SX_FIELD("unused2","byte[32]",96,32,SX_RESERVED),
    SX_FIELD("volume_set_size_le","uint16le",128,2,SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be","uint16be",130,2,SX_COUNT_PROP),
    SX_FIELD("sequence_number_le","uint16le",132,2,SX_ID),
    SX_FIELD("sequence_number_be","uint16be",134,2,SX_ID),
    SX_FIELD("block_size_le","uint16le",136,2,SX_SIZE),
    SX_FIELD("block_size_be","uint16be",138,2,SX_SIZE),
    SX_FIELD("path_table_size_le","uint32le",140,4,SX_SIZE),
    SX_FIELD("path_table_size_be","uint32be",144,4,SX_SIZE),
    SX_FIELD("path_table_locations","byte[32]",148,32,SX_NONE),
};
const sx_layout sxvi_hsf_volume_prefix = {0x60530052U,"hsf_volume_prefix",sxvi_hsf_volume_prefix_fields,SX_COUNT(sxvi_hsf_volume_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_hsf_descriptor_header_fields[] = {
    SX_FIELD("descriptor_sector_le","uint32le",0,4,SX_NONE),
    SX_FIELD("descriptor_sector_be","uint32be",4,4,SX_NONE),
    SX_FIELD("type","uint8",8,1,SX_ID),
    SX_FIELD("signature","char[5]",9,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
};
const sx_layout sxvi_hsf_descriptor_header = {0x60530053U,"hsf_descriptor_header",sxvi_hsf_descriptor_header_fields,SX_COUNT(sxvi_hsf_descriptor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_hsf_directory_record_fields[] = {
    SX_FIELD("record_size","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("extent_block_le","uint32le",2,4,SX_NONE),
    SX_FIELD("extent_block_be","uint32be",6,4,SX_NONE),
    SX_FIELD("data_size_le","uint32le",10,4,SX_SIZE),
    SX_FIELD("data_size_be","uint32be",14,4,SX_SIZE),
    SX_FIELD("year_since1900","uint8",18,1,SX_NONE),
    SX_FIELD("month","uint8",19,1,SX_NONE),
    SX_FIELD("day","uint8",20,1,SX_NONE),
    SX_FIELD("hour","uint8",21,1,SX_NONE),
    SX_FIELD("minute","uint8",22,1,SX_NONE),
    SX_FIELD("second","uint8",23,1,SX_NONE),
    SX_FIELD("flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",25,1,SX_RESERVED),
    SX_FIELD("interleave_unit_blocks","uint8",26,1,SX_COUNT_PROP),
    SX_FIELD("interleave_gap_blocks","uint8",27,1,SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le","uint16le",28,2,SX_ID),
    SX_FIELD("volume_sequence_be","uint16be",30,2,SX_ID),
    SX_FIELD("identifier_size","uint8",32,1,SX_SIZE),
};
const sx_layout sxvi_hsf_directory_record = {0x60530054U,"hsf_directory_record",sxvi_hsf_directory_record_fields,SX_COUNT(sxvi_hsf_directory_record_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_hsf_volume_identifiers_fields[] = {
    SX_FIELD("volume_set_identifier","char[128]",0,128,SX_STRING),
    SX_FIELD("publisher_identifier","char[128]",128,128,SX_STRING),
    SX_FIELD("preparer_identifier","char[128]",256,128,SX_STRING),
    SX_FIELD("application_identifier","char[128]",384,128,SX_STRING),
    SX_FIELD("copyright_identifier","char[32]",512,32,SX_STRING),
    SX_FIELD("abstract_identifier","char[32]",544,32,SX_STRING),
    SX_FIELD("creation_time","char[16]",576,16,SX_STRING),
    SX_FIELD("modification_time","char[16]",592,16,SX_STRING),
    SX_FIELD("expiration_time","char[16]",608,16,SX_STRING),
    SX_FIELD("effective_time","char[16]",624,16,SX_STRING),
    SX_FIELD("file_structure_version","uint8",640,1,SX_ID),
};
const sx_layout sxvi_hsf_volume_identifiers = {0x60530055U,"hsf_volume_identifiers",sxvi_hsf_volume_identifiers_fields,SX_COUNT(sxvi_hsf_volume_identifiers_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
typedef struct sxvi_directory{uint64_t p,size;unsigned depth;}sxvi_directory;
static bool sxvi_hsf(sx_context*c){uint8_t h[2048];uint64_t bs=0,blocks=0,root=0,rootsize=0;bool found=false;
 for(unsigned i=16;i<80;i++){uint64_t p=(uint64_t)i*2048;if(!sxvi_read(c,p,h,2048)||xx_rt_memcmp(h+9,"CDROM",5)||h[14]!=1||sxvi32(h,0)!=i||sxvi32(h+4,1)!=i)break;
  if(h[8]==1){if(!SXVI_ADD(c,hsf_volume_prefix,p)||!SXVI_ADD(c,hsf_directory_record,p+180)||!SXVI_ADD(c,hsf_volume_identifiers,p+214))return false;if(!found){bs=sxvi16(h+136,0);blocks=sxvi32(h+88,0);root=(uint64_t)sxvi32(h+182,0)+h[181];rootsize=sxvi32(h+190,0);found=true;}}
  else if(!SXVI_ADD(c,hsf_descriptor_header,p))return false;if(h[8]==255)break;
 }
 if(!found)return false;if((bs!=512&&bs!=1024&&bs!=2048)||!blocks||blocks>(uint64_t)c->size/bs||root>=blocks||rootsize>(blocks-root)*bs)return true;
 sxvi_directory*q=xx_rt_calloc(4096,sizeof(*q));if(!q)return false;size_t count=1,index=0;uint64_t walked=0;bool ok=true;q[0]=(sxvi_directory){root*bs,rootsize,0};
 while(ok&&index<count&&c->count<SXVI_LIMIT){sxvi_directory d=q[index++];if(d.depth>32||d.size>UINT64_C(16777216)||walked>UINT64_C(67108864)-d.size||!sxvi_span(c,d.p,d.size))continue;walked+=d.size;
  for(uint64_t pos=0;pos<d.size&&ok&&c->count<SXVI_LIMIT;pos+=bs){uint64_t n=d.size-pos;if(n>bs)n=bs;if(!sxvi_read(c,d.p+pos,h,(size_t)n))break;
   for(uint64_t at=0;at+33<=n;){unsigned z=h[at],len=h[at+32];if(!z)break;if(z<33||z>n-at||!len||len>z-33)break;if(!SXVI_ADD(c,hsf_directory_record,d.p+pos+at)){ok=false;break;}uint64_t block=sxvi32(h+at+2,0),size=sxvi32(h+at+10,0);bool child=(h[at+24]&2)&&!(len==1&&(h[at+33]==0||h[at+33]==1));
    if(child&&count<4096&&block==sxvi32(h+at+6,1)&&size==sxvi32(h+at+14,1)){block+=h[at+1];if(block<blocks&&size<=(blocks-block)*bs){bool seen=false;for(size_t k=0;k<count;k++)if(q[k].p==block*bs)seen=true;if(!seen)q[count++]=(sxvi_directory){block*bs,size,d.depth+1};}}
    at+=z;
   }
  }
 }xx_rt_free(q);return ok;
}
bool sx_hsf_build(sx_context*c)
{
 return sxvi_hsf(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
