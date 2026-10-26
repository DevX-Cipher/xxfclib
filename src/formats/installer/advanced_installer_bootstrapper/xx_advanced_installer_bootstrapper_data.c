/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Advanced Installer bootstrapper data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_installerlast_utf16_name_fields[] = {
    SX_FIELD("name","uint16",0,0,SX_NONE),
};
const sx_layout sxil_installerlast_utf16_name = {0x60850002U,"installerlast_utf16_name",sxil_installerlast_utf16_name_fields,SX_COUNT(sxil_installerlast_utf16_name_fields),SX_LE};
static const xx_data_struct_field_desc sxil_advanced_installer_footer_fields[] = {
    SX_FIELD("mode","uint32",0,4,SX_ID),
    SX_FIELD("external_name_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",12,4,SX_ID),
    SX_FIELD("metadata_end","uint32",16,4,SX_OFFSET),
    SX_FIELD("info_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("guid_hex","char[32]",28,32,SX_NONE),
    SX_FIELD("unknown","uint32",60,4,SX_NONE),
    SX_FIELD("marker","char[10]",64,10,SX_SIGNATURE),
};
const sx_layout sxil_advanced_installer_footer = {0x60850006U,"advanced_installer_footer",sxil_advanced_installer_footer_fields,SX_COUNT(sxil_advanced_installer_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_advanced_installer_record_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("index","uint32",4,4,SX_NONE),
    SX_FIELD("xor_flag","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("name_length","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxil_advanced_installer_record = {0x60850007U,"advanced_installer_record",sxil_advanced_installer_record_fields,SX_COUNT(sxil_advanced_installer_record_fields),SX_LE};
static const xx_data_struct_field_desc sxil_advanced_installer_external_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
    SX_FIELD("name_length","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxil_advanced_installer_external = {0x60850008U,"advanced_installer_external",sxil_advanced_installer_external_fields,SX_COUNT(sxil_advanced_installer_external_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_advanced(sx_context*c,sxil_records*r){
 uint64_t start=0,p=0;uint8_t b[74];size_t attempts=0;
 while(attempts++<100000&&sxil_find(c,(const uint8_t*)"ADVINSTSFX",10,start,(uint64_t)c->size,&p)){
  start=p+10;if(p<64||!sxil_read(c,p-64,b,74))continue;
  uint32_t mode=sxil32(b,false),ext=sxil32(b+4,false),count=sxil32(b+8,false),info=sxil32(b+20,false);
  if(mode>1||sxil32(b+12,false)!=100||sxil32(b+16,false)!=p-64||!count||count>4096||info>=p-64)continue;
  if(r->count&&r->items[0].header!=info)continue;
  if(!SXIL_ADD(c,advanced_installer_footer,p-64))return false;
  uint64_t q=info,limit=mode?ext:p-64;
  for(uint32_t i=0;i<count&&q<=limit&&24<=limit-q;i++){
   uint8_t h[24];if(!sxil_read(c,q,h,24))return true;uint64_t n=sxil32(h+20,false);if(!n||n>2048||n*2>limit-q-24)return true;
   if(!SXIL_ADD(c,advanced_installer_record,q)||!sxil_text(c,&sxil_installerlast_utf16_name,q+24,n*2))return false;q+=24+n*2;
  }
  if(mode&&ext<=p-64&&8<=p-64-ext){uint32_t n;if(sxil_u32(c,ext+4,&n)&&n<=(p-64-ext-8)/2){if(!SXIL_ADD(c,advanced_installer_external,ext)||!sxil_text(c,&sxil_installerlast_utf16_name,ext+8,(uint64_t)n*2))return false;}}
  return true;
 }
 return true;
}
bool sx_advanced_installer_bootstrapper_build(sx_context*c,sxil_records records)
{
 return sxil_advanced(c,&records);
}
#undef SXIL_ADD
