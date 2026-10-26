/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MPEG TRANSPORT STREAM data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_ts_header_fields[]={
 SX_FIELD("sync","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("flags_pid","uint16",1,2,SX_FLAGS),
 SX_FIELD("scrambling_adaptation_counter","uint8",3,1,SX_FLAGS),
};
const sx_layout sxnx_ts_header={UINT32_C(0x603200FC),"ts_header",sxnx_ts_header_fields,SX_COUNT(sxnx_ts_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_adaptation_size_fields[]={
 SX_FIELD("data_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_ts_adaptation_size={UINT32_C(0x603200FD),"ts_adaptation_size",sxnx_ts_adaptation_size_fields,SX_COUNT(sxnx_ts_adaptation_size_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_adaptation_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnx_ts_adaptation_flags={UINT32_C(0x603200FE),"ts_adaptation_flags",sxnx_ts_adaptation_flags_fields,SX_COUNT(sxnx_ts_adaptation_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_clock_fields[]={
 SX_FIELD("base_high","uint32",0,4,SX_NONE),
 SX_FIELD("base_low_reserved_extension_high","uint8",4,1,SX_FLAGS),
 SX_FIELD("extension_low","uint8",5,1,SX_NONE),
};
const sx_layout sxnx_ts_clock={UINT32_C(0x603200FF),"ts_clock",sxnx_ts_clock_fields,SX_COUNT(sxnx_ts_clock_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_splice_fields[]={
 SX_FIELD("countdown","int8",0,1,SX_NONE),
};
const sx_layout sxnx_ts_splice={UINT32_C(0x60320100),"ts_splice",sxnx_ts_splice_fields,SX_COUNT(sxnx_ts_splice_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_private_size_fields[]={
 SX_FIELD("data_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_ts_private_size={UINT32_C(0x60320101),"ts_private_size",sxnx_ts_private_size_fields,SX_COUNT(sxnx_ts_private_size_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_pointer_fields[]={
 SX_FIELD("pointer_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_ts_pointer={UINT32_C(0x60320102),"ts_pointer",sxnx_ts_pointer_fields,SX_COUNT(sxnx_ts_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_section_fields[]={
 SX_FIELD("table_id","uint8",0,1,SX_ID),
 SX_FIELD("flags_section_length","uint16",1,2,SX_FLAGS),
 SX_FIELD("table_id_extension","uint16",3,2,SX_ID),
 SX_FIELD("version_current_next","uint8",5,1,SX_FLAGS),
 SX_FIELD("section_number","uint8",6,1,SX_ID),
 SX_FIELD("last_section_number","uint8",7,1,SX_ID),
};
const sx_layout sxnx_ts_section={UINT32_C(0x60320103),"ts_section",sxnx_ts_section_fields,SX_COUNT(sxnx_ts_section_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pat_program_fields[]={
 SX_FIELD("program_number","uint16",0,2,SX_ID),
 SX_FIELD("reserved_pid","uint16",2,2,SX_FLAGS),
};
const sx_layout sxnx_ts_pat_program={UINT32_C(0x60320104),"ts_pat_program",sxnx_ts_pat_program_fields,SX_COUNT(sxnx_ts_pat_program_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pmt_fields[]={
 SX_FIELD("reserved_pcr_pid","uint16",0,2,SX_FLAGS),
 SX_FIELD("reserved_program_info_length","uint16",2,2,SX_FLAGS),
};
const sx_layout sxnx_ts_pmt={UINT32_C(0x60320105),"ts_pmt",sxnx_ts_pmt_fields,SX_COUNT(sxnx_ts_pmt_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pmt_stream_fields[]={
 SX_FIELD("stream_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved_elementary_pid","uint16",1,2,SX_FLAGS),
 SX_FIELD("reserved_info_length","uint16",3,2,SX_FLAGS),
};
const sx_layout sxnx_ts_pmt_stream={UINT32_C(0x60320106),"ts_pmt_stream",sxnx_ts_pmt_stream_fields,SX_COUNT(sxnx_ts_pmt_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_sdt_fields[]={
 SX_FIELD("original_network_id","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint8",2,1,SX_RESERVED),
};
const sx_layout sxnx_ts_sdt={UINT32_C(0x60320107),"ts_sdt",sxnx_ts_sdt_fields,SX_COUNT(sxnx_ts_sdt_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_sdt_service_fields[]={
 SX_FIELD("service_id","uint16",0,2,SX_ID),
 SX_FIELD("eit_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("running_free_ca_descriptor_length","uint16",3,2,SX_FLAGS),
};
const sx_layout sxnx_ts_sdt_service={UINT32_C(0x60320108),"ts_sdt_service",sxnx_ts_sdt_service_fields,SX_COUNT(sxnx_ts_sdt_service_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_descriptor_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("data_bytes","uint8",1,1,SX_SIZE),
};
const sx_layout sxnx_ts_descriptor={UINT32_C(0x60320109),"ts_descriptor",sxnx_ts_descriptor_fields,SX_COUNT(sxnx_ts_descriptor_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_ts_descriptors(sxnx_view*v,size_t p,size_t end)
{while(p<end){if(!SN_ROW(ts_descriptor,p,end))return false;unsigned n=v->p[p+1];p+=2;if(!sxnx_need(v,p,n,end))return false;p+=n;}return true;}
static bool sxnx_ts(sxnx_view*v)
{if(v->n%188||v->n/188>4096)return false;unsigned pmt=8191;for(size_t at=0;at<v->n;at+=188){size_t end=at+188,p=at+4;if(!SN_ROW(ts_header,at,end))return false;unsigned pid=sxnx_u16(v->p+at+1,true)&8191,control=(v->p[at+3]>>4)&3;bool start=(v->p[at+1]&64)!=0;
 if(control&2){if(!SN_ROW(ts_adaptation_size,p,end))return false;unsigned z=v->p[p++];if(!sxnx_need(v,p,z,end))return false;size_t ae=p+z;if(z){if(!SN_ROW(ts_adaptation_flags,p,ae))return false;unsigned flags=v->p[p++];if(flags&16){if(!SN_ROW(ts_clock,p,ae))return false;p+=6;}if(flags&8){if(!SN_ROW(ts_clock,p,ae))return false;p+=6;}if(flags&4){if(!SN_ROW(ts_splice,p,ae))return false;p++;}if(flags&2){if(!SN_ROW(ts_private_size,p,ae))return false;unsigned n=v->p[p++];if(!sxnx_need(v,p,n,ae))return false;p+=n;}}p=ae;}
 if(!(control&1)||p>=end)continue;if(start&&(pid==0||pid==17||pid==pmt)){if(!SN_ROW(ts_pointer,p,end))return false;unsigned pointer=v->p[p++];if(!sxnx_need(v,p,pointer,end))return false;p+=pointer;if(!SN_ROW(ts_section,p,end))return false;unsigned z=sxnx_u16(v->p+p+1,true)&4095;if(z<9||!sxnx_need(v,p,3+z,end))return false;size_t finish=p+3+z,q=p+8;if(!SN_ROW(mpeg_crc,finish-4,finish))return false;
 if(pid==0){if(!SN_ROW(ts_pat_program,q,finish-4))return false;pmt=sxnx_u16(v->p+q+2,true)&8191;}else if(pid==17){if(!SN_ROW(ts_sdt,q,finish-4))return false;q+=3;while(q<finish-4){if(!SN_ROW(ts_sdt_service,q,finish-4))return false;unsigned n=sxnx_u16(v->p+q+3,true)&4095;q+=5;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;}}
 else{if(!SN_ROW(ts_pmt,q,finish-4))return false;unsigned n=sxnx_u16(v->p+q+2,true)&4095;q+=4;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;while(q<finish-4){if(!SN_ROW(ts_pmt_stream,q,finish-4))return false;n=sxnx_u16(v->p+q+3,true)&4095;q+=5;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;}}
 }else if(start&&pid!=8191){if(!SN_ROW(mpeg_packet,p,end)||!sxnx_pes(v,p+6,end))return false;}}
 return true;}
bool sx_mpeg_transport_stream_build(sxnx_view*v)
{
 return sxnx_ts(v);
}
#undef SN_ROW
