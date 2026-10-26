/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical storage and audiovisual schemas. Scope and wire references are
 * documented in docs/data_struct_storage_scope.txt. Encoded payloads remain raw.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_storage.h"
static const xx_data_struct_field_desc sx_st_caf_chunk_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("size", "int64", 4, 8, SX_NONE),
};
const sx_layout sx_st_caf_chunk = {0x60080004U, "caf_chunk", sx_st_caf_chunk_fields, SX_COUNT(sx_st_caf_chunk_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_ivf_frame_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("timestamp", "uint64", 4, 8, SX_NONE),
};
const sx_layout sx_st_ivf_frame = {0x6008002AU, "ivf_frame", sx_st_ivf_frame_fields, SX_COUNT(sx_st_ivf_frame_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_qcow1_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("mtime", "uint32", 20, 4, SX_TIME),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("cluster_bits", "uint8", 32, 1, SX_NONE),
    SX_FIELD("l2_bits", "uint8", 33, 1, SX_NONE),
    SX_FIELD("padding", "uint16", 34, 2, SX_RESERVED),
    SX_FIELD("crypt_method", "uint32", 36, 4, SX_ID),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_header = {0x60080049U, "qcow1_header", sx_st_qcow1_header_fields, SX_COUNT(sx_st_qcow1_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow2_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("cluster_bits", "uint32", 20, 4, SX_NONE),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("crypt_method", "uint32", 32, 4, SX_ID),
    SX_FIELD("l1_size", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("refcount_table_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("refcount_table_clusters", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint32", 60, 4, SX_COUNT_PROP),
    SX_FIELD("snapshots_offset", "uint64", 64, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow2_header = {0x6008004AU, "qcow2_header", sx_st_qcow2_header_fields, SX_COUNT(sx_st_qcow2_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow3_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("backing_file_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("backing_file_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("cluster_bits", "uint32", 20, 4, SX_NONE),
    SX_FIELD("virtual_size", "uint64", 24, 8, SX_SIZE),
    SX_FIELD("crypt_method", "uint32", 32, 4, SX_ID),
    SX_FIELD("l1_size", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("l1_table_offset", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("refcount_table_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("refcount_table_clusters", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint32", 60, 4, SX_COUNT_PROP),
    SX_FIELD("snapshots_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("incompatible_features", "uint64", 72, 8, SX_FLAGS),
    SX_FIELD("compatible_features", "uint64", 80, 8, SX_FLAGS),
    SX_FIELD("autoclear_features", "uint64", 88, 8, SX_FLAGS),
    SX_FIELD("refcount_order", "uint32", 96, 4, SX_NONE),
    SX_FIELD("header_length", "uint32", 100, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow3_header = {0x6008004BU, "qcow3_header", sx_st_qcow3_header_fields, SX_COUNT(sx_st_qcow3_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_compression_fields[] = {
    SX_FIELD("compression_type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_st_qcow_compression = {0x6008004CU, "qcow_compression", sx_st_qcow_compression_fields, SX_COUNT(sx_st_qcow_compression_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_extension_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_ID),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow_extension = {0x6008004DU, "qcow_extension", sx_st_qcow_extension_fields, SX_COUNT(sx_st_qcow_extension_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_crypto_extension_fields[] = {
    SX_FIELD("header_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("header_size", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_st_qcow_crypto_extension = {0x6008004EU, "qcow_crypto_extension", sx_st_qcow_crypto_extension_fields, SX_COUNT(sx_st_qcow_crypto_extension_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_l1_entry_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_l1_entry = {0x6008004FU, "qcow_l1_entry", sx_st_qcow_l1_entry_fields, SX_COUNT(sx_st_qcow_l1_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_l2_entry_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_l2_entry = {0x60080050U, "qcow_l2_entry", sx_st_qcow_l2_entry_fields, SX_COUNT(sx_st_qcow_l2_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_l2_extended_fields[] = {
    SX_FIELD("offset_and_flags", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("subcluster_zero_bitmap", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("subcluster_allocation_bitmap", "uint32", 12, 4, SX_FLAGS),
};
static const sx_layout sx_st_qcow_l2_extended = {0x60080051U, "qcow_l2_extended", sx_st_qcow_l2_extended_fields, SX_COUNT(sx_st_qcow_l2_extended_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow1_l1_entry_fields[] = {
    SX_FIELD("l2_table_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_l1_entry = {0x60080052U, "qcow1_l1_entry", sx_st_qcow1_l1_entry_fields, SX_COUNT(sx_st_qcow1_l1_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow1_l2_entry_fields[] = {
    SX_FIELD("offset_and_compressed_flag", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow1_l2_entry = {0x60080053U, "qcow1_l2_entry", sx_st_qcow1_l2_entry_fields, SX_COUNT(sx_st_qcow1_l2_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_refcount_pointer_fields[] = {
    SX_FIELD("block_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_st_qcow_refcount_pointer = {0x60080054U, "qcow_refcount_pointer", sx_st_qcow_refcount_pointer_fields, SX_COUNT(sx_st_qcow_refcount_pointer_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_qcow_snapshot_fields[] = {
    SX_FIELD("l1_table_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("l1_size", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("id_string_size", "uint16", 12, 2, SX_SIZE),
    SX_FIELD("name_size", "uint16", 14, 2, SX_SIZE),
    SX_FIELD("date_seconds", "uint32", 16, 4, SX_TIME),
    SX_FIELD("date_nanoseconds", "uint32", 20, 4, SX_NONE),
    SX_FIELD("vm_clock_nanoseconds", "uint64", 24, 8, SX_NONE),
    SX_FIELD("vm_state_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("extra_data_size", "uint32", 36, 4, SX_SIZE),
};
static const sx_layout sx_st_qcow_snapshot = {0x60080055U, "qcow_snapshot", sx_st_qcow_snapshot_fields, SX_COUNT(sx_st_qcow_snapshot_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_luks1_header_fields[] = {
    SX_FIELD("magic", "byte[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("cipher_name", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("cipher_mode", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("hash_spec", "char[32]", 72, 32, SX_STRING),
    SX_FIELD("payload_sector", "uint32", 104, 4, SX_OFFSET),
    SX_FIELD("key_bytes", "uint32", 108, 4, SX_SIZE),
    SX_FIELD("master_key_digest", "byte[20]", 112, 20, SX_CHECKSUM),
    SX_FIELD("master_key_salt", "byte[32]", 132, 32, SX_NONE),
    SX_FIELD("master_key_iterations", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("uuid", "char[40]", 168, 40, SX_STRING),
};
const sx_layout sx_st_luks1_header = {0x60080056U, "luks1_header", sx_st_luks1_header_fields, SX_COUNT(sx_st_luks1_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_luks1_keyslot_fields[] = {
    SX_FIELD("active", "uint32", 0, 4, SX_ID),
    SX_FIELD("iterations", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("salt", "byte[32]", 8, 32, SX_NONE),
    SX_FIELD("key_material_sector", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("stripes", "uint32", 44, 4, SX_COUNT_PROP),
};
const sx_layout sx_st_luks1_keyslot = {0x60080057U, "luks1_keyslot", sx_st_luks1_keyslot_fields, SX_COUNT(sx_st_luks1_keyslot_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_cramfs_inode_be_fields[] = {
    SX_FIELD("mode_uid", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size_gid", "uint32", 4, 4, SX_NONE),
    SX_FIELD("name_length_and_offset", "uint32", 8, 4, SX_OFFSET),
};
const sx_layout sx_st_cramfs_inode_be = {0x6008005FU, "cramfs_inode_be", sx_st_cramfs_inode_be_fields, SX_COUNT(sx_st_cramfs_inode_be_fields), SX_BE};
static const sx_layout *const sx_storage_layouts[] = {
    &sx_st_midi_header,
    &sx_st_midi_track,
    &sx_st_caf_header,
    &sx_st_caf_chunk,
    &sx_st_caf_description,
    &sx_st_caf_data,
    &sx_st_caf_packet_table,
    &sx_st_voc_header,
    &sx_st_voc_block,
    &sx_st_voc_terminator,
    &sx_st_voc_sound,
    &sx_st_voc_silence,
    &sx_st_voc_marker,
    &sx_st_voc_repeat,
    &sx_st_voc_sound_v2,
    &sx_st_vag_header,
    &sx_st_vag_adpcm_frame,
    &sx_st_psf_header,
    &sx_st_dsf_header,
    &sx_st_dsf_format,
    &sx_st_dsf_data,
    &sx_st_dff_form,
    &sx_st_dff_chunk,
    &sx_st_dff_version,
    &sx_st_dff_property,
    &sx_st_dff_frequency,
    &sx_st_dff_channels,
    &sx_st_dff_channel,
    &sx_st_dff_compression,
    &sx_st_wave64_header,
    &sx_st_wave64_chunk,
    &sx_st_wave64_format,
    &sx_st_wave64_format_extra,
    &sx_st_adx_header,
    &sx_st_adx_terminator,
    &sx_st_wavpack_block,
    &sx_st_wavpack_metadata,
    &sx_st_wavpack_metadata_large,
    &sx_st_apev2_tag,
    &sx_st_apev2_item,
    &sx_st_ivf_header,
    &sx_st_ivf_frame,
    &sx_st_roq_header,
    &sx_st_roq_chunk,
    &sx_st_roq_info,
    &sx_st_roq_codebook_cell,
    &sx_st_roq_codebook_quad,
    &sx_st_flv_header,
    &sx_st_flv_previous_tag,
    &sx_st_flv_tag,
    &sx_st_flv_audio,
    &sx_st_flv_aac_audio,
    &sx_st_flv_video,
    &sx_st_flv_avc_video,
    &sx_st_bink_header,
    &sx_st_bink_audio_maximum,
    &sx_st_bink_audio_format,
    &sx_st_bink_audio_id,
    &sx_st_bink_frame_index,
    &sx_st_bink_end_offset,
    &sx_st_bink_audio_packet,
    &sx_st_bink_audio_decoded,
    &sx_st_smacker_header,
    &sx_st_smacker_frame_size,
    &sx_st_smacker_frame_type,
    &sx_st_smacker_audio_packet,
    &sx_st_smacker_audio_decoded,
    &sx_st_smacker_palette,
    &sx_st_fli_header,
    &sx_st_flc_header,
    &sx_st_flic_chunk,
    &sx_st_flic_frame,
    &sx_st_qcow1_header,
    &sx_st_qcow2_header,
    &sx_st_qcow3_header,
    &sx_st_qcow_compression,
    &sx_st_qcow_extension,
    &sx_st_qcow_crypto_extension,
    &sx_st_qcow_l1_entry,
    &sx_st_qcow_l2_entry,
    &sx_st_qcow_l2_extended,
    &sx_st_qcow1_l1_entry,
    &sx_st_qcow1_l2_entry,
    &sx_st_qcow_refcount_pointer,
    &sx_st_qcow_snapshot,
    &sx_st_luks1_header,
    &sx_st_luks1_keyslot,
    &sx_st_luks2_header,
    &sx_st_romfs_superblock,
    &sx_st_romfs_inode,
    &sx_st_cramfs_superblock_le,
    &sx_st_cramfs_inode_le,
    &sx_st_cramfs_block_pointer_le,
    &sx_st_cramfs_superblock_be,
    &sx_st_cramfs_inode_be,
    &sx_st_cramfs_block_pointer_be,
};
/* Physical records only; native readers establish validity, while this walker
 * independently bounds every field and pointed-to table. Codec streams, names,
 * JSON and unsupported/over-budget metadata stay explicitly RAW_DATA. */
static bool sx_storage_supports(xx_file_type_t t)
{
    switch(t) {
    case XX_FILE_TYPE_MIDI: case XX_FILE_TYPE_CAF: case XX_FILE_TYPE_CREATIVE_VOC:
    case XX_FILE_TYPE_SONY_VAG: case XX_FILE_TYPE_SONY_PSF: case XX_FILE_TYPE_AUDIO_DSF:
    case XX_FILE_TYPE_AUDIO_DFF: case XX_FILE_TYPE_AUDIO_WAVE64: case XX_FILE_TYPE_AUDIO_ADX:
    case XX_FILE_TYPE_AUDIO_WAVPACK: case XX_FILE_TYPE_IVF: case XX_FILE_TYPE_IDTECH_ROQ:
    case XX_FILE_TYPE_FLASH_VIDEO_FLV: case XX_FILE_TYPE_RAD_BINK: case XX_FILE_TYPE_RAD_SMACKER:
    case XX_FILE_TYPE_AUTODESK_FLIC: case XX_FILE_TYPE_QCOW: case XX_FILE_TYPE_QCOW1:
    case XX_FILE_TYPE_LUKS: case XX_FILE_TYPE_ROMFS: case XX_FILE_TYPE_CRAMFS:return true;
    default:return false;
    }
}
bool sx_st_fits(const sx_context *c,uint64_t o,uint64_t n)
{return c&&c->size>=0&&o<=(uint64_t)c->size&&n<=(uint64_t)c->size-o;}
static void sx_st_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++) {
        xx_data_struct item=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=item;
    }
}
bool sx_st_finish(sx_context *c)
{
    int64_t end=0;size_t n=c->count;sx_st_sort(c);
    for(size_t i=0;i<n;i++) {
        int64_t off=c->items[i].offset-c->f->base_address;
        if(off<end)return false;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        end=off+c->items[i].total_size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_st_sort(c);return !c->failed;
}
/* Pointer graphs may alias, cycle or intersect other metadata. Only nonoverlapping
 * physical regions become structures; a rejected candidate is retained as raw. */
bool sx_st_free(sx_context *c,uint64_t o,uint64_t n)
{
    if(!sx_st_fits(c,o,n)||c->count>=20000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t x=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(o<x+z&&x<o+n)return false;
    }
    return true;
}
static bool sx_st_qcow_l1(sx_context *c,uint64_t at,uint64_t count,uint32_t bits,uint32_t l2bits,bool v1,bool extended)
{
    uint64_t l2bytes=UINT64_C(8)<<l2bits;
    if(count>1048576||(!v1&&(at&((UINT64_C(1)<<bits)-1)))||!sx_st_free(c,at,count*8))return true;
    if(!sx_table(c,v1?&sx_st_qcow1_l1_entry:&sx_st_qcow_l1_entry,(int64_t)at,8,count))return false;
    /* Large tables retain all L1 physical entries. Follow at most 8192 L2
     * pointers so an adversarial sparse image cannot monopolize traversal. */
    for(uint64_t j=0;j<count&&j<8192;j++) {
        uint64_t entry;if(!sx_u64(c,(int64_t)(at+j*8),true,&entry))return false;
        uint64_t p=v1?entry:(entry&UINT64_C(0x00fffffffffffe00));
        uint64_t bytes=v1?l2bytes:(UINT64_C(1)<<bits);
        if(!p||!sx_st_free(c,p,bytes))continue;
        if(!sx_table(c,v1?&sx_st_qcow1_l2_entry:extended?&sx_st_qcow_l2_extended:&sx_st_qcow_l2_entry,(int64_t)p,extended?16:8,bytes/(extended?16:8)))return false;
    }
    return true;
}
bool sx_st_qcow(sx_context *c,bool v1)
{
    uint8_t h[104];uint32_t version,bits,l2bits,l1count=0;uint64_t l1,size,cluster;bool extended=false;
    if(!sx_read(c,0,h,v1?48:72))return false;version=xx_data_get_u32(h,104,4,true);size=xx_data_get_u64(h,104,24,true);
    if(v1) {
        bits=h[32];l2bits=h[33];l1=xx_data_get_u64(h,104,40,true);
        if(bits<9||bits>16||l2bits<6||l2bits>13||!sx_add(c,&sx_st_qcow1_header,0,48))return false;
        uint64_t per=UINT64_C(1)<<(bits+l2bits),count=size/per+(size%per!=0);
        return sx_st_qcow_l1(c,l1,count,bits,l2bits,true,false);
    }
    bits=xx_data_get_u32(h,104,20,true);if(bits<9||bits>21)return false;cluster=UINT64_C(1)<<bits;
    l1count=xx_data_get_u32(h,104,36,true);l1=xx_data_get_u64(h,104,40,true);
    uint64_t header=72,backing=xx_data_get_u64(h,104,8,true),ext_end=backing?backing:cluster;
    if(version==3) {
        if(!sx_read(c,0,h,104)||!sx_add(c,&sx_st_qcow3_header,0,104))return false;
        header=xx_data_get_u32(h,104,100,true);extended=(xx_data_get_u64(h,104,72,true)&16)!=0;
        if(header<104||header>cluster)return false;
        if(header>104&&sx_st_fits(c,104,1)&&!sx_add(c,&sx_st_qcow_compression,104,1))return false;
    } else if(version!=2||!sx_add(c,&sx_st_qcow2_header,0,72))return false;
    /* Extensions are framed only within the first cluster before any backing
     * name. Unknown extension payloads and future header bytes remain raw. */
    if(ext_end<=cluster&&ext_end<=(uint64_t)c->size&&header<=ext_end)for(unsigned i=0;i<4096&&ext_end-header>=8;i++) {
        uint32_t type,n;if(!sx_u32(c,(int64_t)header,true,&type)||!sx_u32(c,(int64_t)header+4,true,&n))return false;
        if((uint64_t)n>ext_end-header-8)break;
        if(!sx_add(c,&sx_st_qcow_extension,(int64_t)header,8))return false;header+=8;
        if(!type)break;
        if(type==0x0537be77U&&n==16) {
            uint64_t off,len;uint8_t magic[8];
            if(!sx_add(c,&sx_st_qcow_crypto_extension,(int64_t)header,16)||!sx_u64(c,(int64_t)header,true,&off)||!sx_u64(c,(int64_t)header+8,true,&len))return false;
            if(len>=592&&sx_st_fits(c,off,len)&&sx_st_free(c,off,592)) {
                if(!sx_read(c,(int64_t)off,magic,8))return false;
                if(!xx_rt_memcmp(magic,"LUKS\xba\xbe\0\1",8)&&(!sx_add(c,&sx_st_luks1_header,(int64_t)off,208)||!sx_table(c,&sx_st_luks1_keyslot,(int64_t)off+208,48,8)))return false;
            }
        }
        header+=n;if(header>UINT64_MAX-7)return false;header=(header+7)&~UINT64_C(7);
    }
    l2bits=bits-(extended?4:3);
    /* Reserve the refcount pointer array before L2 traversal to avoid aliasing
     * declared allocation metadata into another structure family. */
    uint64_t rc=xx_data_get_u64(h,104,48,true),rcc=xx_data_get_u32(h,104,56,true);
    if(rcc<=UINT64_MAX/cluster&&rcc*cluster<=UINT64_C(64)*1024*1024&&sx_st_free(c,rc,rcc*cluster)&&!sx_table(c,&sx_st_qcow_refcount_pointer,(int64_t)rc,8,rcc*cluster/8))return false;
    if(!sx_st_qcow_l1(c,l1,l1count,bits,l2bits,false,extended))return false;
    uint32_t count=xx_data_get_u32(h,104,60,true);uint64_t at=xx_data_get_u64(h,104,64,true);
    for(uint32_t j=0;j<count&&j<4096;j++) {
        uint8_t sh[40];uint64_t n;
        if(!sx_st_free(c,at,40))break;if(!sx_read(c,(int64_t)at,sh,40))return false;
        n=40+(uint64_t)xx_data_get_u32(sh,40,36,true)+xx_data_get_u16(sh,40,12,true)+xx_data_get_u16(sh,40,14,true);
        if(!sx_st_free(c,at,n))break;if(!sx_add(c,&sx_st_qcow_snapshot,(int64_t)at,40))return false;
        /* Snapshot variable extra-data and names are raw. Their own L1 tables
         * are followed with the same physical bounds as the active image. */
        if(!sx_st_qcow_l1(c,xx_data_get_u64(sh,40,0,true),xx_data_get_u32(sh,40,8,true),bits,l2bits,false,extended))return false;
        at+=n;if(at>UINT64_MAX-7)return false;at=(at+7)&~UINT64_C(7);
    }
    return true;
}
static bool sx_storage_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    if(c->f->file_type==XX_FILE_TYPE_MIDI)return sx_midi_build(c);
    if(c->f->file_type==XX_FILE_TYPE_CAF)return sx_caf_build(c);
    if(c->f->file_type==XX_FILE_TYPE_CREATIVE_VOC)return sx_creative_voc_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SONY_VAG)return sx_sony_vag_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SONY_PSF)return sx_sony_psf_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_DSF)return sx_audio_dsf_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_DFF)return sx_audio_dff_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_WAVE64)return sx_audio_wave64_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_ADX)return sx_audio_adx_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_WAVPACK)return sx_audio_wavpack_build(c);
    if(c->f->file_type==XX_FILE_TYPE_IVF)return sx_ivf_build(c);
    if(c->f->file_type==XX_FILE_TYPE_IDTECH_ROQ)return sx_idtech_roq_build(c);
    if(c->f->file_type==XX_FILE_TYPE_FLASH_VIDEO_FLV)return sx_flash_video_flv_build(c);
    if(c->f->file_type==XX_FILE_TYPE_RAD_BINK)return sx_rad_bink_build(c);
    if(c->f->file_type==XX_FILE_TYPE_RAD_SMACKER)return sx_rad_smacker_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUTODESK_FLIC)return sx_autodesk_flic_build(c);
    if(c->f->file_type==XX_FILE_TYPE_QCOW)return sx_qcow_build(c);
    if(c->f->file_type==XX_FILE_TYPE_QCOW1)return sx_qcow1_build(c);
    if(c->f->file_type==XX_FILE_TYPE_LUKS)return sx_luks_build(c);
    if(c->f->file_type==XX_FILE_TYPE_ROMFS)return sx_romfs_build(c);
    if(c->f->file_type==XX_FILE_TYPE_CRAMFS)return sx_cramfs_build(c);
    return false;
}
static bool sx_storage_comment(xx_data_struct_record *r,uint32_t id)
{
    if(id<0x60080000U||id>=0x60090000U||!r->name)return true;
    const wchar_t *n=r->name,*text=NULL;
    if(!xx_rt_wcscmp(n,L"sample_rate"))text=L"Samples per second (Hz)";
    else if(!xx_rt_wcscmp(n,L"bits_per_sample")||!xx_rt_wcscmp(n,L"sample_bits")||!xx_rt_wcscmp(n,L"bits_per_channel")||!xx_rt_wcscmp(n,L"depth"))text=L"Bits per sample or pixel; not a byte count";
    else if(!xx_rt_wcscmp(n,L"average_bytes_per_second"))text=L"Byte rate in bytes per second";
    else if(!xx_rt_wcscmp(n,L"cluster_bits"))text=L"Encoded exponent: cluster bytes = 1 << cluster_bits";
    else if(!xx_rt_wcscmp(n,L"l2_bits"))text=L"Encoded exponent: L2 entry count = 1 << l2_bits";
    else if(!xx_rt_wcscmp(n,L"refcount_order"))text=L"Encoded exponent: bits per reference count = 1 << refcount_order";
    else if(!xx_rt_wcscmp(n,L"payload_sector")||!xx_rt_wcscmp(n,L"key_material_sector"))text=L"Offset in 512-byte sectors relative to the volume";
    else if(!xx_rt_wcscmp(n,L"word_count"))text=L"Encoded payload length in two-byte words, including odd-byte padding";
    else if(!xx_rt_wcscmp(n,L"four_byte_units"))text=L"Palette packet length in four-byte units, including this byte";
    else if(!xx_rt_wcscmp(n,L"time_constant"))text=L"Encoded rate: samples per second = 1000000 / (256 - value)";
    else if(!xx_rt_wcscmp(n,L"division"))text=L"Bit 15 clear: ticks per quarter note; set: signed SMPTE frame rate and ticks per frame";
    else if(!xx_rt_wcscmp(n,L"predictor_and_shift"))text=L"High nibble: ADPCM predictor; low nibble: sample shift";
    else if(!xx_rt_wcscmp(n,L"timestamp_low24"))text=L"Low 24 bits of millisecond timestamp; combine with timestamp_high8";
    else if(!xx_rt_wcscmp(n,L"timestamp_high8"))text=L"High 8 bits of millisecond timestamp";
    else if(!xx_rt_wcscmp(n,L"composition_time"))text=L"Signed composition-time offset in milliseconds";
    else if(!xx_rt_wcscmp(n,L"offset_and_keyframe_flag"))text=L"Physical byte offset in bits 1..31; bit 0 is the keyframe flag";
    else if(!xx_rt_wcscmp(n,L"size_and_flags"))text=L"Frame byte length in bits 2..31; low two bits are flags";
    else if(!xx_rt_wcscmp(n,L"next_offset_and_type"))text=L"Next inode byte offset in bits 4..31; bit 3 executable, bits 0..2 inode type";
    else if(!xx_rt_wcscmp(n,L"spec_info"))text=L"Type-dependent: directory child, hardlink target, device number, or zero";
    else if(!xx_rt_wcscmp(n,L"mode_uid"))text=id==sx_st_cramfs_inode_be.id?L"High 16 bits: mode; low 16 bits: UID":L"Low 16 bits: mode; high 16 bits: UID";
    else if(!xx_rt_wcscmp(n,L"size_gid"))text=id==sx_st_cramfs_inode_be.id?L"High 24 bits: byte size; low 8 bits: GID":L"Low 24 bits: byte size; high 8 bits: GID";
    else if(!xx_rt_wcscmp(n,L"name_length_and_offset"))text=id==sx_st_cramfs_inode_be.id?L"High 6 bits: name length in four-byte units; low 26 bits: offset in four-byte units":L"Low 6 bits: name length in four-byte units; high 26 bits: offset in four-byte units";
    else if(!xx_rt_wcscmp(n,L"end_offset_and_flags"))text=L"Block end offset; high two flag bits apply only with extended block pointers";
    else if(!xx_rt_wcscmp(n,L"speed_jiffies"))text=L"Delay in units of 1/70 second";
    else if(!xx_rt_wcscmp(n,L"speed_milliseconds")||!xx_rt_wcscmp(n,L"delay"))text=L"Delay in milliseconds";
    else if(!xx_rt_wcscmp(n,L"frame_duration"))text=L"Positive: milliseconds; negative: absolute value in 1/100000 second units";
    else if(!xx_rt_wcscmp(n,L"data_offset_minus_four"))text=L"Audio starts at this encoded offset plus four bytes";
    else if(!xx_rt_wcscmp(n,L"size_marker"))text=L"RoQ sentinel 0xFFFFFFFF; not a byte count";
    else if(!xx_rt_wcscmp(n,L"timestamp")&&id==sx_st_ivf_frame.id)text=L"Timestamp in IVF time-base ticks (denominator / numerator seconds)";
    else if(!xx_rt_wcscmp(n,L"size")&&id==sx_st_caf_chunk.id)text=L"Signed payload byte length; -1 means data extends to end of file";
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_storage_family={sx_storage_supports,sx_storage_build,sx_storage_layouts,SX_COUNT(sx_storage_layouts),sx_storage_comment};
