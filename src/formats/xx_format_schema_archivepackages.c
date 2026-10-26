/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivepackages_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivepackages.h"
static const xx_data_struct_field_desc sxap_archivepackages_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxap_archivepackages_dcl = {UINT32_C(0x60720039),"archivepackages_dcl",sxap_archivepackages_dcl_fields,SX_COUNT(sxap_archivepackages_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxap_archivepackages_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxap_archivepackages_name = {UINT32_C(0x6072003a),"archivepackages_name",sxap_archivepackages_name_fields,SX_COUNT(sxap_archivepackages_name_fields),SX_LE};
static const sx_layout *const sx_archivepackages_layouts[] = {
 &sxap_kpck_header,
 &sxap_kpck_filter,
 &sxap_lingvo_header,
 &sxap_lingvo_index_v1,
 &sxap_lingvo_member_v1,
 &sxap_lingvo_index_v2,
 &sxap_lingvo_member_v2,
 &sxap_finear_header,
 &sxap_lingvo_stream_header,
 &sxap_lingvo_code_length,
 &sxap_legacy_lz4_magic,
 &sxap_legacy_lz4_block,
 &sxap_legacy_lz4_skip,
 &sxap_ssm_header,
 &sxap_spark_prefix,
 &sxap_spark_original_size,
 &sxap_spark_riscos,
 &sxap_spark_end,
 &sxap_wrzl_header,
 &sxap_wrzl_block_size,
 &sxap_wrzl_mode,
 &sxap_wrzl_control,
 &sxap_qip_header,
 &sxap_qip_index,
 &sxap_qip_member_v1,
 &sxap_qip_member_v2,
 &sxap_twrx_header,
 &sxap_twrx_deflate,
 &sxap_beospkg_header,
 &sxap_beospkg_tag,
 &sxap_beospkg_value32,
 &sxap_beospkg_value64,
 &sxap_beospkg_offset64,
 &sxap_beospkg_size64,
 &sxap_beospkg_length,
 &sxap_beospkg_chunk,
 &sxap_cpoint_setup,
 &sxap_cpoint_file,
 &sxap_cpoint_footer,
 &sxap_mlbft_header,
 &sxap_mlbft_member,
 &sxap_oberon_member,
 &sxap_oberon_szdd,
 &sxap_solitaire_header,
 &sxap_solitaire_member,
 &sxap_rdc_block,
 &sxap_kgb2_header,
 &sxap_kgb2_member,
 &sxap_kgb2_encryption,
 &sxap_tar_nextstep_header,
 &sxap_bff_volume,
 &sxap_bff_legacy,
 &sxap_bff_member,
 &sxap_bff_compact,
 &sxap_bff_security_sizes,
 &sxap_bff_terminator,
 &sxap_archivepackages_dcl,
 &sxap_archivepackages_name,
 &sxap_vms_backup_block,
 &sxap_vms_backup_record,
 &sxap_vms_backup_file_version,
 &sxap_vms_backup_attribute,
 &sxap_vms_backup_fid,
 &sxap_vms_backup_characteristics,
 &sxap_vms_backup_date,
 &sxap_vms_backup_fat,
 &sxap_vmspcsi_header,
 &sxap_vmspcsi_table,
 &sxap_vmspcsi_context,
 &sxap_vmspcsi_bitmap,
 &sxap_vmspcsi_node,
 &sxap_vmspcsi_context_map,
 &sxap_vmspcsi_record,
 &sxap_vmsdb_prefix,
 &sxap_vmsdb_short,
 &sxap_vmsdb_indefinite,
 &sxap_vmsdb_long1,
 &sxap_vmsdb_long2,
 &sxap_vmsdb_attributes,
};
static bool sx_archivepackages_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60720000U||id>=0x60730000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60720001U:
 if(!xx_rt_wcscmp(r->name,L"method_flags"))text=L"1=LZMA; 0x40=x86 filter1; 0x80=x86 filter2, mutually exclusive";
 break;
 case 0x60720002U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"x86 call-trick marker; parameters occupy the final five physical bytes";
 break;
 case 0x60720005U:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"Packed DOS date/time";
 if(!xx_rt_wcscmp(r->name,L"fragment_method"))text=L"0=complete FINEAR, 6=first fragment, 2=continuation from previous volume";
 break;
 case 0x60720007U:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"Packed DOS date/time";
 if(!xx_rt_wcscmp(r->name,L"fragment_method"))text=L"0=complete FINEAR, 6=first fragment, 2=continuation from previous volume";
 break;
 case 0x60720008U:
 if(!xx_rt_wcscmp(r->name,L"crc16_word"))text=L"CRC16/ARC stored in a 32-bit word";
 break;
 case 0x60720009U:
 if(!xx_rt_wcscmp(r->name,L"parameters"))text=L"Fixed native-supported stream parameters; individual meanings not established";
 break;
 case 0x6072000aU:
 if(!xx_rt_wcscmp(r->name,L"code_bits"))text=L"Canonical Huffman symbol code length in bits; 321 symbols including end marker256";
 break;
 case 0x6072000bU:
 if(!xx_rt_wcscmp(r->name,L"magic"))text=L"0x184C2102 legacy frame; 0x184D2A50..0x184D2A5F skippable frames";
 break;
 case 0x6072000eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"3 or5 PICTools opcode stream; synthesized MZ prologue is not stored metadata";
 break;
 case 0x6072000fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"High bit indicates RISC OS extension; masked0 ends archive";
 break;
 case 0x60720011U:
 if(!xx_rt_wcscmp(r->name,L"load_address"))text=L"Filetyped RISC OS words may encode type/date rather than address";
 if(!xx_rt_wcscmp(r->name,L"exec_address"))text=L"For filetyped load word, this contains timestamp low bits";
 break;
 case 0x60720012U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Masked method0 terminates the containing member chain";
 break;
 case 0x60720014U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Includes mode byte and any control words";
 break;
 case 0x60720015U:
 if(!xx_rt_wcscmp(r->name,L"mode"))text=L"0x80 copied; 0x40 LZRW1/KH coded";
 break;
 case 0x60720016U:
 if(!xx_rt_wcscmp(r->name,L"control_bits"))text=L"Sixteen token flags, most significant bit first; subsequent codec tokens remain raw";
 break;
 case 0x60720019U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=file,1=install path";
 if(!xx_rt_wcscmp(r->name,L"sequence_number"))text=L"One-based sequence number";
 break;
 case 0x6072001aU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=file,1=install path";
 if(!xx_rt_wcscmp(r->name,L"sequence_number"))text=L"One-based sequence number";
 break;
 case 0x6072001bU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored,6=DCL,8=Deflate with six-byte prefix";
 if(!xx_rt_wcscmp(r->name,L"stamp_low"))text=L"Unidentified low stamp word";
 if(!xx_rt_wcscmp(r->name,L"packed_crc32"))text=L"Reflected CRC32 seed0/no final complement; zero disables verification";
 break;
 case 0x6072001eU:
 if(!xx_rt_wcscmp(r->name,L"payload_type"))text=L"0x101=u32BE,0x102=u64BE,0x200=string,0x300=chunk,0x400=group,0x500=blob; zero tag/type=end group";
 break;
 case 0x60720024U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"2=zlib";
 break;
 case 0x60720025U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"First setup tags124,125,126";
 break;
 case 0x60720026U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"3=stored file";
 break;
 case 0x60720028U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"Native-supported version6";
 break;
 case 0x6072002aU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native accepts0 or1";
 break;
 case 0x6072002dU:
 if(!xx_rt_wcscmp(r->name,L"value"))text=L"Native metadata word; category interpretation not established";
 break;
 case 0x6072002eU:
 if(!xx_rt_wcscmp(r->name,L"size_or_stored_length"))text=L"Negative=stored byte count after negation; positive=compressed byte count; zero=stream end";
 break;
 case 0x6072002fU:
 if(!xx_rt_wcscmp(r->name,L"algorithm"))text=L"0=stored;1..7=PAQ-family solid models";
 break;
 case 0x60720030U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Size of _wfinddata64_t record, excluding this word and final byte sum";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"UTF16LE NUL-terminated; unused suffix may contain stale bytes";
 if(!xx_rt_wcscmp(r->name,L"byte_sum"))text=L"Sum of plaintext bytes";
 break;
 case 0x60720031U:
 if(!xx_rt_wcscmp(r->name,L"encrypted_check"))text=L"Encrypted payload prefix; no plaintext interpretation";
 break;
 case 0x60720032U:
 if(!xx_rt_wcscmp(r->name,L"typeflag"))text=L"0/ASCII0=regular,1/2=link no payload,5=directory";
 if(!xx_rt_wcscmp(r->name,L"unknown_tail"))text=L"Native reader does not define the remaining shifted TAR dialect fields";
 break;
 case 0x60720033U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Header length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"volume_words"))text=L"Number of eight-byte words";
 break;
 case 0x60720034U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720035U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720036U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720037U:
 if(!xx_rt_wcscmp(r->name,L"acl_words"))text=L"ACL length in eight-byte words";
 if(!xx_rt_wcscmp(r->name,L"pcl_words"))text=L"PCL length in eight-byte words";
 break;
 case 0x60720039U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0=raw literals,1=coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Dictionary selector4..6";
 break;
 case 0x6072003bU:
 if(!xx_rt_wcscmp(r->name,L"application"))text=L"1=BACKUP data,2=filler";
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Filler block zero inherits first block size";
 if(!xx_rt_wcscmp(r->name,L"bucket_size"))text=L"Bucket size in512-byte blocks";
 if(!xx_rt_wcscmp(r->name,L"file_size"))text=L"BBH file size word; native does not consume units";
 break;
 case 0x6072003cU:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0=null,1=summary,3=file,4=VBN data";
 if(!xx_rt_wcscmp(r->name,L"address"))text=L"Record logical address; not physical file offset";
 break;
 case 0x6072003eU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x2a=name,0x2c=FID,0x33=characteristics,0x34=FAT,0x36/37=dates";
 break;
 case 0x60720040U:
 if(!xx_rt_wcscmp(r->name,L"characteristics"))text=L"0x2000=directory; stored Files-11 characteristics";
 break;
 case 0x60720041U:
 if(!xx_rt_wcscmp(r->name,L"vms_time"))text=L"VMS100-nanosecond ticks since1858-11-17; not Unix seconds";
 break;
 case 0x60720042U:
 if(!xx_rt_wcscmp(r->name,L"high_block"))text=L"Allocated512-byte block count, PDP word order";
 if(!xx_rt_wcscmp(r->name,L"eof_block"))text=L"One-based EOF block; byte size=(eof_block-1)*512+first_free_byte";
 if(!xx_rt_wcscmp(r->name,L"first_free_byte"))text=L"Offset within the EOF block";
 if(!xx_rt_wcscmp(r->name,L"bucket_size"))text=L"In512-byte blocks";
 if(!xx_rt_wcscmp(r->name,L"default_extend"))text=L"Allocation extension in512-byte blocks";
 break;
 case 0x60720045U:
 if(!xx_rt_wcscmp(r->name,L"node_offset"))text=L"Relative to this context block";
 if(!xx_rt_wcscmp(r->name,L"map_offset"))text=L"Relative to this context block; zero means implicit context0";
 break;
 case 0x60720046U:
 if(!xx_rt_wcscmp(r->name,L"leaf_flags"))text=L"One bit per node; one=leaf symbol, zero=child index";
 break;
 case 0x60720047U:
 if(!xx_rt_wcscmp(r->name,L"symbol_or_child"))text=L"Leaf bitmap selects symbol vs child/2; child0 ends record";
 break;
 case 0x60720048U:
 if(!xx_rt_wcscmp(r->name,L"next_context"))text=L"Context index selected after decoding the corresponding symbol";
 break;
 case 0x60720049U:
 if(!xx_rt_wcscmp(r->name,L"unknown_record_word"))text=L"Physical two-byte prefix discarded by native codec; later record starts are codec-defined";
 break;
 case 0x6072004aU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"0xffff introduces the BER-like PCSI database";
 break;
 case 0x6072004cU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x80: constructed value terminated by tag0";
 break;
 case 0x6072004dU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x81";
 break;
 case 0x6072004eU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x82";
 break;
 case 0x6072004fU:
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"Signed512-byte block count; effective size=max(0,(blocks-1)*512+last_block_bytes)";
 if(!xx_rt_wcscmp(r->name,L"last_block_bytes"))text=L"Bytes used in last512-byte block";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXAP_LIMIT 20000U
