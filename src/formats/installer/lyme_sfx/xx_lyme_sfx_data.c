/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lyme SFX data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_lyme_footer_fields[]={
 SX_FIELD("member_count","uint32le",0,4,SX_COUNT_PROP),
 SX_FIELD("signature","char[14]",4,14,SX_SIGNATURE),
};
const sx_layout sxir_lyme_footer={0x60800031U,"lyme_footer",sxir_lyme_footer_fields,SX_COUNT(sxir_lyme_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_member_fields[]={
 SX_FIELD("file_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("stored_size","uint32le",8,4,SX_SIZE),
};
const sx_layout sxir_lyme_member={0x60800032U,"lyme_member",sxir_lyme_member_fields,SX_COUNT(sxir_lyme_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_name_length_fields[]={
 SX_FIELD("name_size","uint32le",0,4,SX_SIZE),
};
const sx_layout sxir_lyme_name_length={0x60800033U,"lyme_name_length",sxir_lyme_name_length_fields,SX_COUNT(sxir_lyme_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_zero_sentinel_fields[]={
 SX_FIELD("zero","uint32le",0,4,SX_RESERVED),
};
const sx_layout sxir_lyme_zero_sentinel={0x6080003dU,"lyme_zero_sentinel",sxir_lyme_zero_sentinel_fields,SX_COUNT(sxir_lyme_zero_sentinel_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_lyme(sxir_view*v)
{uint64_t end=v->c->size;if(end<18)return false;uint64_t at=end-18,count;if(!sxir_eq(v,at+4,"1.10!LYME_SFX!",14,end)||!IR_U(at,4,count,end)||!count||count>65536||!IR_ROW(lyme_footer,at,end))return false;
 if(at>=12){uint64_t n,kind,zero;if(!IR_U(at-8,4,n,end)||!IR_U(at-4,4,kind,end))return false;if((kind==1||kind==3)&&n<=4096&&n<=at-12&&IR_U(at-12-n,4,zero,end)&&!zero){if(!IR_ROW(lyme_zero_sentinel,at-12-n,end)||!sxir_emit(v,&sxir_installer_name,at-8-n,n,end)||!IR_ROW(lyme_label,at-8,end))return false;at-=12+n;}}
 for(uint64_t i=0;i<count;i++){uint64_t n,offset,size;if(at<4||!IR_U(at-4,4,n,end)||!n||n>4096||n>at-4||at-4-n<12||!IR_ROW(lyme_name_length,at-4,end))return false;at-=4+n;if(!sxir_emit(v,&sxir_installer_name,at,n,end))return false;at-=12;if(!IR_ROW(lyme_member,at,end)||!IR_U(at,4,offset,end)||!IR_U(at+8,4,size,end)||!sxir_span(v,offset,size,at))return false;}return true;}
bool sx_lyme_sfx_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_lyme(v);
}
#undef IR_ROW
#undef IR_U
