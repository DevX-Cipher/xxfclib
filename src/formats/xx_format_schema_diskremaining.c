/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_diskremaining_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_diskremaining.h"
static const sx_layout *const sx_diskremaining_layouts[] = {
    &sxdr_sydex_wb_header,
    &sxdr_sydex_image_header,
    &sxdr_sydex_track_header,
    &sxdr_trs80_boot_directory,
    &sxdr_trs80_gat_track,
    &sxdr_trs80_gat_identity,
    &sxdr_trs80_hit,
    &sxdr_trs80_primary_entry,
    &sxdr_trs80_extended_entry,
    &sxdr_trs80_extent,
    &sxdr_trs80_extent_link,
    &sxdr_savage_header,
    &sxdr_vtr_header,
    &sxdr_vtr_track_entry,
    &sxdr_pc99_id_fm,
    &sxdr_pc99_id_mfm,
    &sxdr_pc99_data_fm,
    &sxdr_pc99_data_mfm,
    &sxdr_pc99_data_crc,
    &sxdr_apple_gcr_address,
    &sxdr_apple_gcr_data_prefix,
    &sxdr_apple_gcr_data_suffix,
    &sxdr_gutenberg_link,
    &sxdr_gutenberg_volume,
    &sxdr_gutenberg_entry,
    &sxdr_cassette_riff,
    &sxdr_cassette_chunk,
    &sxdr_cassette_pcm_format,
    &sxdr_xbox_fatx_header_le,
    &sxdr_xbox_fatx_header_be,
    &sxdr_plist_tag,
    &sxdr_plist_key,
    &sxdr_plist_string,
    &sxdr_plist_integer,
    &sxdr_plist_disk_size,
    &sxdr_plist_band_size,
    &sxdr_plist_bundle_version,
    &sxdr_trs80_gat_lockout,
    &sxdr_trs80_gat_system,
    &sxdr_sydex_description,
    &sxdr_fei_id_phase0,
    &sxdr_fei_id_phase1,
    &sxdr_fei_id_phase2,
    &sxdr_fei_id_phase3,
    &sxdr_fei_id_phase4,
    &sxdr_fei_id_phase5,
    &sxdr_fei_id_phase6,
    &sxdr_fei_id_phase7,
    &sxdr_ddd_initial_dictionary,
    &sxdr_speccydos_boot_header,
    &sxdr_cassette_pcm_extension,
    &sxdr_xbox_fatx_name_le,
};
static bool sx_diskremaining_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x607f0000U||id>=0x60800000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x607f0001U:
        if(!xx_rt_wcscmp(r->name,L"last_page_bytes"))s=L"Bytes used in the final512-byte page; zero denotes a full page";
        else if(!xx_rt_wcscmp(r->name,L"page_count"))s=L"512-byte pages; the size includes this stage header";
        break;
    case 0x607f0002U:
        if(!xx_rt_wcscmp(r->name,L"encryption"))s=L"Native reader requires zero; nonzero denotes encrypted image";
        else if(!xx_rt_wcscmp(r->name,L"description_bytes"))s=L"Nonnegative byte length immediately after the header";
        else if(!xx_rt_wcscmp(r->name,L"description_crc16"))s=L"CRC16/ARC of description; native reader does not require it";
        else if(!xx_rt_wcscmp(r->name,L"serial_marker"))s=L"SNUM marker in known producers";
        else if(!xx_rt_wcscmp(r->name,L"header_crc16"))s=L"CRC16/ARC over the first31 header bytes";
        break;
    case 0x607f0003U:
        if(!xx_rt_wcscmp(r->name,L"decoded_crc16"))s=L"CRC16/ARC of the reconstructed track";
        else if(!xx_rt_wcscmp(r->name,L"signed_packed_length"))s=L"Positive LZHUF byte length; negative magnitude is RLE byte length";
        break;
    case 0x607f0004U:
        if(!xx_rt_wcscmp(r->name,L"directory_track_flags"))s=L"Low7bits identify the directory track; highbit is preserved";
        break;
    case 0x607f0005U:
        if(!xx_rt_wcscmp(r->name,L"allocated_granules"))s=L"Model I: low two bits represent the two five-sector granules in this track";
        break;
    case 0x607f0006U:
        if(!xx_rt_wcscmp(r->name,L"date_text"))s=L"Stored calendar text, not an integer timestamp";
        else if(!xx_rt_wcscmp(r->name,L"auto_command"))s=L"Physical command bytes; NUL or carriage-return terminates the meaningful text";
        break;
    case 0x607f0007U:
        if(!xx_rt_wcscmp(r->name,L"filename_hash"))s=L"TRSDOS rotate/XOR filename hash; zero marks an unused directory-entry code";
        break;
    case 0x607f0008U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"bit7 extended,bit6 system,bit5 limits/PDS,bit4 active,bit3 invisible,low3 protection";
        else if(!xx_rt_wcscmp(r->name,L"month_flags"))s=L"Low4bits month; remaining bits stored flags";
        else if(!xx_rt_wcscmp(r->name,L"day_year_flags"))s=L"High5bits day; low3bits year relative to1980";
        else if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"Zero means full256-byte sector";
        else if(!xx_rt_wcscmp(r->name,L"logical_record_length"))s=L"Zero means256-byte record";
        break;
    case 0x607f0009U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"bit7 extended,bit6 system,bit5 limits/PDS,bit4 active,bit3 invisible,low3 protection";
        else if(!xx_rt_wcscmp(r->name,L"previous_entry_code"))s=L"Previous directory-entry code, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"day_year_flags"))s=L"High5bits day; low3bits year relative to1980";
        else if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"Zero means full256-byte sector";
        else if(!xx_rt_wcscmp(r->name,L"logical_record_length"))s=L"Zero means256-byte record";
        break;
    case 0x607f000aU:
        if(!xx_rt_wcscmp(r->name,L"granule_start_count"))s=L"High3bits first granule; low5bits granule count minus one";
        break;
    case 0x607f000bU:
        if(!xx_rt_wcscmp(r->name,L"marker"))s=L"FE marks an extended-directory link";
        else if(!xx_rt_wcscmp(r->name,L"next_entry_code"))s=L"Directory-entry code, not a byte offset";
        break;
    case 0x607f000cU:
        if(!xx_rt_wcscmp(r->name,L"header_size_minus_two"))s=L"Native variant stores29 for a31-byte physical header";
        else if(!xx_rt_wcscmp(r->name,L"unknown_01"))s=L"Not interpreted by the native Savage reader";
        else if(!xx_rt_wcscmp(r->name,L"unknown_0f"))s=L"Native Savage grammar does not interpret these stored bytes";
        else if(!xx_rt_wcscmp(r->name,L"disk_crc16"))s=L"CRC16 of the decoded901120-byte disk";
        break;
    case 0x607f000dU:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"bitrate_kbps"))s=L"Kilobits per second";
        else if(!xx_rt_wcscmp(r->name,L"track_list_block"))s=L"512-byte block number, not an unscaled byte offset";
        break;
    case 0x607f000eU:
        if(!xx_rt_wcscmp(r->name,L"track_block"))s=L"512-byte block number";
        else if(!xx_rt_wcscmp(r->name,L"combined_track_bytes"))s=L"Combined storage for both interleaved sides";
        break;
    case 0x607f000fU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size128<<code; native requires1";
        else if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0010U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size128<<code; native requires1";
        else if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0011U:
        if(!xx_rt_wcscmp(r->name,L"data_mark"))s=L"FB normal or F8 deleted data";
        break;
    case 0x607f0012U:
        if(!xx_rt_wcscmp(r->name,L"data_mark"))s=L"FB normal or F8 deleted data";
        break;
    case 0x607f0013U:
        if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0014U:
        if(!xx_rt_wcscmp(r->name,L"prologue"))s=L"D5AA96 for16sector or D5AAB5 for13sector address framing";
        else if(!xx_rt_wcscmp(r->name,L"volume_4and4"))s=L"Original4-and-4 encoded8-bit volume; decoded=(first<<1|1)&second";
        else if(!xx_rt_wcscmp(r->name,L"track_4and4"))s=L"Original4-and-4 encoded8-bit track";
        else if(!xx_rt_wcscmp(r->name,L"sector_4and4"))s=L"Original4-and-4 encoded8-bit sector";
        else if(!xx_rt_wcscmp(r->name,L"xor_checksum_4and4"))s=L"Original4-and-4 encoding of volume XOR track XOR sector";
        else if(!xx_rt_wcscmp(r->name,L"epilogue"))s=L"Standard DEAAEB epilogue; native authenticates the significant prefix";
        break;
    case 0x607f0015U:
        if(!xx_rt_wcscmp(r->name,L"prologue"))s=L"D5AAAD data framing";
        break;
    case 0x607f0016U:
        if(!xx_rt_wcscmp(r->name,L"translated_xor_checksum"))s=L"Original translated GCR checksum code, not a decoded sample";
        break;
    case 0x607f0017U:
        if(!xx_rt_wcscmp(r->name,L"current_sector_flags"))s=L"bit7 marks first sector;40hex encodes zero in low7bits";
        else if(!xx_rt_wcscmp(r->name,L"next_track_flags"))s=L"bit7 marks end of chain and points back to its firstsector";
        break;
    case 0x607f0018U:
        if(!xx_rt_wcscmp(r->name,L"volume_name_high_ascii"))s=L"High-bit Apple text; trailing spaces padded";
        else if(!xx_rt_wcscmp(r->name,L"carriage_return"))s=L"8Dhex";
        break;
    case 0x607f0019U:
        if(!xx_rt_wcscmp(r->name,L"first_track_flags"))s=L"Low7bits track;40hex encodes zero";
        else if(!xx_rt_wcscmp(r->name,L"first_sector_flags"))s=L"Low7bits sector;40hex encodes zero";
        else if(!xx_rt_wcscmp(r->name,L"type_high_ascii"))s=L"Low7bits space/L/M/P";
        else if(!xx_rt_wcscmp(r->name,L"carriage_return"))s=L"8Dhex";
        break;
    case 0x607f001aU:
        if(!xx_rt_wcscmp(r->name,L"riff_bytes"))s=L"Size excluding the first8 bytes";
        break;
    case 0x607f001bU:
        if(!xx_rt_wcscmp(r->name,L"data_bytes"))s=L"Payload size excluding8-byte header and alignment byte";
        break;
    case 0x607f001cU:
        if(!xx_rt_wcscmp(r->name,L"sample_rate"))s=L"Samples per second";
        else if(!xx_rt_wcscmp(r->name,L"byte_rate"))s=L"Bytes per second";
        break;
    case 0x607f001dU:
        if(!xx_rt_wcscmp(r->name,L"root_cluster"))s=L"Cluster index";
        break;
    case 0x607f001eU:
        if(!xx_rt_wcscmp(r->name,L"root_cluster"))s=L"Cluster index";
        break;
    case 0x607f001fU:
        if(!xx_rt_wcscmp(r->name,L"tag"))s=L"Physical XML tag spelling";
        break;
    case 0x607f0020U:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Physical property-list key; entity spelling retained";
        break;
    case 0x607f0021U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Physical string token";
        break;
    case 0x607f0022U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Decimal integer token";
        break;
    case 0x607f0023U:
        if(!xx_rt_wcscmp(r->name,L"disk_size"))s=L"Virtual disk byte length";
        break;
    case 0x607f0024U:
        if(!xx_rt_wcscmp(r->name,L"band_size"))s=L"Bytes per external band file";
        break;
    case 0x607f0025U:
        if(!xx_rt_wcscmp(r->name,L"bundle_version"))s=L"Native supports versions1 and2; the version key may be absent";
        break;
    case 0x607f0026U:
        if(!xx_rt_wcscmp(r->name,L"lockout_flags"))s=L"FF lockedout,FC available in native Model I scope";
        break;
    case 0x607f0027U:
        if(!xx_rt_wcscmp(r->name,L"cylinders_minus_35"))s=L"LDOS interpretation; native geometry is separately validated";
        else if(!xx_rt_wcscmp(r->name,L"geometry_flags"))s=L"LDOS low3bits granules-per-track minus1,bit5 sides,bit6 density";
        break;
    case 0x607f0028U:
        if(!xx_rt_wcscmp(r->name,L"description"))s=L"Physical description bytes; no decompression";
        break;
    case 0x607f0029U:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit0";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002aU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit1";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002bU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit2";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002cU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit3";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002dU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit4";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002eU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit5";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002fU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit6";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f0030U:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit7";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f0031U:
        if(!xx_rt_wcscmp(r->name,L"dos_lead"))s=L"Original DOS load-address/length prefix or DDD Pro marker; no synthesized semantics";
        else if(!xx_rt_wcscmp(r->name,L"reserved_prefix"))s=L"Three zero bits";
        else if(!xx_rt_wcscmp(r->name,L"volume_reversed_bits"))s=L"Stored MSB-positioned bit sequence; reverse these8bits for decoded volume";
        else if(!xx_rt_wcscmp(r->name,L"favorite_0_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_1_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_2_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_3_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_4_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_5_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_6_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_7_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_8_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_9_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_10_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_11_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_12_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_13_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_14_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_15_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_16_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_17_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_18_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_19_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        break;
    case 0x607f0032U:
        if(!xx_rt_wcscmp(r->name,L"density"))s=L"0 MFM at250kbit/s;1 FM at125kbit/s";
        else if(!xx_rt_wcscmp(r->name,L"cylinders_and_sides"))s=L"Low7bits cylinders;highbit selects two sides";
        break;
    case 0x607f0033U:
        if(!xx_rt_wcscmp(r->name,L"extension_bytes"))s=L"Native PCM variant requires zero";
        break;
    case 0x607f0034U:
        if(!xx_rt_wcscmp(r->name,L"partition_name_utf16"))s=L"Original Xbox optional UTF16LE partition name; Xbox360 does not use this header field";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXDR_LIMIT 24000U
bool sxdr_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxdr_read(sx_context*c,uint64_t p,void*b,size_t n){return sxdr_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxdr16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
uint32_t sxdr32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
bool sxdr_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxdr_span(c,p,count*z))return false;if(!count||c->count>=SXDR_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
bool sxdr_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxdr_span(c,p,n))return false;if(!n||n>16384||c->count>=SXDR_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxdr_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxdr_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdr_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdr_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
uint16_t sxdr_ccitt(const uint8_t*b,size_t n){uint16_t v=0xffffU;for(size_t i=0;i<n;i++){v^=(uint16_t)b[i]<<8;for(unsigned j=0;j<8;j++)v=(uint16_t)((v<<1)^((v&0x8000U)?0x1021U:0));}return v;}
static bool sx_diskremaining_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_SFX_SYDEX_DISKETTE_IMAGE:case XX_FILE_TYPE_APPLE_SPARSE_BUNDLE:case XX_FILE_TYPE_TRS_80_JV1:case XX_FILE_TYPE_DDD:case XX_FILE_TYPE_FEI:case XX_FILE_TYPE_APPLE_NIB:case XX_FILE_TYPE_TI99_PC99:case XX_FILE_TYPE_VTR_DISK:case XX_FILE_TYPE_SPECCYDOS_SDD:case XX_FILE_TYPE_SAVAGE:case XX_FILE_TYPE_GUTENBERG:case XX_FILE_TYPE_APPLE_CASSETTE:case XX_FILE_TYPE_XBOX360_LAYOUT:return true;default:return false;}}
static bool sx_diskremaining_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SFX_SYDEX_DISKETTE_IMAGE:ok=sx_sfx_sydex_diskette_image_build(c);break;
case XX_FILE_TYPE_APPLE_SPARSE_BUNDLE:ok=sx_apple_sparse_bundle_build(c);break;
case XX_FILE_TYPE_TRS_80_JV1:ok=sx_trs_80_jv1_build(c);break;
case XX_FILE_TYPE_DDD:ok=sx_ddd_build(c);break;
case XX_FILE_TYPE_FEI:ok=sx_fei_build(c);break;
case XX_FILE_TYPE_APPLE_NIB:ok=sx_apple_nib_build(c);break;
case XX_FILE_TYPE_TI99_PC99:ok=sx_ti99_pc99_build(c);break;
case XX_FILE_TYPE_VTR_DISK:ok=sx_vtr_disk_build(c);break;
case XX_FILE_TYPE_SPECCYDOS_SDD:ok=sx_speccydos_sdd_build(c);break;
case XX_FILE_TYPE_SAVAGE:ok=sx_savage_build(c);break;
case XX_FILE_TYPE_GUTENBERG:ok=sx_gutenberg_build(c);break;
case XX_FILE_TYPE_APPLE_CASSETTE:ok=sx_apple_cassette_build(c);break;
case XX_FILE_TYPE_XBOX360_LAYOUT:ok=sx_xbox360_layout_build(c);break;
default:return false;}
return ok&&c->count&&sxdr_finish(c);}
#undef SXDR_LIMIT
const sx_family sx_diskremaining_family={sx_diskremaining_supports,sx_diskremaining_build,sx_diskremaining_layouts,SX_COUNT(sx_diskremaining_layouts),sx_diskremaining_comment};
