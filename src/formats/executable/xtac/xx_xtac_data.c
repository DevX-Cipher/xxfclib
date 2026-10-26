/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XTAC data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_xtac_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("is_updated","uint32",8,4,SX_FLAGS),
 SX_FIELD("address_pairs_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("address_pair_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("module_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("module_name_size","uint32",24,4,SX_SIZE),
 SX_FIELD("nt_path_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("nt_path_size","uint32",32,4,SX_SIZE),
 SX_FIELD("head_block_stub_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("tail_block_stub_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("block_stub_code_size","uint32",44,4,SX_SIZE),
 SX_FIELD("linked_list_head_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("linked_list_tail_offset","uint32",52,4,SX_OFFSET),
};
const sx_layout sxexm_xtac_header = {UINT32_C(0x602b0032),"xtac_header",sxexm_xtac_header_fields,SX_COUNT(sxexm_xtac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_address_pair_fields[] = {
 SX_FIELD("x86_rva","uint32",0,4,SX_ADDRESS),
 SX_FIELD("arm64_rva","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxexm_xtac_address_pair = {UINT32_C(0x602b0033),"xtac_address_pair",sxexm_xtac_address_pair_fields,SX_COUNT(sxexm_xtac_address_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_block_stub_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("offset_to_next_entry","uint32",4,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("padding","uint32",12,4,SX_RESERVED),
};
const sx_layout sxexm_xtac_block_stub = {UINT32_C(0x602b0034),"xtac_block_stub",sxexm_xtac_block_stub_fields,SX_COUNT(sxexm_xtac_block_stub_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry0_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
};
const sx_layout sxexm_xtac_linked_entry0 = {UINT32_C(0x602b0035),"xtac_linked_entry0",sxexm_xtac_linked_entry0_fields,SX_COUNT(sxexm_xtac_linked_entry0_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry1_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("forward_edge_address","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxexm_xtac_linked_entry1 = {UINT32_C(0x602b0036),"xtac_linked_entry1",sxexm_xtac_linked_entry1_fields,SX_COUNT(sxexm_xtac_linked_entry1_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry2_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("backward_edge_address","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxexm_xtac_linked_entry2 = {UINT32_C(0x602b0037),"xtac_linked_entry2",sxexm_xtac_linked_entry2_fields,SX_COUNT(sxexm_xtac_linked_entry2_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry3_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("forward_edge_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("backward_edge_address","uint32",8,4,SX_ADDRESS),
};
const sx_layout sxexm_xtac_linked_entry3 = {UINT32_C(0x602b0038),"xtac_linked_entry3",sxexm_xtac_linked_entry3_fields,SX_COUNT(sxexm_xtac_linked_entry3_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_xtac(sx_context*c){uint8_t h[56],b[16];if(!sxexm_read(c,0,h,56)||!sxexm_add(c,&sxexm_xtac_header,0)||!sxexm_table(c,&sxexm_xtac_address_pair,sxexm32(h+12,false),sxexm32(h+16,false)))return false;uint64_t p=sxexm32(h+36,false);for(unsigned i=0;p&&i<20;i++){if(!sxexm_read(c,p,b,16)||xx_rt_memcmp(b,"BLCK",4)||!sxexm_free(c,p,16))break;if(!sxexm_add(c,&sxexm_xtac_block_stub,p))return false;p=sxexm32(b+8,false);}p=sxexm32(h+48,false);for(unsigned i=0;p&&i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){uint64_t v;if(!sxexm_word(c,p,4,false,&v))break;unsigned k=(unsigned)(v>>28)&3,z=4+((k&1)?4:0)+((k&2)?4:0);const sx_layout*ls[]={&sxexm_xtac_linked_entry0,&sxexm_xtac_linked_entry1,&sxexm_xtac_linked_entry2,&sxexm_xtac_linked_entry3};if(!sxexm_span(c,p,z)||!sxexm_free(c,p,z))break;if(!sxexm_add(c,ls[k],p))return false;uint64_t step=v&0x0fffffff;if(!step||step==0x0fffffff)break;p+=step*4;}return true;}
bool sx_xtac_build(sx_context*c)
{
bool ok=false;
ok=sxexm_xtac(c);
return ok&&sxexm_finish(c);
}
