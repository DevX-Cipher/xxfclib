/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-volume and forensic-image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_volumeimages_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_volumeimages.h"
static const xx_data_struct_field_desc sxvi_ewf1_file_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("fields_start","uint8",8,1,SX_SIGNATURE),
    SX_FIELD("segment_number","uint16",9,2,SX_ID),
    SX_FIELD("fields_end","uint16",11,2,SX_RESERVED),
};
static const sx_layout sxvi_ewf1_file_header = {0x60530007U,"ewf1_file_header",sxvi_ewf1_file_header_fields,SX_COUNT(sxvi_ewf1_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_section_descriptor_fields[] = {
    SX_FIELD("type","char[16]",0,16,SX_STRING),
    SX_FIELD("next_descriptor_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("section_size","uint64",24,8,SX_SIZE),
    SX_FIELD("padding","byte[40]",32,40,SX_RESERVED),
    SX_FIELD("adler32","uint32",72,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_section_descriptor = {0x60530008U,"ewf1_section_descriptor",sxvi_ewf1_section_descriptor_fields,SX_COUNT(sxvi_ewf1_section_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_volume_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("media_flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("unknown1","byte[3]",37,3,SX_NONE),
    SX_FIELD("palm_start_sector","uint32",40,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",44,4,SX_NONE),
    SX_FIELD("smart_logs_distance","uint32",48,4,SX_NONE),
    SX_FIELD("compression_level","uint8",52,1,SX_ID),
    SX_FIELD("unknown3","byte[3]",53,3,SX_NONE),
    SX_FIELD("error_granularity","uint32",56,4,SX_NONE),
    SX_FIELD("unknown4","byte[4]",60,4,SX_NONE),
    SX_FIELD("segment_set_identifier","byte[16]",64,16,SX_ID),
    SX_FIELD("unknown5","byte[963]",80,963,SX_NONE),
    SX_FIELD("reserved_signature","byte[5]",1043,5,SX_NONE),
    SX_FIELD("adler32","uint32",1048,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_volume = {0x60530009U,"ewf1_volume",sxvi_ewf1_volume_fields,SX_COUNT(sxvi_ewf1_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_logical_volume_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("logical_sector_value","uint64",16,8,SX_NONE),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("media_flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("unknown1","byte[3]",37,3,SX_NONE),
    SX_FIELD("palm_start_sector","uint32",40,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",44,4,SX_NONE),
    SX_FIELD("smart_logs_distance","uint32",48,4,SX_NONE),
    SX_FIELD("compression_level","uint8",52,1,SX_ID),
    SX_FIELD("unknown3","byte[3]",53,3,SX_NONE),
    SX_FIELD("error_granularity","uint32",56,4,SX_NONE),
    SX_FIELD("unknown4","byte[4]",60,4,SX_NONE),
    SX_FIELD("segment_set_identifier","byte[16]",64,16,SX_ID),
    SX_FIELD("unknown5","byte[963]",80,963,SX_NONE),
    SX_FIELD("reserved_signature","byte[5]",1043,5,SX_NONE),
    SX_FIELD("adler32","uint32",1048,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_logical_volume = {0x6053000aU,"ewf1_logical_volume",sxvi_ewf1_logical_volume_fields,SX_COUNT(sxvi_ewf1_logical_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_smart_volume_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[20]",20,20,SX_RESERVED),
    SX_FIELD("padding","byte[45]",40,45,SX_RESERVED),
    SX_FIELD("signature","char[5]",85,5,SX_SIGNATURE),
    SX_FIELD("adler32","uint32",90,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_smart_volume = {0x6053000bU,"ewf1_smart_volume",sxvi_ewf1_smart_volume_fields,SX_COUNT(sxvi_ewf1_smart_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_table_header_fields[] = {
    SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","byte[4]",4,4,SX_RESERVED),
    SX_FIELD("base_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("padding1","byte[4]",16,4,SX_RESERVED),
    SX_FIELD("adler32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_table_header = {0x6053000cU,"ewf1_table_header",sxvi_ewf1_table_header_fields,SX_COUNT(sxvi_ewf1_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_chunk_entry_fields[] = {
    SX_FIELD("offset_and_compression","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf1_chunk_entry = {0x6053000dU,"ewf1_chunk_entry",sxvi_ewf1_chunk_entry_fields,SX_COUNT(sxvi_ewf1_chunk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_image_adler32_fields[] = {
    SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxvi_image_adler32 = {0x6053000eU,"image_adler32",sxvi_image_adler32_fields,SX_COUNT(sxvi_image_adler32_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_hash_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("unknown","byte[16]",16,16,SX_NONE),
    SX_FIELD("adler32","uint32",32,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_hash = {0x6053000fU,"ewf1_hash",sxvi_ewf1_hash_fields,SX_COUNT(sxvi_ewf1_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_digest_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("sha1","byte[20]",16,20,SX_CHECKSUM),
    SX_FIELD("padding","byte[40]",36,40,SX_RESERVED),
    SX_FIELD("adler32","uint32",76,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_digest = {0x60530010U,"ewf1_digest",sxvi_ewf1_digest_fields,SX_COUNT(sxvi_ewf1_digest_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf1_ltree_header_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("data_size","uint64",16,8,SX_SIZE),
    SX_FIELD("adler32","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("unknown","byte[20]",28,20,SX_NONE),
};
static const sx_layout sxvi_ewf1_ltree_header = {0x60530011U,"ewf1_ltree_header",sxvi_ewf1_ltree_header_fields,SX_COUNT(sxvi_ewf1_ltree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_file_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("compression_method","uint16",10,2,SX_ID),
    SX_FIELD("segment_number","uint32",12,4,SX_ID),
    SX_FIELD("set_identifier","byte[16]",16,16,SX_ID),
};
static const sx_layout sxvi_ewf2_file_header = {0x60530012U,"ewf2_file_header",sxvi_ewf2_file_header_fields,SX_COUNT(sxvi_ewf2_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_section_descriptor_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("previous_descriptor_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",16,8,SX_SIZE),
    SX_FIELD("descriptor_size","uint32",24,4,SX_SIZE),
    SX_FIELD("padding_size","uint32",28,4,SX_SIZE),
    SX_FIELD("data_md5","byte[16]",32,16,SX_CHECKSUM),
    SX_FIELD("reserved","byte[12]",48,12,SX_RESERVED),
    SX_FIELD("adler32","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_section_descriptor = {0x60530013U,"ewf2_section_descriptor",sxvi_ewf2_section_descriptor_fields,SX_COUNT(sxvi_ewf2_section_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_table_header_fields[] = {
    SX_FIELD("first_chunk_number","uint64",0,8,SX_NONE),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("padding","byte[12]",20,12,SX_RESERVED),
};
static const sx_layout sxvi_ewf2_table_header = {0x60530014U,"ewf2_table_header",sxvi_ewf2_table_header_fields,SX_COUNT(sxvi_ewf2_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_chunk_entry_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf2_chunk_entry = {0x60530015U,"ewf2_chunk_entry",sxvi_ewf2_chunk_entry_fields,SX_COUNT(sxvi_ewf2_chunk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_pattern_entry_fields[] = {
    SX_FIELD("fill_pattern","byte[8]",0,8,SX_NONE),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf2_pattern_entry = {0x60530016U,"ewf2_pattern_entry",sxvi_ewf2_pattern_entry_fields,SX_COUNT(sxvi_ewf2_pattern_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_md5_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_md5 = {0x60530017U,"ewf2_md5",sxvi_ewf2_md5_fields,SX_COUNT(sxvi_ewf2_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_ewf2_sha1_fields[] = {
    SX_FIELD("sha1","byte[20]",0,20,SX_CHECKSUM),
    SX_FIELD("adler32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_sha1 = {0x60530018U,"ewf2_sha1",sxvi_ewf2_sha1_fields,SX_COUNT(sxvi_ewf2_sha1_fields),SX_LE};
static const sx_layout *const sx_volumeimages_layouts[] = {
    &sxvi_lvm2_label_header,
    &sxvi_lvm2_pv_header,
    &sxvi_lvm2_disk_location,
    &sxvi_lvm2_pv_extension,
    &sxvi_lvm2_mda_header,
    &sxvi_lvm2_raw_location,
    &sxvi_ewf1_file_header,
    &sxvi_ewf1_section_descriptor,
    &sxvi_ewf1_volume,
    &sxvi_ewf1_logical_volume,
    &sxvi_ewf1_smart_volume,
    &sxvi_ewf1_table_header,
    &sxvi_ewf1_chunk_entry,
    &sxvi_image_adler32,
    &sxvi_ewf1_hash,
    &sxvi_ewf1_digest,
    &sxvi_ewf1_ltree_header,
    &sxvi_ewf2_file_header,
    &sxvi_ewf2_section_descriptor,
    &sxvi_ewf2_table_header,
    &sxvi_ewf2_chunk_entry,
    &sxvi_ewf2_pattern_entry,
    &sxvi_ewf2_md5,
    &sxvi_ewf2_sha1,
    &sxvi_uif_trailer,
    &sxvi_uif_table_header,
    &sxvi_uif_block_entry,
    &sxvi_uif_descriptor_header,
    &sxvi_uif_output_format,
    &sxvi_gbi_header100,
    &sxvi_gbi_header110,
    &sxvi_gbi_descriptor,
    &sxvi_gbi_part_count,
    &sxvi_zisofs_header,
    &sxvi_zisofs_block_pointer,
    &sxvi_btrfs_send_header,
    &sxvi_btrfs_send_command,
    &sxvi_btrfs_send_attribute,
    &sxvi_btrfs_send_data_attribute_v2,
    &sxvi_btrfs_send_uuid,
    &sxvi_btrfs_send_id64,
    &sxvi_btrfs_send_size64,
    &sxvi_btrfs_send_offset64,
    &sxvi_btrfs_send_flags64,
    &sxvi_btrfs_send_flags32,
    &sxvi_btrfs_send_codec32,
    &sxvi_btrfs_send_timespec,
    &sxvi_aaru2_header,
    &sxvi_aaru2_ddt_header,
    &sxvi_aaru2_ddt_entry,
    &sxvi_aaru_index3,
    &sxvi_aaru_index_entry,
    &sxvi_aaru_data_header,
    &sxvi_aff_segment_header,
    &sxvi_aff_segment_footer,
    &sxvi_aff_quadword,
    &sxvi_bsd_disklabel_le,
    &sxvi_bsd_disklabel_be,
    &sxvi_bsd_partition_le,
    &sxvi_bsd_partition_be,
    &sxvi_md1_superblock,
    &sxvi_md1_superblock_ppl,
    &sxvi_md1_device_role,
    &sxvi_md090_header_le,
    &sxvi_md090_header_be,
    &sxvi_md090_disk_le,
    &sxvi_md090_disk_be,
    &sxvi_sun_sparc_label,
    &sxvi_sun_x86_label,
    &sxvi_nextstep_container_header,
    &sxvi_mds_header,
    &sxvi_mds_session,
    &sxvi_mds_track,
    &sxvi_mds_track_extra,
    &sxvi_mds_footer,
    &sxvi_ldm_private_header,
    &sxvi_ldm_tocblock,
    &sxvi_ldm_vmdb_header,
    &sxvi_ldm_vblk_fragment,
    &sxvi_ldm_vblk_record_header,
    &sxvi_ldm_variable_length,
    &sxvi_hsf_volume_prefix,
    &sxvi_hsf_descriptor_header,
    &sxvi_hsf_directory_record,
    &sxvi_hsf_volume_identifiers,
    &sxvi_cdi_footer_v2,
    &sxvi_cdi_footer_v35,
    &sxvi_cdi_descriptor_header,
    &sxvi_cdi_track_prefix,
    &sxvi_cdi_index_count,
    &sxvi_cdi_index,
    &sxvi_cdi_cdtext_count,
    &sxvi_cdi_track_geometry,
    &sxvi_partimage_volume_header,
    &sxvi_partimage_main_header,
    &sxvi_partimage_local_header,
    &sxvi_partimage_header_checksum,
    &sxvi_partimage_extension_header,
    &sxvi_partimage_data_check,
    &sxvi_partimage_tail,
};
typedef struct sxvi_flag {uint64_t mask;const wchar_t*name;} sxvi_flag;
static bool sxvi_flags(xx_data_struct_record*r,uint64_t value,const sxvi_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}
static bool sx_volumeimages_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60530000U||id>=0x60540000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){static const sxvi_flag bits[]={{1U,L"MD_FEATURE_BITMAP_OFFSET"},{2U,L"MD_FEATURE_RECOVERY_OFFSET"},{4U,L"MD_FEATURE_RESHAPE_ACTIVE"},{8U,L"MD_FEATURE_BAD_BLOCKS"},{16U,L"MD_FEATURE_REPLACEMENT"},{32U,L"MD_FEATURE_RESHAPE_BACKWARDS"},{64U,L"MD_FEATURE_NEW_OFFSET"},{128U,L"MD_FEATURE_RECOVERY_BITMAP"},{256U,L"MD_FEATURE_CLUSTERED"},{512U,L"MD_FEATURE_JOURNAL"},{1024U,L"MD_FEATURE_PPL"},{2048U,L"MD_FEATURE_MULTIPLE_PPLS"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){static const sxvi_flag bits[]={{1U,L"MD_FEATURE_BITMAP_OFFSET"},{2U,L"MD_FEATURE_RECOVERY_OFFSET"},{4U,L"MD_FEATURE_RESHAPE_ACTIVE"},{8U,L"MD_FEATURE_BAD_BLOCKS"},{16U,L"MD_FEATURE_REPLACEMENT"},{32U,L"MD_FEATURE_RESHAPE_BACKWARDS"},{64U,L"MD_FEATURE_NEW_OFFSET"},{128U,L"MD_FEATURE_RECOVERY_BITMAP"},{256U,L"MD_FEATURE_CLUSTERED"},{512U,L"MD_FEATURE_JOURNAL"},{1024U,L"MD_FEATURE_PPL"},{2048U,L"MD_FEATURE_MULTIPLE_PPLS"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"Has data integrity hash"},{2U,L"Encrypted"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530004U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"PV_EXT_USED"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530006U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"RAW_LOCN_IGNORED"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530015U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"COMPRESSED"},{2U,L"CHECKSUMMED"},{4U,L"PATTERNFILL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530016U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"COMPRESSED"},{2U,L"CHECKSUMMED"},{4U,L"PATTERNFILL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530042U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_DISK_FAULTY"},{2U,L"MD_DISK_ACTIVE"},{4U,L"MD_DISK_SYNC"},{8U,L"MD_DISK_REMOVED"},{16U,L"MD_DISK_CLUSTER_ADD"},{32U,L"MD_DISK_CANDIDATE"},{512U,L"MD_DISK_WRITEMOSTLY"},{1024U,L"MD_DISK_FAILFAST"},{262144U,L"MD_DISK_JOURNAL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530043U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_DISK_FAULTY"},{2U,L"MD_DISK_ACTIVE"},{4U,L"MD_DISK_SYNC"},{8U,L"MD_DISK_REMOVED"},{16U,L"MD_DISK_CLUSTER_ADD"},{32U,L"MD_DISK_CANDIDATE"},{512U,L"MD_DISK_WRITEMOSTLY"},{1024U,L"MD_DISK_FAILFAST"},{262144U,L"MD_DISK_JOURNAL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530040U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_SB_CLEAN"},{2U,L"MD_SB_ERRORS"},{32U,L"MD_SB_CLUSTERED"},{256U,L"MD_SB_BITMAP_PRESENT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530041U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_SB_CLEAN"},{2U,L"MD_SB_ERRORS"},{32U,L"MD_SB_CLUSTERED"},{256U,L"MD_SB_BITMAP_PRESENT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530039U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"D_REMOVABLE"},{2U,L"D_ECC"},{4U,L"D_BADSECT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053003aU&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"D_REMOVABLE"},{2U,L"D_ECC"},{4U,L"D_BADSECT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"media_flags")&&integer){static const sxvi_flag bits[]={{1U,L"IMAGE_FILE"},{2U,L"PHYSICAL_DEVICE"},{4U,L"FASTBLOC_WRITE_BLOCKER"},{8U,L"TABLEAU_WRITE_BLOCKER"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"media_flags")&&integer){static const sxvi_flag bits[]={{1U,L"IMAGE_FILE"},{2U,L"PHYSICAL_DEVICE"},{4U,L"FASTBLOC_WRITE_BLOCKER"},{8U,L"TABLEAU_WRITE_BLOCKER"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Removable media");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fixed media");
    case 3U:return xx_data_struct_record_set_comment(r,L"Optical media");
    case 14U:return xx_data_struct_record_set_comment(r,L"Logical evidence file");
    case 16U:return xx_data_struct_record_set_comment(r,L"Physical memory (RAM)");
    default:break;}}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Removable media");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fixed media");
    case 3U:return xx_data_struct_record_set_comment(r,L"Optical media");
    case 14U:return xx_data_struct_record_set_comment(r,L"Logical evidence file");
    case 16U:return xx_data_struct_record_set_comment(r,L"Physical memory (RAM)");
    default:break;}}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"compression_level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fast compression");
    case 2U:return xx_data_struct_record_set_comment(r,L"Best compression");
    default:break;}}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"compression_level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fast compression");
    case 2U:return xx_data_struct_record_set_comment(r,L"Best compression");
    default:break;}}
    if(id==0x60530012U&&!xx_rt_wcscmp(r->name,L"compression_method")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"DEFLATE (zlib)");
    case 2U:return xx_data_struct_record_set_comment(r,L"BZIP2");
    default:break;}}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Device information");
    case 2U:return xx_data_struct_record_set_comment(r,L"Case data");
    case 3U:return xx_data_struct_record_set_comment(r,L"Sector data");
    case 4U:return xx_data_struct_record_set_comment(r,L"Sector table");
    case 5U:return xx_data_struct_record_set_comment(r,L"Error table");
    case 6U:return xx_data_struct_record_set_comment(r,L"Session table");
    case 7U:return xx_data_struct_record_set_comment(r,L"Increment data");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD5 hash");
    case 9U:return xx_data_struct_record_set_comment(r,L"SHA1 hash");
    case 10U:return xx_data_struct_record_set_comment(r,L"Restart data");
    case 11U:return xx_data_struct_record_set_comment(r,L"Encryption keys");
    case 12U:return xx_data_struct_record_set_comment(r,L"Memory extents table");
    case 13U:return xx_data_struct_record_set_comment(r,L"Next segment");
    case 14U:return xx_data_struct_record_set_comment(r,L"Final information");
    case 15U:return xx_data_struct_record_set_comment(r,L"Done");
    case 16U:return xx_data_struct_record_set_comment(r,L"Analytical data");
    case 32U:return xx_data_struct_record_set_comment(r,L"Single files data");
    default:break;}}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"Has data integrity hash");
    case 2U:return xx_data_struct_record_set_comment(r,L"Encrypted");
    default:break;}}
    if(id==0x60530015U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Compressed");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored with Adler32");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed flag with repeated 8-byte fill pattern");
    default:break;}}
    if(id==0x60530016U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Compressed");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored with Adler32");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed flag with repeated 8-byte fill pattern");
    default:break;}}
    if(id==0x60530004U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"PV_EXT_USED");
    default:break;}}
    if(id==0x60530006U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAW_LOCN_IGNORED");
    default:break;}}
    if(id==0x6053001bU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Stored block");
    case 3U:return xx_data_struct_record_set_comment(r,L"Zero block");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed block");
    default:break;}}
    if(id==0x6053001dU&&!xx_rt_wcscmp(r->name,L"output_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"ISO");
    case 1U:return xx_data_struct_record_set_comment(r,L"BIN/CUE");
    case 2U:return xx_data_struct_record_set_comment(r,L"MDF/MDS");
    case 3U:return xx_data_struct_record_set_comment(r,L"IMG/CCD/SUB");
    case 4U:return xx_data_struct_record_set_comment(r,L"NRG");
    default:break;}}
    if(id==0x60530020U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"Split-volume descriptor");
    case 3U:return xx_data_struct_record_set_comment(r,L"Encryption descriptor");
    default:break;}}
    if(id==0x6053001fU&&!xx_rt_wcscmp(r->name,L"lzma_filter")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No filter");
    case 1U:return xx_data_struct_record_set_comment(r,L"x86 BCJ");
    default:break;}}
    if(id==0x60530025U&&!xx_rt_wcscmp(r->name,L"command")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"SUBVOL");
    case 2U:return xx_data_struct_record_set_comment(r,L"SNAPSHOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"MKFILE");
    case 4U:return xx_data_struct_record_set_comment(r,L"MKDIR");
    case 5U:return xx_data_struct_record_set_comment(r,L"MKNOD");
    case 6U:return xx_data_struct_record_set_comment(r,L"MKFIFO");
    case 7U:return xx_data_struct_record_set_comment(r,L"MKSOCK");
    case 8U:return xx_data_struct_record_set_comment(r,L"SYMLINK");
    case 9U:return xx_data_struct_record_set_comment(r,L"RENAME");
    case 10U:return xx_data_struct_record_set_comment(r,L"LINK");
    case 11U:return xx_data_struct_record_set_comment(r,L"UNLINK");
    case 12U:return xx_data_struct_record_set_comment(r,L"RMDIR");
    case 13U:return xx_data_struct_record_set_comment(r,L"SET_XATTR");
    case 14U:return xx_data_struct_record_set_comment(r,L"REMOVE_XATTR");
    case 15U:return xx_data_struct_record_set_comment(r,L"WRITE");
    case 16U:return xx_data_struct_record_set_comment(r,L"CLONE");
    case 17U:return xx_data_struct_record_set_comment(r,L"TRUNCATE");
    case 18U:return xx_data_struct_record_set_comment(r,L"CHMOD");
    case 19U:return xx_data_struct_record_set_comment(r,L"CHOWN");
    case 20U:return xx_data_struct_record_set_comment(r,L"UTIMES");
    case 21U:return xx_data_struct_record_set_comment(r,L"END");
    case 22U:return xx_data_struct_record_set_comment(r,L"UPDATE_EXTENT");
    case 23U:return xx_data_struct_record_set_comment(r,L"FALLOCATE");
    case 24U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 25U:return xx_data_struct_record_set_comment(r,L"ENCODED_WRITE");
    case 26U:return xx_data_struct_record_set_comment(r,L"ENABLE_VERITY");
    default:break;}}
    if(id==0x60530026U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"UUID");
    case 2U:return xx_data_struct_record_set_comment(r,L"CTRANSID");
    case 3U:return xx_data_struct_record_set_comment(r,L"INO");
    case 4U:return xx_data_struct_record_set_comment(r,L"SIZE");
    case 5U:return xx_data_struct_record_set_comment(r,L"MODE");
    case 6U:return xx_data_struct_record_set_comment(r,L"UID");
    case 7U:return xx_data_struct_record_set_comment(r,L"GID");
    case 8U:return xx_data_struct_record_set_comment(r,L"RDEV");
    case 9U:return xx_data_struct_record_set_comment(r,L"CTIME");
    case 10U:return xx_data_struct_record_set_comment(r,L"MTIME");
    case 11U:return xx_data_struct_record_set_comment(r,L"ATIME");
    case 12U:return xx_data_struct_record_set_comment(r,L"OTIME");
    case 13U:return xx_data_struct_record_set_comment(r,L"XATTR_NAME");
    case 14U:return xx_data_struct_record_set_comment(r,L"XATTR_DATA");
    case 15U:return xx_data_struct_record_set_comment(r,L"PATH");
    case 16U:return xx_data_struct_record_set_comment(r,L"PATH_TO");
    case 17U:return xx_data_struct_record_set_comment(r,L"PATH_LINK");
    case 18U:return xx_data_struct_record_set_comment(r,L"FILE_OFFSET");
    case 19U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 20U:return xx_data_struct_record_set_comment(r,L"CLONE_UUID");
    case 21U:return xx_data_struct_record_set_comment(r,L"CLONE_CTRANSID");
    case 22U:return xx_data_struct_record_set_comment(r,L"CLONE_PATH");
    case 23U:return xx_data_struct_record_set_comment(r,L"CLONE_OFFSET");
    case 24U:return xx_data_struct_record_set_comment(r,L"CLONE_LEN");
    case 25U:return xx_data_struct_record_set_comment(r,L"FALLOCATE_MODE");
    case 26U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 27U:return xx_data_struct_record_set_comment(r,L"UNENCODED_FILE_LEN");
    case 28U:return xx_data_struct_record_set_comment(r,L"UNENCODED_LEN");
    case 29U:return xx_data_struct_record_set_comment(r,L"UNENCODED_OFFSET");
    case 30U:return xx_data_struct_record_set_comment(r,L"COMPRESSION");
    case 31U:return xx_data_struct_record_set_comment(r,L"ENCRYPTION");
    case 32U:return xx_data_struct_record_set_comment(r,L"VERITY_ALGORITHM");
    case 33U:return xx_data_struct_record_set_comment(r,L"VERITY_BLOCK_SIZE");
    case 34U:return xx_data_struct_record_set_comment(r,L"VERITY_SALT_DATA");
    case 35U:return xx_data_struct_record_set_comment(r,L"VERITY_SIG_DATA");
    default:break;}}
    if(id==0x60530027U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"UUID");
    case 2U:return xx_data_struct_record_set_comment(r,L"CTRANSID");
    case 3U:return xx_data_struct_record_set_comment(r,L"INO");
    case 4U:return xx_data_struct_record_set_comment(r,L"SIZE");
    case 5U:return xx_data_struct_record_set_comment(r,L"MODE");
    case 6U:return xx_data_struct_record_set_comment(r,L"UID");
    case 7U:return xx_data_struct_record_set_comment(r,L"GID");
    case 8U:return xx_data_struct_record_set_comment(r,L"RDEV");
    case 9U:return xx_data_struct_record_set_comment(r,L"CTIME");
    case 10U:return xx_data_struct_record_set_comment(r,L"MTIME");
    case 11U:return xx_data_struct_record_set_comment(r,L"ATIME");
    case 12U:return xx_data_struct_record_set_comment(r,L"OTIME");
    case 13U:return xx_data_struct_record_set_comment(r,L"XATTR_NAME");
    case 14U:return xx_data_struct_record_set_comment(r,L"XATTR_DATA");
    case 15U:return xx_data_struct_record_set_comment(r,L"PATH");
    case 16U:return xx_data_struct_record_set_comment(r,L"PATH_TO");
    case 17U:return xx_data_struct_record_set_comment(r,L"PATH_LINK");
    case 18U:return xx_data_struct_record_set_comment(r,L"FILE_OFFSET");
    case 19U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 20U:return xx_data_struct_record_set_comment(r,L"CLONE_UUID");
    case 21U:return xx_data_struct_record_set_comment(r,L"CLONE_CTRANSID");
    case 22U:return xx_data_struct_record_set_comment(r,L"CLONE_PATH");
    case 23U:return xx_data_struct_record_set_comment(r,L"CLONE_OFFSET");
    case 24U:return xx_data_struct_record_set_comment(r,L"CLONE_LEN");
    case 25U:return xx_data_struct_record_set_comment(r,L"FALLOCATE_MODE");
    case 26U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 27U:return xx_data_struct_record_set_comment(r,L"UNENCODED_FILE_LEN");
    case 28U:return xx_data_struct_record_set_comment(r,L"UNENCODED_LEN");
    case 29U:return xx_data_struct_record_set_comment(r,L"UNENCODED_OFFSET");
    case 30U:return xx_data_struct_record_set_comment(r,L"COMPRESSION");
    case 31U:return xx_data_struct_record_set_comment(r,L"ENCRYPTION");
    case 32U:return xx_data_struct_record_set_comment(r,L"VERITY_ALGORITHM");
    case 33U:return xx_data_struct_record_set_comment(r,L"VERITY_BLOCK_SIZE");
    case 34U:return xx_data_struct_record_set_comment(r,L"VERITY_SALT_DATA");
    case 35U:return xx_data_struct_record_set_comment(r,L"VERITY_SIG_DATA");
    default:break;}}
    if(id==0x60530034U&&!xx_rt_wcscmp(r->name,L"block_type")&&integer){switch(value){
    case 844383300U:return xx_data_struct_record_set_comment(r,L"DDT2");
    case 1263288900U:return xx_data_struct_record_set_comment(r,L"DBLK");
    default:break;}}
    if(id==0x60530031U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530034U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530035U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530031U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    default:break;}}
    if(id==0x60530035U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    default:break;}}
    if(id==0x6053003bU&&!xx_rt_wcscmp(r->name,L"filesystem_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FS_UNUSED");
    case 1U:return xx_data_struct_record_set_comment(r,L"FS_SWAP");
    case 2U:return xx_data_struct_record_set_comment(r,L"FS_V6");
    case 3U:return xx_data_struct_record_set_comment(r,L"FS_V7");
    case 4U:return xx_data_struct_record_set_comment(r,L"FS_SYSV");
    case 5U:return xx_data_struct_record_set_comment(r,L"FS_V71K");
    case 6U:return xx_data_struct_record_set_comment(r,L"FS_V8");
    case 7U:return xx_data_struct_record_set_comment(r,L"FS_BSDFFS");
    case 8U:return xx_data_struct_record_set_comment(r,L"FS_MSDOS");
    case 9U:return xx_data_struct_record_set_comment(r,L"FS_BSDLFS");
    case 10U:return xx_data_struct_record_set_comment(r,L"FS_OTHER");
    case 11U:return xx_data_struct_record_set_comment(r,L"FS_HPFS");
    case 12U:return xx_data_struct_record_set_comment(r,L"FS_ISO9660");
    case 13U:return xx_data_struct_record_set_comment(r,L"FS_BOOT");
    case 14U:return xx_data_struct_record_set_comment(r,L"FS_VINUM");
    case 15U:return xx_data_struct_record_set_comment(r,L"FS_RAID");
    case 16U:return xx_data_struct_record_set_comment(r,L"FS_FILECORE");
    case 17U:return xx_data_struct_record_set_comment(r,L"FS_EXT2FS");
    case 18U:return xx_data_struct_record_set_comment(r,L"FS_NTFS");
    default:break;}}
    if(id==0x6053003cU&&!xx_rt_wcscmp(r->name,L"filesystem_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FS_UNUSED");
    case 1U:return xx_data_struct_record_set_comment(r,L"FS_SWAP");
    case 2U:return xx_data_struct_record_set_comment(r,L"FS_V6");
    case 3U:return xx_data_struct_record_set_comment(r,L"FS_V7");
    case 4U:return xx_data_struct_record_set_comment(r,L"FS_SYSV");
    case 5U:return xx_data_struct_record_set_comment(r,L"FS_V71K");
    case 6U:return xx_data_struct_record_set_comment(r,L"FS_V8");
    case 7U:return xx_data_struct_record_set_comment(r,L"FS_BSDFFS");
    case 8U:return xx_data_struct_record_set_comment(r,L"FS_MSDOS");
    case 9U:return xx_data_struct_record_set_comment(r,L"FS_BSDLFS");
    case 10U:return xx_data_struct_record_set_comment(r,L"FS_OTHER");
    case 11U:return xx_data_struct_record_set_comment(r,L"FS_HPFS");
    case 12U:return xx_data_struct_record_set_comment(r,L"FS_ISO9660");
    case 13U:return xx_data_struct_record_set_comment(r,L"FS_BOOT");
    case 14U:return xx_data_struct_record_set_comment(r,L"FS_VINUM");
    case 15U:return xx_data_struct_record_set_comment(r,L"FS_RAID");
    case 16U:return xx_data_struct_record_set_comment(r,L"FS_FILECORE");
    case 17U:return xx_data_struct_record_set_comment(r,L"FS_EXT2FS");
    case 18U:return xx_data_struct_record_set_comment(r,L"FS_NTFS");
    default:break;}}
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x60530040U&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x60530041U&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No optional features");
    case 1U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BITMAP_OFFSET");
    case 2U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_OFFSET");
    case 4U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_ACTIVE");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BAD_BLOCKS");
    case 16U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_REPLACEMENT");
    case 32U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_BACKWARDS");
    case 64U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_NEW_OFFSET");
    case 128U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_BITMAP");
    case 256U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_CLUSTERED");
    case 512U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_JOURNAL");
    case 1024U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_PPL");
    case 2048U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_MULTIPLE_PPLS");
    default:break;}}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No optional features");
    case 1U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BITMAP_OFFSET");
    case 2U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_OFFSET");
    case 4U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_ACTIVE");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BAD_BLOCKS");
    case 16U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_REPLACEMENT");
    case 32U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_BACKWARDS");
    case 64U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_NEW_OFFSET");
    case 128U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_BITMAP");
    case 256U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_CLUSTERED");
    case 512U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_JOURNAL");
    case 1024U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_PPL");
    case 2048U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_MULTIPLE_PPLS");
    default:break;}}
    if(id==0x6053003fU&&!xx_rt_wcscmp(r->name,L"role")&&integer){switch(value){
    case 65535U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_SPARE");
    case 65534U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_FAULTY");
    case 65533U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_JOURNAL");
    default:break;}}
    if(id==0x60530050U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 50U:return xx_data_struct_record_set_comment(r,L"Component v3");
    case 51U:return xx_data_struct_record_set_comment(r,L"Partition v3");
    case 52U:return xx_data_struct_record_set_comment(r,L"Disk v3");
    case 53U:return xx_data_struct_record_set_comment(r,L"Disk group v3");
    case 68U:return xx_data_struct_record_set_comment(r,L"Disk v4");
    case 69U:return xx_data_struct_record_set_comment(r,L"Disk group v4");
    case 81U:return xx_data_struct_record_set_comment(r,L"Volume v5");
    default:break;}}
    if(id==0x6053004eU&&!xx_rt_wcscmp(r->name,L"update_state")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Database consistent");
    default:break;}}
    if(id==0x60530049U&&!xx_rt_wcscmp(r->name,L"mode")&&integer){switch(value){
    case 169U:return xx_data_struct_record_set_comment(r,L"Audio");
    case 170U:return xx_data_struct_record_set_comment(r,L"Mode 1");
    case 171U:return xx_data_struct_record_set_comment(r,L"Mode 2");
    case 236U:return xx_data_struct_record_set_comment(r,L"Mode 2 Form 1");
    case 173U:return xx_data_struct_record_set_comment(r,L"Mode 2 Form 2 alternate");
    default:break;}}
    if(id==0x60530049U&&!xx_rt_wcscmp(r->name,L"point")&&integer){switch(value){
    case 160U:return xx_data_struct_record_set_comment(r,L"First track in session");
    case 161U:return xx_data_struct_record_set_comment(r,L"Last track in session");
    case 162U:return xx_data_struct_record_set_comment(r,L"Lead-out start");
    case 176U:return xx_data_struct_record_set_comment(r,L"Next session information");
    case 192U:return xx_data_struct_record_set_comment(r,L"Lead-in information");
    default:break;}}
    if(id==0x6053005dU&&!xx_rt_wcscmp(r->name,L"read_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2048-byte sectors");
    case 1U:return xx_data_struct_record_set_comment(r,L"2336-byte sectors");
    case 2U:return xx_data_struct_record_set_comment(r,L"2352-byte sectors");
    default:break;}}
    if(id==0x6053005dU&&!xx_rt_wcscmp(r->name,L"mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Audio");
    case 1U:return xx_data_struct_record_set_comment(r,L"Mode 1");
    case 2U:return xx_data_struct_record_set_comment(r,L"Mode 2");
    default:break;}}
    if(id==0x60530052U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Boot record");
    case 1U:return xx_data_struct_record_set_comment(r,L"Standard file structure volume descriptor");
    case 2U:return xx_data_struct_record_set_comment(r,L"Coded file structure volume descriptor");
    case 255U:return xx_data_struct_record_set_comment(r,L"Volume descriptor terminator");
    default:break;}}
    if(id==0x60530053U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Boot record");
    case 1U:return xx_data_struct_record_set_comment(r,L"Standard file structure volume descriptor");
    case 2U:return xx_data_struct_record_set_comment(r,L"Coded file structure volume descriptor");
    case 255U:return xx_data_struct_record_set_comment(r,L"Volume descriptor terminator");
    default:break;}}
    if(id==0x6053005fU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"Gzip");
    case 2U:return xx_data_struct_record_set_comment(r,L"Bzip2");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530039U&&!xx_rt_wcscmp(r->name,L"drive_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DTYPE_SMD");
    case 2U:return xx_data_struct_record_set_comment(r,L"DTYPE_MSCP");
    case 3U:return xx_data_struct_record_set_comment(r,L"DTYPE_DEC");
    case 4U:return xx_data_struct_record_set_comment(r,L"DTYPE_SCSI");
    case 5U:return xx_data_struct_record_set_comment(r,L"DTYPE_ESDI");
    case 6U:return xx_data_struct_record_set_comment(r,L"DTYPE_ST506");
    case 7U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPIB");
    case 8U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPFL");
    case 10U:return xx_data_struct_record_set_comment(r,L"DTYPE_FLOPPY");
    case 11U:return xx_data_struct_record_set_comment(r,L"DTYPE_CCD");
    case 12U:return xx_data_struct_record_set_comment(r,L"DTYPE_VINUM");
    case 13U:return xx_data_struct_record_set_comment(r,L"DTYPE_DOC2K");
    case 14U:return xx_data_struct_record_set_comment(r,L"DTYPE_RAID");
    default:break;}}
    if(id==0x6053003aU&&!xx_rt_wcscmp(r->name,L"drive_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DTYPE_SMD");
    case 2U:return xx_data_struct_record_set_comment(r,L"DTYPE_MSCP");
    case 3U:return xx_data_struct_record_set_comment(r,L"DTYPE_DEC");
    case 4U:return xx_data_struct_record_set_comment(r,L"DTYPE_SCSI");
    case 5U:return xx_data_struct_record_set_comment(r,L"DTYPE_ESDI");
    case 6U:return xx_data_struct_record_set_comment(r,L"DTYPE_ST506");
    case 7U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPIB");
    case 8U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPFL");
    case 10U:return xx_data_struct_record_set_comment(r,L"DTYPE_FLOPPY");
    case 11U:return xx_data_struct_record_set_comment(r,L"DTYPE_CCD");
    case 12U:return xx_data_struct_record_set_comment(r,L"DTYPE_VINUM");
    case 13U:return xx_data_struct_record_set_comment(r,L"DTYPE_DOC2K");
    case 14U:return xx_data_struct_record_set_comment(r,L"DTYPE_RAID");
    default:break;}}
    switch(id){
    case 0x60530001U:
        if(!xx_rt_wcscmp(r->name,L"sector_number"))s=L"Label location in 512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"LVM CRC seed 0xF597A6CF over bytes20..511";
        else if(!xx_rt_wcscmp(r->name,L"pv_header_offset"))s=L"Byte offset from the start of this label sector";
        break;
    case 0x60530003U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from the physical-volume image start; all-zero pair terminates a list";
        else if(!xx_rt_wcscmp(r->name,L"size"))s=L"Zero size for a data area can mean all remaining bytes";
        break;
    case 0x60530005U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"LVM CRC seed0xF597A6CF over bytes4..511";
        else if(!xx_rt_wcscmp(r->name,L"start"))s=L"Byte offset from physical-volume image start";
        break;
    case 0x60530006U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset within this metadata area; text may wrap after its512-byte header";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 RAW_LOCN_IGNORED";
        break;
    case 0x60530008U:
        if(!xx_rt_wcscmp(r->name,L"next_descriptor_offset"))s=L"Relative to this segment file; terminal sections point to themselves";
        else if(!xx_rt_wcscmp(r->name,L"section_size"))s=L"Includes76-byte descriptor; terminal sections may store0";
        else if(!xx_rt_wcscmp(r->name,L"adler32"))s=L"Adler32 of first72descriptor bytes";
        break;
    case 0x60530009U:
        if(!xx_rt_wcscmp(r->name,L"palm_start_sector"))s=L"Sector number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"smart_logs_distance"))s=L"Sector distance backwards from the end of media";
        else if(!xx_rt_wcscmp(r->name,L"error_granularity"))s=L"Error-block size in sectors";
        break;
    case 0x6053000aU:
        if(!xx_rt_wcscmp(r->name,L"chunk_count"))s=L"Commonly0 for logical evidence";
        else if(!xx_rt_wcscmp(r->name,L"logical_sector_value"))s=L"Logical-evidence field does not necessarily describe physical media sectors";
        else if(!xx_rt_wcscmp(r->name,L"palm_start_sector"))s=L"Sector number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"smart_logs_distance"))s=L"Sector distance backwards from the end of media";
        else if(!xx_rt_wcscmp(r->name,L"error_granularity"))s=L"Error-block size in sectors";
        break;
    case 0x6053000cU:
        if(!xx_rt_wcscmp(r->name,L"base_offset"))s=L"Segment-relative base for encoded chunk offsets; older writers store0";
        break;
    case 0x6053000dU:
        if(!xx_rt_wcscmp(r->name,L"offset_and_compression"))s=L"Bit31 means compressed; low31bits are a byte offset relative to table base";
        break;
    case 0x60530011U:
        if(!xx_rt_wcscmp(r->name,L"adler32"))s=L"Header Adler32 with this field zeroed";
        break;
    case 0x60530013U:
        if(!xx_rt_wcscmp(r->name,L"previous_descriptor_offset"))s=L"Segment-relative descriptor byte offset;0 means first section";
        else if(!xx_rt_wcscmp(r->name,L"data_size"))s=L"Includes alignment padding preceding this descriptor";
        break;
    case 0x60530014U:
        if(!xx_rt_wcscmp(r->name,L"first_chunk_number"))s=L"Logical chunk index, not a byte offset";
        break;
    case 0x60530015U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from segment start";
        break;
    case 0x60530016U:
        if(!xx_rt_wcscmp(r->name,L"fill_pattern"))s=L"Physical repeated pattern bytes, not an offset";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Compressed and pattern-fill bits set";
        break;
    case 0x60530019U:
        if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"0means a complete final sector";
        break;
    case 0x6053001aU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Counts bytes starting at offset8 of this header";
        break;
    case 0x6053001bU:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"Logical sector index";
        break;
    case 0x6053001cU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"blms counts from header offset8; blss from offset12; uncompressed data uses original_size";
        break;
    case 0x6053001fU:
        if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"Low24bits are byte offset; upper bits retain format flags";
        else if(!xx_rt_wcscmp(r->name,L"chunk_size_and_flags"))s=L"Low12bits count16KiB units; remaining bits encode table/codec/permutation flags";
        else if(!xx_rt_wcscmp(r->name,L"table_bit_widths"))s=L"Bits0..2 type width; bits3..7 encoded length width";
        break;
    case 0x60530020U:
        if(!xx_rt_wcscmp(r->name,L"size"))s=L"Includes this8-byte header";
        break;
    case 0x60530022U:
        if(!xx_rt_wcscmp(r->name,L"header_size_words"))s=L"Header length in4-byte words";
        else if(!xx_rt_wcscmp(r->name,L"block_size_log2"))s=L"log2 uncompressed block size in bytes";
        break;
    case 0x60530023U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from zisofs compressed-file start";
        break;
    case 0x60530025U:
        if(!xx_rt_wcscmp(r->name,L"crc32c"))s=L"CRC32C seeded0 without final inversion";
        break;
    case 0x60530027U:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"DATA19 consumes remainder of command without a stored length";
        break;
    case 0x6053002bU:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Logical file-data byte offset, not an offset in the send-stream container";
        break;
    case 0x6053002fU:
        if(!xx_rt_wcscmp(r->name,L"seconds"))s=L"Unix seconds, signed64 representation";
        else if(!xx_rt_wcscmp(r->name,L"nanoseconds"))s=L"Fractional nanoseconds within the second";
        break;
    case 0x60530030U:
        if(!xx_rt_wcscmp(r->name,L"application"))s=L"UTF8 in AaruFormat version2";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Windows FILETIME100ns intervals since1601-01-01UTC";
        else if(!xx_rt_wcscmp(r->name,L"last_written_time"))s=L"Windows FILETIME100ns intervals since1601-01-01UTC";
        else if(!xx_rt_wcscmp(r->name,L"block_alignment_shift"))s=L"Byte alignment is2^shift";
        break;
    case 0x60530031U:
        if(!xx_rt_wcscmp(r->name,L"table_level"))s=L"Zero-based hierarchy level";
        else if(!xx_rt_wcscmp(r->name,L"blocks"))s=L"Logical sector span including negative and overflow sectors";
        else if(!xx_rt_wcscmp(r->name,L"start"))s=L"Logical starting sector index, not a physical byte offset";
        else if(!xx_rt_wcscmp(r->name,L"block_alignment_shift"))s=L"Physical block alignment is2^shift bytes";
        else if(!xx_rt_wcscmp(r->name,L"data_shift"))s=L"Low data_shift bits of a DDT entry contain its sector index within the data block";
        else if(!xx_rt_wcscmp(r->name,L"table_shift"))s=L"Logical sectors per primary entry are2^table_shift";
        break;
    case 0x60530032U:
        if(!xx_rt_wcscmp(r->name,L"encoded_location"))s=L"High4bits are status; lower60bits combine shifted aligned data-block index and within-block sector index";
        break;
    case 0x60530036U:
        if(!xx_rt_wcscmp(r->name,L"argument"))s=L"Segment-specific argument: page codec flags or scalar value";
        break;
    case 0x60530037U:
        if(!xx_rt_wcscmp(r->name,L"segment_size"))s=L"Includes16-byte header, name, payload and8-byte footer";
        break;
    case 0x60530038U:
        if(!xx_rt_wcscmp(r->name,L"low"))s=L"Low32bits of AFF quadword, stored big endian";
        else if(!xx_rt_wcscmp(r->name,L"high"))s=L"High32bits of AFF quadword, stored big endian";
        break;
    case 0x60530039U:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"interleave"))s=L"Physical-sector interleave ratio";
        else if(!xx_rt_wcscmp(r->name,L"track_skew"))s=L"Sector displacement per track";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_skew"))s=L"Sector displacement per cylinder";
        else if(!xx_rt_wcscmp(r->name,L"drive_data"))s=L"Drive-specific stored words";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"XOR of label and declared partition-table16-bit words";
        break;
    case 0x6053003aU:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"interleave"))s=L"Physical-sector interleave ratio";
        else if(!xx_rt_wcscmp(r->name,L"track_skew"))s=L"Sector displacement per track";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_skew"))s=L"Sector displacement per cylinder";
        else if(!xx_rt_wcscmp(r->name,L"drive_data"))s=L"Drive-specific stored words";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"XOR of label and declared partition-table16-bit words";
        break;
    case 0x6053003bU:
        if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Sector number relative to disk start";
        break;
    case 0x6053003cU:
        if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Sector number relative to disk start";
        break;
    case 0x6053003dU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_offset"))s=L"Signed512-byte sector displacement from superblock; meaningful when feature bit0 is set";
        else if(!xx_rt_wcscmp(r->name,L"new_level"))s=L"Valid only during reshape";
        else if(!xx_rt_wcscmp(r->name,L"reshape_position"))s=L"Next logical array sector to reshape";
        else if(!xx_rt_wcscmp(r->name,L"new_data_offset"))s=L"Signed sector displacement added to data_offset during reshape";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Physical component start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"super_offset"))s=L"Physical superblock start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"recovery_or_journal_offset"))s=L"Feature-dependent logical sector position relative to data_offset";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_shift"))s=L"Bad-block unit is512 shifted by this value";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_log_offset"))s=L"Signed sector displacement from this superblock";
        else if(!xx_rt_wcscmp(r->name,L"update_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"resync_offset"))s=L"Synchronized logical sector count orUINT64_MAX sentinel";
        break;
    case 0x6053003eU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"ppl_offset"))s=L"Signed512-byte sector displacement from superblock";
        else if(!xx_rt_wcscmp(r->name,L"new_level"))s=L"Valid only during reshape";
        else if(!xx_rt_wcscmp(r->name,L"reshape_position"))s=L"Next logical array sector to reshape";
        else if(!xx_rt_wcscmp(r->name,L"new_data_offset"))s=L"Signed sector displacement added to data_offset during reshape";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Physical component start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"super_offset"))s=L"Physical superblock start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"recovery_or_journal_offset"))s=L"Feature-dependent logical sector position relative to data_offset";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_shift"))s=L"Bad-block unit is512 shifted by this value";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_log_offset"))s=L"Signed sector displacement from this superblock";
        else if(!xx_rt_wcscmp(r->name,L"update_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"resync_offset"))s=L"Synchronized logical sector count orUINT64_MAX sentinel";
        break;
    case 0x6053003fU:
        if(!xx_rt_wcscmp(r->name,L"role"))s=L"Array role;0xFFFF spare,0xFFFE faulty,0xFFFD journal";
        break;
    case 0x60530040U:
        if(!xx_rt_wcscmp(r->name,L"valid_words"))s=L"Used32-bit words in constant section";
        else if(!xx_rt_wcscmp(r->name,L"level"))s=L"Signed RAID personality convention";
        else if(!xx_rt_wcscmp(r->name,L"component_kib"))s=L"Apparent member size in1024-byte units";
        else if(!xx_rt_wcscmp(r->name,L"events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"checkpoint_events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"recovery_checkpoint"))s=L"Sectors recovered";
        else if(!xx_rt_wcscmp(r->name,L"state_reserved"))s=L"Reshape extension is not defined for native-supported minor90";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Logical volume root block number";
        break;
    case 0x60530041U:
        if(!xx_rt_wcscmp(r->name,L"valid_words"))s=L"Used32-bit words in constant section";
        else if(!xx_rt_wcscmp(r->name,L"level"))s=L"Signed RAID personality convention";
        else if(!xx_rt_wcscmp(r->name,L"component_kib"))s=L"Apparent member size in1024-byte units";
        else if(!xx_rt_wcscmp(r->name,L"events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"checkpoint_events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"recovery_checkpoint"))s=L"Sectors recovered";
        else if(!xx_rt_wcscmp(r->name,L"state_reserved"))s=L"Reshape extension is not defined for native-supported minor90";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Logical volume root block number";
        break;
    case 0x60530044U:
        if(!xx_rt_wcscmp(r->name,L"partition_0_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_1_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_2_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_3_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_4_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_5_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_6_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_7_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        break;
    case 0x60530045U:
        if(!xx_rt_wcscmp(r->name,L"partition_0_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_1_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_2_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_3_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_4_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_5_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_6_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_7_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_8_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_9_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_10_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_11_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_12_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_13_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_14_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_15_start_sector"))s=L"Disk-relative512-byte sector number";
        break;
    case 0x60530046U:
        if(!xx_rt_wcscmp(r->name,L"format_word"))s=L"Native accepts1..16; detailed revision meaning is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_0"))s=L"Product of the three geometry factors gives total_sectors; physical axis is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_1"))s=L"Native bounds this factor to1..255; physical axis is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_2"))s=L"Native bounds this factor to1..255; physical axis is unverified";
        break;
    case 0x60530047U:
        if(!xx_rt_wcscmp(r->name,L"session_count_copy"))s=L"Native supported producer duplicates session count here";
        break;
    case 0x60530048U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Signed logical sector position";
        else if(!xx_rt_wcscmp(r->name,L"end_lba"))s=L"Signed logical sector position";
        break;
    case 0x60530049U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector position in companion MDF image";
        else if(!xx_rt_wcscmp(r->name,L"mdf_offset"))s=L"Byte offset in the companion MDF, not in this MDS descriptor";
        break;
    case 0x6053004cU:
        if(!xx_rt_wcscmp(r->name,L"logical_disk_start"))s=L"512-byte sectors relative to the component image";
        else if(!xx_rt_wcscmp(r->name,L"configuration_start"))s=L"512-byte sectors relative to the component image";
        break;
    case 0x6053004dU:
        if(!xx_rt_wcscmp(r->name,L"configuration_start"))s=L"Sector index relative to configuration area";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Sector index relative to configuration area";
        break;
    case 0x6053004eU:
        if(!xx_rt_wcscmp(r->name,L"last_vblk_sequence"))s=L"Exclusive VBLK slot bound; multiplied by record size";
        else if(!xx_rt_wcscmp(r->name,L"vblk_offset"))s=L"Byte offset relative to this VMDB header";
        break;
    case 0x6053004fU:
        if(!xx_rt_wcscmp(r->name,L"fragment_number"))s=L"Zero-based fragment number within group";
        break;
    case 0x60530050U:
        if(!xx_rt_wcscmp(r->name,L"declared_length"))s=L"Type-specific static and variable widths; not an offset from VBLK magic";
        break;
    case 0x60530051U:
        if(!xx_rt_wcscmp(r->name,L"length"))s=L"Byte length of following field";
        break;
    case 0x60530052U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_sector_le"))s=L"2048-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"descriptor_sector_be"))s=L"Big-endian copy of descriptor sector number";
        else if(!xx_rt_wcscmp(r->name,L"path_table_locations"))s=L"Encoded little/big-endian path-table block locations; not followed by this provider";
        break;
    case 0x60530053U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_sector_le"))s=L"2048-byte sector number";
        break;
    case 0x60530054U:
        if(!xx_rt_wcscmp(r->name,L"extent_block_le"))s=L"Logical block index relative to the volume";
        break;
    case 0x60530055U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Decimal YYYYMMDDhhmmsscc; no timezone byte in High Sierra";
        break;
    case 0x60530056U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_offset"))s=L"Offset from beginning of CDI file";
        break;
    case 0x60530057U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_distance"))s=L"Distance backwards from end of CDI file to descriptor";
        break;
    case 0x6053005bU:
        if(!xx_rt_wcscmp(r->name,L"sectors"))s=L"Sector count for this index; first entry is pregap";
        break;
    case 0x6053005dU:
        if(!xx_rt_wcscmp(r->name,L"session_index"))s=L"Zero-based session number";
        else if(!xx_rt_wcscmp(r->name,L"track_index"))s=L"Zero-based track number";
        else if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Logical sector position on the disc";
        else if(!xx_rt_wcscmp(r->name,L"read_mode"))s=L"0=2048bytes;1=2336bytes;2=2352bytes per stored sector";
        break;
    case 0x6053005eU:
        if(!xx_rt_wcscmp(r->name,L"volume_number"))s=L"Zero-based split volume number";
        break;
    case 0x6053005fU:
        if(!xx_rt_wcscmp(r->name,L"month"))s=L"Zero-based month as in struct tm";
        else if(!xx_rt_wcscmp(r->name,L"year"))s=L"Years since1900";
        else if(!xx_rt_wcscmp(r->name,L"timezone_offset"))s=L"Legacy portable_tm word; signed offset representation can be encoded in these32bits";
        else if(!xx_rt_wcscmp(r->name,L"timezone_word"))s=L"Legacy stored timezone word; not a portable pointer";
        break;
    case 0x60530061U:
        if(!xx_rt_wcscmp(r->name,L"additive_checksum"))s=L"Sum of signed8-bit header bytes modulo2^32";
        break;
    case 0x60530063U:
        if(!xx_rt_wcscmp(r->name,L"block_position"))s=L"Original partition block index at this checkpoint";
        break;
    case 0x60530064U:
        if(!xx_rt_wcscmp(r->name,L"additive_checksum"))s=L"Unsigned byte sum through MAGIC-BEGIN-TAIL";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXVI_LIMIT 24000U
