/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivefinal_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivefinal.h"

static const xx_data_struct_field_desc sxaf_squeeze1_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
};
static const sx_layout sxaf_squeeze1_header = {UINT32_C(0x603c000a),"squeeze1_header",sxaf_squeeze1_header_fields,SX_COUNT(sxaf_squeeze1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze2_magic_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxaf_squeeze2_magic = {UINT32_C(0x603c000b),"squeeze2_magic",sxaf_squeeze2_magic_fields,SX_COUNT(sxaf_squeeze2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze2_header_fields[] = {
 SX_FIELD("empty_field","uint8",0,1,SX_NONE),
 SX_FIELD("end_of_text","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("node_count","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sxaf_squeeze2_header = {UINT32_C(0x603c000c),"squeeze2_header",sxaf_squeeze2_header_fields,SX_COUNT(sxaf_squeeze2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze_node_count_fields[] = {
 SX_FIELD("node_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxaf_squeeze_node_count = {UINT32_C(0x603c000d),"squeeze_node_count",sxaf_squeeze_node_count_fields,SX_COUNT(sxaf_squeeze_node_count_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze_tree_node_fields[] = {
 SX_FIELD("left_child","int16",0,2,SX_NONE),
 SX_FIELD("right_child","int16",2,2,SX_NONE),
};
static const sx_layout sxaf_squeeze_tree_node = {UINT32_C(0x603c000e),"squeeze_tree_node",sxaf_squeeze_tree_node_fields,SX_COUNT(sxaf_squeeze_tree_node_fields),SX_LE};
static const sx_layout *const sx_archivefinal_layouts[] = {
 &sxaf_nar_string_length,
 &sxaf_phar_manifest_prefix,
 &sxaf_phar_api_version,
 &sxaf_phar_manifest_flags,
 &sxaf_phar_metadata_length,
 &sxaf_phar_name_length,
 &sxaf_phar_file_entry,
 &sxaf_phar_signature_footer,
 &sxaf_stuffit_split_header,
 &sxaf_squeeze1_header,
 &sxaf_squeeze2_magic,
 &sxaf_squeeze2_header,
 &sxaf_squeeze_node_count,
 &sxaf_squeeze_tree_node,
 &sxaf_sq_magic,
 &sxaf_sq_calendar,
 &sxaf_lspack10_member,
 &sxaf_rnca_header,
 &sxaf_rnca_directory_offset,
 &sxaf_rnca_stored_member,
 &sxaf_rnca_compressed_member,
 &sxaf_bagf_header,
 &sxaf_ixa_header,
 &sxaf_ixa_entry,
 &sxaf_bga_member,
 &sxaf_dfc_header,
 &sxaf_dfc_entry,
 &sxaf_ka_header,
 &sxaf_ka_entry,
 &sxaf_cdaf_header,
 &sxaf_cdaf_member,
 &sxaf_cdaf_chunk,
 &sxaf_spack_magic,
 &sxaf_spack_stored_member,
 &sxaf_spack_compressed_member,
 &sxaf_spack_footer,
 &sxaf_pcompress_magic,
 &sxaf_pcompress_member_size,
 &sxaf_pcompress_lh_block,
 &sxaf_mxm_simplearc_member,
 &sxaf_lif_header,
 &sxaf_dn_data_header,
 &sxaf_dn_directory_header,
 &sxaf_dn_end_marker,
 &sxaf_insa_version,
 &sxaf_insa_member,
};
static bool sx_archivefinal_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x603c0000U||id>=0x603d0000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x603c0001U:
 if(!xx_rt_wcscmp(r->name,L"byte_length"))text=L"NAR string byte length; following bytes are padded to an8-byte boundary.";
 break;
 case 0x603c0003U:
 if(!xx_rt_wcscmp(r->name,L"api_version"))text=L"Three big-endian version nibbles: major/minor/patch, followed by zero nibble.";
 break;
 case 0x603c0004U:
 if(!xx_rt_wcscmp(r->name,L"global_flags"))text=L"0x10000 signature present; other unused bits reserved.";
 break;
 case 0x603c0007U:
 if(!xx_rt_wcscmp(r->name,L"unix_timestamp"))text=L"Seconds since1970-01-01.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Low9bits permissions;0x1000 DEFLATE;0x2000 BZIP2.";
 break;
 case 0x603c0008U:
 if(!xx_rt_wcscmp(r->name,L"signature_type"))text=L"1 MD5,2 SHA1,3 SHA256,4 SHA512,16 OpenSSL.";
 break;
 case 0x603c0009U:
 if(!xx_rt_wcscmp(r->name,L"part_number"))text=L"One-based segment number.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01.";
 if(!xx_rt_wcscmp(r->name,L"resource_fork_size"))text=L"Whole original resource fork, not this segment.";
 if(!xx_rt_wcscmp(r->name,L"data_fork_size"))text=L"Whole original data fork, not this segment.";
 if(!xx_rt_wcscmp(r->name,L"segment_bookkeeping"))text=L"Stored bookkeeping bytes; semantics not established.";
 break;
 case 0x603c000aU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes modulo65536.";
 break;
 case 0x603c000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes modulo65536.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: year since1980/month/day.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: hour/minute/2-second count.";
 break;
 case 0x603c000eU:
 if(!xx_rt_wcscmp(r->name,L"left_child"))text=L"Nonnegative node index; negative value encodes symbol=-(value+1),256=end.";
 if(!xx_rt_wcscmp(r->name,L"right_child"))text=L"Nonnegative node index; negative value encodes symbol=-(value+1),256=end.";
 break;
 case 0x603c0011U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored;2 raw DEFLATE.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 break;
 case 0x603c0012U:
 if(!xx_rt_wcscmp(r->name,L"directory_checkword"))text=L"Stored checkword; native reader does not validate its algorithm.";
 break;
 case 0x603c0015U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"RNC method1 or2.";
 break;
 case 0x603c0016U:
 if(!xx_rt_wcscmp(r->name,L"positive_word"))text=L"Native reader requires positive; meaning is unknown.";
 if(!xx_rt_wcscmp(r->name,L"class_word0"))text=L"Observed selector; semantics unknown.";
 if(!xx_rt_wcscmp(r->name,L"class_word1"))text=L"Observed selector; semantics unknown.";
 break;
 case 0x603c0017U:
 if(!xx_rt_wcscmp(r->name,L"fixed_word"))text=L"Native requires0x30; further semantics are not established.";
 if(!xx_rt_wcscmp(r->name,L"slot_count_plus_one"))text=L"Directory row count is this value minus one.";
 break;
 case 0x603c0019U:
 if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Sum of signed header/name bytes starting at offset4.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"0x10 directory.";
 if(!xx_rt_wcscmp(r->name,L"archive_type"))text=L"1 compressed,2 stored,0 autodetect based on length and suffix.";
 break;
 case 0x603c001bU:
 if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))text=L"Bitwise complement of the plaintext standard CRC32.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 PKWARE DCL;1 stored.";
 break;
 case 0x603c001eU:
 if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Complete file size minus8.";
 break;
 case 0x603c001fU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Name length plus20; excludes8-byte chunk prefix.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored;1..7 Shrink arithmetic/LZ.";
 break;
 case 0x603c0022U:
 if(!xx_rt_wcscmp(r->name,L"id_and_flags"))text=L"0x8000 stored;low15bits member ID.";
 break;
 case 0x603c0026U:
 if(!xx_rt_wcscmp(r->name,L"name_terminator"))text=L"Newline delimiter.";
 break;
 case 0x603c0027U:
 if(!xx_rt_wcscmp(r->name,L"raw_crc32"))text=L"CRC32 of packed bytes with initial state zero, no complement.";
 break;
 case 0x603c0028U:
 if(!xx_rt_wcscmp(r->name,L"next_record_delta"))text=L"Relative to current header;zero means final member.";
 break;
 case 0x603c0029U:
 if(!xx_rt_wcscmp(r->name,L"positive_word"))text=L"Native requires nonzero; semantics unknown.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"6 Zoo LZD.";
 break;
 case 0x603c002aU:
 if(!xx_rt_wcscmp(r->name,L"opaque_prefix"))text=L"Uninterpreted physical header bytes.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAF_LIMIT 20000U
bool sxaf_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxaf_read(sx_context*c,uint64_t p,void*b,size_t n){return sxaf_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxaf_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxaf_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxaf_read(c,p,b,n))return false;*v=sxaf_uint(b,n,be);return true;}
bool sxaf_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXAF_LIMIT&&sxaf_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
bool sxaf_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap,uint8_t stop){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxaf_read(c,(*p)++,&b,1))return false;if(b==stop)return true;}return false;}
bool sxaf_squeeze(sx_context*c,bool second){uint64_t p=second?2:4,n;if(!sxaf_add(c,second?&sxaf_squeeze2_magic:&sxaf_squeeze1_header,0)||!sxaf_zstr(c,&p,(uint64_t)c->size,256,0))return false;if(second){if(!sxaf_zstr(c,&p,(uint64_t)c->size,256,0)||!sxaf_word(c,p+8,2,false,&n)||!sxaf_add(c,&sxaf_squeeze2_header,p))return false;p+=10;}else{if(!sxaf_word(c,p,2,false,&n)||!sxaf_add(c,&sxaf_squeeze_node_count,p))return false;p+=2;}if(n>256||!sxaf_span(c,p,4*n))return false;for(uint64_t i=0;i<n;i++)if(!sxaf_add(c,&sxaf_squeeze_tree_node,p+4*i))return false;return true;}
bool sxaf_table(sx_context*c,const sx_layout*h,const sx_layout*entry,uint64_t off,unsigned width,uint64_t p,uint64_t stride){uint64_t count;if(!sxaf_word(c,off,width,false,&count)||!sxaf_span(c,p,count*stride)||!sxaf_add(c,h,0))return false;for(uint64_t i=0;i<count;i++)if(!sxaf_add(c,entry,p+i*stride))return false;return true;}
static int sxaf_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxaf_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxaf_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxaf_order);return !c->failed;}
static bool sx_archivefinal_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NIX_NAR:case XX_FILE_TYPE_PHAR:case XX_FILE_TYPE_STUFFIT_SPLIT_FILE:case XX_FILE_TYPE_SQUEEZE1:case XX_FILE_TYPE_SQUEEZE2:case XX_FILE_TYPE_SQ:case XX_FILE_TYPE_LSPACK10:case XX_FILE_TYPE_RNCA:case XX_FILE_TYPE_BAGF:case XX_FILE_TYPE_IXA:case XX_FILE_TYPE_BGA:case XX_FILE_TYPE_DFC:case XX_FILE_TYPE_KA:case XX_FILE_TYPE_SHRINK_CDAF:case XX_FILE_TYPE_SPACK:case XX_FILE_TYPE_PCOMPRESS_PACK:case XX_FILE_TYPE_MXM_SIMPLEARC:case XX_FILE_TYPE_LIF:case XX_FILE_TYPE_DN:case XX_FILE_TYPE_INSA:return true;default:return false;}}
static bool sx_archivefinal_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NIX_NAR:ok=sx_nix_nar_build(c);break;case XX_FILE_TYPE_PHAR:ok=sx_phar_build(c);break;case XX_FILE_TYPE_STUFFIT_SPLIT_FILE:ok=sx_stuffit_split_file_build(c);break;case XX_FILE_TYPE_SQUEEZE1:ok=sx_squeeze1_build(c);break;case XX_FILE_TYPE_SQUEEZE2:ok=sx_squeeze2_build(c);break;case XX_FILE_TYPE_SQ:ok=sx_sq_build(c);break;case XX_FILE_TYPE_LSPACK10:ok=sx_lspack10_build(c);break;case XX_FILE_TYPE_RNCA:ok=sx_rnca_build(c);break;case XX_FILE_TYPE_BAGF:ok=sx_bagf_build(c);break;case XX_FILE_TYPE_IXA:ok=sx_ixa_build(c);break;case XX_FILE_TYPE_BGA:ok=sx_bga_build(c);break;case XX_FILE_TYPE_DFC:ok=sx_dfc_build(c);break;case XX_FILE_TYPE_KA:ok=sx_ka_build(c);break;case XX_FILE_TYPE_SHRINK_CDAF:ok=sx_shrink_cdaf_build(c);break;case XX_FILE_TYPE_SPACK:ok=sx_spack_build(c);break;case XX_FILE_TYPE_PCOMPRESS_PACK:ok=sx_pcompress_pack_build(c);break;case XX_FILE_TYPE_MXM_SIMPLEARC:ok=sx_mxm_simplearc_build(c);break;case XX_FILE_TYPE_LIF:ok=sx_lif_build(c);break;case XX_FILE_TYPE_DN:ok=sx_dn_build(c);break;case XX_FILE_TYPE_INSA:ok=sx_insa_build(c);break;default:break;}(void)ok;return c->count&&sxaf_finish(c);}
const sx_family sx_archivefinal_family={sx_archivefinal_supports,sx_archivefinal_build,sx_archivefinal_layouts,SX_COUNT(sx_archivefinal_layouts),sx_archivefinal_comment};
