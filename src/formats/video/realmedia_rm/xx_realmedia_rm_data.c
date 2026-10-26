/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * REALMEDIA RM data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_rmf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("object_version","uint16",8,2,SX_ID),
 SX_FIELD("file_version","uint32",10,4,SX_ID),
 SX_FIELD("header_count","uint32",14,4,SX_COUNT_PROP),
};
const sx_layout sxnx_rmf_header={UINT32_C(0x603200DD),"rmf_header",sxnx_rmf_header_fields,SX_COUNT(sxnx_rmf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_object_fields[]={
 SX_FIELD("object_id","bytes",0,4,SX_ID),
 SX_FIELD("object_size","uint32",4,4,SX_SIZE),
 SX_FIELD("object_version","uint16",8,2,SX_ID),
};
const sx_layout sxnx_rm_object={UINT32_C(0x603200DE),"rm_object",sxnx_rm_object_fields,SX_COUNT(sxnx_rm_object_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_prop_fields[]={
 SX_FIELD("max_bit_rate","uint32",0,4,SX_NONE),
 SX_FIELD("average_bit_rate","uint32",4,4,SX_NONE),
 SX_FIELD("max_packet_size","uint32",8,4,SX_SIZE),
 SX_FIELD("average_packet_size","uint32",12,4,SX_SIZE),
 SX_FIELD("packet_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("duration_ms","uint32",20,4,SX_NONE),
 SX_FIELD("preroll_ms","uint32",24,4,SX_NONE),
 SX_FIELD("index_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("stream_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
};
const sx_layout sxnx_rm_prop={UINT32_C(0x603200DF),"rm_prop",sxnx_rm_prop_fields,SX_COUNT(sxnx_rm_prop_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_title_length_fields[]={
 SX_FIELD("title_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_rm_title_length={UINT32_C(0x603200E0),"rm_title_length",sxnx_rm_title_length_fields,SX_COUNT(sxnx_rm_title_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_author_length_fields[]={
 SX_FIELD("author_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_rm_author_length={UINT32_C(0x603200E1),"rm_author_length",sxnx_rm_author_length_fields,SX_COUNT(sxnx_rm_author_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_copyright_length_fields[]={
 SX_FIELD("copyright_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_rm_copyright_length={UINT32_C(0x603200E2),"rm_copyright_length",sxnx_rm_copyright_length_fields,SX_COUNT(sxnx_rm_copyright_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_comment_length_fields[]={
 SX_FIELD("comment_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_rm_comment_length={UINT32_C(0x603200E3),"rm_comment_length",sxnx_rm_comment_length_fields,SX_COUNT(sxnx_rm_comment_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_mdpr_fields[]={
 SX_FIELD("stream_number","uint16",0,2,SX_ID),
 SX_FIELD("max_bit_rate","uint32",2,4,SX_NONE),
 SX_FIELD("average_bit_rate","uint32",6,4,SX_NONE),
 SX_FIELD("max_packet_size","uint32",10,4,SX_SIZE),
 SX_FIELD("average_packet_size","uint32",14,4,SX_SIZE),
 SX_FIELD("start_time_ms","uint32",18,4,SX_NONE),
 SX_FIELD("preroll_ms","uint32",22,4,SX_NONE),
 SX_FIELD("duration_ms","uint32",26,4,SX_NONE),
};
const sx_layout sxnx_rm_mdpr={UINT32_C(0x603200E4),"rm_mdpr",sxnx_rm_mdpr_fields,SX_COUNT(sxnx_rm_mdpr_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_name_length_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_rm_name_length={UINT32_C(0x603200E5),"rm_name_length",sxnx_rm_name_length_fields,SX_COUNT(sxnx_rm_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_rm_mime_length_fields[]={
 SX_FIELD("mime_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_rm_mime_length={UINT32_C(0x603200E6),"rm_mime_length",sxnx_rm_mime_length_fields,SX_COUNT(sxnx_rm_mime_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_rm_specific_length_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxnx_rm_specific_length={UINT32_C(0x603200E7),"rm_specific_length",sxnx_rm_specific_length_fields,SX_COUNT(sxnx_rm_specific_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_video_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("signature","bytes",4,4,SX_SIGNATURE),
 SX_FIELD("codec_id","bytes",8,4,SX_ID),
 SX_FIELD("width","uint16",12,2,SX_NONE),
 SX_FIELD("height","uint16",14,2,SX_NONE),
 SX_FIELD("bits_per_pixel","uint16",16,2,SX_NONE),
 SX_FIELD("pad_width","uint16",18,2,SX_NONE),
 SX_FIELD("pad_height","uint16",20,2,SX_NONE),
 SX_FIELD("frame_rate_fixed","uint32",22,4,SX_NONE),
};
const sx_layout sxnx_rm_video={UINT32_C(0x603200E8),"rm_video",sxnx_rm_video_fields,SX_COUNT(sxnx_rm_video_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_audio_prefix_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("revision","uint16",6,2,SX_ID),
};
const sx_layout sxnx_rm_audio_prefix={UINT32_C(0x603200E9),"rm_audio_prefix",sxnx_rm_audio_prefix_fields,SX_COUNT(sxnx_rm_audio_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_data_fields[]={
 SX_FIELD("packet_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("next_data_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxnx_rm_data={UINT32_C(0x603200EA),"rm_data",sxnx_rm_data_fields,SX_COUNT(sxnx_rm_data_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_packet_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("packet_size","uint16",2,2,SX_SIZE),
 SX_FIELD("stream_number","uint16",4,2,SX_ID),
 SX_FIELD("timestamp_ms","uint32",6,4,SX_NONE),
 SX_FIELD("reserved","uint8",10,1,SX_RESERVED),
 SX_FIELD("flags","uint8",11,1,SX_FLAGS),
};
const sx_layout sxnx_rm_packet={UINT32_C(0x603200EB),"rm_packet",sxnx_rm_packet_fields,SX_COUNT(sxnx_rm_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_index_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("stream_number","uint16",4,2,SX_ID),
 SX_FIELD("next_index_offset","uint32",6,4,SX_OFFSET),
};
const sx_layout sxnx_rm_index={UINT32_C(0x603200EC),"rm_index",sxnx_rm_index_fields,SX_COUNT(sxnx_rm_index_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_index_entry_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("timestamp_ms","uint32",2,4,SX_NONE),
 SX_FIELD("packet_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("packet_number","uint32",10,4,SX_ID),
};
const sx_layout sxnx_rm_index_entry={UINT32_C(0x603200ED),"rm_index_entry",sxnx_rm_index_entry_fields,SX_COUNT(sxnx_rm_index_entry_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_rm(sxnx_view*v)
{if(!SN_ROW(rmf_header,0,v->n))return false;size_t p=18;unsigned work=0;while(p<v->n){if(++work>20||!SN_ROW(rm_object,p,v->n))return false;unsigned id=sxnx_u32(v->p+p,true),n=sxnx_u32(v->p+p+4,true);size_t start=p;p+=10;if(n<10)return false;
 if(id==UINT32_C(0x44415441)){if(!SN_ROW(rm_data,p,v->n))return false;unsigned count=sxnx_u32(v->p+p,true);if(count>4090)return false;p+=8;for(unsigned i=0;i<count;i++){if(!SN_ROW(rm_packet,p,v->n))return false;unsigned z=sxnx_u16(v->p+p+2,true);if(z<12||!sxnx_need(v,p,z,v->n))return false;p+=z;}if(n==(uint64_t)(p-start)+18){if(!sxnx_need(v,p,8,v->n))return false;p+=8;}else if(n!=p-start)return false;continue;}
 if(!sxnx_need(v,start,n,v->n))return false;size_t end=start+n;
 if(id==UINT32_C(0x50524f50)){if(!SN_ROW(rm_prop,p,end))return false;}else if(id==UINT32_C(0x434f4e54)){const sx_layout*l[]={&sxnx_rm_title_length,&sxnx_rm_author_length,&sxnx_rm_copyright_length,&sxnx_rm_comment_length};for(unsigned i=0;i<4;i++){if(!sxnx_row(v,l[i],p,end))return false;unsigned z=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_need(v,p,z,end))return false;p+=z;}}else if(id==UINT32_C(0x4d445052)){if(!SN_ROW(rm_mdpr,p,end))return false;p+=30;const sx_layout*l[]={&sxnx_rm_name_length,&sxnx_rm_mime_length};for(unsigned i=0;i<2;i++){if(!sxnx_row(v,l[i],p,end))return false;unsigned z=v->p[p++];if(!sxnx_need(v,p,z,end))return false;p+=z;}if(!SN_ROW(rm_specific_length,p,end))return false;unsigned z=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,z,end))return false;if(z>=12&&!xx_rt_memcmp(v->p+p+4,"VIDO",4)){if(!SN_ROW(rm_video,p,p+z))return false;}else if(!SN_ROW(rm_audio_prefix,p,p+z))return false;
 }else if(id==UINT32_C(0x494e4458)){if(!SN_ROW(rm_index,p,end)||!sxnx_table(v,&sxnx_rm_index_entry,p+10,sxnx_u32(v->p+p,true),end))return false;}p=end;}return true;}
bool sx_realmedia_rm_build(sxnx_view*v)
{
 return sxnx_rm(v);
}
#undef SN_ROW
