/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_resourceextra_scope.txt. */
static const xx_data_struct_field_desc sxre_secondnature_banner_fields[] = {
 SX_FIELD("banner","char[28]",0,28,SX_SIGNATURE),
 SX_FIELD("kind","char[3]",28,3,SX_NONE),
 SX_FIELD("terminator","uint8",31,1,SX_NONE),
};
static const sx_layout sxre_secondnature_banner = {UINT32_C(0x603f0001),"secondnature_banner",sxre_secondnature_banner_fields,SX_COUNT(sxre_secondnature_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_bmx_count_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxre_secondnature_bmx_count = {UINT32_C(0x603f0002),"secondnature_bmx_count",sxre_secondnature_bmx_count_fields,SX_COUNT(sxre_secondnature_bmx_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_counts_fields[] = {
 SX_FIELD("text_member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("image_member_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxre_secondnature_ref_counts = {UINT32_C(0x603f0003),"secondnature_ref_counts",sxre_secondnature_ref_counts_fields,SX_COUNT(sxre_secondnature_ref_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_text_fields[] = {
 SX_FIELD("title","char[64]",0,64,SX_NONE),
 SX_FIELD("caption","char[128]",64,128,SX_NONE),
 SX_FIELD("description","char[128]",192,128,SX_NONE),
};
static const sx_layout sxre_secondnature_snx_text = {UINT32_C(0x603f0004),"secondnature_snx_text",sxre_secondnature_snx_text_fields,SX_COUNT(sxre_secondnature_snx_text_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_info_fields[] = {
 SX_FIELD("sequence_id","uint16",0,2,SX_NONE),
 SX_FIELD("width","uint16",2,2,SX_NONE),
 SX_FIELD("height","uint16",4,2,SX_NONE),
};
static const sx_layout sxre_secondnature_snx_info = {UINT32_C(0x603f0005),"secondnature_snx_info",sxre_secondnature_snx_info_fields,SX_COUNT(sxre_secondnature_snx_info_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",17,4,SX_SIZE),
};
static const sx_layout sxre_secondnature_entry = {UINT32_C(0x603f0006),"secondnature_entry",sxre_secondnature_entry_fields,SX_COUNT(sxre_secondnature_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("kind","uint16",13,2,SX_NONE),
 SX_FIELD("payload_offset","uint32",15,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",19,4,SX_SIZE),
 SX_FIELD("rectangle_0","uint16",23,2,SX_NONE),
 SX_FIELD("rectangle_1","uint16",25,2,SX_NONE),
 SX_FIELD("rectangle_2","uint16",27,2,SX_NONE),
 SX_FIELD("rectangle_3","uint16",29,2,SX_NONE),
};
static const sx_layout sxre_secondnature_ref_entry = {UINT32_C(0x603f0007),"secondnature_ref_entry",sxre_secondnature_ref_entry_fields,SX_COUNT(sxre_secondnature_ref_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_banner_complemented_fields[] = {
 SX_FIELD("banner","ones_char[28]",0,28,SX_SIGNATURE),
 SX_FIELD("kind","ones_char[3]",28,3,SX_NONE),
 SX_FIELD("terminator","uint8_ones",31,1,SX_NONE),
};
static const sx_layout sxre_secondnature_banner_complemented = {UINT32_C(0x603f0008),"secondnature_banner_complemented",sxre_secondnature_banner_complemented_fields,SX_COUNT(sxre_secondnature_banner_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_bmx_count_complemented_fields[] = {
 SX_FIELD("member_count","uint16_ones_le",0,2,SX_COUNT_PROP),
};
static const sx_layout sxre_secondnature_bmx_count_complemented = {UINT32_C(0x603f0009),"secondnature_bmx_count_complemented",sxre_secondnature_bmx_count_complemented_fields,SX_COUNT(sxre_secondnature_bmx_count_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_counts_complemented_fields[] = {
 SX_FIELD("text_member_count","uint16_ones_le",0,2,SX_COUNT_PROP),
 SX_FIELD("image_member_count","uint16_ones_le",2,2,SX_COUNT_PROP),
};
static const sx_layout sxre_secondnature_ref_counts_complemented = {UINT32_C(0x603f000a),"secondnature_ref_counts_complemented",sxre_secondnature_ref_counts_complemented_fields,SX_COUNT(sxre_secondnature_ref_counts_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_text_complemented_fields[] = {
 SX_FIELD("title","ones_char[64]",0,64,SX_NONE),
 SX_FIELD("caption","ones_char[128]",64,128,SX_NONE),
 SX_FIELD("description","ones_char[128]",192,128,SX_NONE),
};
static const sx_layout sxre_secondnature_snx_text_complemented = {UINT32_C(0x603f000b),"secondnature_snx_text_complemented",sxre_secondnature_snx_text_complemented_fields,SX_COUNT(sxre_secondnature_snx_text_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_snx_info_complemented_fields[] = {
 SX_FIELD("sequence_id","uint16_ones_le",0,2,SX_NONE),
 SX_FIELD("width","uint16_ones_le",2,2,SX_NONE),
 SX_FIELD("height","uint16_ones_le",4,2,SX_NONE),
};
static const sx_layout sxre_secondnature_snx_info_complemented = {UINT32_C(0x603f000c),"secondnature_snx_info_complemented",sxre_secondnature_snx_info_complemented_fields,SX_COUNT(sxre_secondnature_snx_info_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_entry_complemented_fields[] = {
 SX_FIELD("name","ones_char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32_ones_le",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32_ones_le",17,4,SX_SIZE),
};
static const sx_layout sxre_secondnature_entry_complemented = {UINT32_C(0x603f000d),"secondnature_entry_complemented",sxre_secondnature_entry_complemented_fields,SX_COUNT(sxre_secondnature_entry_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_ref_entry_complemented_fields[] = {
 SX_FIELD("name","ones_char[13]",0,13,SX_NONE),
 SX_FIELD("kind","uint16_ones_le",13,2,SX_NONE),
 SX_FIELD("payload_offset","uint32_ones_le",15,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32_ones_le",19,4,SX_SIZE),
 SX_FIELD("rectangle_0","uint16_ones_le",23,2,SX_NONE),
 SX_FIELD("rectangle_1","uint16_ones_le",25,2,SX_NONE),
 SX_FIELD("rectangle_2","uint16_ones_le",27,2,SX_NONE),
 SX_FIELD("rectangle_3","uint16_ones_le",29,2,SX_NONE),
};
static const sx_layout sxre_secondnature_ref_entry_complemented = {UINT32_C(0x603f000e),"secondnature_ref_entry_complemented",sxre_secondnature_ref_entry_complemented_fields,SX_COUNT(sxre_secondnature_ref_entry_complemented_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_short_string_length_fields[] = {
 SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxre_skf_short_string_length = {UINT32_C(0x603f000f),"skf_short_string_length",sxre_skf_short_string_length_fields,SX_COUNT(sxre_skf_short_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_long_string_length_fields[] = {
 SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxre_skf_long_string_length = {UINT32_C(0x603f0010),"skf_long_string_length",sxre_skf_long_string_length_fields,SX_COUNT(sxre_skf_long_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_object_count_fields[] = {
 SX_FIELD("object_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_object_count = {UINT32_C(0x603f0011),"skf_object_count",sxre_skf_object_count_fields,SX_COUNT(sxre_skf_object_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_property_count_fields[] = {
 SX_FIELD("property_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_property_count = {UINT32_C(0x603f0012),"skf_property_count",sxre_skf_property_count_fields,SX_COUNT(sxre_skf_property_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_property_id_fields[] = {
 SX_FIELD("property_id","uint16",0,2,SX_NONE),
};
static const sx_layout sxre_skf_property_id = {UINT32_C(0x603f0013),"skf_property_id",sxre_skf_property_id_fields,SX_COUNT(sxre_skf_property_id_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_resource_count_fields[] = {
 SX_FIELD("resource_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_resource_count = {UINT32_C(0x603f0014),"skf_resource_count",sxre_skf_resource_count_fields,SX_COUNT(sxre_skf_resource_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_resource_prefix_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("opaque_word","uint16",4,2,SX_NONE),
};
static const sx_layout sxre_skf_resource_prefix = {UINT32_C(0x603f0015),"skf_resource_prefix",sxre_skf_resource_prefix_fields,SX_COUNT(sxre_skf_resource_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_record6_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_record6_count = {UINT32_C(0x603f0016),"skf_record6_count",sxre_skf_record6_count_fields,SX_COUNT(sxre_skf_record6_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_optional_flag_fields[] = {
 SX_FIELD("present","uint32",0,4,SX_NONE),
};
static const sx_layout sxre_skf_optional_flag = {UINT32_C(0x603f0017),"skf_optional_flag",sxre_skf_optional_flag_fields,SX_COUNT(sxre_skf_optional_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_record14_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_record14_count = {UINT32_C(0x603f0018),"skf_record14_count",sxre_skf_record14_count_fields,SX_COUNT(sxre_skf_record14_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_variable_record_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxre_skf_variable_record_count = {UINT32_C(0x603f0019),"skf_variable_record_count",sxre_skf_variable_record_count_fields,SX_COUNT(sxre_skf_variable_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_payload_size_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxre_skf_payload_size = {UINT32_C(0x603f001a),"skf_payload_size",sxre_skf_payload_size_fields,SX_COUNT(sxre_skf_payload_size_fields),SX_LE};
static const sx_layout *const sx_resourceextra_layouts[] = {
 &sxre_secondnature_banner,
 &sxre_secondnature_bmx_count,
 &sxre_secondnature_ref_counts,
 &sxre_secondnature_snx_text,
 &sxre_secondnature_snx_info,
 &sxre_secondnature_entry,
 &sxre_secondnature_ref_entry,
 &sxre_secondnature_banner_complemented,
 &sxre_secondnature_bmx_count_complemented,
 &sxre_secondnature_ref_counts_complemented,
 &sxre_secondnature_snx_text_complemented,
 &sxre_secondnature_snx_info_complemented,
 &sxre_secondnature_entry_complemented,
 &sxre_secondnature_ref_entry_complemented,
 &sxre_skf_short_string_length,
 &sxre_skf_long_string_length,
 &sxre_skf_object_count,
 &sxre_skf_property_count,
 &sxre_skf_property_id,
 &sxre_skf_resource_count,
 &sxre_skf_resource_prefix,
 &sxre_skf_record6_count,
 &sxre_skf_optional_flag,
 &sxre_skf_record14_count,
 &sxre_skf_variable_record_count,
 &sxre_skf_payload_size,
};
static bool sx_resourceextra_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x603f0000U||id>=0x60400000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x603f0005U:
 if(!xx_rt_wcscmp(r->name,L"width"))text=L"Pixels.";
 if(!xx_rt_wcscmp(r->name,L"height"))text=L"Pixels.";
 break;
 case 0x603f0006U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"NUL terminated; original stale bytes after terminator remain in raw column.";
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"File-relative stored value; zero/all-one slots may be reference-only.";
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Stored member extent; all-one unused SNX sentinel is not a byte size.";
 break;
 case 0x603f0007U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native preserves the kind word without assigning an enumeration.";
 if(!xx_rt_wcscmp(r->name,L"rectangle_0"))text=L"Screen placement rectangle word0; axis/order not established.";
 break;
 case 0x603f000cU:
 if(!xx_rt_wcscmp(r->name,L"width"))text=L"Pixels.";
 if(!xx_rt_wcscmp(r->name,L"height"))text=L"Pixels.";
 break;
 case 0x603f000dU:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"NUL terminated; original stale bytes after terminator remain in raw column.";
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"File-relative stored value; zero/all-one slots may be reference-only.";
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Stored member extent; all-one unused SNX sentinel is not a byte size.";
 break;
 case 0x603f000eU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native preserves the kind word without assigning an enumeration.";
 if(!xx_rt_wcscmp(r->name,L"rectangle_0"))text=L"Screen placement rectangle word0; axis/order not established.";
 break;
 case 0x603f0013U:
 if(!xx_rt_wcscmp(r->name,L"property_id"))text=L"Observed native branches:2 compound states;13 extra word;44 length-prefixed data. Other nonzero properties use a standard group.";
 break;
 case 0x603f0015U:
 if(!xx_rt_wcscmp(r->name,L"opaque_word"))text=L"Stored resource word; native reader does not assign semantics.";
 break;
 case 0x603f0016U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Count of following opaque6-byte records.";
 break;
 case 0x603f0017U:
 if(!xx_rt_wcscmp(r->name,L"present"))text=L"Nonzero introduces27 opaque bytes and a one-byte-length string.";
 break;
 case 0x603f0018U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Count of following opaque14-byte records.";
 break;
 case 0x603f0019U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Each row has14 opaque bytes, a4-byte size, and that many payload bytes.";
 break;
 default:break;}
 if((id==sxre_secondnature_entry.id||id==sxre_secondnature_entry_complemented.id)&&(!xx_rt_wcscmp(r->name,L"payload_size")||!xx_rt_wcscmp(r->name,L"payload_offset"))&&xx_var_get_u64(&r->value)==UINT32_MAX)text=L"All-one unused SNX slot sentinel, not a byte count or address.";
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXRE_LIMIT 20000U
static bool sxre_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxre_read(sx_context*c,uint64_t p,void*b,size_t n){return sxre_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static bool sxre_word(sx_context*c,uint64_t p,unsigned n,bool mask,uint64_t*v){uint8_t b[4];if(!n||n>4||!sxre_read(c,p,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)(mask?(uint8_t)~b[i]:b[i])<<(8*i);return true;}
static bool sxre_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXRE_LIMIT&&sxre_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
static bool sxre_secondnature(sx_context*c){uint8_t b[32];if(!sxre_read(c,0,b,32))return false;bool mask=b[0]!=(uint8_t)'S';if(mask)for(unsigned i=0;i<32;i++)b[i]=(uint8_t)~b[i];if(xx_rt_memcmp(b,"Second Nature Software Inc. ",28)||b[31])return false;uint64_t count,p,z;const sx_layout *entry;
#define SXRE_SN(n) (mask?&sxre_secondnature_##n##_complemented:&sxre_secondnature_##n)
 if(!sxre_add(c,SXRE_SN(banner),0))return false;
 if(!xx_rt_memcmp(b+28,"BMX",3)){if(!sxre_word(c,32,2,mask,&count)||count<1||count>4096||!sxre_add(c,SXRE_SN(bmx_count),32))return false;p=34;z=21;entry=SXRE_SN(entry);}
 else if(!xx_rt_memcmp(b+28,"REF",3)){uint64_t a,v;if(!sxre_word(c,32,2,mask,&a)||!sxre_word(c,34,2,mask,&v)||a>64||v>64||!(count=a+v)||count>64||!sxre_add(c,SXRE_SN(ref_counts),32))return false;p=36;z=31;entry=SXRE_SN(ref_entry);}
 else if(!xx_rt_memcmp(b+28,"SNX",3)){if(!sxre_add(c,SXRE_SN(snx_text),32)||!sxre_add(c,SXRE_SN(snx_info),352))return false;p=358;z=21;count=3;entry=SXRE_SN(entry);}
 else return false;
 if(!sxre_span(c,p,count*z))return false;for(uint64_t i=0;i<count;i++)if(!sxre_add(c,entry,p+i*z))return false;
#undef SXRE_SN
 return true;}
static bool sxre_skip(sx_context*c,uint64_t*p,uint64_t n){if(!sxre_span(c,*p,n))return false;*p+=n;return true;}
static bool sxre_scalar(sx_context*c,const sx_layout*l,uint64_t*p,unsigned width,uint64_t*v){if(!sxre_word(c,*p,width,false,v)||!sxre_add(c,l,*p))return false;*p+=width;return true;}
static bool sxre_name(sx_context*c,uint64_t*p,bool big){uint64_t n;return sxre_scalar(c,big?&sxre_skf_long_string_length:&sxre_skf_short_string_length,p,big?4:1,&n)&&n<=1024&&sxre_skip(c,p,n);}
static bool sxre_group(sx_context*c,uint64_t*p,unsigned version){uint64_t count,n;if(!sxre_scalar(c,&sxre_skf_resource_count,p,4,&count)||count>1000000)return false;for(uint64_t i=0;i<count;i++){
 if((version>218&&!sxre_skip(c,p,4))||!sxre_word(c,*p,4,false,&n)||n>INT32_MAX||!sxre_add(c,&sxre_skf_resource_prefix,*p)||!sxre_skip(c,p,6)||!sxre_skip(c,p,n)||!sxre_skip(c,p,version>205?24:20))return false;}
 if(!sxre_scalar(c,&sxre_skf_record6_count,p,4,&n)||n>INT32_MAX/6||!sxre_skip(c,p,n*6))return false;
 if(version>201){if(!sxre_scalar(c,&sxre_skf_record6_count,p,4,&n)||n>INT32_MAX/6||!sxre_skip(c,p,n*6))return false;if(version>206){if(!sxre_scalar(c,&sxre_skf_optional_flag,p,4,&n))return false;if(n&&(!sxre_skip(c,p,27)||!sxre_name(c,p,false)))return false;}if(version>218&&!sxre_skip(c,p,4))return false;}
 return sxre_skip(c,p,4);}
static bool sxre_skf(sx_context*c){uint8_t h[16];uint64_t p=0,n,objects;if(!sxre_word(c,0,1,false,&n)||n<6||n>15||!sxre_read(c,1,h,(size_t)n)||xx_rt_memcmp(h,"SKF",3)||h[3]<'0'||h[3]>'9'||h[4]!='.'||h[5]<'0'||h[5]>'9')return false;
 unsigned version=(h[3]-'0')*100+h[5]-'0';if(n>6){if(n!=7||h[6]<'0'||h[6]>'9')return false;version=(h[3]-'0')*100+(h[5]-'0')*10+h[6]-'0';}if(version<200||version>299||!sxre_name(c,&p,false))return false;
 for(unsigned i=0;i<(version>218?10U:4U);i++)if(!sxre_name(c,&p,true))return false;
 if(!sxre_scalar(c,&sxre_skf_object_count,&p,4,&objects)||objects>1000000)return false;
 for(uint64_t i=0;i<objects;i++){uint64_t properties;if(!sxre_name(c,&p,false)||!sxre_scalar(c,&sxre_skf_property_count,&p,4,&properties)||properties>65535)return false;
  for(uint64_t j=0;j<properties;j++){uint64_t prop;if(!sxre_scalar(c,&sxre_skf_property_id,&p,2,&prop)||!prop||!sxre_group(c,&p,version))return false;
   if(prop==13){if(!sxre_skip(c,&p,4))return false;}else if(prop==44){if(!sxre_scalar(c,&sxre_skf_payload_size,&p,4,&n)||n>INT32_MAX||!sxre_skip(c,&p,n))return false;}else if(prop==2){
    for(unsigned k=0;k<4;k++){uint64_t m;if(!sxre_group(c,&p,version)||!sxre_scalar(c,&sxre_skf_record14_count,&p,4,&n)||n>INT32_MAX/14||!sxre_skip(c,&p,n*14)||!sxre_scalar(c,&sxre_skf_variable_record_count,&p,4,&m)||m>1000000)return false;
     for(uint64_t l=0;l<m;l++)if(!sxre_skip(c,&p,14)||!sxre_scalar(c,&sxre_skf_payload_size,&p,4,&n)||n>INT32_MAX||!sxre_skip(c,&p,n))return false;
     if(version<209&&!sxre_skip(c,&p,4))return false;}
    if(!sxre_group(c,&p,version)||(version<=208&&!sxre_skip(c,&p,version==200?100:version==201?148:76)))return false;
   }
  }
 }
 return true;}
static int sxre_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxre_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxre_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxre_order);return !c->failed;}
static bool sx_resourceextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_SECONDNATURE:case XX_FILE_TYPE_SKF:return true;default:return false;}}
static bool sx_resourceextra_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=c->f->file_type==XX_FILE_TYPE_SECONDNATURE?sxre_secondnature(c):c->f->file_type==XX_FILE_TYPE_SKF?sxre_skf(c):false;(void)ok;return c->count&&sxre_finish(c);}
