/* SPDX-License-Identifier: MIT. Bounded physical protocol/text metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_textwire.h"
static const xx_data_struct_field_desc sxtw_signature_fields[]={
 SX_FIELD("signature","utf8",0,0,SX_SIGNATURE),
};
const sx_layout sxtw_signature={0x60710001U,"textwire_signature",sxtw_signature_fields,SX_COUNT(sxtw_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_version_fields[]={
 SX_FIELD("version","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_version={0x60710002U,"textwire_version",sxtw_version_fields,SX_COUNT(sxtw_version_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_method_fields[]={
 SX_FIELD("method","utf8",0,0,SX_STRING),
};
static const sx_layout sxtw_method={0x60710003U,"textwire_method",sxtw_method_fields,SX_COUNT(sxtw_method_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_request_target_fields[]={
 SX_FIELD("request_target","utf8",0,0,SX_STRING),
};
static const sx_layout sxtw_request_target={0x60710004U,"textwire_request_target",sxtw_request_target_fields,SX_COUNT(sxtw_request_target_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_protocol_version_fields[]={
 SX_FIELD("protocol_version","utf8",0,0,SX_STRING),
};
static const sx_layout sxtw_protocol_version={0x60710005U,"textwire_protocol_version",sxtw_protocol_version_fields,SX_COUNT(sxtw_protocol_version_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_reason_phrase_fields[]={
 SX_FIELD("reason_phrase","utf8",0,0,SX_STRING),
};
static const sx_layout sxtw_reason_phrase={0x60710006U,"textwire_reason_phrase",sxtw_reason_phrase_fields,SX_COUNT(sxtw_reason_phrase_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_field_name_fields[]={
 SX_FIELD("field_name","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_field_name={0x60710007U,"textwire_field_name",sxtw_field_name_fields,SX_COUNT(sxtw_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_field_value_fields[]={
 SX_FIELD("field_value","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_field_value={0x60710008U,"textwire_field_value",sxtw_field_value_fields,SX_COUNT(sxtw_field_value_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_name={0x60710009U,"textwire_name",sxtw_name_fields,SX_COUNT(sxtw_name_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_path_fields[]={
 SX_FIELD("path","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_path={0x6071000aU,"textwire_path",sxtw_path_fields,SX_COUNT(sxtw_path_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_text_fields[]={
 SX_FIELD("text","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_text={0x6071000cU,"textwire_text",sxtw_text_fields,SX_COUNT(sxtw_text_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_command_fields[]={
 SX_FIELD("command","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_command={0x6071000dU,"textwire_command",sxtw_command_fields,SX_COUNT(sxtw_command_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_encryption_fields[]={
 SX_FIELD("encryption","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_encryption={0x6071000eU,"textwire_encryption",sxtw_encryption_fields,SX_COUNT(sxtw_encryption_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_base64_text_fields[]={
 SX_FIELD("base64_text","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_base64_text={0x60710010U,"textwire_base64_text",sxtw_base64_text_fields,SX_COUNT(sxtw_base64_text_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_octal_mode_fields[]={
 SX_FIELD("octal_mode","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_octal_mode={0x60710015U,"textwire_octal_mode",sxtw_octal_mode_fields,SX_COUNT(sxtw_octal_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_pem_label_fields[]={
 SX_FIELD("pem_label","utf8",0,0,SX_STRING),
};
static const sx_layout sxtw_pem_label={0x60710021U,"textwire_pem_label",sxtw_pem_label_fields,SX_COUNT(sxtw_pem_label_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_content_length_fields[]={
 SX_FIELD("content_length","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxtw_content_length={0x60710022U,"textwire_content_length",sxtw_content_length_fields,SX_COUNT(sxtw_content_length_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_byte_length_fields[]={
 SX_FIELD("byte_length","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxtw_byte_length={0x60710023U,"textwire_byte_length",sxtw_byte_length_fields,SX_COUNT(sxtw_byte_length_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_declared_size_fields[]={
 SX_FIELD("declared_size","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxtw_declared_size={0x60710024U,"textwire_declared_size",sxtw_declared_size_fields,SX_COUNT(sxtw_declared_size_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_integer_value_fields[]={
 SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_integer_value={0x60710028U,"textwire_integer_value",sxtw_integer_value_fields,SX_COUNT(sxtw_integer_value_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_sequence_fields[]={
 SX_FIELD("sequence","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxtw_sequence={0x60710029U,"textwire_sequence",sxtw_sequence_fields,SX_COUNT(sxtw_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_max_forwards_fields[]={
 SX_FIELD("max_forwards","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxtw_max_forwards={0x6071002aU,"textwire_max_forwards",sxtw_max_forwards_fields,SX_COUNT(sxtw_max_forwards_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_uid_fields[]={
 SX_FIELD("uid","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_uid={0x6071002cU,"textwire_uid",sxtw_uid_fields,SX_COUNT(sxtw_uid_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_gid_fields[]={
 SX_FIELD("gid","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_gid={0x6071002dU,"textwire_gid",sxtw_gid_fields,SX_COUNT(sxtw_gid_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_address_hex_fields[]={
 SX_FIELD("address_hex","ascii_hex",0,0,SX_ADDRESS),
};
const sx_layout sxtw_address_hex={0x6071003eU,"textwire_address_hex",sxtw_address_hex_fields,SX_COUNT(sxtw_address_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_segment_hex_fields[]={
 SX_FIELD("segment_hex","ascii_hex",0,0,SX_ADDRESS),
};
static const sx_layout sxtw_segment_hex={0x6071003fU,"textwire_segment_hex",sxtw_segment_hex_fields,SX_COUNT(sxtw_segment_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_entry_address_hex_fields[]={
 SX_FIELD("entry_address_hex","ascii_hex",0,0,SX_ADDRESS),
};
static const sx_layout sxtw_entry_address_hex={0x60710040U,"textwire_entry_address_hex",sxtw_entry_address_hex_fields,SX_COUNT(sxtw_entry_address_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_srec_record_count_fields[]={
 SX_FIELD("srec_record_count","ascii_hex",0,0,SX_COUNT_PROP),
};
static const sx_layout sxtw_srec_record_count={0x60710042U,"textwire_srec_record_count",sxtw_srec_record_count_fields,SX_COUNT(sxtw_srec_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_hex_byte_fields[]={
 SX_FIELD("hex_byte","ascii_hex",0,0,SX_NONE),
};
const sx_layout sxtw_hex_byte={0x60710043U,"textwire_hex_byte",sxtw_hex_byte_fields,SX_COUNT(sxtw_hex_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_checksum_hex_fields[]={
 SX_FIELD("checksum_hex","ascii_hex",0,0,SX_CHECKSUM),
};
static const sx_layout sxtw_checksum_hex={0x60710044U,"textwire_checksum_hex",sxtw_checksum_hex_fields,SX_COUNT(sxtw_checksum_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_hex_size_fields[]={
 SX_FIELD("hex_size","ascii_hex",0,0,SX_SIZE),
};
const sx_layout sxtw_hex_size={0x60710045U,"textwire_hex_size",sxtw_hex_size_fields,SX_COUNT(sxtw_hex_size_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_control_fields[]={
 SX_FIELD("control","uint8",0,1,SX_NONE),
};
const sx_layout sxtw_control={0x60710048U,"textwire_control",sxtw_control_fields,SX_COUNT(sxtw_control_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_openpgp_compressed_header_fields[]={
 SX_FIELD("packet_tag","uint8",0,1,SX_ID),
 SX_FIELD("compression_algorithm","uint8",1,1,SX_ID),
};
static const sx_layout sxtw_openpgp_compressed_header={0x6071004aU,"textwire_openpgp_compressed_header",sxtw_openpgp_compressed_header_fields,SX_COUNT(sxtw_openpgp_compressed_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_zlib_header_fields[]={
 SX_FIELD("cmf","uint8",0,1,SX_FLAGS),
 SX_FIELD("flg","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxtw_zlib_header={0x6071004bU,"textwire_zlib_header",sxtw_zlib_header_fields,SX_COUNT(sxtw_zlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_zlib_adler32_fields[]={
 SX_FIELD("adler32","uint32be",0,4,SX_CHECKSUM),
};
static const sx_layout sxtw_zlib_adler32={0x6071004cU,"textwire_zlib_adler32",sxtw_zlib_adler32_fields,SX_COUNT(sxtw_zlib_adler32_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_ihex_header_fields[]={
 SX_FIELD("record_mark","char[1]",0,1,SX_SIGNATURE),
 SX_FIELD("data_bytes","ascii_hex[2]",1,2,SX_SIZE),
 SX_FIELD("address","ascii_hex[4]",3,4,SX_ADDRESS),
 SX_FIELD("record_type","ascii_hex[2]",7,2,SX_ID),
};
static const sx_layout sxtw_ihex_header={0x6071004dU,"textwire_ihex_header",sxtw_ihex_header_fields,SX_COUNT(sxtw_ihex_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_srec_header_fields[]={
 SX_FIELD("record_mark","char[1]",0,1,SX_SIGNATURE),
 SX_FIELD("record_type","ascii_signed[1]",1,1,SX_ID),
 SX_FIELD("remaining_bytes","ascii_hex[2]",2,2,SX_SIZE),
};
static const sx_layout sxtw_srec_header={0x6071004eU,"textwire_srec_header",sxtw_srec_header_fields,SX_COUNT(sxtw_srec_header_fields),SX_LE};
static const sx_layout*const sx_textwire_layouts[]={&sxtw_signature,&sxtw_version,&sxtw_method,&sxtw_request_target,&sxtw_protocol_version,&sxtw_reason_phrase,&sxtw_field_name,&sxtw_field_value,&sxtw_name,&sxtw_path,&sxtw_key,&sxtw_text,&sxtw_command,&sxtw_encryption,&sxtw_algorithm,&sxtw_base64_text,&sxtw_base64url_header,&sxtw_base64url_payload,&sxtw_base64url_signature,&sxtw_mac_text,&sxtw_octal_mode,&sxtw_type_name,&sxtw_time_text,&sxtw_xml_element,&sxtw_xml_attribute,&sxtw_json_key,&sxtw_json_string,&sxtw_tensor_dtype,&sxtw_recipient_type,&sxtw_encoded_public_key,&sxtw_encoded_wrapped_key,&sxtw_encoded_header_mac,&sxtw_pem_label,&sxtw_content_length,&sxtw_byte_length,&sxtw_declared_size,&sxtw_backup_version,&sxtw_compression,&sxtw_array_count,&sxtw_integer_value,&sxtw_sequence,&sxtw_max_forwards,&sxtw_line_count,&sxtw_uid,&sxtw_gid,&sxtw_inode,&sxtw_link_count,&sxtw_checksum_decimal,&sxtw_shape_dimension,&sxtw_sixel_parameter,&sxtw_aspect_numerator,&sxtw_aspect_denominator,&sxtw_width,&sxtw_height,&sxtw_color_register,&sxtw_color_mode,&sxtw_red_percent,&sxtw_green_percent,&sxtw_blue_percent,&sxtw_repeat_count,&sxtw_record_count,&sxtw_address_hex,&sxtw_segment_hex,&sxtw_entry_address_hex,&sxtw_tensor_data_offset,&sxtw_srec_record_count,&sxtw_hex_byte,&sxtw_checksum_hex,&sxtw_hex_size,&sxtw_binary_nonce,&sxtw_sixel_symbol,&sxtw_control,&sxtw_safetensors_header,&sxtw_openpgp_compressed_header,&sxtw_zlib_header,&sxtw_zlib_adler32,&sxtw_ihex_header,&sxtw_srec_header};
static bool sx_textwire_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(!r->name||id<0x60710001U||id>=0x60710001U+SX_COUNT(sx_textwire_layouts))return true;xx_var_type_t t=xx_var_get_type(&r->value);bool numeric=t>=XX_VAR_TYPE_INT8&&t<=XX_VAR_TYPE_UINT64;uint64_t v=numeric?xx_var_get_u64(&r->value):0;const wchar_t*text=NULL;switch(id){
case 0x60710010U:
return xx_data_struct_record_set_comment(r,L"Physical encoded text. Decoded bytes are not assigned invented source offsets.");
case 0x60710011U:
return xx_data_struct_record_set_comment(r,L"Physical Base64url protected header. Decoded JSON has no contiguous physical byte span.");
case 0x60710012U:
return xx_data_struct_record_set_comment(r,L"Physical Base64url payload.");
case 0x60710013U:
return xx_data_struct_record_set_comment(r,L"Physical Base64url signature. Display does not authenticate the signature.");
case 0x60710015U:
return xx_data_struct_record_set_comment(r,L"Stored octal permission spelling; not a decimal integer.");
case 0x60710017U:
return xx_data_struct_record_set_comment(r,L"Stored timestamp spelling, including fractional seconds where present.");
case 0x60710026U:
if(numeric&&!xx_rt_wcscmp(r->name,L"compression"))switch(v){case 0:text=L"Uncompressed Android backup payload";break;case 1:text=L"ZLIB-compressed Android backup payload";break;default:break;}
if(text)return xx_data_struct_record_set_comment(r,text);
return true;
case 0x60710031U:
return xx_data_struct_record_set_comment(r,L"Stored tensor dimension, not a byte offset.");
case 0x60710038U:
if(numeric&&!xx_rt_wcscmp(r->name,L"color_mode"))switch(v){case 2:text=L"RGB percentages";break;default:break;}
if(text)return xx_data_struct_record_set_comment(r,text);
return true;
case 0x6071003fU:
return xx_data_struct_record_set_comment(r,L"Stored segment/base-address component in hexadecimal; no implicit shift or synthetic absolute address.");
case 0x60710041U:
return xx_data_struct_record_set_comment(r,L"Byte offset relative to the tensor data region following the 8-byte length and JSON header. Stored relative value is shown in hexadecimal.");
case 0x6071004aU:
if(numeric&&!xx_rt_wcscmp(r->name,L"compression_algorithm"))switch(v){case 1:text=L"ZIP (raw DEFLATE)";break;default:break;}
if(text)return xx_data_struct_record_set_comment(r,text);
return xx_data_struct_record_set_comment(r,L"Native old-format tag8 indeterminate-length packet; algorithm1 is ZIP/raw DEFLATE. Decompressed OpenPGP packet fields have no physical source offsets.");
case 0x6071004bU:
return xx_data_struct_record_set_comment(r,L"RFC1950 compressed stream header: CMF low4 bits compression method, high4 bits window size; FLG includes dictionary flag and level.");
case 0x6071004dU:
if(numeric&&!xx_rt_wcscmp(r->name,L"record_type"))switch(v){case 0:text=L"Data record";break;case 1:text=L"End of file";break;case 2:text=L"Extended segment address";break;case 3:text=L"Start segment address (CS:IP)";break;case 4:text=L"Extended linear address";break;case 5:text=L"Start linear address";break;default:break;}
if(text)return xx_data_struct_record_set_comment(r,text);
return true;
case 0x6071004eU:
if(numeric&&!xx_rt_wcscmp(r->name,L"record_type"))switch(v){case 0:text=L"S0 header";break;case 1:text=L"S1 data: 16-bit address";break;case 2:text=L"S2 data: 24-bit address";break;case 3:text=L"S3 data: 32-bit address";break;case 5:text=L"S5 record count";break;case 6:text=L"S6 record count";break;case 7:text=L"S7 start: 32-bit address";break;case 8:text=L"S8 start: 24-bit address";break;case 9:text=L"S9 start: 16-bit address";break;default:break;}
if(text)return xx_data_struct_record_set_comment(r,text);
return true;
default:return true;}}
bool sxtw_space(unsigned x){return x==' '||(x>=9&&x<=13);}
static bool sxtw_span(sxtw_cursor*q,int64_t a,int64_t n){return a>=0&&n>=0&&a<=q->n&&n<=q->n-a&&!xx_pd_is_stopped(q->c->pd);}
bool sxtw_eq(sxtw_cursor*q,int64_t a,int64_t n,const char*s){return sxtw_span(q,a,n)&&n==(int64_t)xx_rt_strlen(s)&&!xx_rt_memcmp(q->b+a,s,(size_t)n);}
bool sxtw_ci(sxtw_cursor*q,int64_t a,int64_t n,const char*s){if(!sxtw_span(q,a,n)||n!=(int64_t)xx_rt_strlen(s))return false;for(int64_t i=0;i<n;i++){unsigned c=q->b[a+i],d=(unsigned char)s[i];if(c>='A'&&c<='Z')c+=32;if(d>='A'&&d<='Z')d+=32;if(c!=d)return false;}return true;}
bool sxtw_emit(sxtw_cursor*q,const sx_layout*l,int64_t a,int64_t n){if(!sxtw_span(q,a,n))return false;if(!n||q->c->count>=32000)return true;if(!l->fields[0].size&&n>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,a,n);}
bool sxtw_line(sxtw_cursor*q,int64_t*a,int64_t*end){if(q->p>=q->n||xx_pd_is_stopped(q->c->pd))return false;*a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;*end=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
void sxtw_trim(sxtw_cursor*q,int64_t*a,int64_t*end){while(*a<*end&&sxtw_space(q->b[*a]))(*a)++;while(*end>*a&&sxtw_space(q->b[*end-1]))(*end)--;}
bool sxtw_number(sxtw_cursor*q,int64_t a,int64_t n,unsigned radix,uint64_t*out){if(!sxtw_span(q,a,n)||!n||n>24)return false;uint64_t v=0;for(int64_t i=0;i<n;i++){unsigned c=q->b[a+i],d=c>='0'&&c<='9'?c-'0':c>='a'&&c<='f'?c-'a'+10:c>='A'&&c<='F'?c-'A'+10:16;if(d>=radix||v>(UINT64_MAX-d)/radix)return false;v=v*radix+d;}*out=v;return true;}
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
/* HTTP/SIP/RTSP preserve physical header spellings; payloads stay raw. */
bool sxtw_headers(sxtw_cursor*q,bool http)
{
 while(q->p<q->n){
  if(q->c->count>=32000)return true;int64_t a,end;if(!sxtw_line(q,&a,&end))return false;
  int64_t x=a,y;while(x<end&&q->b[x]!=' ')x++;if(x==end)return false;y=x+1;while(y<end&&q->b[y]!=' ')y++;if(y==end)return false;
  bool response=http&&sxtw_eq(q,a,x-a,"HTTP/1.1");
  if(response){TW_EMIT(protocol_version,a,x-a);TW_EMIT(integer_value,x+1,y-x-1);TW_EMIT(reason_phrase,y+1,end-y-1);}
  else{TW_EMIT(method,a,x-a);TW_EMIT(request_target,x+1,y-x-1);TW_EMIT(protocol_version,y+1,end-y-1);}
  uint64_t bytes=0;bool length=false,chunked=false;
  while(sxtw_line(q,&a,&end)){
   if(a==end)break;int64_t colon=a;while(colon<end&&q->b[colon]!=':')colon++;if(colon==end)return false;TW_EMIT(field_name,a,colon-a);int64_t v=colon+1;sxtw_trim(q,&v,&end);
   if(sxtw_ci(q,a,colon-a,"content-length")){if(!sxtw_number(q,v,end-v,10,&bytes))return false;TW_EMIT(content_length,v,end-v);length=true;}
   else if(sxtw_ci(q,a,colon-a,"transfer-encoding")){TW_EMIT(field_value,v,end-v);chunked=sxtw_ci(q,v,end-v,"chunked");}
   else if(sxtw_ci(q,a,colon-a,"cseq")){int64_t z=v;while(z<end&&q->b[z]>='0'&&q->b[z]<='9')z++;TW_EMIT(sequence,v,z-v);if(z<end){while(z<end&&q->b[z]==' ')z++;TW_EMIT(method,z,end-z);}}
   else if(sxtw_ci(q,a,colon-a,"max-forwards")){TW_EMIT(max_forwards,v,end-v);}
   else {TW_EMIT(field_value,v,end-v);}
   if(q->c->count>=32000)return true;
  }
  if(chunked){
   for(;;){if(!sxtw_line(q,&a,&end)||!sxtw_number(q,a,end-a,16,&bytes))return false;TW_EMIT(hex_size,a,end-a);if(q->c->count>=32000)return true;
    if(!bytes){while(sxtw_line(q,&a,&end)&&a!=end){int64_t c=a;while(c<end&&q->b[c]!=':')c++;if(c==end)return false;TW_EMIT(field_name,a,c-a);int64_t v=c+1;sxtw_trim(q,&v,&end);TW_EMIT(field_value,v,end-v);}break;}
    if(bytes>(uint64_t)(q->n-q->p)||q->n-q->p-(int64_t)bytes<2)return false;q->p+=(int64_t)bytes;if(q->b[q->p]!='\r'||q->b[q->p+1]!='\n')return false;q->p+=2;
   }
  }else {if(!length||bytes>(uint64_t)(q->n-q->p))return false;q->p+=(int64_t)bytes;}
  if(!http)return q->p==q->n;
 }
 return true;
}
bool sxtw_hex_records(sxtw_cursor*q,bool intel)
{
 int64_t a,end;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;sxtw_trim(q,&a,&end);if(intel)while(end>a&&(sxtw_space(q->b[end-1])||q->b[end-1]==26))end--;if(a==end)continue;
  /* Hexadecimal members require complete physical digits. A damaged record
   * stays raw instead of exposing a descriptor whose members cannot be read. */
  bool digits=true;for(int64_t i=a+(intel?1:2);i<end;i++){uint64_t v;if(!sxtw_number(q,i,1,16,&v)){digits=false;break;}}if(!digits)break;
  uint64_t n,type;int64_t data;unsigned width;
  if(intel){if(end-a<11||q->b[a]!=':'||!sxtw_number(q,a+1,2,16,&n)||!sxtw_number(q,a+7,2,16,&type)||type>5||end-a!=11+(int64_t)n*2)break;TW_EMIT(ihex_header,a,9);data=a+9;width=0;}
  else{if(end-a<10||q->b[a]!='S'||!sxtw_number(q,a+1,1,10,&type)||type==4||type>9||!sxtw_number(q,a+2,2,16,&n)||end-a!=4+(int64_t)n*2)break;width=type==2||type==6||type==8?3:type==3||type==7?4:2;if(n<width+1)return false;TW_EMIT(srec_header,a,4);if(type==5||type==6){TW_EMIT(srec_record_count,a+4,width*2);}else{TW_EMIT(address_hex,a+4,width*2);}data=a+4+width*2;n-=width+1;}
  if(intel&&type>=2&&type<=5){if(type==3&&n==4){TW_EMIT(segment_hex,data,4);TW_EMIT(entry_address_hex,data+4,4);}else if(n){if(type==2||type==4){TW_EMIT(segment_hex,data,(int64_t)n*2);}else{TW_EMIT(entry_address_hex,data,(int64_t)n*2);}}}
  else for(uint64_t i=0;i<n;i++){TW_EMIT(hex_byte,data+(int64_t)i*2,2);if(q->c->count>=32000)return true;}
  TW_EMIT(checksum_hex,end-2,2);
 }return true;
}
bool sxtw_base64(sxtw_cursor*q,bool pem)
{
 int64_t a,end;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;if(a==end)continue;
  if(end-a>=13&&sxtw_eq(q,a,13,"begin-base64 ")){TW_EMIT(signature,a,12);int64_t p=a+13,z=p;while(z<end&&q->b[z]!=' ')z++;TW_EMIT(octal_mode,p,z-p);if(z<end){TW_EMIT(name,z+1,end-z-1);}continue;}
  if(pem&&end-a>16&&sxtw_eq(q,a,11,"-----BEGIN ")){TW_EMIT(signature,a,11);if(end-a>=16&&sxtw_eq(q,end-5,5,"-----")){TW_EMIT(pem_label,a+11,end-a-16);}continue;}
  if(pem&&end-a>14&&sxtw_eq(q,a,9,"-----END ")){TW_EMIT(signature,a,9);if(sxtw_eq(q,end-5,5,"-----")){TW_EMIT(pem_label,a+9,end-a-14);}continue;}
  if(end-a>=4&&sxtw_eq(q,a,4,"====")){TW_EMIT(signature,a,4);continue;}
  int64_t colon=a;while(colon<end&&q->b[colon]!=':')colon++;
  if(pem&&colon<end){TW_EMIT(field_name,a,colon-a);int64_t v=colon+1;sxtw_trim(q,&v,&end);TW_EMIT(field_value,v,end-v);continue;}
  bool alphabet=true;for(int64_t p=a;p<end;p++){unsigned c=q->b[p];if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='+'||c=='/'||c=='='))alphabet=false;}
  if(alphabet){for(int64_t p=a;p<end;){int64_t z=end-p>4096?4096:end-p;TW_EMIT(base64_text,p,z);p+=z;if(q->c->count>=32000)return true;}}
 }return true;
}
bool sxtw_carrier(sxtw_cursor*q,bool git)
{
 int64_t extent=q->c->f->format_size;if(extent<0||extent>q->n)extent=q->n;
 if(git){if(extent<6||q->b[0]%16!=8||((unsigned)q->b[0]*256+q->b[1])%31)return false;TW_EMIT(zlib_header,0,2);TW_EMIT(zlib_adler32,extent-4,4);}
 else {if(extent<6||q->b[0]!=0xa3||q->b[1]!=1)return false;TW_EMIT(openpgp_compressed_header,0,2);}
 return true;
}
static int sxtw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxtw_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxtw_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxtw_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_textwire_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_HTTP1_MESSAGE:case XX_FILE_TYPE_SIP_MESSAGE:case XX_FILE_TYPE_RTSP_MESSAGE:case XX_FILE_TYPE_REDIS_RESP:case XX_FILE_TYPE_STOMP_FRAMES:case XX_FILE_TYPE_SMTP_TRANSCRIPT:case XX_FILE_TYPE_BITTORRENT_METAINFO:case XX_FILE_TYPE_BASE16:case XX_FILE_TYPE_BASE64:case XX_FILE_TYPE_PEM:case XX_FILE_TYPE_ANDROID_AB:case XX_FILE_TYPE_AGE_ENCRYPTED:case XX_FILE_TYPE_JOSE_JWS:case XX_FILE_TYPE_PUTTY_PPK:case XX_FILE_TYPE_SREC:case XX_FILE_TYPE_IHEX:case XX_FILE_TYPE_DEBUGSCR:case XX_FILE_TYPE_GDBM_DUMP:case XX_FILE_TYPE_MTREE:case XX_FILE_TYPE_SAFETENSORS:case XX_FILE_TYPE_SVG:case XX_FILE_TYPE_DEC_SIXEL:case XX_FILE_TYPE_GIT_OBJECT:case XX_FILE_TYPE_GPG_SIGNED:return true;default:return false;}}
static bool sx_textwire_build(sx_context*c){
 if(!c||!c->f||c->size<1||c->size>33554432||xx_pd_is_stopped(c->pd))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxtw_cursor cursor={c,b,c->size,0},*q=&cursor;xx_file_type_t type=c->f->file_type;
 if(ok)switch(type){case XX_FILE_TYPE_HTTP1_MESSAGE:ok=sx_http1_message_build(q);break;case XX_FILE_TYPE_SIP_MESSAGE:ok=sx_sip_message_build(q);break;case XX_FILE_TYPE_RTSP_MESSAGE:ok=sx_rtsp_message_build(q);break;case XX_FILE_TYPE_REDIS_RESP:ok=sx_redis_resp_build(q);break;case XX_FILE_TYPE_STOMP_FRAMES:ok=sx_stomp_frames_build(q);break;case XX_FILE_TYPE_SMTP_TRANSCRIPT:ok=sx_smtp_transcript_build(q);break;case XX_FILE_TYPE_BITTORRENT_METAINFO:ok=sx_bittorrent_metainfo_build(q);break;case XX_FILE_TYPE_BASE16:ok=sx_base16_build(q);break;case XX_FILE_TYPE_BASE64:ok=sx_base64_build(q);break;case XX_FILE_TYPE_PEM:ok=sx_pem_build(q);break;case XX_FILE_TYPE_ANDROID_AB:ok=sx_android_ab_build(q);break;case XX_FILE_TYPE_AGE_ENCRYPTED:ok=sx_age_encrypted_build(q);break;case XX_FILE_TYPE_JOSE_JWS:ok=sx_jose_jws_build(q);break;case XX_FILE_TYPE_PUTTY_PPK:ok=sx_putty_ppk_build(q);break;case XX_FILE_TYPE_SREC:ok=sx_srec_build(q);break;case XX_FILE_TYPE_IHEX:ok=sx_ihex_build(q);break;case XX_FILE_TYPE_DEBUGSCR:ok=sx_debugscr_build(q);break;case XX_FILE_TYPE_GDBM_DUMP:ok=sx_gdbm_dump_build(q);break;case XX_FILE_TYPE_MTREE:ok=sx_mtree_build(q);break;case XX_FILE_TYPE_SAFETENSORS:ok=sx_safetensors_build(q);break;case XX_FILE_TYPE_SVG:ok=sx_svg_build(q);break;case XX_FILE_TYPE_DEC_SIXEL:ok=sx_dec_sixel_build(q);break;case XX_FILE_TYPE_GIT_OBJECT:ok=sx_gitobject_build(q);break;case XX_FILE_TYPE_GPG_SIGNED:ok=sx_gpgsigned_build(q);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxtw_finish(c);}
#undef TW_VALUE
#undef TW_EMIT
const sx_family sx_textwire_family={sx_textwire_supports,sx_textwire_build,sx_textwire_layouts,SX_COUNT(sx_textwire_layouts),sx_textwire_comment};
