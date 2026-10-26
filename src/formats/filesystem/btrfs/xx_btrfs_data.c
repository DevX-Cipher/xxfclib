/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Btrfs data structures, moved out of the cowfs schema family. */
#include "../../xx_format_schema_cowfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/apfs/xx_apfs.h"
#include "xxfclib/formats/filesystem/btrfs/xx_btrfs.h"

static const xx_data_struct_field_desc sxc_btrfs_device_item_fields[] = {
    SX_FIELD("device_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("total_bytes", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("io_alignment", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("io_width", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("sector_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("type", "uint64", 36, 8, SX_FLAGS),
    SX_FIELD("generation", "uint64", 44, 8, SX_NONE),
    SX_FIELD("start_offset", "uint64", 52, 8, SX_OFFSET),
    SX_FIELD("device_group", "uint32", 60, 4, SX_NONE),
    SX_FIELD("seek_speed", "uint8", 64, 1, SX_NONE),
    SX_FIELD("bandwidth", "uint8", 65, 1, SX_NONE),
    SX_FIELD("device_uuid", "uint8[16]", 66, 16, SX_NONE),
    SX_FIELD("filesystem_uuid", "uint8[16]", 82, 16, SX_NONE),
};
const sx_layout sxc_btrfs_device_item = {UINT32_C(0x60180015),"btrfs_device_item",sxc_btrfs_device_item_fields,SX_COUNT(sxc_btrfs_device_item_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_superblock_tail_fields[] = {
    SX_FIELD("label", "char[256]", 0, 256, SX_STRING),
    SX_FIELD("cache_generation", "uint64", 256, 8, SX_NONE),
    SX_FIELD("uuid_tree_generation", "uint64", 264, 8, SX_NONE),
    SX_FIELD("metadata_uuid", "uint8[16]", 272, 16, SX_NONE),
    SX_FIELD("global_root_count", "uint64", 288, 8, SX_COUNT_PROP),
    SX_FIELD("remap_root_logical_address", "uint64", 296, 8, SX_ADDRESS),
    SX_FIELD("remap_root_generation", "uint64", 304, 8, SX_NONE),
    SX_FIELD("remap_root_level", "uint8", 312, 1, SX_NONE),
    SX_FIELD("reserved", "bytes", 313, 199, SX_RESERVED),
};
const sx_layout sxc_btrfs_superblock_tail = {UINT32_C(0x60180016),"btrfs_superblock_tail",sxc_btrfs_superblock_tail_fields,SX_COUNT(sxc_btrfs_superblock_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_root_backup_fields[] = {
    SX_FIELD("tree_root_logical_address", "uint64", 0, 8, SX_ADDRESS),
    SX_FIELD("tree_root_generation", "uint64", 8, 8, SX_NONE),
    SX_FIELD("chunk_root_logical_address", "uint64", 16, 8, SX_ADDRESS),
    SX_FIELD("chunk_root_generation", "uint64", 24, 8, SX_NONE),
    SX_FIELD("extent_root_logical_address", "uint64", 32, 8, SX_ADDRESS),
    SX_FIELD("extent_root_generation", "uint64", 40, 8, SX_NONE),
    SX_FIELD("filesystem_root_logical_address", "uint64", 48, 8, SX_ADDRESS),
    SX_FIELD("filesystem_root_generation", "uint64", 56, 8, SX_NONE),
    SX_FIELD("device_root_logical_address", "uint64", 64, 8, SX_ADDRESS),
    SX_FIELD("device_root_generation", "uint64", 72, 8, SX_NONE),
    SX_FIELD("checksum_root_logical_address", "uint64", 80, 8, SX_ADDRESS),
    SX_FIELD("checksum_root_generation", "uint64", 88, 8, SX_NONE),
    SX_FIELD("total_bytes", "uint64", 96, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 104, 8, SX_SIZE),
    SX_FIELD("device_count", "uint64", 112, 8, SX_COUNT_PROP),
    SX_FIELD("reserved64_0", "uint64", 120, 8, SX_RESERVED),
    SX_FIELD("reserved64_1", "uint64", 128, 8, SX_RESERVED),
    SX_FIELD("reserved64_2", "uint64", 136, 8, SX_RESERVED),
    SX_FIELD("reserved64_3", "uint64", 144, 8, SX_RESERVED),
    SX_FIELD("tree_root_level", "uint8", 152, 1, SX_NONE),
    SX_FIELD("chunk_root_level", "uint8", 153, 1, SX_NONE),
    SX_FIELD("extent_root_level", "uint8", 154, 1, SX_NONE),
    SX_FIELD("filesystem_root_level", "uint8", 155, 1, SX_NONE),
    SX_FIELD("device_root_level", "uint8", 156, 1, SX_NONE),
    SX_FIELD("checksum_root_level", "uint8", 157, 1, SX_NONE),
    SX_FIELD("reserved8", "uint8[10]", 158, 10, SX_RESERVED),
};
const sx_layout sxc_btrfs_root_backup = {UINT32_C(0x60180017),"btrfs_root_backup",sxc_btrfs_root_backup_fields,SX_COUNT(sxc_btrfs_root_backup_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_superblock_padding_fields[] = {
    SX_FIELD("padding", "bytes", 0, 565, SX_RESERVED),
};
const sx_layout sxc_btrfs_superblock_padding = {UINT32_C(0x60180018),"btrfs_superblock_padding",sxc_btrfs_superblock_padding_fields,SX_COUNT(sxc_btrfs_superblock_padding_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_stripe_fields[] = {
    SX_FIELD("device_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("physical_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("device_uuid", "uint8[16]", 16, 16, SX_NONE),
};
const sx_layout sxc_btrfs_stripe = {UINT32_C(0x6018001B),"btrfs_stripe",sxc_btrfs_stripe_fields,SX_COUNT(sxc_btrfs_stripe_fields),SX_LE};
static const xx_data_struct_field_desc sxc_btrfs_tree_header_fields[] = {
    SX_FIELD("checksum", "uint8[32]", 0, 32, SX_CHECKSUM),
    SX_FIELD("fsid", "uint8[16]", 32, 16, SX_NONE),
    SX_FIELD("logical_address", "uint64", 48, 8, SX_ADDRESS),
    SX_FIELD("flags", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("chunk_tree_uuid", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("generation", "uint64", 80, 8, SX_NONE),
    SX_FIELD("owner_object_id", "uint64", 88, 8, SX_ID),
    SX_FIELD("item_count", "uint32", 96, 4, SX_COUNT_PROP),
    SX_FIELD("level", "uint8", 100, 1, SX_NONE),
};
const sx_layout sxc_btrfs_tree_header = {UINT32_C(0x6018001C),"btrfs_tree_header",sxc_btrfs_tree_header_fields,SX_COUNT(sxc_btrfs_tree_header_fields),SX_LE};
static uint32_t sxc_crc32c(const uint8_t *p,uint32_t n)
{
    uint32_t crc=UINT32_MAX;for(uint32_t i=0;i<n;i++){crc^=p[i];for(unsigned j=0;j<8;j++)crc=(crc>>1)^((crc&1)?UINT32_C(0x82f63b78):0);}return ~crc;
}
typedef struct sxc_bt_mapping {uint64_t logical,length,physical;} sxc_bt_mapping;
typedef struct sxc_bt_maps {sxc_bt_mapping rows[128];size_t count;} sxc_bt_maps;
static bool sxc_bt_chunk(sx_context *c,int64_t at,const uint8_t *p,uint32_t available,uint64_t logical,uint64_t device,sxc_bt_maps *maps)
{
    if(available<48)return false;uint16_t n=sxc_u16(p+44);if(!n||n>(available-48)/32)return false;
    if(!sxc_add(c,&sxc_btrfs_chunk,at,48)||!sxc_table(c,&sxc_btrfs_stripe,at+48,32,n))return false;
    uint64_t length=sxc_u64(p);if(maps&&length&&logical<=UINT64_MAX-length&&!(sxc_u64(p+24)&(8|64|128|256))){
        for(uint16_t i=0;i<n;i++)if(sxc_u64(p+48+i*32)==device){
            size_t row=0;while(row<maps->count&&maps->rows[row].logical!=logical)row++;
            if(row==maps->count){if(row>=128)return false;maps->count++;}
            maps->rows[row]=(sxc_bt_mapping){logical,length,sxc_u64(p+56+i*32)};break;
        }
    }return true;
}
static bool sxc_bt_physical(sx_context *c,const sxc_bt_maps *maps,uint64_t logical,uint32_t size,int64_t *at)
{
    for(size_t i=0;i<maps->count;i++){
        const sxc_bt_mapping *m=&maps->rows[i];if(logical<m->logical||logical-m->logical>=m->length)continue;uint64_t delta=logical-m->logical;
        if(size>m->length-delta||m->physical>UINT64_MAX-delta||m->physical+delta>INT64_MAX)return false;*at=(int64_t)(m->physical+delta);return sxc_can(c,*at,size);
    }return false;
}
static bool sxc_bt_super_valid(sx_context *c,int64_t at,uint8_t b[4096])
{
    if(!sxc_can(c,at,4096)||!sx_read(c,at,b,4096)||xx_rt_memcmp(b+64,"_BHRfS_M",8)||sxc_u64(b+48)!=(uint64_t)at)return false;
    uint32_t unit=sxc_u32(b+144),node=sxc_u32(b+148);
    if(node<4096||node>65536||(node&(node-1))||unit<512||unit>node||(unit&(unit-1))||sxc_u32(b+160)>2048||!sxc_u64(b+136)||b[198]>64||b[199]>64)return false;
    return sxc_u16(b+196)!=0||sxc_u32(b)==sxc_crc32c(b+32,4064);
}
static bool sxc_bt_super(sx_context *c,int64_t at,const uint8_t b[4096],sxc_bt_maps *maps)
{
    if(!sxc_add(c,&sxc_btrfs_superblock_header,at,201)||!sxc_add(c,&sxc_btrfs_device_item,at+201,98)||!sxc_add(c,&sxc_btrfs_superblock_tail,at+299,512)||!sxc_table(c,&sxc_btrfs_root_backup,at+2859,168,4)||!sxc_add(c,&sxc_btrfs_superblock_padding,at+3531,565))return false;
    uint32_t bytes=sxc_u32(b+160),pos=811,end=811+bytes;
    while(end-pos>=65){const uint8_t *p=b+pos;uint16_t n=sxc_u16(p+17+44);if(p[8]!=228||sxc_u64(p)!=256||!n||n>(end-pos-65)/32)break;
        if(!sxc_add(c,&sxc_btrfs_disk_key,at+pos,17)||!sxc_bt_chunk(c,at+pos+17,p+17,end-pos-17,sxc_u64(p+9),sxc_u64(b+201),maps))return false;pos+=65U+(uint32_t)n*32;
    }return true;
}
typedef struct sxc_bt_work {uint64_t logical;unsigned depth;} sxc_bt_work;
static bool sxc_bt_tree(sx_context *c,const xx_btrfs *f,sxc_bt_maps *maps)
{
    uint32_t unit=f->node_size;uint8_t *b=xx_mem_alloc(unit);sxc_bt_work *queue=xx_mem_alloc(4096*sizeof(*queue));size_t count=0;bool ok=false;
    if(!b||!queue)goto done;
    uint64_t roots[]={f->chunk_root,f->root_tree,f->fs_tree_root};size_t q=0;
    /* Complete the chunk-tree mapping pass before scheduling other roots. */
    for(unsigned phase=0;phase<2;phase++){
    for(unsigned i=phase?1:0;i<(phase?3:1);i++)if(roots[i]){bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].logical==roots[i])seen=true;if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_bt_work){roots[i],0};}}
    for(;q<count;q++){
        if(xx_pd_is_stopped(c->pd)||queue[q].depth>64)goto done;int64_t at;uint64_t logical=queue[q].logical;
        if(!sxc_bt_physical(c,maps,logical,unit,&at)||!sx_read(c,at,b,unit))continue;
        if(sxc_u32(b)!=sxc_crc32c(b+32,unit-32)||sxc_u64(b+48)!=logical||(xx_rt_memcmp(b+32,f->fsid,16)&&xx_rt_memcmp(b+32,f->metadata_uuid,16)))continue;
        uint32_t n=sxc_u32(b+96),entry=b[100]?33:25;if(b[100]>64||n>(unit-101)/entry)continue;
        bool good=true;for(uint32_t i=0;i<n&&!b[100];i++){const uint8_t *p=b+101+i*25;uint32_t pos=sxc_u32(p+17),size=sxc_u32(p+21);if(pos>unit-101||size>unit-101-pos||pos<n*25){good=false;break;}}if(!good)continue;
        if(!sxc_add(c,&sxc_btrfs_tree_header,at,101)||(n&&!sxc_table(c,b[100]?&sxc_btrfs_key_pointer:&sxc_btrfs_leaf_item,at+101,entry,n)))goto done;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+101+i*entry;
            if(b[100]){uint64_t child=sxc_u64(p+17);bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].logical==child)seen=true;if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_bt_work){child,queue[q].depth+1};}}
            else if(p[8]==228&&sxc_u64(p)==256){uint32_t pos=101+sxc_u32(p+17),size=sxc_u32(p+21);if(size>=48){uint16_t stripes=sxc_u16(b+pos+44);if(stripes&&stripes<=(size-48)/32&&!sxc_bt_chunk(c,at+pos,b+pos,size,sxc_u64(p+9),f->devid,maps))goto done;}}
        }
    }}ok=true;
done:xx_mem_free(queue);xx_mem_free(b);return ok;
}
static bool sxc_btrfs_build(sx_context *c)
{
    const xx_btrfs *f=(const xx_btrfs *)c->f;int64_t at=f->super_offset-c->f->base_address;uint8_t b[4096];sxc_bt_maps maps;xx_rt_memset(&maps,0,sizeof(maps));
    if(!sxc_bt_super_valid(c,at,b)||!sxc_bt_super(c,at,b,&maps))return false;
    const int64_t mirrors[]={INT64_C(0x10000),INT64_C(0x4000000),INT64_C(0x4000000000)};
    for(unsigned i=0;i<3;i++)if(mirrors[i]!=at&&sxc_bt_super_valid(c,mirrors[i],b)&&!xx_rt_memcmp(b+32,f->fsid,16)&&!sxc_bt_super(c,mirrors[i],b,NULL))return false;
    return f->csum_type!=0||sxc_bt_tree(c,f,&maps);
}
bool sx_btrfs_build(sx_context*c)
{
 return sxc_btrfs_build(c);
}
