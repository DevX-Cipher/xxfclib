/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * yEnc data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_transport_attribute_name_fields[]={
 SX_FIELD("transport_attribute_name","char",0,0,SX_STRING),
};
const sx_layout sxarm_transport_attribute_name={UINT32_C(0x607c000d),"transport_attribute_name",sxarm_transport_attribute_name_fields,SX_COUNT(sxarm_transport_attribute_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_attribute_value_fields[]={
 SX_FIELD("transport_attribute_value","char",0,0,SX_STRING),
};
const sx_layout sxarm_transport_attribute_value={UINT32_C(0x607c000e),"transport_attribute_value",sxarm_transport_attribute_value_fields,SX_COUNT(sxarm_transport_attribute_value_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_line_width_fields[]={
 SX_FIELD("yenc_line_width","ascii_decimal",0,0,SX_COUNT_PROP),
};
const sx_layout sxarm_yenc_line_width={UINT32_C(0x607c000f),"yenc_line_width",sxarm_yenc_line_width_fields,SX_COUNT(sxarm_yenc_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_part_number_fields[]={
 SX_FIELD("yenc_part_number","ascii_decimal",0,0,SX_NONE),
};
const sx_layout sxarm_yenc_part_number={UINT32_C(0x607c0010),"yenc_part_number",sxarm_yenc_part_number_fields,SX_COUNT(sxarm_yenc_part_number_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_total_parts_fields[]={
 SX_FIELD("yenc_total_parts","ascii_decimal",0,0,SX_COUNT_PROP),
};
const sx_layout sxarm_yenc_total_parts={UINT32_C(0x607c0011),"yenc_total_parts",sxarm_yenc_total_parts_fields,SX_COUNT(sxarm_yenc_total_parts_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_begin_position_fields[]={
 SX_FIELD("yenc_begin_position","ascii_decimal",0,0,SX_NONE),
};
const sx_layout sxarm_yenc_begin_position={UINT32_C(0x607c0012),"yenc_begin_position",sxarm_yenc_begin_position_fields,SX_COUNT(sxarm_yenc_begin_position_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_end_position_fields[]={
 SX_FIELD("yenc_end_position","ascii_decimal",0,0,SX_NONE),
};
const sx_layout sxarm_yenc_end_position={UINT32_C(0x607c0013),"yenc_end_position",sxarm_yenc_end_position_fields,SX_COUNT(sxarm_yenc_end_position_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_begin_fields[]={
 SX_FIELD("marker","char[7]",0,7,SX_SIGNATURE),
};
const sx_layout sxarm_yenc_begin={UINT32_C(0x607c003d),"yenc_begin",sxarm_yenc_begin_fields,SX_COUNT(sxarm_yenc_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_part_fields[]={
 SX_FIELD("marker","char[6]",0,6,SX_ID),
};
const sx_layout sxarm_yenc_part={UINT32_C(0x607c003e),"yenc_part",sxarm_yenc_part_fields,SX_COUNT(sxarm_yenc_part_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_end_fields[]={
 SX_FIELD("marker","char[5]",0,5,SX_ID),
};
const sx_layout sxarm_yenc_end={UINT32_C(0x607c003f),"yenc_end",sxarm_yenc_end_fields,SX_COUNT(sxarm_yenc_end_fields),SX_LE};
static bool sxarm_yenc(sx_context*c){uint64_t p=0,next;uint8_t b[4096];size_t n;bool body=false,part_allowed=false;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;unsigned head=0;const sx_layout*l=NULL;if(!body&&n>=7&&!xx_rt_memcmp(b,"=ybegin",7)){head=7;l=&sxarm_yenc_begin;}else if(part_allowed&&n>=6&&!xx_rt_memcmp(b,"=ypart",6)){head=6;l=&sxarm_yenc_part;}else if(body&&n>=5&&!xx_rt_memcmp(b,"=yend",5)){head=5;l=&sxarm_yenc_end;}if(l){if(head==7){body=true;part_allowed=true;}else if(head==6)part_allowed=false;else{body=false;part_allowed=false;}if(!sxarm_add(c,l,p))return false;size_t q=head;while(q<n){while(q<n&&(b[q]==' '||b[q]=='\t'))q++;size_t key=q;while(q<n&&b[q]!='='&&b[q]!=' '&&b[q]!='\t')q++;if(q==n||b[q]!='=')break;size_t keylen=q-key,a=++q;bool name=sxarm_eq(b+key,keylen,"name");if(name)q=n;else while(q<n&&b[q]!=' '&&b[q]!='\t')q++;l=&sxarm_transport_attribute_value;if(name)l=&sxarm_transport_filename;else if(sxarm_eq(b+key,keylen,"size"))l=&sxarm_transport_decimal_size;else if(sxarm_eq(b+key,keylen,"line"))l=&sxarm_yenc_line_width;else if(sxarm_eq(b+key,keylen,"part"))l=&sxarm_yenc_part_number;else if(sxarm_eq(b+key,keylen,"total"))l=&sxarm_yenc_total_parts;else if(sxarm_eq(b+key,keylen,"begin"))l=&sxarm_yenc_begin_position;else if(sxarm_eq(b+key,keylen,"end"))l=&sxarm_yenc_end_position;else if(sxarm_eq(b+key,keylen,"crc32")||sxarm_eq(b+key,keylen,"pcrc32"))l=&sxarm_transport_crc;if(!sxarm_text(c,&sxarm_transport_attribute_name,p+key,keylen,false)||!sxarm_numeric_text(c,l,p+a,b+a,q-a))return false;}}else part_allowed=false;p=next;}return true;}
bool sx_yenc_encoded_file_build(sx_context*c)
{
 return sxarm_yenc(c);
}
