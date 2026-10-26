/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivetails_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivetails.h"

static const xx_data_struct_field_desc sxat_archivetails_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxat_archivetails_dcl = {UINT32_C(0x60640018),"archivetails_dcl",sxat_archivetails_dcl_fields,SX_COUNT(sxat_archivetails_dcl_fields),SX_LE};
static const sx_layout *const sx_archivetails_layouts[] = {
 &sxat_zxzip_header,
 &sxat_zxzip_member,
 &sxat_saf_banner29,
 &sxat_saf_banner47,
 &sxat_saf_member,
 &sxat_saf_chunk,
 &sxat_sls_header,
 &sxat_nid_header,
 &sxat_nid_member,
 &sxat_nid_block,
 &sxat_gamos_header,
 &sxat_gamos_member,
 &sxat_fpak_header,
 &sxat_fpac_header,
 &sxat_fpak_segment,
 &sxat_finear_header,
 &sxat_gst_member,
 &sxat_gpfpack_header,
 &sxat_gpfpack_block,
 &sxat_psdc_header,
 &sxat_edi_header,
 &sxat_edi_name,
 &sxat_edi_size,
 &sxat_archivetails_dcl,
 &sxat_lzk_header,
 &sxat_lzk_literal,
 &sxat_lzk_match,
 &sxat_compaqlzh_header,
 &sxat_lifkd_member,
 &sxat_psn_header,
 &sxat_mcc_member,
 &sxat_xlas_header,
 &sxat_xlas_member,
 &sxat_mdcd_member,
 &sxat_mdcd_path,
 &sxat_bvrp_header,
 &sxat_bvrp_member,
};
static bool sx_archivetails_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60640000U||id>=0x60650000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60640001U:
 if(!xx_rt_wcscmp(r->name,L"size_high_guard"))text=L"Upper bound for the high byte of chain_size";
 if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Hobeta sum: sum(first15bytes)*0x101+0x69, low16 bits";
 break;
 case 0x60640002U:
 if(!xx_rt_wcscmp(r->name,L"start_or_basic_size"))text=L"B/b: BASIC program byte length; other types: stored TR-DOS start word";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"256-byte output sectors";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Opaque decompressed checksum, not verified by the native reader";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 unsupported, 2 Shrink, 3 ZXZIP LZH";
 break;
 case 0x60640005U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"3 single bitstream, others use length-prefixed chunks";
 break;
 case 0x60640008U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Stored checksum, algorithm not verified";
 break;
 case 0x60640009U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 local member, 2 following-volume continuation";
 if(!xx_rt_wcscmp(r->name,L"payload_offset1"))text=L"One-based offset relative to the container: subtract1 for the physical byte position";
 if(!xx_rt_wcscmp(r->name,L"folder_key"))text=L"Opaque folder grouping key";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Space-padded FCB 8+3 name";
 break;
 case 0x6064000aU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0x0800 compressed, 0x0100 last block";
 break;
 case 0x6064000cU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 Gamos LZSS, 2 stored";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Stored method2 uses compressed_size and ignores this zero field";
 break;
 case 0x6064000dU:
 if(!xx_rt_wcscmp(r->name,L"set_compressed_size"))text=L"Whole distribution set, not this volume";
 if(!xx_rt_wcscmp(r->name,L"set_uncompressed_size"))text=L"Whole distribution set";
 break;
 case 0x6064000fU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PKZIP general-purpose flags";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 6 imploded";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Whole member plaintext";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Whole member across segments";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Whole member across segments";
 if(!xx_rt_wcscmp(r->name,L"segment_size"))text=L"Physical payload bytes in this segment";
 break;
 case 0x60640010U:
 if(!xx_rt_wcscmp(r->name,L"crc16_word"))text=L"CRC16/ARC of plaintext, zero-extended to32 bits";
 break;
 case 0x60640011U:
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"0xC8E9 or alternate0xC9EA";
 if(!xx_rt_wcscmp(r->name,L"stamp"))text=L"Opaque stored stamp";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 PKWARE DCL";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of plaintext";
 break;
 case 0x60640013U:
 if(!xx_rt_wcscmp(r->name,L"bit_count"))text=L"Stored compressed bit budget; physical byte length is ceil(bit_count/8)";
 break;
 case 0x60640014U:
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes this80-byte header";
 break;
 case 0x60640018U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or1 Huffman-coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4=1KiB,5=2KiB,6=4KiB dictionary; encoded selector, not byte size";
 break;
 case 0x6064001aU:
 if(!xx_rt_wcscmp(r->name,L"literal_code"))text=L"Bit0 is0; bits1..7 store literal byte count";
 break;
 case 0x6064001bU:
 if(!xx_rt_wcscmp(r->name,L"match_code"))text=L"Bit0 is1; bits1..11 store backwards distance, bits12..15 store length minus3";
 break;
 case 0x6064001dU:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"DOS date in high16 bits, time in low16";
 if(!xx_rt_wcscmp(r->name,L"packed_crc16"))text=L"CRC16/CCITT-FALSE of physical packed bytes";
 if(!xx_rt_wcscmp(r->name,L"plain_crc16"))text=L"CRC16/CCITT-FALSE of plaintext";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 stored,2 LZD";
 break;
 case 0x6064001eU:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"FFFFFFFF means the uncompressed size was not recorded";
 break;
 case 0x6064001fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 XOR-filtered LZW";
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"DOS date in high16 bits, time in low16";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/BUYPASS of plaintext";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Space-padded";
 break;
 case 0x60640021U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 Okumura LZSS";
 break;
 case 0x60640022U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 LZD";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/XMODEM of plaintext; zero tolerated for stored members";
 break;
 case 0x60640024U:
 if(!xx_rt_wcscmp(r->name,L"writer_version"))text=L"Major in high byte, minor in low byte";
 break;
 case 0x60640025U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 LZHUF";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"Container-relative physical end of this member, or next header";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/ARC of plaintext";
 if(!xx_rt_wcscmp(r->name,L"name_tail_size"))text=L"Optional repeated NUL-terminated name after compressed payload; zero may use native name matching";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
