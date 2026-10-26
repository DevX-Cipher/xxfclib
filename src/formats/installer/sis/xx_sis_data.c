/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Symbian / EPOC installation packages data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_sis_uids_fields[]={
 SX_FIELD("uid1","uint32le",0,4,SX_ID),
 SX_FIELD("uid2","uint32le",4,4,SX_ID),
 SX_FIELD("uid3","uint32le",8,4,SX_ID),
 SX_FIELD("uid_checksum","uint32le",12,4,SX_CHECKSUM),
};
const sx_layout sxiw_sis_uids={UINT32_C(0x60790022),"sis_uids",sxiw_sis_uids_fields,SX_COUNT(sxiw_sis_uids_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc_header_fields[]={
 SX_FIELD("uid1","uint32le",0,4,SX_ID),
 SX_FIELD("uid2","uint32le",4,4,SX_ID),
 SX_FIELD("uid3","uint32le",8,4,SX_ID),
 SX_FIELD("uid_checksum","uint32le",12,4,SX_CHECKSUM),
 SX_FIELD("file_crc16","uint16le",16,2,SX_CHECKSUM),
 SX_FIELD("language_count","uint16le",18,2,SX_COUNT_PROP),
 SX_FIELD("file_record_count","uint16le",20,2,SX_COUNT_PROP),
 SX_FIELD("requisite_count","uint16le",22,2,SX_COUNT_PROP),
 SX_FIELD("installation_language","uint16le",24,2,SX_ID),
 SX_FIELD("installation_files","uint16le",26,2,SX_COUNT_PROP),
 SX_FIELD("installation_drive","uint16le",28,2,SX_ID),
 SX_FIELD("capability_count","uint16le",30,2,SX_COUNT_PROP),
 SX_FIELD("installer_version","uint32le",32,4,SX_NONE),
 SX_FIELD("options","uint16le",36,2,SX_FLAGS),
 SX_FIELD("package_type","uint16le",38,2,SX_ID),
 SX_FIELD("version_major","uint16le",40,2,SX_NONE),
 SX_FIELD("version_minor","uint16le",42,2,SX_NONE),
 SX_FIELD("variant","uint32le",44,4,SX_NONE),
 SX_FIELD("languages_offset","uint32le",48,4,SX_OFFSET),
 SX_FIELD("file_records_offset","uint32le",52,4,SX_OFFSET),
 SX_FIELD("requisites_offset","uint32le",56,4,SX_OFFSET),
 SX_FIELD("certificates_offset","uint32le",60,4,SX_OFFSET),
 SX_FIELD("component_names_offset","uint32le",64,4,SX_OFFSET),
};
const sx_layout sxiw_sis_epoc_header={UINT32_C(0x60790023),"sis_epoc_header",sxiw_sis_epoc_header_fields,SX_COUNT(sxiw_sis_epoc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc6_extension_fields[]={
 SX_FIELD("signature_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("capabilities_offset","uint32le",4,4,SX_OFFSET),
};
const sx_layout sxiw_sis_epoc6_extension={UINT32_C(0x60790024),"sis_epoc6_extension",sxiw_sis_epoc6_extension_fields,SX_COUNT(sxiw_sis_epoc6_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_installed_space_fields[]={
 SX_FIELD("installed_space","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_installed_space={UINT32_C(0x60790025),"sis_installed_space",sxiw_sis_installed_space_fields,SX_COUNT(sxiw_sis_installed_space_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_maximum_installed_space_fields[]={
 SX_FIELD("maximum_installed_space","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_maximum_installed_space={UINT32_C(0x60790026),"sis_maximum_installed_space",sxiw_sis_maximum_installed_space_fields,SX_COUNT(sxiw_sis_maximum_installed_space_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc6_reserved_fields[]={
 SX_FIELD("reserved","uint8[16]",0,16,SX_RESERVED),
};
const sx_layout sxiw_sis_epoc6_reserved={UINT32_C(0x60790027),"sis_epoc6_reserved",sxiw_sis_epoc6_reserved_fields,SX_COUNT(sxiw_sis_epoc6_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_requisite_fields[]={
 SX_FIELD("uid","uint32le",0,4,SX_ID),
 SX_FIELD("version_major","uint16le",4,2,SX_NONE),
 SX_FIELD("version_minor","uint16le",6,2,SX_NONE),
 SX_FIELD("variant","uint32le",8,4,SX_NONE),
};
const sx_layout sxiw_sis_requisite={UINT32_C(0x60790028),"sis_requisite",sxiw_sis_requisite_fields,SX_COUNT(sxiw_sis_requisite_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_certificate_header_fields[]={
 SX_FIELD("year","uint16le",0,2,SX_NONE),
 SX_FIELD("month","uint16le",2,2,SX_NONE),
 SX_FIELD("day","uint16le",4,2,SX_NONE),
 SX_FIELD("hour","uint16le",6,2,SX_NONE),
 SX_FIELD("minute","uint16le",8,2,SX_NONE),
 SX_FIELD("second","uint16le",10,2,SX_NONE),
 SX_FIELD("certificate_count","uint32le",12,4,SX_COUNT_PROP),
};
const sx_layout sxiw_sis_certificate_header={UINT32_C(0x60790029),"sis_certificate_header",sxiw_sis_certificate_header_fields,SX_COUNT(sxiw_sis_certificate_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_language_fields[]={
 SX_FIELD("language_code","uint16le",0,2,SX_ID),
};
const sx_layout sxiw_sis_language={UINT32_C(0x6079002a),"sis_language",sxiw_sis_language_fields,SX_COUNT(sxiw_sis_language_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_file_record_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
 SX_FIELD("file_type","uint32le",4,4,SX_ID),
 SX_FIELD("details","uint32le",8,4,SX_FLAGS),
 SX_FIELD("source_name_length","uint32le",12,4,SX_SIZE),
 SX_FIELD("source_name_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("destination_name_length","uint32le",20,4,SX_SIZE),
 SX_FIELD("destination_name_offset","uint32le",24,4,SX_OFFSET),
};
const sx_layout sxiw_sis_file_record={UINT32_C(0x6079002b),"sis_file_record",sxiw_sis_file_record_fields,SX_COUNT(sxiw_sis_file_record_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_payload_length_fields[]={
 SX_FIELD("payload_length","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_payload_length={UINT32_C(0x6079002c),"sis_payload_length",sxiw_sis_payload_length_fields,SX_COUNT(sxiw_sis_payload_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_payload_offset_fields[]={
 SX_FIELD("payload_offset","uint32le",0,4,SX_OFFSET),
};
const sx_layout sxiw_sis_payload_offset={UINT32_C(0x6079002d),"sis_payload_offset",sxiw_sis_payload_offset_fields,SX_COUNT(sxiw_sis_payload_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_uncompressed_length_fields[]={
 SX_FIELD("uncompressed_length","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_uncompressed_length={UINT32_C(0x6079002e),"sis_uncompressed_length",sxiw_sis_uncompressed_length_fields,SX_COUNT(sxiw_sis_uncompressed_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_mime_length_fields[]={
 SX_FIELD("mime_length","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_mime_length={UINT32_C(0x6079002f),"sis_mime_length",sxiw_sis_mime_length_fields,SX_COUNT(sxiw_sis_mime_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_mime_offset_fields[]={
 SX_FIELD("mime_offset","uint32le",0,4,SX_OFFSET),
};
const sx_layout sxiw_sis_mime_offset={UINT32_C(0x60790030),"sis_mime_offset",sxiw_sis_mime_offset_fields,SX_COUNT(sxiw_sis_mime_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_conditional_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
 SX_FIELD("expression_length","uint32le",4,4,SX_SIZE),
};
const sx_layout sxiw_sis_conditional={UINT32_C(0x60790031),"sis_conditional",sxiw_sis_conditional_fields,SX_COUNT(sxiw_sis_conditional_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_control_type_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
};
const sx_layout sxiw_sis_control_type={UINT32_C(0x60790032),"sis_control_type",sxiw_sis_control_type_fields,SX_COUNT(sxiw_sis_control_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_field_fields[]={
 SX_FIELD("type","uint32le",0,4,SX_ID),
 SX_FIELD("length","uint32le",4,4,SX_SIZE),
};
const sx_layout sxiw_sisx_field={UINT32_C(0x60790033),"sisx_field",sxiw_sisx_field_fields,SX_COUNT(sxiw_sisx_field_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_long_field_fields[]={
 SX_FIELD("type","uint32le",0,4,SX_ID),
 SX_FIELD("length_low_with_flag","uint32le",4,4,SX_FLAGS),
 SX_FIELD("length_high","uint32le",8,4,SX_NONE),
};
const sx_layout sxiw_sisx_long_field={UINT32_C(0x60790034),"sisx_long_field",sxiw_sisx_long_field_fields,SX_COUNT(sxiw_sisx_long_field_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_element_fields[]={
 SX_FIELD("element_type","uint32le",0,4,SX_ID),
};
const sx_layout sxiw_sisx_array_element={UINT32_C(0x60790035),"sisx_array_element",sxiw_sisx_array_element_fields,SX_COUNT(sxiw_sisx_array_element_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_length_fields[]={
 SX_FIELD("length","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sisx_array_length={UINT32_C(0x60790036),"sisx_array_length",sxiw_sisx_array_length_fields,SX_COUNT(sxiw_sisx_array_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_long_length_fields[]={
 SX_FIELD("length_low_with_flag","uint32le",0,4,SX_FLAGS),
 SX_FIELD("length_high","uint32le",4,4,SX_NONE),
};
const sx_layout sxiw_sisx_array_long_length={UINT32_C(0x60790037),"sisx_array_long_length",sxiw_sisx_array_long_length_fields,SX_COUNT(sxiw_sisx_array_long_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_compressed_fields[]={
 SX_FIELD("algorithm","uint32le",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint64le",4,8,SX_SIZE),
};
const sx_layout sxiw_sisx_compressed={UINT32_C(0x60790038),"sisx_compressed",sxiw_sisx_compressed_fields,SX_COUNT(sxiw_sisx_compressed_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_latin1_fields[]={
 SX_FIELD("sis_latin1","uint8",0,0,SX_NONE),
};
const sx_layout sxiw_sis_latin1={UINT32_C(0x6079004f),"sis_latin1",sxiw_sis_latin1_fields,SX_COUNT(sxiw_sis_latin1_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_utf16_fields[]={
 SX_FIELD("sis_utf16","uint16",0,0,SX_NONE),
};
const sx_layout sxiw_sis_utf16={UINT32_C(0x60790050),"sis_utf16",sxiw_sis_utf16_fields,SX_COUNT(sxiw_sis_utf16_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_capability_fields[]={
 SX_FIELD("capability_key","uint32le",0,4,SX_ID),
 SX_FIELD("capability_value","uint32le",4,4,SX_NONE),
};
const sx_layout sxiw_sis_capability={UINT32_C(0x60790051),"sis_capability",sxiw_sis_capability_fields,SX_COUNT(sxiw_sis_capability_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_checksum_fields[]={
 SX_FIELD("crc16","uint16le",0,2,SX_CHECKSUM),
};
const sx_layout sxiw_sisx_checksum={UINT32_C(0x60790052),"sisx_checksum",sxiw_sisx_checksum_fields,SX_COUNT(sxiw_sisx_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_data_index_fields[]={
 SX_FIELD("data_index","uint32le",0,4,SX_NONE),
};
const sx_layout sxiw_sisx_data_index={UINT32_C(0x60790053),"sisx_data_index",sxiw_sisx_data_index_fields,SX_COUNT(sxiw_sisx_data_index_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_localized_name_length_fields[]={
 SX_FIELD("name_length","uint32le",0,4,SX_SIZE),
};
const sx_layout sxiw_sis_localized_name_length={UINT32_C(0x6079006e),"sis_localized_name_length",sxiw_sis_localized_name_length_fields,SX_COUNT(sxiw_sis_localized_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_localized_name_offset_fields[]={
 SX_FIELD("name_offset","uint32le",0,4,SX_OFFSET),
};
const sx_layout sxiw_sis_localized_name_offset={UINT32_C(0x6079006f),"sis_localized_name_offset",sxiw_sis_localized_name_offset_fields,SX_COUNT(sxiw_sis_localized_name_offset_fields),SX_LE};
#define SXIW_LIMIT 20000U
static bool sxiw_sisx(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint32_t implicit){
 if(depth>32||p>end||end>(uint64_t)c->size)return false;
 for(unsigned count=0;p<end&&count<SXIW_LIMIT&&c->count<SXIW_LIMIT;count++){
 uint64_t type=implicit,low,high=0,z,q,stop;const sx_layout*l;
 q=p;if(!implicit){if(end-q<4||!sxiw_word(c,q,4,false,&type))return true;q+=4;}
 if(end-q<4||!sxiw_word(c,q,4,false,&low))return true;q+=4;
 if(low&0x80000000U){if(end-q<4||!sxiw_word(c,q,4,false,&high)||high>=0x80000000U)return true;q+=4;}
 z=(low&0x7fffffffU)|(high<<31);if(z>end-q)return true;stop=q+z;
 l=implicit?(low&0x80000000U?&sxiw_sisx_array_long_length:&sxiw_sisx_array_length):(low&0x80000000U?&sxiw_sisx_long_field:&sxiw_sisx_field);
 if(!sxiw_add(c,l,p))return false;
 if(type==2&&z>=4){uint64_t element;if(!sxiw_word(c,q,4,false,&element)||!sxiw_add(c,&sxiw_sisx_array_element,q))return false;if(element&&element<=42&&!sxiw_sisx(c,q+4,stop,depth+1,(uint32_t)element))return false;}
 else if(type==3&&z>=12){uint64_t algo,uz;if(!sxiw_word(c,q,4,false,&algo)||!sxiw_word(c,q+4,8,false,&uz)||!sxiw_add(c,&sxiw_sisx_compressed,q))return false;if(!algo&&uz==z-12&&!sxiw_sisx(c,q+12,stop,depth+1,0))return false;}
 else if(type==1&&!(z&1)){if(!sxiw_text(c,&sxiw_sis_utf16,q,z,false))return false;}
 else if((type==34||type==35)&&z>=2){if(!sxiw_add(c,&sxiw_sisx_checksum,q))return false;}
 else if(type==40&&z>=4){if(!sxiw_add(c,&sxiw_sisx_data_index,q))return false;}
 else if(type==12||type==13||type==28||type==30||type==31||type==32){if(!sxiw_sisx(c,q,stop,depth+1,0))return false;}
 p=stop;uint64_t pad=(4-(z&3))&3;if(pad>end-p)p=end;else p+=pad;
 }return true;
}
static bool sxiw_sis(sx_context*c){uint8_t h[68];uint64_t uid;if(!sxiw_word(c,0,4,false,&uid))return false;if(uid==0x10201a7aU)return sxiw_add(c,&sxiw_sis_uids,0)&&sxiw_sisx(c,16,(uint64_t)c->size,0,0);
 if(!sxiw_read(c,0,h,68)||!sxiw_add(c,&sxiw_sis_epoc_header,0))return false;
 bool r6=sxiw_uint(h+4,4,false)==0x10003a12U,unicode=(h[36]&1)!=0;uint64_t langs=sxiw_uint(h+18,2,false),files=sxiw_uint(h+20,2,false),lp=sxiw_uint(h+48,4,false),fp=sxiw_uint(h+52,4,false),limit=(uint64_t)c->size;const sx_layout*str=unicode?&sxiw_sis_utf16:&sxiw_sis_latin1;
 for(unsigned k=48;k<=64;k+=4){uint64_t a=sxiw_uint(h+k,4,false);if(a>=68&&a<limit)limit=a;}
 if(r6){if(limit>=76&&!sxiw_add(c,&sxiw_sis_epoc6_extension,68))return false;if(limit>=80&&!sxiw_add(c,&sxiw_sis_installed_space,76))return false;if(limit>=84&&!sxiw_add(c,&sxiw_sis_maximum_installed_space,80))return false;if(limit>=100&&!sxiw_add(c,&sxiw_sis_epoc6_reserved,84))return false;}
 if(langs<=256&&lp>=68&&sxiw_span(c,lp,langs*2)&&!sxiw_table(c,&sxiw_sis_language,lp,2,langs))return false;
 uint64_t p=fp;for(uint64_t i=0;i<files&&c->count<SXIW_LIMIT;i++){uint64_t typ;if(!sxiw_word(c,p,4,false,&typ))break;if(typ==3||typ==4){uint64_t n;if(!sxiw_word(c,p+4,4,false,&n)||!sxiw_span(c,p,8+n)||!sxiw_add(c,&sxiw_sis_conditional,p))break;p+=8+n;continue;}if(typ==5||typ==6){if(!sxiw_add(c,&sxiw_sis_control_type,p))break;p+=4;continue;}if(typ>1)break;
 uint64_t forks=typ?langs:1,z=28+(r6?12*forks+8:8*forks);uint8_t r[28];if(forks>256||!sxiw_span(c,p,z)||!sxiw_read(c,p,r,28)||!sxiw_add(c,&sxiw_sis_file_record,p))break;
 for(unsigned j=12;j<=20;j+=8){uint64_t n=sxiw_uint(r+j,4,false),off=sxiw_uint(r+j+4,4,false);if(sxiw_span(c,off,n)&&(!unicode||!(n&1))&&!sxiw_text(c,str,off,n,false))return false;}
 uint64_t q=p+28;if(!sxiw_table(c,&sxiw_sis_payload_length,q,4,forks)||!sxiw_table(c,&sxiw_sis_payload_offset,q+4*forks,4,forks))return false;q+=8*forks;
 if(r6){if(!sxiw_table(c,&sxiw_sis_uncompressed_length,q,4,forks))return false;q+=4*forks;if(!sxiw_add(c,&sxiw_sis_mime_length,q)||!sxiw_add(c,&sxiw_sis_mime_offset,q+4))return false;}
 p+=z;}
 /* Requisites and component names store parallel arrays of localized lengths and pointers. */
 p=sxiw_uint(h+56,4,false);uint64_t req=sxiw_uint(h+22,2,false),width=12+8*langs;if(p>=68&&langs<=256&&width&&sxiw_span(c,p,req*width))for(uint64_t i=0;i<req&&c->count<SXIW_LIMIT;i++,p+=width){if(!sxiw_add(c,&sxiw_sis_requisite,p)||!sxiw_table(c,&sxiw_sis_localized_name_length,p+12,4,langs)||!sxiw_table(c,&sxiw_sis_localized_name_offset,p+12+4*langs,4,langs))return false;}
 p=sxiw_uint(h+64,4,false);if(p>=68&&langs<=256&&sxiw_span(c,p,8*langs)){if(!sxiw_table(c,&sxiw_sis_localized_name_length,p,4,langs)||!sxiw_table(c,&sxiw_sis_localized_name_offset,p+4*langs,4,langs))return false;}
 p=sxiw_uint(h+60,4,false);if(p>=68&&sxiw_span(c,p,16)&&!sxiw_add(c,&sxiw_sis_certificate_header,p))return false;
 if(r6&&limit>=76){uint64_t cp,n=sxiw_uint(h+30,2,false);if(sxiw_word(c,72,4,false,&cp)&&cp>=68&&sxiw_span(c,cp,n*8)&&!sxiw_table(c,&sxiw_sis_capability,cp,8,n))return false;}
 return true;
}
bool sx_sis_build(sx_context*c)
{
 return sxiw_sis(c);
}
