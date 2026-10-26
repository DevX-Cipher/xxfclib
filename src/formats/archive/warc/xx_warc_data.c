/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WARC data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_warc_version_fields[]={
 SX_FIELD("warc_version","char",0,0,SX_ID),
};
const sx_layout sxarm_warc_version={UINT32_C(0x607c0002),"warc_version",sxarm_warc_version_fields,SX_COUNT(sxarm_warc_version_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_field_name_fields[]={
 SX_FIELD("warc_field_name","char",0,0,SX_STRING),
};
const sx_layout sxarm_warc_field_name={UINT32_C(0x607c0003),"warc_field_name",sxarm_warc_field_name_fields,SX_COUNT(sxarm_warc_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_field_value_fields[]={
 SX_FIELD("warc_field_value","utf8",0,0,SX_STRING),
};
const sx_layout sxarm_warc_field_value={UINT32_C(0x607c0004),"warc_field_value",sxarm_warc_field_value_fields,SX_COUNT(sxarm_warc_field_value_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_content_length_fields[]={
 SX_FIELD("warc_content_length","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxarm_warc_content_length={UINT32_C(0x607c0005),"warc_content_length",sxarm_warc_content_length_fields,SX_COUNT(sxarm_warc_content_length_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_segment_number_fields[]={
 SX_FIELD("warc_segment_number","ascii_decimal",0,0,SX_NONE),
};
const sx_layout sxarm_warc_segment_number={UINT32_C(0x607c0006),"warc_segment_number",sxarm_warc_segment_number_fields,SX_COUNT(sxarm_warc_segment_number_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_segment_total_length_fields[]={
 SX_FIELD("warc_segment_total_length","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxarm_warc_segment_total_length={UINT32_C(0x607c0007),"warc_segment_total_length",sxarm_warc_segment_total_length_fields,SX_COUNT(sxarm_warc_segment_total_length_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_digest_fields[]={
 SX_FIELD("warc_digest","char",0,0,SXARM_CHECKSUM),
};
const sx_layout sxarm_warc_digest={UINT32_C(0x607c0008),"warc_digest",sxarm_warc_digest_fields,SX_COUNT(sxarm_warc_digest_fields),SX_LE};
static bool sxarm_warc(sx_context*c){uint64_t p=0,next,z=0;uint8_t b[4096];size_t n;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return false;if(!n){p=next;continue;}if(n!=8||!sxarm_eq(b,5,"WARC/")||!sxarm_text(c,&sxarm_warc_version,p,n,false))return false;p=next;bool length=false;uint64_t header_start=p;for(;;){if(p-header_start>1048576||!sxarm_line(c,p,b,sizeof(b),&n,&next))return false;if(!n){p=next;break;}size_t k=0;while(k<n&&b[k]!=':')k++;if(k==n||!k)return true;size_t a=k+1;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;size_t e=n;while(e>a&&(b[e-1]==' '||b[e-1]=='\t'))e--;const sx_layout*l=&sxarm_warc_field_value;if(sxarm_eq(b,k,"Content-Length")){l=&sxarm_warc_content_length;if(!sxarm_uint_text(b+a,e-a,10,&z))return true;length=true;}else if(sxarm_eq(b,k,"WARC-Segment-Number"))l=&sxarm_warc_segment_number;else if(sxarm_eq(b,k,"WARC-Segment-Total-Length"))l=&sxarm_warc_segment_total_length;else if(sxarm_eq(b,k,"WARC-Block-Digest")||sxarm_eq(b,k,"WARC-Payload-Digest"))l=&sxarm_warc_digest;if(!sxarm_text(c,&sxarm_warc_field_name,p,k,false)||!sxarm_text(c,l,p+a,e-a,false))return false;p=next;}if(!length||!sxarm_span(c,p,z))return true;p+=z;}return true;}
bool sx_warc_build(sx_context*c)
{
 return sxarm_warc(c);
}