bool sxat_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxat_read(sx_context*c,uint64_t p,void*b,size_t n){return sxat_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxat_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxat_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxat_read(c,p,b,n))return false;*v=sxat_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
bool sxat_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAT_LIMIT||!sxat_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxat_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxat_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxat_add(c,&sxat_archivetails_dcl,p);}
static int sxat_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxat_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxat_order);return !c->failed;}
bool sxat_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxat_add(c,l,p+i*width))return false;return true;}
bool sxat_hex(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[16];*v=0;if(!n||n>16||!sxat_read(c,p,b,n))return false;for(unsigned i=0;i<n;i++){unsigned d;if(b[i]>='0'&&b[i]<='9')d=b[i]-'0';else if(b[i]>='A'&&b[i]<='F')d=b[i]-'A'+10;else if(b[i]>='a'&&b[i]<='f')d=b[i]-'a'+10;else return false;*v=(*v<<4)|d;}return true;}
static bool sx_archivetails_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_ZXZIP:case XX_FILE_TYPE_SAF:case XX_FILE_TYPE_SLS:case XX_FILE_TYPE_NID:case XX_FILE_TYPE_GAMOS:case XX_FILE_TYPE_FPAK:case XX_FILE_TYPE_FINEAR:case XX_FILE_TYPE_GST:case XX_FILE_TYPE_GPFPACK:case XX_FILE_TYPE_PSDC:case XX_FILE_TYPE_EDILZSS:case XX_FILE_TYPE_DCLFT:case XX_FILE_TYPE_LZK00:case XX_FILE_TYPE_COMPAQLZH:case XX_FILE_TYPE_LIFKD:case XX_FILE_TYPE_PSN:case XX_FILE_TYPE_MCC:case XX_FILE_TYPE_XLAS:case XX_FILE_TYPE_MDCD:case XX_FILE_TYPE_BVRP:return true;default:return false;}}
static bool sx_archivetails_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_ZXZIP:ok=sx_zxzip_build(c);break;case XX_FILE_TYPE_SAF:ok=sx_saf_build(c);break;case XX_FILE_TYPE_SLS:ok=sx_sls_build(c);break;case XX_FILE_TYPE_NID:ok=sx_nid_build(c);break;case XX_FILE_TYPE_GAMOS:ok=sx_gamos_build(c);break;case XX_FILE_TYPE_FPAK:ok=sx_fpak_build(c);break;case XX_FILE_TYPE_FINEAR:ok=sx_finear_build(c);break;case XX_FILE_TYPE_GST:ok=sx_gst_build(c);break;case XX_FILE_TYPE_GPFPACK:ok=sx_gpfpack_build(c);break;case XX_FILE_TYPE_PSDC:ok=sx_psdc_build(c);break;case XX_FILE_TYPE_EDILZSS:ok=sx_edilzss_build(c);break;case XX_FILE_TYPE_DCLFT:ok=sxat_dcl(c,0,(uint64_t)c->size);break;case XX_FILE_TYPE_LZK00:ok=sx_lzk00_build(c);break;case XX_FILE_TYPE_COMPAQLZH:ok=sx_compaqlzh_build(c);break;case XX_FILE_TYPE_LIFKD:ok=sx_lifkd_build(c);break;case XX_FILE_TYPE_PSN:ok=sx_psn_build(c);break;case XX_FILE_TYPE_MCC:ok=sx_mcc_build(c);break;case XX_FILE_TYPE_XLAS:ok=sx_xlas_build(c);break;case XX_FILE_TYPE_MDCD:ok=sx_mdcd_build(c);break;case XX_FILE_TYPE_BVRP:ok=sx_bvrp_build(c);break;default:break;}(void)ok;return c->count&&sxat_finish(c);}
const sx_family sx_archivetails_family={sx_archivetails_supports,sx_archivetails_build,sx_archivetails_layouts,SX_COUNT(sx_archivetails_layouts),sx_archivetails_comment};
