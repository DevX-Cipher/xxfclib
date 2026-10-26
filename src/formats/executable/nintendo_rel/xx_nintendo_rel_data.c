/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NINTENDO_REL data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_rel_header_fields[] = {
 SX_FIELD("module_id","uint32",0,4,SX_ID),
 SX_FIELD("next_module_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("previous_module_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("section_table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("module_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("module_name_size","uint32",24,4,SX_SIZE),
 SX_FIELD("version","uint32",28,4,SX_ID),
 SX_FIELD("bss_size","uint32",32,4,SX_SIZE),
 SX_FIELD("relocation_table_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("import_table_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("import_table_size","uint32",44,4,SX_SIZE),
 SX_FIELD("prolog_section","uint8",48,1,SX_ID),
 SX_FIELD("epilog_section","uint8",49,1,SX_ID),
 SX_FIELD("unresolved_section","uint8",50,1,SX_ID),
 SX_FIELD("bss_section","uint8",51,1,SX_ID),
 SX_FIELD("prolog_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("epilog_offset","uint32",56,4,SX_OFFSET),
 SX_FIELD("unresolved_offset","uint32",60,4,SX_OFFSET),
};
const sx_layout sxexm_rel_header = {UINT32_C(0x602b002c),"rel_header",sxexm_rel_header_fields,SX_COUNT(sxexm_rel_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_v2_extension_fields[] = {
 SX_FIELD("section_alignment","uint32",0,4,SX_SIZE),
 SX_FIELD("bss_alignment","uint32",4,4,SX_SIZE),
};
const sx_layout sxexm_rel_v2_extension = {UINT32_C(0x602b002d),"rel_v2_extension",sxexm_rel_v2_extension_fields,SX_COUNT(sxexm_rel_v2_extension_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_v3_extension_fields[] = {
 SX_FIELD("section_alignment","uint32",0,4,SX_SIZE),
 SX_FIELD("bss_alignment","uint32",4,4,SX_SIZE),
 SX_FIELD("fix_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxexm_rel_v3_extension = {UINT32_C(0x602b002e),"rel_v3_extension",sxexm_rel_v3_extension_fields,SX_COUNT(sxexm_rel_v3_extension_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_section_fields[] = {
 SX_FIELD("offset_and_executable","uint32",0,4,SX_FLAGS),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxexm_rel_section = {UINT32_C(0x602b002f),"rel_section",sxexm_rel_section_fields,SX_COUNT(sxexm_rel_section_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_import_fields[] = {
 SX_FIELD("module_id","uint32",0,4,SX_ID),
 SX_FIELD("relocations_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxexm_rel_import = {UINT32_C(0x602b0030),"rel_import",sxexm_rel_import_fields,SX_COUNT(sxexm_rel_import_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_relocation_fields[] = {
 SX_FIELD("offset_delta","uint16",0,2,SX_OFFSET),
 SX_FIELD("relocation_type","uint8",2,1,SX_ID),
 SX_FIELD("section","uint8",3,1,SX_ID),
 SX_FIELD("addend","uint32",4,4,SX_NONE),
};
const sx_layout sxexm_rel_relocation = {UINT32_C(0x602b0031),"rel_relocation",sxexm_rel_relocation_fields,SX_COUNT(sxexm_rel_relocation_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_rel(sx_context*c){uint8_t h[64];if(!sxexm_read(c,0,h,64)||!sxexm_add(c,&sxexm_rel_header,0))return false;uint64_t v=sxexm32(h+28,true),p=sxexm32(h+40,true),n=sxexm32(h+44,true)/8;if(!sxexm_table(c,&sxexm_rel_section,sxexm32(h+16,true),sxexm32(h+12,true))||!sxexm_table(c,&sxexm_rel_import,p,n))return false;if((v==2||v==3)&&sxexm_span(c,64,v==2?8:12)&&!sxexm_add(c,v==2?&sxexm_rel_v2_extension:&sxexm_rel_v3_extension,64))return false;if(n>SXEXM_LIMIT||!sxexm_span(c,p,n*8))return true;for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++){uint64_t q;if(!sxexm_word(c,p+i*8+4,4,true,&q)||!q)continue;for(unsigned j=0;j<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;j++,q+=8){uint8_t r[8];if(!sxexm_read(c,q,r,8)||!sxexm_free(c,q,8))break;if(!sxexm_add(c,&sxexm_rel_relocation,q))return false;if(r[2]==203)break;}}return true;}
bool sx_nintendo_rel_build(sx_context*c)
{
bool ok=false;
ok=sxexm_rel(c);
return ok&&sxexm_finish(c);
}
