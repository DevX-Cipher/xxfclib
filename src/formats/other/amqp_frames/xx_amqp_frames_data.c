/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMQP FRAMES data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_amqp_protocol_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("protocol_id","uint8",4,1,SX_ID),
 SX_FIELD("major_version","uint8",5,1,SX_ID),
 SX_FIELD("minor_version","uint8",6,1,SX_ID),
 SX_FIELD("revision","uint8",7,1,SX_ID),
};
const sx_layout sxnm_amqp_protocol_header={UINT32_C(0x60260081),"amqp_protocol_header",sxnm_amqp_protocol_header_fields,SX_COUNT(sxnm_amqp_protocol_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_method_header_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("method_id","uint16",2,2,SX_ID),
};
const sx_layout sxnm_amqp_method_header={UINT32_C(0x60260083),"amqp_method_header",sxnm_amqp_method_header_fields,SX_COUNT(sxnm_amqp_method_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_frame_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxnm_amqp_frame_end={UINT32_C(0x60260085),"amqp_frame_end",sxnm_amqp_frame_end_fields,SX_COUNT(sxnm_amqp_frame_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_publish_prefix_fields[]={
 SX_FIELD("reserved_ticket","uint16",0,2,SX_RESERVED),
};
const sx_layout sxnm_amqp_publish_prefix={UINT32_C(0x60260086),"amqp_publish_prefix",sxnm_amqp_publish_prefix_fields,SX_COUNT(sxnm_amqp_publish_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_publish_flags_fields[]={
 SX_FIELD("mandatory_and_immediate","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnm_amqp_publish_flags={UINT32_C(0x60260087),"amqp_publish_flags",sxnm_amqp_publish_flags_fields,SX_COUNT(sxnm_amqp_publish_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_close_code_fields[]={
 SX_FIELD("reply_code","uint16",0,2,SX_ID),
};
const sx_layout sxnm_amqp_close_code={UINT32_C(0x60260088),"amqp_close_code",sxnm_amqp_close_code_fields,SX_COUNT(sxnm_amqp_close_code_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_close_method_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("method_id","uint16",2,2,SX_ID),
};
const sx_layout sxnm_amqp_close_method={UINT32_C(0x60260089),"amqp_close_method",sxnm_amqp_close_method_fields,SX_COUNT(sxnm_amqp_close_method_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_short_string_fields[]={
 SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_amqp_short_string={UINT32_C(0x6026008A),"amqp_short_string",sxnm_amqp_short_string_fields,SX_COUNT(sxnm_amqp_short_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_table_length_fields[]={
 SX_FIELD("table_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxnm_amqp_table_length={UINT32_C(0x6026008B),"amqp_table_length",sxnm_amqp_table_length_fields,SX_COUNT(sxnm_amqp_table_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxnm_amqp_uint8={UINT32_C(0x6026008D),"amqp_uint8",sxnm_amqp_uint8_fields,SX_COUNT(sxnm_amqp_uint8_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxnm_amqp_int8={UINT32_C(0x6026008E),"amqp_int8",sxnm_amqp_int8_fields,SX_COUNT(sxnm_amqp_int8_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxnm_amqp_uint16={UINT32_C(0x6026008F),"amqp_uint16",sxnm_amqp_uint16_fields,SX_COUNT(sxnm_amqp_uint16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxnm_amqp_int16={UINT32_C(0x60260090),"amqp_int16",sxnm_amqp_int16_fields,SX_COUNT(sxnm_amqp_int16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxnm_amqp_uint32={UINT32_C(0x60260091),"amqp_uint32",sxnm_amqp_uint32_fields,SX_COUNT(sxnm_amqp_uint32_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxnm_amqp_int32={UINT32_C(0x60260092),"amqp_int32",sxnm_amqp_int32_fields,SX_COUNT(sxnm_amqp_int32_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxnm_amqp_uint64={UINT32_C(0x60260093),"amqp_uint64",sxnm_amqp_uint64_fields,SX_COUNT(sxnm_amqp_uint64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxnm_amqp_int64={UINT32_C(0x60260094),"amqp_int64",sxnm_amqp_int64_fields,SX_COUNT(sxnm_amqp_int64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_boolean_fields[]={
 SX_FIELD("value","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnm_amqp_boolean={UINT32_C(0x60260095),"amqp_boolean",sxnm_amqp_boolean_fields,SX_COUNT(sxnm_amqp_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_long_string_fields[]={
 SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxnm_amqp_long_string={UINT32_C(0x6026009A),"amqp_long_string",sxnm_amqp_long_string_fields,SX_COUNT(sxnm_amqp_long_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_priority_fields[]={
 SX_FIELD("priority","uint8",0,1,SX_NONE),
};
const sx_layout sxnm_amqp_priority={UINT32_C(0x6026009C),"amqp_priority",sxnm_amqp_priority_fields,SX_COUNT(sxnm_amqp_priority_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_aq_short(sxnm_view *v,size_t *at,size_t end){if(!SN_ROW(amqp_short_string,*at,end))return false;unsigned n=v->p[(*at)++];if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}
static bool sxnm_aq_table(sxnm_view *v,size_t *at,size_t end,unsigned depth,bool array);
static bool sxnm_aq_value(sxnm_view *v,size_t *at,size_t end,unsigned depth)
{
 if(!SN_ROW(amqp_field_type,*at,end))return false;unsigned type=v->p[(*at)++];const sx_layout *l=NULL;
 switch(type){case 't':l=&sxnm_amqp_boolean;break;case 'b':l=&sxnm_amqp_int8;break;case 'B':l=&sxnm_amqp_uint8;break;case 'U':l=&sxnm_amqp_int16;break;case 'u':l=&sxnm_amqp_uint16;break;case 'I':l=&sxnm_amqp_int32;break;case 'i':l=&sxnm_amqp_uint32;break;case 'L':l=&sxnm_amqp_int64;break;case 'l':l=&sxnm_amqp_uint64;break;case 'f':l=&sxnm_amqp_float_bits;break;case 'd':l=&sxnm_amqp_double_bits;break;case 'D':l=&sxnm_amqp_decimal;break;case 'T':l=&sxnm_amqp_timestamp;break;case 'V':return true;case 's':return sxnm_aq_short(v,at,end);case 'A':case 'F':return sxnm_aq_table(v,at,end,depth+1,type=='A');case 'S':case 'x':{if(!SN_ROW(amqp_long_string,*at,end))return false;size_t n=sxnm_u32(v->p+*at);*at+=4;if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}default:return false;}
 if(!sxnm_row(v,l,*at,end))return false;const xx_data_struct_field_desc *f=l->fields+l->field_count-1;*at+=(size_t)(f->rel_offset+f->size);return true;
}
static bool sxnm_aq_table(sxnm_view *v,size_t *at,size_t end,unsigned depth,bool array)
{
 if(depth>32||!SN_ROW(amqp_table_length,*at,end))return false;size_t n=sxnm_u32(v->p+*at);*at+=4;if(!sxnm_need(v,*at,n,end))return false;size_t stop=*at+n;
 while(*at<stop){if(!array&&!sxnm_aq_short(v,at,stop))return false;if(!sxnm_aq_value(v,at,stop,depth))return false;}return true;
}
static bool sxnm_amqp(sxnm_view *v)
{
 if(!SN_ROW(amqp_protocol_header,0,v->n))return false;size_t at=8;
 while(at<v->n){if(!SN_ROW(amqp_frame_header,at,v->n))return false;unsigned type=v->p[at];size_t n=sxnm_u32(v->p+at+3);at+=7;if(!sxnm_need(v,at,(uint64_t)n+1,v->n))return false;size_t end=at+n;if(!SN_ROW(amqp_frame_end,end,v->n))return false;
  if(type==1){if(!SN_ROW(amqp_method_header,at,end))return false;unsigned cl=sxnm_u16(v->p+at),me=sxnm_u16(v->p+at+2);at+=4;
   if(cl==20&&me==10){if(!sxnm_aq_short(v,&at,end))return false;}
   else if(cl==60&&me==40){if(!SN_ROW(amqp_publish_prefix,at,end))return false;at+=2;if(!sxnm_aq_short(v,&at,end)||!sxnm_aq_short(v,&at,end)||!SN_ROW(amqp_publish_flags,at,end))return false;at++;}
   else if(cl==10&&me==50){if(!SN_ROW(amqp_close_code,at,end))return false;at+=2;if(!sxnm_aq_short(v,&at,end)||!SN_ROW(amqp_close_method,at,end))return false;at+=4;}else return false;
   if(at!=end)return false;
  }else if(type==2){if(!SN_ROW(amqp_content_header,at,end))return false;unsigned flags=sxnm_u16(v->p+at+12);at+=14;
   for(int bit=15;bit>=2;bit--){if(!(flags&(1U<<bit)))continue;if(bit==13){if(!sxnm_aq_table(v,&at,end,0,false))return false;}else if(bit==12||bit==11){if(!sxnm_row(v,bit==12?&sxnm_amqp_delivery_mode:&sxnm_amqp_priority,at,end))return false;at++;}else if(bit==6){if(!SN_ROW(amqp_timestamp,at,end))return false;at+=8;}else if(!sxnm_aq_short(v,&at,end))return false;}if(at!=end)return false;
  }else if(type!=3&&type!=8)return false;at=end+1;
 }return true;
}
bool sx_amqp_frames_build(sxnm_view*v)
{
 return sxnm_amqp(v);
}
#undef SN_ROW
