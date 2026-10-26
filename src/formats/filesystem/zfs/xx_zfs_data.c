/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_zfs_embedded_checksum_le_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint64[4]",8,32,SX_CHECKSUM),
};
const sx_layout sxmf_zfs_embedded_checksum_le = {0x6042003dU,"zfs_embedded_checksum_le",sxmf_zfs_embedded_checksum_le_fields,SX_COUNT(sxmf_zfs_embedded_checksum_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_zfs_embedded_checksum_be_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint64[4]",8,32,SX_CHECKSUM),
};
const sx_layout sxmf_zfs_embedded_checksum_be = {0x6042003eU,"zfs_embedded_checksum_be",sxmf_zfs_embedded_checksum_be_fields,SX_COUNT(sxmf_zfs_embedded_checksum_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_zfs_block_pointer_le_fields[] = {
    SX_FIELD("dva0_word0","uint64",0,8,SX_FLAGS),
    SX_FIELD("dva0_word1","uint64",8,8,SX_FLAGS),
    SX_FIELD("dva1_word0","uint64",16,8,SX_FLAGS),
    SX_FIELD("dva1_word1","uint64",24,8,SX_FLAGS),
    SX_FIELD("dva2_word0","uint64",32,8,SX_FLAGS),
    SX_FIELD("dva2_word1","uint64",40,8,SX_FLAGS),
    SX_FIELD("properties","uint64",48,8,SX_FLAGS),
    SX_FIELD("properties2","uint64",56,8,SX_FLAGS),
    SX_FIELD("padding","uint64",64,8,SX_RESERVED),
    SX_FIELD("physical_birth_word","uint64",72,8,SX_NONE),
    SX_FIELD("logical_birth_word","uint64",80,8,SX_NONE),
    SX_FIELD("fill_count","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("checksum","uint64[4]",96,32,SX_CHECKSUM),
};
const sx_layout sxmf_zfs_block_pointer_le = {0x6042003fU,"zfs_block_pointer_le",sxmf_zfs_block_pointer_le_fields,SX_COUNT(sxmf_zfs_block_pointer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_zfs_block_pointer_be_fields[] = {
    SX_FIELD("dva0_word0","uint64",0,8,SX_FLAGS),
    SX_FIELD("dva0_word1","uint64",8,8,SX_FLAGS),
    SX_FIELD("dva1_word0","uint64",16,8,SX_FLAGS),
    SX_FIELD("dva1_word1","uint64",24,8,SX_FLAGS),
    SX_FIELD("dva2_word0","uint64",32,8,SX_FLAGS),
    SX_FIELD("dva2_word1","uint64",40,8,SX_FLAGS),
    SX_FIELD("properties","uint64",48,8,SX_FLAGS),
    SX_FIELD("properties2","uint64",56,8,SX_FLAGS),
    SX_FIELD("padding","uint64",64,8,SX_RESERVED),
    SX_FIELD("physical_birth_word","uint64",72,8,SX_NONE),
    SX_FIELD("logical_birth_word","uint64",80,8,SX_NONE),
    SX_FIELD("fill_count","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("checksum","uint64[4]",96,32,SX_CHECKSUM),
};
const sx_layout sxmf_zfs_block_pointer_be = {0x60420040U,"zfs_block_pointer_be",sxmf_zfs_block_pointer_be_fields,SX_COUNT(sxmf_zfs_block_pointer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_zfs_uberblock_prefix_le_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_ID),
    SX_FIELD("transaction_group","uint64",16,8,SX_NONE),
    SX_FIELD("guid_sum","uint64",24,8,SX_ID),
    SX_FIELD("timestamp","uint64",32,8,SX_TIME),
};
const sx_layout sxmf_zfs_uberblock_prefix_le = {0x60420041U,"zfs_uberblock_prefix_le",sxmf_zfs_uberblock_prefix_le_fields,SX_COUNT(sxmf_zfs_uberblock_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_zfs_uberblock_prefix_be_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_ID),
    SX_FIELD("transaction_group","uint64",16,8,SX_NONE),
    SX_FIELD("guid_sum","uint64",24,8,SX_ID),
    SX_FIELD("timestamp","uint64",32,8,SX_TIME),
};
const sx_layout sxmf_zfs_uberblock_prefix_be = {0x60420042U,"zfs_uberblock_prefix_be",sxmf_zfs_uberblock_prefix_be_fields,SX_COUNT(sxmf_zfs_uberblock_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_zfs_uberblock_tail_le_fields[] = {
    SX_FIELD("software_version","uint64",0,8,SX_ID),
    SX_FIELD("mmp_magic","uint64",8,8,SX_SIGNATURE),
    SX_FIELD("mmp_delay","uint64",16,8,SX_NONE),
    SX_FIELD("mmp_config","uint64",24,8,SX_FLAGS),
    SX_FIELD("checkpoint_transaction_group","uint64",32,8,SX_NONE),
    SX_FIELD("raidz_reflow_info","uint64",40,8,SX_FLAGS),
};
const sx_layout sxmf_zfs_uberblock_tail_le = {0x60420043U,"zfs_uberblock_tail_le",sxmf_zfs_uberblock_tail_le_fields,SX_COUNT(sxmf_zfs_uberblock_tail_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_zfs_uberblock_tail_be_fields[] = {
    SX_FIELD("software_version","uint64",0,8,SX_ID),
    SX_FIELD("mmp_magic","uint64",8,8,SX_SIGNATURE),
    SX_FIELD("mmp_delay","uint64",16,8,SX_NONE),
    SX_FIELD("mmp_config","uint64",24,8,SX_FLAGS),
    SX_FIELD("checkpoint_transaction_group","uint64",32,8,SX_NONE),
    SX_FIELD("raidz_reflow_info","uint64",40,8,SX_FLAGS),
};
const sx_layout sxmf_zfs_uberblock_tail_be = {0x60420044U,"zfs_uberblock_tail_be",sxmf_zfs_uberblock_tail_be_fields,SX_COUNT(sxmf_zfs_uberblock_tail_be_fields),SX_BE};
#define SXMF_ORDER(l,o) ((o)==1?&sxmf_##l##_be:&sxmf_##l##_le)
static bool sxmf_zfs(sx_context*c){
 /* Embedded label checksum records are physically framed even when no local
  * dataset tree can be decoded. Uberblock slots vary with the device ashift. */
 uint8_t b[216];bool any=false;uint64_t labels[4]={0,262144,UINT64_MAX,UINT64_MAX};if(c->size>=524288){labels[2]=((uint64_t)c->size&~UINT64_C(262143))-524288;labels[3]=labels[2]+262144;}
 for(unsigned i=0;i<4;i++){uint64_t p=labels[i];if(p==UINT64_MAX||!sxmf_span(c,p,262144))continue;bool dup=false;for(unsigned k=0;k<i;k++)if(labels[k]==p)dup=true;if(dup)continue;
  uint64_t ck[3]={p+8192-40,p+16384-40,p+131072-40};for(unsigned k=0;k<3;k++)if(sxmf_read(c,ck[k],b,40)){unsigned o=sxmf64(b,0)==UINT64_C(0x0210da7ab10c7a11)?0:sxmf64(b,1)==UINT64_C(0x0210da7ab10c7a11)?1:2;if(o<2){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),ck[k],1))return false;any=true;}}
  for(uint64_t q=p+131072;q+1024<=p+262144;q+=1024){if(!sxmf_read(c,q,b,216))break;unsigned o=sxmf64(b,0)==0xbab10cU?0:sxmf64(b,1)==0xbab10cU?1:2;if(o==2)continue;
   if(!sxmf_put(c,SXMF_ORDER(zfs_uberblock_prefix,o),q,1)||!sxmf_put(c,SXMF_ORDER(zfs_block_pointer,o),q+40,1)||!sxmf_put(c,SXMF_ORDER(zfs_uberblock_tail,o),q+168,1))return false;any=true;
   /* Locate the checksum at a supported power-of-two slot boundary. */
   for(uint64_t z=1024;z<=131072&&z<=p+262144-q;z*=2)if(sxmf_read(c,q+z-40,b,40)&&sxmf64(b,o)==UINT64_C(0x0210da7ab10c7a11)){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),q+z-40,1))return false;break;}
  }
 }
 /* The native recognizer also accepts a checksum in its initial 512-byte
  * probe. Include only the real 40-byte checksum record at that boundary. */
 const uint64_t probe[]={8192,15872,130560,392704};for(unsigned i=0;i<4;i++)if(sxmf_read(c,probe[i]+472,b,40)){unsigned o=sxmf64(b,0)==UINT64_C(0x0210da7ab10c7a11)?0:sxmf64(b,1)==UINT64_C(0x0210da7ab10c7a11)?1:2;if(o<2){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),probe[i]+472,1))return false;any=true;}}
 return any;
}
bool sx_zfs_build(sx_context*c)
{
 return sxmf_zfs(c);
}
#undef SXMF_ORDER
