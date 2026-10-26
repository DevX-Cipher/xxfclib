/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IBM ZPAK installer data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
};
const sx_layout sxil_ibm_zpak_sfx_header = {0x60850018U,"ibm_zpak_sfx_header",sxil_ibm_zpak_sfx_header_fields,SX_COUNT(sxil_ibm_zpak_sfx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v1_directory_fields[] = {
    SX_FIELD("name","char[102]",0,102,SX_NONE),
    SX_FIELD("packed_size","int32",102,4,SX_SIZE),
    SX_FIELD("reserved","uint32",106,4,SX_RESERVED),
    SX_FIELD("dos_date","uint16",110,2,SX_NONE),
    SX_FIELD("dos_time","uint16",112,2,SX_NONE),
};
const sx_layout sxil_ibm_zpak_sfx_v1_directory = {0x60850019U,"ibm_zpak_sfx_v1_directory",sxil_ibm_zpak_sfx_v1_directory_fields,SX_COUNT(sxil_ibm_zpak_sfx_v1_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v2_record_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("unused","uint8",1,1,SX_NONE),
    SX_FIELD("packed_size","int32",2,4,SX_SIZE),
    SX_FIELD("writer_scratch","byte[4]",6,4,SX_NONE),
    SX_FIELD("dos_date","uint16",10,2,SX_NONE),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("name_size","int16",14,2,SX_SIZE),
};
const sx_layout sxil_ibm_zpak_sfx_v2_record = {0x6085001aU,"ibm_zpak_sfx_v2_record",sxil_ibm_zpak_sfx_v2_record_fields,SX_COUNT(sxil_ibm_zpak_sfx_v2_record_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v1_trailer_fields[] = {
    SX_FIELD("file_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("header_offset","uint32",2,4,SX_OFFSET),
    SX_FIELD("declared_file_size","uint32",6,4,SX_SIZE),
    SX_FIELD("product_tag","char[12]",10,12,SX_NONE),
};
const sx_layout sxil_ibm_zpak_sfx_v1_trailer = {0x6085001bU,"ibm_zpak_sfx_v1_trailer",sxil_ibm_zpak_sfx_v1_trailer_fields,SX_COUNT(sxil_ibm_zpak_sfx_v1_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v2_trailer_fields[] = {
    SX_FIELD("file_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("header_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("adjusted_file_size","uint32",8,4,SX_NONE),
    SX_FIELD("product_tag","char[26]",12,26,SX_NONE),
};
const sx_layout sxil_ibm_zpak_sfx_v2_trailer = {0x6085001cU,"ibm_zpak_sfx_v2_trailer",sxil_ibm_zpak_sfx_v2_trailer_fields,SX_COUNT(sxil_ibm_zpak_sfx_v2_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installerlast_dcl_prelude_fields[] = {
    SX_FIELD("literal_mode","uint8",0,1,SX_ID),
    SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
const sx_layout sxil_installerlast_dcl_prelude = {0x6085001dU,"installerlast_dcl_prelude",sxil_installerlast_dcl_prelude_fields,SX_COUNT(sxil_installerlast_dcl_prelude_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_zpak(sx_context*c){
 uint64_t total=(uint64_t)c->size;uint8_t b[38];uint32_t count,p;unsigned version=0;uint64_t tr=0;
 if(total>=38&&sxil_read(c,total-38,b,38)){count=sxil32(b,false);p=sxil32(b+4,false);if(count&&count<=65535&&sxil_eq(c,p,"-ZPAK\0\2\0",8)){version=2;tr=total-38;}}
 if(!version&&total>=22&&sxil_read(c,total-22,b,22)){count=sxil16(b,false);p=sxil32(b+2,false);if(count&&sxil_eq(c,p,"-ZPAK\0\1\0",8)){version=1;tr=total-22;}}
 if(!version||!SXIL_ADD(c,ibm_zpak_sfx_header,p))return !version;
 if(version==1){if(!SXIL_ADD(c,ibm_zpak_sfx_v1_trailer,tr))return false;if(count>tr/114)return true;uint64_t dir=tr-(uint64_t)count*114,q=(uint64_t)p+8;if(dir<q)return true;
  if(!sxil_put(c,&sxil_ibm_zpak_sfx_v1_directory,dir,count))return false;for(uint32_t i=0;i<count;i++){uint32_t z;if(!sxil_u32(c,dir+(uint64_t)i*114+102,&z)||z<3||z>dir-q)return true;if(!SXIL_ADD(c,installerlast_dcl_prelude,q))return false;q+=z;}}
 else{if(!SXIL_ADD(c,ibm_zpak_sfx_v2_trailer,tr))return false;uint64_t q=(uint64_t)p+8;for(uint32_t i=0;i<count&&q<=tr&&16<=tr-q;i++){uint8_t h[16];if(!sxil_read(c,q,h,16))return true;uint64_t z=sxil32(h+2,false),n=sxil16(h+14,false);if(h[0]!=10||!n||n>1024||n>tr-q-16||z<3||z>tr-q-16-n)return true;if(!SXIL_ADD(c,ibm_zpak_sfx_v2_record,q)||!sxil_name(c,q+16,n)||!SXIL_ADD(c,installerlast_dcl_prelude,q+16+n))return false;q+=16+n+z;}}
 return true;
}
bool sx_ibm_zpak_installer_build(sx_context*c)
{
 return sxil_zpak(c);
}
#undef SXIL_ADD
