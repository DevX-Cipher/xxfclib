/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CDI FS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_cdi_volume_descriptor_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("standard_id","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",6,1,SX_ID),
    SX_FIELD("flags","uint8",7,1,SX_FLAGS),
    SX_FIELD("system_id","char[32]",8,32,SX_STRING),
    SX_FIELD("volume_id","char[32]",40,32,SX_STRING),
    SX_FIELD("reserved0","byte[12]",72,12,SX_RESERVED),
    SX_FIELD("volume_blocks","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("character_set","char[32]",88,32,SX_STRING),
    SX_FIELD("reserved1","uint16",120,2,SX_RESERVED),
    SX_FIELD("album_volume_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint16",124,2,SX_RESERVED),
    SX_FIELD("album_sequence","uint16",126,2,SX_NONE),
    SX_FIELD("reserved3","uint16",128,2,SX_RESERVED),
    SX_FIELD("logical_block_size","uint16",130,2,SX_SIZE),
    SX_FIELD("reserved4","uint32",132,4,SX_RESERVED),
    SX_FIELD("path_table_size","uint32",136,4,SX_SIZE),
    SX_FIELD("reserved5","byte[8]",140,8,SX_RESERVED),
    SX_FIELD("path_table_block","uint32",148,4,SX_NONE),
    SX_FIELD("reserved6","byte[38]",152,38,SX_RESERVED),
    SX_FIELD("album_id","char[128]",190,128,SX_STRING),
    SX_FIELD("publisher","char[128]",318,128,SX_STRING),
    SX_FIELD("data_preparer","char[128]",446,128,SX_STRING),
    SX_FIELD("application_id","char[128]",574,128,SX_STRING),
    SX_FIELD("copyright_file","char[32]",702,32,SX_STRING),
    SX_FIELD("reserved7","byte[5]",734,5,SX_RESERVED),
    SX_FIELD("abstract_file","char[32]",739,32,SX_STRING),
    SX_FIELD("reserved8","byte[5]",771,5,SX_RESERVED),
    SX_FIELD("bibliography_file","char[32]",776,32,SX_STRING),
    SX_FIELD("reserved9","byte[5]",808,5,SX_RESERVED),
    SX_FIELD("creation_date","char[16]",813,16,SX_NONE),
    SX_FIELD("reserved10","uint8",829,1,SX_RESERVED),
    SX_FIELD("modification_date","char[16]",830,16,SX_NONE),
    SX_FIELD("reserved11","uint8",846,1,SX_RESERVED),
    SX_FIELD("expiration_date","char[16]",847,16,SX_NONE),
    SX_FIELD("reserved12","uint8",863,1,SX_RESERVED),
    SX_FIELD("effective_date","char[16]",864,16,SX_NONE),
    SX_FIELD("reserved13","uint8",880,1,SX_RESERVED),
    SX_FIELD("structure_version","uint8",881,1,SX_ID),
    SX_FIELD("reserved14","uint8",882,1,SX_RESERVED),
    SX_FIELD("application_use","byte[512]",883,512,SX_NONE),
    SX_FIELD("reserved15","byte[653]",1395,653,SX_RESERVED),
};
const sx_layout sxmf_cdi_volume_descriptor = {0x60420082U,"cdi_volume_descriptor",sxmf_cdi_volume_descriptor_fields,SX_COUNT(sxmf_cdi_volume_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_cdi_terminator_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("standard_id","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",6,1,SX_ID),
    SX_FIELD("reserved","byte[2041]",7,2041,SX_RESERVED),
};
const sx_layout sxmf_cdi_terminator = {0x60420083U,"cdi_terminator",sxmf_cdi_terminator_fields,SX_COUNT(sxmf_cdi_terminator_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_cdi_path_entry_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("directory_block","uint32",2,4,SX_NONE),
    SX_FIELD("parent_directory_number","uint16",6,2,SX_NONE),
};
const sx_layout sxmf_cdi_path_entry = {0x60420084U,"cdi_path_entry",sxmf_cdi_path_entry_fields,SX_COUNT(sxmf_cdi_path_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_cdi_directory_entry_fields[] = {
    SX_FIELD("record_length","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint32",2,4,SX_RESERVED),
    SX_FIELD("file_block","uint32",6,4,SX_NONE),
    SX_FIELD("reserved1","uint32",10,4,SX_RESERVED),
    SX_FIELD("file_size","uint32",14,4,SX_SIZE),
    SX_FIELD("year_since_1900","uint8",18,1,SX_NONE),
    SX_FIELD("month","uint8",19,1,SX_NONE),
    SX_FIELD("day","uint8",20,1,SX_NONE),
    SX_FIELD("hour","uint8",21,1,SX_NONE),
    SX_FIELD("minute","uint8",22,1,SX_NONE),
    SX_FIELD("second","uint8",23,1,SX_NONE),
    SX_FIELD("reserved2","uint8",24,1,SX_RESERVED),
    SX_FIELD("flags","uint8",25,1,SX_FLAGS),
    SX_FIELD("interleave_unit_sectors","uint8",26,1,SX_COUNT_PROP),
    SX_FIELD("interleave_gap_sectors","uint8",27,1,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint16",28,2,SX_RESERVED),
    SX_FIELD("album_sequence","uint16",30,2,SX_NONE),
    SX_FIELD("name_length","uint8",32,1,SX_SIZE),
};
const sx_layout sxmf_cdi_directory_entry = {0x60420085U,"cdi_directory_entry",sxmf_cdi_directory_entry_fields,SX_COUNT(sxmf_cdi_directory_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_cdi_directory_attributes_fields[] = {
    SX_FIELD("group_id","uint16",0,2,SX_ID),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved0","uint16",6,2,SX_RESERVED),
    SX_FIELD("file_number","uint8",8,1,SX_ID),
    SX_FIELD("reserved1","uint8",9,1,SX_RESERVED),
};
const sx_layout sxmf_cdi_directory_attributes = {0x60420086U,"cdi_directory_attributes",sxmf_cdi_directory_attributes_fields,SX_COUNT(sxmf_cdi_directory_attributes_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_cdi_mode2_sector_header_fields[] = {
    SX_FIELD("sync","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("minute_bcd","uint8",12,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",13,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",14,1,SX_NONE),
    SX_FIELD("mode","uint8",15,1,SX_ID),
    SX_FIELD("file_number","uint8",16,1,SX_ID),
    SX_FIELD("channel_number","uint8",17,1,SX_ID),
    SX_FIELD("submode","uint8",18,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",19,1,SX_FLAGS),
    SX_FIELD("repeated_file_number","uint8",20,1,SX_ID),
    SX_FIELD("repeated_channel_number","uint8",21,1,SX_ID),
    SX_FIELD("repeated_submode","uint8",22,1,SX_FLAGS),
    SX_FIELD("repeated_coding_information","uint8",23,1,SX_FLAGS),
};
const sx_layout sxmf_cdi_mode2_sector_header = {0x60420087U,"cdi_mode2_sector_header",sxmf_cdi_mode2_sector_header_fields,SX_COUNT(sxmf_cdi_mode2_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_cdi_form1_edc_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxmf_cdi_form1_edc = {0x60420088U,"cdi_form1_edc",sxmf_cdi_form1_edc_fields,SX_COUNT(sxmf_cdi_form1_edc_fields),SX_LE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
static bool sxmf_ci_read(sx_context*c,uint64_t logical,void*out,size_t n,unsigned stride){uint8_t*p=out;while(n){uint64_t block=logical/2048,within=logical%2048,part=2048-within;if(part>n)part=n;if(block>UINT64_MAX/stride||!sxmf_read(c,block*stride+(stride==2352?24:0)+within,p,(size_t)part))return false;p+=part;n-=(size_t)part;logical+=part;}return true;}
static bool sxmf_ci_frame(sx_context*c,uint64_t block,unsigned stride){if(stride!=2352)return true;uint8_t h[24];uint64_t p=block*2352;if(!sxmf_read(c,p,h,24)||h[15]!=2||xx_rt_memcmp(h+16,h+20,4)||(h[18]&0x20))return true;return SXMF_ADD(c,cdi_mode2_sector_header,p)&&SXMF_ADD(c,cdi_form1_edc,p+2072);}
static bool sxmf_ci_row(sx_context*c,const sx_layout*l,uint64_t logical,unsigned stride){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=(uint64_t)(f->rel_offset+f->size),block=logical/2048,within=logical%2048;if(stride==2352&&n>2048-within)return true;if(!sxmf_ci_frame(c,block,stride))return false;return sxmf_put(c,l,block*stride+(stride==2352?24:0)+within,1);}
static bool sxmf_cdi(sx_context*c){uint8_t h[2048],b[2048];unsigned stride=2048;if(!sxmf_ci_read(c,16*2048,h,2048,stride)||h[0]!=1||xx_rt_memcmp(h+1,"CD-I ",5)){stride=2352;if(!sxmf_ci_read(c,16*2048,h,2048,stride)||h[0]!=1||xx_rt_memcmp(h+1,"CD-I ",5))return false;}if(!sxmf_ci_row(c,&sxmf_cdi_volume_descriptor,16*2048,stride))return false;uint64_t blocks=sxmf32(h+84,1),path=sxmf32(h+148,1),bytes=sxmf32(h+136,1);if(blocks>(uint64_t)c->size/stride||path>=blocks||bytes>1048576||bytes>(blocks-path)*2048)return true;
 for(uint64_t i=17;i<blocks&&i<80;i++){if(!sxmf_ci_read(c,i*2048,b,2048,stride)||xx_rt_memcmp(b+1,"CD-I ",5)||b[6]!=1)break;if(b[0]==255){if(!sxmf_ci_row(c,&sxmf_cdi_terminator,i*2048,stride))return false;break;}if(b[0]==1&&!sxmf_ci_row(c,&sxmf_cdi_volume_descriptor,i*2048,stride))return false;}
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;bool ok=true;for(uint64_t p=0;p+8<=bytes&&c->count<SXMF_LIMIT;){uint8_t d[8];if(!sxmf_ci_read(c,path*2048+p,d,8,stride)||!d[0])break;uint64_t z=8+d[0]+(d[0]&1),dir=sxmf32(d+2,1);if(z>bytes-p)break;if(!sxmf_ci_row(c,&sxmf_cdi_path_entry,path*2048+p,stride)){ok=false;break;}if(dir<blocks)sxmf_queue_add(q,dir,0,0);p+=z;}
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){uint64_t block=q->items[q->index++].p;if(!sxmf_ci_read(c,block*2048,b,2048,stride)||b[0]<33)continue;uint64_t size=sxmf32(b+14,1);if(size>UINT64_C(16777216)||(size+2047)/2048>blocks-block)continue;for(uint64_t pos=0;pos<size&&c->count<SXMF_LIMIT&&ok;pos+=2048){uint64_t limit=size-pos;if(limit>2048)limit=2048;if(!sxmf_ci_read(c,block*2048+pos,b,(size_t)limit,stride))break;for(uint64_t at=0;at+33<=limit;){uint64_t z=b[at],n=b[at+32],tail=33+n+((n&1)==0);if(!z)break;if(z>limit-at||z<33||tail>z||10>z-tail)break;if(!sxmf_ci_row(c,&sxmf_cdi_directory_entry,block*2048+pos+at,stride)||!sxmf_ci_row(c,&sxmf_cdi_directory_attributes,block*2048+pos+at+tail,stride)){ok=false;break;}at+=z;}}}
 xx_rt_free(q);return ok;
}
bool sx_cdi_fs_build(sx_context*c)
{
 return sxmf_cdi(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
