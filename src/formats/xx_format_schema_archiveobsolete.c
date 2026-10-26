/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveobsolete_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveobsolete.h"
static const xx_data_struct_field_desc sxao_sw_path_length_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxao_sw_path_length = {UINT32_C(0x60700002),"sw_path_length",sxao_sw_path_length_fields,SX_COUNT(sxao_sw_path_length_fields),SX_BE};
static const xx_data_struct_field_desc sxao_archiveobsolete_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxao_archiveobsolete_name = {UINT32_C(0x60700003),"archiveobsolete_name",sxao_archiveobsolete_name_fields,SX_COUNT(sxao_archiveobsolete_name_fields),SX_LE};
static const xx_data_struct_field_desc sxao_archiveobsolete_path_fields[] = {
 SX_FIELD("path","char",0,0,SX_NONE),
};
const sx_layout sxao_archiveobsolete_path = {UINT32_C(0x60700004),"archiveobsolete_path",sxao_archiveobsolete_path_fields,SX_COUNT(sxao_archiveobsolete_path_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_signature_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_wraptor_signature = {UINT32_C(0x60700014),"wraptor_signature",sxao_wraptor_signature_fields,SX_COUNT(sxao_wraptor_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxao_wraptor_flags = {UINT32_C(0x60700015),"wraptor_flags",sxao_wraptor_flags_fields,SX_COUNT(sxao_wraptor_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_checksum_fields[] = {
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxao_wraptor_checksum = {UINT32_C(0x60700016),"wraptor_checksum",sxao_wraptor_checksum_fields,SX_COUNT(sxao_wraptor_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_end_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_wraptor_end = {UINT32_C(0x60700017),"wraptor_end",sxao_wraptor_end_fields,SX_COUNT(sxao_wraptor_end_fields),SX_LE};
static const xx_data_struct_field_desc sxao_corelltec_member_fields[] = {
 SX_FIELD("record_size","uint16",0,2,SX_SIZE),
 SX_FIELD("block_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("decoded_member_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxao_corelltec_member = {UINT32_C(0x60700019),"corelltec_member",sxao_corelltec_member_fields,SX_COUNT(sxao_corelltec_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_archiveobsolete_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxao_archiveobsolete_dcl = {UINT32_C(0x6070003f),"archiveobsolete_dcl",sxao_archiveobsolete_dcl_fields,SX_COUNT(sxao_archiveobsolete_dcl_fields),SX_LE};
static const sx_layout *const sx_archiveobsolete_layouts[] = {
 &sxao_sw_header,
 &sxao_sw_path_length,
 &sxao_archiveobsolete_name,
 &sxao_archiveobsolete_path,
 &sxao_dsl2_header,
 &sxao_dsl2_path_length,
 &sxao_dsl2_member,
 &sxao_dsl2_name_length,
 &sxao_dsl2_name,
 &sxao_topspeed_block,
 &sxao_ulead_prefix,
 &sxao_ulead_name,
 &sxao_ulead_block_counts,
 &sxao_ulead_block_size,
 &sxao_quantum_header,
 &sxao_quantum_length1,
 &sxao_quantum_length2,
 &sxao_quantum_member,
 &sxao_quantum_crc16,
 &sxao_wraptor_signature,
 &sxao_wraptor_flags,
 &sxao_wraptor_checksum,
 &sxao_wraptor_end,
 &sxao_corelltec_header,
 &sxao_corelltec_member,
 &sxao_rsvk_container,
 &sxao_rsvk_block,
 &sxao_rsvk_member,
 &sxao_rsvk_trailer,
 &sxao_arcv_header,
 &sxao_arcv_member,
 &sxao_arcv_chunk,
 &sxao_bcw_header,
 &sxao_bcw_record,
 &sxao_bcw_time,
 &sxao_scf_header,
 &sxao_scf_member,
 &sxao_recognita_member,
 &sxao_jasc_member,
 &sxao_jasc_end,
 &sxao_bnd_header,
 &sxao_bnd_record,
 &sxao_bnd_prologue,
 &sxao_bnd_member_tail,
 &sxao_bnd_trailer,
 &sxao_smsipak_header,
 &sxao_smsipak_member,
 &sxao_smsipak_index,
 &sxao_smsipak_index_entry,
 &sxao_cpx_header,
 &sxao_cpx_member,
 &sxao_cpx4_header,
 &sxao_cpx4_member,
 &sxao_red_member,
 &sxao_red_header_crc,
 &sxao_red_segment_crc,
 &sxao_aiaff_header,
 &sxao_aiaff_member,
 &sxao_aiaff_terminator,
 &sxao_softpaq2_locator,
 &sxao_softpaq2_stored,
 &sxao_softpaq2_compressed,
 &sxao_archiveobsolete_dcl,
};
static bool sx_archiveobsolete_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60700000U||id>=0x60710000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60700007U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Per-byte+0x33 storage bias; decoded bit0x10 selects DCL";
 break;
 case 0x60700008U:
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Decoded length includes the NUL; native name extent is directory-bounded, not record-bounded";
 break;
 case 0x6070000aU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Additive sum of stored payload bytes";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Physical payload uses min(compressed_size,uncompressed_size); compressed_size>=uncompressed_size means stored";
 break;
 case 0x6070000dU:
 if(!xx_rt_wcscmp(r->name,L"last_block_size"))text=L"Earlier blocks decode to16384 bytes each";
 break;
 case 0x6070000eU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Stored if equal to this block plain size; otherwise independent12-bit LZW";
 break;
 case 0x6070000fU:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"Below0x17 uses directory CRC and old solid coder";
 if(!xx_rt_wcscmp(r->name,L"window_bits"))text=L"Encoded power of two,10..21";
 break;
 case 0x60700011U:
 if(!xx_rt_wcscmp(r->name,L"length_high"))text=L"Bit7 is set; low7 bits are upper length bits";
 if(!xx_rt_wcscmp(r->name,L"length_low"))text=L"Full byte length=((length_high&0x7f)<<8)|length_low";
 break;
 case 0x60700013U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"Old stream variant plaintext checksum";
 break;
 case 0x60700016U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Stored word; algorithm not verified by native reader";
 break;
 case 0x60700018U:
 if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Meaning not established";
 break;
 case 0x60700019U:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Relative to physical payload area after directory";
 if(!xx_rt_wcscmp(r->name,L"decoded_member_offset"))text=L"Offset in decompressed block, not a physical file coordinate";
 break;
 case 0x6070001bU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Plaintext checksum";
 if(!xx_rt_wcscmp(r->name,L"primary_index"))text=L"Inverse BWT primary row";
 if(!xx_rt_wcscmp(r->name,L"hole_index"))text=L"Inverse BWT sentinel row";
 break;
 case 0x6070001cU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size_hint"))text=L"Stored hint; actual block chain can have a different length";
 break;
 case 0x6070001eU:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"0x0100 LH1 or0x0110 stop-symbol LZHUF";
 break;
 case 0x6070001fU:
 if(!xx_rt_wcscmp(r->name,L"jamcrc"))text=L"v1.00 plaintext; v1.10 matching packed checksum selects compact coder, otherwise plaintext wide coder";
 break;
 case 0x60700022U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0 terminator,1 file,2 enter directory,3 leave directory";
 break;
 case 0x60700027U:
 if(!xx_rt_wcscmp(r->name,L"header_size_minus2"))text=L"Encoded header length equals name_size+15; actual header is stored value+2";
 if(!xx_rt_wcscmp(r->name,L"header_check"))text=L"Algorithm not established";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds since1970-01-01";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/ARC of plaintext";
 break;
 case 0x60700029U:
 if(!xx_rt_wcscmp(r->name,L"volume_prefix"))text=L"All-zero standalone prefix, or repeated [20/20] tag in executable-overlay variant";
 break;
 case 0x6070002aU:
 if(!xx_rt_wcscmp(r->name,L"stored_member_size"))text=L"Includes the member prologue/header";
 break;
 case 0x6070002bU:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0x74 full member,0x75 continuation";
 break;
 case 0x6070002cU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"DOS attributes word at member+0xba";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Declared whole member stream, possibly continued in next volume";
 if(!xx_rt_wcscmp(r->name,L"dos_date_word"))text=L"Low16 bits contain DOS date";
 if(!xx_rt_wcscmp(r->name,L"dos_time_word"))text=L"Low16 bits contain DOS time";
 break;
 case 0x6070002fU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Plaintext checksum";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 DCL,2 stored";
 break;
 case 0x60700033U:
 if(!xx_rt_wcscmp(r->name,L"group"))text=L"Path or volume identifier";
 if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))text=L"Bit31 means stored, low31 bits are unreliable for stored members";
 break;
 case 0x60700035U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to name table";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp; epoch not established";
 break;
 case 0x60700036U:
 if(!xx_rt_wcscmp(r->name,L"crc1"))text=L"Opaque stored checksum word";
 if(!xx_rt_wcscmp(r->name,L"crc2"))text=L"CRC16/IBM-3740 of plaintext";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 stored,11 LH5 with per-segment CRC words";
 break;
 case 0x60700037U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/IBM-3740 over header bytes2 through header_size-3";
 break;
 case 0x60700038U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/IBM-3740 of up to4094 coded bytes; whole declared segment must be physically present";
 break;
 case 0x6070003aU:
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds since epoch";
 if(!xx_rt_wcscmp(r->name,L"mode"))text=L"Octal ASCII file type and permissions";
 break;
 case 0x6070003dU:
 if(!xx_rt_wcscmp(r->name,L"published"))text=L"0 extractor resource,nonzero public archive member";
 break;
 case 0x6070003eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,6 DCL";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Packed stream checksum";
 break;
 case 0x6070003fU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or1 Huffman literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4=1KiB,5=2KiB,6=4KiB; encoded power,not byte count";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAO_LIMIT 20000U
bool sxao_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxao_read(sx_context*c,uint64_t p,void*b,size_t n){return sxao_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxao_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxao_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxao_read(c,p,b,n))return false;*v=sxao_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
bool sxao_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAO_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxao_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxao_add(sx_context*c,const sx_layout*l,uint64_t p){return sxao_put(c,l,p,0,false);}
bool sxao_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){return !n||n>4096?true:sxao_put(c,l,p,n,aliases);}
bool sxao_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxao_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static int sxao_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxao_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxao_order);return !c->failed;}
bool sxao_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxao_add(c,l,p+i*width))return false;return true;}
bool sxao_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t b[2];return n<2||!sxao_read(c,p,b,2)||b[0]>1||b[1]<4||b[1]>6?true:sxao_add(c,&sxao_archiveobsolete_dcl,p);}
/* Reuse authenticated physical extents for grammars whose end is codec-defined.
 * Callbacks belong to the supplied native reader; no constructor is linked. */
bool sxao_native_members(sx_context*c){xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;bool ok=true;uint64_t end=0;for(size_t work=0;work<SXAO_LIMIT;work++){const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);if(!r)break;if(r->header_offset<c->f->base_address||r->header_size<0||r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-c->f->base_address),n=(uint64_t)r->header_size,d=(uint64_t)(r->data_offset-c->f->base_address),z=(uint64_t)r->compressed_size;if(!sxao_span(c,p,n)||!sxao_span(c,d,z)){ok=false;break;}
 if(c->f->file_type==XX_FILE_TYPE_SW){if(n<2||!sxao_add(c,&sxao_sw_path_length,p)||!sxao_text(c,&sxao_archiveobsolete_path,p+2,n-2,false)){ok=false;break;}}
 else if(c->f->file_type==XX_FILE_TYPE_C64WRAPTOR){if(n<6||d!=p+n||!sxao_add(c,&sxao_wraptor_signature,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+4,n-5,false)||!sxao_add(c,&sxao_wraptor_flags,d-1)||!sxao_add(c,&sxao_wraptor_checksum,d+z)){ok=false;break;}end=d+z+2;}
 else if(c->f->file_type==XX_FILE_TYPE_CORELLTEC){if(n<15||!sxao_add(c,&sxao_corelltec_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+14,n-14,false)){ok=false;break;}}
 if(!xx_format_archive_record_move_to_next(c->f,s,c->pd))break;}
 xx_format_free_archive_records_reading(c->f,s);if(ok&&c->f->file_type==XX_FILE_TYPE_C64WRAPTOR){uint64_t tag;if(sxao_word(c,end,4,false,&tag)&&tag==0x1a1a1a1a)ok=sxao_add(c,&sxao_wraptor_end,end);}return ok;}
static bool sx_archiveobsolete_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_SW:case XX_FILE_TYPE_DSL2:case XX_FILE_TYPE_TOPSPEED:case XX_FILE_TYPE_ULEAD:case XX_FILE_TYPE_QUANTUM:case XX_FILE_TYPE_C64WRAPTOR:case XX_FILE_TYPE_CORELLTEC:case XX_FILE_TYPE_RSVK:case XX_FILE_TYPE_ARCV:case XX_FILE_TYPE_BCW:case XX_FILE_TYPE_SCF:case XX_FILE_TYPE_RECOGNITA:case XX_FILE_TYPE_JASC:case XX_FILE_TYPE_BND:case XX_FILE_TYPE_SMSIPAK:case XX_FILE_TYPE_CPX:case XX_FILE_TYPE_CPX4:case XX_FILE_TYPE_RED:case XX_FILE_TYPE_AIAFF:case XX_FILE_TYPE_SOFTPAQ2:return true;default:return false;}}
static bool sx_archiveobsolete_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SW:ok=sx_sw_build(c);break;case XX_FILE_TYPE_DSL2:ok=sx_dsl2_build(c);break;case XX_FILE_TYPE_TOPSPEED:ok=sx_topspeed_build(c);break;case XX_FILE_TYPE_ULEAD:ok=sx_ulead_build(c);break;case XX_FILE_TYPE_QUANTUM:ok=sx_quantum_build(c);break;case XX_FILE_TYPE_C64WRAPTOR:ok=sx_c64wraptor_build(c);break;case XX_FILE_TYPE_CORELLTEC:ok=sx_corelltec_build(c);break;case XX_FILE_TYPE_RSVK:ok=sx_rsvk_build(c);break;case XX_FILE_TYPE_ARCV:ok=sx_arcv_build(c);break;case XX_FILE_TYPE_BCW:ok=sx_bcw_build(c);break;case XX_FILE_TYPE_SCF:ok=sx_scf_build(c);break;case XX_FILE_TYPE_RECOGNITA:ok=sx_recognita_build(c);break;case XX_FILE_TYPE_JASC:ok=sx_jasc_build(c);break;case XX_FILE_TYPE_BND:ok=sx_bnd_build(c);break;case XX_FILE_TYPE_SMSIPAK:ok=sx_smsipak_build(c);break;case XX_FILE_TYPE_CPX:case XX_FILE_TYPE_CPX4:ok=sx_cpx_build(c);break;case XX_FILE_TYPE_RED:ok=sx_red_build(c);break;case XX_FILE_TYPE_AIAFF:ok=sx_aiaff_build(c);break;case XX_FILE_TYPE_SOFTPAQ2:ok=sx_softpaq2_build(c);break;default:break;}(void)ok;return c->count&&sxao_finish(c);}
const sx_family sx_archiveobsolete_family={sx_archiveobsolete_supports,sx_archiveobsolete_build,sx_archiveobsolete_layouts,SX_COUNT(sx_archiveobsolete_layouts),sx_archiveobsolete_comment};
