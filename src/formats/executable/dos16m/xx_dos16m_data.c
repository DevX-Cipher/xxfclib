/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DOS16M/DOS4G data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_dos_extender_mz_fields[] = {
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("pages_in_file","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("relocation_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("header_paragraphs","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("min_alloc_paragraphs","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("max_alloc_paragraphs","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("initial_ss","uint16",14,2,SX_NONE),
 SX_FIELD("initial_sp","uint16",16,2,SX_ADDRESS),
 SX_FIELD("checksum","uint16",18,2,SX_CHECKSUM),
 SX_FIELD("initial_ip","uint16",20,2,SX_ADDRESS),
 SX_FIELD("initial_cs","uint16",22,2,SX_NONE),
 SX_FIELD("relocations_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("overlay_number","uint16",26,2,SX_ID),
 SX_FIELD("reserved","uint16[4]",28,8,SX_RESERVED),
 SX_FIELD("oem_id","uint16",36,2,SX_ID),
 SX_FIELD("oem_info","uint16",38,2,SX_NONE),
 SX_FIELD("reserved2","uint16[10]",40,20,SX_RESERVED),
 SX_FIELD("new_header_offset","uint32",60,4,SX_OFFSET),
};
const sx_layout sxexm_dos_extender_mz = {UINT32_C(0x602b0043),"dos_extender_mz",sxexm_dos_extender_mz_fields,SX_COUNT(sxexm_dos_extender_mz_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dos16m_bw_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("pages_in_file","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved1","uint16",6,2,SX_RESERVED),
 SX_FIELD("reserved2","uint16",8,2,SX_RESERVED),
 SX_FIELD("min_alloc_kib","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("max_alloc_kib","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("stack_selector","uint16",14,2,SX_ID),
 SX_FIELD("stack_pointer","uint16",16,2,SX_ADDRESS),
 SX_FIELD("first_relocation_selector","uint16",18,2,SX_ID),
 SX_FIELD("initial_ip","uint16",20,2,SX_ADDRESS),
 SX_FIELD("code_selector","uint16",22,2,SX_ID),
 SX_FIELD("runtime_gdt_size","uint16",24,2,SX_SIZE),
 SX_FIELD("makepm_version","uint16",26,2,SX_NONE),
 SX_FIELD("next_header_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("codeview_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("last_selector","uint16",36,2,SX_ID),
 SX_FIELD("physical_alloc_kib","uint16",38,2,SX_COUNT_PROP),
 SX_FIELD("allocation_increment_kib","uint16",40,2,SX_COUNT_PROP),
 SX_FIELD("unknown42","uint8[6]",42,6,SX_NONE),
 SX_FIELD("options","uint16",48,2,SX_FLAGS),
 SX_FIELD("transition_stack_selector","uint16",50,2,SX_ID),
 SX_FIELD("flags","uint16",52,2,SX_FLAGS),
 SX_FIELD("program_paragraphs","uint16",54,2,SX_COUNT_PROP),
 SX_FIELD("gdt_image_size","uint16",56,2,SX_SIZE),
 SX_FIELD("first_selector","uint16",58,2,SX_ID),
 SX_FIELD("default_memory_strategy","uint8",60,1,SX_ID),
 SX_FIELD("unknown61","uint8",61,1,SX_NONE),
 SX_FIELD("transfer_buffer_size","uint16",62,2,SX_SIZE),
 SX_FIELD("unknown64","uint8[48]",64,48,SX_NONE),
 SX_FIELD("exp_path","char[64]",112,64,SX_STRING),
};
const sx_layout sxexm_dos16m_bw_header = {UINT32_C(0x602b0044),"dos16m_bw_header",sxexm_dos16m_bw_header_fields,SX_COUNT(sxexm_dos16m_bw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dos16m_mf_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxexm_dos16m_mf_header = {UINT32_C(0x602b0045),"dos16m_mf_header",sxexm_dos16m_mf_header_fields,SX_COUNT(sxexm_dos16m_mf_header_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_dos(sx_context*c){uint8_t h[64];if(!sxexm_read(c,0,h,64)||!sxexm_add(c,&sxexm_dos_extender_mz,0))return false;uint64_t pages=sxexm16(h+4,false);if(!pages)return true;uint64_t p=(pages-1)*512+sxexm16(h+2,false);for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,2))break;if(!xx_rt_memcmp(h,"BW",2)){uint64_t next;if(!sxexm_span(c,p,176)||!sxexm_word(c,p+28,4,false,&next))break;if(!sxexm_add(c,&sxexm_dos16m_bw_header,p))return false;if(next<=p)break;p=next;}else if(!xx_rt_memcmp(h,"MF",2)){uint64_t z;if(!sxexm_word(c,p+2,4,false,&z)||z<6||!sxexm_span(c,p,z))break;if(!sxexm_add(c,&sxexm_dos16m_mf_header,p))return false;p+=z;}else if(!xx_rt_memcmp(h,"MZ",2)){if(sxexm_span(c,p,64)&&!sxexm_add(c,&sxexm_dos_extender_mz,p))return false;break;}else break;}return true;}
bool sx_dos16m_build(sx_context*c)
{
bool ok=false;
ok=sxexm_dos(c);
return ok&&sxexm_finish(c);
}
