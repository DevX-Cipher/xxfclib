/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical archive and compressed stream schemas; payload bytes stay raw.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archive.h"

static const xx_data_struct_field_desc sx_a_cpio_binary_le_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("dev", "uint16", 2, 2, SX_ID),
    SX_FIELD("ino", "uint16", 4, 2, SX_ID),
    SX_FIELD("mode", "uint16", 6, 2, SX_FLAGS),
    SX_FIELD("uid", "uint16", 8, 2, SX_ID),
    SX_FIELD("gid", "uint16", 10, 2, SX_ID),
    SX_FIELD("nlink", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("rdev", "uint16", 14, 2, SX_ID),
    SX_FIELD("mtime_high", "uint16", 16, 2, SX_NONE),
    SX_FIELD("mtime_low", "uint16", 18, 2, SX_NONE),
    SX_FIELD("namesize", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("filesize_high", "uint16", 22, 2, SX_NONE),
    SX_FIELD("filesize_low", "uint16", 24, 2, SX_NONE),
};
const sx_layout sx_a_cpio_binary_le_header = { UINT32_C(0x60040004), "cpio_binary_le_header", sx_a_cpio_binary_le_header_fields, SX_COUNT(sx_a_cpio_binary_le_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_binary_be_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("dev", "uint16", 2, 2, SX_ID),
    SX_FIELD("ino", "uint16", 4, 2, SX_ID),
    SX_FIELD("mode", "uint16", 6, 2, SX_FLAGS),
    SX_FIELD("uid", "uint16", 8, 2, SX_ID),
    SX_FIELD("gid", "uint16", 10, 2, SX_ID),
    SX_FIELD("nlink", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("rdev", "uint16", 14, 2, SX_ID),
    SX_FIELD("mtime_high", "uint16", 16, 2, SX_NONE),
    SX_FIELD("mtime_low", "uint16", 18, 2, SX_NONE),
    SX_FIELD("namesize", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("filesize_high", "uint16", 22, 2, SX_NONE),
    SX_FIELD("filesize_low", "uint16", 24, 2, SX_NONE),
};
const sx_layout sx_a_cpio_binary_be_header = { UINT32_C(0x60040005), "cpio_binary_be_header", sx_a_cpio_binary_be_header_fields, SX_COUNT(sx_a_cpio_binary_be_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_cab_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved1", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("cbCabinet", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("reserved2", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("coffFiles", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("reserved3", "uint32", 20, 4, SX_RESERVED),
    SX_FIELD("versionMinor", "uint8", 24, 1, SX_NONE),
    SX_FIELD("versionMajor", "uint8", 25, 1, SX_NONE),
    SX_FIELD("cFolders", "uint16", 26, 2, SX_COUNT_PROP),
    SX_FIELD("cFiles", "uint16", 28, 2, SX_COUNT_PROP),
    SX_FIELD("flags", "uint16", 30, 2, SX_FLAGS),
    SX_FIELD("setID", "uint16", 32, 2, SX_ID),
    SX_FIELD("iCabinet", "uint16", 34, 2, SX_ID),
};
const sx_layout sx_a_cab_header = { UINT32_C(0x60040009), "cab_header", sx_a_cab_header_fields, SX_COUNT(sx_a_cab_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cab_folder_fields[] = {
    SX_FIELD("coffCabStart", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("cCFData", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("typeCompress", "uint16", 6, 2, SX_FLAGS),
};
const sx_layout sx_a_cab_folder = { UINT32_C(0x6004000B), "cab_folder", sx_a_cab_folder_fields, SX_COUNT(sx_a_cab_folder_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_skippable_frame_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_a_skippable_frame = { UINT32_C(0x6004000E), "skippable_frame", sx_a_skippable_frame_fields, SX_COUNT(sx_a_skippable_frame_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lz4_block_header_fields[] = {
    SX_FIELD("size_and_uncompressed_flag", "uint32", 0, 4, SX_FLAGS),
};
const sx_layout sx_a_lz4_block_header = { UINT32_C(0x60040013), "lz4_block_header", sx_a_lz4_block_header_fields, SX_COUNT(sx_a_lz4_block_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_checksum_le_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_a_checksum_le = { UINT32_C(0x60040014), "checksum_le", sx_a_checksum_le_fields, SX_COUNT(sx_a_checksum_le_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_block_header_fields[] = {
    SX_FIELD("last_type_size", "uint24", 0, 3, SX_FLAGS),
};
const sx_layout sx_a_zstd_block_header = { UINT32_C(0x60040037), "zstd_block_header", sx_a_zstd_block_header_fields, SX_COUNT(sx_a_zstd_block_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lzop_header_00_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("method", "uint8", 13, 1, SX_ID),
    SX_FIELD("flags", "uint32", 14, 4, SX_FLAGS),
    SX_FIELD("mode", "uint32", 18, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 22, 4, SX_TIME),
    SX_FIELD("filename_length", "uint8", 26, 1, SX_SIZE),
};
const sx_layout sx_a_lzop_header_00 = { UINT32_C(0x6004003A), "lzop_header_00", sx_a_lzop_header_00_fields, SX_COUNT(sx_a_lzop_header_00_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_header_01_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("method", "uint8", 13, 1, SX_ID),
    SX_FIELD("flags", "uint32", 14, 4, SX_FLAGS),
    SX_FIELD("filter", "uint32", 18, 4, SX_ID),
    SX_FIELD("mode", "uint32", 22, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 26, 4, SX_TIME),
    SX_FIELD("filename_length", "uint8", 30, 1, SX_SIZE),
};
const sx_layout sx_a_lzop_header_01 = { UINT32_C(0x6004003B), "lzop_header_01", sx_a_lzop_header_01_fields, SX_COUNT(sx_a_lzop_header_01_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_header_10_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("version_needed", "uint16", 13, 2, SX_NONE),
    SX_FIELD("method", "uint8", 15, 1, SX_ID),
    SX_FIELD("level", "uint8", 16, 1, SX_NONE),
    SX_FIELD("flags", "uint32", 17, 4, SX_FLAGS),
    SX_FIELD("mode", "uint32", 21, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 25, 4, SX_NONE),
    SX_FIELD("mtime_high", "uint32", 29, 4, SX_NONE),
    SX_FIELD("filename_length", "uint8", 33, 1, SX_SIZE),
};
const sx_layout sx_a_lzop_header_10 = { UINT32_C(0x6004003C), "lzop_header_10", sx_a_lzop_header_10_fields, SX_COUNT(sx_a_lzop_header_10_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_header_11_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("version_needed", "uint16", 13, 2, SX_NONE),
    SX_FIELD("method", "uint8", 15, 1, SX_ID),
    SX_FIELD("level", "uint8", 16, 1, SX_NONE),
    SX_FIELD("flags", "uint32", 17, 4, SX_FLAGS),
    SX_FIELD("filter", "uint32", 21, 4, SX_ID),
    SX_FIELD("mode", "uint32", 25, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 29, 4, SX_NONE),
    SX_FIELD("mtime_high", "uint32", 33, 4, SX_NONE),
    SX_FIELD("filename_length", "uint8", 37, 1, SX_SIZE),
};
const sx_layout sx_a_lzop_header_11 = { UINT32_C(0x6004003D), "lzop_header_11", sx_a_lzop_header_11_fields, SX_COUNT(sx_a_lzop_header_11_fields), SX_BE };
static const sx_layout *const sx_archive_layouts[] = {
    &sx_a_cpio_newc_header,
    &sx_a_cpio_odc_header,
    &sx_a_cpio_afio_header,
    &sx_a_cpio_binary_le_header,
    &sx_a_cpio_binary_be_header,
    &sx_a_cpio_solaris_tl,
    &sx_a_cpio_solaris_tg,
    &sx_a_cpio_solaris_block,
    &sx_a_cab_header,
    &sx_a_cab_reserve_sizes,
    &sx_a_cab_folder,
    &sx_a_cab_file,
    &sx_a_cab_data,
    &sx_a_skippable_frame,
    &sx_a_lz4_frame_header_00,
    &sx_a_lz4_frame_header_01,
    &sx_a_lz4_frame_header_10,
    &sx_a_lz4_frame_header_11,
    &sx_a_lz4_block_header,
    &sx_a_checksum_le,
    &sx_a_checksum_be,
    &sx_a_lz4_legacy_header,
    &sx_a_zstd_frame_header_000,
    &sx_a_zstd_frame_header_001,
    &sx_a_zstd_frame_header_002,
    &sx_a_zstd_frame_header_003,
    &sx_a_zstd_frame_header_010,
    &sx_a_zstd_frame_header_011,
    &sx_a_zstd_frame_header_012,
    &sx_a_zstd_frame_header_013,
    &sx_a_zstd_frame_header_020,
    &sx_a_zstd_frame_header_021,
    &sx_a_zstd_frame_header_022,
    &sx_a_zstd_frame_header_023,
    &sx_a_zstd_frame_header_030,
    &sx_a_zstd_frame_header_031,
    &sx_a_zstd_frame_header_032,
    &sx_a_zstd_frame_header_033,
    &sx_a_zstd_frame_header_100,
    &sx_a_zstd_frame_header_101,
    &sx_a_zstd_frame_header_102,
    &sx_a_zstd_frame_header_103,
    &sx_a_zstd_frame_header_110,
    &sx_a_zstd_frame_header_111,
    &sx_a_zstd_frame_header_112,
    &sx_a_zstd_frame_header_113,
    &sx_a_zstd_frame_header_120,
    &sx_a_zstd_frame_header_121,
    &sx_a_zstd_frame_header_122,
    &sx_a_zstd_frame_header_123,
    &sx_a_zstd_frame_header_130,
    &sx_a_zstd_frame_header_131,
    &sx_a_zstd_frame_header_132,
    &sx_a_zstd_frame_header_133,
    &sx_a_zstd_block_header,
    &sx_a_lzip_header,
    &sx_a_lzip_trailer,
    &sx_a_lzop_header_00,
    &sx_a_lzop_header_01,
    &sx_a_lzop_header_10,
    &sx_a_lzop_header_11,
    &sx_a_lzop_block_sizes,
    &sx_a_lzop_end,
    &sx_a_lzop_extra_size,
};
bool sx_a_raw_advance(sx_context *c,int64_t *at,uint64_t size)
{
    if(*at<0||*at>c->size||size>(uint64_t)(c->size-*at))return false;
    if(!sx_raw(c,*at,(int64_t)size))return false;
    *at+=(int64_t)size;return true;
}
bool sx_a_skippable(sx_context *c,int64_t *at)
{
    uint32_t size;
    if(!sx_u32(c,*at+4,false,&size)||!sx_add(c,&sx_a_skippable_frame,*at,8))return false;
    *at+=8;return sx_a_raw_advance(c,at,size);
}
static bool sx_archive_supports(xx_file_type_t t)
{
    return t==XX_FILE_TYPE_CPIO||t==XX_FILE_TYPE_CAB||t==XX_FILE_TYPE_LZ4||t==XX_FILE_TYPE_ZSTD||t==XX_FILE_TYPE_LZIP||t==XX_FILE_TYPE_LZOP;
}
static bool sx_archive_build(sx_context *c)
{
    if(c->f->file_type==XX_FILE_TYPE_CPIO)return sx_cpio_build(c);
    if(c->f->file_type==XX_FILE_TYPE_CAB)return sx_cab_build(c);
    if(c->f->file_type==XX_FILE_TYPE_LZ4)return sx_lz4_build(c);
    if(c->f->file_type==XX_FILE_TYPE_ZSTD)return sx_zstd_build(c);
    if(c->f->file_type==XX_FILE_TYPE_LZIP)return sx_lzip_build(c);
    if(c->f->file_type==XX_FILE_TYPE_LZOP)return sx_lzop_build(c);
    return false;
}
static bool sx_archive_comment(xx_data_struct_record *r,uint32_t id)
{
    const wchar_t *s=NULL;uint64_t v;
    if(!r||!r->name||id<UINT32_C(0x60040001)||id>UINT32_C(0x6004ffff))return true;
    v=xx_var_get_u64(&r->value);
    if(id==sx_a_cpio_binary_le_header.id||id==sx_a_cpio_binary_be_header.id){
        if(!xx_rt_wcscmp(r->name,L"filesize_high"))s=L"High 16 bits of the 32-bit file size";
        else if(!xx_rt_wcscmp(r->name,L"filesize_low"))s=L"Low 16 bits of the 32-bit file size";
        else if(!xx_rt_wcscmp(r->name,L"mtime_high"))s=L"High 16 bits of the 32-bit modification time";
        else if(!xx_rt_wcscmp(r->name,L"mtime_low"))s=L"Low 16 bits of the 32-bit modification time";
    }else if(id==sx_a_cab_folder.id&&!xx_rt_wcscmp(r->name,L"typeCompress")){
        switch(v&15){case 0:s=L"CAB_COMP_NONE";break;case 1:s=L"CAB_COMP_MSZIP";break;case 2:s=L"CAB_COMP_QUANTUM";break;case 3:s=L"CAB_COMP_LZX";break;}
    }else if(id==sx_a_cab_header.id&&!xx_rt_wcscmp(r->name,L"flags")){
        static const wchar_t *const names[]={L"0",L"CAB_FLAG_PREV",L"CAB_FLAG_NEXT",L"CAB_FLAG_PREV|CAB_FLAG_NEXT",L"CAB_FLAG_RESERVE",L"CAB_FLAG_PREV|CAB_FLAG_RESERVE",L"CAB_FLAG_NEXT|CAB_FLAG_RESERVE",L"CAB_FLAG_PREV|CAB_FLAG_NEXT|CAB_FLAG_RESERVE"};
        if(v<8)s=names[v];
    }else if(!xx_rt_wcscmp(r->name,L"frame_content_size_encoded"))s=L"Decoded content size is this value + 256";
    else if(id==sx_a_zstd_block_header.id){
        static const wchar_t *const names[]={L"Raw block",L"RLE block",L"Compressed block",L"Reserved"};s=names[(v>>1)&3];
    }else if(id==sx_a_lz4_block_header.id)s=v==0?L"End mark":(v&0x80000000U)?L"Uncompressed block; low 31 bits are size":L"Compressed block size";
    else if((id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id)&&!xx_rt_wcscmp(r->name,L"mtime_low"))s=L"Low 32 bits of the 64-bit modification time";
    else if((id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id)&&!xx_rt_wcscmp(r->name,L"mtime_high"))s=L"High 32 bits of the 64-bit modification time";
    else if(!xx_rt_wcscmp(r->name,L"method")&&(id==sx_a_lzop_header_00.id||id==sx_a_lzop_header_01.id||id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id))s=v==1?L"LZO1X-1":v==2?L"LZO1X-1(15)":v==3?L"LZO1X-999":NULL;
    return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_archive_family={sx_archive_supports,sx_archive_build,sx_archive_layouts,SX_COUNT(sx_archive_layouts),sx_archive_comment};
