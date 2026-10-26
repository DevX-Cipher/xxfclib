/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ADF data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_adf_boot_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("dos_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("boot_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
};
const sx_layout sxrfs_adf_boot_header = {0x60650039U,"adf_boot_header",sxrfs_adf_boot_header_fields,SX_COUNT(sxrfs_adf_boot_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_adf_root_block_fields[] = {
    SX_FIELD("block_type","int32",0,4,SX_ID),
    SX_FIELD("header_key","uint32",4,4,SX_NONE),
    SX_FIELD("high_sequence","uint32",8,4,SX_NONE),
    SX_FIELD("hash_table_size","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("first_data","uint32",16,4,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
    SX_FIELD("hash_block_numbers","uint32[72]",24,288,SX_NONE),
    SX_FIELD("bitmap_valid","int32",312,4,SX_FLAGS),
    SX_FIELD("bitmap_blocks","uint32[25]",316,100,SX_NONE),
    SX_FIELD("bitmap_extension_block","uint32",416,4,SX_NONE),
    SX_FIELD("modification_days","uint32",420,4,SX_NONE),
    SX_FIELD("modification_minutes","uint32",424,4,SX_NONE),
    SX_FIELD("modification_ticks","uint32",428,4,SX_NONE),
    SX_FIELD("volume_name_length","uint8",432,1,SX_SIZE),
    SX_FIELD("volume_name","byte[31]",433,31,SX_NONE),
    SX_FIELD("reserved464","byte[8]",464,8,SX_RESERVED),
    SX_FIELD("volume_modification_days","uint32",472,4,SX_NONE),
    SX_FIELD("volume_modification_minutes","uint32",476,4,SX_NONE),
    SX_FIELD("volume_modification_ticks","uint32",480,4,SX_NONE),
    SX_FIELD("creation_days","uint32",484,4,SX_NONE),
    SX_FIELD("creation_minutes","uint32",488,4,SX_NONE),
    SX_FIELD("creation_ticks","uint32",492,4,SX_NONE),
    SX_FIELD("reserved496","uint32",496,4,SX_RESERVED),
    SX_FIELD("reserved500","uint32",500,4,SX_RESERVED),
    SX_FIELD("directory_cache_block","uint32",504,4,SX_NONE),
    SX_FIELD("secondary_type","int32",508,4,SX_ID),
};
const sx_layout sxrfs_adf_root_block = {0x6065003aU,"adf_root_block",sxrfs_adf_root_block_fields,SX_COUNT(sxrfs_adf_root_block_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_adf_block_prefix_fields[] = {
    SX_FIELD("block_type","int32",0,4,SX_ID),
    SX_FIELD("header_key","uint32",4,4,SX_NONE),
    SX_FIELD("high_sequence","uint32",8,4,SX_NONE),
    SX_FIELD("data_size_or_table_size","uint32",12,4,SX_NONE),
    SX_FIELD("first_or_next_data_block","uint32",16,4,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxrfs_adf_block_prefix = {0x6065003bU,"adf_block_prefix",sxrfs_adf_block_prefix_fields,SX_COUNT(sxrfs_adf_block_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_adf_block_pointer_fields[] = {
    SX_FIELD("block_number","uint32",0,4,SX_NONE),
};
const sx_layout sxrfs_adf_block_pointer = {0x6065003cU,"adf_block_pointer",sxrfs_adf_block_pointer_fields,SX_COUNT(sxrfs_adf_block_pointer_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_adf_classic_entry_tail_fields[] = {
    SX_FIELD("reserved312","uint32",0,4,SX_RESERVED),
    SX_FIELD("owner_uid","uint16",4,2,SX_ID),
    SX_FIELD("owner_gid","uint16",6,2,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("byte_size","uint32",12,4,SX_SIZE),
    SX_FIELD("comment_length","uint8",16,1,SX_SIZE),
    SX_FIELD("comment","byte[79]",17,79,SX_NONE),
    SX_FIELD("reserved408","byte[12]",96,12,SX_RESERVED),
    SX_FIELD("modification_days","uint32",108,4,SX_NONE),
    SX_FIELD("modification_minutes","uint32",112,4,SX_NONE),
    SX_FIELD("modification_ticks","uint32",116,4,SX_NONE),
    SX_FIELD("name_length","uint8",120,1,SX_SIZE),
    SX_FIELD("name","byte[31]",121,31,SX_NONE),
    SX_FIELD("reserved464","byte[4]",152,4,SX_RESERVED),
    SX_FIELD("real_entry_block","uint32",156,4,SX_NONE),
    SX_FIELD("next_link_block","uint32",160,4,SX_NONE),
    SX_FIELD("reserved476","byte[20]",164,20,SX_RESERVED),
    SX_FIELD("hash_chain","uint32",184,4,SX_NONE),
    SX_FIELD("parent_block","uint32",188,4,SX_NONE),
    SX_FIELD("extension_block","uint32",192,4,SX_NONE),
    SX_FIELD("secondary_type","int32",196,4,SX_ID),
};
const sx_layout sxrfs_adf_classic_entry_tail = {0x6065003dU,"adf_classic_entry_tail",sxrfs_adf_classic_entry_tail_fields,SX_COUNT(sxrfs_adf_classic_entry_tail_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_adf_bitmap_block_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("free_block_bits","uint32[127]",4,508,SX_FLAGS),
};
const sx_layout sxrfs_adf_bitmap_block = {0x6065003eU,"adf_bitmap_block",sxrfs_adf_bitmap_block_fields,SX_COUNT(sxrfs_adf_bitmap_block_fields),SX_BE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
static bool sxrfs_adf_sum(const uint8_t*b){uint32_t sum=0;for(unsigned i=0;i<512;i+=4)sum+=sxrfs32(b+i,1);return sum==0;}
static bool sxrfs_adf(sx_context*c){uint8_t b[512],boot[4];if(!sxrfs_read(c,0,boot,4))return false;unsigned blocks=(unsigned)((uint64_t)c->size/512);if(blocks<4||blocks>0x2000000)return false;bool marked=!xx_rt_memcmp(boot,"DOS",3)&&boot[3]<=7;if(!marked&&(boot[0]||boot[1]||boot[2]||boot[3]||(blocks!=1760&&blocks!=3520)))return false;unsigned roots[3]={(blocks+1)/2,880,1760},root=0;for(unsigned i=0;i<3;i++){if(roots[i]>=blocks||!sxrfs_read(c,(uint64_t)roots[i]*512,b,512))continue;if(sxrfs32(b,1)==2&&!sxrfs32(b+4,1)&&sxrfs32(b+12,1)==72&&sxrfs32(b+508,1)==1&&sxrfs_adf_sum(b)){root=roots[i];break;}}if(!root)return false;if(marked&&!SXRFS_ADD(c,adf_boot_header,0))return false;if(!SXRFS_ADD(c,adf_root_block,(uint64_t)root*512))return false;
 for(unsigned i=0;i<25;i++){unsigned bm=sxrfs32(b+316+i*4,1);uint8_t bitmap[512];if(bm>=2&&bm<blocks&&sxrfs_read(c,(uint64_t)bm*512,bitmap,512)&&sxrfs_adf_sum(bitmap)&&!SXRFS_ADD(c,adf_bitmap_block,(uint64_t)bm*512))return false;}
 uint32_t*q=xx_rt_calloc(24000,sizeof(*q));uint8_t*seen=xx_rt_calloc((blocks+7)/8,1);if(!q||!seen){xx_rt_free(q);xx_rt_free(seen);return false;}size_t n=0,i=0;for(unsigned j=0;j<72;j++){unsigned v=sxrfs32(b+24+j*4,1);if(v>=2&&v<blocks&&n<24000&&!(seen[v/8]&(1U<<(v%8)))){seen[v/8]|=1U<<(v%8);q[n++]=v;}}bool ok=true;
 while(i<n&&c->count<SXRFS_LIMIT){unsigned block=q[i++];uint64_t p=(uint64_t)block*512;if(!sxrfs_read(c,p,b,512)||sxrfs32(b,1)!=2||!sxrfs_adf_sum(b))continue;int32_t type=(int32_t)sxrfs32(b+508,1);if(!SXRFS_ADD(c,adf_block_prefix,p)){ok=false;break;}if(boot[3]<6&&!SXRFS_ADD(c,adf_classic_entry_tail,p+312)){ok=false;break;}if(type==2||type==-3){if(!SXRFS_TABLE(c,adf_block_pointer,p+24,72)){ok=false;break;}}
  for(unsigned j=0;j<(type==2?73:1);j++){unsigned v=sxrfs32(b+(j==0?496:24+(j-1)*4),1);if(v>=2&&v<blocks&&n<24000&&!(seen[v/8]&(1U<<(v%8)))){seen[v/8]|=1U<<(v%8);q[n++]=v;}}
 }xx_rt_free(q);xx_rt_free(seen);return ok;}
bool sx_adf_build(sx_context*c)
{
 return sxrfs_adf(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
#undef SXRFS_TABLE
