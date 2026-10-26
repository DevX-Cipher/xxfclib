#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveremaining.h"

#ifdef XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM
#else
#define SXARM_CHECKSUM SX_NONE
#endif
/* SPDX-License-Identifier: MIT. Physical metadata. Scope: docs/data_struct_archiveremaining_scope.txt. */
static const xx_data_struct_field_desc sxarm_archiveremaining_name_fields[]={
 SX_FIELD("archiveremaining_name","char",0,0,SX_STRING),
};
static const sx_layout sxarm_archiveremaining_name={UINT32_C(0x607c0001),"archiveremaining_name",sxarm_archiveremaining_name_fields,SX_COUNT(sxarm_archiveremaining_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_filename_fields[]={
 SX_FIELD("transport_filename","char",0,0,SX_STRING),
};
const sx_layout sxarm_transport_filename={UINT32_C(0x607c0009),"transport_filename",sxarm_transport_filename_fields,SX_COUNT(sxarm_transport_filename_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_decimal_size_fields[]={
 SX_FIELD("transport_decimal_size","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxarm_transport_decimal_size={UINT32_C(0x607c000a),"transport_decimal_size",sxarm_transport_decimal_size_fields,SX_COUNT(sxarm_transport_decimal_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_crc_fields[]={
 SX_FIELD("transport_crc","ascii_hex",0,0,SXARM_CHECKSUM),
};
const sx_layout sxarm_transport_crc={UINT32_C(0x607c000c),"transport_crc",sxarm_transport_crc_fields,SX_COUNT(sxarm_transport_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pax_member_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("plaintext_prefix","uint8[4]",4,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown_header_bytes","uint8[16]",12,16,SX_NONE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxarm_pax_member={UINT32_C(0x607c0015),"pax_member",sxarm_pax_member_fields,SX_COUNT(sxarm_pax_member_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_voc_block_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("payload_size","uint24",1,3,SX_SIZE),
};
const sx_layout sxarm_sou_voc_block={UINT32_C(0x607c0022),"sou_voc_block",sxarm_sou_voc_block_fields,SX_COUNT(sxarm_sou_voc_block_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_rvz_disc_header_fields[]={
 SX_FIELD("disc_type","uint32",0,4,SX_ID),
 SX_FIELD("compression","uint32",4,4,SX_ID),
 SX_FIELD("compression_level","int32",8,4,SX_NONE),
 SX_FIELD("chunk_size","uint32",12,4,SX_SIZE),
 SX_FIELD("disc_image_header","uint8[128]",16,128,SX_NONE),
 SX_FIELD("partition_count","uint32",144,4,SX_COUNT_PROP),
 SX_FIELD("partition_entry_size","uint32",148,4,SX_SIZE),
 SX_FIELD("partition_table_offset","uint64",152,8,SX_OFFSET),
 SX_FIELD("partition_table_sha1","uint8[20]",160,20,SXARM_CHECKSUM),
 SX_FIELD("raw_count","uint32",180,4,SX_COUNT_PROP),
 SX_FIELD("raw_table_offset","uint64",184,8,SX_OFFSET),
 SX_FIELD("raw_table_size","uint32",192,4,SX_SIZE),
 SX_FIELD("group_count","uint32",196,4,SX_COUNT_PROP),
 SX_FIELD("group_table_offset","uint64",200,8,SX_OFFSET),
 SX_FIELD("group_table_size","uint32",208,4,SX_SIZE),
 SX_FIELD("compression_properties_size","uint8",212,1,SX_SIZE),
};
const sx_layout sxarm_rvz_disc_header={UINT32_C(0x607c002b),"rvz_disc_header",sxarm_rvz_disc_header_fields,SX_COUNT(sxarm_rvz_disc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_transport_invalid_number_fields[]={
 SX_FIELD("transport_invalid_number","char",0,0,SX_NONE),
};
static const sx_layout sxarm_transport_invalid_number={UINT32_C(0x607c0048),"transport_invalid_number",sxarm_transport_invalid_number_fields,SX_COUNT(sxarm_transport_invalid_number_fields),SX_LE};
static const sx_layout *const sx_archiveremaining_layouts[]={
 &sxarm_archiveremaining_name,
 &sxarm_warc_version,
 &sxarm_warc_field_name,
 &sxarm_warc_field_value,
 &sxarm_warc_content_length,
 &sxarm_warc_segment_number,
 &sxarm_warc_segment_total_length,
 &sxarm_warc_digest,
 &sxarm_transport_filename,
 &sxarm_transport_decimal_size,
 &sxarm_transport_hex_size,
 &sxarm_transport_crc,
 &sxarm_transport_attribute_name,
 &sxarm_transport_attribute_value,
 &sxarm_yenc_line_width,
 &sxarm_yenc_part_number,
 &sxarm_yenc_total_parts,
 &sxarm_yenc_begin_position,
 &sxarm_yenc_end_position,
 &sxarm_btoa_line_width,
 &sxarm_pax_member,
 &sxarm_pcomm_literal,
 &sxarm_pcomm_near_match,
 &sxarm_pcomm_far_match,
 &sxarm_pcomm_block_end,
 &sxarm_balz_header,
 &sxarm_bzip1_header,
 &sxarm_freeze2_header,
 &sxarm_he_tlkb_chunk,
 &sxarm_sou_header,
 &sxarm_sou_chunk,
 &sxarm_sou_mouth_sync,
 &sxarm_sou_voc_header,
 &sxarm_sou_voc_block,
 &sxarm_sou_voc_end,
 &sxarm_sou_voc_sound,
 &sxarm_sou_voc_silence,
 &sxarm_sou_voc_marker,
 &sxarm_sou_voc_repeat,
 &sxarm_sou_voc_extended,
 &sxarm_sou_voc_new_sound,
 &sxarm_rvz_file_header,
 &sxarm_rvz_disc_header,
 &sxarm_rvz_raw_entry,
 &sxarm_rvz_group_entry,
 &sxarm_rvz_packing_run,
 &sxarm_rvz_prng_seed,
 &sxarm_binscii_signature,
 &sxarm_binscii_alphabet,
 &sxarm_binscii_header,
 &sxarm_binscii_data_crc,
 &sxarm_uue_begin,
 &sxarm_uue_mode_1,
 &sxarm_uue_mode_2,
 &sxarm_uue_mode_3,
 &sxarm_uue_mode_4,
 &sxarm_uue_mode_5,
 &sxarm_uue_mode_6,
 &sxarm_uue_line,
 &sxarm_uue_end,
 &sxarm_yenc_begin,
 &sxarm_yenc_part,
 &sxarm_yenc_end,
 &sxarm_btoa_begin,
 &sxarm_btoa5_begin,
 &sxarm_btoa_end,
 &sxarm_ascii85_begin,
 &sxarm_ascii85_end,
 &sxarm_ascii85_group,
 &sxarm_ascii85_shorthand,
 &sxarm_btoa_line_check,
 &sxarm_transport_invalid_number,
};
static bool sx_archiveremaining_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x607c0000U||id>=0x607d0000U)return true;if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)&&r->value.type==XX_VAR_TYPE_BYTES)return true;const wchar_t*text=NULL;switch(id){
 case 0x607c0006U:text=L"One-based part/segment number, not a byte offset or quantity.";break;
 case 0x607c000fU:text=L"Configured encoded characters per output line; escapes may extend the encoded line.";break;
 case 0x607c0010U:text=L"One-based part/segment number, not a byte offset or quantity.";break;
 case 0x607c0012U:text=L"One-based inclusive byte position in the reconstructed output, not a physical file offset.";break;
 case 0x607c0013U:text=L"One-based inclusive byte position in the reconstructed output, not a physical file offset.";break;
 case 0x607c0015U:text=L"Name size includes its terminating NUL. Unknown physical header bytes retained without inferred meaning; adaptive Huffman parameters/payload remain raw.";break;
 case 0x607c0016U:text=L"Literal run length = control - 0xE0 bytes. The immediately following bytes are literals.";break;
 case 0x607c0017U:text=L"Length=(control>>5)+2; distance=((control&31)<<8|distance_low)+1 in current decoded block; no physical file offset is stored.";break;
 case 0x607c0018U:text=L"Length=length_code+4; source is an absolute byte position inside the current decoded block, not a stored-file offset.";break;
 case 0x607c0019U:text=L"0xE0 ends a decoded block; a second consecutive empty block terminates the file.";break;
 case 0x607c001aU:text=L"BALZ 1.20 stored output byte length; the range-coded body has no independent byte-aligned per-symbol headers.";break;
 case 0x607c001bU:text=L"Original bzip 0 stream: ASCII block-size digit 1..9 multiplies 100000 bytes. Arithmetic-coded blocks and whole-file CRC are not mapped to fabricated byte fields.";break;
 case 0x607c001cU:text=L"Freeze 2 distance-code counts: low word bits 0,1..2,3..5,6..9,10..14 hold counts for lengths 1..5; next byte stores length 6 count. Length 7/8 counts are derived.";break;
 case 0x607c001dU:text=L"Each stored byte is XOR 0x69. Decoded tag is ASCII and decoded big-endian size includes this 8-byte header; decoded numbers are not the raw stored value.";break;
 case 0x607c001fU:text=L"SOU VCTL/VTTL/VTLK size includes its 8-byte header.";break;
 case 0x607c0020U:text=L"Big-endian mouth-sync timing value; time units depend on the game, not audio sample positions. 0xFFFF is the end sentinel.";break;
 case 0x607c0027U:text=L"Repeat count encoding; 0xFFFF means endless repetition.";break;
 case 0x607c002bU:text=L"RVZ v1 native scope is GameCube without partitions. Compression level is signed (Zstandard supports negative values).";break;
 case 0x607c002cU:text=L"Offset refers to reconstructed ISO bytes, not this physical RVZ file.";break;
 case 0x607c002dU:text=L"Physical payload offset=data_offset_div4*4. Size low 31 bits are stored bytes; bit 31 selects configured compression. Packed size 0 means RVZ packing is absent.";break;
 case 0x607c002eU:text=L"Low31 bits are output byte length; bit 31 selects 68 bytes of PRNG seed instead of literal bytes.";break;
 case 0x607c002fU:text=L"17 big-endian seed words for Dolphin RVZ lagged-Fibonacci padding generator.";break;
 case 0x607c0031U:text=L"Each distinct physical character maps to its 0..63 position; four encoded symbols represent three bytes in reverse group order.";break;
 case 0x607c0032U:text=L"Name length=first character-0x40. The 36 encoded symbols carry 27 decoded metadata bytes; fields that share encoded symbols are deliberately not assigned fictitious byte offsets.";break;
 case 0x607c0033U:text=L"Four alphabet symbols encode the little-endian CRC16/XMODEM plus one padding byte; checksum covers decoded padded data.";break;
 case 0x607c003bU:text=L"UU/XX alphabet value of this character gives decoded byte count. The following groups encode 3 bytes per 4 symbols.";break;
 case 0x607c0045U:text=L"Contiguous stored Ascii85 digit characters; whitespace can split a decoded group. z/y/w are separate shorthand tokens.";break;
 case 0x607c0046U:text=L"Ascii85/btoa shorthand: z=zeros, y=spaces (or legacy 0xFF), w=256x0xFF in old btoa; native validation determines legal dialect.";break;
 case 0x607c0047U:text=L"btoa5 line check character; retained physically. Native reader ignores its value and verifies trailer checksums.";break;
 case 0x607c0048U:text=L"Invalid or overflowing hexadecimal token; original encoded bytes retained without numeric interpretation.";break;
 default:break;}
 if(id==sxarm_rvz_disc_header.id&&!xx_rt_wcscmp(r->name,L"disc_type")){if(xx_var_get_u64(&r->value)==1)text=L"GameCube";else if(xx_var_get_u64(&r->value)==2)text=L"Wii";}
 if(id==sxarm_rvz_disc_header.id&&!xx_rt_wcscmp(r->name,L"compression")){switch(xx_var_get_u64(&r->value)){case 0:text=L"None (stored tables and groups)";break;case 5:text=L"Zstandard";break;default:text=L"Other RVZ compression method; compressed metadata remains raw";break;}}
 if(id==sxarm_sou_voc_block.id&&!xx_rt_wcscmp(r->name,L"block_type")){static const wchar_t*const names[]={L"Terminator",L"Sound data",L"Sound data continuation",L"Silence",L"Marker",L"Text",L"Repeat start",L"Repeat end",L"Extended sound information",L"New sound data"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}

 return !text||xx_data_struct_record_set_comment(r,text);
}
bool sxarm_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxarm_read(sx_context*c,uint64_t p,void*b,size_t n){return sxarm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxarm_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxarm_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxarm_read(c,p,b,n))return false;*v=sxarm_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxarm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXARM_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxarm_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxarm_add(sx_context*c,const sx_layout*l,uint64_t p){return sxarm_put(c,l,p,0,false);}
bool sxarm_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxarm_put(c,l,p,n,aliases);}
static int sxarm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxarm_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxarm_order);return !c->failed;}
bool sxarm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxarm_add(c,l,p+i*width))return false;return true;}
bool sxarm_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxarm_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxarm_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}
bool sxarm_eq(const uint8_t*b,size_t n,const char*s){size_t z=xx_rt_strlen(s);if(z!=n)return false;for(size_t i=0;i<n;i++){unsigned x=b[i],y=(unsigned char)s[i];if(x>='A'&&x<='Z')x+=32;if(y>='A'&&y<='Z')y+=32;if(x!=y)return false;}return true;}
bool sxarm_uint_text(const uint8_t*b,size_t n,unsigned radix,uint64_t*v){*v=0;if(!n||n>24)return false;for(size_t i=0;i<n;i++){unsigned x=b[i],d=x>='0'&&x<='9'?x-'0':x>='a'&&x<='f'?x-'a'+10:x>='A'&&x<='F'?x-'A'+10:255;if(d>=radix||*v>(UINT64_MAX-d)/radix)return false;*v=*v*radix+d;}return true;}
static bool sxarm_name(sx_context*c,uint64_t p,uint64_t n){return sxarm_text(c,&sxarm_archiveremaining_name,p,n,false);}
/* Strict encoded integers are emitted only when the physical token converts.
 * Damaged optional hexadecimal tokens remain in raw gaps. */
bool sxarm_numeric_text(sx_context*c,const sx_layout*l,uint64_t p,const uint8_t*b,size_t n){uint64_t value;if(!xx_rt_wcsncmp(l->fields[0].type,L"ascii_hex",9)&&!sxarm_uint_text(b,n,16,&value))return sxarm_text(c,&sxarm_transport_invalid_number,p,n,false);return sxarm_text(c,l,p,n,false);}
/* Native archive callbacks publish authenticated source extents. No reader
 * factory or decoder is called here, and callback state is always released. */
static bool sxarm_callback(sx_context*c,bool pax){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXARM_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset>=f->base_address&&r->header_size>0){uint64_t p=(uint64_t)(r->header_offset-f->base_address),z=(uint64_t)r->header_size;if(!sxarm_span(c,p,z)){ok=false;break;}if(pax){if(z<32||!sxarm_add(c,&sxarm_pax_member,p)||!sxarm_name(c,p+30,z-30)){ok=false;break;}}else if(!sxarm_name(c,p,z)){ok=false;break;}}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
static bool sx_archiveremaining_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_WARC:case XX_FILE_TYPE_GLU:case XX_FILE_TYPE_PCOMMOS2:case XX_FILE_TYPE_PAX:case XX_FILE_TYPE_BTOA:case XX_FILE_TYPE_UUE:case XX_FILE_TYPE_BINSCII:case XX_FILE_TYPE_YENC_ENCODED_FILE:case XX_FILE_TYPE_BALZ:case XX_FILE_TYPE_BZIP1:case XX_FILE_TYPE_FREEZE:case XX_FILE_TYPE_RVZ:case XX_FILE_TYPE_AUDIO_SCUMM_SOU:case XX_FILE_TYPE_HE_TLKB:return true;default:return false;}}
static bool sx_archiveremaining_build(sx_context*c){bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_WARC:ok=sx_warc_build(c);break;case XX_FILE_TYPE_GLU:ok=sxarm_callback(c,false);break;case XX_FILE_TYPE_PAX:ok=sxarm_callback(c,true);break;case XX_FILE_TYPE_PCOMMOS2:ok=sx_pcommos2_build(c);break;case XX_FILE_TYPE_BTOA:ok=sx_btoa_build(c);break;case XX_FILE_TYPE_UUE:ok=sx_uue_build(c);break;case XX_FILE_TYPE_BINSCII:ok=sx_binscii_build(c);break;case XX_FILE_TYPE_YENC_ENCODED_FILE:ok=sx_yenc_encoded_file_build(c);break;case XX_FILE_TYPE_BALZ:ok=sx_balz_build(c);break;case XX_FILE_TYPE_BZIP1:ok=sx_bzip1_build(c);break;case XX_FILE_TYPE_FREEZE:ok=sx_freeze_build(c);break;case XX_FILE_TYPE_RVZ:ok=sx_rvz_build(c);break;case XX_FILE_TYPE_AUDIO_SCUMM_SOU:ok=sx_audio_scumm_sou_build(c);break;case XX_FILE_TYPE_HE_TLKB:ok=sx_he_tlkb_build(c);break;default:return false;}(void)ok;/* Bounded valid prefix survives damaged optional metadata or display cap. */return c->count&&sxarm_finish(c);}
const sx_family sx_archiveremaining_family={sx_archiveremaining_supports,sx_archiveremaining_build,sx_archiveremaining_layouts,SX_COUNT(sx_archiveremaining_layouts),sx_archiveremaining_comment};
