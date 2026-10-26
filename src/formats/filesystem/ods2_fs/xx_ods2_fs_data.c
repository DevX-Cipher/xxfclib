/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ODS2_FS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_ods_home_block_fields[] = {
    SX_FIELD("home_lbn","uint32",0,4,SX_NONE),
    SX_FIELD("alternate_home_lbn","uint32",4,4,SX_NONE),
    SX_FIELD("alternate_index_lbn","uint32",8,4,SX_NONE),
    SX_FIELD("structure_level","uint16",12,2,SX_ID),
    SX_FIELD("cluster_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("home_vbn","uint16",16,2,SX_NONE),
    SX_FIELD("alternate_home_vbn","uint16",18,2,SX_NONE),
    SX_FIELD("alternate_index_vbn","uint16",20,2,SX_NONE),
    SX_FIELD("index_bitmap_vbn","uint16",22,2,SX_NONE),
    SX_FIELD("index_bitmap_lbn","uint32",24,4,SX_NONE),
    SX_FIELD("maximum_files","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("index_bitmap_blocks","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("reserved_files","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",36,2,SX_ID),
    SX_FIELD("relative_volume","uint16",38,2,SX_NONE),
    SX_FIELD("volume_count","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("characteristics","uint16",42,2,SX_FLAGS),
    SX_FIELD("owner_uic","uint32",44,4,SX_ID),
    SX_FIELD("security_mask","uint32",48,4,SX_FLAGS),
    SX_FIELD("protection","uint16",52,2,SX_FLAGS),
    SX_FIELD("default_file_protection","uint16",54,2,SX_FLAGS),
    SX_FIELD("default_record_protection","uint16",56,2,SX_FLAGS),
    SX_FIELD("checksum1","uint16",58,2,SX_CHECKSUM),
    SX_FIELD("creation_time","uint64",60,8,SX_TIME),
    SX_FIELD("window_size","uint8",68,1,SX_COUNT_PROP),
    SX_FIELD("directory_cache_limit","uint8",69,1,SX_COUNT_PROP),
    SX_FIELD("default_allocation_blocks","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("minimum_retention","uint64",72,8,SX_NONE),
    SX_FIELD("maximum_retention","uint64",80,8,SX_NONE),
    SX_FIELD("revision_time","uint64",88,8,SX_TIME),
    SX_FIELD("minimum_security_class","byte[20]",96,20,SX_NONE),
    SX_FIELD("maximum_security_class","byte[20]",116,20,SX_NONE),
    SX_FIELD("file_lookup_number","uint16",136,2,SX_NONE),
    SX_FIELD("file_lookup_sequence","uint16",138,2,SX_NONE),
    SX_FIELD("file_lookup_relative_volume","uint8",140,1,SX_NONE),
    SX_FIELD("file_lookup_number_high","uint8",141,1,SX_NONE),
    SX_FIELD("lowest_structure_level","uint16",142,2,SX_ID),
    SX_FIELD("highest_structure_level","uint16",144,2,SX_ID),
    SX_FIELD("copy_time","uint64",146,8,SX_TIME),
    SX_FIELD("reserved0","byte[302]",154,302,SX_RESERVED),
    SX_FIELD("serial_number","uint32",456,4,SX_ID),
    SX_FIELD("volume_set_name","char[12]",460,12,SX_NONE),
    SX_FIELD("volume_name","char[12]",472,12,SX_NONE),
    SX_FIELD("owner_name","char[12]",484,12,SX_NONE),
    SX_FIELD("format_identifier","char[12]",496,12,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",508,2,SX_RESERVED),
    SX_FIELD("checksum2","uint16",510,2,SX_CHECKSUM),
};
const sx_layout sxcf_ods_home_block = {0x603d0057U,"ods_home_block",sxcf_ods_home_block_fields,SX_COUNT(sxcf_ods_home_block_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_file_header_fields[] = {
    SX_FIELD("identification_word_offset","uint8",0,1,SX_NONE),
    SX_FIELD("map_word_offset","uint8",1,1,SX_NONE),
    SX_FIELD("access_control_word_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved_word_offset","uint8",3,1,SX_NONE),
    SX_FIELD("segment_number","uint16",4,2,SX_NONE),
    SX_FIELD("structure_level","uint16",6,2,SX_ID),
    SX_FIELD("file_number_low","uint16",8,2,SX_NONE),
    SX_FIELD("file_sequence","uint16",10,2,SX_NONE),
    SX_FIELD("file_relative_volume","uint8",12,1,SX_NONE),
    SX_FIELD("file_number_high","uint8",13,1,SX_NONE),
    SX_FIELD("extension_number_low","uint16",14,2,SX_NONE),
    SX_FIELD("extension_sequence","uint16",16,2,SX_NONE),
    SX_FIELD("extension_relative_volume","uint8",18,1,SX_NONE),
    SX_FIELD("extension_number_high","uint8",19,1,SX_NONE),
    SX_FIELD("record_type_organization","uint8",20,1,SX_FLAGS),
    SX_FIELD("record_attributes","uint8",21,1,SX_FLAGS),
    SX_FIELD("record_size","uint16",22,2,SX_SIZE),
    SX_FIELD("allocated_block_high","uint16",24,2,SX_NONE),
    SX_FIELD("allocated_block_low","uint16",26,2,SX_NONE),
    SX_FIELD("eof_block_high","uint16",28,2,SX_NONE),
    SX_FIELD("eof_block_low","uint16",30,2,SX_NONE),
    SX_FIELD("first_free_byte","uint16",32,2,SX_OFFSET),
    SX_FIELD("bucket_blocks","uint8",34,1,SX_COUNT_PROP),
    SX_FIELD("fixed_control_size","uint8",35,1,SX_SIZE),
    SX_FIELD("maximum_record_size","uint16",36,2,SX_SIZE),
    SX_FIELD("default_extend_blocks","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("global_buffer_count_16","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("record_attribute_flags","uint8",42,1,SX_FLAGS),
    SX_FIELD("reserved0","uint8",43,1,SX_RESERVED),
    SX_FIELD("global_buffer_count_32","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","uint16",48,2,SX_RESERVED),
    SX_FIELD("version_limit","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("characteristics","uint32",52,4,SX_FLAGS),
    SX_FIELD("record_protection","uint16",56,2,SX_FLAGS),
    SX_FIELD("mapping_words","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("access_mode","uint8",59,1,SX_ID),
    SX_FIELD("owner_member","uint16",60,2,SX_ID),
    SX_FIELD("owner_group","uint16",62,2,SX_ID),
    SX_FIELD("protection","uint16",64,2,SX_FLAGS),
    SX_FIELD("backlink_number_low","uint16",66,2,SX_NONE),
    SX_FIELD("backlink_sequence","uint16",68,2,SX_NONE),
    SX_FIELD("backlink_relative_volume","uint8",70,1,SX_NONE),
    SX_FIELD("backlink_number_high","uint8",71,1,SX_NONE),
    SX_FIELD("journal_flags","uint8",72,1,SX_FLAGS),
    SX_FIELD("recovery_unit_active","uint8",73,1,SX_FLAGS),
    SX_FIELD("link_count","uint16",74,2,SX_COUNT_PROP),
    SX_FIELD("highwater_block","uint32",76,4,SX_NONE),
};
const sx_layout sxcf_ods_file_header = {0x603d0058U,"ods_file_header",sxcf_ods_file_header_fields,SX_COUNT(sxcf_ods_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_file_checksum_fields[] = {
    SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxcf_ods_file_checksum = {0x603d0059U,"ods_file_checksum",sxcf_ods_file_checksum_fields,SX_COUNT(sxcf_ods_file_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer0_fields[] = {
    SX_FIELD("placement_word","uint16",0,2,SX_FLAGS),
};
const sx_layout sxcf_ods_retrieval_pointer0 = {0x603d005aU,"ods_retrieval_pointer0",sxcf_ods_retrieval_pointer0_fields,SX_COUNT(sxcf_ods_retrieval_pointer0_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer1_fields[] = {
    SX_FIELD("blocks_minus_one","uint8",0,1,SX_NONE),
    SX_FIELD("format_and_lbn_high","uint8",1,1,SX_FLAGS),
    SX_FIELD("lbn_low","uint16",2,2,SX_NONE),
};
const sx_layout sxcf_ods_retrieval_pointer1 = {0x603d005bU,"ods_retrieval_pointer1",sxcf_ods_retrieval_pointer1_fields,SX_COUNT(sxcf_ods_retrieval_pointer1_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer2_fields[] = {
    SX_FIELD("format_and_blocks_minus_one","uint16",0,2,SX_FLAGS),
    SX_FIELD("first_lbn","uint32",2,4,SX_NONE),
};
const sx_layout sxcf_ods_retrieval_pointer2 = {0x603d005cU,"ods_retrieval_pointer2",sxcf_ods_retrieval_pointer2_fields,SX_COUNT(sxcf_ods_retrieval_pointer2_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer3_fields[] = {
    SX_FIELD("format_and_count_high","uint16",0,2,SX_FLAGS),
    SX_FIELD("count_low","uint16",2,2,SX_NONE),
    SX_FIELD("first_lbn","uint32",4,4,SX_NONE),
};
const sx_layout sxcf_ods_retrieval_pointer3 = {0x603d005dU,"ods_retrieval_pointer3",sxcf_ods_retrieval_pointer3_fields,SX_COUNT(sxcf_ods_retrieval_pointer3_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_directory_header_fields[] = {
    SX_FIELD("following_record_size","uint16",0,2,SX_SIZE),
    SX_FIELD("version_limit","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("flags_and_name_encoding","uint8",4,1,SX_FLAGS),
    SX_FIELD("name_size","uint8",5,1,SX_SIZE),
};
const sx_layout sxcf_ods_directory_header = {0x603d005eU,"ods_directory_header",sxcf_ods_directory_header_fields,SX_COUNT(sxcf_ods_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ods_directory_version_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_NONE),
    SX_FIELD("file_number_low","uint16",2,2,SX_NONE),
    SX_FIELD("file_sequence","uint16",4,2,SX_NONE),
    SX_FIELD("relative_volume","uint8",6,1,SX_NONE),
    SX_FIELD("file_number_high","uint8",7,1,SX_NONE),
};
const sx_layout sxcf_ods_directory_version = {0x603d005fU,"ods_directory_version",sxcf_ods_directory_version_fields,SX_COUNT(sxcf_ods_directory_version_fields),SX_LE};
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
static uint16_t sxcf_ods_sum(const uint8_t*b,size_t n){uint16_t sum=0;for(size_t i=0;i<n;i+=2)sum=(uint16_t)(sum+sxcf16(b+i,0));return sum;}
static unsigned sxcf_ods_map(sx_context*c,const uint8_t*h,uint64_t at,sxcf_extent_map*m,unsigned cap,bool emit){
 unsigned q=h[1]*2,end=q+h[58]*2,count=0;uint64_t logical=0;if(q<80||end>510||q>end)return 0;
 while(q+2<=end){uint16_t w=sxcf16(h+q,0);unsigned format=w>>14,z=format==0?2:format==1?4:format==2?6:8;if(z>end-q)return 0;
  const sx_layout*l=format==0?&sxcf_ods_retrieval_pointer0:format==1?&sxcf_ods_retrieval_pointer1:format==2?&sxcf_ods_retrieval_pointer2:&sxcf_ods_retrieval_pointer3;
  if(emit&&!sxcf_put(c,l,at+q,1))return 0;
  if(format){uint64_t n=format==1?(w&255)+1U:format==2?(w&0x3fff)+1U:(((uint64_t)(w&0x3fff)<<16)|sxcf16(h+q+2,0))+1U;uint64_t block=format==1?((uint32_t)(w&0x3f00)<<8)|sxcf16(h+q+2,0):sxcf32(h+q+(format==2?2:4),0);if(n>UINT64_MAX/512||!sxcf_span(c,block*512,n*512)||count>=cap)return count;m[count++]=(sxcf_extent_map){logical,block*512,n*512};logical+=n*512;}
  q+=z;
 }return count;
}
static bool sxcf_ods_header_ok(const uint8_t*h){return sxcf_ods_sum(h,510)==sxcf16(h+510,0)&&(sxcf16(h+6,0)>>8==2||sxcf16(h+6,0)>>8==5)&&h[0]>=40&&h[0]<=h[1]&&h[1]<=h[2]&&h[2]<=h[3]&&h[3]<=255&&(unsigned)h[1]+h[58]<=h[2];}
static bool sxcf_ods_dir(sx_context*c,uint64_t p,uint64_t bytes){uint8_t h[6];for(uint64_t q=0;q+6<=bytes&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,p+q,h,6))return false;unsigned n=sxcf16(h,0),names=h[5];if(!n||n==65535){q=((q/512)+1)*512;continue;}unsigned values=6+((names+1)&~1U);if(n<14||(n&1)||n+2>bytes-q||n+2>512-q%512||values+8>n+2||(n+2-values)%8)break;if(!SXCF_ADD(c,ods_directory_header,p+q)||!SXCF_TABLE(c,ods_directory_version,p+q+values,(n+2-values)/8))return false;q+=n+2;}return true;}
static bool sxcf_ods(sx_context*c){
 uint8_t h[512],b[512];sxcf_extent_map index[215],map[215];if(!sxcf_read(c,512,h,512)||(!(!xx_rt_memcmp(h+496,"DECFILE11A  ",12)||!xx_rt_memcmp(h+496,"DECFILE11B  ",12)))||sxcf_ods_sum(h,58)!=sxcf16(h+58,0)||sxcf_ods_sum(h,510)!=sxcf16(h+510,0)||!SXCF_ADD(c,ods_home_block,512))return false;
 uint64_t first=(uint64_t)sxcf32(h+24,0)+sxcf16(h+32,0),vbn=(uint64_t)sxcf16(h+22,0)+sxcf16(h+32,0),max=sxcf32(h+28,0);if(!vbn||!max||!sxcf_read(c,first*512,b,512)||!sxcf_ods_header_ok(b))return true;
 unsigned ni=sxcf_ods_map(c,b,first*512,index,215,false);if(!ni)return true;if(max>SXCF_INODES)max=SXCF_INODES;
 for(uint64_t id=1;id<=max&&c->count<SXCF_LIMIT;id++){uint64_t logical=(vbn+id-2)*512,p=UINT64_MAX;for(unsigned k=0;k<ni;k++)if(logical>=index[k].logical&&logical-index[k].logical<=index[k].bytes&&512<=index[k].bytes-(logical-index[k].logical)){p=index[k].physical+logical-index[k].logical;break;}if(p==UINT64_MAX)continue;if(!sxcf_read(c,p,b,512))return false;if(!sxcf_ods_header_ok(b)||((uint32_t)sxcf16(b+8,0)|(uint32_t)b[13]<<16)!=id)continue;
  if(!SXCF_ADD(c,ods_file_header,p)||!SXCF_ADD(c,ods_file_checksum,p+510))return false;unsigned nm=sxcf_ods_map(c,b,p,map,215,true);
  if(sxcf32(b+52,0)&0x2000){uint64_t end=(uint32_t)sxcf16(b+28,0)<<16|sxcf16(b+30,0),size=end?(end-1)*512+sxcf16(b+32,0):0;for(unsigned k=0;k<nm;k++){if(map[k].logical>=size)break;uint64_t n=map[k].bytes;if(n>size-map[k].logical)n=size-map[k].logical;if(!sxcf_ods_dir(c,map[k].physical,n))return false;}}
 }return true;
}
bool sx_ods2_fs_build(sx_context*c)
{
 return sxcf_ods(c);
}
