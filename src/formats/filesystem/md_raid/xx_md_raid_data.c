/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Md Raid data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_md1_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("feature_map","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("set_uuid","byte[16]",16,16,SX_ID),
    SX_FIELD("set_name","char[32]",32,32,SX_STRING),
    SX_FIELD("creation_time_encoded","uint64",64,8,SX_NONE),
    SX_FIELD("level","int32",72,4,SX_ID),
    SX_FIELD("layout","uint32",76,4,SX_ID),
    SX_FIELD("component_sectors","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("chunk_sectors","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","int32",96,4,SX_NONE),
    SX_FIELD("new_level","int32",100,4,SX_ID),
    SX_FIELD("reshape_position","uint64",104,8,SX_NONE),
    SX_FIELD("delta_disks","int32",112,4,SX_NONE),
    SX_FIELD("new_layout","uint32",116,4,SX_ID),
    SX_FIELD("new_chunk_sectors","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("new_data_offset","int32",124,4,SX_NONE),
    SX_FIELD("data_offset","uint64",128,8,SX_NONE),
    SX_FIELD("data_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("super_offset","uint64",144,8,SX_NONE),
    SX_FIELD("recovery_or_journal_offset","uint64",152,8,SX_NONE),
    SX_FIELD("device_number","uint32",160,4,SX_ID),
    SX_FIELD("corrected_reads","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("device_uuid","byte[16]",168,16,SX_ID),
    SX_FIELD("device_flags","uint8",184,1,SX_FLAGS),
    SX_FIELD("bad_block_shift","uint8",185,1,SX_NONE),
    SX_FIELD("bad_block_log_sectors","uint16",186,2,SX_COUNT_PROP),
    SX_FIELD("bad_block_log_offset","int32",188,4,SX_NONE),
    SX_FIELD("update_time_encoded","uint64",192,8,SX_NONE),
    SX_FIELD("events","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("resync_offset","uint64",208,8,SX_NONE),
    SX_FIELD("checksum","uint32",216,4,SX_CHECKSUM),
    SX_FIELD("max_devices","uint32",220,4,SX_COUNT_PROP),
    SX_FIELD("padding","byte[32]",224,32,SX_RESERVED),
};
const sx_layout sxvi_md1_superblock = {0x6053003dU,"md1_superblock",sxvi_md1_superblock_fields,SX_COUNT(sxvi_md1_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_md1_superblock_ppl_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("feature_map","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("set_uuid","byte[16]",16,16,SX_ID),
    SX_FIELD("set_name","char[32]",32,32,SX_STRING),
    SX_FIELD("creation_time_encoded","uint64",64,8,SX_NONE),
    SX_FIELD("level","int32",72,4,SX_ID),
    SX_FIELD("layout","uint32",76,4,SX_ID),
    SX_FIELD("component_sectors","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("chunk_sectors","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("ppl_offset","int16",96,2,SX_NONE),
    SX_FIELD("ppl_sectors","uint16",98,2,SX_COUNT_PROP),
    SX_FIELD("new_level","int32",100,4,SX_ID),
    SX_FIELD("reshape_position","uint64",104,8,SX_NONE),
    SX_FIELD("delta_disks","int32",112,4,SX_NONE),
    SX_FIELD("new_layout","uint32",116,4,SX_ID),
    SX_FIELD("new_chunk_sectors","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("new_data_offset","int32",124,4,SX_NONE),
    SX_FIELD("data_offset","uint64",128,8,SX_NONE),
    SX_FIELD("data_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("super_offset","uint64",144,8,SX_NONE),
    SX_FIELD("recovery_or_journal_offset","uint64",152,8,SX_NONE),
    SX_FIELD("device_number","uint32",160,4,SX_ID),
    SX_FIELD("corrected_reads","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("device_uuid","byte[16]",168,16,SX_ID),
    SX_FIELD("device_flags","uint8",184,1,SX_FLAGS),
    SX_FIELD("bad_block_shift","uint8",185,1,SX_NONE),
    SX_FIELD("bad_block_log_sectors","uint16",186,2,SX_COUNT_PROP),
    SX_FIELD("bad_block_log_offset","int32",188,4,SX_NONE),
    SX_FIELD("update_time_encoded","uint64",192,8,SX_NONE),
    SX_FIELD("events","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("resync_offset","uint64",208,8,SX_NONE),
    SX_FIELD("checksum","uint32",216,4,SX_CHECKSUM),
    SX_FIELD("max_devices","uint32",220,4,SX_COUNT_PROP),
    SX_FIELD("padding","byte[32]",224,32,SX_RESERVED),
};
const sx_layout sxvi_md1_superblock_ppl = {0x6053003eU,"md1_superblock_ppl",sxvi_md1_superblock_ppl_fields,SX_COUNT(sxvi_md1_superblock_ppl_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_md1_device_role_fields[] = {
    SX_FIELD("role","uint16",0,2,SX_ID),
};
const sx_layout sxvi_md1_device_role = {0x6053003fU,"md1_device_role",sxvi_md1_device_role_fields,SX_COUNT(sxvi_md1_device_role_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_md090_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("minor_version","uint32",8,4,SX_ID),
    SX_FIELD("patch_version","uint32",12,4,SX_ID),
    SX_FIELD("valid_words","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uuid0","uint32",20,4,SX_ID),
    SX_FIELD("creation_time","uint32",24,4,SX_TIME),
    SX_FIELD("level","int32",28,4,SX_ID),
    SX_FIELD("component_kib","uint32",32,4,SX_NONE),
    SX_FIELD("total_disks","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("preferred_minor","uint32",44,4,SX_ID),
    SX_FIELD("not_persistent","uint32",48,4,SX_FLAGS),
    SX_FIELD("uuid1","uint32",52,4,SX_ID),
    SX_FIELD("uuid2","uint32",56,4,SX_ID),
    SX_FIELD("uuid3","uint32",60,4,SX_ID),
    SX_FIELD("constant_reserved","byte[64]",64,64,SX_RESERVED),
    SX_FIELD("update_time","uint32",128,4,SX_TIME),
    SX_FIELD("state","uint32",132,4,SX_FLAGS),
    SX_FIELD("active_disks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("working_disks","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("failed_disks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("spare_disks","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("checksum","uint32",152,4,SX_CHECKSUM),
    SX_FIELD("events","uint64",156,8,SX_COUNT_PROP),
    SX_FIELD("checkpoint_events","uint64",164,8,SX_COUNT_PROP),
    SX_FIELD("recovery_checkpoint","uint32",172,4,SX_NONE),
    SX_FIELD("state_reserved","byte[80]",176,80,SX_RESERVED),
    SX_FIELD("layout","uint32",256,4,SX_ID),
    SX_FIELD("chunk_size","uint32",260,4,SX_SIZE),
    SX_FIELD("root_pv","uint32",264,4,SX_ID),
    SX_FIELD("root_block","uint32",268,4,SX_NONE),
    SX_FIELD("personality_reserved","byte[240]",272,240,SX_RESERVED),
};
const sx_layout sxvi_md090_header_le = {0x60530040U,"md090_header_le",sxvi_md090_header_le_fields,SX_COUNT(sxvi_md090_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_md090_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("minor_version","uint32",8,4,SX_ID),
    SX_FIELD("patch_version","uint32",12,4,SX_ID),
    SX_FIELD("valid_words","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uuid0","uint32",20,4,SX_ID),
    SX_FIELD("creation_time","uint32",24,4,SX_TIME),
    SX_FIELD("level","int32",28,4,SX_ID),
    SX_FIELD("component_kib","uint32",32,4,SX_NONE),
    SX_FIELD("total_disks","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("preferred_minor","uint32",44,4,SX_ID),
    SX_FIELD("not_persistent","uint32",48,4,SX_FLAGS),
    SX_FIELD("uuid1","uint32",52,4,SX_ID),
    SX_FIELD("uuid2","uint32",56,4,SX_ID),
    SX_FIELD("uuid3","uint32",60,4,SX_ID),
    SX_FIELD("constant_reserved","byte[64]",64,64,SX_RESERVED),
    SX_FIELD("update_time","uint32",128,4,SX_TIME),
    SX_FIELD("state","uint32",132,4,SX_FLAGS),
    SX_FIELD("active_disks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("working_disks","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("failed_disks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("spare_disks","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("checksum","uint32",152,4,SX_CHECKSUM),
    SX_FIELD("events","uint64",156,8,SX_COUNT_PROP),
    SX_FIELD("checkpoint_events","uint64",164,8,SX_COUNT_PROP),
    SX_FIELD("recovery_checkpoint","uint32",172,4,SX_NONE),
    SX_FIELD("state_reserved","byte[80]",176,80,SX_RESERVED),
    SX_FIELD("layout","uint32",256,4,SX_ID),
    SX_FIELD("chunk_size","uint32",260,4,SX_SIZE),
    SX_FIELD("root_pv","uint32",264,4,SX_ID),
    SX_FIELD("root_block","uint32",268,4,SX_NONE),
    SX_FIELD("personality_reserved","byte[240]",272,240,SX_RESERVED),
};
const sx_layout sxvi_md090_header_be = {0x60530041U,"md090_header_be",sxvi_md090_header_be_fields,SX_COUNT(sxvi_md090_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_md090_disk_le_fields[] = {
    SX_FIELD("number","uint32",0,4,SX_ID),
    SX_FIELD("major","uint32",4,4,SX_ID),
    SX_FIELD("minor","uint32",8,4,SX_ID),
    SX_FIELD("raid_role","uint32",12,4,SX_ID),
    SX_FIELD("state","uint32",16,4,SX_FLAGS),
    SX_FIELD("reserved","byte[108]",20,108,SX_RESERVED),
};
const sx_layout sxvi_md090_disk_le = {0x60530042U,"md090_disk_le",sxvi_md090_disk_le_fields,SX_COUNT(sxvi_md090_disk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_md090_disk_be_fields[] = {
    SX_FIELD("number","uint32",0,4,SX_ID),
    SX_FIELD("major","uint32",4,4,SX_ID),
    SX_FIELD("minor","uint32",8,4,SX_ID),
    SX_FIELD("raid_role","uint32",12,4,SX_ID),
    SX_FIELD("state","uint32",16,4,SX_FLAGS),
    SX_FIELD("reserved","byte[108]",20,108,SX_RESERVED),
};
const sx_layout sxvi_md090_disk_be = {0x60530043U,"md090_disk_be",sxvi_md090_disk_be_fields,SX_COUNT(sxvi_md090_disk_be_fields),SX_BE};
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
#define SXVI_ORDER(l,o) ((o)==1?&sxvi_##l##_be:&sxvi_##l##_le)
static bool sxvi_md(sx_context*c){uint8_t b[256];uint64_t sectors=(uint64_t)c->size/512,at[3]={0,4096,UINT64_MAX};if(sectors>=16)at[2]=((sectors-16)&~UINT64_C(7))*512;
 for(unsigned i=0;i<3;i++){if(at[i]==UINT64_MAX||!sxvi_read(c,at[i],b,256)||sxvi32(b,0)!=0xa92b4efcU||sxvi32(b+4,0)!=1)continue;uint64_t n=sxvi32(b+220,0);if(!n||n>3840||sxvi64(b+144,0)!=at[i]/512||!sxvi_span(c,at[i]+256,n*2))continue;return sxvi_put(c,(sxvi32(b+8,0)&1024)?&sxvi_md1_superblock_ppl:&sxvi_md1_superblock,at[i],1)&&SXVI_TABLE(c,md1_device_role,at[i]+256,n);}
 if(c->size<131072)return false;uint64_t p=((uint64_t)c->size&~UINT64_C(65535))-65536;if(!sxvi_read(c,p,b,16)||!sxvi_span(c,p,4096))return false;unsigned o=sxvi32(b,0)==0xa92b4efcU?0:sxvi32(b,1)==0xa92b4efcU?1:2;if(o==2||sxvi32(b+4,o)||sxvi32(b+8,o)!=90)return false;
 return sxvi_put(c,SXVI_ORDER(md090_header,o),p,1)&&sxvi_put(c,SXVI_ORDER(md090_disk,o),p+512,27)&&sxvi_put(c,SXVI_ORDER(md090_disk,o),p+3968,1);
}
bool sx_md_raid_build(sx_context*c)
{
 return sxvi_md(c);
}
#undef SXVI_TABLE
#undef SXVI_ORDER
