/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMSSaveset data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_vms_backup_block_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("operating_system","uint16",2,2,SX_NONE),
 SX_FIELD("subsystem","uint16",4,2,SX_NONE),
 SX_FIELD("application","uint16",6,2,SX_NONE),
 SX_FIELD("block_number","uint32",8,4,SX_NONE),
 SX_FIELD("spare1","uint8[20]",12,20,SX_NONE),
 SX_FIELD("structure_level","uint16",32,2,SX_NONE),
 SX_FIELD("volume_number","uint16",34,2,SX_NONE),
 SX_FIELD("crc32","uint32",36,4,SX_CHECKSUM),
 SX_FIELD("block_size","int32",40,4,SX_SIZE),
 SX_FIELD("flags","uint32",44,4,SX_FLAGS),
 SX_FIELD("saveset_name","char[32]",48,32,SX_NONE),
 SX_FIELD("file_id","uint16[3]",80,6,SX_NONE),
 SX_FIELD("directory_id","uint16[3]",86,6,SX_NONE),
 SX_FIELD("filename","char[128]",92,128,SX_NONE),
 SX_FIELD("record_format","uint8",220,1,SX_NONE),
 SX_FIELD("record_attributes","uint8",221,1,SX_FLAGS),
 SX_FIELD("record_size","uint16",222,2,SX_SIZE),
 SX_FIELD("bucket_size","uint8",224,1,SX_NONE),
 SX_FIELD("fixed_control_size","uint8",225,1,SX_SIZE),
 SX_FIELD("maximum_record","uint16",226,2,SX_SIZE),
 SX_FIELD("file_size","uint32",228,4,SX_NONE),
 SX_FIELD("spare2","uint8[22]",232,22,SX_NONE),
 SX_FIELD("checksum","uint16",254,2,SX_CHECKSUM),
};
const sx_layout sxap_vms_backup_block = {UINT32_C(0x6072003b),"vms_backup_block",sxap_vms_backup_block_fields,SX_COUNT(sxap_vms_backup_block_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_record_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
 SX_FIELD("record_type","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("spare","uint32",12,4,SX_NONE),
};
const sx_layout sxap_vms_backup_record = {UINT32_C(0x6072003c),"vms_backup_record",sxap_vms_backup_record_fields,SX_COUNT(sxap_vms_backup_record_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_file_version_fields[] = {
 SX_FIELD("structure_level","uint16",0,2,SX_NONE),
};
const sx_layout sxap_vms_backup_file_version = {UINT32_C(0x6072003d),"vms_backup_file_version",sxap_vms_backup_file_version_fields,SX_COUNT(sxap_vms_backup_file_version_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_attribute_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
};
const sx_layout sxap_vms_backup_attribute = {UINT32_C(0x6072003e),"vms_backup_attribute",sxap_vms_backup_attribute_fields,SX_COUNT(sxap_vms_backup_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_fid_fields[] = {
 SX_FIELD("number","uint16",0,2,SX_NONE),
 SX_FIELD("sequence","uint16",2,2,SX_NONE),
 SX_FIELD("relative_volume_and_extension","uint16",4,2,SX_NONE),
};
const sx_layout sxap_vms_backup_fid = {UINT32_C(0x6072003f),"vms_backup_fid",sxap_vms_backup_fid_fields,SX_COUNT(sxap_vms_backup_fid_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_characteristics_fields[] = {
 SX_FIELD("characteristics","uint32",0,4,SX_FLAGS),
};
const sx_layout sxap_vms_backup_characteristics = {UINT32_C(0x60720040),"vms_backup_characteristics",sxap_vms_backup_characteristics_fields,SX_COUNT(sxap_vms_backup_characteristics_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_date_fields[] = {
 SX_FIELD("vms_time","uint64",0,8,SX_NONE),
};
const sx_layout sxap_vms_backup_date = {UINT32_C(0x60720041),"vms_backup_date",sxap_vms_backup_date_fields,SX_COUNT(sxap_vms_backup_date_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_fat_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_NONE),
 SX_FIELD("record_attributes","uint8",1,1,SX_FLAGS),
 SX_FIELD("record_size","uint16",2,2,SX_SIZE),
 SX_FIELD("high_block","uint32_pdp",4,4,SX_NONE),
 SX_FIELD("eof_block","uint32_pdp",8,4,SX_NONE),
 SX_FIELD("first_free_byte","uint16",12,2,SX_NONE),
 SX_FIELD("bucket_size","uint8",14,1,SX_NONE),
 SX_FIELD("fixed_control_size","uint8",15,1,SX_SIZE),
 SX_FIELD("maximum_record","uint16",16,2,SX_SIZE),
 SX_FIELD("default_extend","uint16",18,2,SX_NONE),
 SX_FIELD("global_buffers","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[8]",22,8,SX_NONE),
 SX_FIELD("version_limit","uint16",30,2,SX_NONE),
};
const sx_layout sxap_vms_backup_fat = {UINT32_C(0x60720042),"vms_backup_fat",sxap_vms_backup_fat_fields,SX_COUNT(sxap_vms_backup_fat_fields),SX_LE};
static bool sxap_saveset(sx_context*c){uint64_t p=0,first=0;while(sxap_span(c,p,256)){uint64_t z,app;if(!sxap_word(c,p+40,4,false,&z)||!sxap_word(c,p+6,2,false,&app)||!sxap_add(c,&sxap_vms_backup_block,p))return false;if(!first)first=z;if(app==2&&!z)z=first;if(z<=256||z>INT32_MAX)return true;uint64_t end=p+z,q=p+256;if(!sxap_span(c,p,z))end=(uint64_t)c->size;if(app!=2)while(q<=end&&end-q>=16){uint64_t len,type;if(!sxap_word(c,q,2,false,&len)||!sxap_word(c,q+2,2,false,&type)||!sxap_add(c,&sxap_vms_backup_record,q))return false;q+=16;if(len>end-q)return true;if(type==3&&len>=2){if(!sxap_add(c,&sxap_vms_backup_file_version,q))return false;uint64_t a=q+2,stop=q+len;while(a<=stop&&stop-a>=4){uint64_t n,tag;if(!sxap_word(c,a,2,false,&n)||!sxap_word(c,a+2,2,false,&tag)||!sxap_add(c,&sxap_vms_backup_attribute,a))return false;a+=4;if(n>stop-a)return true;if(tag==0x2a){if(!sxap_text(c,&sxap_archivepackages_name,a,n,false))return false;}else if(tag==0x2c&&n==6){if(!sxap_add(c,&sxap_vms_backup_fid,a))return false;}else if(tag==0x33&&n==4){if(!sxap_add(c,&sxap_vms_backup_characteristics,a))return false;}else if(tag==0x34&&n==32){if(!sxap_add(c,&sxap_vms_backup_fat,a))return false;}else if((tag==0x36||tag==0x37)&&n==8){if(!sxap_add(c,&sxap_vms_backup_date,a))return false;}a+=n;}}q+=len;}p+=z;}return true;}
bool sx_vmssaveset_build(sx_context*c)
{
 return sxap_saveset(c);
}
