/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WRZL data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_wrzl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxap_wrzl_header = {UINT32_C(0x60720013),"wrzl_header",sxap_wrzl_header_fields,SX_COUNT(sxap_wrzl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_block_size_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxap_wrzl_block_size = {UINT32_C(0x60720014),"wrzl_block_size",sxap_wrzl_block_size_fields,SX_COUNT(sxap_wrzl_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_mode_fields[] = {
 SX_FIELD("mode","uint8",0,1,SX_NONE),
};
const sx_layout sxap_wrzl_mode = {UINT32_C(0x60720015),"wrzl_mode",sxap_wrzl_mode_fields,SX_COUNT(sxap_wrzl_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_control_fields[] = {
 SX_FIELD("control_bits","uint16",0,2,SX_FLAGS),
};
const sx_layout sxap_wrzl_control = {UINT32_C(0x60720016),"wrzl_control",sxap_wrzl_control_fields,SX_COUNT(sxap_wrzl_control_fields),SX_BE};
static bool sxap_wrzl(sx_context*c){uint64_t p=8;if(!sxap_add(c,&sxap_wrzl_header,0))return false;while(sxap_span(c,p,3)){uint64_t n,mode;if(!sxap_word(c,p,2,false,&n)||!n||!sxap_word(c,p+2,1,false,&mode)||!sxap_add(c,&sxap_wrzl_block_size,p)||!sxap_add(c,&sxap_wrzl_mode,p+2))return false;p+=2;if(!sxap_span(c,p,n))return true;if(mode==0x40&&n>=3&&!sxap_add(c,&sxap_wrzl_control,p+1))return false;p+=n;}return true;}
bool sx_wrzl_build(sx_context*c)
{
 return sxap_wrzl(c);
}
