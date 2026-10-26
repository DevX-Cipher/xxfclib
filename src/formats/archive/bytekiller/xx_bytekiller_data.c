/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BYTEKILLER data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_bytekiller_header_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("xor_checksum","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxan_bytekiller_header = {UINT32_C(0x6077005e),"bytekiller_header",sxan_bytekiller_header_fields,SX_COUNT(sxan_bytekiller_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_ace_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("xor_checksum","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxan_bytekiller_ace_header = {UINT32_C(0x6077005f),"bytekiller_ace_header",sxan_bytekiller_ace_header_fields,SX_COUNT(sxan_bytekiller_ace_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_anc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxan_bytekiller_anc_header = {UINT32_C(0x60770060),"bytekiller_anc_header",sxan_bytekiller_anc_header_fields,SX_COUNT(sxan_bytekiller_anc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_grac_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
};
const sx_layout sxan_bytekiller_grac_header = {UINT32_C(0x60770061),"bytekiller_grac_header",sxan_bytekiller_grac_header_fields,SX_COUNT(sxan_bytekiller_grac_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_md11_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("encoded_size","uint32",4,4,SX_NONE),
};
const sx_layout sxan_bytekiller_md11_header = {UINT32_C(0x60770062),"bytekiller_md11_header",sxan_bytekiller_md11_header_fields,SX_COUNT(sxan_bytekiller_md11_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxan_bytekiller_signature = {UINT32_C(0x60770063),"bytekiller_signature",sxan_bytekiller_signature_fields,SX_COUNT(sxan_bytekiller_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_bytekiller_footer_fields[] = {
 SX_FIELD("xor_checksum","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxan_bytekiller_footer = {UINT32_C(0x60770064),"bytekiller_footer",sxan_bytekiller_footer_fields,SX_COUNT(sxan_bytekiller_footer_fields),SX_BE};
static bool sxan_bytekiller(sx_context*c){uint64_t head,foot,z;if(c->size<12||!sxan_word(c,0,4,true,&head)||!sxan_word(c,(uint64_t)c->size-4,4,true,&foot))return false;switch(head){case 0x41434521:return sxan_add(c,&sxan_bytekiller_ace_header,0);case 0x46564c30:if(!sxan_word(c,4,4,true,&z)||z<8)return false;return sxan_add(c,&sxan_bytekiller_anc_header,0)&&sxan_add(c,&sxan_bytekiller_footer,z);case 0x47523230:return sxan_add(c,&sxan_bytekiller_grac_header,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);case 0x4d443130:return sxan_add(c,&sxan_bytekiller_signature,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);case 0x4d443131:return sxan_add(c,&sxan_bytekiller_md11_header,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);default:if(foot==0x4a454b21)return c->size>=16&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-12)&&sxan_add(c,&sxan_bytekiller_signature,(uint64_t)c->size-4);if(!sxan_add(c,&sxan_bytekiller_header,0))return false;return foot!=0x64617461||sxan_add(c,&sxan_bytekiller_signature,head+12);}}
bool sx_bytekiller_build(sx_context*c)
{
bool ok=false;
ok=sxan_bytekiller(c);
(void)ok;return c->count&&sxan_finish(c);
}
