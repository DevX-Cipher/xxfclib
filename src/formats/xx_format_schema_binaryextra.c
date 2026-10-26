/* SPDX-License-Identifier: MIT. Physical binary-container metadata. Scope: docs/data_struct_binaryextra_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_binaryextra.h"
static bool sxbx_metakit_comment(xx_data_struct_record*r){size_t n=0;const uint8_t*b=xx_var_get_bytes(&r->value,&n);if(!b||!n||n>9)return true;uint64_t v=0;for(size_t i=0;i<n;i++){if(((b[i]&128)!=0)!=(i+1==n))return xx_data_struct_record_set_comment(r,L"Invalid Metakit varint framing; encoded bytes preserved");v=(v<<7)|(b[i]&127);}bool hex=!xx_rt_wcscmp(r->name,L"column_offset");char a[40];wchar_t out[40];int z=xx_rt_snprintf(a,sizeof(a),hex?"0x%llX":"%llu",(unsigned long long)v);if(z<0||z>=40)return false;for(int i=0;i<=z;i++)out[i]=(unsigned char)a[i];xx_var_set_u64(&r->value,v);return xx_data_struct_record_set_display_value(r,out)&&xx_data_struct_record_set_comment(r,hex?L"Decoded Metakit varint; byte offset relative to the embedded Metakit datafile.":L"Decoded Metakit MSB-first seven-bit groups; high bit marks the final physical byte.");}
static const sx_layout *const sx_binaryextra_layouts[] = {
 &sxbx_clp_header,
 &sxbx_clp_record,
 &sxbx_lmd_header,
 &sxbx_lmd_record_offset,
 &sxbx_lmd_flags,
 &sxbx_lmd_name_length,
 &sxbx_lmd_optional_value,
 &sxbx_lmd_bitmap_size,
 &sxbx_lmd_block_header,
 &sxbx_vice_snapshot_header,
 &sxbx_vice_version_header,
 &sxbx_vice_module_header,
 &sxbx_mcap_magic,
 &sxbx_mcap_record_header,
 &sxbx_mcap_schema_id,
 &sxbx_mcap_channel_ids,
 &sxbx_mcap_message,
 &sxbx_mcap_attachment_times,
 &sxbx_mcap_footer,
 &sxbx_mcap_crc,
 &sxbx_mcap_map_size,
 &sxbx_mcap_string_size,
 &sxbx_mcap_data_size,
 &sxbx_mcap_attachment_size,
 &sxbx_regf_header,
 &sxbx_regf_checksum,
 &sxbx_regf_hbin,
 &sxbx_regf_cell,
 &sxbx_regf_nk,
 &sxbx_regf_sk,
 &sxbx_regf_list,
 &sxbx_regf_list_offset,
 &sxbx_regf_list_hash,
 &sxbx_regf_vk,
 &sxbx_regf_db,
 &sxbx_evtx_header,
 &sxbx_evtx_chunk,
 &sxbx_evtx_string_offset,
 &sxbx_evtx_template_offset,
 &sxbx_evtx_record,
 &sxbx_evtx_record_trailer,
 &sxbx_kafka_batch,
 &sxbx_kafka_attributes,
 &sxbx_kafka_record_size1,
 &sxbx_kafka_record_size2,
 &sxbx_kafka_record_size3,
 &sxbx_kafka_record_size4,
 &sxbx_kafka_record_size5,
 &sxbx_kafka_record_size6,
 &sxbx_kafka_record_size7,
 &sxbx_kafka_record_size8,
 &sxbx_kafka_record_size9,
 &sxbx_kafka_record_size10,
 &sxbx_kafka_timestamp_delta1,
 &sxbx_kafka_timestamp_delta2,
 &sxbx_kafka_timestamp_delta3,
 &sxbx_kafka_timestamp_delta4,
 &sxbx_kafka_timestamp_delta5,
 &sxbx_kafka_timestamp_delta6,
 &sxbx_kafka_timestamp_delta7,
 &sxbx_kafka_timestamp_delta8,
 &sxbx_kafka_timestamp_delta9,
 &sxbx_kafka_timestamp_delta10,
 &sxbx_kafka_offset_delta1,
 &sxbx_kafka_offset_delta2,
 &sxbx_kafka_offset_delta3,
 &sxbx_kafka_offset_delta4,
 &sxbx_kafka_offset_delta5,
 &sxbx_kafka_offset_delta6,
 &sxbx_kafka_offset_delta7,
 &sxbx_kafka_offset_delta8,
 &sxbx_kafka_offset_delta9,
 &sxbx_kafka_offset_delta10,
 &sxbx_kafka_nullable_size1,
 &sxbx_kafka_nullable_size2,
 &sxbx_kafka_nullable_size3,
 &sxbx_kafka_nullable_size4,
 &sxbx_kafka_nullable_size5,
 &sxbx_kafka_nullable_size6,
 &sxbx_kafka_nullable_size7,
 &sxbx_kafka_nullable_size8,
 &sxbx_kafka_nullable_size9,
 &sxbx_kafka_nullable_size10,
 &sxbx_kafka_header_count1,
 &sxbx_kafka_header_count2,
 &sxbx_kafka_header_count3,
 &sxbx_kafka_header_count4,
 &sxbx_kafka_header_count5,
 &sxbx_kafka_header_count6,
 &sxbx_kafka_header_count7,
 &sxbx_kafka_header_count8,
 &sxbx_kafka_header_count9,
 &sxbx_kafka_header_count10,
 &sxbx_kafka_header_key_size1,
 &sxbx_kafka_header_key_size2,
 &sxbx_kafka_header_key_size3,
 &sxbx_kafka_header_key_size4,
 &sxbx_kafka_header_key_size5,
 &sxbx_kafka_header_key_size6,
 &sxbx_kafka_header_key_size7,
 &sxbx_kafka_header_key_size8,
 &sxbx_kafka_header_key_size9,
 &sxbx_kafka_header_key_size10,
 &sxbx_capnp_segment_table,
 &sxbx_capnp_struct_pointer,
 &sxbx_capnp_list_pointer,
 &sxbx_capnp_composite_tag,
 &sxbx_capnp_null_pointer,
 &sxbx_acb_header,
 &sxbx_acb_string_length,
 &sxbx_acb_palette,
 &sxbx_acb_color_rgb,
 &sxbx_acb_color_cmyk,
 &sxbx_acb_color_lab,
 &sxbx_acb_trailer,
 &sxbx_keytab_header,
 &sxbx_keytab_entry_length,
 &sxbx_keytab_component_count,
 &sxbx_keytab_string_length,
 &sxbx_kerberos_name_type,
 &sxbx_keytab_key,
 &sxbx_keytab_extended_kvno,
 &sxbx_ccache_header,
 &sxbx_ccache_tag,
 &sxbx_ccache_time_offset,
 &sxbx_ccache_principal,
 &sxbx_ccache_blob_size,
 &sxbx_ccache_key,
 &sxbx_ccache_times_flags,
 &sxbx_ccache_list_count,
 &sxbx_ccache_typed_blob,
 &sxbx_jks_header,
 &sxbx_jks_entry_tag,
 &sxbx_jks_string_size,
 &sxbx_jks_timestamp,
 &sxbx_jks_blob_size,
 &sxbx_jks_certificate_count,
 &sxbx_jks_digest,
 &sxbx_gguf_header,
 &sxbx_gguf_string_size,
 &sxbx_gguf_value_type,
 &sxbx_gguf_array,
 &sxbx_gguf_value0,
 &sxbx_gguf_value1,
 &sxbx_gguf_value2,
 &sxbx_gguf_value3,
 &sxbx_gguf_value4,
 &sxbx_gguf_value5,
 &sxbx_gguf_value6,
 &sxbx_gguf_value7,
 &sxbx_gguf_value10,
 &sxbx_gguf_value11,
 &sxbx_gguf_value12,
 &sxbx_gguf_dimensions,
 &sxbx_gguf_dimension,
 &sxbx_gguf_tensor_storage,
 &sxbx_nvp_header,
 &sxbx_nvp_directory,
 &sxbx_nvp_record,
 &sxbx_nvp_jpeg_size,
 &sxbx_nvp_string_list,
 &sxbx_lbrcobol_title,
 &sxbx_lbrcobol_directory_header,
 &sxbx_lbrcobol_header_constants,
 &sxbx_lbrcobol_member,
 &sxbx_lbrcobol_member_tail,
 &sxbx_pyz_header_le,
 &sxbx_pyz_header_be,
 &sxbx_pyz_marshal_tag,
 &sxbx_pyz_marshal_int32,
 &sxbx_pyz_marshal_int64,
 &sxbx_pyz_marshal_length,
 &sxbx_pyz_marshal_count,
 &sxbx_pyz_marshal_short_count,
 &sxbx_pyz_marshal_short_length,
 &sxbx_pyz_marshal_reference,
 &sxbx_pyz_marshal_long_digits,
 &sxbx_pyz_marshal_digit,
 &sxbx_pyinstaller_cookie24,
 &sxbx_pyinstaller_library,
 &sxbx_pyinstaller_toc,
 &sxbx_starkit_header,
 &sxbx_starkit_commit,
 &sxbx_starkit_root_prefix,
 &sxbx_starkit_row_count1,
 &sxbx_starkit_row_count2,
 &sxbx_starkit_row_count3,
 &sxbx_starkit_row_count4,
 &sxbx_starkit_row_count5,
 &sxbx_starkit_row_count6,
 &sxbx_starkit_row_count7,
 &sxbx_starkit_row_count8,
 &sxbx_starkit_row_count9,
 &sxbx_starkit_column_size1,
 &sxbx_starkit_column_size2,
 &sxbx_starkit_column_size3,
 &sxbx_starkit_column_size4,
 &sxbx_starkit_column_size5,
 &sxbx_starkit_column_size6,
 &sxbx_starkit_column_size7,
 &sxbx_starkit_column_size8,
 &sxbx_starkit_column_size9,
 &sxbx_starkit_column_offset1,
 &sxbx_starkit_column_offset2,
 &sxbx_starkit_column_offset3,
 &sxbx_starkit_column_offset4,
 &sxbx_starkit_column_offset5,
 &sxbx_starkit_column_offset6,
 &sxbx_starkit_column_offset7,
 &sxbx_starkit_column_offset8,
 &sxbx_starkit_column_offset9,
 &sxbx_starkit_memo_row_delta1,
 &sxbx_starkit_memo_row_delta2,
 &sxbx_starkit_memo_row_delta3,
 &sxbx_starkit_memo_row_delta4,
 &sxbx_starkit_memo_row_delta5,
 &sxbx_starkit_memo_row_delta6,
 &sxbx_starkit_memo_row_delta7,
 &sxbx_starkit_memo_row_delta8,
 &sxbx_starkit_memo_row_delta9,
 &sxbx_starkit_view_tag1,
 &sxbx_starkit_view_tag2,
 &sxbx_starkit_view_tag3,
 &sxbx_starkit_view_tag4,
 &sxbx_starkit_view_tag5,
 &sxbx_starkit_view_tag6,
 &sxbx_starkit_view_tag7,
 &sxbx_starkit_view_tag8,
 &sxbx_starkit_view_tag9,
 &sxbx_evb_header,
 &sxbx_evb_table_prefix,
 &sxbx_evb_node,
 &sxbx_evb_node_type,
 &sxbx_evb_file_stored_size,
 &sxbx_gta_img_header,
 &sxbx_gta_img_entry,
 &sxbx_pam_pak_header,
 &sxbx_pam_pak_data,
 &sxbx_pam_pak_directory_marker,
 &sxbx_pam_pak_index,
 &sxbx_pfpk_header,
 &sxbx_pfpk_name_size,
 &sxbx_pfpk_member,
 &sxbx_pyz_marshal_offset32,
 &sxbx_pyz_marshal_size32,
 &sxbx_pyz_marshal_offset64,
 &sxbx_pyz_marshal_size64,
 &sxbx_evb_file_modern,
 &sxbx_evb_file_legacy,
 &sxbx_evb_chunk_header,
 &sxbx_evb_chunk_entry,
 &sxbx_evb_ap32,
};
static bool sx_binaryextra_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60300000U||id>=0x60310000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x603000b9U: return sxbx_metakit_comment(r);
 case 0x603000baU: return sxbx_metakit_comment(r);
 case 0x603000bbU: return sxbx_metakit_comment(r);
 case 0x603000bcU: return sxbx_metakit_comment(r);
 case 0x603000bdU: return sxbx_metakit_comment(r);
 case 0x603000beU: return sxbx_metakit_comment(r);
 case 0x603000bfU: return sxbx_metakit_comment(r);
 case 0x603000c0U: return sxbx_metakit_comment(r);
 case 0x603000c1U: return sxbx_metakit_comment(r);
 case 0x603000c2U: return sxbx_metakit_comment(r);
 case 0x603000c3U: return sxbx_metakit_comment(r);
 case 0x603000c4U: return sxbx_metakit_comment(r);
 case 0x603000c5U: return sxbx_metakit_comment(r);
 case 0x603000c6U: return sxbx_metakit_comment(r);
 case 0x603000c7U: return sxbx_metakit_comment(r);
 case 0x603000c8U: return sxbx_metakit_comment(r);
 case 0x603000c9U: return sxbx_metakit_comment(r);
 case 0x603000caU: return sxbx_metakit_comment(r);
 case 0x603000cbU: return sxbx_metakit_comment(r);
 case 0x603000ccU: return sxbx_metakit_comment(r);
 case 0x603000cdU: return sxbx_metakit_comment(r);
 case 0x603000ceU: return sxbx_metakit_comment(r);
 case 0x603000cfU: return sxbx_metakit_comment(r);
 case 0x603000d0U: return sxbx_metakit_comment(r);
 case 0x603000d1U: return sxbx_metakit_comment(r);
 case 0x603000d2U: return sxbx_metakit_comment(r);
 case 0x603000d3U: return sxbx_metakit_comment(r);
 case 0x603000d4U: return sxbx_metakit_comment(r);
 case 0x603000d5U: return sxbx_metakit_comment(r);
 case 0x603000d6U: return sxbx_metakit_comment(r);
 case 0x603000d7U: return sxbx_metakit_comment(r);
 case 0x603000d8U: return sxbx_metakit_comment(r);
 case 0x603000d9U: return sxbx_metakit_comment(r);
 case 0x603000daU: return sxbx_metakit_comment(r);
 case 0x603000dbU: return sxbx_metakit_comment(r);
 case 0x603000dcU: return sxbx_metakit_comment(r);
 case 0x603000ddU: return sxbx_metakit_comment(r);
 case 0x603000deU: return sxbx_metakit_comment(r);
 case 0x603000dfU: return sxbx_metakit_comment(r);
 case 0x603000e0U: return sxbx_metakit_comment(r);
 case 0x603000e1U: return sxbx_metakit_comment(r);
 case 0x603000e2U: return sxbx_metakit_comment(r);
 case 0x603000e3U: return sxbx_metakit_comment(r);
 case 0x603000e4U: return sxbx_metakit_comment(r);
 case 0x603000e5U: return sxbx_metakit_comment(r);
 case 0x60300002U:
 if(!xx_rt_wcscmp(r->name,L"format_name_or_reserved"))text=L"Physical 79-byte record tail; encoding and meaning vary by clipboard writer.";
 break;
 case 0x60300005U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0 compressed bitmap; bit1 name present; bit2 optional value present; bit3 bitmap record.";
 break;
 case 0x60300009U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Byte count after this four-byte length, including the method byte.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x80 stored bytes; 0x40 encoded LMD bitmap block.";
 break;
 case 0x6030000cU:
 if(!xx_rt_wcscmp(r->name,L"module_size"))text=L"Includes the 22-byte module header.";
 break;
 case 0x60300011U:
 if(!xx_rt_wcscmp(r->name,L"log_time"))text=L"Nanoseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"publish_time"))text=L"Nanoseconds since Unix epoch.";
 break;
 case 0x60300012U:
 if(!xx_rt_wcscmp(r->name,L"log_time"))text=L"Nanoseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"create_time"))text=L"Nanoseconds since Unix epoch.";
 break;
 case 0x60300019U:
 if(!xx_rt_wcscmp(r->name,L"last_written"))text=L"Windows FILETIME, 100-nanosecond intervals since 1601 UTC.";
 if(!xx_rt_wcscmp(r->name,L"root_cell_offset"))text=L"Relative to the hive-bin data area at file offset 0x1000.";
 if(!xx_rt_wcscmp(r->name,L"clustering_factor"))text=L"Underlying logical sector size divided by 512.";
 if(!xx_rt_wcscmp(r->name,L"filename"))text=L"Physical UTF-16LE filename fragment; not necessarily terminated.";
 break;
 case 0x6030001bU:
 if(!xx_rt_wcscmp(r->name,L"bin_offset"))text=L"Relative to the hive-bin data area at file offset 0x1000.";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Optional FILETIME in the first bin; later bins may contain stale data.";
 break;
 case 0x6030001cU:
 if(!xx_rt_wcscmp(r->name,L"signed_cell_size"))text=L"Absolute magnitude is the total cell byte count; negative means allocated and positive means free.";
 break;
 case 0x6030001dU:
 if(!xx_rt_wcscmp(r->name,L"parent_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"subkey_list_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"volatile_list_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"values_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"security_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"class_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 break;
 case 0x60300020U:
 if(!xx_rt_wcscmp(r->name,L"cell_offset"))text=L"Relative to the hive-bin data area.";
 break;
 case 0x60300021U:
 if(!xx_rt_wcscmp(r->name,L"cell_offset"))text=L"Relative to the hive-bin data area.";
 if(!xx_rt_wcscmp(r->name,L"name_hash_or_hint"))text=L"lh: name hash; lf: first four compressed-name bytes.";
 break;
 case 0x60300022U:
 if(!xx_rt_wcscmp(r->name,L"data_size_flags"))text=L"High bit selects inline data; low 31 bits are the encoded byte count.";
 if(!xx_rt_wcscmp(r->name,L"data_offset_or_inline"))text=L"Hive-bin-relative cell offset, or up to four inline data bytes when data_size_flags has bit31 set.";
 break;
 case 0x60300025U:
 if(!xx_rt_wcscmp(r->name,L"last_record_offset"))text=L"Relative to this chunk.";
 if(!xx_rt_wcscmp(r->name,L"free_space_offset"))text=L"Relative to this chunk.";
 break;
 case 0x60300026U:
 if(!xx_rt_wcscmp(r->name,L"string_offset"))text=L"Relative to this chunk; zero means unused.";
 break;
 case 0x60300027U:
 if(!xx_rt_wcscmp(r->name,L"template_offset"))text=L"Relative to this chunk; zero means unused.";
 break;
 case 0x60300028U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Windows FILETIME, 100-nanosecond intervals since 1601 UTC.";
 break;
 case 0x6030002aU:
 if(!xx_rt_wcscmp(r->name,L"base_offset"))text=L"Logical Kafka log offset, not a physical byte offset.";
 if(!xx_rt_wcscmp(r->name,L"batch_length"))text=L"Bytes after the first 12 bytes of this batch.";
 if(!xx_rt_wcscmp(r->name,L"last_offset_delta"))text=L"Logical record-offset delta, not a byte offset.";
 if(!xx_rt_wcscmp(r->name,L"base_timestamp"))text=L"Milliseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"max_timestamp"))text=L"Milliseconds since Unix epoch.";
 break;
 case 0x6030002cU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002dU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002eU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002fU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300030U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300031U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300032U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300033U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300034U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300035U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300036U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300037U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300038U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300039U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003aU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003bU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003cU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003dU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003eU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003fU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300040U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300041U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300042U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300043U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300044U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300045U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300046U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300047U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300048U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300049U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x6030004aU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004bU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004cU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004dU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004eU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004fU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300050U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300051U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300052U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300053U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300054U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300055U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300056U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300057U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300058U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300059U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005aU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005bU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005cU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005dU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005eU:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x6030005fU:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300060U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300061U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300062U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300063U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300064U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300065U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300066U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300067U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300068U:
 if(!xx_rt_wcscmp(r->name,L"segment_count_minus_one"))text=L"Stored segment count minus one. Native reader supports one unpacked segment.";
 if(!xx_rt_wcscmp(r->name,L"segment_words"))text=L"Number of 64-bit words in the segment.";
 break;
 case 0x60300069U:
 if(!xx_rt_wcscmp(r->name,L"offset_and_kind"))text=L"Low2bits=0; upper30bits are a signed word displacement from the word after this pointer.";
 if(!xx_rt_wcscmp(r->name,L"data_word_count"))text=L"Number of 64-bit words in the struct data section.";
 break;
 case 0x6030006aU:
 if(!xx_rt_wcscmp(r->name,L"offset_and_kind"))text=L"Low2bits=1; upper30bits are a signed word displacement.";
 if(!xx_rt_wcscmp(r->name,L"count_and_element_size"))text=L"Low3bits are element-size code; upper29bits are element count, or word count for inline-composite lists.";
 break;
 case 0x6030006bU:
 if(!xx_rt_wcscmp(r->name,L"element_count_and_kind"))text=L"Low2bits=0; upper30bits are the element count.";
 break;
 case 0x6030006fU:
 if(!xx_rt_wcscmp(r->name,L"color_space"))text=L"0 RGB; 2 CMYK; 7 Lab.";
 break;
 case 0x60300070U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300071U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300072U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300075U:
 if(!xx_rt_wcscmp(r->name,L"signed_entry_size"))text=L"Positive: entry byte count after this word; negative: deleted slot of the absolute byte count; zero: end marker.";
 break;
 case 0x60300079U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Seconds since Unix epoch.";
 break;
 case 0x60300081U:
 if(!xx_rt_wcscmp(r->name,L"auth_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"start_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"end_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"renew_until"))text=L"Seconds since Unix epoch.";
 break;
 case 0x60300085U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"1 private key with certificate chain; 2 trusted certificate.";
 break;
 case 0x60300087U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Signed Java long: milliseconds since Unix epoch.";
 break;
 case 0x6030009cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the aligned tensor-data area, not the start of the file.";
 break;
 case 0x6030009fU:
 if(!xx_rt_wcscmp(r->name,L"size_and_flags"))text=L"Low31bits are record payload byte count; top bit is preserved as an encoded flag.";
 break;
 case 0x603000a3U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Encoded block size; native payload coordinates use 128-byte blocks.";
 break;
 case 0x603000a5U:
 if(!xx_rt_wcscmp(r->name,L"payload_block"))text=L"Multiply by 128 for the file-relative byte offset.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 break;
 case 0x603000a9U:
 if(!xx_rt_wcscmp(r->name,L"type_and_reference"))text=L"Low7bits are the Python marshal type code; highbit reserves a reference slot.";
 break;
 case 0x603000b3U:
 if(!xx_rt_wcscmp(r->name,L"toc_offset"))text=L"Relative to the package start, derived from the cookie end minus package_size.";
 break;
 case 0x603000b5U:
 if(!xx_rt_wcscmp(r->name,L"entry_size"))text=L"Includes this fixed18-byte prefix and padded NUL-terminated name.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the CArchive package start.";
 break;
 case 0x603000b7U:
 if(!xx_rt_wcscmp(r->name,L"footer_offset"))text=L"Relative to the embedded Metakit container.";
 if(!xx_rt_wcscmp(r->name,L"root_size_and_tag"))text=L"Highbit is the commit tag; low31bits are the root descriptor byte count.";
 if(!xx_rt_wcscmp(r->name,L"root_offset"))text=L"Relative to the embedded Metakit container.";
 break;
 case 0x603000b8U:
 if(!xx_rt_wcscmp(r->name,L"schema_size_and_tag"))text=L"Highbit terminates this encoded length; low7bits are schema string size.";
 break;
 case 0x603000e9U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"2 file; 3 directory.";
 break;
 case 0x603000ecU:
 if(!xx_rt_wcscmp(r->name,L"sector_offset"))text=L"Multiply by 2048 for the file-relative byte offset.";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 2048-byte sectors.";
 break;
 case 0x603000efU:
 if(!xx_rt_wcscmp(r->name,L"size_marker"))text=L"0xC0000000 marks a directory; not a byte size.";
 if(!xx_rt_wcscmp(r->name,L"offset_marker"))text=L"0xFFFFFFFF marks a directory; not a file offset.";
 break;
 case 0x603000f0U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string table after both entry arrays.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXBX_LIMIT 20000U
bool sxbx_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxbx_read(sx_context *c,uint64_t p,void *b,size_t n){return sxbx_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxbx_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint32_t sxbx32(const uint8_t *b,bool be){return (uint32_t)sxbx_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
bool sxbx_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
bool sxbx_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxbx_span(c,p,n))return false;if(!sxbx_free(c,p,n))return true;return c->count>=SXBX_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxbx_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXBX_LIMIT||!sxbx_span(c,p,n*z))return true;if(!sxbx_free(c,p,n*z))return true;return c->count>=SXBX_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sxbx_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxbx_read(c,p,b,n))return false;*v=sxbx_uint(b,n,be);return true;}
bool sxbx_counted(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,unsigned width,bool be,unsigned multiplier){uint64_t z;if(*p>end||width>end-*p||!sxbx_word(c,*p,width,be,&z)||z>(end-*p-width)/multiplier||!sxbx_add(c,l,*p))return false;*p+=width+z*multiplier;return true;}
bool sxbx_zero_string(sx_context*c,uint64_t*p,uint64_t end,unsigned width){for(unsigned i=0;i<4096;i++){uint64_t v;if(*p>end||width>end-*p||!sxbx_word(c,*p,width,false,&v))return false;*p+=width;if(!v)return true;}return false;}
static int sxbx_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxbx_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxbx_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxbx_order);return !c->failed;}
static bool sx_binaryextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_CLP:case XX_FILE_TYPE_LMD_CONTAINER:case XX_FILE_TYPE_VICE_SNAPSHOT:case XX_FILE_TYPE_MCAP:case XX_FILE_TYPE_WINDOWS_REGISTRY_HIVE:case XX_FILE_TYPE_WINDOWS_EVTX:case XX_FILE_TYPE_KAFKA_RECORD_BATCH:case XX_FILE_TYPE_CAPNPROTO_MESSAGE:case XX_FILE_TYPE_ADOBE_ACB:case XX_FILE_TYPE_KERBEROS_KEYTAB:case XX_FILE_TYPE_KERBEROS_CCACHE:case XX_FILE_TYPE_JKS_KEYSTORE:case XX_FILE_TYPE_GGUF:case XX_FILE_TYPE_NVP:case XX_FILE_TYPE_LBRCOBOL:case XX_FILE_TYPE_PYZ:case XX_FILE_TYPE_PYINSTALLER_ONE_EXECUTABLE:case XX_FILE_TYPE_STARKIT:case XX_FILE_TYPE_ENIGMA_VIRTUAL_BOX:case XX_FILE_TYPE_GTA_IMG:case XX_FILE_TYPE_PAM_PAK:case XX_FILE_TYPE_PFPK:return true;default:return false;}}
static bool sx_binaryextra_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_CLP:ok=sx_clp_build(c);break;
case XX_FILE_TYPE_LMD_CONTAINER:ok=sx_lmd_container_build(c);break;
case XX_FILE_TYPE_VICE_SNAPSHOT:ok=sx_vice_snapshot_build(c);break;
case XX_FILE_TYPE_MCAP:ok=sx_mcap_build(c);break;
case XX_FILE_TYPE_WINDOWS_REGISTRY_HIVE:ok=sx_windows_registry_hive_build(c);break;
case XX_FILE_TYPE_WINDOWS_EVTX:ok=sx_windows_evtx_build(c);break;
case XX_FILE_TYPE_KAFKA_RECORD_BATCH:ok=sx_kafka_record_batch_build(c);break;
case XX_FILE_TYPE_CAPNPROTO_MESSAGE:ok=sx_capnproto_message_build(c);break;
case XX_FILE_TYPE_ADOBE_ACB:ok=sx_adobe_acb_build(c);break;
case XX_FILE_TYPE_KERBEROS_KEYTAB:ok=sx_kerberos_keytab_build(c);break;
case XX_FILE_TYPE_KERBEROS_CCACHE:ok=sx_kerberos_ccache_build(c);break;
case XX_FILE_TYPE_JKS_KEYSTORE:ok=sx_jks_keystore_build(c);break;
case XX_FILE_TYPE_GGUF:ok=sx_gguf_build(c);break;
case XX_FILE_TYPE_NVP:ok=sx_nvp_build(c);break;
case XX_FILE_TYPE_LBRCOBOL:ok=sx_lbrcobol_build(c);break;
case XX_FILE_TYPE_PYZ:ok=sx_pyz_build(c);break;
case XX_FILE_TYPE_PYINSTALLER_ONE_EXECUTABLE:ok=sx_pyinstaller_one_executable_build(c);break;
case XX_FILE_TYPE_STARKIT:ok=sx_starkit_build(c);break;
case XX_FILE_TYPE_ENIGMA_VIRTUAL_BOX:ok=sx_enigma_virtual_box_build(c);break;
case XX_FILE_TYPE_GTA_IMG:ok=sx_gta_img_build(c);break;
case XX_FILE_TYPE_PAM_PAK:ok=sx_pam_pak_build(c);break;
case XX_FILE_TYPE_PFPK:ok=sx_pfpk_build(c);break;
default:break;}return ok&&sxbx_finish(c);}
const sx_family sx_binaryextra_family={sx_binaryextra_supports,sx_binaryextra_build,sx_binaryextra_layouts,SX_COUNT(sx_binaryextra_layouts),sx_binaryextra_comment};
