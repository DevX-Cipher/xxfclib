/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivesystems_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivesystems.h"

static const xx_data_struct_field_desc sxasy_archivesystems_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxasy_archivesystems_dcl = {UINT32_C(0x60440038),"archivesystems_dcl",sxasy_archivesystems_dcl_fields,SX_COUNT(sxasy_archivesystems_dcl_fields),SX_LE};
static const sx_layout *const sx_archivesystems_layouts[] = {
 &sxasy_arcv2_header,
 &sxasy_arcv2_block,
 &sxasy_arcv2_attributes,
 &sxasy_arcv4_header,
 &sxasy_arcv4_record,
 &sxasy_arcv4_tag_size,
 &sxasy_arcv4_name_size,
 &sxasy_arcv4_attributes,
 &sxasy_arcv4_data,
 &sxasy_cru_header,
 &sxasy_cru_entry,
 &sxasy_powerbbs_name,
 &sxasy_powerbbs_size1,
 &sxasy_powerbbs_size2,
 &sxasy_powerbbs_size4,
 &sxasy_fld_member,
 &sxasy_igf1_header,
 &sxasy_igf2_header,
 &sxasy_igf2_member56,
 &sxasy_igf2_member44,
 &sxasy_igf2_end,
 &sxasy_inteduft_header,
 &sxasy_inteduft_index,
 &sxasy_inteduft_member,
 &sxasy_jm93_header,
 &sxasy_miz_header,
 &sxasy_miz_member,
 &sxasy_mva_header,
 &sxasy_mva_member,
 &sxasy_povlab_header,
 &sxasy_povlab_attributes,
 &sxasy_povlab_extension_size,
 &sxasy_povlab_extension_type,
 &sxasy_qip1_member,
 &sxasy_qp_header,
 &sxasy_qp_index,
 &sxasy_qp_path,
 &sxasy_qp_member,
 &sxasy_rcf_header,
 &sxasy_rcf_entry,
 &sxasy_rcf_count,
 &sxasy_riversoft_header,
 &sxasy_riversoft_entry,
 &sxasy_tgcf_header,
 &sxasy_tgcf_list_offset,
 &sxasy_tgcf_crc,
 &sxasy_tgcf_member_prefix,
 &sxasy_tgcf_member_attributes,
 &sxasy_tgcf_member_flag,
 &sxasy_tgcf_payload_offset,
 &sxasy_trc_header,
 &sxasy_netwarepacked_header,
 &sxasy_netware2_record,
 &sxasy_netware2_metadata,
 &sxasy_netware2_packed,
 &sxasy_archivesystems_dcl,
 &sxasy_miz_footer,
};
static bool sx_archivesystems_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60440000U||id>=0x60450000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60440001U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"ARCV 0x0200";
 if(!xx_rt_wcscmp(r->name,L"volume_flags"))text=L"1 single, 2 first, 4 middle, 8 last volume";
 break;
 case 0x60440002U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1 whole, 2 split head, 8 split tail; 0x10 stored, 0x20 compressed";
 break;
 case 0x60440003U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Total compressed bytes across volumes";
 if(!xx_rt_wcscmp(r->name,L"dos_timestamp"))text=L"Packed DOS date and time";
 if(!xx_rt_wcscmp(r->name,L"packed_crc32"))text=L"CRC-32/JAMCRC of the stored packed bytes";
 break;
 case 0x60440004U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"ARCV 0x0400";
 if(!xx_rt_wcscmp(r->name,L"subvariant"))text=L"Observed 1 or 5";
 break;
 case 0x60440005U:
 if(!xx_rt_wcscmp(r->name,L"chunk_type"))text=L"Low byte 1 FILE, 3 EOFM";
 break;
 case 0x60440008U:
 if(!xx_rt_wcscmp(r->name,L"filetime"))text=L"Windows FILETIME, 100 ns since 1601";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"0xFFFFFFFF indicates a split stream";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 2 compressed";
 break;
 case 0x60440009U:
 if(!xx_rt_wcscmp(r->name,L"chunk_type"))text=L"Low byte 1 split, 5 whole";
 break;
 case 0x6044000bU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"One based directory index; zero means root";
 break;
 case 0x6044000cU:
 if(!xx_rt_wcscmp(r->name,L"encoded_name_length"))text=L"1..8: basename length and 2/4-byte size; 11..18: basename length minus 10 and 1-byte size; extension occupies 3 bytes";
 break;
 case 0x60440010U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 PKWARE DCL";
 break;
 case 0x60440011U:
 if(!xx_rt_wcscmp(r->name,L"pack_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds, zero unspecified";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data";
 if(!xx_rt_wcscmp(r->name,L"unpacked_checksum"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"packed_checksum"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"complemented_data_offset"))text=L"One's complement of the data offset";
 break;
 case 0x60440012U:
 if(!xx_rt_wcscmp(r->name,L"positive_count_word"))text=L"Positive header word; not used as the member traversal count";
 if(!xx_rt_wcscmp(r->name,L"complemented_record_offset"))text=L"One's complement of the first record offset";
 break;
 case 0x60440013U:
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds";
 break;
 case 0x60440014U:
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds";
 break;
 case 0x60440015U:
 if(!xx_rt_wcscmp(r->name,L"end_tag"))text=L"0xFFFF terminates the member chain";
 break;
 case 0x60440018U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 8 raw DEFLATE";
 break;
 case 0x6044001dU:
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"checksum1"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"checksum2"))text=L"Unidentified checksum algorithm";
 break;
 case 0x6044001eU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Excludes size and checksum bytes";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of base-header bytes after this byte modulo 256";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-ARS- stored; -ARA- LHA lh5";
 if(!xx_rt_wcscmp(r->name,L"skip_size"))text=L"Compressed payload plus all extended-header bytes";
 break;
 case 0x6044001fU:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC-16/ARC of the member data";
 break;
 case 0x60440020U:
 if(!xx_rt_wcscmp(r->name,L"next_header_size"))text=L"Zero ends the extended-header chain; nonzero includes type/body and its final next-size word";
 break;
 case 0x60440021U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Extension type; remaining body bytes are preserved raw";
 break;
 case 0x60440022U:
 if(!xx_rt_wcscmp(r->name,L"flag"))text=L"Observed 0x21, not a codec selector";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data, positive selects DCL";
 break;
 case 0x60440025U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"1 path record";
 break;
 case 0x60440026U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0 member record";
 break;
 case 0x60440027U:
 if(!xx_rt_wcscmp(r->name,L"encoded_signature"))text=L"Biased RCF signature F7 E8 EB";
 break;
 case 0x6044002fU:
 if(!xx_rt_wcscmp(r->name,L"split_kind"))text=L"2 continuation fragment";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 4 zlib";
 break;
 case 0x60440030U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp, retained without assuming an epoch";
 break;
 case 0x60440034U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x0A NetWare LZH";
 break;
 case 0x60440035U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Includes this four-byte size word";
 if(!xx_rt_wcscmp(r->name,L"name_count"))text=L"Stored tag length plus one; the counted NUL is not physically present";
 break;
 case 0x60440036U:
 if(!xx_rt_wcscmp(r->name,L"date_text"))text=L"MM-DD-YY";
 if(!xx_rt_wcscmp(r->name,L"time_text"))text=L"HH:MM:SS";
 if(!xx_rt_wcscmp(r->name,L"attribute_identifier_text"))text=L"Printable attributes and identifier text with no further established field boundaries";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Exact stored DOS-name bytes, followed by an additional NUL";
 break;
 case 0x60440037U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x0A NetWare LZH";
 break;
 case 0x60440038U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary literals, 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary size parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
