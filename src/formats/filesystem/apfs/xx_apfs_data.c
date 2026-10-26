/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APFS data structures, moved out of the cowfs schema family. */
#include "../../xx_format_schema_cowfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/apfs/xx_apfs.h"
#include "xxfclib/formats/filesystem/btrfs/xx_btrfs.h"

static const xx_data_struct_field_desc sxc_apfs_object_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
};
const sx_layout sxc_apfs_object_header = {UINT32_C(0x60180001),"apfs_object_header",sxc_apfs_object_header_fields,SX_COUNT(sxc_apfs_object_header_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_container_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("magic", "char[4]", 32, 4, SX_SIGNATURE),
    SX_FIELD("block_size", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("block_count", "uint64", 40, 8, SX_COUNT_PROP),
    SX_FIELD("features", "uint64", 48, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_features", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("incompatible_features", "uint64", 64, 8, SX_FLAGS),
    SX_FIELD("uuid", "uint8[16]", 72, 16, SX_NONE),
    SX_FIELD("next_object_id", "uint64", 88, 8, SX_ID),
    SX_FIELD("next_transaction_id", "uint64", 96, 8, SX_ID),
    SX_FIELD("checkpoint_descriptor_blocks_flags", "uint32", 104, 4, SX_FLAGS),
    SX_FIELD("checkpoint_data_blocks_flags", "uint32", 108, 4, SX_FLAGS),
    SX_FIELD("checkpoint_descriptor_base", "int64", 112, 8, SX_NONE),
    SX_FIELD("checkpoint_data_base", "int64", 120, 8, SX_NONE),
    SX_FIELD("checkpoint_descriptor_next", "uint32", 128, 4, SX_NONE),
    SX_FIELD("checkpoint_data_next", "uint32", 132, 4, SX_NONE),
    SX_FIELD("checkpoint_descriptor_index", "uint32", 136, 4, SX_NONE),
    SX_FIELD("checkpoint_descriptor_length_blocks", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("checkpoint_data_index", "uint32", 144, 4, SX_NONE),
    SX_FIELD("checkpoint_data_length_blocks", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("spaceman_oid", "uint64", 152, 8, SX_ID),
    SX_FIELD("omap_oid", "uint64", 160, 8, SX_ID),
    SX_FIELD("reaper_oid", "uint64", 168, 8, SX_ID),
    SX_FIELD("test_type", "uint32", 176, 4, SX_ID),
    SX_FIELD("maximum_file_systems", "uint32", 180, 4, SX_COUNT_PROP),
};
const sx_layout sxc_apfs_container_header = {UINT32_C(0x60180002),"apfs_container_header",sxc_apfs_container_header_fields,SX_COUNT(sxc_apfs_container_header_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_file_system_oid_fields[] = {
    SX_FIELD("file_system_oid", "uint64", 0, 8, SX_ID),
};
const sx_layout sxc_apfs_file_system_oid = {UINT32_C(0x60180003),"apfs_file_system_oid",sxc_apfs_file_system_oid_fields,SX_COUNT(sxc_apfs_file_system_oid_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_container_counter_fields[] = {
    SX_FIELD("counter", "uint64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxc_apfs_container_counter = {UINT32_C(0x60180004),"apfs_container_counter",sxc_apfs_container_counter_fields,SX_COUNT(sxc_apfs_container_counter_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_container_tail_fields[] = {
    SX_FIELD("blocked_out_start_block", "int64", 0, 8, SX_NONE),
    SX_FIELD("blocked_out_block_count", "uint64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("evict_mapping_tree_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("flags", "uint64", 24, 8, SX_FLAGS),
    SX_FIELD("efi_jumpstart_block", "int64", 32, 8, SX_NONE),
    SX_FIELD("fusion_uuid", "uint8[16]", 40, 16, SX_NONE),
    SX_FIELD("keylocker_start_block", "int64", 56, 8, SX_NONE),
    SX_FIELD("keylocker_block_count", "uint64", 64, 8, SX_COUNT_PROP),
    SX_FIELD("ephemeral_info0", "uint64", 72, 8, SX_NONE),
    SX_FIELD("ephemeral_info1", "uint64", 80, 8, SX_NONE),
    SX_FIELD("ephemeral_info2", "uint64", 88, 8, SX_NONE),
    SX_FIELD("ephemeral_info3", "uint64", 96, 8, SX_NONE),
    SX_FIELD("test_oid", "uint64", 104, 8, SX_ID),
    SX_FIELD("fusion_middle_tree_oid", "uint64", 112, 8, SX_ID),
    SX_FIELD("fusion_writeback_cache_oid", "uint64", 120, 8, SX_ID),
    SX_FIELD("fusion_writeback_start_block", "int64", 128, 8, SX_NONE),
    SX_FIELD("fusion_writeback_block_count", "uint64", 136, 8, SX_COUNT_PROP),
    SX_FIELD("newest_mounted_version", "uint64", 144, 8, SX_ID),
    SX_FIELD("media_keybag_start_block", "int64", 152, 8, SX_NONE),
    SX_FIELD("media_keybag_block_count", "uint64", 160, 8, SX_COUNT_PROP),
};
const sx_layout sxc_apfs_container_tail = {UINT32_C(0x60180005),"apfs_container_tail",sxc_apfs_container_tail_fields,SX_COUNT(sxc_apfs_container_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_checkpoint_map_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint32", 32, 4, SX_FLAGS),
    SX_FIELD("mapping_count", "uint32", 36, 4, SX_COUNT_PROP),
};
const sx_layout sxc_apfs_checkpoint_map = {UINT32_C(0x60180006),"apfs_checkpoint_map",sxc_apfs_checkpoint_map_fields,SX_COUNT(sxc_apfs_checkpoint_map_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_checkpoint_mapping_fields[] = {
    SX_FIELD("object_type", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 4, 4, SX_ID),
    SX_FIELD("object_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("padding", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("file_system_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_id", "uint64", 24, 8, SX_ID),
    SX_FIELD("physical_block", "uint64", 32, 8, SX_NONE),
};
const sx_layout sxc_apfs_checkpoint_mapping = {UINT32_C(0x60180007),"apfs_checkpoint_mapping",sxc_apfs_checkpoint_mapping_fields,SX_COUNT(sxc_apfs_checkpoint_mapping_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_object_map_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint32", 32, 4, SX_FLAGS),
    SX_FIELD("snapshot_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("tree_type", "uint32", 40, 4, SX_FLAGS),
    SX_FIELD("snapshot_tree_type", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("tree_oid", "uint64", 48, 8, SX_ID),
    SX_FIELD("snapshot_tree_oid", "uint64", 56, 8, SX_ID),
    SX_FIELD("most_recent_snapshot_xid", "uint64", 64, 8, SX_ID),
    SX_FIELD("pending_revert_min_xid", "uint64", 72, 8, SX_ID),
    SX_FIELD("pending_revert_max_xid", "uint64", 80, 8, SX_ID),
};
const sx_layout sxc_apfs_object_map = {UINT32_C(0x60180008),"apfs_object_map",sxc_apfs_object_map_fields,SX_COUNT(sxc_apfs_object_map_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_btree_info_fields[] = {
    SX_FIELD("flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("node_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("key_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("value_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("longest_key", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("longest_value", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("key_count", "uint64", 24, 8, SX_COUNT_PROP),
    SX_FIELD("node_count", "uint64", 32, 8, SX_COUNT_PROP),
};
const sx_layout sxc_apfs_btree_info = {UINT32_C(0x6018000A),"apfs_btree_info",sxc_apfs_btree_info_fields,SX_COUNT(sxc_apfs_btree_info_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_btree_kvoff_fields[] = {
    SX_FIELD("key_offset", "uint16", 0, 2, SX_OFFSET),
    SX_FIELD("value_offset", "uint16", 2, 2, SX_OFFSET),
};
const sx_layout sxc_apfs_btree_kvoff = {UINT32_C(0x6018000B),"apfs_btree_kvoff",sxc_apfs_btree_kvoff_fields,SX_COUNT(sxc_apfs_btree_kvoff_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_btree_kvloc_fields[] = {
    SX_FIELD("key_offset", "uint16", 0, 2, SX_OFFSET),
    SX_FIELD("key_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("value_offset", "uint16", 4, 2, SX_OFFSET),
    SX_FIELD("value_length", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sxc_apfs_btree_kvloc = {UINT32_C(0x6018000C),"apfs_btree_kvloc",sxc_apfs_btree_kvloc_fields,SX_COUNT(sxc_apfs_btree_kvloc_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_omap_key_fields[] = {
    SX_FIELD("object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 8, 8, SX_ID),
};
const sx_layout sxc_apfs_omap_key = {UINT32_C(0x6018000D),"apfs_omap_key",sxc_apfs_omap_key_fields,SX_COUNT(sxc_apfs_omap_key_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_btree_child_fields[] = {
    SX_FIELD("child_oid", "uint64", 0, 8, SX_ID),
};
const sx_layout sxc_apfs_btree_child = {UINT32_C(0x6018000F),"apfs_btree_child",sxc_apfs_btree_child_fields,SX_COUNT(sxc_apfs_btree_child_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_volume_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("magic", "char[4]", 32, 4, SX_SIGNATURE),
    SX_FIELD("filesystem_index", "uint32", 36, 4, SX_NONE),
    SX_FIELD("features", "uint64", 40, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_features", "uint64", 48, 8, SX_FLAGS),
    SX_FIELD("incompatible_features", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("unmount_time", "uint64", 64, 8, SX_TIME),
    SX_FIELD("reserve_block_count", "uint64", 72, 8, SX_COUNT_PROP),
    SX_FIELD("quota_block_count", "uint64", 80, 8, SX_COUNT_PROP),
    SX_FIELD("allocated_block_count", "uint64", 88, 8, SX_COUNT_PROP),
    SX_FIELD("crypto_major_version", "uint16", 96, 2, SX_ID),
    SX_FIELD("crypto_minor_version", "uint16", 98, 2, SX_ID),
    SX_FIELD("crypto_flags", "uint32", 100, 4, SX_FLAGS),
    SX_FIELD("crypto_protection_class", "uint32", 104, 4, SX_ID),
    SX_FIELD("crypto_key_os_version", "uint32", 108, 4, SX_ID),
    SX_FIELD("crypto_key_revision", "uint16", 112, 2, SX_ID),
    SX_FIELD("crypto_unused", "uint16", 114, 2, SX_RESERVED),
    SX_FIELD("root_tree_type", "uint32", 116, 4, SX_FLAGS),
    SX_FIELD("extentref_tree_type", "uint32", 120, 4, SX_FLAGS),
    SX_FIELD("snapshot_metadata_tree_type", "uint32", 124, 4, SX_FLAGS),
    SX_FIELD("omap_oid", "uint64", 128, 8, SX_ID),
    SX_FIELD("root_tree_oid", "uint64", 136, 8, SX_ID),
    SX_FIELD("extentref_tree_oid", "uint64", 144, 8, SX_ID),
    SX_FIELD("snapshot_metadata_tree_oid", "uint64", 152, 8, SX_ID),
    SX_FIELD("revert_to_xid", "uint64", 160, 8, SX_ID),
    SX_FIELD("revert_to_superblock_oid", "uint64", 168, 8, SX_ID),
    SX_FIELD("next_object_id", "uint64", 176, 8, SX_ID),
    SX_FIELD("file_count", "uint64", 184, 8, SX_COUNT_PROP),
    SX_FIELD("directory_count", "uint64", 192, 8, SX_COUNT_PROP),
    SX_FIELD("symlink_count", "uint64", 200, 8, SX_COUNT_PROP),
    SX_FIELD("other_object_count", "uint64", 208, 8, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint64", 216, 8, SX_COUNT_PROP),
    SX_FIELD("total_blocks_allocated", "uint64", 224, 8, SX_COUNT_PROP),
    SX_FIELD("total_blocks_freed", "uint64", 232, 8, SX_COUNT_PROP),
    SX_FIELD("volume_uuid", "uint8[16]", 240, 16, SX_NONE),
    SX_FIELD("last_modified_time", "uint64", 256, 8, SX_TIME),
    SX_FIELD("filesystem_flags", "uint64", 264, 8, SX_FLAGS),
};
const sx_layout sxc_apfs_volume_header = {UINT32_C(0x60180010),"apfs_volume_header",sxc_apfs_volume_header_fields,SX_COUNT(sxc_apfs_volume_header_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_modified_by_fields[] = {
    SX_FIELD("identifier", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("timestamp", "uint64", 32, 8, SX_TIME),
    SX_FIELD("last_transaction_id", "uint64", 40, 8, SX_ID),
};
const sx_layout sxc_apfs_modified_by = {UINT32_C(0x60180011),"apfs_modified_by",sxc_apfs_modified_by_fields,SX_COUNT(sxc_apfs_modified_by_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_volume_name_fields[] = {
    SX_FIELD("volume_name", "char[256]", 0, 256, SX_STRING),
};
const sx_layout sxc_apfs_volume_name = {UINT32_C(0x60180012),"apfs_volume_name",sxc_apfs_volume_name_fields,SX_COUNT(sxc_apfs_volume_name_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_volume_tail_fields[] = {
    SX_FIELD("next_document_id", "uint32", 0, 4, SX_ID),
    SX_FIELD("role", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("reserved", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("root_to_xid", "uint64", 8, 8, SX_ID),
    SX_FIELD("er_state_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("cloneinfo_id_epoch", "uint64", 24, 8, SX_NONE),
    SX_FIELD("cloneinfo_xid", "uint64", 32, 8, SX_ID),
    SX_FIELD("snapshot_metadata_extended_oid", "uint64", 40, 8, SX_ID),
    SX_FIELD("volume_group_id", "uint8[16]", 48, 16, SX_NONE),
    SX_FIELD("integrity_metadata_oid", "uint64", 64, 8, SX_ID),
    SX_FIELD("file_extent_tree_oid", "uint64", 72, 8, SX_ID),
    SX_FIELD("file_extent_tree_type", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("reserved_type", "uint32", 84, 4, SX_RESERVED),
    SX_FIELD("reserved_oid", "uint64", 88, 8, SX_RESERVED),
};
const sx_layout sxc_apfs_volume_tail = {UINT32_C(0x60180013),"apfs_volume_tail",sxc_apfs_volume_tail_fields,SX_COUNT(sxc_apfs_volume_tail_fields),SX_LE};
/* Local checks avoid introducing a codec or native-reader link dependency in
 * minimal/bytecode profiles. Each algorithm checks the physical object bytes. */
static uint64_t sxc_fletcher(const uint8_t *p,uint32_t n)
{
    const uint64_t mod=UINT64_C(0xffffffff);uint64_t a=0,b=0;
    for(uint32_t i=8;i<n;i+=4){a=(a+sxc_u32(p+i))%mod;b=(b+a)%mod;}
    uint64_t lo=mod-(a+b)%mod,hi=mod-(a+lo)%mod;return lo|(hi<<32);
}
static bool sxc_apfs_object(sx_context *c,uint64_t block,uint32_t unit,uint8_t *b,int64_t *at)
{
    if(!unit||block>(uint64_t)INT64_MAX/unit)return false;*at=(int64_t)(block*unit);
    return sxc_can(c,*at,unit)&&sx_read(c,*at,b,unit)&&sxc_u64(b)==sxc_fletcher(b,unit);
}
static bool sxc_apfs_container(sx_context *c,int64_t at,const uint8_t *b,uint32_t unit)
{
    if(unit<184||xx_rt_memcmp(b+32,"NXSB",4)||(sxc_u32(b+24)&65535)!=1||sxc_u32(b+36)!=unit||!sxc_u64(b+40)||!sxc_u32(b+180)||sxc_u32(b+180)>100)return false;
    if(!sxc_add(c,&sxc_apfs_container_header,at,184))return false;
    uint32_t slots=(unit-184)/8;if(slots>100)slots=100;
    if(slots&&!sxc_table(c,&sxc_apfs_file_system_oid,at+184,8,slots))return false;
    if(unit>=984){uint32_t counters=(unit-984)/8;if(counters>32)counters=32;if(counters&&!sxc_table(c,&sxc_apfs_container_counter,at+984,8,counters))return false;}
    if(unit>=1408&&!sxc_add(c,&sxc_apfs_container_tail,at+1240,168))return false;
    return true;
}
typedef struct sxc_apfs_work {uint64_t block;uint32_t key_size,value_size;unsigned depth;} sxc_apfs_work;
static bool sxc_apfs_tree(sx_context *c,uint64_t root,uint32_t unit)
{
    uint8_t *b=xx_mem_alloc(unit);sxc_apfs_work *queue=xx_mem_alloc(4096*sizeof(*queue));size_t count=1;bool ok=false;
    if(!b||!queue)goto done;queue[0]=(sxc_apfs_work){root,0,0,0};
    for(size_t q=0;q<count;q++){
        if(xx_pd_is_stopped(c->pd))goto done;if(queue[q].depth>64)goto done;int64_t at;
        if(!sxc_apfs_object(c,queue[q].block,unit,b,&at))continue;
        uint32_t type=sxc_u32(b+24)&65535;if((type!=2&&type!=3)||sxc_u32(b+28)!=11)continue;
        uint16_t flags=sxc_u16(b+32);uint32_t n=sxc_u32(b+36),toc=56U+sxc_u16(b+40),len=sxc_u16(b+42),end=unit-((flags&1)?40:0),entry=(flags&4)?4:8;
        uint32_t key_size=queue[q].key_size,value_size=queue[q].value_size;if(flags&1){key_size=sxc_u32(b+end+8);value_size=sxc_u32(b+end+12);}
        if(toc>end||len>end-toc||n>len/entry||((flags&4)&&(!key_size||key_size>unit)))continue;
        uint32_t key_base=toc+len;bool good=true;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+toc+i*entry;uint32_t ko=sxc_u16(p),kl=(flags&4)?key_size:sxc_u16(p+2),vo=sxc_u16(p+((flags&4)?2:4)),vl=(flags&4)?((flags&2)?value_size:8):sxc_u16(p+6);
            if(ko>end-key_base||kl>end-key_base-ko||vo>end||vl>vo||end-vo<key_base+ko+kl){good=false;break;}
        }if(!good)continue;
        if(!sxc_add(c,&sxc_apfs_btree_node,at,56))goto done;
        if(n&&!sxc_table(c,(flags&4)?&sxc_apfs_btree_kvoff:&sxc_apfs_btree_kvloc,at+toc,entry,n))goto done;
        if((flags&1)&&!sxc_add(c,&sxc_apfs_btree_info,at+end,40))goto done;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+toc+i*entry;uint32_t ko=sxc_u16(p),kl=(flags&4)?key_size:sxc_u16(p+2),vo=sxc_u16(p+((flags&4)?2:4)),vl=(flags&4)?((flags&2)?value_size:8):sxc_u16(p+6),value=end-vo;
            if(kl==16&&!sxc_add(c,&sxc_apfs_omap_key,at+key_base+ko,16))goto done;
            if(flags&2){if(vl==16&&!sxc_add(c,&sxc_apfs_omap_value,at+value,16))goto done;}
            else if(vl>=8){
                if(!sxc_add(c,&sxc_apfs_btree_child,at+value,8))goto done;uint64_t child=sxc_u64(b+value);bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].block==child)seen=true;
                if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_apfs_work){child,key_size,value_size,queue[q].depth+1};}
            }
        }
    }ok=true;
done:xx_mem_free(queue);xx_mem_free(b);return ok;
}
static bool sxc_apfs_omap(sx_context *c,uint64_t block,uint32_t unit)
{
    if(!block)return true;uint8_t b[88];int64_t at;if(block>(uint64_t)INT64_MAX/unit)return true;at=(int64_t)(block*unit);
    uint8_t *full=xx_mem_alloc(unit);if(!full)return false;bool valid=sxc_apfs_object(c,block,unit,full,&at)&&(sxc_u32(full+24)&65535)==11;
    if(valid)xx_rt_memcpy(b,full,88);xx_mem_free(full);if(!valid)return !c->failed&&!xx_pd_is_stopped(c->pd);
    return sxc_add(c,&sxc_apfs_object_map,at,88)&&sxc_apfs_tree(c,sxc_u64(b+48),unit);
}
static bool sxc_apfs_build(sx_context *c)
{
    const xx_apfs *f=(const xx_apfs *)c->f;uint32_t unit=f->block_size;uint8_t *b=xx_mem_alloc(unit);bool ok=false;int64_t at;uint64_t base;uint32_t count;
    if(!b||unit<512||unit>65536||(unit&(unit-1)))goto done;
    if(!sxc_apfs_object(c,0,unit,b,&at)||!sxc_apfs_container(c,at,b,unit))goto done;
    base=sxc_u64(b+112);count=sxc_u32(b+104);
    /* The initial descriptor range is frozen before scanning checkpoints. */
    if(!(count&UINT32_C(0x80000000))&&count<=8192&&base&&base<=INT64_MAX){
        for(uint32_t i=0;i<count;i++){
            if(xx_pd_is_stopped(c->pd))goto done;if(base>UINT64_MAX-i)break;if(!sxc_apfs_object(c,base+i,unit,b,&at))continue;uint32_t type=sxc_u32(b+24)&65535;
            if(type==1){size_t saved=c->count;if(!sxc_apfs_container(c,at,b,unit)){if(c->failed)goto done;c->count=saved;}}
            else if(type==12){uint32_t n=sxc_u32(b+36);if(n>(unit-40)/40)continue;if(!sxc_add(c,&sxc_apfs_checkpoint_map,at,40)||(n&&!sxc_table(c,&sxc_apfs_checkpoint_mapping,at+40,40,n)))goto done;}
            else if(type!=2&&type!=3&&type!=11&&type!=13){if(!sxc_add(c,&sxc_apfs_object_header,at,32))goto done;}
        }
    }
    if(!sxc_apfs_omap(c,f->omap_oid,unit))goto done;
    for(uint32_t i=0;i<f->volume_count&&i<100;i++){
        const xx_apfs_volume_info *v=&f->volumes[i];if(!v->superblock_valid||v->block<0)continue;
        if(!sxc_apfs_object(c,(uint64_t)v->block,unit,b,&at)||(sxc_u32(b+24)&65535)!=13||xx_rt_memcmp(b+32,"APSB",4))continue;
        if(!sxc_add(c,&sxc_apfs_volume_header,at,272))goto done;
        uint32_t records=(unit-272)/48;if(records>9)records=9;if(records&&!sxc_table(c,&sxc_apfs_modified_by,at+272,48,records))goto done;
        if(unit>=960&&!sxc_add(c,&sxc_apfs_volume_name,at+704,256))goto done;
        if(unit>=1056&&!sxc_add(c,&sxc_apfs_volume_tail,at+960,96))goto done;
        if(!sxc_apfs_omap(c,v->omap_oid,unit))goto done;
    }ok=true;
done:xx_mem_free(b);return ok;
}
bool sx_apfs_build(sx_context*c)
{
 return sxc_apfs_build(c);
}
