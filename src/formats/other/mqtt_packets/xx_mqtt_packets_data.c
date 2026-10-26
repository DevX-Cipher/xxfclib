/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MQTT PACKETS data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_mqtt_string_length_fields[]={
 SX_FIELD("string_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxnm_mqtt_string_length={UINT32_C(0x6026007C),"mqtt_string_length",sxnm_mqtt_string_length_fields,SX_COUNT(sxnm_mqtt_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_packet_id_fields[]={
 SX_FIELD("packet_identifier","uint16",0,2,SX_ID),
};
const sx_layout sxnm_mqtt_packet_id={UINT32_C(0x6026007E),"mqtt_packet_id",sxnm_mqtt_packet_id_fields,SX_COUNT(sxnm_mqtt_packet_id_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_requested_qos_fields[]={
 SX_FIELD("requested_qos","uint8",0,1,SX_ID),
};
const sx_layout sxnm_mqtt_requested_qos={UINT32_C(0x6026007F),"mqtt_requested_qos",sxnm_mqtt_requested_qos_fields,SX_COUNT(sxnm_mqtt_requested_qos_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_suback_result_fields[]={
 SX_FIELD("result_code","uint8",0,1,SX_ID),
};
const sx_layout sxnm_mqtt_suback_result={UINT32_C(0x60260080),"mqtt_suback_result",sxnm_mqtt_suback_result_fields,SX_COUNT(sxnm_mqtt_suback_result_fields),SX_BE};
static const sx_layout *const sxnm_mqtt_remaining_rows[]={&sxnm_mqtt_remaining_length_1,&sxnm_mqtt_remaining_length_2,&sxnm_mqtt_remaining_length_3,&sxnm_mqtt_remaining_length_4};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_mq_string(sxnm_view *v,size_t *at,size_t end){if(!SN_ROW(mqtt_string_length,*at,end))return false;size_t n=sxnm_u16(v->p+*at);*at+=2;if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}
static bool sxnm_mqtt(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(mqtt_control_byte,at,v->n))return false;unsigned flags=v->p[at++],type=flags>>4;size_t start=at,bytes=0;unsigned w=0;
  for(;w<4;w++){if(!sxnm_need(v,at,1,v->n))return false;unsigned b=v->p[at++];bytes|=(size_t)(b&127)<<(7*w);if(!(b&128))break;}if(w==4||!sxnm_row(v,sxnm_mqtt_remaining_rows[w],start,v->n)||!sxnm_need(v,at,bytes,v->n))return false;size_t end=at+bytes;
  if(type==1){if(!SN_ROW(mqtt_connect,at,end))return false;unsigned f=v->p[at+7];at+=10;if(!sxnm_mq_string(v,&at,end))return false;if(f&4){if(!sxnm_mq_string(v,&at,end)||!sxnm_mq_string(v,&at,end))return false;}if(f&128&&!sxnm_mq_string(v,&at,end))return false;if(f&64&&!sxnm_mq_string(v,&at,end))return false;}
  else if(type==2){if(!SN_ROW(mqtt_connack,at,end))return false;at+=2;}
  else if(type==3){if(!sxnm_mq_string(v,&at,end))return false;if((flags>>1)&3){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;}at=end;}
  else if(type==8||type==9||type==10){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;while(at<end){if(type==9){if(!SN_ROW(mqtt_suback_result,at,end))return false;at++;}else{if(!sxnm_mq_string(v,&at,end))return false;if(type==8){if(!SN_ROW(mqtt_requested_qos,at,end))return false;at++;}}}}
  else if((type>=4&&type<=7)||type==11){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;}
  else if(type<12||type>14)return false;
  if(at!=end)return false;
 }return true;
}
bool sx_mqtt_packets_build(sxnm_view*v)
{
 return sxnm_mqtt(v);
}
#undef SN_ROW
