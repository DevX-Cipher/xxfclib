/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ecm data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_ecm_signature_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxdn_ecm_signature = {0x60780021U,"ecm_signature",sxdn_ecm_signature_fields,SX_COUNT(sxdn_ecm_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ecm_record_first_fields[] = {
    SX_FIELD("type_count_continue","uint8",0,1,SX_NONE),
};
const sx_layout sxdn_ecm_record_first = {0x60780022U,"ecm_record_first",sxdn_ecm_record_first_fields,SX_COUNT(sxdn_ecm_record_first_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ecm_record_continuation_fields[] = {
    SX_FIELD("count_continue","uint8",0,1,SX_NONE),
};
const sx_layout sxdn_ecm_record_continuation = {0x60780023U,"ecm_record_continuation",sxdn_ecm_record_continuation_fields,SX_COUNT(sxdn_ecm_record_continuation_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ecm_edc_fields[] = {
    SX_FIELD("reconstructed_edc","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxdn_ecm_edc = {0x60780024U,"ecm_edc",sxdn_ecm_edc_fields,SX_COUNT(sxdn_ecm_edc_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ecm_mode1_address_fields[] = {
    SX_FIELD("minute_bcd","uint8",0,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",2,1,SX_NONE),
};
const sx_layout sxdn_ecm_mode1_address = {0x60780025U,"ecm_mode1_address",sxdn_ecm_mode1_address_fields,SX_COUNT(sxdn_ecm_mode1_address_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ecm_mode2_subheader_fields[] = {
    SX_FIELD("file_number","uint8",0,1,SX_ID),
    SX_FIELD("channel_number","uint8",1,1,SX_ID),
    SX_FIELD("submode","uint8",2,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",3,1,SX_FLAGS),
};
const sx_layout sxdn_ecm_mode2_subheader = {0x60780026U,"ecm_mode2_subheader",sxdn_ecm_mode2_subheader_fields,SX_COUNT(sxdn_ecm_mode2_subheader_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_ecm(sx_context*c){if(!SXDN_ADD(c,ecm_signature,0))return false;uint64_t p=4;for(unsigned work=0;work<1000000&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;work++){uint8_t b;if(!sxdn_read(c,p,&b,1)||!SXDN_ADD(c,ecm_record_first,p++))break;unsigned type=b&3,bits=5;uint64_t v=(b&0x7c)>>2;while(b&0x80){if(bits>33||!sxdn_read(c,p,&b,1)||!SXDN_ADD(c,ecm_record_continuation,p++))return true;v|=(uint64_t)(b&127)<<bits;bits+=7;}if(v>UINT32_MAX)return true;if(v==UINT32_MAX)return sxdn_span(c,p,4)?SXDN_ADD(c,ecm_edc,p):true;static const unsigned sizes[]={1,2051,2052,2328};uint64_t n=v+1;if(n>((uint64_t)c->size-p)/sizes[type])return true;if(type)for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++)if(!sxdn_put(c,type==1?&sxdn_ecm_mode1_address:&sxdn_ecm_mode2_subheader,p+i*sizes[type],1))return false;p+=n*sizes[type];}return true;}
bool sx_ecm_build(sx_context*c)
{
 return sxdn_ecm(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
