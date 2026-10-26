/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical installer and self-extractor metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_installerextras_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_installerextras.h"
static const xx_data_struct_field_desc sxiex_installer_name_fields[] = {
    SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxiex_installer_name = {0x60820003U,"installer_name",sxiex_installer_name_fields,SX_COUNT(sxiex_installer_name_fields),SX_LE};
static const sx_layout *const sx_installerextras_layouts[] = {
    &sxiex_sbx_member,
    &sxiex_sbx_plain_size,
    &sxiex_installer_name,
    &sxiex_installer_utf16_name,
    &sxiex_installer_encoded_bytes,
    &sxiex_ffs_header,
    &sxiex_ffs_index,
    &sxiex_ffs_member,
    &sxiex_ffs_cmp1,
    &sxiex_ffs_cmp2,
    &sxiex_ffs_footer,
    &sxiex_krzip_header,
    &sxiex_krzip_encoded_name_length,
    &sxiex_krzip_encoded_fields,
    &sxiex_krzip_footer,
    &sxiex_warpin_header,
    &sxiex_warpin_extension,
    &sxiex_warpin_package,
    &sxiex_warpin_member,
    &sxiex_instalit_engine,
    &sxiex_instalit_footer,
    &sxiex_instalit_catalog_prefix,
    &sxiex_instalit_catalog_1c55,
    &sxiex_instalit_catalog_1c59,
    &sxiex_instalit_catalog_1a47,
    &sxiex_instalit_script,
    &sxiex_instalit_data_marker,
    &sxiex_abbyy_count,
    &sxiex_abbyy_string,
    &sxiex_abbyy_stream_size,
    &sxiex_abbyy_dates,
    &sxiex_abbyy_finear,
    &sxiex_abbyy_trailer,
    &sxiex_deploymaster_record,
    &sxiex_deploymaster_separator,
    &sxiex_deploymaster_bzip2,
    &sxiex_pimp_header,
    &sxiex_pimp_directory,
    &sxiex_pimp_text,
    &sxiex_pimp_v1_count,
    &sxiex_pimp_v2_count,
    &sxiex_pimp_name_length,
    &sxiex_pimp_v1_sizes,
    &sxiex_pimp_v2_sizes,
    &sxiex_pimp_command_length,
    &sxiex_softpaq_fit1,
    &sxiex_softpaq_fit2,
    &sxiex_wasp_resource_shift,
    &sxiex_wasp_resource_type,
    &sxiex_wasp_resource_entry,
    &sxiex_wasp_string_length,
    &sxiex_wasp_payload_size,
    &sxiex_sfxstart_header,
    &sxiex_sfxstart_name,
    &sxiex_sfxstart_size,
    &sxiex_sfxstart_separator,
    &sxiex_sfxstart_command,
    &sxiex_sfxstart_footer,
    &sxiex_clickteam_pack,
    &sxiex_clickteam_name,
    &sxiex_clickteam_size,
    &sxiex_clickteam_checksum_size,
    &sxiex_jugglor_member,
    &sxiex_exeattachment_member,
    &sxiex_jugglor_trailer,
    &sxiex_exeattachment_trailer,
    &sxiex_ebook_creator_header,
    &sxiex_ebook_creator_member,
    &sxiex_ebook_creator_ref,
    &sxiex_ebook_creator_list,
    &sxiex_ebook_creator_element,
    &sxiex_ebook_creator_name,
    &sxiex_ebook_creator_footer,
    &sxiex_sbook_header,
    &sxiex_sbook_count,
    &sxiex_sbook_name_length,
    &sxiex_sbook_member,
    &sxiex_sbook_chunk,
    &sxiex_sbook_footer,
    &sxiex_pftw_settings_size,
    &sxiex_pftw_settings_new,
    &sxiex_pftw_settings_old,
    &sxiex_pftw_cab_header,
    &sxiex_pftw_cab_reserve,
    &sxiex_pftw_cab_folder,
    &sxiex_pftw_cab_file,
    &sxiex_pftw_cab_data,
    &sxiex_sfx_red_header,
    &sxiex_sfx_red_name,
    &sxiex_sfx_red_short_name,
    &sxiex_sfx_red_crc16,
    &sxiex_instalit_resource_shift,
    &sxiex_instalit_resource_type,
    &sxiex_instalit_resource_entry,
    &sxiex_instalit_resource_end,
    &sxiex_instalit_resource_name_length,
    &sxiex_wasp_name_separator,
    &sxiex_wasp_run_marker,
    &sxiex_wasp_resource_end,
};
static bool sx_installerextras_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60820000U||id>=0x60830000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x60820001U:
        if(!xx_rt_wcscmp(r->name,L"record_size"))s=L"Whole record byte size, including this header, name, size word and compressed body";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820003U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored legacy byte string; codepage depends on the installer";
        break;
    case 0x60820004U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored UTF-16LE code units";
        break;
    case 0x60820005U:
        if(!xx_rt_wcscmp(r->name,L"encoded_bytes"))s=L"Encoded physical bytes; not the decoded member representation";
        break;
    case 0x60820006U:
        if(!xx_rt_wcscmp(r->name,L"complemented_file_count"))s=L"Bitwise complement of the stored file count";
        break;
    case 0x60820007U:
        if(!xx_rt_wcscmp(r->name,L"filename_crc32"))s=L"CRC32 of the upper-case member name";
        else if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Offset in original executable; carved FFS images may require an inferred common offset bias";
        break;
    case 0x60820009U:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Uncompressed byte size";
        break;
    case 0x6082000aU:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Bitwise complement of the uncompressed byte size";
        break;
    case 0x6082000bU:
        if(!xx_rt_wcscmp(r->name,L"archive_offset"))s=L"Offset from the original executable start";
        break;
    case 0x6082000dU:
        if(!xx_rt_wcscmp(r->name,L"encrypted_name_length"))s=L"XOR-obfuscated little-endian name byte length";
        break;
    case 0x6082000eU:
        if(!xx_rt_wcscmp(r->name,L"encrypted_dos_time"))s=L"XOR-obfuscated packed DOS time";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_dos_date"))s=L"XOR-obfuscated packed DOS date";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_unpacked_size"))s=L"XOR-obfuscated little-endian unpacked byte size";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_attributes"))s=L"XOR-obfuscated attribute word";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_packed_size"))s=L"XOR-obfuscated little-endian packed byte size";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_complemented_crc32"))s=L"XOR-obfuscated complemented member CRC32";
        break;
    case 0x6082000fU:
        if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))s=L"Bitwise complement of CRC32 over the deobfuscated record stream";
        break;
    case 0x60820010U:
        if(!xx_rt_wcscmp(r->name,L"script_unpacked_size_low"))s=L"Low 16 bits of the script uncompressed byte size";
        break;
    case 0x60820011U:
        if(!xx_rt_wcscmp(r->name,L"extension_size"))s=L"Includes this size word; remaining extension fields are undocumented";
        break;
    case 0x60820012U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Package data offset; native reader accepts package-relative or original-file-relative values with a common bias";
        break;
    case 0x60820013U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 bzip2";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored member checksum; native reader does not authenticate this algorithm";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix timestamp in seconds";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Unix timestamp in seconds";
        else if(!xx_rt_wcscmp(r->name,L"extension"))s=L"Native reader supports extension zero";
        break;
    case 0x60820015U:
        if(!xx_rt_wcscmp(r->name,L"script_offset"))s=L"Offset within the associated volume; may refer to another file";
        else if(!xx_rt_wcscmp(r->name,L"packed_data_offset"))s=L"Volume-zero PVL marker offset";
        else if(!xx_rt_wcscmp(r->name,L"catalog_offset"))s=L"PVM marker offset";
        break;
    case 0x60820016U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Offset relative to the packed data body of its disk volume";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820017U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x60820018U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x60820019U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x6082001dU:
        if(!xx_rt_wcscmp(r->name,L"length"))s=L"Length of the following Windows-1251 byte string";
        break;
    case 0x6082001eU:
        if(!xx_rt_wcscmp(r->name,L"stream_size"))s=L"Complete physical FINEAR stream size";
        break;
    case 0x6082001fU:
        if(!xx_rt_wcscmp(r->name,L"first_date"))s=L"Unix seconds at local midnight, as stored by the producer";
        else if(!xx_rt_wcscmp(r->name,L"second_date"))s=L"Unix seconds at local midnight, as stored by the producer";
        break;
    case 0x60820020U:
        if(!xx_rt_wcscmp(r->name,L"crc16_arc"))s=L"Stored CRC16/ARC in a 32-bit word";
        break;
    case 0x60820022U:
        if(!xx_rt_wcscmp(r->name,L"compressed_size"))s=L"Size of the following physical zlib stream";
        break;
    case 0x60820023U:
        if(!xx_rt_wcscmp(r->name,L"marker"))s=L"0xFFFFFFFF separates bzip2 engine and length-prefixed zlib records";
        break;
    case 0x60820024U:
        if(!xx_rt_wcscmp(r->name,L"block_size_digit"))s=L"ASCII digit 1..9; nominal block size in 100000-byte units";
        break;
    case 0x6082002aU:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Stored name length including the terminating NUL";
        break;
    case 0x6082002dU:
        if(!xx_rt_wcscmp(r->name,L"command_length"))s=L"Stored command length including NUL when present";
        break;
    case 0x6082002eU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Offset from the executable beginning";
        break;
    case 0x6082002fU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Offset from the executable beginning";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820030U:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))s=L"Resource physical offsets and allocation lengths are shifted left by this number of bits";
        break;
    case 0x60820031U:
        if(!xx_rt_wcscmp(r->name,L"type_identifier"))s=L"High bit denotes integer ID; otherwise resource-table-relative string offset";
        break;
    case 0x60820032U:
        if(!xx_rt_wcscmp(r->name,L"offset_units"))s=L"Physical byte offset = stored value shifted by the resource alignment shift";
        else if(!xx_rt_wcscmp(r->name,L"length_units"))s=L"Allocated byte length = stored value shifted by the resource alignment shift";
        else if(!xx_rt_wcscmp(r->name,L"resource_identifier"))s=L"High bit denotes integer ID; otherwise resource-table-relative string offset";
        break;
    case 0x60820034U:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Declared payload byte size in the member metadata string";
        break;
    case 0x60820035U:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Byte size after this header, including the command trailer";
        else if(!xx_rt_wcscmp(r->name,L"last_file_index"))s=L"File count minus one";
        break;
    case 0x6082003cU:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Character count; one-byte legacy or UTF-16LE encoding is chosen by the authenticated native variant";
        break;
    case 0x6082003eU:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Rolling rotate-left-one sum of little-endian dwords followed by remaining bytes";
        break;
    case 0x6082003fU:
        if(!xx_rt_wcscmp(r->name,L"local_filetime"))s=L"Windows FILETIME ticks in the producer's local time convention";
        break;
    case 0x60820040U:
        if(!xx_rt_wcscmp(r->name,L"local_filetime"))s=L"Windows FILETIME ticks in the producer's local time convention";
        break;
    case 0x60820041U:
        if(!xx_rt_wcscmp(r->name,L"producer_value"))s=L"Zero in later builds; 797 in the observed Jester Jugglor 1.01 variant";
        break;
    case 0x60820044U:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Includes the following unpacked-size word, excludes this block-size word";
        break;
    case 0x60820048U:
        if(!xx_rt_wcscmp(r->name,L"file_index"))s=L"One-based file index";
        break;
    case 0x6082004bU:
        if(!xx_rt_wcscmp(r->name,L"count_or_zero"))s=L"File count in the first record; zero separator in subsequent records";
        break;
    case 0x6082004dU:
        if(!xx_rt_wcscmp(r->name,L"dos_datetime"))s=L"Packed DOS date in high half and time in low half";
        break;
    case 0x6082004eU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Size of the following zlib chunk; all nonfinal chunks decode to 16384 bytes";
        break;
    case 0x60820050U:
        if(!xx_rt_wcscmp(r->name,L"settings_size"))s=L"Physical settings byte size; settings may be XOR-obfuscated";
        break;
    case 0x60820052U:
        if(!xx_rt_wcscmp(r->name,L"encoded_signature"))s=L"Alphabetic XOR encoding of SCG";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_size"))s=L"Alphabetic XOR encoding of little-endian cabinet byte size";
        break;
    case 0x60820053U:
        if(!xx_rt_wcscmp(r->name,L"files_offset"))s=L"Relative to the cabinet start";
        break;
    case 0x60820055U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to cabinet start";
        break;
    case 0x60820056U:
        if(!xx_rt_wcscmp(r->name,L"folder_offset"))s=L"Uncompressed byte offset within the folder stream; not a physical file offset";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820058U:
        if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        break;
    case 0x6082005aU:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"39-byte RED variant shares its twelfth name byte with the header checksum";
        break;
    case 0x6082005cU:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))s=L"Resource offsets and allocation lengths use 2^shift byte units";
        break;
    case 0x6082005dU:
        if(!xx_rt_wcscmp(r->name,L"type_identifier"))s=L"High bit denotes integer ID; otherwise offset from resource table start to Pascal type name";
        break;
    case 0x6082005eU:
        if(!xx_rt_wcscmp(r->name,L"offset_units"))s=L"Physical byte offset equals this word shifted by alignment_shift";
        else if(!xx_rt_wcscmp(r->name,L"length_units"))s=L"Allocated byte length equals this word shifted by alignment_shift";
        else if(!xx_rt_wcscmp(r->name,L"resource_identifier"))s=L"High bit denotes integer ID; otherwise offset from resource table start to Pascal resource name";
        break;
    case 0x6082005fU:
        if(!xx_rt_wcscmp(r->name,L"type_terminator"))s=L"Zero terminates resource type rows";
        break;
    case 0x60820060U:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Byte length of the following resource-table Pascal string";
        break;
    case 0x60820061U:
        if(!xx_rt_wcscmp(r->name,L"separator"))s=L"Comma separating the stored filename from its decimal payload size";
        break;
    case 0x60820062U:
        if(!xx_rt_wcscmp(r->name,L"run_after_extract"))s=L"Asterisk requests execution after extraction; this reader never executes it";
        break;
    case 0x60820063U:
        if(!xx_rt_wcscmp(r->name,L"type_terminator"))s=L"Zero terminates resource type rows";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXIEX_LIMIT 24000U
