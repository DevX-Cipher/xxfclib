/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CBM ARC v1/v2 254-byte records data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_arc_cbm_member_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("method","uint8",1,1,SX_ID),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint24",4,3,SX_SIZE),
 SX_FIELD("block_count","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("file_type","char[1]",9,1,SX_ID),
 SX_FIELD("name_size","uint8",10,1,SX_SIZE),
};
const sx_layout sxag_arc_cbm_member = {UINT32_C(0x6025000c),"arc_cbm_member",sxag_arc_cbm_member_fields,SX_COUNT(sxag_arc_cbm_member_fields),SX_LE};
static const xx_data_struct_field_desc sxag_arc_cbm_v2_fields[] = {
 SX_FIELD("record_length","uint8",0,1,SX_SIZE),
 SX_FIELD("date","uint16",1,2,SX_NONE),
};
const sx_layout sxag_arc_cbm_v2 = {UINT32_C(0x6025000d),"arc_cbm_v2",sxag_arc_cbm_v2_fields,SX_COUNT(sxag_arc_cbm_v2_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_cbm(sx_context *c){uint8_t b[20];uint64_t p=0;if(!sxag_read(c,0,b,11))return false;if((uint64_t)c->size>265&&b[6]==0x9e&&b[7]=='('){unsigned line=sxag16(b+4,false);if(line<7||line>4096)return false;p=(uint64_t)(line-6)*254;if(line==15&&b[8]=='7')p--;}
 for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,11)||(b[0]!=1&&b[0]!=2))break;unsigned version=b[0],name=b[10];uint64_t n=(uint64_t)sxag16(b+7,false)*254,h=11+name+(version==2?3:0);if(!name||name>16||n<h||!sxag_span(c,p,n))break;if(!sxag_add(c,&sxag_arc_cbm_member,p))return false;if(version==2&&!sxag_add(c,&sxag_arc_cbm_v2,p+11+name))return false;p+=n;}
 return c->count!=0;}
bool sx_arc_cbm_build(sx_context*c)
{
 return sxag_cbm(c);
}