bool sxap_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxap_read(sx_context*c,uint64_t p,void*b,size_t n){return sxap_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxap_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxap_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxap_read(c,p,b,n))return false;*v=sxap_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxap_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAP_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxap_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxap_add(sx_context*c,const sx_layout*l,uint64_t p){return sxap_put(c,l,p,0,false);}
bool sxap_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){return !n||n>4096?true:sxap_put(c,l,p,n,aliases);}
static int sxap_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxap_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxap_order);return !c->failed;}
bool sxap_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxap_add(c,l,p+i*width))return false;return true;}
bool sxap_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t b[2];return n<2||!sxap_read(c,p,b,2)||b[0]>1||b[1]<4||b[1]>6?true:sxap_add(c,&sxap_archivepackages_dcl,p);}
static bool sx_archivepackages_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_KPCK:case XX_FILE_TYPE_LINGVOARC:case XX_FILE_TYPE_LZ4DEMO:case XX_FILE_TYPE_VMSSAVESET:case XX_FILE_TYPE_SSM:case XX_FILE_TYPE_SPK:case XX_FILE_TYPE_WRZL:case XX_FILE_TYPE_QIP2:case XX_FILE_TYPE_TWRX:case XX_FILE_TYPE_BEOSPKG:case XX_FILE_TYPE_VMSPCSI:case XX_FILE_TYPE_VMSDB:case XX_FILE_TYPE_MLB_FT:case XX_FILE_TYPE_OBERON:case XX_FILE_TYPE_SOLITAIRE_DELUXE:case XX_FILE_TYPE_CPOINT:case XX_FILE_TYPE_RDC:case XX_FILE_TYPE_KGB_ARCHIVER:case XX_FILE_TYPE_TAR_NEXTSTEP:case XX_FILE_TYPE_AIXBFF:return true;default:return false;}}
static bool sx_archivepackages_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_KPCK:ok=sx_kpck_build(c);break;case XX_FILE_TYPE_LINGVOARC:ok=sx_lingvoarc_build(c);break;case XX_FILE_TYPE_LZ4DEMO:ok=sx_lz4demo_build(c);break;case XX_FILE_TYPE_VMSSAVESET:ok=sx_vmssaveset_build(c);break;case XX_FILE_TYPE_SSM:ok=sx_ssm_build(c);break;case XX_FILE_TYPE_SPK:ok=sx_spk_build(c);break;case XX_FILE_TYPE_WRZL:ok=sx_wrzl_build(c);break;case XX_FILE_TYPE_QIP2:ok=sx_qip2_build(c);break;case XX_FILE_TYPE_TWRX:ok=sx_twrx_build(c);break;case XX_FILE_TYPE_BEOSPKG:ok=sx_beospkg_build(c);break;case XX_FILE_TYPE_VMSPCSI:ok=sx_vmspcsi_build(c);break;case XX_FILE_TYPE_VMSDB:ok=sx_vmsdb_build(c);break;case XX_FILE_TYPE_MLB_FT:ok=sx_mlb_ft_build(c);break;case XX_FILE_TYPE_OBERON:ok=sx_oberon_build(c);break;case XX_FILE_TYPE_SOLITAIRE_DELUXE:ok=sx_solitaire_deluxe_build(c);break;case XX_FILE_TYPE_CPOINT:ok=sx_cpoint_build(c);break;case XX_FILE_TYPE_RDC:ok=sx_rdc_build(c);break;case XX_FILE_TYPE_KGB_ARCHIVER:ok=sx_kgb_archiver_build(c);break;case XX_FILE_TYPE_TAR_NEXTSTEP:ok=sx_tar_nextstep_build(c);break;case XX_FILE_TYPE_AIXBFF:ok=sx_aixbff_build(c);break;default:break;}(void)ok;return c->count&&sxap_finish(c);}
const sx_family sx_archivepackages_family={sx_archivepackages_supports,sx_archivepackages_build,sx_archivepackages_layouts,SX_COUNT(sx_archivepackages_layouts),sx_archivepackages_comment};
