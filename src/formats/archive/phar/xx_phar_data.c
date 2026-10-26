/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Phar data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_phar_manifest_prefix_fields[] = {
 SX_FIELD("manifest_size","uint32",0,4,SX_SIZE),
 SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxaf_phar_manifest_prefix = {UINT32_C(0x603c0002),"phar_manifest_prefix",sxaf_phar_manifest_prefix_fields,SX_COUNT(sxaf_phar_manifest_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_api_version_fields[] = {
 SX_FIELD("api_version","uint16",0,2,SX_NONE),
};
const sx_layout sxaf_phar_api_version = {UINT32_C(0x603c0003),"phar_api_version",sxaf_phar_api_version_fields,SX_COUNT(sxaf_phar_api_version_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_phar_manifest_flags_fields[] = {
 SX_FIELD("global_flags","uint32",0,4,SX_NONE),
 SX_FIELD("alias_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxaf_phar_manifest_flags = {UINT32_C(0x603c0004),"phar_manifest_flags",sxaf_phar_manifest_flags_fields,SX_COUNT(sxaf_phar_manifest_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_metadata_length_fields[] = {
 SX_FIELD("metadata_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxaf_phar_metadata_length = {UINT32_C(0x603c0005),"phar_metadata_length",sxaf_phar_metadata_length_fields,SX_COUNT(sxaf_phar_metadata_length_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_name_length_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxaf_phar_name_length = {UINT32_C(0x603c0006),"phar_name_length",sxaf_phar_name_length_fields,SX_COUNT(sxaf_phar_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_file_entry_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unix_timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",16,4,SX_NONE),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
};
const sx_layout sxaf_phar_file_entry = {UINT32_C(0x603c0007),"phar_file_entry",sxaf_phar_file_entry_fields,SX_COUNT(sxaf_phar_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_signature_footer_fields[] = {
 SX_FIELD("signature_type","uint32",0,4,SX_NONE),
 SX_FIELD("magic","char[4]",4,4,SX_SIGNATURE),
};
const sx_layout sxaf_phar_signature_footer = {UINT32_C(0x603c0008),"phar_signature_footer",sxaf_phar_signature_footer_fields,SX_COUNT(sxaf_phar_signature_footer_fields),SX_LE};
static bool sxaf_phar(sx_context*c){uint64_t p=0,limit=(uint64_t)c->size<8388608?(uint64_t)c->size:8388608;uint8_t b[4113];bool found=false;
 for(uint64_t block=0;block<limit&&!found;block+=4096){size_t nr=(size_t)(limit-block);if(nr>sizeof(b))nr=sizeof(b);if(!sxaf_read(c,block,b,nr))return false;for(size_t i=0;i+18<=nr&&i<4096;i++){if(!xx_rt_memcmp(b+i,"__HALT_COMPILER();",18)){p=block+i+18;found=true;break;}}}if(!found)return false;uint8_t tail[8];size_t n=(uint64_t)c->size-p<8?(size_t)((uint64_t)c->size-p):8;if(!sxaf_read(c,p,tail,n))return false;size_t skip=0;while(skip<n&&(tail[skip]==' '||tail[skip]=='\t'))skip++;if(skip+2<=n&&tail[skip]=='?'&&tail[skip+1]=='>')skip+=2;if(skip+2<=n&&tail[skip]=='\r'&&tail[skip+1]=='\n')skip+=2;else if(skip<n&&tail[skip]=='\n')skip++;p+=skip;
 uint64_t size,count,alias,meta,flags;if(!sxaf_word(c,p,4,false,&size)||!sxaf_span(c,p+4,size)||!sxaf_word(c,p+4,4,false,&count)||!sxaf_word(c,p+14,4,false,&alias)||!sxaf_word(c,p+10,4,false,&flags)||!sxaf_add(c,&sxaf_phar_manifest_prefix,p)||!sxaf_add(c,&sxaf_phar_api_version,p+8)||!sxaf_add(c,&sxaf_phar_manifest_flags,p+10))return false;uint64_t end=p+4+size,q=p+18,data=end;if(q>end||alias>end-q)return false;q+=alias;if(end-q<4||!sxaf_word(c,q,4,false,&meta)||!sxaf_add(c,&sxaf_phar_metadata_length,q))return false;q+=4;if(meta>end-q)return false;q+=meta;
 for(uint64_t i=0;i<count;i++){uint64_t name,packed;if(end-q<4||!sxaf_word(c,q,4,false,&name)||!sxaf_add(c,&sxaf_phar_name_length,q))return false;q+=4;if(name>end-q)return false;q+=name;if(end-q<24||!sxaf_word(c,q+20,4,false,&meta)||!sxaf_word(c,q+8,4,false,&packed)||!sxaf_add(c,&sxaf_phar_file_entry,q))return false;q+=24;if(!sxaf_span(c,data,packed))return false;data+=packed;if(meta>end-q)return false;q+=meta;}
 if((flags&0x10000)&&c->size>=8&&data<=(uint64_t)c->size-8&&sxaf_read(c,(uint64_t)c->size-4,b,4)&&!xx_rt_memcmp(b,"GBMB",4)){uint64_t kind;if(!sxaf_word(c,(uint64_t)c->size-8,4,false,&kind))return false;uint64_t signature_size=kind==1?16:kind==2?20:kind==3?32:kind==4?64:0;if(signature_size&&(uint64_t)c->size-8-data==signature_size)return sxaf_add(c,&sxaf_phar_signature_footer,(uint64_t)c->size-8);}return true;}
bool sx_phar_build(sx_context*c)
{
 return sxaf_phar(c);
}
