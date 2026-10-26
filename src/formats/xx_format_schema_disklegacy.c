/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disklegacy_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_disklegacy.h"
static const sx_layout *const sx_disklegacy_layouts[] = {
    &sxdleg_shrinkwrap_header,
    &sxdleg_jv3_sector_descriptor,
    &sxdleg_jv3_write_protection,
    &sxdleg_x68000_dim_header,
    &sxdleg_dart_header,
    &sxdleg_dart_block_length,
    &sxdleg_mds2_header,
    &sxdleg_mdx_header,
    &sxdleg_mdx_key_salt,
    &sxdleg_ldbs_header,
    &sxdleg_ldbs_block_header,
    &sxdleg_ldbs_directory_header,
    &sxdleg_ldbs_directory_entry,
    &sxdleg_ldbs_track_header,
    &sxdleg_ldbs_sector16,
    &sxdleg_ldbs_sector18,
    &sxdleg_ldbs_geometry,
    &sxdleg_atari_dim_header,
    &sxdleg_stt_header,
    &sxdleg_stt_track_entry,
    &sxdleg_stt_track_header,
    &sxdleg_stt_sector_section,
    &sxdleg_stt_sector_descriptor,
    &sxdleg_stt_raw_section,
    &sxdleg_stt_unknown_section,
    &sxdleg_stw_header,
    &sxdleg_stw_track_header,
    &sxdleg_discferret_header,
    &sxdleg_discferret_capture,
    &sxdleg_afi_header,
    &sxdleg_afi_info,
    &sxdleg_afi_string_offset,
    &sxdleg_afi_track_offset,
    &sxdleg_afi_data_offset,
    &sxdleg_afi_crc,
    &sxdleg_afi_string,
    &sxdleg_afi_track_list,
    &sxdleg_afi_track,
    &sxdleg_afi_data,
    &sxdleg_hxc_qd_header,
    &sxdleg_hxc_qd_track,
    &sxdleg_hxc_stream_chunk,
    &sxdleg_hxc_stream_metadata,
    &sxdleg_hxc_stream_io,
    &sxdleg_hxc_stream_flux,
    &sxdleg_hxc_stream_crc,
    &sxdleg_oric_sector_header,
    &sxdleg_oric_mfm_header,
    &sxdleg_gkh_header,
    &sxdleg_gkh_format_tag,
    &sxdleg_gkh_geometry_tag,
    &sxdleg_gkh_location_tag,
    &sxdleg_ede_text_header,
    &sxdleg_ede_bitmap_marker,
    &sxdleg_ede_bitmap_byte,
    &sxdleg_ede_format,
    &sxdleg_sad_header,
    &sxdleg_trackstar_track_header,
    &sxdleg_trackstar_track_size,
    &sxdleg_fatx_superblock,
    &sxdleg_fatx_fat16_entry,
    &sxdleg_fatx_fat32_entry,
    &sxdleg_fatx_directory_entry,
    &sxdleg_xdvdfs_volume_descriptor,
    &sxdleg_xdvdfs_directory_entry,
    &sxdleg_focusdrive_header,
    &sxdleg_focusdrive_partition,
    &sxdleg_focusdrive_name_header,
    &sxdleg_focusdrive_partition_name,
    &sxdleg_microdrive_header,
    &sxdleg_microdrive_start,
    &sxdleg_microdrive_size,
    &sxdleg_ldbs_track_directory_entry,
    &sxdleg_ldbs_track_block_header,
    &sxdleg_ldbs_sector_block_header,
};
typedef struct sxdleg_flag {uint64_t mask;const wchar_t*name;} sxdleg_flag;
static bool sxdleg_flags(xx_data_struct_record*r,uint64_t value,const sxdleg_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}
static bool sx_disklegacy_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60750000U||id>=0x60760000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x60750015U&&!xx_rt_wcscmp(r->name,L"data_flags")&&integer){static const sxdleg_flag bits[]={{1U,L"Sectors and ID fields"},{2U,L"Raw track data"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750013U&&!xx_rt_wcscmp(r->name,L"all_track_flags")&&integer){static const sxdleg_flag bits[]={{1U,L"Sectors and ID fields"},{2U,L"Raw track data"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6075000fU&&!xx_rt_wcscmp(r->name,L"status1")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing address mark"},{4U,L"No data"},{32U,L"Data error"},{128U,L"End of cylinder"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750010U&&!xx_rt_wcscmp(r->name,L"status1")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing address mark"},{4U,L"No data"},{32U,L"Data error"},{128U,L"End of cylinder"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6075000fU&&!xx_rt_wcscmp(r->name,L"status2")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing data address mark"},{32U,L"Data error"},{64U,L"Deleted data mark"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750010U&&!xx_rt_wcscmp(r->name,L"status2")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing data address mark"},{32U,L"Data error"},{64U,L"Deleted data mark"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750005U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Word RLE");
    case 1U:return xx_data_struct_record_set_comment(r,L"LZHUF");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored");
    default:break;}}
    if(id==0x60750005U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Macintosh");
    case 2U:return xx_data_struct_record_set_comment(r,L"Lisa");
    case 3U:return xx_data_struct_record_set_comment(r,L"Apple II");
    case 16U:return xx_data_struct_record_set_comment(r,L"Macintosh HD");
    case 17U:return xx_data_struct_record_set_comment(r,L"DOS 720K");
    case 18U:return xx_data_struct_record_set_comment(r,L"DOS 1440K");
    default:break;}}
    if(id==0x60750001U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"400 KiB GCR");
    case 1U:return xx_data_struct_record_set_comment(r,L"800 KiB GCR");
    case 2U:return xx_data_struct_record_set_comment(r,L"720 KiB MFM");
    case 3U:return xx_data_struct_record_set_comment(r,L"1440 KiB MFM");
    default:break;}}
    if(id==0x60750004U&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2HD (1024 x 8)");
    case 1U:return xx_data_struct_record_set_comment(r,L"2HS (1024 x 9)");
    case 2U:return xx_data_struct_record_set_comment(r,L"2HC (512 x 15)");
    case 3U:return xx_data_struct_record_set_comment(r,L"2HDE (1024 x 9)");
    case 9U:return xx_data_struct_record_set_comment(r,L"2HQ (512 x 18)");
    case 17U:return xx_data_struct_record_set_comment(r,L"N88-BASIC (256 x 26)");
    default:break;}}
    if(id==0x60750003U&&!xx_rt_wcscmp(r->name,L"write_protection")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Write-protected");
    case 255U:return xx_data_struct_record_set_comment(r,L"Writable; padding in subsequent headers");
    default:break;}}
    if(id==0x6075001fU&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"3.5-inch DD");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5-inch HD");
    case 3U:return xx_data_struct_record_set_comment(r,L"3.5-inch ED");
    case 4U:return xx_data_struct_record_set_comment(r,L"5.25-inch");
    case 5U:return xx_data_struct_record_set_comment(r,L"3-inch");
    default:break;}}
    if(id==0x6075001fU&&!xx_rt_wcscmp(r->name,L"platform_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Atari ST");
    case 2U:return xx_data_struct_record_set_comment(r,L"Amiga");
    case 3U:return xx_data_struct_record_set_comment(r,L"PC");
    case 4U:return xx_data_struct_record_set_comment(r,L"CPC");
    case 5U:return xx_data_struct_record_set_comment(r,L"MSX2");
    default:break;}}
    if(id==0x60750026U&&!xx_rt_wcscmp(r->name,L"encoding_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM");
    case 2U:return xx_data_struct_record_set_comment(r,L"PDC");
    case 3U:return xx_data_struct_record_set_comment(r,L"Cell array");
    default:break;}}
    if(id==0x60750027U&&!xx_rt_wcscmp(r->name,L"type_id")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM_DATA");
    case 2U:return xx_data_struct_record_set_comment(r,L"INDEX_DATA");
    case 3U:return xx_data_struct_record_set_comment(r,L"BITRATE_DATA");
    case 4U:return xx_data_struct_record_set_comment(r,L"PDC_DATA");
    case 5U:return xx_data_struct_record_set_comment(r,L"WEAKBITS_DATA");
    case 6U:return xx_data_struct_record_set_comment(r,L"CELL_DATA");
    default:break;}}
    if(id==0x60750027U&&!xx_rt_wcscmp(r->name,L"packer")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"zlib (historically called GZIP)");
    case 2U:return xx_data_struct_record_set_comment(r,L"Reserved RLE; opaque");
    case 3U:return xx_data_struct_record_set_comment(r,L"Reserved LZW; opaque");
    default:break;}}
    if(id==0x60750032U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"EPS Disk");
    default:break;}}
    if(id==0x60750032U&&!xx_rt_wcscmp(r->name,L"dump_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Uncompressed dump");
    default:break;}}
    if(id==0x60750034U&&!xx_rt_wcscmp(r->name,L"tag_type")&&integer){switch(value){
    case 11U:return xx_data_struct_record_set_comment(r,L"Image");
    case 20U:return xx_data_struct_record_set_comment(r,L"Author");
    case 21U:return xx_data_struct_record_set_comment(r,L"Subject");
    default:break;}}
    if(id==0x60750030U&&!xx_rt_wcscmp(r->name,L"geometry_order")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Side-major");
    case 2U:return xx_data_struct_record_set_comment(r,L"Cylinder-major");
    default:break;}}
    if(id==0x60750038U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"DD geometry (code 0)");
    case 1U:return xx_data_struct_record_set_comment(r,L"Single-sided mixed-size geometry");
    case 2U:return xx_data_struct_record_set_comment(r,L"Double-sided mixed-size geometry");
    case 3U:return xx_data_struct_record_set_comment(r,L"EPS DD");
    case 4U:return xx_data_struct_record_set_comment(r,L"DD geometry (code 4)");
    case 7U:return xx_data_struct_record_set_comment(r,L"TS DD");
    case 203U:return xx_data_struct_record_set_comment(r,L"ASR HD");
    case 204U:return xx_data_struct_record_set_comment(r,L"TS HD");
    default:break;}}
    if(id==0x6075000eU&&!xx_rt_wcscmp(r->name,L"data_rate")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Single/double density");
    case 2U:return xx_data_struct_record_set_comment(r,L"High density");
    case 3U:return xx_data_struct_record_set_comment(r,L"Extended density");
    default:break;}}
    if(id==0x6075000eU&&!xx_rt_wcscmp(r->name,L"recording_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"FM");
    case 2U:return xx_data_struct_record_set_comment(r,L"MFM");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"recording_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"MFM");
    case 1U:return xx_data_struct_record_set_comment(r,L"FM");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"data_rate")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"500 kbit/s");
    case 1U:return xx_data_struct_record_set_comment(r,L"300 kbit/s");
    case 2U:return xx_data_struct_record_set_comment(r,L"250 kbit/s");
    case 3U:return xx_data_struct_record_set_comment(r,L"1 Mbit/s");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"sidedness")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Alternating sides");
    case 1U:return xx_data_struct_record_set_comment(r,L"Out and back");
    case 2U:return xx_data_struct_record_set_comment(r,L"Out and out");
    case 3U:return xx_data_struct_record_set_comment(r,L"Extended surface");
    default:break;}}
    if(id==0x6075002bU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Metadata text");
    default:break;}}
    if(id==0x6075002cU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"LZ4 packed 16-bit IO");
    default:break;}}
    if(id==0x6075002dU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"LZ4 packed flux stream");
    default:break;}}
    switch(id){
    case 0x60750001U:
        if(!xx_rt_wcscmp(r->name,L"data_checksum"))s=L"Disk Copy rolling checksum of data words";
        else if(!xx_rt_wcscmp(r->name,L"tag_checksum"))s=L"Disk Copy rolling checksum, excluding the first 12 tag bytes";
        else if(!xx_rt_wcscmp(r->name,L"disk_format"))s=L"0=400 KiB, 1=800 KiB, 2=720 KiB, 3=1440 KiB";
        else if(!xx_rt_wcscmp(r->name,L"format_byte"))s=L"GCR/MFM format byte";
        else if(!xx_rt_wcscmp(r->name,L"private_word"))s=L"Private Disk Copy marker, normally 0x0100";
        break;
    case 0x60750002U:
        if(!xx_rt_wcscmp(r->name,L"cylinder"))s=L"0xFF with sector_id 0xFF denotes a free descriptor";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Density, DAM, side, error and size-code bits; free descriptors use a different size-code mapping";
        break;
    case 0x60750003U:
        if(!xx_rt_wcscmp(r->name,L"write_protection"))s=L"First header: 0x00 protected, 0xFF writable; later headers carry padding";
        break;
    case 0x60750004U:
        if(!xx_rt_wcscmp(r->name,L"track_present"))s=L"One byte per physical track; nonzero denotes stored track data";
        else if(!xx_rt_wcscmp(r->name,L"producer_metadata"))s=L"Unspecified producer date, time and comment area; preserved without invented subfields";
        break;
    case 0x60750005U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"0=word RLE, 1=LZHUF, 2=stored";
        else if(!xx_rt_wcscmp(r->name,L"disk_size_kib"))s=L"Logical disk capacity in 1024-byte units";
        break;
    case 0x60750006U:
        if(!xx_rt_wcscmp(r->name,L"encoded_length"))s=L"0=unused; 0xFFFF=stored 20960-byte block; otherwise words for RLE and bytes for LZHUF";
        break;
    case 0x60750007U:
        if(!xx_rt_wcscmp(r->name,L"key_header_offset"))s=L"File-relative offset of the encrypted 512-byte key header";
        break;
    case 0x60750008U:
        if(!xx_rt_wcscmp(r->name,L"mdx_marker"))s=L"0xFFFFFFFF selects the MDX physical envelope";
        else if(!xx_rt_wcscmp(r->name,L"descriptor_span"))s=L"Physical descriptor extent, including its 64-byte salt; encrypted payload remains raw";
        break;
    case 0x60750009U:
        if(!xx_rt_wcscmp(r->name,L"salt"))s=L"Physical key-derivation salt; subsequent key material is encrypted";
        break;
    case 0x6075000eU:
        if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"0=unknown, 1=SD/DD, 2=HD, 3=ED; unlike GEOM rate codes";
        else if(!xx_rt_wcscmp(r->name,L"recording_mode"))s=L"0=unknown, 1=FM, 2=MFM; native reader excludes GCR variants";
        else if(!xx_rt_wcscmp(r->name,L"gap3_length"))s=L"Controller format-gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"track_length"))s=L"Approximate controller track byte length; zero if unavailable";
        break;
    case 0x6075000fU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Approximate controller-track byte offset, not a file offset";
        break;
    case 0x60750010U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Approximate controller-track byte offset, not a file offset";
        else if(!xx_rt_wcscmp(r->name,L"data_size"))s=L"Zero selects the nominal 128<<size_code length";
        break;
    case 0x60750011U:
        if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"0=500 kbit/s, 1=300 kbit/s, 2=250 kbit/s, 3=1 Mbit/s";
        else if(!xx_rt_wcscmp(r->name,L"read_write_gap"))s=L"Controller gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"format_gap"))s=L"Controller gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"recording_mode"))s=L"0=MFM, 1=FM; unlike track-header mode codes";
        break;
    case 0x60750012U:
        if(!xx_rt_wcscmp(r->name,L"sector_size"))s=L"Zero selects the legacy 512-byte sector size";
        break;
    case 0x60750015U:
        if(!xx_rt_wcscmp(r->name,L"data_flags"))s=L"Bit0=sector descriptors and data, bit1=raw track data";
        break;
    case 0x60750016U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750017U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"address_crc"))s=L"Address-field CRC bytes in recorded order";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750018U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750019U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track; unsupported section body remains raw";
        break;
    case 0x6075001aU:
        if(!xx_rt_wcscmp(r->name,L"mfm_word_count"))s=L"Number of encoded 16-bit MFM words per track";
        break;
    case 0x6075001cU:
        if(!xx_rt_wcscmp(r->name,L"magic"))s=L"DFER=version1, DFE2=version2";
        break;
    case 0x6075001eU:
        if(!xx_rt_wcscmp(r->name,L"header_crc"))s=L"CRC16-CCITT stored big endian, unlike the surrounding header";
        break;
    case 0x60750020U:
        if(!xx_rt_wcscmp(r->name,L"string_offset"))s=L"Relative to the AFI_INFO block";
        break;
    case 0x60750021U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Relative to the TRACKLIST block";
        break;
    case 0x60750022U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the TRACK block";
        break;
    case 0x60750023U:
        if(!xx_rt_wcscmp(r->name,L"crc16"))s=L"CRC16-CCITT stored big endian";
        break;
    case 0x60750027U:
        if(!xx_rt_wcscmp(r->name,L"bits_per_element"))s=L"Encoded bit width, not bytes";
        else if(!xx_rt_wcscmp(r->name,L"packer"))s=L"0=stored, 1=zlib; reserved packers remain opaque";
        break;
    case 0x60750028U:
        if(!xx_rt_wcscmp(r->name,L"cell_rate"))s=L"Bit-cell rate in hertz";
        break;
    case 0x60750029U:
        if(!xx_rt_wcscmp(r->name,L"start_switch_offset"))s=L"Byte offset within this track data";
        else if(!xx_rt_wcscmp(r->name,L"stop_switch_offset"))s=L"Byte offset within this track data";
        break;
    case 0x6075002aU:
        if(!xx_rt_wcscmp(r->name,L"total_size"))s=L"Includes chunk header, block records and trailing CRC32";
        break;
    case 0x6075002bU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002cU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002dU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002eU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"Pauline stream CRC32";
        break;
    case 0x60750030U:
        if(!xx_rt_wcscmp(r->name,L"geometry_order"))s=L"1=side-major, 2=cylinder-major";
        break;
    case 0x60750031U:
        if(!xx_rt_wcscmp(r->name,L"number_type"))s=L"ASCII I selects Intel little-endian numbers";
        break;
    case 0x60750032U:
        if(!xx_rt_wcscmp(r->name,L"disk_format"))s=L"1=Ensoniq EPS disk";
        else if(!xx_rt_wcscmp(r->name,L"dump_type"))s=L"1=uncompressed data dump";
        break;
    case 0x60750034U:
        if(!xx_rt_wcscmp(r->name,L"tag_type"))s=L"11=image, 20=author text, 21=subject text";
        break;
    case 0x60750036U:
        if(!xx_rt_wcscmp(r->name,L"text_end"))s=L"CR LF and DOS end-of-text marker";
        break;
    case 0x60750037U:
        if(!xx_rt_wcscmp(r->name,L"sector_bitmap"))s=L"MSB-first: 0=stored sector, 1=implicit fill sector";
        break;
    case 0x60750038U:
        if(!xx_rt_wcscmp(r->name,L"computer_format"))s=L"Native reader supports zero only";
        break;
    case 0x60750039U:
        if(!xx_rt_wcscmp(r->name,L"sector_size_div64"))s=L"Physical sector byte size divided by 64";
        break;
    case 0x6075003aU:
        if(!xx_rt_wcscmp(r->name,L"halftrack_image"))s=L"Zero for 40-track, one for 80-half-track images";
        break;
    case 0x6075003bU:
        if(!xx_rt_wcscmp(r->name,L"stored_track_size"))s=L"Zero denotes failed analysis; data is stored in reverse byte order";
        break;
    case 0x6075003cU:
        if(!xx_rt_wcscmp(r->name,L"sectors_per_cluster"))s=L"Number of 512-byte sectors in a cluster";
        else if(!xx_rt_wcscmp(r->name,L"root_directory_cluster"))s=L"Cluster index, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_name"))s=L"UTF-16LE code units, zero-padded; ignored by the native volume reader";
        break;
    case 0x6075003dU:
        if(!xx_rt_wcscmp(r->name,L"next_cluster"))s=L"0=free; 0xFFFF=end of chain";
        break;
    case 0x6075003eU:
        if(!xx_rt_wcscmp(r->name,L"next_cluster"))s=L"0=free; 0xFFFFFFFF=end of chain";
        break;
    case 0x6075003fU:
        if(!xx_rt_wcscmp(r->name,L"first_cluster"))s=L"Cluster index, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"creation_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"access_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        break;
    case 0x60750040U:
        if(!xx_rt_wcscmp(r->name,L"root_directory_sector"))s=L"Logical sector index in 2048-byte units";
        else if(!xx_rt_wcscmp(r->name,L"creation_filetime"))s=L"Windows FILETIME: 100-nanosecond ticks since 1601-01-01 UTC";
        break;
    case 0x60750041U:
        if(!xx_rt_wcscmp(r->name,L"left_child_words"))s=L"Directory-relative byte offset divided by four; 0/0xFFFF means absent";
        else if(!xx_rt_wcscmp(r->name,L"right_child_words"))s=L"Directory-relative byte offset divided by four; 0/0xFFFF means absent";
        else if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"Logical sector index in 2048-byte units";
        break;
    case 0x60750042U:
        if(!xx_rt_wcscmp(r->name,L"opaque_identifier"))s=L"Unknown producer metadata, possibly a serial number";
        break;
    case 0x60750043U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Starting logical block in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Partition length in 512-byte blocks";
        else if(!xx_rt_wcscmp(r->name,L"opaque_metadata"))s=L"Native reader requires zero";
        break;
    case 0x60750044U:
        if(!xx_rt_wcscmp(r->name,L"unpartitioned_blocks"))s=L"Number of 512-byte blocks outside the partition map";
        break;
    case 0x60750047U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Starting logical block in 512-byte units";
        break;
    case 0x60750048U:
        if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Partition length in 512-byte blocks";
        else if(!xx_rt_wcscmp(r->name,L"drive_switch"))s=L"Drive-switch metadata for a two-drive configuration";
        break;
    case 0x60750049U:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII T denotes a track descriptor";
        break;
    case 0x6075004aU:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII T denotes a track descriptor";
        break;
    case 0x6075004bU:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII S denotes sector bytes";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed image base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXDLEG_LIMIT 24000U
