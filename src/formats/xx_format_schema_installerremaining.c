/* SPDX-License-Identifier: MIT
 * Bounded physical installer records; compressed and encoded metadata stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_installerremaining.h"
static const xx_data_struct_field_desc sxir_nsis_firstheader_fields[]={
 SX_FIELD("flags","int32le",0,4,SX_FLAGS),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
 SX_FIELD("nsinst","uint32le[3]",8,12,SX_SIGNATURE),
 SX_FIELD("length_of_header","int32le",20,4,SX_SIZE),
 SX_FIELD("length_of_all_following_data","int32le",24,4,SX_SIZE),
};
const sx_layout sxir_nsis_firstheader={0x60800001U,"nsis_firstheader",sxir_nsis_firstheader_fields,SX_COUNT(sxir_nsis_firstheader_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxir_installer_name={0x60800008U,"installer_name",sxir_installer_name_fields,SX_COUNT(sxir_installer_name_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_terminator_fields[]={
 SX_FIELD("nul","uint8",0,1,SX_RESERVED),
};
const sx_layout sxir_installer_terminator={0x6080000aU,"installer_terminator",sxir_installer_terminator_fields,SX_COUNT(sxir_installer_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxir_cookfs_footer_fields[]={
 SX_FIELD("stored_index_size","uint32be",0,4,SX_SIZE),
 SX_FIELD("page_count","uint32be",4,4,SX_COUNT_PROP),
 SX_FIELD("default_compression_method","uint8",8,1,SX_ID),
 SX_FIELD("signature","char[7]",9,7,SX_SIGNATURE),
};
const sx_layout sxir_cookfs_footer={0x6080000cU,"cookfs_footer",sxir_cookfs_footer_fields,SX_COUNT(sxir_cookfs_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_blob_fields[]={
 SX_FIELD("compression_method","uint8",0,1,SX_ID),
};
const sx_layout sxir_cookfs_blob={0x6080000fU,"cookfs_blob",sxir_cookfs_blob_fields,SX_COUNT(sxir_cookfs_blob_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_entry_fields[]={
 SX_FIELD("mtime","uint64be",0,8,SX_TIME),
 SX_FIELD("block_count","int32be",8,4,SX_COUNT_PROP),
};
const sx_layout sxir_cookfs_entry={0x60800013U,"cookfs_entry",sxir_cookfs_entry_fields,SX_COUNT(sxir_cookfs_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxir_sim_footer_fields[]={
 SX_FIELD("strings_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("runtime_size","uint64le",8,8,SX_SIZE),
 SX_FIELD("runtime_offset","uint64le",16,8,SX_OFFSET),
 SX_FIELD("content_offset","uint64le",24,8,SX_OFFSET),
 SX_FIELD("compressed_runtime","uint8",32,1,SX_FLAGS),
 SX_FIELD("runtime_count","uint8",33,1,SX_COUNT_PROP),
 SX_FIELD("header_string_count","uint8",34,1,SX_COUNT_PROP),
 SX_FIELD("signature","uint8",35,1,SX_SIGNATURE),
};
const sx_layout sxir_sim_footer={0x60800015U,"sim_footer",sxir_sim_footer_fields,SX_COUNT(sxir_sim_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_label_fields[]={
 SX_FIELD("label_size","uint32le",0,4,SX_SIZE),
 SX_FIELD("label_kind","uint32le",4,4,SX_ID),
};
const sx_layout sxir_lyme_label={0x60800034U,"lyme_label",sxir_lyme_label_fields,SX_COUNT(sxir_lyme_label_fields),SX_LE};
static const xx_data_struct_field_desc sxir_instalit_dcl_header_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
const sx_layout sxir_instalit_dcl_header={0x60800035U,"instalit_dcl_header",sxir_instalit_dcl_header_fields,SX_COUNT(sxir_instalit_dcl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_string_pool_fields[]={
 SX_FIELD("strings","uint8",0,0,SX_NONE),
};
const sx_layout sxir_nsis_string_pool={0x6080003eU,"nsis_string_pool",sxir_nsis_string_pool_fields,SX_COUNT(sxir_nsis_string_pool_fields),SX_LE};
static const sx_layout*const sx_installerremaining_layouts[]={&sxir_nsis_firstheader,&sxir_nsis_common_flags,&sxir_nsis_block32,&sxir_nsis_block64,&sxir_nsis_instruction,&sxir_nsis_block_length,&sxir_installer_crc32,&sxir_installer_name,&sxir_installer_utf8,&sxir_installer_terminator,&sxir_installer_size,&sxir_cookfs_footer,&sxir_cookfs_page_digest,&sxir_cookfs_page_size,&sxir_cookfs_blob,&sxir_cookfs_index,&sxir_cookfs_directory,&sxir_cookfs_name_length,&sxir_cookfs_entry,&sxir_cookfs_block,&sxir_sim_footer,&sxir_sim_stored_file,&sxir_excelsior_header,&sxir_excelsior_lzma_stream,&sxir_fead_outer_prefix,&sxir_fead_encoded_header,&sxir_superdat_group,&sxir_superdat_member,&sxir_superdat_lh1_stream,&sxir_superdat_group_trailer,&sxir_superdat_original_footer,&sxir_superdat_footer_v0,&sxir_superdat_footer_v1,&sxir_superdat_footer_v12,&sxir_superdat_manifest_170,&sxir_superdat_manifest_178,&sxir_solaris_zip_signature,&sxir_solaris_zip_object,&sxir_solaris_zip_group,&sxir_solaris_zip_block,&sxir_desksoft_header,&sxir_desksoft_end,&sxir_metaproducts_header,&sxir_metaproducts_member,&sxir_metaproducts_footer,&sxir_visualware_header,&sxir_visualware_legacy_header,&sxir_visualware_legacy_data_header,&sxir_lyme_footer,&sxir_lyme_member,&sxir_lyme_name_length,&sxir_lyme_label,&sxir_instalit_dcl_header,&sxir_softpaq4_descriptor_0,&sxir_softpaq4_descriptor_8,&sxir_softpaq4_name_length,&sxir_softpaq4_footer,&sxir_inftool_header_22,&sxir_inftool_header_24,&sxir_active_delivery_header,&sxir_lyme_zero_sentinel,&sxir_nsis_string_pool};
static bool sx_installerremaining_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x60800000U||id>=0x60810000U)return true;
 if(id==sxir_nsis_string_pool.id)return xx_data_struct_record_set_comment(r,L"Stored NSIS string pool, ANSI or UTF-16LE depending on the installer; bytes preserve every terminator and string-control opcode.");
 if(!xx_rt_wcscmp(r->name,L"header_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the beginning of the decoded NSIS common header; this view exposes only stored headers.");
 if(!xx_rt_wcscmp(r->name,L"page_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in the decoded CookFS page identified by page_index.");
 if(!xx_rt_wcscmp(r->name,L"group_relative_offset"))return xx_data_struct_record_set_comment(r,L"Physical byte offset from the beginning of this TG block group.");
 if(!xx_rt_wcscmp(r->name,L"encoded_payload_size"))return xx_data_struct_record_set_comment(r,L"Masked bytes of the FEAD payload length; these bytes are displayed without decoding the header.");
 if(!xx_rt_wcscmp(r->name,L"digest"))return xx_data_struct_record_set_comment(r,L"MD5 digest of the decoded CookFS page; displaying the digest does not validate it.");
 if(!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"SuperDAT member checksum; classification 2 uses the vendor DAT checksum, other types use reflected CRC with zero initialization and final XOR.");
 if(!xx_rt_wcscmp(r->name,L"encoded_block_size"))return xx_data_struct_record_set_comment(r,L"Bit 31 marks a compressed block; bits 0..30 give the number of stored payload bytes.");
 if(!xx_rt_wcscmp(r->name,L"year_since_1900"))return xx_data_struct_record_set_comment(r,L"Calendar year minus 1900.");
 if(id==sxir_sim_footer.id&&(r->property&SX_OFFSET))return xx_data_struct_record_set_comment(r,L"Stored file offset; launchers may relocate all three offsets by the common delta to the version string. The stored value is preserved.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Physical byte offset relative to the beginning of this installer file.");
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 uint64_t n=xx_var_get_u64(&r->value);
 if(id==sxir_cookfs_entry.id&&!xx_rt_wcscmp(r->name,L"block_count"))return xx_data_struct_record_set_comment(r,xx_var_get_i64(&r->value)==-1?L"DIRECTORY (-1); a recursive directory follows":L"Number of page-slice triples following this file entry");
 if(id==sxir_cookfs_entry.id&&!xx_rt_wcscmp(r->name,L"mtime"))return xx_data_struct_record_set_comment(r,L"CookFS modification timestamp.");
 if(id==sxir_nsis_firstheader.id&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"UNINSTALL=0x1 | SILENT=0x2 | NO_CRC=0x4 | FORCE_CRC=0x8; unknown bits are preserved.");
 if((id==sxir_cookfs_blob.id&&!xx_rt_wcscmp(r->name,L"compression_method"))||(id==sxir_cookfs_footer.id&&!xx_rt_wcscmp(r->name,L"default_compression_method")))return xx_data_struct_record_set_comment(r,n==0?L"STORED":n==1?L"DEFLATE":n==2?L"BZIP2":n==255?L"CUSTOM (LZMA-Alone in supported BitRock files)":L"Other CookFS compression method");
 if(id==sxir_instalit_dcl_header.id&&!xx_rt_wcscmp(r->name,L"literal_mode"))return xx_data_struct_record_set_comment(r,n==0?L"BINARY_LITERALS":n==1?L"HUFFMAN_LITERALS":L"Unknown literal mode");
 if(id==sxir_instalit_dcl_header.id&&!xx_rt_wcscmp(r->name,L"dictionary_bits"))return xx_data_struct_record_set_comment(r,n==4?L"1024-byte dictionary":n==5?L"2048-byte dictionary":n==6?L"4096-byte dictionary":L"Unsupported dictionary size");
 if(id==sxir_lyme_label.id&&!xx_rt_wcscmp(r->name,L"label_kind"))return xx_data_struct_record_set_comment(r,n==1?L"APPLICATION_LABEL":n==3?L"DIRECTORY_LABEL":L"Unknown label kind");
 return true;}
bool sxir_span(sxir_view*v,uint64_t at,uint64_t z,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&end<=(uint64_t)v->c->size&&at<=end&&z<=end-at;}
bool sxir_read(sxir_view*v,uint64_t at,void*b,size_t z,uint64_t end)
{return ++v->work<=4000000&&sxir_span(v,at,z,end)&&sx_read(v->c,(int64_t)at,b,z);}
bool sxir_u(sxir_view*v,uint64_t at,unsigned z,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!z||z>8||!sxir_read(v,at,b,z,end))return false;*out=0;for(unsigned i=0;i<z;i++)*out|=(uint64_t)b[i]<<((be?z-1-i:i)*8);return true;}
bool sxir_eq(sxir_view*v,uint64_t at,const char*s,size_t z,uint64_t end)
{uint8_t b[64];return z<=sizeof(b)&&sxir_read(v,at,b,z,end)&&!xx_rt_memcmp(b,s,z);}
bool sxir_emit(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end)
{if(!sxir_span(v,at,z,end))return false;if(!z||v->c->count>=24000)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if(z<(uint64_t)f->rel_offset)return false;if(!f->size&&z-(uint64_t)f->rel_offset>(uint64_t)sx_variable_field_limit(f->type))return true;return sx_add(v->c,l,(int64_t)at,(int64_t)z);}
bool sxir_row(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return sxir_emit(v,l,at,(uint64_t)(f->rel_offset+f->size),end);}
bool sxir_table(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>4000000||n>UINT64_MAX/z||!sxir_span(v,at,n*z,end))return false;for(uint64_t i=0;i<n&&v->c->count<24000;i++,at+=z)if(!sxir_row(v,l,at,end))return false;return true;}
bool sxir_zstr(sxir_view*v,uint64_t*at,uint64_t end,uint64_t*length)
{uint64_t p=*at;uint8_t b;while(*at<end&&*at-p<=1048576){if(!sxir_read(v,(*at)++,&b,1,end))return false;if(!b){*length=*at-p-1;return sxir_emit(v,&sxir_installer_name,p,*length,end)&&sxir_row(v,&sxir_installer_terminator,*at-1,end);}}return false;}
bool sxir_find(sxir_view*v,uint64_t begin,uint64_t end,const char*sig,size_t z,bool last,uint64_t*out)
{uint8_t b[4096];bool found=false;if(!z||z>64||begin>end)return false;while(end-begin>=z){size_t n=end-begin>sizeof(b)?sizeof(b):(size_t)(end-begin);if(!sxir_read(v,begin,b,n,end))return false;for(size_t i=0;i+z<=n;i++)if(!xx_rt_memcmp(b+i,sig,z)){*out=begin+i;found=true;if(!last)return true;}if(n==end-begin)break;begin+=n-z+1;}return found;}
bool sxir_pe(sxir_view*v,uint64_t start,uint64_t end,uint64_t*out,uint64_t*certificate)
{uint64_t pe,sections,opt,headers,at;*certificate=end;if(!sxir_eq(v,start,"MZ",2,end)){*out=start;return true;}if(!sxir_u(v,start+60,4,false,&pe,end)||pe>16777216||pe>end-start||!sxir_eq(v,start+pe,"PE\0\0",4,end)||!sxir_u(v,start+pe+6,2,false,&sections,end)||!sections||sections>96||!sxir_u(v,start+pe+20,2,false,&opt,end)||opt<64||opt>4096||!sxir_u(v,start+pe+84,4,false,&headers,end))return false;at=start+pe+24+opt;if(!sxir_span(v,at,sections*40,end)||headers<pe+24+opt+sections*40||headers>end-start)return false;*out=start+headers;
 for(uint64_t i=0;i<sections;i++){uint64_t size,offset;if(!sxir_u(v,at+i*40+16,4,false,&size,end)||!sxir_u(v,at+i*40+20,4,false,&offset,end)||offset>end-start||!sxir_span(v,start+offset,size,end))return false;if(size&&start+offset+size>*out)*out=start+offset+size;}
 uint64_t magic;if(!sxir_u(v,start+pe+24,2,false,&magic,end))return false;uint64_t dd=magic==0x10b?128:magic==0x20b?144:0;
 if(dd&&opt>=dd+8){uint64_t off,size;if(!sxir_u(v,start+pe+24+dd,4,false,&off,end)||!sxir_u(v,start+pe+24+dd+4,4,false,&size,end))return false;if(size>=8&&off&&off<=end-start&&sxir_span(v,start+off,size,end)){uint64_t a=start+off,finish=a+size;bool valid=true;while(a<finish){uint64_t z,revision,type;if(!sxir_u(v,a,4,false,&z,finish)||z<8||!sxir_span(v,a,z,finish)||!sxir_u(v,a+4,2,false,&revision,finish)||revision!=0x200||!sxir_u(v,a+6,2,false,&type,finish)||type!=2){valid=false;break;}uint64_t pad=(8-(z&7))&7;if(z+pad>finish-a){valid=false;break;}a+=z+pad;}if(valid&&a==finish){if(finish==end)*certificate=start+off;if(start+off==*out)*out=finish;}}}
 return true;}
static int sxir_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxir_finish(sx_context*c)
{size_t n=c->count,k=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxir_order);for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a<end)continue;c->items[k++]=c->items[i];end=a+z;}c->count=k;n=k;end=0;for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a>end&&!sx_raw(c,end,a-end))return false;end=a+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxir_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_installerremaining_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NSIS:case XX_FILE_TYPE_BITROCK:case XX_FILE_TYPE_SMART_INSTALL_MAKER:case XX_FILE_TYPE_EXCELSIOR_INSTALLER:case XX_FILE_TYPE_NETOPSYSTEMS_FEAD:case XX_FILE_TYPE_SUPERDAT:case XX_FILE_TYPE_SOLARISPKG_ZIP:case XX_FILE_TYPE_DESKSOFT:case XX_FILE_TYPE_METAPRODUCTS:case XX_FILE_TYPE_VISUALWARE:case XX_FILE_TYPE_LYME_SFX:case XX_FILE_TYPE_INSTALIT_DATA:case XX_FILE_TYPE_SFX_AD01:case XX_FILE_TYPE_SFX_SOFTPAQ4:case XX_FILE_TYPE_SFX_INFTOOL:return true;default:return false;}}
static bool sx_installerremaining_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NSIS:ok=sx_nsis_build(c);break;case XX_FILE_TYPE_BITROCK:ok=sx_bitrock_build(c);break;case XX_FILE_TYPE_SMART_INSTALL_MAKER:ok=sx_smart_install_maker_build(c);break;case XX_FILE_TYPE_EXCELSIOR_INSTALLER:ok=sx_excelsior_build(c);break;case XX_FILE_TYPE_NETOPSYSTEMS_FEAD:ok=sx_fead_build(c);break;case XX_FILE_TYPE_SUPERDAT:ok=sx_superdat_build(c);break;case XX_FILE_TYPE_SOLARISPKG_ZIP:ok=sx_solarispkg_zip_build(c);break;case XX_FILE_TYPE_DESKSOFT:ok=sx_desksoft_build(c);break;case XX_FILE_TYPE_METAPRODUCTS:ok=sx_metaproducts_build(c);break;case XX_FILE_TYPE_VISUALWARE:ok=sx_visualware_build(c);break;case XX_FILE_TYPE_LYME_SFX:ok=sx_lyme_sfx_build(c);break;case XX_FILE_TYPE_INSTALIT_DATA:ok=sx_instalit_data_build(c);break;case XX_FILE_TYPE_SFX_AD01:ok=sx_sfx_ad01_build(c);break;case XX_FILE_TYPE_SFX_SOFTPAQ4:ok=sx_sfx_softpaq4_build(c);break;case XX_FILE_TYPE_SFX_INFTOOL:ok=sx_sfx_inftool_build(c);break;default:break;}return ok&&sxir_finish(c);}
const sx_family sx_installerremaining_family={sx_installerremaining_supports,sx_installerremaining_build,sx_installerremaining_layouts,SX_COUNT(sx_installerremaining_layouts),sx_installerremaining_comment};
