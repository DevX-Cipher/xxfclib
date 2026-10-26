/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SuperDAT data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_superdat_group_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
};
const sx_layout sxir_superdat_group={0x6080001bU,"superdat_group",sxir_superdat_group_fields,SX_COUNT(sxir_superdat_group_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_member_fields[]={
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("name","char[260]",14,260,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",274,4,SX_SIZE),
 SX_FIELD("packed_size","uint32le",278,4,SX_SIZE),
 SX_FIELD("hour","uint8",282,1,SX_NONE),
 SX_FIELD("minute","uint8",283,1,SX_NONE),
 SX_FIELD("second","uint8",284,1,SX_NONE),
 SX_FIELD("year_since_1900","uint8",285,1,SX_NONE),
 SX_FIELD("month","uint8",286,1,SX_NONE),
 SX_FIELD("day","uint8",287,1,SX_NONE),
};
const sx_layout sxir_superdat_member={0x6080001cU,"superdat_member",sxir_superdat_member_fields,SX_COUNT(sxir_superdat_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_lh1_stream_fields[]={
 SX_FIELD("uncompressed_size","uint32le",0,4,SX_SIZE),
};
const sx_layout sxir_superdat_lh1_stream={0x6080001dU,"superdat_lh1_stream",sxir_superdat_lh1_stream_fields,SX_COUNT(sxir_superdat_lh1_stream_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_group_trailer_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown_08","uint8[3]",8,3,SX_NONE),
 SX_FIELD("unknown_checksum_bytes","uint8[4]",11,4,SX_NONE),
 SX_FIELD("trailer_size","uint16le",15,2,SX_SIZE),
};
const sx_layout sxir_superdat_group_trailer={0x6080001eU,"superdat_group_trailer",sxir_superdat_group_trailer_fields,SX_COUNT(sxir_superdat_group_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_original_footer_fields[]={
 SX_FIELD("group_size","uint32le",0,4,SX_SIZE),
};
const sx_layout sxir_superdat_original_footer={0x6080001fU,"superdat_original_footer",sxir_superdat_original_footer_fields,SX_COUNT(sxir_superdat_original_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v0_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("group_size","uint32le",17,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",21,4,SX_OFFSET),
 SX_FIELD("member_count","uint32le",25,4,SX_COUNT_PROP),
 SX_FIELD("unknown_tail","uint8[4]",29,4,SX_NONE),
};
const sx_layout sxir_superdat_footer_v0={0x60800020U,"superdat_footer_v0",sxir_superdat_footer_v0_fields,SX_COUNT(sxir_superdat_footer_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v1_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("group_size","uint32le",17,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",21,4,SX_OFFSET),
 SX_FIELD("zero_count","uint32le",25,4,SX_RESERVED),
 SX_FIELD("member_count","uint32le",29,4,SX_COUNT_PROP),
 SX_FIELD("unknown_tail","uint8[4]",33,4,SX_NONE),
};
const sx_layout sxir_superdat_footer_v1={0x60800021U,"superdat_footer_v1",sxir_superdat_footer_v1_fields,SX_COUNT(sxir_superdat_footer_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v12_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("signing_bytes","uint8[268]",17,268,SX_NONE),
 SX_FIELD("group_size","uint32le",285,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",289,4,SX_OFFSET),
 SX_FIELD("member_count","uint32le",293,4,SX_COUNT_PROP),
};
const sx_layout sxir_superdat_footer_v12={0x60800022U,"superdat_footer_v12",sxir_superdat_footer_v12_fields,SX_COUNT(sxir_superdat_footer_v12_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_manifest_170_fields[]={
 SX_FIELD("name","char[144]",0,144,SX_NONE),
 SX_FIELD("checksum","uint32le",144,4,SX_CHECKSUM),
 SX_FIELD("unknown_94","uint8[12]",148,12,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",160,4,SX_SIZE),
 SX_FIELD("unknown_a4","uint8[6]",164,6,SX_NONE),
};
const sx_layout sxir_superdat_manifest_170={0x60800023U,"superdat_manifest_170",sxir_superdat_manifest_170_fields,SX_COUNT(sxir_superdat_manifest_170_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_manifest_178_fields[]={
 SX_FIELD("name","char[144]",0,144,SX_NONE),
 SX_FIELD("checksum","uint32le",144,4,SX_CHECKSUM),
 SX_FIELD("unknown_94","uint8[12]",148,12,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",160,4,SX_SIZE),
 SX_FIELD("unknown_a4","uint8[6]",164,6,SX_NONE),
 SX_FIELD("classification","uint32le",170,4,SX_ID),
 SX_FIELD("unknown_ae","uint8[4]",174,4,SX_NONE),
};
const sx_layout sxir_superdat_manifest_178={0x60800024U,"superdat_manifest_178",sxir_superdat_manifest_178_fields,SX_COUNT(sxir_superdat_manifest_178_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_superdat(sxir_view*v)
{uint64_t end=v->c->size,pe,cert,footer=0,at=0,count=0,declared=0;unsigned kind=3;bool found=false;if(!sxir_pe(v,0,end,&pe,&cert))return false;end=cert;
 if(end>=33){uint64_t begin=end>131072?end-131072:0,scan=begin,candidate;while(end-scan>=33&&sxir_find(v,scan,end,"_SUPERDAT_HEADER\0",17,false,&candidate)){uint64_t z,start,n;if(!IR_U(candidate+17,4,z,end)||!IR_U(candidate+21,4,start,end)||!IR_U(candidate+25,4,n,end))return false;unsigned k=n?0:1;if(!n&&!IR_U(candidate+29,4,n,end))return false;if(z&&n&&n<=65536&&start<=candidate&&sxir_span(v,candidate,k?37:33,end)){footer=candidate;declared=z;at=start;count=n;kind=k;found=true;}scan=candidate+1;}}
 if(!found&&end>=297&&sxir_eq(v,end-297,"_SUPERDAT_HEADER\0",17,end)){uint64_t zero;if(!IR_U(end-280,4,zero,end)||!IR_U(end-12,4,declared,end)||!IR_U(end-8,4,at,end)||!IR_U(end-4,4,count,end))return false;if(!zero&&declared&&count&&count<65536&&at<end-297){footer=end-297;kind=2;found=true;}}
 if(!found){if(end<8||!IR_U(end-4,4,declared,end)||declared<=17||declared>end-8)return false;footer=end-4;at=end-8-declared;kind=3;}
 if(!sxir_row(v,kind==0?&sxir_superdat_footer_v0:kind==1?&sxir_superdat_footer_v1:kind==2?&sxir_superdat_footer_v12:&sxir_superdat_original_footer,footer,end))return false;
 uint64_t last_group=0,members=0;for(unsigned groups=0;;groups++){if(groups>=8||!sxir_eq(v,at,"\xef\xbe\xad\xde",4,footer)||!IR_ROW(superdat_group,at,footer))return false;last_group=at;members=0;at+=4;
  while(!sxir_eq(v,at,"NAISIGN\0",8,footer)){uint64_t z,plain,actual;if(++members>65536||!sxir_eq(v,at,"__NAILZHUFLIB\0",14,footer)||!IR_U(at+274,4,plain,footer)||!IR_U(at+278,4,z,footer)||z<4||!IR_U(at+288,4,actual,footer)||plain!=actual||!IR_ROW(superdat_member,at,footer)||!IR_ROW(superdat_lh1_stream,at+288,footer)||!sxir_span(v,at+288,z,footer))return false;at+=288+z;}
  if(!members||!IR_ROW(superdat_group_trailer,at,footer))return false;at+=17;if(!sxir_eq(v,at,"\xef\xbe\xad\xde",4,end))break;}
 if(at-last_group-4!=declared)return false;if(kind==3)return at==footer;uint64_t stride=kind==2?170:178,bootstrap=kind==2?1:2;if(members!=count+bootstrap||at>footer||footer-at!=count*stride+(kind==1?12:0))return false;return sxir_table(v,kind==2?&sxir_superdat_manifest_170:&sxir_superdat_manifest_178,at,count,footer);}
bool sx_superdat_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_superdat(v);
}
#undef IR_ROW
#undef IR_U