bool sxvi_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxvi_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxvi_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxvi16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxvi32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxvi16(b,0)<<16|sxvi16(b+2,0);return o==1?(uint32_t)sxvi16(b,1)<<16|sxvi16(b+2,1):(uint32_t)sxvi16(b+2,0)<<16|sxvi16(b,0);}
uint64_t sxvi64(const uint8_t*b,unsigned o){return o==1?(uint64_t)sxvi32(b,1)<<32|sxvi32(b+4,1):(uint64_t)sxvi32(b+4,0)<<32|sxvi32(b,0);}
bool sxvi_pow(uint64_t v){return v&&!(v&(v-1));}
bool sxvi_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxvi_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXVI_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static uint32_t sxvi_adler(const uint8_t*p,size_t n){uint32_t a=1,b=0;while(n--){a=(a+*p++)%65521U;b=(b+a)%65521U;}return b<<16|a;}
bool sxvi_magic(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxvi_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static bool sxvi_ewf1(sx_context*c){uint8_t h[76],b[32];uint64_t base=0,p=13;bool logical=c->f->file_type==XX_FILE_TYPE_EWF_L01;
 if(!sxvi_read(c,0,h,13)||((h[0]!='E'&&h[0]!='L')||h[1]!='V'||h[2]!='F')||h[8]!=1||!SXVI_ADD(c,ewf1_file_header,0))return false;
 for(unsigned visited=0;visited<1048576&&c->count<SXVI_LIMIT;visited++){
  if(!sxvi_read(c,p,h,76)||sxvi_adler(h,72)!=sxvi32(h+72,0))break;uint64_t rel=sxvi64(h+16,0),z=sxvi64(h+24,0);if(!SXVI_ADD(c,ewf1_section_descriptor,p))return false;
  if(!xx_rt_memcmp(h,"done\0",5))break;if(!xx_rt_memcmp(h,"next\0",5)){base=p+76;if(!sxvi_read(c,base,b,13)||b[0]!=(logical?'L':'E')||b[1]!='V'||b[2]!='F')break;/* Signature check below is independent of the overwritten descriptor. */if(b[8]!=1||!SXVI_ADD(c,ewf1_file_header,base))return false;p=base+13;continue;}
  if(rel>(uint64_t)c->size-base)break;uint64_t next=base+rel;if(next<=p||next-p<76)break;if(!z)z=next-p;if(z<76||z>next-p)break;uint64_t data=p+76,bytes=z-76;
  if(!xx_rt_memcmp(h,"volume\0",7)||!xx_rt_memcmp(h,"disk\0",5)||!xx_rt_memcmp(h,"data\0",5)){
   if(bytes>=1052){if(!sxvi_put(c,logical?&sxvi_ewf1_logical_volume:&sxvi_ewf1_volume,data,1))return false;}else if(!logical&&bytes==94&&!SXVI_ADD(c,ewf1_smart_volume,data))return false;
  }else if(!xx_rt_memcmp(h,"table\0",6)||!xx_rt_memcmp(h,"table2\0",7)){
   if(bytes>=24&&sxvi_read(c,data,b,24)){uint64_t n=sxvi32(b,0);if(n<=1048576&&n<=(bytes-24)/4){if(!SXVI_ADD(c,ewf1_table_header,data)||!SXVI_TABLE(c,ewf1_chunk_entry,data+24,n))return false;if(bytes-24-n*4>=4&&!SXVI_ADD(c,image_adler32,data+24+n*4))return false;}}
  }else if(!xx_rt_memcmp(h,"hash\0",5)&&bytes>=36){if(!SXVI_ADD(c,ewf1_hash,data))return false;}
  else if(!xx_rt_memcmp(h,"digest\0",7)&&bytes>=80){if(!SXVI_ADD(c,ewf1_digest,data))return false;}
  else if(!xx_rt_memcmp(h,"ltree\0",6)&&bytes>=48){if(!SXVI_ADD(c,ewf1_ltree_header,data))return false;}
  p=next;
 }return true;
}
static bool sxvi_ewf2_descriptor(sx_context*c,uint64_t p,uint8_t b[64]){if(!sxvi_read(c,p,b,64)||sxvi32(b+24,0)!=64||sxvi_adler(b,60)!=sxvi32(b+60,0))return false;uint64_t prev=sxvi64(b+8,0),n=sxvi64(b+16,0);uint32_t type=sxvi32(b,0);if(!type||type>65535||p<32||prev>=p||(prev&&(prev<32||p-prev<64)))return false;uint64_t start=prev?prev+64:32;return start<=p&&n<=p-start&&sxvi32(b+28,0)<=n;}
static bool sxvi_ewf2_row(sx_context*c,uint64_t p,const uint8_t b[64]){uint64_t prev=sxvi64(b+8,0),data=prev?prev+64:32,n=sxvi64(b+16,0);/* Padding may be internal to table headers: bound physical rows by full data_size. */uint32_t type=sxvi32(b,0);if(!SXVI_ADD(c,ewf2_section_descriptor,p))return false;if(sxvi32(b+4,0)&2)return true;uint8_t h[32];
 if(type==4&&n>=32&&sxvi_read(c,data,h,32)){uint64_t count=sxvi32(h+8,0);if(count>1048576||count>(n-32)/16)return true;if(!SXVI_ADD(c,ewf2_table_header,data))return false;for(uint64_t i=0;i<count&&c->count<SXVI_LIMIT;i++){uint8_t e[16];if(!sxvi_read(c,data+32+i*16,e,16))return false;uint32_t f=sxvi32(e+12,0);if(!sxvi_put(c,(f&5)==5?&sxvi_ewf2_pattern_entry:&sxvi_ewf2_chunk_entry,data+32+i*16,1))return false;}if(n-32-count*16>=4&&!SXVI_ADD(c,image_adler32,data+32+count*16))return false;}
 else if(type==8&&n>=20){if(!SXVI_ADD(c,ewf2_md5,data))return false;}else if(type==9&&n>=24){if(!SXVI_ADD(c,ewf2_sha1,data))return false;}return true;
}
static bool sxvi_ewf2(sx_context*c){uint8_t h[64];if(!sxvi_read(c,0,h,32)||((c->f->file_type==XX_FILE_TYPE_EWF2_LX01)?xx_rt_memcmp(h,"LEF2",4):xx_rt_memcmp(h,"EVF2",4))||!SXVI_ADD(c,ewf2_file_header,0))return false;
 uint64_t end=(uint64_t)c->size;if(end>=96&&sxvi_ewf2_descriptor(c,end-64,h)&&(sxvi32(h,0)==13||sxvi32(h,0)==15)){
  uint64_t p=end-64;for(unsigned i=0;i<1048576&&c->count<SXVI_LIMIT;i++){if(!sxvi_ewf2_row(c,p,h))return false;uint64_t prev=sxvi64(h+8,0);if(!prev)break;p=prev;if(!sxvi_ewf2_descriptor(c,p,h))break;}return true;
 }
 /* Padded/truncated native-valid segments use aligned authenticated descriptors.
  * Search at most64MiB of physical metadata; omitted suffix remains raw. */
 uint64_t prev=0,limit=end<UINT64_C(67108864)?end:UINT64_C(67108864);for(uint64_t p=32;p+64<=limit&&c->count<SXVI_LIMIT;p+=16){if(!sxvi_ewf2_descriptor(c,p,h)||sxvi64(h+8,0)!=prev)continue;if(!sxvi_ewf2_row(c,p,h))return false;prev=p;if(sxvi32(h,0)==13||sxvi32(h,0)==15)break;p+=48;}return true;
}
static int sxvi_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxvi_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvi_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_volumeimages_supports(xx_file_type_t t){switch(t){
 case XX_FILE_TYPE_LVM2:case XX_FILE_TYPE_MD_RAID:case XX_FILE_TYPE_WINDOWS_LDM:case XX_FILE_TYPE_BSD_DISKLABEL:case XX_FILE_TYPE_SUNVTOC:case XX_FILE_TYPE_NEXTSTEP_DISKIMAGE:case XX_FILE_TYPE_AFF:case XX_FILE_TYPE_EWF:case XX_FILE_TYPE_EWF_L01:case XX_FILE_TYPE_EWF2_EX01:case XX_FILE_TYPE_EWF2_LX01:case XX_FILE_TYPE_PARTIMAGE:case XX_FILE_TYPE_BTRFS_STREAM:case XX_FILE_TYPE_DISKJUGGLER:case XX_FILE_TYPE_MDS:case XX_FILE_TYPE_UIF:case XX_FILE_TYPE_GBI:case XX_FILE_TYPE_HSF:case XX_FILE_TYPE_AARUFORMAT:case XX_FILE_TYPE_ZISOFS:return true;default:return false;}}
static bool sx_volumeimages_build(sx_context*c){bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_LVM2:ok=sx_lvm2_build(c);break;case XX_FILE_TYPE_MD_RAID:ok=sx_md_raid_build(c);break;case XX_FILE_TYPE_WINDOWS_LDM:ok=sx_windows_ldm_build(c);break;case XX_FILE_TYPE_BSD_DISKLABEL:ok=sx_bsd_disklabel_build(c);break;case XX_FILE_TYPE_SUNVTOC:ok=sx_sunvtoc_build(c);break;case XX_FILE_TYPE_NEXTSTEP_DISKIMAGE:ok=sx_nextstep_diskimage_build(c);break;case XX_FILE_TYPE_AFF:ok=sx_aff_build(c);break;case XX_FILE_TYPE_EWF:case XX_FILE_TYPE_EWF_L01:ok=sxvi_ewf1(c);break;case XX_FILE_TYPE_EWF2_EX01:case XX_FILE_TYPE_EWF2_LX01:ok=sxvi_ewf2(c);break;case XX_FILE_TYPE_PARTIMAGE:ok=sx_partimage_build(c);break;case XX_FILE_TYPE_BTRFS_STREAM:ok=sx_btrfs_stream_build(c);break;case XX_FILE_TYPE_DISKJUGGLER:ok=sx_diskjuggler_build(c);break;case XX_FILE_TYPE_MDS:ok=sx_mds_build(c);break;case XX_FILE_TYPE_UIF:ok=sx_uif_build(c);break;case XX_FILE_TYPE_GBI:ok=sx_gbi_build(c);break;case XX_FILE_TYPE_HSF:ok=sx_hsf_build(c);break;case XX_FILE_TYPE_AARUFORMAT:ok=sx_aaruformat_build(c);break;case XX_FILE_TYPE_ZISOFS:ok=sx_zisofs_build(c);break;default:return false;}
 return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxvi_finish(c);
}
#undef SXVI_ADD
#undef SXVI_TABLE
#undef SXVI_LIMIT
const sx_family sx_volumeimages_family={sx_volumeimages_supports,sx_volumeimages_build,sx_volumeimages_layouts,SX_COUNT(sx_volumeimages_layouts),sx_volumeimages_comment};
