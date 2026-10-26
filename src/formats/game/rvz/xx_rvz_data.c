/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Dolphin RVZ data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_rvz_file_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("compatible_version","uint32",8,4,SX_NONE),
 SX_FIELD("disc_header_size","uint32",12,4,SX_SIZE),
 SX_FIELD("disc_header_sha1","uint8[20]",16,20,SXARM_CHECKSUM),
 SX_FIELD("iso_file_size","uint64",36,8,SX_SIZE),
 SX_FIELD("rvz_file_size","uint64",44,8,SX_SIZE),
 SX_FIELD("file_header_sha1","uint8[20]",52,20,SXARM_CHECKSUM),
};
const sx_layout sxarm_rvz_file_header={UINT32_C(0x607c002a),"rvz_file_header",sxarm_rvz_file_header_fields,SX_COUNT(sxarm_rvz_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_raw_entry_fields[]={
 SX_FIELD("iso_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("iso_size","uint64",8,8,SX_SIZE),
 SX_FIELD("first_group_index","uint32",16,4,SX_NONE),
 SX_FIELD("group_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxarm_rvz_raw_entry={UINT32_C(0x607c002c),"rvz_raw_entry",sxarm_rvz_raw_entry_fields,SX_COUNT(sxarm_rvz_raw_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_group_entry_fields[]={
 SX_FIELD("data_offset_div4","uint32",0,4,SX_NONE),
 SX_FIELD("data_size_and_compressed_flag","uint32",4,4,SX_NONE),
 SX_FIELD("rvz_packed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxarm_rvz_group_entry={UINT32_C(0x607c002d),"rvz_group_entry",sxarm_rvz_group_entry_fields,SX_COUNT(sxarm_rvz_group_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_packing_run_fields[]={
 SX_FIELD("length_and_seed_flag","uint32",0,4,SX_NONE),
};
const sx_layout sxarm_rvz_packing_run={UINT32_C(0x607c002e),"rvz_packing_run",sxarm_rvz_packing_run_fields,SX_COUNT(sxarm_rvz_packing_run_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_prng_seed_fields[]={
 SX_FIELD("seed_0","uint32",0,4,SX_NONE),
 SX_FIELD("seed_1","uint32",4,4,SX_NONE),
 SX_FIELD("seed_2","uint32",8,4,SX_NONE),
 SX_FIELD("seed_3","uint32",12,4,SX_NONE),
 SX_FIELD("seed_4","uint32",16,4,SX_NONE),
 SX_FIELD("seed_5","uint32",20,4,SX_NONE),
 SX_FIELD("seed_6","uint32",24,4,SX_NONE),
 SX_FIELD("seed_7","uint32",28,4,SX_NONE),
 SX_FIELD("seed_8","uint32",32,4,SX_NONE),
 SX_FIELD("seed_9","uint32",36,4,SX_NONE),
 SX_FIELD("seed_10","uint32",40,4,SX_NONE),
 SX_FIELD("seed_11","uint32",44,4,SX_NONE),
 SX_FIELD("seed_12","uint32",48,4,SX_NONE),
 SX_FIELD("seed_13","uint32",52,4,SX_NONE),
 SX_FIELD("seed_14","uint32",56,4,SX_NONE),
 SX_FIELD("seed_15","uint32",60,4,SX_NONE),
 SX_FIELD("seed_16","uint32",64,4,SX_NONE),
};
const sx_layout sxarm_rvz_prng_seed={UINT32_C(0x607c002f),"rvz_prng_seed",sxarm_rvz_prng_seed_fields,SX_COUNT(sxarm_rvz_prng_seed_fields),SX_BE};
static bool sxarm_rvz_packed(sx_context*c,uint64_t p,uint64_t n){uint64_t end=p+n;while(p<end){uint64_t word;if(end-p<4||!sxarm_word(c,p,4,true,&word)||!sxarm_add(c,&sxarm_rvz_packing_run,p))return false;p+=4;uint64_t z=(word&0x80000000U)?68:(word&0x7fffffffU);if(z>end-p)return false;if((word&0x80000000U)&&!sxarm_add(c,&sxarm_rvz_prng_seed,p))return false;p+=z;}return true;}
static bool sxarm_rvz(sx_context*c){uint8_t magic[4];if(!sxarm_read(c,0,magic,4)||xx_rt_memcmp(magic,"RVZ\1",4))return false;uint64_t compression,raw,n,rawz,group,gn,gz,p,z,packed;if(!sxarm_add(c,&sxarm_rvz_file_header,0)||!sxarm_add(c,&sxarm_rvz_disc_header,72)||!sxarm_word(c,76,4,true,&compression))return false;if(compression)return true;/* Compressed table coordinates cannot be mapped to plaintext fields. */
 if(!sxarm_word(c,72+0xb4,4,true,&n)||!sxarm_word(c,72+0xb8,8,true,&raw)||!sxarm_word(c,72+0xc0,4,true,&rawz)||n>rawz/24||!sxarm_span(c,raw,rawz)||!sxarm_table(c,&sxarm_rvz_raw_entry,raw,24,n)||!sxarm_word(c,72+0xc4,4,true,&gn)||!sxarm_word(c,72+0xc8,8,true,&group)||!sxarm_word(c,72+0xd0,4,true,&gz)||gn>gz/12||!sxarm_span(c,group,gz)||!sxarm_table(c,&sxarm_rvz_group_entry,group,12,gn))return false;
 for(uint64_t i=0;i<gn;i++){if(!sxarm_word(c,group+12*i,4,true,&p)||!sxarm_word(c,group+12*i+4,4,true,&z)||!sxarm_word(c,group+12*i+8,4,true,&packed))return false;p*=4;if(z&0x80000000U)continue;if(z&&packed&&sxarm_span(c,p,z)){/* Shared or overlapping payloads are legal; existing physical records are retained once. */size_t old=c->count;if(!sxarm_rvz_packed(c,p,z)){(void)old;return true;}}}return true;}
bool sx_rvz_build(sx_context*c)
{
 return sxarm_rvz(c);
}
