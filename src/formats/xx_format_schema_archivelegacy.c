/* SPDX-License-Identifier: MIT. Physical archive metadata. Scope: docs/data_struct_archivelegacy_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivelegacy.h"
static const xx_data_struct_field_desc sxag_archivelegacy_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
const sx_layout sxag_archivelegacy_dcl = {UINT32_C(0x60250020),"archivelegacy_dcl",sxag_archivelegacy_dcl_fields,SX_COUNT(sxag_archivelegacy_dcl_fields),SX_LE};
static const sx_layout *const sx_archivelegacy_layouts[] = {
 &sxag_amplus_header,
 &sxag_amplus_chunk,
 &sxag_amplus_data,
 &sxag_amplus_file,
 &sxag_nowcompress_header,
 &sxag_nowcompress_entry,
 &sxag_nowcompress_stream,
 &sxag_nowcompress_block,
 &sxag_nowcompress_stream_end,
 &sxag_applelink_header,
 &sxag_applelink_member,
 &sxag_arc_cbm_member,
 &sxag_arc_cbm_v2,
 &sxag_vmarc_member,
 &sxag_vmarc_record,
 &sxag_ti99_tifiles,
 &sxag_ti99_fiad,
 &sxag_ti99_record_count,
 &sxag_ti99_fiad_times,
 &sxag_ti99_entry,
 &sxag_ti99_catalog_end,
 &sxag_zfsf_header,
 &sxag_zfsf_group,
 &sxag_zfsf_entry,
 &sxag_trcpak_header,
 &sxag_trcpak_entry,
 &sxag_chieflz_header,
 &sxag_chieflz_entry,
 &sxag_ibmzpak_header,
 &sxag_ibmzpak_entry,
 &sxag_ibmzpak_count,
 &sxag_archivelegacy_dcl,
 &sxag_ascend_header,
 &sxag_cfl_header,
 &sxag_cfl_directory_block,
 &sxag_cfl_directory_size,
 &sxag_cfl_entry,
 &sxag_cfl_member_block,
 &sxag_dpk_header,
 &sxag_dpk_entry,
 &sxag_swagpacket_header,
 &sxag_swagpacket_entry,
 &sxag_marc_header,
 &sxag_marc_entry,
 &sxag_hlb_header,
 &sxag_hlb_entry,
 &sxag_hlb_footer,
 &sxag_jam_header,
 &sxag_jam_file_count,
 &sxag_jam_directory_count,
 &sxag_jam_file,
 &sxag_jam_directory,
 &sxag_tws_header,
 &sxag_tws_entry,
 &sxag_fiz_member,
 &sxag_ealib_header,
 &sxag_ealib_entry,
 &sxag_ealib_packed_size,
};
static bool sx_archivelegacy_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60250000U||id>=0x60260000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x60250001U:
 if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Byte count following this field, including the APUP form type.";
 break;
 case 0x60250003U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"PACK: 0=AMPK codec, other values denote unsupported XPK variants. DATA is stored.";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes packed into big-endian 32-bit words, with zero tail padding.";
 break;
 case 0x60250004U:
 if(!xx_rt_wcscmp(r->name,L"body_size"))text=L"FILE chunk body byte count includes its nested NAME chunk.";
 if(!xx_rt_wcscmp(r->name,L"days"))text=L"Amiga DateStamp days since 1978-01-01.";
 if(!xx_rt_wcscmp(r->name,L"minutes"))text=L"Amiga DateStamp minutes since midnight.";
 if(!xx_rt_wcscmp(r->name,L"ticks"))text=L"Amiga DateStamp ticks within the minute, 50 ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"protection"))text=L"Complete Amiga protection flag bit word.";
 break;
 case 0x60250006U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 4 marks a directory.";
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"accessed"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of the first 106 entry bytes.";
 break;
 case 0x60250008U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 5=Huffman, low 5 bits=old LZ, bit 6=new LZ; zero means stored. Equal consecutive offsets reset history.";
 if(!xx_rt_wcscmp(r->name,L"padding_size"))text=L"Padding after the block and its four-byte opaque trailer.";
 break;
 case 0x60250009U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of the stream-table bytes preceding this checksum.";
 break;
 case 0x6025000bU:
 if(!xx_rt_wcscmp(r->name,L"resource_method"))text=L"0=stored, 3=Squeeze.";
 if(!xx_rt_wcscmp(r->name,L"data_method"))text=L"0=stored, 3=Squeeze.";
 if(!xx_rt_wcscmp(r->name,L"resource_storage_blocks"))text=L"ProDOS storage allocation in 512-byte blocks; not a byte length.";
 if(!xx_rt_wcscmp(r->name,L"data_storage_blocks"))text=L"ProDOS storage allocation in 512-byte blocks; not a byte length.";
 if(!xx_rt_wcscmp(r->name,L"storage_type"))text=L"13=directory.";
 if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"header_crc16"))text=L"CRC16/XMODEM over the first 52 fixed-header bytes and the variable name.";
 break;
 case 0x6025000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Version 1: byte sum. Version 2: sum of each byte XOR its one-based byte index modulo 256.";
 if(!xx_rt_wcscmp(r->name,L"block_count"))text=L"Physical member span in 254-byte Commodore blocks.";
 break;
 case 0x6025000dU:
 if(!xx_rt_wcscmp(r->name,L"record_length"))text=L"Record byte length for Commodore relative files.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x6025000eU:
 if(!xx_rt_wcscmp(r->name,L"name_ebcdic"))text=L"Blank-padded EBCDIC CP037 filename; original encoded bytes are retained.";
 if(!xx_rt_wcscmp(r->name,L"type_ebcdic"))text=L"Blank-padded EBCDIC CP037 CMS file type.";
 if(!xx_rt_wcscmp(r->name,L"record_format"))text=L"EBCDIC F (0xC6)=fixed, V (0xE5)=variable.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=12-byte extension; bit 6=stored; bit 7=other codec when not stored.";
 break;
 case 0x6025000fU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Stored-record byte count; zero terminates the member.";
 break;
 case 0x60250010U:
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte sectors.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native ARK wrapper: bit 1 selects LZW-compressed archive data.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250011U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native ARK wrapper: bit 1 selects LZW-compressed archive data.";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte sectors.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250013U:
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Encoded TI file date/time, retained in physical byte order.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Encoded TI file date/time, retained in physical byte order.";
 break;
 case 0x60250014U:
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte payload sectors.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250015U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"END! marks the last catalog sector; zero continues the catalog.";
 break;
 case 0x6025001cU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=directory; other values use file_parent.";
 if(!xx_rt_wcscmp(r->name,L"directory_parent"))text=L"One-based parent entry index for directories, zero denotes root.";
 if(!xx_rt_wcscmp(r->name,L"file_parent"))text=L"One-based parent entry index for files, zero denotes root.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))text=L"Bitwise complement of the uncompressed-data CRC32.";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Encoded name bytes in the following name pool: byte i is stored as character+i+4.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"2=stored, 3=unsupported method, 4=ChiefLZ.";
 break;
 case 0x6025001eU:
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250020U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0=literal bytes, 1=Huffman-coded literals.";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Extra distance bits: 4, 5, or 6; dictionary size is 1 << (6+this value) bytes.";
 break;
 case 0x60250023U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored directory, 1=zlib directory without Adler32 trailer.";
 break;
 case 0x60250025U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored, 1=zlib stream in a physical member block.";
 break;
 case 0x60250026U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Byte count following this field, including the uncompressed-size word.";
 break;
 case 0x60250028U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Complete directory record size, including variable NUL-padded name.";
 break;
 case 0x6025002aU:
 if(!xx_rt_wcscmp(r->name,L"entry_index"))text=L"One-based member ordinal.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"ASCII MM-DD-YY.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"ASCII HH:MM.";
 if(!xx_rt_wcscmp(r->name,L"block_count"))text=L"Total 128-byte member blocks, including this header block.";
 break;
 case 0x60250035U:
 if(!xx_rt_wcscmp(r->name,L"entry_count_minus1"))text=L"Member count is this encoded value plus one.";
 break;
 case 0x60250036U:
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250037U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored, 1=LH5.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250039U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 or 3=stored, 1=LZSS, 4=PKWARE DCL; the last directory entry is the end sentinel.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to this EALIB container; the sentinel bounds its payload.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAG_LIMIT 20000U
bool sxag_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxag_read(sx_context *c,uint64_t p,void *b,size_t n){return sxag_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxag_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint16_t sxag16(const uint8_t *b,bool be){return (uint16_t)sxag_uint(b,2,be);}
uint32_t sxag32(const uint8_t *b,bool be){return (uint32_t)sxag_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
bool sxag_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
bool sxag_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxag_span(c,p,n))return false;if(!sxag_free(c,p,n))return true;return c->count>=SXAG_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxag_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXAG_LIMIT||!sxag_span(c,p,n*z))return false;if(!sxag_free(c,p,n*z))return true;return c->count>=SXAG_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sxag_fixed(sx_context *c,const sx_layout *header,const sx_layout *entry,unsigned h,unsigned field,unsigned width,bool be,uint64_t p,int extra){uint8_t b[32];if(h>sizeof(b)||!sxag_read(c,0,b,h)||!sxag_add(c,header,0))return false;uint64_t n=sxag_uint(b+field,width,be);if(n>INT32_MAX||n>SXAG_LIMIT)return true;n+=(unsigned)extra;if(!n||n>SXAG_LIMIT)return true;uint64_t z=(uint64_t)(entry->fields[entry->field_count-1].rel_offset+entry->fields[entry->field_count-1].size);if(!sxag_span(c,p,n*z))return true;return sxag_table(c,entry,p,n);}
static int sxag_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxag_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxag_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxag_order);return !c->failed;}
static bool sx_archivelegacy_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_AMPLUS:case XX_FILE_TYPE_NOWCOMPRESS:case XX_FILE_TYPE_APPLELINK_PE:case XX_FILE_TYPE_ARC_CBM:case XX_FILE_TYPE_VMARC:case XX_FILE_TYPE_TI99ARC:case XX_FILE_TYPE_ZFSF:case XX_FILE_TYPE_TRCPAK:case XX_FILE_TYPE_CHIEFLZMULTI:case XX_FILE_TYPE_IBMZPAK:case XX_FILE_TYPE_ASCEND:case XX_FILE_TYPE_CFL:case XX_FILE_TYPE_DPK:case XX_FILE_TYPE_SWAGPACKET:case XX_FILE_TYPE_MARC:case XX_FILE_TYPE_HLB:case XX_FILE_TYPE_JAM:case XX_FILE_TYPE_TWS:case XX_FILE_TYPE_FIZ:case XX_FILE_TYPE_EALIB:return true;default:return false;}}
static bool sx_archivelegacy_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_AMPLUS:ok=sx_amplus_build(c);break;case XX_FILE_TYPE_NOWCOMPRESS:ok=sx_nowcompress_build(c);break;case XX_FILE_TYPE_APPLELINK_PE:ok=sx_applelink_pe_build(c);break;case XX_FILE_TYPE_ARC_CBM:ok=sx_arc_cbm_build(c);break;case XX_FILE_TYPE_VMARC:ok=sx_vmarc_build(c);break;case XX_FILE_TYPE_TI99ARC:ok=sx_ti99arc_build(c);break;case XX_FILE_TYPE_ZFSF:ok=sx_zfsf_build(c);break;case XX_FILE_TYPE_TRCPAK:ok=sx_trcpak_build(c);break;case XX_FILE_TYPE_CHIEFLZMULTI:ok=sx_chieflzmulti_build(c);break;case XX_FILE_TYPE_IBMZPAK:ok=sx_ibmzpak_build(c);break;case XX_FILE_TYPE_ASCEND:ok=sx_ascend_build(c);break;case XX_FILE_TYPE_CFL:ok=sx_cfl_build(c);break;case XX_FILE_TYPE_DPK:ok=sx_dpk_build(c);break;case XX_FILE_TYPE_SWAGPACKET:ok=sx_swagpacket_build(c);break;case XX_FILE_TYPE_MARC:ok=sx_marc_build(c);break;case XX_FILE_TYPE_HLB:ok=sx_hlb_build(c);break;case XX_FILE_TYPE_JAM:ok=sx_jam_build(c);break;case XX_FILE_TYPE_TWS:ok=sx_tws_build(c);break;case XX_FILE_TYPE_FIZ:ok=sx_fiz_build(c);break;case XX_FILE_TYPE_EALIB:ok=sx_ealib_build(c);break;default:break;}return ok&&sxag_finish(c);}
const sx_family sx_archivelegacy_family={sx_archivelegacy_supports,sx_archivelegacy_build,sx_archivelegacy_layouts,SX_COUNT(sx_archivelegacy_layouts),sx_archivelegacy_comment};
