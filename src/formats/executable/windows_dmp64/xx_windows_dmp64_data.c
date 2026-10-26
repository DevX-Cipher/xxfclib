/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WINDOWS_DMP64 data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_dmp64_prefix_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("valid_dump","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint32",8,4,SX_ID),
 SX_FIELD("minor_version","uint32",12,4,SX_ID),
 SX_FIELD("directory_table_base","uint64",16,8,SX_ADDRESS),
 SX_FIELD("pfn_database","uint64",24,8,SX_ADDRESS),
 SX_FIELD("loaded_module_list","uint64",32,8,SX_ADDRESS),
 SX_FIELD("active_process_head","uint64",40,8,SX_ADDRESS),
 SX_FIELD("machine_type","uint32",48,4,SX_ID),
 SX_FIELD("processor_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("bugcheck_code","uint32",56,4,SX_ID),
 SX_FIELD("padding","uint32",60,4,SX_RESERVED),
 SX_FIELD("bugcheck_parameters","uint64[4]",64,32,SX_NONE),
 SX_FIELD("version_user","char[32]",96,32,SX_STRING),
 SX_FIELD("debugger_data_block","uint64",128,8,SX_ADDRESS),
};
const sx_layout sxexm_dmp64_prefix = {UINT32_C(0x602b0021),"dmp64_prefix",sxexm_dmp64_prefix_fields,SX_COUNT(sxexm_dmp64_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_type_fields[] = {
 SX_FIELD("dump_type","uint32",0,4,SX_ID),
};
const sx_layout sxexm_dmp64_type = {UINT32_C(0x602b0022),"dmp64_type",sxexm_dmp64_type_fields,SX_COUNT(sxexm_dmp64_type_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_required_space_fields[] = {
 SX_FIELD("required_space","uint64",0,8,SX_SIZE),
};
const sx_layout sxexm_dmp64_required_space = {UINT32_C(0x602b0023),"dmp64_required_space",sxexm_dmp64_required_space_fields,SX_COUNT(sxexm_dmp64_required_space_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_product_fields[] = {
 SX_FIELD("secondary_state","uint32",0,4,SX_FLAGS),
 SX_FIELD("product_type","uint32",4,4,SX_ID),
 SX_FIELD("suite_mask","uint32",8,4,SX_FLAGS),
};
const sx_layout sxexm_dmp64_product = {UINT32_C(0x602b0024),"dmp64_product",sxexm_dmp64_product_fields,SX_COUNT(sxexm_dmp64_product_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_bitmap_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown","uint8[24]",8,24,SX_NONE),
 SX_FIELD("first_page_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("present_page_count","uint64",40,8,SX_COUNT_PROP),
 SX_FIELD("addressable_page_count","uint64",48,8,SX_COUNT_PROP),
};
const sx_layout sxexm_dmp64_bitmap_header = {UINT32_C(0x602b0025),"dmp64_bitmap_header",sxexm_dmp64_bitmap_header_fields,SX_COUNT(sxexm_dmp64_bitmap_header_fields),SX_LE};
bool sx_windows_dmp64_build(sx_context*c)
{
bool ok=false;
ok=sxexm_add(c,&sxexm_dmp64_prefix,0)&&sxexm_add(c,&sxexm_dmp64_type,0xf98)&&sxexm_add(c,&sxexm_dmp64_required_space,0xfa0)&&sxexm_add(c,&sxexm_dmp64_product,0x103c)&&sxexm_add(c,&sxexm_dmp64_bitmap_header,8192);
return ok&&sxexm_finish(c);
}