bool sxdleg_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxdleg_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdleg_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxdleg16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxdleg32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdleg16(b,0)<<16|sxdleg16(b+2,0);return o==1?(uint32_t)sxdleg16(b,1)<<16|sxdleg16(b+2,1):(uint32_t)sxdleg16(b+2,0)<<16|sxdleg16(b,0);}
bool sxdleg_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxdleg_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXDLEG_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
static int sxdleg_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdleg_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdleg_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_disklegacy_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_SHRINKWRAP:
case XX_FILE_TYPE_TRS_80_JV3:
case XX_FILE_TYPE_X68000_DIM:
case XX_FILE_TYPE_DART:
case XX_FILE_TYPE_DAEMON_TOOLS_MDX:
case XX_FILE_TYPE_LDBS:
case XX_FILE_TYPE_ATARI_DIM:
case XX_FILE_TYPE_ATARI_STT:
case XX_FILE_TYPE_ATARI_STW:
case XX_FILE_TYPE_DISCFERRET_DFI:
case XX_FILE_TYPE_HXC_AFI:
case XX_FILE_TYPE_HXC_QD:
case XX_FILE_TYPE_HXC_STREAM:
case XX_FILE_TYPE_ORIC_DSK:
case XX_FILE_TYPE_ENSONIQ_GKH:
case XX_FILE_TYPE_ENSONIQ_EDE:
case XX_FILE_TYPE_SAMCOUPE_SAD:
case XX_FILE_TYPE_TRACKSTAR:
case XX_FILE_TYPE_FATX:
case XX_FILE_TYPE_XBOX_XDVDFS:
case XX_FILE_TYPE_FOCUSDRIVE:
case XX_FILE_TYPE_MICRODRIVE:
return true;default:return false;}}
static bool sx_disklegacy_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SHRINKWRAP:ok=sx_shrinkwrap_build(c);break;
case XX_FILE_TYPE_TRS_80_JV3:ok=sx_trs_80_jv3_build(c);break;
case XX_FILE_TYPE_X68000_DIM:ok=sx_x68000_dim_build(c);break;
case XX_FILE_TYPE_DART:ok=sx_dart_build(c);break;
case XX_FILE_TYPE_DAEMON_TOOLS_MDX:ok=sx_daemon_tools_mdx_build(c);break;
case XX_FILE_TYPE_LDBS:ok=sx_ldbs_build(c);break;
case XX_FILE_TYPE_ATARI_DIM:ok=sx_atari_dim_build(c);break;
case XX_FILE_TYPE_ATARI_STT:ok=sx_atari_stt_build(c);break;
case XX_FILE_TYPE_ATARI_STW:ok=sx_atari_stw_build(c);break;
case XX_FILE_TYPE_DISCFERRET_DFI:ok=sx_discferret_dfi_build(c);break;
case XX_FILE_TYPE_HXC_AFI:ok=sx_hxc_afi_build(c);break;
case XX_FILE_TYPE_HXC_QD:ok=sx_hxc_qd_build(c);break;
case XX_FILE_TYPE_HXC_STREAM:ok=sx_hxc_stream_build(c);break;
case XX_FILE_TYPE_ORIC_DSK:ok=sx_oric_dsk_build(c);break;
case XX_FILE_TYPE_ENSONIQ_GKH:ok=sx_ensoniq_gkh_build(c);break;
case XX_FILE_TYPE_ENSONIQ_EDE:ok=sx_ensoniq_ede_build(c);break;
case XX_FILE_TYPE_SAMCOUPE_SAD:ok=sx_samcoupe_sad_build(c);break;
case XX_FILE_TYPE_TRACKSTAR:ok=sx_trackstar_build(c);break;
case XX_FILE_TYPE_FATX:ok=sx_fatx_build(c);break;
case XX_FILE_TYPE_XBOX_XDVDFS:ok=sx_xbox_xdvdfs_build(c);break;
case XX_FILE_TYPE_FOCUSDRIVE:ok=sx_focusdrive_build(c);break;
case XX_FILE_TYPE_MICRODRIVE:ok=sx_microdrive_build(c);break;
default:return false;}return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxdleg_finish(c);}
#undef SXDLEG_LIMIT
const sx_family sx_disklegacy_family={sx_disklegacy_supports,sx_disklegacy_build,sx_disklegacy_layouts,SX_COUNT(sx_disklegacy_layouts),sx_disklegacy_comment};
