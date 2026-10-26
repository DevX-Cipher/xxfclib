/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveframes_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveframes.h"
static const sx_layout *const sx_archiveframes_layouts[] = {
 &sxafr_lzhcxp_header,
 &sxafr_lzhcxp_block_size,
 &sxafr_lzwd_header,
 &sxafr_mi10_member,
 &sxafr_mi10_prefix,
 &sxafr_pakleo_header,
 &sxafr_pakleo_member,
 &sxafr_zcmp_header,
 &sxafr_zcmp_seek_word,
 &sxafr_ztc_header,
 &sxafr_ztc_member,
 &sxafr_ztc_check,
 &sxafr_ztc_page_sum,
 &sxafr_gtu_header,
 &sxafr_gtu_record,
 &sxafr_gtu_terminator,
 &sxafr_gtu_info,
 &sxafr_gtu_frame,
 &sxafr_jbf_member,
 &sxafr_jbf_count,
 &sxafr_imp_header,
 &sxafr_imp_directory_block,
 &sxafr_irwinpac_header,
 &sxafr_irwinpac_block,
 &sxafr_kpack_header,
 &sxafr_kpack_filter,
 &sxafr_lim_header,
 &sxafr_lim_chunk,
 &sxafr_lim_member,
 &sxafr_qda_header,
 &sxafr_qda_member,
 &sxafr_rid_member,
 &sxafr_rid_block,
 &sxafr_tivoli_header,
 &sxafr_tivoli_block,
 &sxafr_tivoli_digest,
 &sxafr_wintersoft_header,
 &sxafr_wintersoft_member,
 &sxafr_wpk_header,
 &sxafr_wpk_member,
 &sxafr_xeditpack_header,
 &sxafr_zie_header,
 &sxafr_clay_member,
 &sxafr_archiveframes_dcl,
 &sxafr_clay_prefix,
};
static bool sx_archiveframes_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60540000U||id>=0x60550000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60540002U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Zero ends the length-prefixed LZW block chain";
 break;
 case 0x60540004U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of uncompressed bytes";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Excludes the following two-byte stream prefix";
 break;
 case 0x60540005U:
 if(!xx_rt_wcscmp(r->name,L"escape"))text=L"Escape value for the backwards token stream";
 break;
 case 0x60540007U:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"-ll0- stored, -ll1- LEOLZW";
 break;
 case 0x60540008U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Maximum uncompressed bytes per block";
 break;
 case 0x60540009U:
 if(!xx_rt_wcscmp(r->name,L"seek_index_word"))text=L"Stored seek-index word; native validation derives block boundaries by inflation instead of trusting this index";
 break;
 case 0x6054000bU:
 if(!xx_rt_wcscmp(r->name,L"stamp"))text=L"First record has 0x3BC4";
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes record, name, check word and compressed payload";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored time, epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes a NUL inside the stored field";
 break;
 case 0x6054000cU:
 if(!xx_rt_wcscmp(r->name,L"header_check"))text=L"Low byte of uncompressed size plus low byte of timestamp plus every stored name byte";
 break;
 case 0x6054000dU:
 if(!xx_rt_wcscmp(r->name,L"page_sum"))text=L"Sum of the physical compressed bytes in the preceding page, at most 4096 bytes";
 break;
 case 0x60540010U:
 if(!xx_rt_wcscmp(r->name,L"self_offset"))text=L"Offset of this physical record";
 if(!xx_rt_wcscmp(r->name,L"unused"))text=L"Remaining terminator bytes are not interpreted by the native reader";
 break;
 case 0x60540011U:
 if(!xx_rt_wcscmp(r->name,L"skip_size"))text=L"Uncompressed bytes belonging to a previous volume";
 break;
 case 0x60540013U:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Checksum algorithm unidentified";
 break;
 case 0x60540015U:
 if(!xx_rt_wcscmp(r->name,L"header_crc16"))text=L"Low 16 bits of CRC-32 with this word treated as zero";
 break;
 case 0x60540016U:
 if(!xx_rt_wcscmp(r->name,L"method_and_lengths"))text=L"LSB-first: bits0..4 method/flags, bits5..24 uncompressed length, bits25..44 stored chunk advance excluding six-byte signature; upper3 bits are padding";
 break;
 case 0x60540018U:
 if(!xx_rt_wcscmp(r->name,L"compressed"))text=L"0 stored, 1 compressed";
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes this ten-byte header";
 if(!xx_rt_wcscmp(r->name,L"uninitialized"))text=L"Uninitialized encoder scratch, not a checksum";
 break;
 case 0x60540019U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0x01 LZMA, 0x40 call-trick1, 0x80 call-trick2; filters are mutually exclusive";
 break;
 case 0x6054001aU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Call-trick filter marker byte";
 break;
 case 0x6054001cU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0xD180 directory, 0xF123 file";
 if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Stored chunk field; cursor advancement follows the body grammar";
 break;
 case 0x6054001dU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 LIM";
 break;
 case 0x6054001eU:
 if(!xx_rt_wcscmp(r->name,L"packed"))text=L"0 stored, 1 byte-pair encoding";
 break;
 case 0x6054001fU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Ignored when the archive packed flag is zero";
 break;
 case 0x60540021U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"0 stored, 1 DCL, 0xFF ends the member with zero length";
 break;
 case 0x60540022U:
 if(!xx_rt_wcscmp(r->name,L"header_line"))text=L"Physical 79-byte Filepack declaration, including LF; variable text is preserved";
 break;
 case 0x60540023U:
 if(!xx_rt_wcscmp(r->name,L"flags_and_size"))text=L"Zero terminates; bit15 selects stored, bits0..14 count physical block bytes including its eight-byte running-MD5 tail";
 break;
 case 0x60540024U:
 if(!xx_rt_wcscmp(r->name,L"running_md5_prefix"))text=L"First eight MD5 bytes of all uncompressed output emitted so far";
 break;
 case 0x60540025U:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"LZW or HUFF applies to every member";
 break;
 case 0x60540028U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp, epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC-32 of consumed compressed prefix, not plaintext or the entire upper-bound run";
 if(!xx_rt_wcscmp(r->name,L"method_and_name_size"))text=L"Bit7 selects method B instead of A; low7 bits are physical name length";
 break;
 case 0x60540029U:
 if(!xx_rt_wcscmp(r->name,L"record_format"))text=L"0xC6 F fixed, 0xE5 V variable";
 break;
 case 0x6054002cU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary parameter";
 break;
 case 0x6054002dU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"window_exponent"))text=L"4, 5 or 6; encoded history-window parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAFR_LIMIT 20000U
