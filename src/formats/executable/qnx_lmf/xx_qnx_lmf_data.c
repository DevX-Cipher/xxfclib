/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QNX_LMF data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_qnx_record_header_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved1","uint8",1,1,SX_RESERVED),
 SX_FIELD("data_size","uint16",2,2,SX_SIZE),
 SX_FIELD("reserved2","uint16",4,2,SX_RESERVED),
};
const sx_layout sxexm_qnx_record_header = {UINT32_C(0x602b0039),"qnx_record_header",sxexm_qnx_record_header_fields,SX_COUNT(sxexm_qnx_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_module_header_fields[] = {
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("cpu","uint16",4,2,SX_ID),
 SX_FIELD("fpu","uint16",6,2,SX_ID),
 SX_FIELD("code_index","uint16",8,2,SX_ID),
 SX_FIELD("stack_index","uint16",10,2,SX_ID),
 SX_FIELD("heap_index","uint16",12,2,SX_ID),
 SX_FIELD("argv_index","uint16",14,2,SX_ID),
 SX_FIELD("spare2","uint16[4]",16,8,SX_RESERVED),
 SX_FIELD("code_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("stack_size","uint32",28,4,SX_SIZE),
 SX_FIELD("heap_size","uint32",32,4,SX_SIZE),
 SX_FIELD("image_base","uint32",36,4,SX_ADDRESS),
 SX_FIELD("spare3","uint32[2]",40,8,SX_RESERVED),
};
const sx_layout sxexm_qnx_module_header = {UINT32_C(0x602b003a),"qnx_module_header",sxexm_qnx_module_header_fields,SX_COUNT(sxexm_qnx_module_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_segment_fields[] = {
 SX_FIELD("size_and_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxexm_qnx_segment = {UINT32_C(0x602b003b),"qnx_segment",sxexm_qnx_segment_fields,SX_COUNT(sxexm_qnx_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_load_header_fields[] = {
 SX_FIELD("segment_index","uint16",0,2,SX_ID),
 SX_FIELD("segment_offset","uint32",2,4,SX_OFFSET),
};
const sx_layout sxexm_qnx_load_header = {UINT32_C(0x602b003c),"qnx_load_header",sxexm_qnx_load_header_fields,SX_COUNT(sxexm_qnx_load_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_resource_header_fields[] = {
 SX_FIELD("resource_type","uint16",0,2,SX_ID),
 SX_FIELD("spare","uint16[3]",2,6,SX_RESERVED),
};
const sx_layout sxexm_qnx_resource_header = {UINT32_C(0x602b003d),"qnx_resource_header",sxexm_qnx_resource_header_fields,SX_COUNT(sxexm_qnx_resource_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_read_write_end_fields[] = {
 SX_FIELD("verification","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("signature","uint32",2,4,SX_SIGNATURE),
};
const sx_layout sxexm_qnx_read_write_end = {UINT32_C(0x602b003e),"qnx_read_write_end",sxexm_qnx_read_write_end_fields,SX_COUNT(sxexm_qnx_read_write_end_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_image_end_fields[] = {
 SX_FIELD("spare","uint16[3]",0,6,SX_RESERVED),
};
const sx_layout sxexm_qnx_image_end = {UINT32_C(0x602b003f),"qnx_image_end",sxexm_qnx_image_end_fields,SX_COUNT(sxexm_qnx_image_end_fields),SX_LE};
#define SXEXM_LIMIT 20000U
static bool sxexm_qnx(sx_context*c){uint64_t p=0;uint8_t h[6];for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,6))break;uint64_t z=sxexm16(h+2,false);unsigned type=h[0];if(type>8||!sxexm_span(c,p+6,z))break;if(!sxexm_add(c,&sxexm_qnx_record_header,p))return false;const sx_layout*l=NULL;if(type==0&&z>=48){l=&sxexm_qnx_module_header;if(!sxexm_table(c,&sxexm_qnx_segment,p+54,(z-48)/4))return false;}else if(type==2||type==3||type==4||type==8){if(z>=6)l=&sxexm_qnx_load_header;}else if(type==6&&z>=8)l=&sxexm_qnx_resource_header;else if(type==7&&z>=6)l=&sxexm_qnx_read_write_end;else if(type==5&&z>=6)l=&sxexm_qnx_image_end;if(l&&!sxexm_add(c,l,p+6))return false;p+=6+z;if(type==5)break;}return c->count!=0;}
bool sx_qnx_lmf_build(sx_context*c)
{
bool ok=false;
ok=sxexm_qnx(c);
return ok&&sxexm_finish(c);
}
