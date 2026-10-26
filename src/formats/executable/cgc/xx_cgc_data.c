/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CGC data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_cgc_header_le_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("elf_class","uint8",4,1,SX_ID),
 SX_FIELD("endian","uint8",5,1,SX_ID),
 SX_FIELD("elf_version","uint8",6,1,SX_ID),
 SX_FIELD("osabi","uint8",7,1,SX_ID),
 SX_FIELD("abi_version","uint8",8,1,SX_ID),
 SX_FIELD("padding","uint8[7]",9,7,SX_RESERVED),
 SX_FIELD("file_type","uint16",16,2,SX_ID),
 SX_FIELD("machine","uint16",18,2,SX_ID),
 SX_FIELD("version","uint32",20,4,SX_ID),
 SX_FIELD("entry_point","uint32",24,4,SX_ADDRESS),
 SX_FIELD("program_headers_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("section_headers_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("flags","uint32",36,4,SX_FLAGS),
 SX_FIELD("header_size","uint16",40,2,SX_SIZE),
 SX_FIELD("program_header_size","uint16",42,2,SX_SIZE),
 SX_FIELD("program_header_count","uint16",44,2,SX_COUNT_PROP),
 SX_FIELD("section_header_size","uint16",46,2,SX_SIZE),
 SX_FIELD("section_header_count","uint16",48,2,SX_COUNT_PROP),
 SX_FIELD("section_names_index","uint16",50,2,SX_ID),
};
const sx_layout sxexm_cgc_header_le = {UINT32_C(0x602b0026),"cgc_header_le",sxexm_cgc_header_le_fields,SX_COUNT(sxexm_cgc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_header_be_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("elf_class","uint8",4,1,SX_ID),
 SX_FIELD("endian","uint8",5,1,SX_ID),
 SX_FIELD("elf_version","uint8",6,1,SX_ID),
 SX_FIELD("osabi","uint8",7,1,SX_ID),
 SX_FIELD("abi_version","uint8",8,1,SX_ID),
 SX_FIELD("padding","uint8[7]",9,7,SX_RESERVED),
 SX_FIELD("file_type","uint16",16,2,SX_ID),
 SX_FIELD("machine","uint16",18,2,SX_ID),
 SX_FIELD("version","uint32",20,4,SX_ID),
 SX_FIELD("entry_point","uint32",24,4,SX_ADDRESS),
 SX_FIELD("program_headers_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("section_headers_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("flags","uint32",36,4,SX_FLAGS),
 SX_FIELD("header_size","uint16",40,2,SX_SIZE),
 SX_FIELD("program_header_size","uint16",42,2,SX_SIZE),
 SX_FIELD("program_header_count","uint16",44,2,SX_COUNT_PROP),
 SX_FIELD("section_header_size","uint16",46,2,SX_SIZE),
 SX_FIELD("section_header_count","uint16",48,2,SX_COUNT_PROP),
 SX_FIELD("section_names_index","uint16",50,2,SX_ID),
};
const sx_layout sxexm_cgc_header_be = {UINT32_C(0x602b0027),"cgc_header_be",sxexm_cgc_header_be_fields,SX_COUNT(sxexm_cgc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_cgc_program_header_le_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("virtual_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("physical_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
 SX_FIELD("memory_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",28,4,SX_SIZE),
};
const sx_layout sxexm_cgc_program_header_le = {UINT32_C(0x602b0028),"cgc_program_header_le",sxexm_cgc_program_header_le_fields,SX_COUNT(sxexm_cgc_program_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_program_header_be_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("virtual_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("physical_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
 SX_FIELD("memory_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",28,4,SX_SIZE),
};
const sx_layout sxexm_cgc_program_header_be = {UINT32_C(0x602b0029),"cgc_program_header_be",sxexm_cgc_program_header_be_fields,SX_COUNT(sxexm_cgc_program_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_cgc_section_header_le_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint32",4,4,SX_ID),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("link","uint32",24,4,SX_ID),
 SX_FIELD("info","uint32",28,4,SX_NONE),
 SX_FIELD("alignment","uint32",32,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",36,4,SX_SIZE),
};
const sx_layout sxexm_cgc_section_header_le = {UINT32_C(0x602b002a),"cgc_section_header_le",sxexm_cgc_section_header_le_fields,SX_COUNT(sxexm_cgc_section_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_section_header_be_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint32",4,4,SX_ID),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("link","uint32",24,4,SX_ID),
 SX_FIELD("info","uint32",28,4,SX_NONE),
 SX_FIELD("alignment","uint32",32,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",36,4,SX_SIZE),
};
const sx_layout sxexm_cgc_section_header_be = {UINT32_C(0x602b002b),"cgc_section_header_be",sxexm_cgc_section_header_be_fields,SX_COUNT(sxexm_cgc_section_header_be_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_cgc(sx_context*c){uint8_t h[52];if(!sxexm_read(c,0,h,52))return false;bool be=h[5]==2;if(!sxexm_add(c,be?&sxexm_cgc_header_be:&sxexm_cgc_header_le,0))return false;for(unsigned t=0;t<2;t++){uint64_t p=sxexm32(h+(t?32:28),be),stride=sxexm16(h+(t?46:42),be),n=sxexm16(h+(t?48:44),be),minimum=t?40:32;if(n>SXEXM_LIMIT||stride<minimum||!sxexm_span(c,p,n*stride))continue;const sx_layout*l=t?(be?&sxexm_cgc_section_header_be:&sxexm_cgc_section_header_le):(be?&sxexm_cgc_program_header_be:&sxexm_cgc_program_header_le);for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++)if(!sxexm_add(c,l,p+i*stride))return false;}return true;}
bool sx_cgc_build(sx_context*c)
{
bool ok=false;
ok=sxexm_cgc(c);
return ok&&sxexm_finish(c);
}
