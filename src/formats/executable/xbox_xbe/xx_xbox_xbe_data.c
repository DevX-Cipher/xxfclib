/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XBOX_XBE data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_xbe_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("digital_signature","uint8[256]",4,256,SX_SIGNATURE),
 SX_FIELD("base_address","uint32",260,4,SX_ADDRESS),
 SX_FIELD("headers_size","uint32",264,4,SX_SIZE),
 SX_FIELD("image_size","uint32",268,4,SX_SIZE),
 SX_FIELD("image_header_size","uint32",272,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",276,4,SX_TIME),
 SX_FIELD("certificate_address","uint32",280,4,SX_ADDRESS),
 SX_FIELD("section_count","uint32",284,4,SX_COUNT_PROP),
 SX_FIELD("section_headers_address","uint32",288,4,SX_ADDRESS),
 SX_FIELD("initialization_flags","uint32",292,4,SX_FLAGS),
 SX_FIELD("encoded_entry_point","uint32",296,4,SX_FLAGS),
 SX_FIELD("tls_address","uint32",300,4,SX_ADDRESS),
 SX_FIELD("stack_commit","uint32",304,4,SX_SIZE),
 SX_FIELD("heap_reserve","uint32",308,4,SX_SIZE),
 SX_FIELD("heap_commit","uint32",312,4,SX_SIZE),
 SX_FIELD("original_base_address","uint32",316,4,SX_ADDRESS),
 SX_FIELD("original_image_size","uint32",320,4,SX_SIZE),
 SX_FIELD("original_checksum","uint32",324,4,SX_CHECKSUM),
 SX_FIELD("original_timestamp","uint32",328,4,SX_TIME),
 SX_FIELD("debug_path_address","uint32",332,4,SX_ADDRESS),
 SX_FIELD("debug_filename_address","uint32",336,4,SX_ADDRESS),
 SX_FIELD("debug_unicode_filename_address","uint32",340,4,SX_ADDRESS),
 SX_FIELD("encoded_kernel_thunk_address","uint32",344,4,SX_FLAGS),
 SX_FIELD("nonkernel_import_address","uint32",348,4,SX_ADDRESS),
 SX_FIELD("library_version_count","uint32",352,4,SX_COUNT_PROP),
 SX_FIELD("library_versions_address","uint32",356,4,SX_ADDRESS),
 SX_FIELD("kernel_library_version_address","uint32",360,4,SX_ADDRESS),
 SX_FIELD("xapi_library_version_address","uint32",364,4,SX_ADDRESS),
 SX_FIELD("logo_address","uint32",368,4,SX_ADDRESS),
 SX_FIELD("logo_size","uint32",372,4,SX_SIZE),
};
const sx_layout sxexm_xbe_header = {UINT32_C(0x602b001e),"xbe_header",sxexm_xbe_header_fields,SX_COUNT(sxexm_xbe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xbe_section_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("virtual_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",8,4,SX_SIZE),
 SX_FIELD("raw_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("raw_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_address","uint32",20,4,SX_ADDRESS),
 SX_FIELD("reference_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("head_shared_reference_address","uint32",28,4,SX_ADDRESS),
 SX_FIELD("tail_shared_reference_address","uint32",32,4,SX_ADDRESS),
 SX_FIELD("sha1","uint8[20]",36,20,SX_CHECKSUM),
};
const sx_layout sxexm_xbe_section = {UINT32_C(0x602b001f),"xbe_section",sxexm_xbe_section_fields,SX_COUNT(sxexm_xbe_section_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xbe_certificate_fields[] = {
 SX_FIELD("certificate_size","uint32",0,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
 SX_FIELD("title_id","uint32",8,4,SX_ID),
 SX_FIELD("title_name","uint16[40]",12,80,SX_STRING),
 SX_FIELD("alternate_title_ids","uint32[16]",92,64,SX_ID),
 SX_FIELD("allowed_media","uint32",156,4,SX_FLAGS),
 SX_FIELD("game_region","uint32",160,4,SX_FLAGS),
 SX_FIELD("game_ratings","uint32",164,4,SX_FLAGS),
 SX_FIELD("disc_number","uint32",168,4,SX_ID),
 SX_FIELD("version","uint32",172,4,SX_ID),
 SX_FIELD("lan_key","uint8[16]",176,16,SX_NONE),
 SX_FIELD("signature_key","uint8[16]",192,16,SX_NONE),
 SX_FIELD("alternate_signature_keys","uint8[256]",208,256,SX_NONE),
};
const sx_layout sxexm_xbe_certificate = {UINT32_C(0x602b0020),"xbe_certificate",sxexm_xbe_certificate_fields,SX_COUNT(sxexm_xbe_certificate_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_xbe(sx_context*c){uint8_t b[376];if(!sxexm_read(c,0,b,sizeof(b))||!sxexm_add(c,&sxexm_xbe_header,0))return false;uint64_t base=sxexm32(b+260,false),heads=sxexm32(b+264,false),cert=sxexm32(b+280,false),n=sxexm32(b+284,false),table=sxexm32(b+288,false);if(table>=base&&table-base<=heads&&n<=SXEXM_LIMIT&&n<=(heads-(table-base))/56&&!sxexm_table(c,&sxexm_xbe_section,table-base,n))return false;if(cert>=base&&cert-base<=heads&&heads-(cert-base)>=464){uint64_t z;if(sxexm_word(c,cert-base,4,false,&z)&&z>=464&&z<=heads-(cert-base)&&!sxexm_add(c,&sxexm_xbe_certificate,cert-base))return false;}return true;}
bool sx_xbox_xbe_build(sx_context*c)
{
bool ok=false;
ok=sxexm_xbe(c);
return ok&&sxexm_finish(c);
}
