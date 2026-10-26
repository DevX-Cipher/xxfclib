/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_vmfs_volume_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unknown0","byte[6]",8,6,SX_NONE),
    SX_FIELD("lun","uint8",14,1,SX_ID),
    SX_FIELD("unknown1","byte[3]",15,3,SX_NONE),
    SX_FIELD("name","char[28]",18,28,SX_STRING),
    SX_FIELD("lun_identity","byte[49]",46,49,SX_NONE),
    SX_FIELD("size_units","uint32",95,4,SX_NONE),
    SX_FIELD("unknown2","byte[31]",99,31,SX_NONE),
    SX_FIELD("uuid","byte[16]",130,16,SX_ID),
    SX_FIELD("creation_time","uint64",146,8,SX_NONE),
    SX_FIELD("modification_time","uint64",154,8,SX_NONE),
};
const sx_layout sxmf_vmfs_volume_header = {0x6042006bU,"vmfs_volume_header",sxmf_vmfs_volume_header_fields,SX_COUNT(sxmf_vmfs_volume_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_lvm_header_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("blocks","uint64",8,8,SX_NONE),
    SX_FIELD("unknown0","uint32",16,4,SX_NONE),
    SX_FIELD("uuid_string","char[35]",20,35,SX_STRING),
    SX_FIELD("unknown1","byte[29]",55,29,SX_NONE),
    SX_FIELD("uuid","byte[16]",84,16,SX_ID),
    SX_FIELD("unknown2","uint32",100,4,SX_NONE),
    SX_FIELD("creation_time","uint64",104,8,SX_NONE),
    SX_FIELD("unknown3","uint32",112,4,SX_NONE),
    SX_FIELD("segment_count","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("first_segment","uint32",120,4,SX_NONE),
    SX_FIELD("unknown4","uint32",124,4,SX_NONE),
    SX_FIELD("last_segment","uint32",128,4,SX_NONE),
    SX_FIELD("unknown5","uint32",132,4,SX_NONE),
    SX_FIELD("modification_time","uint64",136,8,SX_NONE),
    SX_FIELD("extent_count","uint32",144,4,SX_COUNT_PROP),
};
const sx_layout sxmf_vmfs35_lvm_header = {0x6042006cU,"vmfs35_lvm_header",sxmf_vmfs35_lvm_header_fields,SX_COUNT(sxmf_vmfs35_lvm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_filesystem_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("volume_version","uint32",4,4,SX_ID),
    SX_FIELD("version","uint8",8,1,SX_ID),
    SX_FIELD("uuid","byte[16]",9,16,SX_ID),
    SX_FIELD("mode","uint32",25,4,SX_FLAGS),
    SX_FIELD("label","char[128]",29,128,SX_STRING),
    SX_FIELD("device_block_size","uint32",157,4,SX_SIZE),
    SX_FIELD("block_size","uint64",161,8,SX_SIZE),
    SX_FIELD("creation_time","uint32",169,4,SX_TIME),
    SX_FIELD("unknown3","uint32",173,4,SX_NONE),
    SX_FIELD("lvm_uuid","byte[16]",177,16,SX_ID),
    SX_FIELD("unknown4","byte[16]",193,16,SX_NONE),
    SX_FIELD("fdc_header_size","uint32",209,4,SX_SIZE),
    SX_FIELD("fdc_bitmap_count","uint32",213,4,SX_COUNT_PROP),
    SX_FIELD("subblock_size","uint32",217,4,SX_SIZE),
};
const sx_layout sxmf_vmfs35_filesystem_header = {0x6042006dU,"vmfs35_filesystem_header",sxmf_vmfs35_filesystem_header_fields,SX_COUNT(sxmf_vmfs35_filesystem_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_bitmap_header_fields[] = {
    SX_FIELD("items_per_entry","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("entries_per_area","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_size","uint32",12,4,SX_SIZE),
    SX_FIELD("area_size","uint32",16,4,SX_SIZE),
    SX_FIELD("total_items","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("area_count","uint32",24,4,SX_COUNT_PROP),
};
const sx_layout sxmf_vmfs35_bitmap_header = {0x6042006eU,"vmfs35_bitmap_header",sxmf_vmfs35_bitmap_header_fields,SX_COUNT(sxmf_vmfs35_bitmap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_inode_data_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
    SX_FIELD("id2","uint32",4,4,SX_ID),
    SX_FIELD("link_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("type","uint32",12,4,SX_ID),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("file_size","uint64",20,8,SX_SIZE),
    SX_FIELD("block_size","uint64",28,8,SX_SIZE),
    SX_FIELD("block_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("modification_time","uint32",44,4,SX_TIME),
    SX_FIELD("change_time","uint32",48,4,SX_TIME),
    SX_FIELD("access_time","uint32",52,4,SX_TIME),
    SX_FIELD("uid","uint32",56,4,SX_ID),
    SX_FIELD("gid","uint32",60,4,SX_ID),
    SX_FIELD("mode","uint32",64,4,SX_FLAGS),
    SX_FIELD("allocation_format","uint32",68,4,SX_ID),
    SX_FIELD("tbz","uint32",72,4,SX_NONE),
    SX_FIELD("copy_on_write","uint32",76,4,SX_FLAGS),
    SX_FIELD("unknown","byte[432]",80,432,SX_NONE),
};
const sx_layout sxmf_vmfs35_inode_data = {0x6042006fU,"vmfs35_inode_data",sxmf_vmfs35_inode_data_fields,SX_COUNT(sxmf_vmfs35_inode_data_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_directory_entry_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("block_id","uint32",4,4,SX_ID),
    SX_FIELD("record_id","uint32",8,4,SX_ID),
    SX_FIELD("name","char[128]",12,128,SX_STRING),
};
const sx_layout sxmf_vmfs35_directory_entry = {0x60420070U,"vmfs35_directory_entry",sxmf_vmfs35_directory_entry_fields,SX_COUNT(sxmf_vmfs35_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_block_id_fields[] = {
    SX_FIELD("block_id","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmf_vmfs35_block_id = {0x60420071U,"vmfs35_block_id",sxmf_vmfs35_block_id_fields,SX_COUNT(sxmf_vmfs35_block_id_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_vmfs35_metadata_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("position","uint64",4,8,SX_OFFSET),
    SX_FIELD("heartbeat_position","uint64",12,8,SX_OFFSET),
    SX_FIELD("heartbeat_sequence","uint64",20,8,SX_NONE),
    SX_FIELD("object_sequence","uint64",28,8,SX_NONE),
    SX_FIELD("heartbeat_lock","uint32",36,4,SX_FLAGS),
    SX_FIELD("heartbeat_uuid","byte[16]",40,16,SX_ID),
    SX_FIELD("modification_time","uint64",56,8,SX_NONE),
    SX_FIELD("padding","byte[448]",64,448,SX_NONE),
};
const sx_layout sxmf_vmfs35_metadata_header = {0x60420089U,"vmfs35_metadata_header",sxmf_vmfs35_metadata_header_fields,SX_COUNT(sxmf_vmfs35_metadata_header_fields),SX_LE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_vmfs(sx_context*c){uint8_t h[1024],b[2048];if(!sxmf_read(c,1048576,h,1024)||sxmf32(h,0)!=0xc001d00dU||!SXMF_ADD(c,vmfs_volume_header,1048576)||!SXMF_ADD(c,vmfs35_lvm_header,1049088))return false;const uint64_t base=0x1100000,super=0x1300000;if(!sxmf_read(c,super,h,512)||sxmf32(h,0)!=0x2fabf15eU||(h[8]!=3&&h[8]!=5))return true;if(!SXMF_ADD(c,vmfs35_filesystem_header,super))return false;uint64_t bs=sxmf64(h+161,0);if(!sxmf_pow(bs)||bs<1048576||bs>8388608)return true;uint64_t fdc=base+(0x400000/bs)*bs;if(fdc==base)fdc+=bs;if(!sxmf_read(c,fdc,h,28))return true;uint64_t items=sxmf32(h,0),entries=sxmf32(h+4,0),hdr=sxmf32(h+8,0),data=sxmf32(h+12,0),area=sxmf32(h+16,0),total=sxmf32(h+20,0);if(!items||items>1024||!entries||entries>4096||data!=2048||hdr<28||area<entries*1024+items*entries*data||!total||total>65536)return true;if(!SXMF_ADD(c,vmfs35_bitmap_header,fdc))return false;uint64_t per=items*entries;
 for(uint64_t i=0;i<total&&i<4096&&c->count<SXMF_LIMIT;i++){uint64_t p=fdc+hdr+(i/per)*area+entries*1024+(i%per)*data;if(!sxmf_read(c,p,b,2048)||sxmf32(b,0)!=0x10c00001U)continue;if(!SXMF_ADD(c,vmfs35_metadata_header,p)||!SXMF_ADD(c,vmfs35_inode_data,p+512))return false;uint64_t n=sxmf64(b+532,0);unsigned format=sxmf32(b+580,0),type=sxmf32(b+524,0);
  if(format==4305){if(n>1024)continue;if(type==2&&n%140==0&&!SXMF_TABLE(c,vmfs35_directory_entry,p+1024,n/140))return false;}
  else if(format==1&&!SXMF_TABLE(c,vmfs35_block_id,p+1024,256))return false;
 }return true;
}
bool sx_vmfs_build(sx_context*c)
{
 return sxmf_vmfs(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
#undef SXMF_TABLE
