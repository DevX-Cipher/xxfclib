/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VisualWare data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_visualware_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("unknown_10","uint8[8]",16,8,SX_NONE),
 SX_FIELD("stored_size","uint32le",24,4,SX_SIZE),
};
const sx_layout sxir_visualware_header={0x6080002eU,"visualware_header",sxir_visualware_header_fields,SX_COUNT(sxir_visualware_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_visualware_legacy_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("stored_size","uint32le",16,4,SX_SIZE),
};
const sx_layout sxir_visualware_legacy_header={0x6080002fU,"visualware_legacy_header",sxir_visualware_legacy_header_fields,SX_COUNT(sxir_visualware_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_visualware_legacy_data_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("stored_size_with_length","uint32le",16,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",20,4,SX_SIZE),
};
const sx_layout sxir_visualware_legacy_data_header={0x60800030U,"visualware_legacy_data_header",sxir_visualware_legacy_data_header_fields,SX_COUNT(sxir_visualware_legacy_data_header_fields),SX_LE};
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_visualware(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;bool legacy=false;for(unsigned i=0;i<3;i++){const char*tag=i==0?"\\]_B":i==1?"\\]_V":"\\]_Z";if(!sxir_eq(v,at,"JKMNPQSTVWYZ",12,end)||!sxir_eq(v,at+12,tag,4,end))return false;if(!i)legacy=sxir_eq(v,at+20,"\xca\xfe\xba\xbe",4,end);uint64_t n,z=legacy?(i==2?24:20):28;if(!IR_U(at+(legacy?16:24),4,n,end))return false;if(legacy&&i==2){if(n<4)return false;n-=4;}if(!sxir_row(v,legacy?(i==2?&sxir_visualware_legacy_data_header:&sxir_visualware_legacy_header):&sxir_visualware_header,at,end)||!n||!sxir_span(v,at+z,n,end))return false;at+=z+n;if(i<2){uint64_t pad=(16-(at&15))&15;if(!sxir_span(v,at,pad,end))return false;at+=pad;}}return true;}
bool sx_visualware_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_visualware(v);
}
#undef IR_U
