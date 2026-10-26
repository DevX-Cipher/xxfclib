/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical APFS and Btrfs metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_cowfs.h"
static const xx_data_struct_field_desc sxc_apfs_btree_node_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint16", 32, 2, SX_FLAGS),
    SX_FIELD("level", "uint16", 34, 2, SX_NONE),
    SX_FIELD("key_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("table_space_offset", "uint16", 40, 2, SX_OFFSET),
    SX_FIELD("table_space_length", "uint16", 42, 2, SX_SIZE),
    SX_FIELD("free_space_offset", "uint16", 44, 2, SX_OFFSET),
    SX_FIELD("free_space_length", "uint16", 46, 2, SX_SIZE),
    SX_FIELD("key_free_list_offset", "uint16", 48, 2, SX_OFFSET),
    SX_FIELD("key_free_list_length", "uint16", 50, 2, SX_SIZE),
    SX_FIELD("value_free_list_offset", "uint16", 52, 2, SX_OFFSET),
    SX_FIELD("value_free_list_length", "uint16", 54, 2, SX_SIZE),
};
const sx_layout sxc_apfs_btree_node = {UINT32_C(0x60180009),"apfs_btree_node",sxc_apfs_btree_node_fields,SX_COUNT(sxc_apfs_btree_node_fields),SX_LE};
static const xx_data_struct_field_desc sxc_apfs_omap_value_fields[] = {
    SX_FIELD("flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("physical_block", "int64", 8, 8, SX_NONE),
};
const sx_layout sxc_apfs_omap_value = {UINT32_C(0x6018000E),"apfs_omap_value",sxc_apfs_omap_value_fields,SX_COUNT(sxc_apfs_omap_value_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_superblock_header_fields[] = {
    SX_FIELD("checksum", "uint8[32]", 0, 32, SX_CHECKSUM),
    SX_FIELD("fsid", "uint8[16]", 32, 16, SX_NONE),
    SX_FIELD("physical_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("flags", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("magic", "char[8]", 64, 8, SX_SIGNATURE),
    SX_FIELD("generation", "uint64", 72, 8, SX_NONE),
    SX_FIELD("root_logical_address", "uint64", 80, 8, SX_ADDRESS),
    SX_FIELD("chunk_root_logical_address", "uint64", 88, 8, SX_ADDRESS),
    SX_FIELD("log_root_logical_address", "uint64", 96, 8, SX_ADDRESS),
    SX_FIELD("unused_log_root_transid", "uint64", 104, 8, SX_RESERVED),
    SX_FIELD("total_bytes", "uint64", 112, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 120, 8, SX_SIZE),
    SX_FIELD("root_directory_object_id", "uint64", 128, 8, SX_ID),
    SX_FIELD("device_count", "uint64", 136, 8, SX_COUNT_PROP),
    SX_FIELD("sector_size", "uint32", 144, 4, SX_SIZE),
    SX_FIELD("node_size", "uint32", 148, 4, SX_SIZE),
    SX_FIELD("unused_leaf_size", "uint32", 152, 4, SX_RESERVED),
    SX_FIELD("stripe_size", "uint32", 156, 4, SX_SIZE),
    SX_FIELD("system_chunk_array_size", "uint32", 160, 4, SX_SIZE),
    SX_FIELD("chunk_root_generation", "uint64", 164, 8, SX_NONE),
    SX_FIELD("compatible_flags", "uint64", 172, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_flags", "uint64", 180, 8, SX_FLAGS),
    SX_FIELD("incompatible_flags", "uint64", 188, 8, SX_FLAGS),
    SX_FIELD("checksum_type", "uint16", 196, 2, SX_ID),
    SX_FIELD("root_level", "uint8", 198, 1, SX_NONE),
    SX_FIELD("chunk_root_level", "uint8", 199, 1, SX_NONE),
    SX_FIELD("log_root_level", "uint8", 200, 1, SX_NONE),
};
const sx_layout sxc_btrfs_superblock_header = {UINT32_C(0x60180014),"btrfs_superblock_header",sxc_btrfs_superblock_header_fields,SX_COUNT(sxc_btrfs_superblock_header_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_disk_key_fields[] = {
    SX_FIELD("object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("type", "uint8", 8, 1, SX_ID),
    SX_FIELD("offset", "uint64", 9, 8, SX_NONE),
};
const sx_layout sxc_btrfs_disk_key = {UINT32_C(0x60180019),"btrfs_disk_key",sxc_btrfs_disk_key_fields,SX_COUNT(sxc_btrfs_disk_key_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_chunk_fields[] = {
    SX_FIELD("length", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("owner_object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("stripe_length", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("type", "uint64", 24, 8, SX_FLAGS),
    SX_FIELD("io_alignment", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("io_width", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("sector_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("stripe_count", "uint16", 44, 2, SX_COUNT_PROP),
    SX_FIELD("sub_stripe_count", "uint16", 46, 2, SX_COUNT_PROP),
};
const sx_layout sxc_btrfs_chunk = {UINT32_C(0x6018001A),"btrfs_chunk",sxc_btrfs_chunk_fields,SX_COUNT(sxc_btrfs_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_leaf_item_fields[] = {
    SX_FIELD("key_object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("key_type", "uint8", 8, 1, SX_ID),
    SX_FIELD("key_offset", "uint64", 9, 8, SX_NONE),
    SX_FIELD("data_offset", "uint32", 17, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 21, 4, SX_SIZE),
};
const sx_layout sxc_btrfs_leaf_item = {UINT32_C(0x6018001D),"btrfs_leaf_item",sxc_btrfs_leaf_item_fields,SX_COUNT(sxc_btrfs_leaf_item_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_key_pointer_fields[] = {
    SX_FIELD("key_object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("key_type", "uint8", 8, 1, SX_ID),
    SX_FIELD("key_offset", "uint64", 9, 8, SX_NONE),
    SX_FIELD("child_logical_address", "uint64", 17, 8, SX_ADDRESS),
    SX_FIELD("generation", "uint64", 25, 8, SX_NONE),
};
const sx_layout sxc_btrfs_key_pointer = {UINT32_C(0x6018001E),"btrfs_key_pointer",sxc_btrfs_key_pointer_fields,SX_COUNT(sxc_btrfs_key_pointer_fields),SX_LE};
static const sx_layout *const sx_cowfs_layouts[] = {
    &sxc_apfs_object_header,
    &sxc_apfs_container_header,
    &sxc_apfs_file_system_oid,
    &sxc_apfs_container_counter,
    &sxc_apfs_container_tail,
    &sxc_apfs_checkpoint_map,
    &sxc_apfs_checkpoint_mapping,
    &sxc_apfs_object_map,
    &sxc_apfs_btree_node,
    &sxc_apfs_btree_info,
    &sxc_apfs_btree_kvoff,
    &sxc_apfs_btree_kvloc,
    &sxc_apfs_omap_key,
    &sxc_apfs_omap_value,
    &sxc_apfs_btree_child,
    &sxc_apfs_volume_header,
    &sxc_apfs_modified_by,
    &sxc_apfs_volume_name,
    &sxc_apfs_volume_tail,
    &sxc_btrfs_superblock_header,
    &sxc_btrfs_device_item,
    &sxc_btrfs_superblock_tail,
    &sxc_btrfs_root_backup,
    &sxc_btrfs_superblock_padding,
    &sxc_btrfs_disk_key,
    &sxc_btrfs_chunk,
    &sxc_btrfs_stripe,
    &sxc_btrfs_tree_header,
    &sxc_btrfs_leaf_item,
    &sxc_btrfs_key_pointer,
};
#include "xxfclib/formats/filesystem/apfs/xx_apfs.h"
#include "xxfclib/formats/filesystem/btrfs/xx_btrfs.h"
static bool sx_cowfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_APFS||t==XX_FILE_TYPE_BTRFS;}
uint16_t sxc_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
uint32_t sxc_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
uint64_t sxc_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
bool sxc_can(sx_context *c,int64_t at,uint64_t n){return at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at)&&!xx_pd_is_stopped(c->pd);}
bool sxc_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
    if(n<=0||!sxc_can(c,at,(uint64_t)n)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==n)return true;
    return sx_add(c,l,at,n);
}
bool sxc_table(sx_context *c,const sx_layout *l,int64_t at,int64_t entry,uint64_t count)
{
    if(!count)return true;if(entry<=0||count>(uint64_t)INT64_MAX/(uint64_t)entry)return false;int64_t size=(int64_t)count*entry;
    if(!sxc_can(c,at,(uint64_t)size)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==size&&c->items[i].entry_size==entry&&c->items[i].count==count)return true;
    return sx_table(c,l,at,entry,count);
}
static int sxc_order(const void *left,const void *right)
{
    const xx_data_struct *a=left,*b=right;return a->offset<b->offset?-1:a->offset>b->offset?1:0;
}
static bool sxc_finish(sx_context *c)
{
    size_t count=c->count;int64_t end=0;
    xx_rt_qsort(c->items,count,sizeof(*c->items),sxc_order);
    for(size_t i=0;i<count;i++){int64_t at=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxc_order);
    return !c->failed;
}
static bool sx_cowfs_build(sx_context *c)
{
    if(!c->f->handle_base_info||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_APFS?sx_apfs_build(c):c->f->file_type==XX_FILE_TYPE_BTRFS?sx_btrfs_build(c):false;
    return ok&&c->count&&sxc_finish(c);
}
static bool sxc_has(const wchar_t *s,const wchar_t *p){size_t n=xx_rt_wcslen(p);for(;*s;s++)if(!xx_rt_wcsncmp(s,p,n))return true;return false;}
static bool sx_cowfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60180000)||id>=UINT32_C(0x60190000))return true;
    const wchar_t *n=r->name,*text=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(id<sxc_btrfs_superblock_header.id){
        if(!xx_rt_wcscmp(n,L"checksum"))text=L"Fletcher-64 over the remaining bytes of this physical APFS block";
        if(sxc_has(n,L"_block")||sxc_has(n,L"_blocks")||sxc_has(n,L"_base")||!xx_rt_wcscmp(n,L"block_count"))text=L"Container block units; byte position or length = value * container block size";
        if(sxc_has(n,L"blocks_flags"))text=L"Low 31 bits: block count; high bit: descriptor/data area is represented by a tree";
        if(sxc_has(n,L"_time")||!xx_rt_wcscmp(n,L"timestamp"))text=L"Nanoseconds since 1970-01-01 UTC";
        if(!xx_rt_wcscmp(n,L"object_type"))text=(v&65535)==1?L"OBJECT_TYPE_NX_SUPERBLOCK (low 16 bits); upper bits are object flags":(v&65535)==2?L"OBJECT_TYPE_BTREE":(v&65535)==3?L"OBJECT_TYPE_BTREE_NODE":(v&65535)==5?L"OBJECT_TYPE_SPACEMAN":(v&65535)==11?L"OBJECT_TYPE_OMAP":(v&65535)==12?L"OBJECT_TYPE_CHECKPOINT_MAP":(v&65535)==13?L"OBJECT_TYPE_FS":NULL;
        if(!xx_rt_wcscmp(n,L"omap_oid")||!xx_rt_wcscmp(n,L"tree_oid"))text=L"Physical object identifier: container block number";
        if(!xx_rt_wcscmp(n,L"key_offset"))text=L"Byte offset from the start of the B-tree key area";
        if(!xx_rt_wcscmp(n,L"value_offset"))text=L"Positive byte distance backwards from the end of the B-tree value area";
        if(id==sxc_apfs_btree_node.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits: 0 root, 1 leaf, 2 fixed key/value size, 3 hashed, 4 noheader";
        if(id==sxc_apfs_omap_value.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits: 0 deleted, 1 saved, 2 encrypted, 3 noheader, 4 crypto generation";
    }else{
        if(!xx_rt_wcscmp(n,L"checksum"))text=L"Checksum of bytes after this 32-byte field; algorithm selected by the superblock checksum_type";
        if(sxc_has(n,L"logical_address"))text=L"Btrfs logical byte address; translate through the chunk map before seeking on a device";
        if(!xx_rt_wcscmp(n,L"checksum_type"))text=v==0?L"BTRFS_CSUM_TYPE_CRC32 (CRC32C)":v==1?L"BTRFS_CSUM_TYPE_XXHASH":v==2?L"BTRFS_CSUM_TYPE_SHA256":v==3?L"BTRFS_CSUM_TYPE_BLAKE2":NULL;
        if(!xx_rt_wcscmp(n,L"data_offset"))text=L"Byte offset from the end of the 101-byte tree header";
        if(!xx_rt_wcscmp(n,L"offset")||!xx_rt_wcscmp(n,L"key_offset"))text=L"Key-dependent value: object-specific offset, logical address, hash or identifier";
        if((id==sxc_btrfs_disk_key.id||id==sxc_btrfs_leaf_item.id||id==sxc_btrfs_key_pointer.id)&&(sxc_has(n,L"type")))text=v==228?L"BTRFS_CHUNK_ITEM_KEY":v==132?L"BTRFS_ROOT_ITEM_KEY":v==1?L"BTRFS_INODE_ITEM_KEY":v==84?L"BTRFS_DIR_ITEM_KEY":v==108?L"BTRFS_EXTENT_DATA_KEY":NULL;
        if(id==sxc_btrfs_chunk.id&&!xx_rt_wcscmp(n,L"type"))text=L"Bits: 0 DATA, 1 SYSTEM, 2 METADATA, 3 RAID0, 4 RAID1, 5 DUP, 6 RAID10, 7 RAID5, 8 RAID6, 9 RAID1C3, 10 RAID1C4";
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_cowfs_family={sx_cowfs_supports,sx_cowfs_build,sx_cowfs_layouts,SX_COUNT(sx_cowfs_layouts),sx_cowfs_comment};
