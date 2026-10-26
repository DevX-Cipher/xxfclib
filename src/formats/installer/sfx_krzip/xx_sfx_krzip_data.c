/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_krzip data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_installer_encoded_bytes_fields[] = {
    SX_FIELD("encoded_bytes","uint8",0,0,SX_NONE),
};
const sx_layout sxiex_installer_encoded_bytes = {0x60820005U,"installer_encoded_bytes",sxiex_installer_encoded_bytes_fields,SX_COUNT(sxiex_installer_encoded_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_krzip_header_fields[] = {
    SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
};
const sx_layout sxiex_krzip_header = {0x6082000cU,"krzip_header",sxiex_krzip_header_fields,SX_COUNT(sxiex_krzip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_krzip_encoded_name_length_fields[] = {
    SX_FIELD("encrypted_name_length","byte[2]",0,2,SX_NONE),
};
const sx_layout sxiex_krzip_encoded_name_length = {0x6082000dU,"krzip_encoded_name_length",sxiex_krzip_encoded_name_length_fields,SX_COUNT(sxiex_krzip_encoded_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_krzip_encoded_fields_fields[] = {
    SX_FIELD("encrypted_dos_time","byte[2]",0,2,SX_NONE),
    SX_FIELD("encrypted_dos_date","byte[2]",2,2,SX_NONE),
    SX_FIELD("encrypted_unpacked_size","byte[4]",4,4,SX_NONE),
    SX_FIELD("encrypted_attributes","byte[4]",8,4,SX_NONE),
    SX_FIELD("encrypted_packed_size","byte[4]",12,4,SX_NONE),
    SX_FIELD("encrypted_complemented_crc32","byte[4]",16,4,SX_NONE),
};
const sx_layout sxiex_krzip_encoded_fields = {0x6082000eU,"krzip_encoded_fields",sxiex_krzip_encoded_fields_fields,SX_COUNT(sxiex_krzip_encoded_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_krzip_footer_fields[] = {
    SX_FIELD("complemented_crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxiex_krzip_footer = {0x6082000fU,"krzip_footer",sxiex_krzip_footer_fields,SX_COUNT(sxiex_krzip_footer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_encoded(sx_context*c,uint64_t p,uint64_t n){return sxiex_text(c,&sxiex_installer_encoded_bytes,p,n);}
static bool sxiex_krzip(sx_context*c,const sxiex_records*r){
 uint64_t p;if(sxiex_pe(c,&p)&&sxiex_eq(c,p,"<KRZIP FILE BEGINS HERE>",24)&&!SXIEX_ADD(c,krzip_header,p))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size<23||m->header_size>1046)continue;uint64_t n=m->header_size-22;if(!SXIEX_ADD(c,krzip_encoded_name_length,m->header)||!sxiex_encoded(c,m->header+2,n)||!SXIEX_ADD(c,krzip_encoded_fields,m->header+2+n))return false;}
 return c->size<4||SXIEX_ADD(c,krzip_footer,(uint64_t)c->size-4);
}
bool sx_sfx_krzip_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_krzip(c,records);
}
#undef SXIEX_ADD