bool sxasy_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxasy_read(sx_context*c,uint64_t p,void*b,size_t n){return sxasy_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxasy_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxasy_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxasy_read(c,p,b,n))return false;*v=sxasy_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
bool sxasy_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXASY_LIMIT||!sxasy_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxasy_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxasy_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
bool sxasy_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxasy_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxasy_add(c,&sxasy_archivesystems_dcl,p);}
static int sxasy_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxasy_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxasy_order);return !c->failed;}
static bool sx_archivesystems_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_ARCV2:case XX_FILE_TYPE_ARCV4:case XX_FILE_TYPE_CRU:case XX_FILE_TYPE_POWERBOARDBBS:case XX_FILE_TYPE_FLD:case XX_FILE_TYPE_IGF1:case XX_FILE_TYPE_IGF2:case XX_FILE_TYPE_INTEDUFT:case XX_FILE_TYPE_JM93:case XX_FILE_TYPE_MIZ:case XX_FILE_TYPE_MVA:case XX_FILE_TYPE_POVLABLZH:case XX_FILE_TYPE_QIP1:case XX_FILE_TYPE_QUARTERDECKQP:case XX_FILE_TYPE_RCF:case XX_FILE_TYPE_RIVERSOFT:case XX_FILE_TYPE_TGCF:case XX_FILE_TYPE_TRC:case XX_FILE_TYPE_NETWAREPACKED:case XX_FILE_TYPE_NETWARE2:return true;default:return false;}}
static bool sx_archivesystems_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_ARCV2:ok=sx_arcv2_build(c);break;case XX_FILE_TYPE_ARCV4:ok=sx_arcv4_build(c);break;case XX_FILE_TYPE_CRU:ok=sx_cru_build(c);break;case XX_FILE_TYPE_POWERBOARDBBS:ok=sx_powerboardbbs_build(c);break;case XX_FILE_TYPE_FLD:ok=sx_fld_build(c);break;case XX_FILE_TYPE_IGF1:ok=sx_igf1_build(c);break;case XX_FILE_TYPE_IGF2:ok=sx_igf2_build(c);break;case XX_FILE_TYPE_INTEDUFT:ok=sx_inteduft_build(c);break;case XX_FILE_TYPE_JM93:ok=sx_jm93_build(c);break;case XX_FILE_TYPE_MIZ:ok=sx_miz_build(c);break;case XX_FILE_TYPE_MVA:ok=sx_mva_build(c);break;case XX_FILE_TYPE_POVLABLZH:ok=sx_povlablzh_build(c);break;case XX_FILE_TYPE_QIP1:ok=sx_qip1_build(c);break;case XX_FILE_TYPE_QUARTERDECKQP:ok=sx_quarterdeckqp_build(c);break;case XX_FILE_TYPE_RCF:ok=sx_rcf_build(c);break;case XX_FILE_TYPE_RIVERSOFT:ok=sx_riversoft_build(c);break;case XX_FILE_TYPE_TGCF:ok=sx_tgcf_build(c);break;case XX_FILE_TYPE_TRC:ok=sx_trc_build(c);break;case XX_FILE_TYPE_NETWAREPACKED:ok=sx_netwarepacked_build(c);break;case XX_FILE_TYPE_NETWARE2:ok=sx_netware2_build(c);break;default:break;}(void)ok;return c->count&&sxasy_finish(c);}
const sx_family sx_archivesystems_family={sx_archivesystems_supports,sx_archivesystems_build,sx_archivesystems_layouts,SX_COUNT(sx_archivesystems_layouts),sx_archivesystems_comment};
