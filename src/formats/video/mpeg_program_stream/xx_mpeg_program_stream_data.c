/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MPEG PROGRAM STREAM data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_mpeg_start_code_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("stream_id","uint8",3,1,SX_ID),
};
const sx_layout sxnx_mpeg_start_code={UINT32_C(0x603200EE),"mpeg_start_code",sxnx_mpeg_start_code_fields,SX_COUNT(sxnx_mpeg_start_code_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_pack1_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("pack_id","uint8",3,1,SX_ID),
 SX_FIELD("scr_marker_bits","uint40",4,5,SX_FLAGS),
 SX_FIELD("mux_rate_marker_bits","uint24",9,3,SX_FLAGS),
};
const sx_layout sxnx_mpeg_pack1={UINT32_C(0x603200EF),"mpeg_pack1",sxnx_mpeg_pack1_fields,SX_COUNT(sxnx_mpeg_pack1_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pack2_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("pack_id","uint8",3,1,SX_ID),
 SX_FIELD("scr_base_extension_marker_bits","uint48",4,6,SX_FLAGS),
 SX_FIELD("mux_rate_marker_bits","uint24",10,3,SX_FLAGS),
 SX_FIELD("reserved_stuffing_length","uint8",13,1,SX_FLAGS),
};
const sx_layout sxnx_mpeg_pack2={UINT32_C(0x603200F0),"mpeg_pack2",sxnx_mpeg_pack2_fields,SX_COUNT(sxnx_mpeg_pack2_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_system_fields[]={
 SX_FIELD("rate_bound_marker_bits","uint24",0,3,SX_FLAGS),
 SX_FIELD("audio_bound_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("video_bound_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("packet_rate_restriction_reserved","uint8",5,1,SX_FLAGS),
};
const sx_layout sxnx_mpeg_system={UINT32_C(0x603200F6),"mpeg_system",sxnx_mpeg_system_fields,SX_COUNT(sxnx_mpeg_system_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_system_stream_fields[]={
 SX_FIELD("stream_id","uint8",0,1,SX_ID),
 SX_FIELD("buffer_scale_size","uint16",1,2,SX_FLAGS),
};
const sx_layout sxnx_mpeg_system_stream={UINT32_C(0x603200F7),"mpeg_system_stream",sxnx_mpeg_system_stream_fields,SX_COUNT(sxnx_mpeg_system_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_fields[]={
 SX_FIELD("version_current_next","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved_marker","uint8",1,1,SX_FLAGS),
 SX_FIELD("program_info_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxnx_mpeg_map={UINT32_C(0x603200F8),"mpeg_map",sxnx_mpeg_map_fields,SX_COUNT(sxnx_mpeg_map_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_length_fields[]={
 SX_FIELD("elementary_map_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_mpeg_map_length={UINT32_C(0x603200F9),"mpeg_map_length",sxnx_mpeg_map_length_fields,SX_COUNT(sxnx_mpeg_map_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_stream_fields[]={
 SX_FIELD("stream_type","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("descriptor_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxnx_mpeg_map_stream={UINT32_C(0x603200FA),"mpeg_map_stream",sxnx_mpeg_map_stream_fields,SX_COUNT(sxnx_mpeg_map_stream_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_ps(sxnx_view*v)
{size_t p=0;while(p<v->n){if(!sxnx_need(v,p,4,v->n))return false;unsigned kind=v->p[p+3];if(kind==0xb9){if(!SN_ROW(mpeg_start_code,p,v->n))return false;p+=4;continue;}if(kind==0xba){if(!sxnx_need(v,p,5,v->n))return false;bool one=(v->p[p+4]>>4)==2;if(!sxnx_row(v,one?&sxnx_mpeg_pack1:&sxnx_mpeg_pack2,p,v->n))return false;unsigned z=one?0:v->p[p+13]&7;p+=one?12:14;if(!sxnx_need(v,p,z,v->n))return false;p+=z;continue;}
 if(!SN_ROW(mpeg_packet,p,v->n))return false;unsigned z=sxnx_u16(v->p+p+4,true);p+=6;if(!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;
 if(kind==0xbb){if(!SN_ROW(mpeg_system,p,end)||z<6||(z-6)%3||!sxnx_table(v,&sxnx_mpeg_system_stream,p+6,(z-6)/3,end))return false;}else if(kind==0xbc){if(z<10||!SN_ROW(mpeg_map,p,end))return false;unsigned bytes=sxnx_u16(v->p+p+2,true);p+=4;if(!sxnx_need(v,p,bytes,end-4))return false;p+=bytes;if(!SN_ROW(mpeg_map_length,p,end-4))return false;bytes=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_need(v,p,bytes,end-4))return false;size_t stop=p+bytes;while(p<stop){if(!SN_ROW(mpeg_map_stream,p,stop))return false;unsigned n=sxnx_u16(v->p+p+2,true);p+=4;if(!sxnx_need(v,p,n,stop))return false;p+=n;}if(!SN_ROW(mpeg_crc,end-4,end))return false;}else if(kind==0xbd||(kind>=0xc0&&kind<=0xef)){if(!sxnx_pes(v,p,end))return false;}p=end;}return true;}
bool sx_mpeg_program_stream_build(sxnx_view*v)
{
 return sxnx_ps(v);
}
#undef SN_ROW