bool sxafr_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxafr_read(sx_context*c,uint64_t p,void*b,size_t n){return sxafr_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxafr_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxafr_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxafr_read(c,p,b,n))return false;*v=sxafr_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
bool sxafr_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAFR_LIMIT||!sxafr_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static int sxafr_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxafr_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxafr_order);return !c->failed;}
static bool sx_archiveframes_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_LZHCXP:case XX_FILE_TYPE_LZWD:case XX_FILE_TYPE_MI10:case XX_FILE_TYPE_PAKLEO:case XX_FILE_TYPE_ZCMP:case XX_FILE_TYPE_ZTC:case XX_FILE_TYPE_GTU:case XX_FILE_TYPE_JBF:case XX_FILE_TYPE_IMP:case XX_FILE_TYPE_IRWINPAC:case XX_FILE_TYPE_KOLIBRIKPACK:case XX_FILE_TYPE_LIM:case XX_FILE_TYPE_QDA:case XX_FILE_TYPE_RID:case XX_FILE_TYPE_TIVOLI:case XX_FILE_TYPE_WINTERSOFT:case XX_FILE_TYPE_WPK:case XX_FILE_TYPE_XEDITPACK:case XX_FILE_TYPE_ZIE:case XX_FILE_TYPE_CLAYLZ:return true;default:return false;}}
static bool sx_archiveframes_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_LZHCXP:ok=sx_lzhcxp_build(c);break;case XX_FILE_TYPE_LZWD:ok=sx_lzwd_build(c);break;case XX_FILE_TYPE_MI10:ok=sx_mi10_build(c);break;case XX_FILE_TYPE_PAKLEO:ok=sx_pakleo_build(c);break;case XX_FILE_TYPE_ZCMP:ok=sx_zcmp_build(c);break;case XX_FILE_TYPE_ZTC:ok=sx_ztc_build(c);break;case XX_FILE_TYPE_GTU:ok=sx_gtu_build(c);break;case XX_FILE_TYPE_JBF:ok=sx_jbf_build(c);break;case XX_FILE_TYPE_IMP:ok=sx_imp_build(c);break;case XX_FILE_TYPE_IRWINPAC:ok=sx_irwinpac_build(c);break;case XX_FILE_TYPE_KOLIBRIKPACK:ok=sx_kolibrikpack_build(c);break;case XX_FILE_TYPE_LIM:ok=sx_lim_build(c);break;case XX_FILE_TYPE_QDA:ok=sx_qda_build(c);break;case XX_FILE_TYPE_RID:ok=sx_rid_build(c);break;case XX_FILE_TYPE_TIVOLI:ok=sx_tivoli_build(c);break;case XX_FILE_TYPE_WINTERSOFT:ok=sx_wintersoft_build(c);break;case XX_FILE_TYPE_WPK:ok=sx_wpk_build(c);break;case XX_FILE_TYPE_XEDITPACK:ok=sx_xeditpack_build(c);break;case XX_FILE_TYPE_ZIE:ok=sx_zie_build(c);break;case XX_FILE_TYPE_CLAYLZ:ok=sx_claylz_build(c);break;default:break;}(void)ok;return c->count&&sxafr_finish(c);}
const sx_family sx_archiveframes_family={sx_archiveframes_supports,sx_archiveframes_build,sx_archiveframes_layouts,SX_COUNT(sx_archiveframes_layouts),sx_archiveframes_comment};
