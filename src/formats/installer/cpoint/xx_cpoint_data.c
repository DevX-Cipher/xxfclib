/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CPOINT data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_cpoint_setup_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_NONE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("payload_size","uint32",5,4,SX_SIZE),
 SX_FIELD("reserved2","uint32",9,4,SX_NONE),
};
const sx_layout sxap_cpoint_setup = {UINT32_C(0x60720025),"cpoint_setup",sxap_cpoint_setup_fields,SX_COUNT(sxap_cpoint_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxap_cpoint_file_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_NONE),
 SX_FIELD("payload_size","uint32",1,4,SX_SIZE),
 SX_FIELD("name_size","uint32",5,4,SX_SIZE),
 SX_FIELD("metadata","uint32",9,4,SX_NONE),
};
const sx_layout sxap_cpoint_file = {UINT32_C(0x60720026),"cpoint_file",sxap_cpoint_file_fields,SX_COUNT(sxap_cpoint_file_fields),SX_LE};
static const xx_data_struct_field_desc sxap_cpoint_footer_fields[] = {
 SX_FIELD("footer","uint32",0,4,SX_NONE),
};
const sx_layout sxap_cpoint_footer = {UINT32_C(0x60720027),"cpoint_footer",sxap_cpoint_footer_fields,SX_COUNT(sxap_cpoint_footer_fields),SX_LE};
#define SXAP_LIMIT 20000U
static bool sxap_cpoint(sx_context*c){uint64_t p=0;for(size_t work=0;work<SXAP_LIMIT&&sxap_span(c,p,13);work++){uint64_t kind,z,n;if(!sxap_word(c,p,1,false,&kind))return false;if(kind==3){if(!sxap_word(c,p+1,4,false,&z)||!sxap_word(c,p+5,4,false,&n)||!sxap_add(c,&sxap_cpoint_file,p)||!sxap_span(c,p+13,n)||!sxap_text(c,&sxap_archivepackages_name,p+13,n,false))return false;p+=13+n;if(!sxap_span(c,p,z+4)||!sxap_add(c,&sxap_cpoint_footer,p+z))return true;p+=z+4;}else{if(!sxap_word(c,p+5,4,false,&z)||!sxap_add(c,&sxap_cpoint_setup,p))return false;p+=13;if(!sxap_span(c,p,z))return true;p+=z;}}return true;}
bool sx_cpoint_build(sx_context*c)
{
 return sxap_cpoint(c);
}
