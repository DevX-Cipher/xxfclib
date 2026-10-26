/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SoftPaq 4 SFX data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_softpaq4_descriptor_0_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32le",4,4,SX_FLAGS),
 SX_FIELD("record_0_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("record_0_offset","uint32le",12,4,SX_OFFSET),
 SX_FIELD("record_1_size","uint32le",16,4,SX_SIZE),
 SX_FIELD("record_1_offset","uint32le",20,4,SX_OFFSET),
 SX_FIELD("record_2_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("record_2_offset","uint32le",28,4,SX_OFFSET),
 SX_FIELD("record_3_size","uint32le",32,4,SX_SIZE),
 SX_FIELD("record_3_offset","uint32le",36,4,SX_OFFSET),
 SX_FIELD("unknown_tail","uint8[24]",40,24,SX_NONE),
};
const sx_layout sxir_softpaq4_descriptor_0={0x60800036U,"softpaq4_descriptor_0",sxir_softpaq4_descriptor_0_fields,SX_COUNT(sxir_softpaq4_descriptor_0_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_descriptor_8_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32le",4,4,SX_FLAGS),
 SX_FIELD("unknown_08","uint8[4]",8,4,SX_NONE),
 SX_FIELD("record_0_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("record_0_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("record_1_size","uint32le",20,4,SX_SIZE),
 SX_FIELD("record_1_offset","uint32le",24,4,SX_OFFSET),
 SX_FIELD("record_2_size","uint32le",28,4,SX_SIZE),
 SX_FIELD("record_2_offset","uint32le",32,4,SX_OFFSET),
 SX_FIELD("record_3_size","uint32le",36,4,SX_SIZE),
 SX_FIELD("record_3_offset","uint32le",40,4,SX_OFFSET),
 SX_FIELD("record_4_size","uint32le",44,4,SX_SIZE),
 SX_FIELD("record_4_offset","uint32le",48,4,SX_OFFSET),
 SX_FIELD("unknown_tail","uint8[12]",52,12,SX_NONE),
};
const sx_layout sxir_softpaq4_descriptor_8={0x60800037U,"softpaq4_descriptor_8",sxir_softpaq4_descriptor_8_fields,SX_COUNT(sxir_softpaq4_descriptor_8_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_name_length_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxir_softpaq4_name_length={0x60800038U,"softpaq4_name_length",sxir_softpaq4_name_length_fields,SX_COUNT(sxir_softpaq4_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_footer_fields[]={
 SX_FIELD("unknown_00","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
};
const sx_layout sxir_softpaq4_footer={0x60800039U,"softpaq4_footer",sxir_softpaq4_footer_fields,SX_COUNT(sxir_softpaq4_footer_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_softpaq4(sxir_view*v)
{uint64_t end=v->c->size,pages,last,image,at,flags;if(!sxir_eq(v,0,"MZ",2,end)||!IR_U(4,2,pages,end)||!pages||!IR_U(2,2,last,end)||last>511)return false;image=(pages-1)*512+(last?last:512);if(image>=end||!sxir_find(v,image,end<16777216?end:16777216,"!3PS",4,false,&at)||!IR_U(at+4,4,flags,end)||(flags!=0&&flags!=8)||!sxir_row(v,flags?&sxir_softpaq4_descriptor_8:&sxir_softpaq4_descriptor_0,at,end))return false;
 uint64_t first=flags?12:8,count=flags?5:4,previous=at+64;for(uint64_t i=0;i<count;i++){uint64_t z,off;if(!IR_U(at+first+8*i,4,z,end)||!IR_U(at+first+8*i+4,4,off,end)||off!=previous||!sxir_span(v,off,z,end))return false;previous=off+z;if(i==0||i>=count-2){uint64_t n;if(!z||!IR_U(off,1,n,end)||!n||n+1>=z||!IR_ROW(softpaq4_name_length,off,previous)||!sxir_emit(v,&sxir_installer_name,off+1,n,previous))return false;}else if(z&&!sxir_emit(v,&sxir_installer_name,off,z,previous))return false;}
 if(previous==end)return true;return end-previous==8&&sxir_eq(v,previous+4,"\x12\xef\xcd\xab",4,end)&&IR_ROW(softpaq4_footer,previous,end);}
bool sx_sfx_softpaq4_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_softpaq4(v);
}
#undef IR_ROW
#undef IR_U
