/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XCOFF data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_xcoff32_file_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("section_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("timestamp","int32",4,4,SX_TIME),
 SX_FIELD("symbol_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("symbol_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("optional_header_size","uint16",16,2,SX_SIZE),
 SX_FIELD("flags","uint16",18,2,SX_FLAGS),
};
const sx_layout sxexm_xcoff32_file_header = {UINT32_C(0x602b0059),"xcoff32_file_header",sxexm_xcoff32_file_header_fields,SX_COUNT(sxexm_xcoff32_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_optional_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version_stamp","uint16",2,2,SX_ID),
 SX_FIELD("text_size","uint32",4,4,SX_SIZE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_descriptor","uint32",16,4,SX_ADDRESS),
 SX_FIELD("text_start","uint32",20,4,SX_ADDRESS),
 SX_FIELD("data_start","uint32",24,4,SX_ADDRESS),
 SX_FIELD("toc","uint32",28,4,SX_ADDRESS),
 SX_FIELD("entry_section","uint16",32,2,SX_ID),
 SX_FIELD("text_section","uint16",34,2,SX_ID),
 SX_FIELD("data_section","uint16",36,2,SX_ID),
 SX_FIELD("toc_section","uint16",38,2,SX_ID),
 SX_FIELD("loader_section","uint16",40,2,SX_ID),
 SX_FIELD("bss_section","uint16",42,2,SX_ID),
 SX_FIELD("text_alignment_shift","uint16",44,2,SX_NONE),
 SX_FIELD("data_alignment_shift","uint16",46,2,SX_NONE),
 SX_FIELD("module_type","uint16",48,2,SX_ID),
 SX_FIELD("cpu_flags","uint8",50,1,SX_FLAGS),
 SX_FIELD("cpu_type","uint8",51,1,SX_ID),
 SX_FIELD("max_stack_size","uint32",52,4,SX_SIZE),
 SX_FIELD("max_data_size","uint32",56,4,SX_SIZE),
 SX_FIELD("debugger","uint32",60,4,SX_NONE),
 SX_FIELD("text_page_size","uint8",64,1,SX_NONE),
 SX_FIELD("data_page_size","uint8",65,1,SX_NONE),
 SX_FIELD("stack_page_size","uint8",66,1,SX_NONE),
 SX_FIELD("flags","uint8",67,1,SX_FLAGS),
 SX_FIELD("tls_data_section","uint16",68,2,SX_ID),
 SX_FIELD("tls_bss_section","uint16",70,2,SX_ID),
};
const sx_layout sxexm_xcoff32_optional_header = {UINT32_C(0x602b005a),"xcoff32_optional_header",sxexm_xcoff32_optional_header_fields,SX_COUNT(sxexm_xcoff32_optional_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_section_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("physical_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("virtual_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("size","uint32",16,4,SX_SIZE),
 SX_FIELD("file_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("relocation_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("line_number_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("relocation_count","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("line_number_count","uint16",34,2,SX_COUNT_PROP),
 SX_FIELD("flags","int32",36,4,SX_FLAGS),
};
const sx_layout sxexm_xcoff32_section = {UINT32_C(0x602b005b),"xcoff32_section",sxexm_xcoff32_section_fields,SX_COUNT(sxexm_xcoff32_section_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_fields[] = {
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("symbol_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("relocation_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("import_strings_size","uint32",12,4,SX_SIZE),
 SX_FIELD("import_file_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("import_files_offset","int32",20,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",24,4,SX_SIZE),
 SX_FIELD("strings_offset","int32",28,4,SX_OFFSET),
};
const sx_layout sxexm_xcoff32_loader = {UINT32_C(0x602b005c),"xcoff32_loader",sxexm_xcoff32_loader_fields,SX_COUNT(sxexm_xcoff32_loader_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_symbol_inline_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("value","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_number","int16",12,2,SX_ID),
 SX_FIELD("type_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("storage_class","uint8",15,1,SX_ID),
 SX_FIELD("import_file_index","uint32",16,4,SX_ID),
 SX_FIELD("parameter_type_offset","uint32",20,4,SX_OFFSET),
};
const sx_layout sxexm_xcoff32_loader_symbol_inline = {UINT32_C(0x602b005d),"xcoff32_loader_symbol_inline",sxexm_xcoff32_loader_symbol_inline_fields,SX_COUNT(sxexm_xcoff32_loader_symbol_inline_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_symbol_external_fields[] = {
 SX_FIELD("zero","uint32",0,4,SX_RESERVED),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("value","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_number","int16",12,2,SX_ID),
 SX_FIELD("type_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("storage_class","uint8",15,1,SX_ID),
 SX_FIELD("import_file_index","uint32",16,4,SX_ID),
 SX_FIELD("parameter_type_offset","uint32",20,4,SX_OFFSET),
};
const sx_layout sxexm_xcoff32_loader_symbol_external = {UINT32_C(0x602b005e),"xcoff32_loader_symbol_external",sxexm_xcoff32_loader_symbol_external_fields,SX_COUNT(sxexm_xcoff32_loader_symbol_external_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_xcoff(sx_context*c){uint8_t h[92],s[40],b[32];if(!sxexm_read(c,0,h,92)||!sxexm_add(c,&sxexm_xcoff32_file_header,0)||!sxexm_add(c,&sxexm_xcoff32_optional_header,20))return false;uint64_t n=sxexm16(h+2,true),loader=sxexm16(h+60,true);if(!sxexm_table(c,&sxexm_xcoff32_section,92,n))return false;if(!loader||loader>n||!sxexm_read(c,92+(loader-1)*40,s,40))return true;uint64_t p=sxexm32(s+20,true),z=sxexm32(s+16,true);if(z<32||!sxexm_span(c,p,z)||!sxexm_read(c,p,b,32)||!sxexm_add(c,&sxexm_xcoff32_loader,p))return true;uint64_t count=sxexm32(b+4,true);if(count>SXEXM_LIMIT||count>(z-32)/24)return true;for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){uint64_t name;if(!sxexm_word(c,p+32+i*24,4,true,&name))break;if(!sxexm_add(c,name?&sxexm_xcoff32_loader_symbol_inline:&sxexm_xcoff32_loader_symbol_external,p+32+i*24))return false;}return true;}
bool sx_xcoff_build(sx_context*c)
{
bool ok=false;
ok=sxexm_xcoff(c);
return ok&&sxexm_finish(c);
}
