/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical document/mailbox metadata; undecoded bodies remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_docmeta.h"
static const xx_data_struct_field_desc sxdm_itolitls_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("postheader_size","uint32",20,4,SX_SIZE),
 SX_FIELD("format_guid","bytes",24,16,SX_ID),
};
static const sx_layout sxdm_itolitls_header={UINT32_C(0x60230038),"itolitls_header",sxdm_itolitls_header_fields,SX_COUNT(sxdm_itolitls_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_itolitls_section_fields[]={
 SX_FIELD("section_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("section_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxdm_itolitls_section={UINT32_C(0x60230039),"itolitls_section",sxdm_itolitls_section_fields,SX_COUNT(sxdm_itolitls_section_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_post_header_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("caol_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("directory_metadata","bytes",8,56,SX_NONE),
 SX_FIELD("entry_count","uint64",64,8,SX_COUNT_PROP),
 SX_FIELD("index_metadata","bytes",72,80,SX_NONE),
};
static const sx_layout sxdm_hxs_post_header={UINT32_C(0x6023003A),"hxs_post_header",sxdm_hxs_post_header_fields,SX_COUNT(sxdm_hxs_post_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_caol_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("metadata","bytes",12,36,SX_NONE),
};
static const sx_layout sxdm_hxs_caol={UINT32_C(0x6023003B),"hxs_caol",sxdm_hxs_caol_fields,SX_COUNT(sxdm_hxs_caol_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_itsf_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("content_offset","uint64",16,8,SX_OFFSET),
 SX_FIELD("timestamp","uint32",24,4,SX_TIME),
 SX_FIELD("language_id","uint32",28,4,SX_ID),
};
static const sx_layout sxdm_hxs_itsf={UINT32_C(0x6023003C),"hxs_itsf",sxdm_hxs_itsf_fields,SX_COUNT(sxdm_hxs_itsf_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_file_size_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
 SX_FIELD("file_size","uint64",8,8,SX_SIZE),
 SX_FIELD("reserved2","bytes",16,8,SX_RESERVED),
};
static const sx_layout sxdm_hxs_file_size_header={UINT32_C(0x6023003D),"hxs_file_size_header",sxdm_hxs_file_size_header_fields,SX_COUNT(sxdm_hxs_file_size_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_ifcm_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("chunk_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("sentinel1","int32",16,4,SX_NONE),
 SX_FIELD("sentinel2","int32",20,4,SX_NONE),
 SX_FIELD("chunk_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxdm_hxs_ifcm={UINT32_C(0x6023003E),"hxs_ifcm",sxdm_hxs_ifcm_fields,SX_COUNT(sxdm_hxs_ifcm_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_aoll_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("quickref_size","uint32",4,4,SX_SIZE),
 SX_FIELD("metadata","bytes",8,40,SX_NONE),
};
static const sx_layout sxdm_hxs_aoll_header={UINT32_C(0x6023003F),"hxs_aoll_header",sxdm_hxs_aoll_header_fields,SX_COUNT(sxdm_hxs_aoll_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_aoll_count_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxdm_hxs_aoll_count={UINT32_C(0x60230040),"hxs_aoll_count",sxdm_hxs_aoll_count_fields,SX_COUNT(sxdm_hxs_aoll_count_fields),SX_LE};
static const sx_layout *const sx_docmeta_layouts[]={
 &sxdm_djvu_form_header,
 &sxdm_djvu_chunk_header,
 &sxdm_djvu_info,
 &sxdm_zxml_header,
 &sxdm_lsz_header,
 &sxdm_lsz_member_header,
 &sxdm_pain_header,
 &sxdm_pain_directory_entry,
 &sxdm_pain_lzss_block_header,
 &sxdm_thebat_msb_header,
 &sxdm_thebat_msb_record,
 &sxdm_stylus_header,
 &sxdm_perform_header,
 &sxdm_pkt_type2_header,
 &sxdm_pkt_message_header,
 &sxdm_paperport_header,
 &sxdm_paperport_chunk_header,
 &sxdm_paperport_root_prefix,
 &sxdm_paperport_root_entry,
 &sxdm_paperport_page_item,
 &sxdm_winhelp_header,
 &sxdm_winhelp_internal_file_header,
 &sxdm_winhelp_btree_header,
 &sxdm_winhelp_index_header,
 &sxdm_winhelp_leaf_header,
 &sxdm_winhelp_file_pointer,
 &sxdm_ivt_header,
 &sxdm_ivt_btree_header,
 &sxdm_ivt_leaf_header,
 &sxdm_ivt_index_header,
 &sxdm_ivt_key_length,
 &sxdm_ivt_child_pointer,
 &sxdm_ivt_entry_terminator,
 &sxdm_ivt_mszip_header,
 &sxdm_ivt_mszip_block_header,
 &sxdm_ivt_leb_offset_1,
 &sxdm_ivt_leb_offset_2,
 &sxdm_ivt_leb_offset_3,
 &sxdm_ivt_leb_offset_4,
 &sxdm_ivt_leb_offset_5,
 &sxdm_ivt_leb_size_1,
 &sxdm_ivt_leb_size_2,
 &sxdm_ivt_leb_size_3,
 &sxdm_ivt_leb_size_4,
 &sxdm_ivt_leb_size_5,
 &sxdm_zim_header,
 &sxdm_zim_url_pointer,
 &sxdm_zim_title_pointer,
 &sxdm_zim_cluster_pointer,
 &sxdm_zim_article_entry,
 &sxdm_zim_redirect_entry,
 &sxdm_zim_cluster_header,
 &sxdm_zim_blob_offset32,
 &sxdm_zim_blob_offset64,
 &sxdm_zim_checksum,
 &sxdm_itolitls_header,
 &sxdm_itolitls_section,
 &sxdm_hxs_post_header,
 &sxdm_hxs_caol,
 &sxdm_hxs_itsf,
 &sxdm_hxs_file_size_header,
 &sxdm_hxs_ifcm,
 &sxdm_hxs_aoll_header,
 &sxdm_hxs_aoll_count,
 &sxdm_dbx_header,
 &sxdm_dbx_node_header,
 &sxdm_dbx_node_entry,
 &sxdm_dbx_info_header,
 &sxdm_dbx_attribute,
 &sxdm_dbx_attribute_indirect,
 &sxdm_dbx_attribute_message,
 &sxdm_dbx_message_pointer,
 &sxdm_dbx_block_header,
};
static bool sx_docmeta_supports(xx_file_type_t t)
{
 switch(t){case XX_FILE_TYPE_DJVU:case XX_FILE_TYPE_ZXML:case XX_FILE_TYPE_LSZ:case XX_FILE_TYPE_PAIN:case XX_FILE_TYPE_THEBAT_MSB:case XX_FILE_TYPE_STYLUS:case XX_FILE_TYPE_PERFORM:case XX_FILE_TYPE_PKT:case XX_FILE_TYPE_PAPERPORT:case XX_FILE_TYPE_WINDOWS_HELP:case XX_FILE_TYPE_IVT:case XX_FILE_TYPE_OPENZIM:case XX_FILE_TYPE_HXS:case XX_FILE_TYPE_MICROSOFT_LIT:case XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX:return true;default:return false;}
}
uint16_t sxdm_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
uint32_t sxdm_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
uint64_t sxdm_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
bool sxdm_span(sx_context *c,int64_t at,uint64_t n){return !xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
bool sxdm_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
 if(n<=0||!sxdm_span(c,at,(uint64_t)n))return false;
 return sx_add(c,l,at,n);
}
static int sxdm_order(const void *aa,const void *bb){const xx_data_struct *a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;if(a->total_size!=b->total_size)return a->total_size<b->total_size?-1:1;return a->id<b->id?-1:a->id>b->id;}
static bool sxdm_finish(sx_context *c)
{
 size_t n=c->count,out=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdm_order);
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];int64_t at=d.offset-c->f->base_address;
  if(out&&sxdm_order(&c->items[out-1],&d)==0)continue;
  if(at<end){if(c->f->file_type==XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX||c->f->file_type==XX_FILE_TYPE_PAPERPORT)continue;return false;}c->items[out++]=d;end=at+d.total_size;
 }
 c->count=out;end=0;
 for(size_t i=0;i<out;i++){int64_t at=c->items[i].offset-c->f->base_address,nbytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+nbytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
bool sxdm_zero(sx_context *c,int64_t *at,int64_t end,unsigned limit)
{
 uint8_t b[256];unsigned used=0;
 while(*at<end&&used<limit){size_t n=(size_t)(end-*at>256?256:end-*at);if(n>limit-used)n=limit-used;if(!sx_read(c,*at,b,n))return false;for(size_t i=0;i<n;i++){++*at;++used;if(!b[i])return true;}}return false;
}
/* LIT shares the transport header but its native reader validates only that
 * layer before invoking an external decoder. We do not invoke that decoder. */
static bool sxdm_itolitls(sx_context *c)
{
 uint8_t b[152];uint64_t offsets[5],sizes[5];if(!sx_read(c,0,b,40)||!sxdm_add(c,&sxdm_itolitls_header,0,40))return false;
 uint32_t table=sxdm_u32(b+12),post=sxdm_u32(b+20);if(sxdm_u32(b+16)!=5||table<40||post<232||!sxdm_span(c,table,80U+(uint64_t)post))return false;
 for(unsigned i=0;i<5;i++){int64_t at=(int64_t)table+i*16;if(!sx_read(c,at,b,16)||!sxdm_add(c,&sxdm_itolitls_section,at,16))return false;offsets[i]=sxdm_u64(b);sizes[i]=sxdm_u64(b+8);if(offsets[i]>INT64_MAX||!sxdm_span(c,(int64_t)offsets[i],sizes[i]))return false;}
 if(c->f->file_type==XX_FILE_TYPE_MICROSOFT_LIT)return true;
 int64_t p=(int64_t)table+80;
 if(!sxdm_add(c,&sxdm_hxs_post_header,p,152)||!sxdm_add(c,&sxdm_hxs_caol,p+152,48)||!sxdm_add(c,&sxdm_hxs_itsf,p+200,32)||sizes[0]<24||!sxdm_add(c,&sxdm_hxs_file_size_header,(int64_t)offsets[0],24)||sizes[1]<32||!sx_read(c,(int64_t)offsets[1],b,32)||!sxdm_add(c,&sxdm_hxs_ifcm,(int64_t)offsets[1],32))return false;
 uint32_t width=sxdm_u32(b+8),count=sxdm_u32(b+24);if(width<50||count>65536||(uint64_t)count*width>sizes[1]-32)return false;
 for(uint32_t i=0;i<count;i++){int64_t at=(int64_t)offsets[1]+32+(int64_t)i*width;if(!sx_read(c,at,b,8))return false;if(xx_rt_memcmp(b,"AOLL",4))continue;uint32_t qr=sxdm_u32(b+4);if(qr<2||qr>width-48)return false;if(!sxdm_add(c,&sxdm_hxs_aoll_header,at,48)||!sxdm_add(c,&sxdm_hxs_aoll_count,at+width-2,2))return false;}
 return true;
}
static bool sx_docmeta_build(sx_context *c)
{
 bool ok=false;
 switch(c->f->file_type){
 case XX_FILE_TYPE_DJVU:ok=sx_djvu_build(c);break;case XX_FILE_TYPE_ZXML:ok=sx_zxml_build(c);break;case XX_FILE_TYPE_LSZ:ok=sx_lsz_build(c);break;case XX_FILE_TYPE_PAIN:ok=sx_pain_build(c);break;case XX_FILE_TYPE_THEBAT_MSB:ok=sx_thebat_msb_build(c);break;case XX_FILE_TYPE_STYLUS:ok=sx_stylus_build(c);break;case XX_FILE_TYPE_PERFORM:ok=sx_perform_build(c);break;case XX_FILE_TYPE_PKT:ok=sx_pkt_build(c);break;case XX_FILE_TYPE_PAPERPORT:ok=sx_paperport_build(c);break;case XX_FILE_TYPE_WINDOWS_HELP:ok=sx_ue2_documents_build(c);break;case XX_FILE_TYPE_IVT:ok=sx_ivt_build(c);break;case XX_FILE_TYPE_OPENZIM:ok=sx_openzim_build(c);break;case XX_FILE_TYPE_HXS:case XX_FILE_TYPE_MICROSOFT_LIT:ok=sxdm_itolitls(c);break;case XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX:ok=sx_outlook_express_dbx_mailbox_build(c);break;default:return false;}
 return ok&&sxdm_finish(c);
}
static bool sx_docmeta_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60230001)||id>UINT32_C(0x6023ffff))return true;
 const wchar_t *comment=NULL;uint64_t v=0;bool number=xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64;
 if(number)v=xx_var_get_u64(&r->value);
#define SDM_IS(l,n) (id==sxdm_##l.id&&!xx_rt_wcscmp(r->name,L##n))
 if(SDM_IS(djvu_info,"gamma_times_ten"))comment=L"Gamma multiplied by 10";
 else if(SDM_IS(djvu_info,"dpi"))comment=L"Dots per inch";
 else if(SDM_IS(djvu_info,"orientation"))comment=v==1?L"Upright":v==2?L"Upside down":v==5?L"Quarter-turn rotation, flag 5":v==6?L"Quarter-turn rotation, flag 6":L"Unknown orientation";
 else if(SDM_IS(djvu_form_header,"form_size"))comment=L"Bytes after the FORM size word, including form type and chunk padding";
 else if(SDM_IS(lsz_member_header,"method"))comment=v==1?L"Stored":v==2?L"PKWARE DCL implode":v==6?L"Empty member":NULL;
 else if(SDM_IS(lsz_member_header,"dos_time"))comment=L"DOS packed local time: hour:5, minute:6, seconds/2:5";
 else if(SDM_IS(lsz_member_header,"dos_date"))comment=L"DOS packed date: years since 1980:7, month:4, day:5";
 else if(SDM_IS(lsz_member_header,"attributes"))comment=L"DOS file attribute bits";
 else if(SDM_IS(pain_directory_entry,"method"))comment=v==0?L"Stored":v==3?L"PAiN LZSS":NULL;
 else if(SDM_IS(pain_lzss_block_header,"block_type"))comment=v==0?L"Compressed LZSS block":v==1?L"Stored block":NULL;
 else if(SDM_IS(stylus_header,"plaintext_crc32"))comment=L"CRC-32 of decoded dictionary";
 else if(SDM_IS(perform_header,"plaintext_crc16"))comment=L"CRC-16/ARC of decoded database";
 else if(SDM_IS(pkt_type2_header,"month_zero_based"))comment=L"0=January, 11=December";
 else if(SDM_IS(pkt_type2_header,"packet_type")||SDM_IS(pkt_message_header,"message_type"))comment=v==2?L"FidoNet Type 2":NULL;
 else if(SDM_IS(pkt_type2_header,"baud_rate"))comment=L"Bits per second";
 else if(SDM_IS(paperport_chunk_header,"chunk_type"))comment=v==0x8000?L"Root":v==0x4000?L"Page item":v==0x1000?L"Image object":NULL;
 else if(SDM_IS(zim_cluster_header,"compression_and_flags"))comment=(v&15)<=1?((v&16)?L"Stored; 64-bit blob offsets":L"Stored; 32-bit blob offsets"):(v&15)==4?L"XZ compressed cluster":(v&15)==5?L"Zstandard compressed cluster":L"Unknown cluster compression";
 else if(SDM_IS(zim_blob_offset32,"cluster_data_offset")||SDM_IS(zim_blob_offset64,"cluster_data_offset"))comment=L"Byte offset from stored cluster data, after its flag byte";
 else if(SDM_IS(zim_redirect_entry,"mime_type"))comment=L"Redirect entry (0xFFFF)";
 else if(SDM_IS(hxs_post_header,"caol_offset"))comment=L"Byte offset relative to post-header";
 else if(SDM_IS(dbx_attribute,"id_and_direct_flag")||SDM_IS(dbx_attribute_indirect,"id_and_direct_flag")||SDM_IS(dbx_attribute_message,"id_and_direct_flag"))comment=(v&128)?((v&127)==4?L"First message block; value stored directly":L"Direct attribute value"):((v&127)==4?L"First message block; value is data-area offset":L"Indirect attribute; offset into data area");
 else if(SDM_IS(dbx_attribute,"direct_value"))comment=L"24-bit direct attribute value";
 else if(SDM_IS(dbx_attribute_indirect,"data_offset"))comment=L"Byte offset relative to attribute data area, after all attribute words";
 else if(SDM_IS(dbx_attribute_message,"first_block_offset"))comment=L"Byte offset relative to file base, stored directly in the attribute";
 else if(r->property==SX_OFFSET)comment=L"Byte offset relative to file base";
 else if((!xx_rt_wcscmp(r->name,L"root_page")||!xx_rt_wcscmp(r->name,L"previous_page")||!xx_rt_wcscmp(r->name,L"next_page")||!xx_rt_wcscmp(r->name,L"child_page")||!xx_rt_wcscmp(r->name,L"last_leaf_page"))&&r->property==SX_ID)comment=L"Page index; sentinel values may denote no page";
#undef SDM_IS
 return !comment||xx_data_struct_record_set_comment(r,comment);
}
const sx_family sx_docmeta_family={sx_docmeta_supports,sx_docmeta_build,sx_docmeta_layouts,SX_COUNT(sx_docmeta_layouts),sx_docmeta_comment};
