/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HP_SOM data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_som_header_fields[] = {
 SX_FIELD("system_id","uint16",0,2,SX_ID),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("version_id","uint32",4,4,SX_ID),
 SX_FIELD("file_time_seconds","uint32",8,4,SX_TIME),
 SX_FIELD("file_time_nanoseconds","uint32",12,4,SX_NONE),
 SX_FIELD("entry_space","uint32",16,4,SX_ID),
 SX_FIELD("entry_subspace","uint32",20,4,SX_ID),
 SX_FIELD("entry_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("auxiliary_header_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("auxiliary_header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("som_size","uint32",36,4,SX_SIZE),
 SX_FIELD("presumed_dp","uint32",40,4,SX_ADDRESS),
 SX_FIELD("space_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("space_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("subspace_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("subspace_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("loader_fixup_offset","uint32",60,4,SX_OFFSET),
 SX_FIELD("loader_fixup_count","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("space_strings_offset","uint32",68,4,SX_OFFSET),
 SX_FIELD("space_strings_size","uint32",72,4,SX_SIZE),
 SX_FIELD("initialization_array_offset","uint32",76,4,SX_OFFSET),
 SX_FIELD("initialization_array_count","uint32",80,4,SX_COUNT_PROP),
 SX_FIELD("compiler_offset","uint32",84,4,SX_OFFSET),
 SX_FIELD("compiler_count","uint32",88,4,SX_COUNT_PROP),
 SX_FIELD("symbol_offset","uint32",92,4,SX_OFFSET),
 SX_FIELD("symbol_count","uint32",96,4,SX_COUNT_PROP),
 SX_FIELD("fixup_request_offset","uint32",100,4,SX_OFFSET),
 SX_FIELD("fixup_request_count","uint32",104,4,SX_COUNT_PROP),
 SX_FIELD("symbol_strings_offset","uint32",108,4,SX_OFFSET),
 SX_FIELD("symbol_strings_size","uint32",112,4,SX_SIZE),
 SX_FIELD("unloadable_space_offset","uint32",116,4,SX_OFFSET),
 SX_FIELD("unloadable_space_size","uint32",120,4,SX_SIZE),
 SX_FIELD("checksum","uint32",124,4,SX_CHECKSUM),
};
const sx_layout sxexm_som_header = {UINT32_C(0x602b0054),"som_header",sxexm_som_header_fields,SX_COUNT(sxexm_som_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_space_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("space_number","int32",8,4,SX_ID),
 SX_FIELD("subspace_index","int32",12,4,SX_ID),
 SX_FIELD("subspace_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("loader_fixup_index","int32",20,4,SX_ID),
 SX_FIELD("loader_fixup_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("initialization_pointer_index","int32",28,4,SX_ID),
 SX_FIELD("initialization_pointer_count","uint32",32,4,SX_COUNT_PROP),
};
const sx_layout sxexm_som_space = {UINT32_C(0x602b0055),"som_space",sxexm_som_space_fields,SX_COUNT(sxexm_som_space_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_subspace_initialized_fields[] = {
 SX_FIELD("space_index","int32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("file_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("initialization_size","uint32",12,4,SX_SIZE),
 SX_FIELD("subspace_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",20,4,SX_SIZE),
 SX_FIELD("alignment_and_reserved","uint32",24,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("fixup_request_index","int32",32,4,SX_ID),
 SX_FIELD("fixup_request_count","uint32",36,4,SX_COUNT_PROP),
};
const sx_layout sxexm_som_subspace_initialized = {UINT32_C(0x602b0056),"som_subspace_initialized",sxexm_som_subspace_initialized_fields,SX_COUNT(sxexm_som_subspace_initialized_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_subspace_pattern_fields[] = {
 SX_FIELD("space_index","int32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("initialization_pattern","int32",8,4,SX_NONE),
 SX_FIELD("initialization_size","uint32",12,4,SX_SIZE),
 SX_FIELD("subspace_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",20,4,SX_SIZE),
 SX_FIELD("alignment_and_reserved","uint32",24,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("fixup_request_index","int32",32,4,SX_ID),
 SX_FIELD("fixup_request_count","uint32",36,4,SX_COUNT_PROP),
};
const sx_layout sxexm_som_subspace_pattern = {UINT32_C(0x602b0057),"som_subspace_pattern",sxexm_som_subspace_pattern_fields,SX_COUNT(sxexm_som_subspace_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_symbol_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("qualifier_name_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("info","uint32",12,4,SX_NONE),
 SX_FIELD("value","uint32",16,4,SX_NONE),
};
const sx_layout sxexm_som_symbol = {UINT32_C(0x602b0058),"som_symbol",sxexm_som_symbol_fields,SX_COUNT(sxexm_som_symbol_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_som(sx_context*c){uint8_t b[128];if(!sxexm_read(c,0,b,128)||!sxexm_add(c,&sxexm_som_header,0))return false;if(!sxexm_table(c,&sxexm_som_space,sxexm32(b+44,true),sxexm32(b+48,true))||!sxexm_table(c,&sxexm_som_symbol,sxexm32(b+92,true),sxexm32(b+96,true)))return false;uint64_t p=sxexm32(b+52,true),n=sxexm32(b+56,true);if(n>SXEXM_LIMIT||!sxexm_span(c,p,n*40))return true;for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++){uint64_t z;if(!sxexm_word(c,p+i*40+12,4,true,&z))break;if(!sxexm_add(c,z?&sxexm_som_subspace_initialized:&sxexm_som_subspace_pattern,p+i*40))return false;}return true;}
bool sx_hp_som_build(sx_context*c)
{
bool ok=false;
ok=sxexm_som(c);
return ok&&sxexm_finish(c);
}
