/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-container metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_systemlater_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_systemlater.h"
static const xx_data_struct_field_desc sxsl_extadf_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",8,2,SX_RESERVED),
    SX_FIELD("track_count","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxsl_extadf_header = {0x60330026U,"extadf_header",sxsl_extadf_header_fields,SX_COUNT(sxsl_extadf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_extadf_track_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("revolution_count_minus_one","uint8",2,1,SX_NONE),
    SX_FIELD("track_type","uint8",3,1,SX_ID),
    SX_FIELD("allocated_size","uint32",4,4,SX_SIZE),
    SX_FIELD("bit_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxsl_extadf_track = {0x60330027U,"extadf_track",sxsl_extadf_track_fields,SX_COUNT(sxsl_extadf_track_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_oldextadf_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxsl_oldextadf_header = {0x60330028U,"oldextadf_header",sxsl_oldextadf_header_fields,SX_COUNT(sxsl_oldextadf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_oldextadf_track_fields[] = {
    SX_FIELD("sync_word","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxsl_oldextadf_track = {0x60330029U,"oldextadf_track",sxsl_oldextadf_track_fields,SX_COUNT(sxsl_oldextadf_track_fields),SX_BE};
static const sx_layout *const sx_systemlater_layouts[] = {
    &sxsl_lofi_header,
    &sxsl_lofi_index,
    &sxsl_lofi_segment,
    &sxsl_lofi_lzma_header,
    &sxsl_savedskf_header,
    &sxsl_diskdupe_header,
    &sxsl_diskdupe_track,
    &sxsl_pmdiskcopy_header,
    &sxsl_qrst_header,
    &sxsl_qrst_track,
    &sxsl_qrst_fill,
    &sxsl_qrst_encoded_size,
    &sxsl_hdcopy_header,
    &sxsl_hdcopy_block,
    &sxsl_apridisk_header,
    &sxsl_apridisk_record,
    &sxsl_diskcopy42_header,
    &sxsl_isz_header,
    &sxsl_isz_checksum_tail,
    &sxsl_isz_encoded_pointer1,
    &sxsl_isz_encoded_pointer2,
    &sxsl_isz_encoded_pointer3,
    &sxsl_isz_encoded_pointer4,
    &sxsl_isz_encoded_segment,
    &sxsl_mfi_header,
    &sxsl_mfi_track,
    &sxsl_sdi_header,
    &sxsl_sdi_section,
    &sxsl_nhd_header,
    &sxsl_virtual98_header,
    &sxsl_anex86_header,
    &sxsl_sap_header,
    &sxsl_sap_sector,
    &sxsl_sap_checksum,
    &sxsl_dmk_header,
    &sxsl_dmk_idam_pointer,
    &sxsl_dmk_idam,
    &sxsl_extadf_header,
    &sxsl_extadf_track,
    &sxsl_oldextadf_header,
    &sxsl_oldextadf_track,
    &sxsl_udi_header,
    &sxsl_udi_track,
    &sxsl_udi_compressed_track,
    &sxsl_udi_checksum,
    &sxsl_moof_header,
    &sxsl_moof_chunk,
    &sxsl_moof_info,
    &sxsl_moof_track_map,
    &sxsl_moof_track,
    &sxsl_bochs_growing_v1,
    &sxsl_bochs_growing_v2,
    &sxsl_bochs_catalog_entry,
    &sxsl_bochs_bitmap_byte,
    &sxsl_partclone_header_le,
    &sxsl_partclone_bitmap_crc_le,
    &sxsl_partclone_header_be,
    &sxsl_partclone_bitmap_crc_be,
    &sxsl_dms_header,
    &sxsl_dms_track,
    &sxsl_nrg_footer32,
    &sxsl_nrg_dao_track32,
    &sxsl_nrg_etn_track32,
    &sxsl_nrg_footer64,
    &sxsl_nrg_dao_track64,
    &sxsl_nrg_etn_track64,
    &sxsl_nrg_chunk,
    &sxsl_nrg_dao_header,
    &sxsl_nrg_cuex,
    &sxsl_nrg_cues,
    &sxsl_nrg_session,
    &sxsl_nrg_media,
    &sxsl_cowd_header,
    &sxsl_cowd_root,
    &sxsl_cowd_child,
    &sxsl_cowd_tail,
    &sxsl_cowd_directory,
    &sxsl_cowd_grain,
    &sxsl_sesparse_header,
    &sxsl_sesparse_volatile,
    &sxsl_sesparse_directory,
    &sxsl_sesparse_grain,
    &sxsl_dmk_idam_doubled,
    &sxsl_partclone_bitmap_byte,
    &sxsl_partclone_data_checksum4,
    &sxsl_partclone_data_checksum16,
};
static bool sx_systemlater_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60330000U||id>=0x60340000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x60330005U&&!xx_rt_wcscmp(r->name,L"signature")&&integer){switch(value){
    case 22698U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_OLD");
    case 22954U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_NEW");
    case 23210U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_COMPRESSED_LZW");
    default:break;}}
    if(id==0x60330009U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 3U:return xx_data_struct_record_set_comment(r,L"720 KiB double-density disk");
    case 4U:return xx_data_struct_record_set_comment(r,L"1.44 MiB high-density disk");
    default:break;}}
    if(id==0x6033000aU&&!xx_rt_wcscmp(r->name,L"method")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored track");
    case 1U:return xx_data_struct_record_set_comment(r,L"Repeated fill byte");
    case 2U:return xx_data_struct_record_set_comment(r,L"Run-length encoded track");
    default:break;}}
    if(id==0x60330010U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 3810328576U:return xx_data_struct_record_set_comment(r,L"Deleted record");
    case 3810328577U:return xx_data_struct_record_set_comment(r,L"Sector record");
    case 3810328578U:return xx_data_struct_record_set_comment(r,L"Comment record");
    case 3810328579U:return xx_data_struct_record_set_comment(r,L"Creator record");
    default:break;}}
    if(id==0x60330010U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 40592U:return xx_data_struct_record_set_comment(r,L"APRIDISK_STORED");
    case 15962U:return xx_data_struct_record_set_comment(r,L"APRIDISK_RLE");
    default:break;}}
    if(id==0x60330011U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"400 KiB GCR");
    case 1U:return xx_data_struct_record_set_comment(r,L"800 KiB GCR");
    case 2U:return xx_data_struct_record_set_comment(r,L"720 KiB MFM");
    case 3U:return xx_data_struct_record_set_comment(r,L"1.44 MiB MFM");
    default:break;}}
    if(id==0x60330012U&&!xx_rt_wcscmp(r->name,L"encryption")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unencrypted");
    case 1U:return xx_data_struct_record_set_comment(r,L"Password-protected");
    case 2U:return xx_data_struct_record_set_comment(r,L"AES-128");
    case 3U:return xx_data_struct_record_set_comment(r,L"AES-192");
    case 4U:return xx_data_struct_record_set_comment(r,L"AES-256");
    default:break;}}
    if(id==0x60330027U&&!xx_rt_wcscmp(r->name,L"track_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Sector data");
    case 1U:return xx_data_struct_record_set_comment(r,L"Raw MFM track");
    default:break;}}
    if(id==0x60330033U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 65536U:return xx_data_struct_record_set_comment(r,L"Bochs redolog version 1");
    default:break;}}
    if(id==0x60330034U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 131072U:return xx_data_struct_record_set_comment(r,L"Bochs redolog version 2");
    default:break;}}
    switch(id){
    case 0x60330002U:
        if(!xx_rt_wcscmp(r->name,L"segment_offset"))s=L"Relative to the end of the index; final entry marks the end of segment data.";
        break;
    case 0x60330003U:
        if(!xx_rt_wcscmp(r->name,L"compressed"))s=L"0 stored; 1 compressed using the header algorithm.";
        break;
    case 0x60330004U:
        if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded LZMA lc/lp/pb properties.";
        break;
    case 0x60330005U:
        if(!xx_rt_wcscmp(r->name,L"media_descriptor"))s=L"Low byte is the FAT media descriptor; upper byte normally zero.";
        else if(!xx_rt_wcscmp(r->name,L"cluster_shift"))s=L"Base-2 logarithm of sectors per cluster.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_sector"))s=L"Logical sector number within the restored disk.";
        else if(!xx_rt_wcscmp(r->name,L"root_directory_sector"))s=L"Logical sector number within the restored disk.";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Stored zero denotes a 512-byte data offset.";
        break;
    case 0x60330007U:
        if(!xx_rt_wcscmp(r->name,L"block_offset"))s=L"Block index relative to the inferred track data area; multiply by block_size for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"status"))s=L"Native reader accepts values 1 and 2; repeated block offsets denote unwritten tracks.";
        break;
    case 0x60330009U:
        if(!xx_rt_wcscmp(r->name,L"disk_type"))s=L"3 is 720 KiB; 4 is 1.44 MiB.";
        else if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"One-based index in the diskette set.";
        else if(!xx_rt_wcscmp(r->name,L"description_and_banner"))s=L"Physical NUL-padded text area; individual string boundaries are not fixed.";
        break;
    case 0x6033000aU:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored track; 1 repeated fill byte; 2 run-length encoded track.";
        break;
    case 0x6033000dU:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))s=L"Last zero-based cylinder index, not a count.";
        else if(!xx_rt_wcscmp(r->name,L"track_usage_map"))s=L"One byte per physical track; zero means unwritten and restored as 0xF6.";
        break;
    case 0x6033000eU:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Encoded bytes after the length, including the escape byte.";
        break;
    case 0x60330010U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"0x9E90 stored; 0x3E5A run-length encoded.";
        break;
    case 0x60330011U:
        if(!xx_rt_wcscmp(r->name,L"private_word"))s=L"DiskCopy private marker 0x0100.";
        break;
    case 0x60330014U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330015U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330016U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330017U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330018U:
        if(!xx_rt_wcscmp(r->name,L"encoded_volume_size"))s=L"XOR-obfuscated u64 volume byte size.";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"XOR-obfuscated file-relative chunk data offset.";
        else if(!xx_rt_wcscmp(r->name,L"encoded_last_chunk_continuation"))s=L"XOR-obfuscated byte count continuing in the next volume.";
        break;
    case 0x60330019U:
        if(!xx_rt_wcscmp(r->name,L"cylinders_and_resolution"))s=L"Low 30 bits: cylinder count; top 2 bits: whole/half/quarter-track resolution.";
        break;
    case 0x6033001aU:
        if(!xx_rt_wcscmp(r->name,L"write_splice"))s=L"Position in MAME angular time units; not a file offset.";
        break;
    case 0x6033001bU:
        if(!xx_rt_wcscmp(r->name,L"device_model"))s=L"GUID in Windows on-disk byte order.";
        else if(!xx_rt_wcscmp(r->name,L"runtime_guid"))s=L"GUID in Windows on-disk byte order.";
        else if(!xx_rt_wcscmp(r->name,L"page_alignment"))s=L"Page size in 512-byte sectors; table begins at one page.";
        break;
    case 0x6033001eU:
        if(!xx_rt_wcscmp(r->name,L"megabyte_size"))s=L"Capacity expressed in megabytes, not bytes.";
        break;
    case 0x60330020U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"1: 256-byte sectors; 2: 128-byte sectors.";
        break;
    case 0x60330023U:
        if(!xx_rt_wcscmp(r->name,L"write_protected"))s=L"0 writable; 0xFF write protected.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit4 single sided; bit6 single-density track bytes are not doubled.";
        else if(!xx_rt_wcscmp(r->name,L"real_disk_flags"))s=L"Native reader supports zero only.";
        break;
    case 0x60330024U:
        if(!xx_rt_wcscmp(r->name,L"offset_and_density"))s=L"Low14 bits are track-relative byte offset; bit15 marks MFM; remaining flag bit retained.";
        break;
    case 0x60330025U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector byte size is 128 shifted left by this code.";
        break;
    case 0x60330027U:
        if(!xx_rt_wcscmp(r->name,L"revolution_count_minus_one"))s=L"Number of captured revolutions minus one for raw MFM tracks.";
        else if(!xx_rt_wcscmp(r->name,L"track_type"))s=L"0 sector data; 1 raw MFM data.";
        else if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Number of meaningful bits, not bytes.";
        break;
    case 0x60330029U:
        if(!xx_rt_wcscmp(r->name,L"sync_word"))s=L"Zero selects stored sectors; nonzero is the omitted leading MFM sync word.";
        break;
    case 0x6033002bU:
        if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Raw track byte count, followed by one to three clock/weak bitmaps.";
        break;
    case 0x6033002cU:
        if(!xx_rt_wcscmp(r->name,L"compressed_size_minus_one"))s=L"Stored compressed byte length minus one.";
        else if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Uncompressed raw track byte count, excluding bitmaps.";
        break;
    case 0x6033002dU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"UDI signed-shift CRC32 variant.";
        break;
    case 0x60330030U:
        if(!xx_rt_wcscmp(r->name,L"optimal_bit_timing"))s=L"Multiples of 125 nanoseconds.";
        else if(!xx_rt_wcscmp(r->name,L"creator"))s=L"UTF-8, padded with spaces.";
        else if(!xx_rt_wcscmp(r->name,L"largest_track_blocks"))s=L"Number of 512-byte allocation blocks.";
        else if(!xx_rt_wcscmp(r->name,L"flux_block"))s=L"File-relative block index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"largest_flux_track_blocks"))s=L"Number of 512-byte allocation blocks.";
        break;
    case 0x60330031U:
        if(!xx_rt_wcscmp(r->name,L"track_index"))s=L"0xFF means an unrecorded track.";
        break;
    case 0x60330032U:
        if(!xx_rt_wcscmp(r->name,L"starting_block"))s=L"File-relative 512-byte block index.";
        else if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Number of bits for bitstream tracks, or bytes for flux tracks.";
        break;
    case 0x60330034U:
        if(!xx_rt_wcscmp(r->name,L"reserved_timestamp"))s=L"Reserved in Growing images; Undoable mode uses packed FAT date/time, not a Unix timestamp.";
        break;
    case 0x60330035U:
        if(!xx_rt_wcscmp(r->name,L"extent_index"))s=L"0xFFFFFFFF means unallocated; other values select physical extent slots.";
        break;
    case 0x60330036U:
        if(!xx_rt_wcscmp(r->name,L"allocated_sector_bits"))s=L"Low bit is the first 512-byte sector in this group.";
        break;
    case 0x6033003bU:
        if(!xx_rt_wcscmp(r->name,L"general_info"))s=L"Bit1 obfuscated; bit4 high density; bit5 MS-DOS; bit8 FILE_ID.DIZ.";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"first_track"))s=L"Inclusive track number; header range may be stale in appended archives.";
        else if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Header hint; actual track records can differ after appending.";
        else if(!xx_rt_wcscmp(r->name,L"unpacked_size"))s=L"Header hint; actual track records can differ after appending.";
        else if(!xx_rt_wcscmp(r->name,L"creator_version"))s=L"Decimal major*100 plus minor.";
        break;
    case 0x6033003cU:
        if(!xx_rt_wcscmp(r->name,L"track_number"))s=L"80 and values at least 0x8000 are informational tracks.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 retains decoder context; bit1 refreshes tables; bit2 selects the final RLE stage in Heavy modes.";
        break;
    case 0x6033003fU:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector address, not a file byte offset.";
        break;
    case 0x60330042U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector address, not a file byte offset.";
        break;
    case 0x60330044U:
        if(!xx_rt_wcscmp(r->name,L"size_word"))s=L"Producer-specific header word retained as bytes; not used by the native extent parser.";
        else if(!xx_rt_wcscmp(r->name,L"session_type"))s=L"0 CD-DA/CD-ROM; 0x10 CD-I; 0x20 CD-ROM XA.";
        break;
    case 0x60330045U:
        if(!xx_rt_wcscmp(r->name,L"track_bcd"))s=L"Packed binary-coded decimal track number.";
        else if(!xx_rt_wcscmp(r->name,L"index_bcd"))s=L"Packed binary-coded decimal index number.";
        else if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Signed logical sector address; pregap entries may be negative.";
        break;
    case 0x60330049U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 identifies a root extent; clear selects child/parent-name metadata.";
        else if(!xx_rt_wcscmp(r->name,L"capacity_sectors"))s=L"Logical sectors of 512 bytes each.";
        else if(!xx_rt_wcscmp(r->name,L"directory_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"next_free_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        break;
    case 0x6033004dU:
        if(!xx_rt_wcscmp(r->name,L"table_sector"))s=L"File-relative sector index; multiply by 512 for bytes. Zero means unallocated.";
        break;
    case 0x6033004eU:
        if(!xx_rt_wcscmp(r->name,L"grain_sector"))s=L"File-relative sector index; multiply by 512 for bytes. Zero means unallocated or supplied by a parent.";
        break;
    case 0x6033004fU:
        if(!xx_rt_wcscmp(r->name,L"volatile_header_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"volatile_header_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"journal_header_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"journal_header_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"journal_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"journal_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grain_directory_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grain_directory_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grain_tables_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grain_tables_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"free_bitmap_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"free_bitmap_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"back_map_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"back_map_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grains_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grains_sectors"))s=L"Number of 512-byte sectors.";
        break;
    case 0x60330051U:
        if(!xx_rt_wcscmp(r->name,L"table_index_and_flags"))s=L"Zero is unallocated; 0x10000000 in the high word identifies a low32-bit table index.";
        break;
    case 0x60330052U:
        if(!xx_rt_wcscmp(r->name,L"grain_index_and_type"))s=L"High nibble: 0 unallocated, 1 unmapped, 2 zero, 3 allocated; allocated index uses bits48..59 as low12 and bits0..47 as upper bits.";
        break;
    case 0x60330053U:
        if(!xx_rt_wcscmp(r->name,L"id_address_mark_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"head_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"sector_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"size_code_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        break;
    case 0x60330054U:
        if(!xx_rt_wcscmp(r->name,L"allocated_bits"))s=L"Physical bitmap byte; big-endian images reverse byte positions within cpu_bits-sized bitmap words.";
        break;
    case 0x60330055U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored checksum of a used-block group; exact wire bytes retained.";
        break;
    case 0x60330056U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored checksum of a used-block group; exact wire bytes retained.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Bounded wire metadata only. Optional damaged extents and display-budget
 * remainder stay raw. No native subclass casts or factory dependencies. */
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
bool sxsl_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxsl_read(sx_context*c,uint64_t p,void*b,size_t n){return sxsl_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxsl_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint16_t sxsl16(const uint8_t*b){return (uint16_t)sxsl_uint(b,2,false);}
uint32_t sxsl32(const uint8_t*b){return (uint32_t)sxsl_uint(b,4,false);}
bool sxsl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(n>8||!sxsl_read(c,p,b,n))return false;*v=sxsl_uint(b,n,be);return true;}
/* Keep metadata sorted as it is collected. Monotonic sector tables take
 * O(log n) overlap checks; out-of-order optional pointers insert in place. */
bool sxsl_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>SXSL_ROWS||n>(uint64_t)INT64_MAX/z||!sxsl_span(c,p,n*z))return false;
 if(xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXSL_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
bool sxsl_extadf(sx_context*c,bool old){uint64_t n;if(old)return SXSL_ADD(c,oldextadf_header,0)&&SXSL_TABLE(c,oldextadf_track,8,160);if(!SXSL_ADD(c,extadf_header,0)||!sxsl_word(c,10,2,true,&n))return false;return n<=340&&SXSL_TABLE(c,extadf_track,12,n);}
static int sxsl_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxsl_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsl_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsl_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_systemlater_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_LOFI:
case XX_FILE_TYPE_DMS:
case XX_FILE_TYPE_SAVEDSKF:
case XX_FILE_TYPE_DISKDUPE:
case XX_FILE_TYPE_PMDISKCOPY:
case XX_FILE_TYPE_QRST:
case XX_FILE_TYPE_HDCOPY:
case XX_FILE_TYPE_APRIDISK:
case XX_FILE_TYPE_DISKCOPY42:
case XX_FILE_TYPE_NRG:
case XX_FILE_TYPE_ISZ:
case XX_FILE_TYPE_MAME_FLOPPY_IMAGE_MFI:
case XX_FILE_TYPE_SDI:
case XX_FILE_TYPE_NHD:
case XX_FILE_TYPE_VIRTUAL98:
case XX_FILE_TYPE_ANEX86_HDI:
case XX_FILE_TYPE_THOMSON_SAP:
case XX_FILE_TYPE_DMK:
case XX_FILE_TYPE_AMIGA_EXT_ADF:
case XX_FILE_TYPE_AMIGA_OLD_EXT_ADF:
case XX_FILE_TYPE_SPECTRUM_UDI:
case XX_FILE_TYPE_MOOF:
case XX_FILE_TYPE_BOCHS_GROWING:
case XX_FILE_TYPE_VMDK_COWD_SPARSE:
case XX_FILE_TYPE_VMDK_SESPARSE:
case XX_FILE_TYPE_PARTCLONE_IMAGE:
return true;default:return false;}}
static bool sx_systemlater_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
if(c->f->file_type==XX_FILE_TYPE_LOFI)return sx_lofi_build(c);
if(c->f->file_type==XX_FILE_TYPE_DMS)return sx_dms_build(c);
if(c->f->file_type==XX_FILE_TYPE_SAVEDSKF)return sx_savedskf_build(c);
if(c->f->file_type==XX_FILE_TYPE_DISKDUPE)return sx_diskdupe_build(c);
if(c->f->file_type==XX_FILE_TYPE_PMDISKCOPY)return sx_pmdiskcopy_build(c);
if(c->f->file_type==XX_FILE_TYPE_QRST)return sx_qrst_build(c);
if(c->f->file_type==XX_FILE_TYPE_HDCOPY)return sx_hdcopy_build(c);
if(c->f->file_type==XX_FILE_TYPE_APRIDISK)return sx_apridisk_build(c);
if(c->f->file_type==XX_FILE_TYPE_DISKCOPY42)return sx_diskcopy42_build(c);
if(c->f->file_type==XX_FILE_TYPE_NRG)return sx_nrg_build(c);
if(c->f->file_type==XX_FILE_TYPE_ISZ)return sx_isz_build(c);
if(c->f->file_type==XX_FILE_TYPE_MAME_FLOPPY_IMAGE_MFI)return sx_mame_floppy_image_mfi_build(c);
if(c->f->file_type==XX_FILE_TYPE_SDI)return sx_sdi_build(c);
if(c->f->file_type==XX_FILE_TYPE_NHD)return sx_nhd_build(c);
if(c->f->file_type==XX_FILE_TYPE_VIRTUAL98)return sx_virtual98_build(c);
if(c->f->file_type==XX_FILE_TYPE_ANEX86_HDI)return sx_anex86_hdi_build(c);
if(c->f->file_type==XX_FILE_TYPE_THOMSON_SAP)return sx_thomson_sap_build(c);
if(c->f->file_type==XX_FILE_TYPE_DMK)return sx_dmk_build(c);
if(c->f->file_type==XX_FILE_TYPE_AMIGA_EXT_ADF)return sx_amiga_ext_adf_build(c);
if(c->f->file_type==XX_FILE_TYPE_AMIGA_OLD_EXT_ADF)return sx_amiga_old_ext_adf_build(c);
if(c->f->file_type==XX_FILE_TYPE_SPECTRUM_UDI)return sx_spectrum_udi_build(c);
if(c->f->file_type==XX_FILE_TYPE_MOOF)return sx_moof_build(c);
if(c->f->file_type==XX_FILE_TYPE_BOCHS_GROWING)return sx_bochs_growing_build(c);
if(c->f->file_type==XX_FILE_TYPE_VMDK_COWD_SPARSE)return sx_vmdk_cowd_sparse_build(c);
if(c->f->file_type==XX_FILE_TYPE_VMDK_SESPARSE)return sx_vmdk_sesparse_build(c);
if(c->f->file_type==XX_FILE_TYPE_PARTCLONE_IMAGE)return sx_partclone_image_build(c);
return false;}
const sx_family sx_systemlater_family={sx_systemlater_supports,sx_systemlater_build,sx_systemlater_layouts,SX_COUNT(sx_systemlater_layouts),sx_systemlater_comment};
