/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * INFTool SFX data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_inftool_header_22_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("string_04_size","uint8",4,1,SX_SIZE),
 SX_FIELD("inf_name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("flag_06","uint8",6,1,SX_FLAGS),
 SX_FIELD("string_07_size","uint8",7,1,SX_SIZE),
 SX_FIELD("field_08_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("field_0c_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("flag_10","uint8",16,1,SX_FLAGS),
 SX_FIELD("zero_11","uint8",17,1,SX_RESERVED),
 SX_FIELD("file_size","uint32le",18,4,SX_SIZE),
};
const sx_layout sxir_inftool_header_22={0x6080003aU,"inftool_header_22",sxir_inftool_header_22_fields,SX_COUNT(sxir_inftool_header_22_fields),SX_LE};
static const xx_data_struct_field_desc sxir_inftool_header_24_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("string_04_size","uint8",4,1,SX_SIZE),
 SX_FIELD("inf_name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("flag_06","uint8",6,1,SX_FLAGS),
 SX_FIELD("string_07_size","uint8",7,1,SX_SIZE),
 SX_FIELD("field_08_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("field_0c_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("flag_10","uint8",16,1,SX_FLAGS),
 SX_FIELD("zero_11","uint8",17,1,SX_RESERVED),
 SX_FIELD("flag_12","uint8",18,1,SX_FLAGS),
 SX_FIELD("obfuscated_cabinet","uint8",19,1,SX_FLAGS),
 SX_FIELD("file_size","uint32le",20,4,SX_SIZE),
};
const sx_layout sxir_inftool_header_24={0x6080003bU,"inftool_header_24",sxir_inftool_header_24_fields,SX_COUNT(sxir_inftool_header_24_fields),SX_LE};
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_inftool(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;bool legacy=sxir_eq(v,at,"MRI",3,end);if(!legacy){uint64_t dll;if(!sxir_eq(v,at,"MZ",2,end)||!sxir_pe(v,at,end,&dll,&cert)||dll<=at)return false;at=dll;}uint64_t z=legacy?22:24,declared;if(!sxir_eq(v,at,"MRI\1",4,end)||!IR_U(at+(legacy?18:20),4,declared,end)||declared!=end||!sxir_row(v,legacy?&sxir_inftool_header_22:&sxir_inftool_header_24,at,end))return false;
 uint64_t p=at+z;const unsigned offsets[]={4,5,7,8,12};for(unsigned i=0;i<5;i++){uint64_t n;if(!IR_U(at+offsets[i],i<3?1:4,n,end)||!sxir_span(v,p,n,end))return false;if(i<3&&n&&!sxir_emit(v,&sxir_installer_name,p,n,end))return false;p+=n;}return sxir_span(v,p,36,end);}
bool sx_sfx_inftool_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_inftool(v);
}
#undef IR_U
