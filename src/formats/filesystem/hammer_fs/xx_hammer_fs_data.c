/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HAMMER FS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_hammer_volume_header_le_fields[] = {
    SX_FIELD("signature","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("boot_begin","int64",8,8,SX_OFFSET),
    SX_FIELD("memory_log_begin","int64",16,8,SX_OFFSET),
    SX_FIELD("buffer_begin","int64",24,8,SX_OFFSET),
    SX_FIELD("buffer_end","int64",32,8,SX_OFFSET),
    SX_FIELD("reserved0","int64",40,8,SX_RESERVED),
    SX_FIELD("filesystem_uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("filesystem_type_uuid","byte[16]",64,16,SX_ID),
    SX_FIELD("label","char[64]",80,64,SX_STRING),
    SX_FIELD("volume_number","int32",144,4,SX_NONE),
    SX_FIELD("volume_count","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",152,4,SX_ID),
    SX_FIELD("crc","uint32",156,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",160,4,SX_FLAGS),
    SX_FIELD("root_volume_number","uint32",164,4,SX_NONE),
    SX_FIELD("reserved1","uint32[8]",168,32,SX_RESERVED),
    SX_FIELD("bigblock_count","int64",200,8,SX_COUNT_PROP),
    SX_FIELD("free_bigblocks","int64",208,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","int64",216,8,SX_RESERVED),
    SX_FIELD("inode_count","int64",224,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","int64",232,8,SX_RESERVED),
    SX_FIELD("btree_root","uint64",240,8,SX_POINTER),
    SX_FIELD("next_transaction_id","uint64",248,8,SX_NONE),
    SX_FIELD("reserved4","uint64",256,8,SX_RESERVED),
};
const sx_layout sxmf_hammer_volume_header_le = {0x60420037U,"hammer_volume_header_le",sxmf_hammer_volume_header_le_fields,SX_COUNT(sxmf_hammer_volume_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_volume_header_be_fields[] = {
    SX_FIELD("signature","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("boot_begin","int64",8,8,SX_OFFSET),
    SX_FIELD("memory_log_begin","int64",16,8,SX_OFFSET),
    SX_FIELD("buffer_begin","int64",24,8,SX_OFFSET),
    SX_FIELD("buffer_end","int64",32,8,SX_OFFSET),
    SX_FIELD("reserved0","int64",40,8,SX_RESERVED),
    SX_FIELD("filesystem_uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("filesystem_type_uuid","byte[16]",64,16,SX_ID),
    SX_FIELD("label","char[64]",80,64,SX_STRING),
    SX_FIELD("volume_number","int32",144,4,SX_NONE),
    SX_FIELD("volume_count","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",152,4,SX_ID),
    SX_FIELD("crc","uint32",156,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",160,4,SX_FLAGS),
    SX_FIELD("root_volume_number","uint32",164,4,SX_NONE),
    SX_FIELD("reserved1","uint32[8]",168,32,SX_RESERVED),
    SX_FIELD("bigblock_count","int64",200,8,SX_COUNT_PROP),
    SX_FIELD("free_bigblocks","int64",208,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","int64",216,8,SX_RESERVED),
    SX_FIELD("inode_count","int64",224,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","int64",232,8,SX_RESERVED),
    SX_FIELD("btree_root","uint64",240,8,SX_POINTER),
    SX_FIELD("next_transaction_id","uint64",248,8,SX_NONE),
    SX_FIELD("reserved4","uint64",256,8,SX_RESERVED),
};
const sx_layout sxmf_hammer_volume_header_be = {0x60420038U,"hammer_volume_header_be",sxmf_hammer_volume_header_be_fields,SX_COUNT(sxmf_hammer_volume_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_blockmap_le_fields[] = {
    SX_FIELD("physical_offset","uint64",0,8,SX_POINTER),
    SX_FIELD("first_offset","uint64",8,8,SX_POINTER),
    SX_FIELD("next_offset","uint64",16,8,SX_POINTER),
    SX_FIELD("allocation_offset","uint64",24,8,SX_POINTER),
    SX_FIELD("reserved","uint32",32,4,SX_RESERVED),
    SX_FIELD("crc","uint32",36,4,SX_CHECKSUM),
};
const sx_layout sxmf_hammer_blockmap_le = {0x60420039U,"hammer_blockmap_le",sxmf_hammer_blockmap_le_fields,SX_COUNT(sxmf_hammer_blockmap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_blockmap_be_fields[] = {
    SX_FIELD("physical_offset","uint64",0,8,SX_POINTER),
    SX_FIELD("first_offset","uint64",8,8,SX_POINTER),
    SX_FIELD("next_offset","uint64",16,8,SX_POINTER),
    SX_FIELD("allocation_offset","uint64",24,8,SX_POINTER),
    SX_FIELD("reserved","uint32",32,4,SX_RESERVED),
    SX_FIELD("crc","uint32",36,4,SX_CHECKSUM),
};
const sx_layout sxmf_hammer_blockmap_be = {0x6042003aU,"hammer_blockmap_be",sxmf_hammer_blockmap_be_fields,SX_COUNT(sxmf_hammer_blockmap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_undo_pointer_le_fields[] = {
    SX_FIELD("address","uint64",0,8,SX_POINTER),
};
const sx_layout sxmf_hammer_undo_pointer_le = {0x6042003bU,"hammer_undo_pointer_le",sxmf_hammer_undo_pointer_le_fields,SX_COUNT(sxmf_hammer_undo_pointer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_undo_pointer_be_fields[] = {
    SX_FIELD("address","uint64",0,8,SX_POINTER),
};
const sx_layout sxmf_hammer_undo_pointer_be = {0x6042003cU,"hammer_undo_pointer_be",sxmf_hammer_undo_pointer_be_fields,SX_COUNT(sxmf_hammer_undo_pointer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_node_header_le_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("reserved0","uint32",4,4,SX_RESERVED),
    SX_FIELD("parent","uint64",8,8,SX_POINTER),
    SX_FIELD("count","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved1","uint8",21,1,SX_RESERVED),
    SX_FIELD("reserved2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved3","uint64[4]",24,32,SX_RESERVED),
    SX_FIELD("mirror_transaction","uint64",56,8,SX_NONE),
};
const sx_layout sxmf_hammer_node_header_le = {0x60420078U,"hammer_node_header_le",sxmf_hammer_node_header_le_fields,SX_COUNT(sxmf_hammer_node_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_node_header_be_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("reserved0","uint32",4,4,SX_RESERVED),
    SX_FIELD("parent","uint64",8,8,SX_POINTER),
    SX_FIELD("count","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved1","uint8",21,1,SX_RESERVED),
    SX_FIELD("reserved2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved3","uint64[4]",24,32,SX_RESERVED),
    SX_FIELD("mirror_transaction","uint64",56,8,SX_NONE),
};
const sx_layout sxmf_hammer_node_header_be = {0x60420079U,"hammer_node_header_be",sxmf_hammer_node_header_be_fields,SX_COUNT(sxmf_hammer_node_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_internal_record_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("mirror_transaction","uint64",40,8,SX_NONE),
    SX_FIELD("subtree","uint64",48,8,SX_POINTER),
    SX_FIELD("reserved","int32[2]",56,8,SX_RESERVED),
};
const sx_layout sxmf_hammer_internal_record_le = {0x6042007aU,"hammer_internal_record_le",sxmf_hammer_internal_record_le_fields,SX_COUNT(sxmf_hammer_internal_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_internal_record_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("mirror_transaction","uint64",40,8,SX_NONE),
    SX_FIELD("subtree","uint64",48,8,SX_POINTER),
    SX_FIELD("reserved","int32[2]",56,8,SX_RESERVED),
};
const sx_layout sxmf_hammer_internal_record_be = {0x6042007bU,"hammer_internal_record_be",sxmf_hammer_internal_record_be_fields,SX_COUNT(sxmf_hammer_internal_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_leaf_record_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("creation_time","uint32",40,4,SX_TIME),
    SX_FIELD("deletion_time","uint32",44,4,SX_TIME),
    SX_FIELD("data_address","uint64",48,8,SX_POINTER),
    SX_FIELD("data_length","int32",56,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
};
const sx_layout sxmf_hammer_leaf_record_le = {0x6042007cU,"hammer_leaf_record_le",sxmf_hammer_leaf_record_le_fields,SX_COUNT(sxmf_hammer_leaf_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_leaf_record_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("creation_time","uint32",40,4,SX_TIME),
    SX_FIELD("deletion_time","uint32",44,4,SX_TIME),
    SX_FIELD("data_address","uint64",48,8,SX_POINTER),
    SX_FIELD("data_length","int32",56,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
};
const sx_layout sxmf_hammer_leaf_record_be = {0x6042007dU,"hammer_leaf_record_be",sxmf_hammer_leaf_record_be_fields,SX_COUNT(sxmf_hammer_leaf_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_inode_le_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("user_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("device_major","uint32",8,4,SX_ID),
    SX_FIELD("device_minor","uint32",12,4,SX_ID),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("parent_object","int64",24,8,SX_ID),
    SX_FIELD("uid","byte[16]",32,16,SX_ID),
    SX_FIELD("gid","byte[16]",48,16,SX_ID),
    SX_FIELD("type","uint8",64,1,SX_ID),
    SX_FIELD("capabilities","uint8",65,1,SX_FLAGS),
    SX_FIELD("reserved0","uint16",66,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32",68,4,SX_RESERVED),
    SX_FIELD("link_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",80,8,SX_SIZE),
    SX_FIELD("inline_extension","byte[24]",88,24,SX_NONE),
    SX_FIELD("modification_time","uint64",112,8,SX_TIME),
    SX_FIELD("access_time","uint64",120,8,SX_TIME),
};
const sx_layout sxmf_hammer_inode_le = {0x6042007eU,"hammer_inode_le",sxmf_hammer_inode_le_fields,SX_COUNT(sxmf_hammer_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_inode_be_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("user_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("device_major","uint32",8,4,SX_ID),
    SX_FIELD("device_minor","uint32",12,4,SX_ID),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("parent_object","int64",24,8,SX_ID),
    SX_FIELD("uid","byte[16]",32,16,SX_ID),
    SX_FIELD("gid","byte[16]",48,16,SX_ID),
    SX_FIELD("type","uint8",64,1,SX_ID),
    SX_FIELD("capabilities","uint8",65,1,SX_FLAGS),
    SX_FIELD("reserved0","uint16",66,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32",68,4,SX_RESERVED),
    SX_FIELD("link_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",80,8,SX_SIZE),
    SX_FIELD("inline_extension","byte[24]",88,24,SX_NONE),
    SX_FIELD("modification_time","uint64",112,8,SX_TIME),
    SX_FIELD("access_time","uint64",120,8,SX_TIME),
};
const sx_layout sxmf_hammer_inode_be = {0x6042007fU,"hammer_inode_be",sxmf_hammer_inode_be_fields,SX_COUNT(sxmf_hammer_inode_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_hammer_directory_entry_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("localization","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxmf_hammer_directory_entry_le = {0x60420080U,"hammer_directory_entry_le",sxmf_hammer_directory_entry_le_fields,SX_COUNT(sxmf_hammer_directory_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_hammer_directory_entry_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("localization","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxmf_hammer_directory_entry_be = {0x60420081U,"hammer_directory_entry_be",sxmf_hammer_directory_entry_be_fields,SX_COUNT(sxmf_hammer_directory_entry_be_fields),SX_BE};
#define SXMF_LIMIT 24000U
#define SXMF_ORDER(l,o) ((o)==1?&sxmf_##l##_be:&sxmf_##l##_le)
static bool sxmf_ha_address(uint64_t begin,uint64_t end,uint64_t encoded,uint64_t bytes,uint64_t*out){unsigned zone=(unsigned)(encoded>>60);uint64_t off=encoded&UINT64_C(0xfffffffffffff);if(begin>end||((encoded>>52)&255)||(zone!=2&&zone!=8&&zone!=9&&zone!=10&&zone!=11)||off>end-begin||bytes>end-begin-off)return false;*out=begin+off;return true;}
static bool sxmf_hammer(sx_context*c){uint8_t h[264],b[4096];if(!sxmf_read(c,0,h,264))return false;unsigned o=sxmf64(h,0)==UINT64_C(0xc8414d4dc5523031)?0:sxmf64(h,1)==UINT64_C(0xc8414d4dc5523031)?1:2;if(o==2||!sxmf_put(c,SXMF_ORDER(hammer_volume_header,o),0,1)||!sxmf_put(c,SXMF_ORDER(hammer_blockmap,o),264,16)||!sxmf_put(c,SXMF_ORDER(hammer_undo_pointer,o),904,128))return false;uint64_t begin=sxmf64(h+24,o),end=sxmf64(h+32,o),root;if(begin<8192||begin>=end||end>(uint64_t)c->size||!sxmf_ha_address(begin,end,sxmf64(h+240,o),4096,&root))return true;
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;bool ok=true;sxmf_queue_add(q,root,0,0);while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){sxmf_task t=q->items[q->index++];if(!sxmf_read(c,t.p,b,4096))continue;unsigned n=sxmf32(b+16,o),kind=b[20];if((kind!='I'&&kind!='L')||n>(kind=='I'?62U:63U))continue;if(!sxmf_put(c,SXMF_ORDER(hammer_node_header,o),t.p,1)||!sxmf_put(c,kind=='I'?SXMF_ORDER(hammer_internal_record,o):SXMF_ORDER(hammer_leaf_record,o),t.p+64,n)){ok=false;break;}
  for(unsigned j=0;j<n;j++){uint8_t*r=b+64+j*64;uint64_t at;if(kind=='I'){if(sxmf_ha_address(begin,end,sxmf64(r+48,o),4096,&at))sxmf_queue_add(q,at,0,t.depth+1);}else{uint64_t nbytes=sxmf32(r+56,o);unsigned type=sxmf16(r+32,o);if(!sxmf_ha_address(begin,end,sxmf64(r+48,o),nbytes,&at))continue;if(type==1&&nbytes==128){if(!sxmf_put(c,SXMF_ORDER(hammer_inode,o),at,1)){ok=false;break;}}else if(type==0x11&&nbytes>=16&&!sxmf_put(c,SXMF_ORDER(hammer_directory_entry,o),at,1)){ok=false;break;}}}
 }xx_rt_free(q);return ok;
}
bool sx_hammer_fs_build(sx_context*c)
{
 return sxmf_hammer(c);
}
#undef SXMF_LIMIT
#undef SXMF_ORDER
