/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivestreams_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivestreams.h"
static const xx_data_struct_field_desc sxas_ibmpack_prefix_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("dialect","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("attributes","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxas_ibmpack_prefix = {UINT32_C(0x60430020),"ibmpack_prefix",sxas_ibmpack_prefix_fields,SX_COUNT(sxas_ibmpack_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ibmpack_chain_fields[] = {
 SX_FIELD("opaque_padding","uint8[3]",0,3,SX_NONE),
 SX_FIELD("extended_attributes_offset","uint32",3,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("next_header_offset","uint32",11,4,SX_OFFSET),
 SX_FIELD("name_field_size","uint16",15,2,SX_SIZE),
};
static const sx_layout sxas_ibmpack_chain = {UINT32_C(0x60430021),"ibmpack_chain",sxas_ibmpack_chain_fields,SX_COUNT(sxas_ibmpack_chain_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ftcomp_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("dialect","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("attributes","uint8",8,1,SX_FLAGS),
 SX_FIELD("opaque_padding","uint8[3]",9,3,SX_NONE),
 SX_FIELD("extended_attributes_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("next_header_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("signature2","char[7]",24,7,SX_SIGNATURE),
 SX_FIELD("opaque_word","uint16",31,2,SX_NONE),
 SX_FIELD("selector","uint16",33,2,SX_NONE),
 SX_FIELD("opaque_dword","uint32",35,4,SX_NONE),
 SX_FIELD("name_field_size","uint16",39,2,SX_SIZE),
};
static const sx_layout sxas_ftcomp_header = {UINT32_C(0x60430028),"ftcomp_header",sxas_ftcomp_header_fields,SX_COUNT(sxas_ftcomp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ibmpack_fixed_name_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
static const sx_layout sxas_ibmpack_fixed_name = {UINT32_C(0x6043002b),"ibmpack_fixed_name",sxas_ibmpack_fixed_name_fields,SX_COUNT(sxas_ibmpack_fixed_name_fields),SX_LE};
static const sx_layout *const sx_archivestreams_layouts[] = {
 &sxas_sqze_header,
 &sxas_csq_header,
 &sxas_csq_entry,
 &sxas_zoot1_header,
 &sxas_zoot1_entry137,
 &sxas_zoot1_entry235,
 &sxas_rdfz_header,
 &sxas_rdfz_count,
 &sxas_rdfz_entry,
 &sxas_rdfz_member_size,
 &sxas_asd_header,
 &sxas_asd_name_length,
 &sxas_asd_entry,
 &sxas_fox_sqz_header,
 &sxas_fox_sqz_member,
 &sxas_fox_sqz_end,
 &sxas_lds_header,
 &sxas_lds_count,
 &sxas_lds_entry,
 &sxas_webexe_header,
 &sxas_webexe_zip_local,
 &sxas_webexe_zip_central,
 &sxas_webexe_zip_end,
 &sxas_pma_header,
 &sxas_pma_crc16,
 &sxas_lhf_header,
 &sxas_lhf_entry,
 &sxas_ecmpacked_header,
 &sxas_chieflz_prefix,
 &sxas_chieflz_name_size,
 &sxas_chieflz_method,
 &sxas_ibmpack_prefix,
 &sxas_ibmpack_chain,
 &sxas_cazip_header,
 &sxas_cazip_dcl_prefix,
 &sxas_tpwm_header,
 &sxas_mrnz_header,
 &sxas_edc_header,
 &sxas_winlink_header,
 &sxas_ftcomp_header,
 &sxas_crunch_magic,
 &sxas_crunch_parameters,
 &sxas_ibmpack_fixed_name,
};
static bool sx_archivestreams_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60430000U||id>=0x60440000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60430003U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 LZSS; both payload forms have a position-dependent byte XOR.";
 break;
 case 0x60430004U:
 if(!xx_rt_wcscmp(r->name,L"directory_size"))text=L"Complete directory bytes after 12-byte header.";
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"0x272e,0x2738 or0x2739.";
 break;
 case 0x60430005U:
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"Physical file position is directory_size+this value+11.";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L"0xfffe marks an unused entry.";
 if(!xx_rt_wcscmp(r->name,L"class_word"))text=L"Native skips values>=20 in versions 0x2738/0x2739.";
 break;
 case 0x60430006U:
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"Physical file position is directory_size+this value+11.";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L"0xfffe marks an unused entry.";
 if(!xx_rt_wcscmp(r->name,L"class_word"))text=L"Native skips values>=20 in versions 0x2738/0x2739.";
 break;
 case 0x60430007U:
 if(!xx_rt_wcscmp(r->name,L"packed_index_size"))text=L"Includes 4 bytes beyond the zlib stream occupied by the member count.";
 break;
 case 0x60430009U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored; 1 four-byte uncompressed size then zlib.";
 break;
 case 0x6043000eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 LZSS or 4 DCL when payload is compressed.";
 break;
 case 0x6043000fU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x00eb file;0x00fe terminator.";
 break;
 case 0x60430010U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x00fe; remaining 21 bytes of end record have no established member semantics.";
 break;
 case 0x60430016U:
 if(!xx_rt_wcscmp(r->name,L"local_header_offset"))text=L"Stored ZIP-relative offset; not rewritten for the carrier.";
 break;
 case 0x60430017U:
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Stored ZIP-relative offset.";
 break;
 case 0x60430018U:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Complete header byte size minus 2.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-pm0- stored,-pm1- and-pm2- compressed.";
 break;
 case 0x6043001bU:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"0 means stored;0xffffffff directory-only sentinel.";
 break;
 case 0x6043001fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"4 ChiefLZ adaptive Huffman/LZ.";
 break;
 case 0x60430020U:
 if(!xx_rt_wcscmp(r->name,L"dialect"))text=L"0x0a14/0x1400 PACK1;0xffff plain;0xfffe chained.";
 break;
 case 0x60430021U:
 if(!xx_rt_wcscmp(r->name,L"extended_attributes_offset"))text=L"File-relative only when it falls inside the member; small values can be unknown metadata.";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"0 or 1 means length not recorded.";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"File-relative;0 means last member.";
 break;
 case 0x60430022U:
 if(!xx_rt_wcscmp(r->name,L"volume_flag"))text=L"1 complete stream;2 may require following volumes.";
 break;
 case 0x60430023U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 uncoded literals;1 coded literals.";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Dictionary exponent 4, 5 or 6.";
 break;
 case 0x60430025U:
 if(!xx_rt_wcscmp(r->name,L"xor_prefix_size"))text=L"Only this many payload bytes are XORed with0xae; no compression by this layer.";
 break;
 case 0x60430026U:
 if(!xx_rt_wcscmp(r->name,L"member_size"))text=L"Includes 41-byte header.";
 break;
 case 0x6043002aU:
 if(!xx_rt_wcscmp(r->name,L"decoder_version"))text=L"High nibble 1 selects older coding, 2 newer.";
 if(!xx_rt_wcscmp(r->name,L"checksum_flag"))text=L"0 has additive 16-bit checksum; 1 omits it.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAS_LIMIT 20000U
bool sxas_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxas_read(sx_context*c,uint64_t p,void*b,size_t n){return sxas_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxas_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxas_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxas_read(c,p,b,n))return false;*v=sxas_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
bool sxas_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAS_LIMIT||!sxas_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxas_ibm(sx_context*c,bool ft){uint64_t p=0;for(unsigned i=0;i<SXAS_LIMIT;i++){uint64_t variant,next=0,n=0;if(!sxas_word(c,p+2,2,false,&variant))return false;if(ft){if(variant!=0xfffd||!sxas_word(c,p+20,4,false,&next)||!sxas_word(c,p+39,2,false,&n)||!sxas_span(c,p+41,n)||!sxas_add(c,&sxas_ftcomp_header,p))return false;}else{if(!sxas_add(c,&sxas_ibmpack_prefix,p))return false;if(variant==0xfffe){if(!sxas_word(c,p+20,4,false,&next)||!sxas_word(c,p+24,2,false,&n)||!sxas_span(c,p+26,n)||!sxas_add(c,&sxas_ibmpack_chain,p+9))return false;}else if(variant==0x0a14||variant==0x1400){if(!sxas_add(c,&sxas_ibmpack_fixed_name,p+10))return false;}else if(variant!=0xffff)return false;}if(!next)return true;if(next<=p||next>(uint64_t)c->size)return false;p=next;}return false;}
static int sxas_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxas_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxas_order);return !c->failed;}
static bool sx_archivestreams_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_SQZE:case XX_FILE_TYPE_CSQ:case XX_FILE_TYPE_ZOOT1:case XX_FILE_TYPE_RDFZ:case XX_FILE_TYPE_ASD:case XX_FILE_TYPE_FOX_SQZ:case XX_FILE_TYPE_LDS:case XX_FILE_TYPE_WEBEXE:case XX_FILE_TYPE_PMA:case XX_FILE_TYPE_LHF:case XX_FILE_TYPE_ECMPACKED:case XX_FILE_TYPE_CHIEFLZ:case XX_FILE_TYPE_IBMPACK:case XX_FILE_TYPE_CAZIP:case XX_FILE_TYPE_TPWM:case XX_FILE_TYPE_MRNZ:case XX_FILE_TYPE_EDC:case XX_FILE_TYPE_WINLINK:case XX_FILE_TYPE_FTCOMP:case XX_FILE_TYPE_CPM_CRUNCH:return true;default:return false;}}
static bool sx_archivestreams_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SQZE:ok=sx_sqze_build(c);break;case XX_FILE_TYPE_CSQ:ok=sx_csq_build(c);break;case XX_FILE_TYPE_ZOOT1:ok=sx_zoot1_build(c);break;case XX_FILE_TYPE_RDFZ:ok=sx_rdfz_build(c);break;case XX_FILE_TYPE_ASD:ok=sx_asd_build(c);break;case XX_FILE_TYPE_FOX_SQZ:ok=sx_fox_sqz_build(c);break;case XX_FILE_TYPE_LDS:ok=sx_lds_build(c);break;case XX_FILE_TYPE_WEBEXE:ok=sx_webexe_build(c);break;case XX_FILE_TYPE_PMA:ok=sx_pma_build(c);break;case XX_FILE_TYPE_LHF:ok=sx_lhf_build(c);break;case XX_FILE_TYPE_ECMPACKED:ok=sx_ecmpacked_build(c);break;case XX_FILE_TYPE_CHIEFLZ:ok=sx_chieflz_build(c);break;case XX_FILE_TYPE_IBMPACK:ok=sx_ibmpack_build(c);break;case XX_FILE_TYPE_CAZIP:ok=sx_cazip_build(c);break;case XX_FILE_TYPE_TPWM:ok=sx_tpwm_build(c);break;case XX_FILE_TYPE_MRNZ:ok=sx_mrnz_build(c);break;case XX_FILE_TYPE_EDC:ok=sx_edc_build(c);break;case XX_FILE_TYPE_WINLINK:ok=sx_winlink_build(c);break;case XX_FILE_TYPE_FTCOMP:ok=sx_ftcomp_build(c);break;case XX_FILE_TYPE_CPM_CRUNCH:ok=sx_cpm_crunch_build(c);break;default:break;}(void)ok;return c->count&&sxas_finish(c);}
const sx_family sx_archivestreams_family={sx_archivestreams_supports,sx_archivestreams_build,sx_archivestreams_layouts,SX_COUNT(sx_archivestreams_layouts),sx_archivestreams_comment};
