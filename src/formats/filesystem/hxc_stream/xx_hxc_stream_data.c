/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hxc stream data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_hxc_stream_chunk_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packet_number","uint32",8,4,SX_NONE),
};
const sx_layout sxdleg_hxc_stream_chunk = {0x6075002aU,"hxc_stream_chunk",sxdleg_hxc_stream_chunk_fields,SX_COUNT(sxdleg_hxc_stream_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_hxc_stream_metadata_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxdleg_hxc_stream_metadata = {0x6075002bU,"hxc_stream_metadata",sxdleg_hxc_stream_metadata_fields,SX_COUNT(sxdleg_hxc_stream_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_hxc_stream_io_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxdleg_hxc_stream_io = {0x6075002cU,"hxc_stream_io",sxdleg_hxc_stream_io_fields,SX_COUNT(sxdleg_hxc_stream_io_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_hxc_stream_flux_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
    SX_FIELD("pulse_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sxdleg_hxc_stream_flux = {0x6075002dU,"hxc_stream_flux",sxdleg_hxc_stream_flux_fields,SX_COUNT(sxdleg_hxc_stream_flux_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_hxc_stream_crc_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxdleg_hxc_stream_crc = {0x6075002eU,"hxc_stream_crc",sxdleg_hxc_stream_crc_fields,SX_COUNT(sxdleg_hxc_stream_crc_fields),SX_LE};
#define SXDLEG_LIMIT 24000U
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_stream(sx_context*c){uint8_t h[20];uint64_t p=0;for(unsigned i=0;i<1024&&p<(uint64_t)c->size&&c->count<SXDLEG_LIMIT;i++){if(!sxdleg_read(c,p,h,12)||xx_rt_memcmp(h,"CHKH",4))break;uint64_t z=sxdleg32(h+4,0);if(z<24||z%4||!sxdleg_span(c,p,z))break;if(!SXDLEG_ADD(c,hxc_stream_chunk,p)||!SXDLEG_ADD(c,hxc_stream_crc,p+z-4))return false;uint64_t q=p+12,end=p+z-4;for(unsigned j=0;j<64&&q<end;j++){if(end-q<8||!sxdleg_read(c,q,h,8))break;uint64_t n=sxdleg32(h+4,0);unsigned type=sxdleg32(h,0),head=type==0?8:type==1?16:type==2?20:0;if(!head||n>end-q-8||head>8+n)break;const sx_layout*l=type==0?&sxdleg_hxc_stream_metadata:type==1?&sxdleg_hxc_stream_io:&sxdleg_hxc_stream_flux;if(!sxdleg_put(c,l,q,1))return false;q+=8+n;}p+=z;}return c->count!=0;}
#undef SXDLEG_LIMIT
#undef SXDLEG_ADD
bool sx_hxc_stream_build(sx_context*c)
{
 return sxdleg_stream(c);
}
