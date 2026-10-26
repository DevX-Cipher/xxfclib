/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMSDB data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_vmsdb_prefix_fields[] = {
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxap_vmsdb_prefix = {UINT32_C(0x6072004a),"vmsdb_prefix",sxap_vmsdb_prefix_fields,SX_COUNT(sxap_vmsdb_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_short_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length","uint8",1,1,SX_SIZE),
};
const sx_layout sxap_vmsdb_short = {UINT32_C(0x6072004b),"vmsdb_short",sxap_vmsdb_short_fields,SX_COUNT(sxap_vmsdb_short_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_indefinite_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
};
const sx_layout sxap_vmsdb_indefinite = {UINT32_C(0x6072004c),"vmsdb_indefinite",sxap_vmsdb_indefinite_fields,SX_COUNT(sxap_vmsdb_indefinite_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_long1_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
 SX_FIELD("length","uint8",2,1,SX_SIZE),
};
const sx_layout sxap_vmsdb_long1 = {UINT32_C(0x6072004d),"vmsdb_long1",sxap_vmsdb_long1_fields,SX_COUNT(sxap_vmsdb_long1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_long2_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
 SX_FIELD("length","uint16",2,2,SX_SIZE),
};
const sx_layout sxap_vmsdb_long2 = {UINT32_C(0x6072004e),"vmsdb_long2",sxap_vmsdb_long2_fields,SX_COUNT(sxap_vmsdb_long2_fields),SX_BE};
static const xx_data_struct_field_desc sxap_vmsdb_attributes_fields[] = {
 SX_FIELD("unknown1","uint8[19]",0,19,SX_NONE),
 SX_FIELD("allocated_blocks","int32",19,4,SX_NONE),
 SX_FIELD("unknown2","uint8[8]",23,8,SX_NONE),
 SX_FIELD("last_block_bytes","uint16",31,2,SX_NONE),
 SX_FIELD("unknown_tail","uint8[138]",33,138,SX_NONE),
};
const sx_layout sxap_vmsdb_attributes = {UINT32_C(0x6072004f),"vmsdb_attributes",sxap_vmsdb_attributes_fields,SX_COUNT(sxap_vmsdb_attributes_fields),SX_LE};
#define SXAP_LIMIT 20000U
static bool sxap_vms_element(sx_context*c,uint64_t*p,unsigned depth,unsigned parent,unsigned grand){uint8_t b[4];if(depth>64||!sxap_read(c,*p,b,2))return false;unsigned tag=b[0],form=b[1];uint64_t n=0;const sx_layout*l=&sxap_vmsdb_short;unsigned width=2;if(form==128)l=&sxap_vmsdb_indefinite;else if(form==129){width=3;l=&sxap_vmsdb_long1;if(!sxap_read(c,*p,b,3))return false;n=b[2];}else if(form==130){width=4;l=&sxap_vmsdb_long2;if(!sxap_read(c,*p,b,4))return false;n=sxap_uint(b+2,2,true);}else if(form<128)n=form;else return false;if(!sxap_add(c,l,*p))return false;*p+=width;if(form==128&&tag){for(size_t work=0;work<SXAP_LIMIT;work++){if(!sxap_read(c,*p,b,2))return false;bool end=!b[0];if(!sxap_vms_element(c,p,depth+1,tag,parent))return false;if(end)return true;}return false;}if(!sxap_span(c,*p,n))return true;if(tag==4&&n==171&&parent==0xa2&&grand==0x30){if(!sxap_add(c,&sxap_vmsdb_attributes,*p))return false;}else if(tag==0x81&&parent==0x30&&!sxap_text(c,&sxap_archivepackages_name,*p,n,false))return false;*p+=n;return true;}
bool sx_vmsdb_build(sx_context*c)
{
uint64_t p=2;return sxap_add(c,&sxap_vmsdb_prefix,0)&&sxap_vms_element(c,&p,0,0,0);
}
