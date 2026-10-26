/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BFF data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_bff_volume_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("volume_number","uint16",6,2,SX_NONE),
 SX_FIELD("backup_time","int32",8,4,SX_TIME),
 SX_FIELD("since_time","int32",12,4,SX_TIME),
 SX_FIELD("volume_words","int32",16,4,SX_NONE),
 SX_FIELD("disk","char[16]",20,16,SX_NONE),
 SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
 SX_FIELD("user","char[16]",52,16,SX_NONE),
 SX_FIELD("dump_level","int16",68,2,SX_NONE),
 SX_FIELD("padding","uint8[2]",70,2,SX_NONE),
};
const sx_layout sxap_bff_volume = {UINT32_C(0x60720033),"bff_volume",sxap_bff_volume_fields,SX_COUNT(sxap_bff_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_legacy_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("inode","uint16",6,2,SX_NONE),
 SX_FIELD("mode","uint16",8,2,SX_FLAGS),
 SX_FIELD("link_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("uid","uint16",12,2,SX_NONE),
 SX_FIELD("gid","uint16",14,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",16,4,SX_SIZE),
 SX_FIELD("access_time","int32",20,4,SX_TIME),
 SX_FIELD("modification_time","int32",24,4,SX_TIME),
 SX_FIELD("change_time","int32",28,4,SX_TIME),
 SX_FIELD("device_major","uint16",32,2,SX_NONE),
 SX_FIELD("device_minor","uint16",34,2,SX_NONE),
 SX_FIELD("rdevice_major","uint16",36,2,SX_NONE),
 SX_FIELD("rdevice_minor","uint16",38,2,SX_NONE),
 SX_FIELD("compressed_size","int32",40,4,SX_SIZE),
 SX_FIELD("padding","int32",44,4,SX_NONE),
};
const sx_layout sxap_bff_legacy = {UINT32_C(0x60720034),"bff_legacy",sxap_bff_legacy_fields,SX_COUNT(sxap_bff_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_member_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("inode","uint32",8,4,SX_NONE),
 SX_FIELD("mode","uint32",12,4,SX_FLAGS),
 SX_FIELD("uid","uint32",16,4,SX_NONE),
 SX_FIELD("gid","uint32",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("access_time","int32",28,4,SX_TIME),
 SX_FIELD("modification_time","int32",32,4,SX_TIME),
 SX_FIELD("change_time","int32",36,4,SX_TIME),
 SX_FIELD("device_major","uint32",40,4,SX_NONE),
 SX_FIELD("device_minor","uint32",44,4,SX_NONE),
 SX_FIELD("rdevice_major","uint32",48,4,SX_NONE),
 SX_FIELD("rdevice_minor","uint32",52,4,SX_NONE),
 SX_FIELD("compressed_size","int32",56,4,SX_SIZE),
 SX_FIELD("padding","int32",60,4,SX_NONE),
};
const sx_layout sxap_bff_member = {UINT32_C(0x60720035),"bff_member",sxap_bff_member_fields,SX_COUNT(sxap_bff_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_compact_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("inode","uint32",8,4,SX_NONE),
 SX_FIELD("mode","uint32",12,4,SX_FLAGS),
 SX_FIELD("uid","uint32",16,4,SX_NONE),
 SX_FIELD("gid","uint32",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("access_time","uint32",28,4,SX_TIME),
 SX_FIELD("modification_time","uint32",32,4,SX_TIME),
 SX_FIELD("change_time","uint32",36,4,SX_TIME),
 SX_FIELD("unknown","uint8[8]",40,8,SX_NONE),
 SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
 SX_FIELD("unknown_tail","uint8[20]",52,20,SX_NONE),
};
const sx_layout sxap_bff_compact = {UINT32_C(0x60720036),"bff_compact",sxap_bff_compact_fields,SX_COUNT(sxap_bff_compact_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_security_sizes_fields[] = {
 SX_FIELD("acl_words","uint32",0,4,SX_NONE),
 SX_FIELD("pcl_words","uint32",4,4,SX_NONE),
};
const sx_layout sxap_bff_security_sizes = {UINT32_C(0x60720037),"bff_security_sizes",sxap_bff_security_sizes_fields,SX_COUNT(sxap_bff_security_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_terminator_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
};
const sx_layout sxap_bff_terminator = {UINT32_C(0x60720038),"bff_terminator",sxap_bff_terminator_fields,SX_COUNT(sxap_bff_terminator_fields),SX_LE};
static bool sxap_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxap_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static bool sxap_bff(sx_context*c){uint64_t p=72;if(!sxap_add(c,&sxap_bff_volume,0))return false;while(sxap_span(c,p,4)){uint8_t h[72];if(!sxap_read(c,p,h,4))return false;uint64_t words=h[0],type=h[1],fixed=type==9?48:type==12?72:64;if(type==7)return sxap_add(c,&sxap_bff_terminator,p);if((type!=9&&type!=11&&type!=12)||words*8<fixed||!sxap_read(c,p,h,(size_t)fixed)||!sxap_span(c,p,words*8))return false;uint64_t mode=sxap_uint(h+(type==9?8:12),type==9?2:4,false),name,z=sxap_uint(h+(type==9?40:type==11?56:48),4,false),plain=sxap_uint(h+(type==9?16:24),4,false),q=p+words*8;if(!sxap_add(c,type==9?&sxap_bff_legacy:type==11?&sxap_bff_member:&sxap_bff_compact,p)||!sxap_zlen(c,p+fixed,q,&name)||!sxap_text(c,&sxap_archivepackages_name,p+fixed,name,false))return false;if(type==11&&(mode&0xf000)!=0xa000){if(!sxap_span(c,q,40)||!sxap_add(c,&sxap_bff_security_sizes,q))return false;q+=40;}if((mode&0xf000)==0x4000)z=0;else if((mode&0xf000)==0xa000&&sxap_uint(h+2,2,false)==0xea6b)z=plain;if(!sxap_span(c,q,z))return true;p=(q+z+7)&~UINT64_C(7);}return true;}
bool sx_aixbff_build(sx_context*c)
{
 return sxap_bff(c);
}