bool sxiex_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxiex_read(sx_context*c,uint64_t p,void*b,size_t n){return sxiex_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxiex16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
uint32_t sxiex32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
bool sxiex_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxiex_span(c,p,count*z))return false;if(!count||c->count>=SXIEX_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
bool sxiex_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxiex_span(c,p,n))return false;if(!n||n>4096||c->count>=SXIEX_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxiex_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxiex_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxiex_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxiex_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
/* Borrow the authenticated native iterator, copy only physical coordinates,
 * and release it before inspecting bytes. No subclass assumptions or ownership transfer. */
static bool sxiex_collect(sx_context*c,sxiex_records*out){
 Abstractformat*f=c->f;out->items=NULL;out->count=0;
 if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;
 xx_archive_record_state*state=(f->create_archive_records_reading)(f,NULL,c->pd);if(!state)return true;
 sxiex_member*v=xx_mem_alloc(SXIEX_LIMIT*sizeof(*v));if(!v){(f->free_archive_records_reading)(f,state);return false;}
 for(size_t i=0;i<SXIEX_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,state);if(!r)break;
  if(r->header_offset>=f->base_address&&r->header_size>=0&&r->data_offset>=f->base_address&&r->compressed_size>=0){
   uint64_t p=(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),h=(uint64_t)r->header_size,z=(uint64_t)r->compressed_size;
   if(sxiex_span(c,p,h)&&sxiex_span(c,d,z))v[out->count++]=(sxiex_member){p,h,d,z};
  }
  if(!(f->archive_record_move_to_next)(f,state,c->pd))break;
 }
 (f->free_archive_records_reading)(f,state);out->items=v;return !xx_pd_is_stopped(c->pd);
}
bool sxiex_u32(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxiex_read(c,p,b,4))return false;*v=sxiex32(b,false);return true;}
bool sxiex_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxiex_read(c,p,b,2))return false;*v=sxiex16(b,false);return true;}
bool sxiex_eq(sx_context*c,uint64_t p,const void*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxiex_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
bool sxiex_name(sx_context*c,uint64_t p,uint64_t n){return sxiex_text(c,&sxiex_installer_name,p,n);}
bool sxiex_zstr(sx_context*c,uint64_t*p,uint64_t end){uint64_t start=*p;uint8_t x;for(uint64_t k=0;k<4096&&*p<end;k++,(*p)++){if(!sxiex_read(c,*p,&x,1))return false;if(!x){(*p)++;return sxiex_name(c,start,*p-start);}}return false;}
/* This carrier walk locates an installer overlay only. It emits no PE fields. */
bool sxiex_pe(sx_context*c,uint64_t*out){
 uint8_t d[64],h[24],o[64],s[40];if(!sxiex_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;
 uint64_t at=sxiex32(d+60,false);if(!sxiex_read(c,at,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 uint16_t count=sxiex16(h+6,false),opt=sxiex16(h+20,false);if(!count||count>96||opt<64||!sxiex_read(c,at+24,o,64))return false;
 uint64_t end=sxiex32(o+60,false),tab=at+24+opt;if(!sxiex_span(c,0,end)||!sxiex_span(c,tab,(uint64_t)count*40))return false;
 for(unsigned i=0;i<count;i++){if(!sxiex_read(c,tab+40U*i,s,40))return false;uint64_t p=sxiex32(s+20,false),n=sxiex32(s+16,false);if(!sxiex_span(c,p,n))return false;if(n&&p+n>end)end=p+n;}
 *out=end;return true;
}
static bool sx_installerextras_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_SFX_SBX_EXTRACTOR:case XX_FILE_TYPE_SFX_ANALOGX_EMUCORE_FFS:case XX_FILE_TYPE_SFX_KRZIP:case XX_FILE_TYPE_SFX_WARPIN_PACKAGE:case XX_FILE_TYPE_SFX_HCI_INSTALIT:case XX_FILE_TYPE_SFX_CLICKTEAM_MULTIMEDIA_FUSION:case XX_FILE_TYPE_SFX_ABBYY_FINE_OBJECTS:case XX_FILE_TYPE_SFX_FLASHJESTER_JUGGLOR:case XX_FILE_TYPE_SFX_JGSOFT_DEPLOYMASTER_PACKAGE:case XX_FILE_TYPE_SFX_NULLSOFT_PIMP:case XX_FILE_TYPE_SFX_COMPAQ_SOFTPAQ:case XX_FILE_TYPE_SFX_WASP_WINDOWS_AUTO:case XX_FILE_TYPE_SFXSTART:case XX_FILE_TYPE_SFX_EBOOK_COMPILER_EXECUTABLES:case XX_FILE_TYPE_SFX_PACKAGEFORTHEWEB:case XX_FILE_TYPE_SFX_RED:return true;default:return false;}}
static bool sx_installerextras_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;sxiex_records records;if(!sxiex_collect(c,&records)){if(records.items)xx_mem_free(records.items);return false;}bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SFX_SBX_EXTRACTOR:ok=sx_sfx_sbx_extractor_build(c,&records);break;
case XX_FILE_TYPE_SFX_ANALOGX_EMUCORE_FFS:ok=sx_sfx_analogx_emucore_ffs_build(c,&records);break;
case XX_FILE_TYPE_SFX_KRZIP:ok=sx_sfx_krzip_build(c,&records);break;
case XX_FILE_TYPE_SFX_WARPIN_PACKAGE:ok=sx_sfx_warpin_package_build(c,&records);break;
case XX_FILE_TYPE_SFX_HCI_INSTALIT:ok=sx_sfx_hci_instalit_build(c,&records);break;
case XX_FILE_TYPE_SFX_CLICKTEAM_MULTIMEDIA_FUSION:ok=sx_sfx_clickteam_multimedia_fusion_build(c,&records);break;
case XX_FILE_TYPE_SFX_ABBYY_FINE_OBJECTS:ok=sx_sfx_abbyy_fine_objects_build(c,&records);break;
case XX_FILE_TYPE_SFX_FLASHJESTER_JUGGLOR:ok=sx_sfx_flashjester_jugglor_build(c,&records);break;
case XX_FILE_TYPE_SFX_JGSOFT_DEPLOYMASTER_PACKAGE:ok=sx_sfx_jgsoft_deploymaster_package_build(c,&records);break;
case XX_FILE_TYPE_SFX_NULLSOFT_PIMP:ok=sx_sfx_nullsoft_pimp_build(c,&records);break;
case XX_FILE_TYPE_SFX_COMPAQ_SOFTPAQ:ok=sx_sfx_compaq_softpaq_build(c,&records);break;
case XX_FILE_TYPE_SFX_WASP_WINDOWS_AUTO:ok=sx_sfx_wasp_windows_auto_build(c,&records);break;
case XX_FILE_TYPE_SFXSTART:ok=sx_sfxstart_build(c,&records);break;
case XX_FILE_TYPE_SFX_EBOOK_COMPILER_EXECUTABLES:ok=sx_sfx_ebook_compiler_executables_build(c,&records);break;
case XX_FILE_TYPE_SFX_PACKAGEFORTHEWEB:ok=sx_sfx_packagefortheweb_build(c,&records);break;
case XX_FILE_TYPE_SFX_RED:ok=sx_sfx_red_build(c,&records);break;
default:break;}if(records.items)xx_mem_free(records.items);(void)ok;return c->count&&sxiex_finish(c);}
#undef SXIEX_LIMIT
const sx_family sx_installerextras_family={sx_installerextras_supports,sx_installerextras_build,sx_installerextras_layouts,SX_COUNT(sx_installerextras_layouts),sx_installerextras_comment};
