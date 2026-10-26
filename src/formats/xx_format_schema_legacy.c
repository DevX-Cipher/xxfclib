/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy archive, codec, executable and catalog metadata.
 * Encoded payloads, bit trees and unparsed extensions remain RAW_DATA.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_legacy.h"
static const xx_data_struct_field_desc sxl_wii_lz77_header_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("original_size", "uint24", 1, 3, SX_SIZE),
};
const sx_layout sxl_wii_lz77_header = { UINT32_C(0x600A0005), "wii_lz77_header", sxl_wii_lz77_header_fields, SX_COUNT(sxl_wii_lz77_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_squeeze_tree_node_fields[] = {
    SX_FIELD("zero_child", "int16", 0, 2, SX_NONE),
    SX_FIELD("one_child", "int16", 2, 2, SX_NONE),
};
const sx_layout sxl_squeeze_tree_node = { UINT32_C(0x600A000B), "squeeze_tree_node", sxl_squeeze_tree_node_fields, SX_COUNT(sxl_squeeze_tree_node_fields), SX_LE };
static const xx_data_struct_field_desc sxl_filename_byte_fields[] = {
    SX_FIELD("character", "char[1]", 0, 1, SX_STRING),
};
static const sx_layout sxl_filename_byte = { UINT32_C(0x600A000C), "filename_byte", sxl_filename_byte_fields, SX_COUNT(sxl_filename_byte_fields), SX_LE };
static const xx_data_struct_field_desc sxl_logitech_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("missing_filename_character", "char[1]", 2, 1, SX_STRING),
    SX_FIELD("unknown", "uint8", 3, 1, SX_NONE),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxl_logitech_header = { UINT32_C(0x600A000F), "logitech_header", sxl_logitech_header_fields, SX_COUNT(sxl_logitech_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_dma_packed_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("filename", "char[14]", 4, 14, SX_STRING),
    SX_FIELD("original_size", "uint32", 18, 4, SX_SIZE),
    SX_FIELD("dos_date", "uint16", 22, 2, SX_NONE),
    SX_FIELD("dos_time", "uint16", 24, 2, SX_NONE),
    SX_FIELD("pack_tag", "bytes", 26, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 32, 2, SX_NONE),
};
static const sx_layout sxl_dma_packed_header = { UINT32_C(0x600A0010), "dma_packed_header", sxl_dma_packed_header_fields, SX_COUNT(sxl_dma_packed_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_dcl_header_fields[] = {
    SX_FIELD("literal_coding", "uint8", 0, 1, SX_ID),
    SX_FIELD("dictionary_bits", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxl_dcl_header = { UINT32_C(0x600A0011), "dcl_header", sxl_dcl_header_fields, SX_COUNT(sxl_dcl_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_gas_huff_header_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("node_count_minus_one", "uint16", 4, 2, SX_NONE),
    SX_FIELD("root_index", "uint16", 6, 2, SX_ID),
};
const sx_layout sxl_gas_huff_header = { UINT32_C(0x600A0012), "gas_huff_header", sxl_gas_huff_header_fields, SX_COUNT(sxl_gas_huff_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_legacy_frame_header_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("block_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 14, 1, SX_CHECKSUM),
};
static const sx_layout sxl_legacy_frame_header = { UINT32_C(0x600A001B), "legacy_frame_header", sxl_legacy_frame_header_fields, SX_COUNT(sxl_legacy_frame_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_legacy_frame_block_fields[] = {
    SX_FIELD("size_and_flags", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sxl_legacy_frame_block = { UINT32_C(0x600A001C), "legacy_frame_block", sxl_legacy_frame_block_fields, SX_COUNT(sxl_legacy_frame_block_fields), SX_LE };
static const xx_data_struct_field_desc sxl_legacy_frame_skip_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("content_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxl_legacy_frame_skip = { UINT32_C(0x600A001D), "legacy_frame_skip", sxl_legacy_frame_skip_fields, SX_COUNT(sxl_legacy_frame_skip_fields), SX_LE };
static const xx_data_struct_field_desc sxl_legacy_frame_checksum_fields[] = {
    SX_FIELD("xxhash32", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sxl_legacy_frame_checksum = { UINT32_C(0x600A001E), "legacy_frame_checksum", sxl_legacy_frame_checksum_fields, SX_COUNT(sxl_legacy_frame_checksum_fields), SX_LE };
static const xx_data_struct_field_desc sxl_qm_block_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("content_size", "uint32", 1, 4, SX_SIZE),
};
const sx_layout sxl_qm_block = { UINT32_C(0x600A0028), "qm_block", sxl_qm_block_fields, SX_COUNT(sxl_qm_block_fields), SX_BE };
static const xx_data_struct_field_desc sxl_qm_message_field_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("content_size", "uint32", 1, 4, SX_SIZE),
};
const sx_layout sxl_qm_message_field = { UINT32_C(0x600A002A), "qm_message_field", sxl_qm_message_field_fields, SX_COUNT(sxl_qm_message_field_fields), SX_BE };
static const xx_data_struct_field_desc sxl_qm_message_end_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
};
const sx_layout sxl_qm_message_end = { UINT32_C(0x600A002B), "qm_message_end", sxl_qm_message_end_fields, SX_COUNT(sxl_qm_message_end_fields), SX_BE };
static const xx_data_struct_field_desc sxl_qm_message_obsolete_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("obsolete_value", "uint32", 1, 4, SX_NONE),
};
const sx_layout sxl_qm_message_obsolete = { UINT32_C(0x600A002C), "qm_message_obsolete", sxl_qm_message_obsolete_fields, SX_COUNT(sxl_qm_message_obsolete_fields), SX_BE };
static const xx_data_struct_field_desc sxl_pef_header_fields[] = {
    SX_FIELD("tag1", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("tag2", "bytes", 4, 4, SX_SIGNATURE),
    SX_FIELD("architecture", "char[4]", 8, 4, SX_ID),
    SX_FIELD("format_version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("created_mac_epoch", "uint32", 16, 4, SX_NONE),
    SX_FIELD("old_definition_version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("old_implementation_version", "uint32", 24, 4, SX_NONE),
    SX_FIELD("current_version", "uint32", 28, 4, SX_NONE),
    SX_FIELD("section_count", "uint16", 32, 2, SX_COUNT_PROP),
    SX_FIELD("instantiated_count", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint32", 36, 4, SX_RESERVED),
};
const sx_layout sxl_pef_header = { UINT32_C(0x600A002F), "pef_header", sxl_pef_header_fields, SX_COUNT(sxl_pef_header_fields), SX_BE };
static const xx_data_struct_field_desc sxl_pef_section_fields[] = {
    SX_FIELD("name_offset", "int32", 0, 4, SX_OFFSET),
    SX_FIELD("default_address", "uint32", 4, 4, SX_ADDRESS),
    SX_FIELD("total_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unpacked_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("container_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("section_kind", "uint8", 24, 1, SX_ID),
    SX_FIELD("share_kind", "uint8", 25, 1, SX_ID),
    SX_FIELD("alignment", "uint8", 26, 1, SX_NONE),
    SX_FIELD("reserved", "uint8", 27, 1, SX_RESERVED),
};
const sx_layout sxl_pef_section = { UINT32_C(0x600A0030), "pef_section", sxl_pef_section_fields, SX_COUNT(sxl_pef_section_fields), SX_BE };
static const xx_data_struct_field_desc sxl_pef_loader_fields[] = {
    SX_FIELD("main_section", "int32", 0, 4, SX_ID),
    SX_FIELD("main_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("init_section", "int32", 8, 4, SX_ID),
    SX_FIELD("init_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("term_section", "int32", 16, 4, SX_ID),
    SX_FIELD("term_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("imported_library_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("imported_symbol_count", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("relocation_section_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("relocation_offset", "uint32", 36, 4, SX_OFFSET),
    SX_FIELD("strings_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("export_hash_offset", "uint32", 44, 4, SX_OFFSET),
    SX_FIELD("export_hash_power", "uint32", 48, 4, SX_NONE),
    SX_FIELD("exported_symbol_count", "uint32", 52, 4, SX_COUNT_PROP),
};
const sx_layout sxl_pef_loader = { UINT32_C(0x600A0031), "pef_loader", sxl_pef_loader_fields, SX_COUNT(sxl_pef_loader_fields), SX_BE };
static const xx_data_struct_field_desc sxl_arcfs_directory_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("filename", "char[11]", 1, 11, SX_STRING),
    SX_FIELD("original_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("load_address", "uint32", 16, 4, SX_NONE),
    SX_FIELD("execution_address", "uint32", 20, 4, SX_NONE),
    SX_FIELD("attributes", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("packed_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("offset_and_flags", "uint32", 32, 4, SX_FLAGS),
};
const sx_layout sxl_arcfs_directory = { UINT32_C(0x600A0036), "arcfs_directory", sxl_arcfs_directory_fields, SX_COUNT(sxl_arcfs_directory_fields), SX_LE };
static const sx_layout *const sx_legacy_layouts[] = {
    &sxl_szdd_header,
    &sxl_sz_header,
    &sxl_imd5_header,
    &sxl_wii_lz77_tag,
    &sxl_wii_lz77_header,
    &sxl_wii_lz77_extended_size,
    &sxl_ash0_header,
    &sxl_lzv1_header,
    &sxl_oracle_squeeze_header,
    &sxl_squeeze_tree_header,
    &sxl_squeeze_tree_node,
    &sxl_filename_byte,
    &sxl_softronics_header,
    &sxl_softronics_metadata,
    &sxl_logitech_header,
    &sxl_dma_packed_header,
    &sxl_dcl_header,
    &sxl_gas_huff_header,
    &sxl_huf_header,
    &sxl_huf_symbol,
    &sxl_huf_directory,
    &sxl_lzdiet_header,
    &sxl_lzdiet_chunk,
    &sxl_lzdiet_table_end,
    &sxl_lzpis2_header,
    &sxl_lzpis2_chunk,
    &sxl_legacy_frame_header,
    &sxl_legacy_frame_block,
    &sxl_legacy_frame_skip,
    &sxl_legacy_frame_checksum,
    &sxl_bullfrog_tag,
    &sxl_rnc_header,
    &sxl_mo_header_le,
    &sxl_mo_string_le,
    &sxl_mo_hash_le,
    &sxl_mo_header_be,
    &sxl_mo_string_be,
    &sxl_mo_hash_be,
    &sxl_qm_header,
    &sxl_qm_block,
    &sxl_qm_hash,
    &sxl_qm_message_field,
    &sxl_qm_message_end,
    &sxl_qm_message_obsolete,
    &sxl_atarist_header,
    &sxl_atarist_symbol,
    &sxl_pef_header,
    &sxl_pef_section,
    &sxl_pef_loader,
    &sxl_artipack_header,
    &sxl_artipack_directory,
    &sxl_artipack_size,
    &sxl_arcfs_header,
    &sxl_arcfs_directory,
};
/* All positions are relative to the selected format. Members which encode
 * bits, indexes or logarithms retain those units rather than byte-size roles. */
bool sxl_span(sx_context *c,uint64_t o,uint64_t n){return o<=(uint64_t)c->size&&n<=(uint64_t)c->size-o;}
bool sxl_sig(sx_context *c,int64_t o,const char *s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sx_read(c,o,b,n)&&!xx_rt_memcmp(b,s,n);}
bool sxl_byte(sx_context *c,int64_t o,uint8_t *v){return sx_read(c,o,v,1);}
bool sxl_name(sx_context *c,int64_t off,int64_t limit,int64_t *next){int64_t at=off;uint8_t b;while(at<limit){if(!sxl_byte(c,at++,&b))return false;if(!b){*next=at;return sx_table(c,&sxl_filename_byte,off,1,(uint64_t)(at-off));}}return false;}
static bool sxl_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;
    for(size_t gap=n/2;gap;gap/=2)for(size_t i=gap;i<n;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    for(size_t i=0;i<n;i++){int64_t off=c->items[i].offset-c->f->base_address,total=c->items[i].total_size;if(off<end||!sxl_span(c,(uint64_t)off,(uint64_t)total)||!sx_raw(c,end,off-end))return false;end=off+total;}
    if(!sx_raw(c,end,c->size-end))return false;
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    return true;
}
static bool sxl_dcl(sx_context *c,bool dma)
{
    int64_t at=dma?34:8;uint8_t h[2];uint32_t n;
    if(dma){if(!sxl_sig(c,0,"dm\x10\x11",4)||!sxl_sig(c,26,"PAKPAK\0\x2a",8)||!sx_u32(c,18,false,&n)||!sx_add(c,&sxl_dma_packed_header,0,34))return false;}
    else if(!sxl_sig(c,0,"\xda\xfa",2)||!sx_u32(c,4,false,&n)||!sx_add(c,&sxl_logitech_header,0,8))return false;
    return n&&sx_read(c,at,h,2)&&h[0]<=1&&h[1]>=4&&h[1]<=6&&sx_add(c,&sxl_dcl_header,at,2)&&sxl_span(c,at+2,1);
}
static bool sxl_frame(sx_context *c,uint32_t expected)
{
    int64_t at=0;bool any=false;
    while(at<c->size){uint32_t magic,n;uint8_t h[2];uint64_t maximum;
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_u32(c,at+4,false,&n)||!sxl_span(c,at+8,n)||!sx_add(c,&sxl_legacy_frame_skip,at,8))return false;at+=8+(int64_t)n;continue;}
        if(magic!=expected||!sx_read(c,at+4,h,2)||(h[0]>>6)!=1||(h[0]&3)||!(h[0]&8)||(h[1]&0x8f)||(h[1]>>4)<4||(h[1]>>4)>7||!sx_add(c,&sxl_legacy_frame_header,at,15))return false;
        maximum=UINT64_C(1)<<(8+2*(h[1]>>4));at+=15;any=true;
        for(;;){if(!sx_u32(c,at,false,&n)||!sx_add(c,&sxl_legacy_frame_block,at,4))return false;at+=4;if(!n)break;uint32_t size=n&0x7fffffffU;if(!size||size>maximum||!sxl_span(c,at,size))return false;at+=size;if(h[0]&16){if(!sx_add(c,&sxl_legacy_frame_checksum,at,4))return false;at+=4;}}
        if(h[0]&4){if(!sx_add(c,&sxl_legacy_frame_checksum,at,4))return false;at+=4;}
    }return any;
}
static bool sx_legacy_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_MS_COMPRESS:case XX_FILE_TYPE_ASH0:case XX_FILE_TYPE_WII_LZ77:case XX_FILE_TYPE_LZV1:case XX_FILE_TYPE_ORACLE_SQUEEZE:case XX_FILE_TYPE_SOFTRONICS:case XX_FILE_TYPE_LOGITECH_COMPRESS:case XX_FILE_TYPE_DMA_PACKED:case XX_FILE_TYPE_GAS_HUFF:case XX_FILE_TYPE_HUF:case XX_FILE_TYPE_LZDIET:case XX_FILE_TYPE_LZPIS2:case XX_FILE_TYPE_LZ5:case XX_FILE_TYPE_LIZARD:case XX_FILE_TYPE_RNC:case XX_FILE_TYPE_GNU_GETTEXT_MO:case XX_FILE_TYPE_QT_QM:case XX_FILE_TYPE_ATARIST:case XX_FILE_TYPE_PEF:case XX_FILE_TYPE_ARTIPACK:case XX_FILE_TYPE_ARCFS:return true;default:return false;}
}
static bool sx_legacy_build(sx_context *c)
{
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_MS_COMPRESS:ok=sx_mscompress_build(c);break;
    case XX_FILE_TYPE_WII_LZ77:ok=sx_wiilz77_build(c);break;
    case XX_FILE_TYPE_ASH0:ok=sx_ash0_build(c);break;
    case XX_FILE_TYPE_LZV1:ok=sx_lzv1_build(c);break;
    case XX_FILE_TYPE_ORACLE_SQUEEZE:ok=sx_oraclesqueeze_build(c);break;
    case XX_FILE_TYPE_SOFTRONICS:ok=sx_softronics_build(c);break;
    case XX_FILE_TYPE_LOGITECH_COMPRESS:case XX_FILE_TYPE_DMA_PACKED:ok=sxl_dcl(c,c->f->file_type==XX_FILE_TYPE_DMA_PACKED);break;
    case XX_FILE_TYPE_GAS_HUFF:ok=sx_gashuff_build(c);break;
    case XX_FILE_TYPE_HUF:ok=sx_huf_build(c);break;
    case XX_FILE_TYPE_LZDIET:ok=sx_lzdiet_build(c);break;
    case XX_FILE_TYPE_LZPIS2:ok=sx_lzpis2_build(c);break;
    case XX_FILE_TYPE_LZ5:case XX_FILE_TYPE_LIZARD:ok=sxl_frame(c,c->f->file_type==XX_FILE_TYPE_LZ5?0x184d2205U:0x184d2206U);break;
    case XX_FILE_TYPE_RNC:ok=sx_rnc_build(c);break;
    case XX_FILE_TYPE_GNU_GETTEXT_MO:ok=sx_ue2_documents_schema_build(c);break;
    case XX_FILE_TYPE_QT_QM:ok=sx_ue2_documents_schema_build(c);break;
    case XX_FILE_TYPE_ATARIST:ok=sx_atarist_build(c);break;
    case XX_FILE_TYPE_PEF:ok=sx_pef_build(c);break;
    case XX_FILE_TYPE_ARTIPACK:ok=sx_artipack_build(c);break;
    case XX_FILE_TYPE_ARCFS:ok=sx_arcfs_build(c);break;
    default:break;
    }return ok&&sxl_finish(c);
}
static bool sx_legacy_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600A0000)||id>=UINT32_C(0x600B0000))return true;
    const wchar_t *n=r->name,*s=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(!xx_rt_wcscmp(n,L"dos_date"))s=L"Packed MS-DOS date: year since 1980, month, day";
    else if(!xx_rt_wcscmp(n,L"dos_time"))s=L"Packed MS-DOS time: hours, minutes, two-second units";
    else if(id==sxl_dcl_header.id){if(!xx_rt_wcscmp(n,L"literal_coding"))s=v?L"Huffman literals":L"Raw literals";else s=L"Dictionary size is 64 times 2 to this power, in bytes";}
    else if(id==sxl_wii_lz77_header.id&&!xx_rt_wcscmp(n,L"method"))s=v==16?L"Nintendo LZ10":v==17?L"Nintendo LZ11":NULL;
    else if(id==sxl_squeeze_tree_node.id)s=L"Nonnegative: node index; negative: -symbol-1; -257 is end of stream";
    else if(id==sxl_gas_huff_header.id&&!xx_rt_wcscmp(n,L"node_count_minus_one"))s=L"Physical tree record count is this value plus one";
    else if(id==sxl_legacy_frame_block.id)s=!v?L"End mark":(v&0x80000000U)?L"Uncompressed block; low 31 bits are byte size":L"Compressed block byte size";
    else if(id==sxl_legacy_frame_header.id&&!xx_rt_wcscmp(n,L"block_descriptor"))s=L"Bits 4..6 select maximum block size; remaining bits reserved";
    else if(id==sxl_qm_block.id&&!xx_rt_wcscmp(n,L"tag"))s=v==0x42?L"Hashes":v==0x69?L"Messages":v==0xa7?L"Language":v==0x2f?L"Contexts":v==0x88?L"Numerus rules":v==0x96?L"Dependencies":NULL;
    else if((id==sxl_qm_message_field.id||id==sxl_qm_message_end.id||id==sxl_qm_message_obsolete.id)&&!xx_rt_wcscmp(n,L"tag"))s=v==1?L"End":v==2?L"SourceText16":v==3?L"Translation":v==4?L"Context16":v==5?L"Obsolete1":v==6?L"SourceText":v==7?L"Context":v==8?L"Comment":v==9?L"Obsolete2":NULL;
    else if(id==sxl_qm_message_field.id&&!xx_rt_wcscmp(n,L"content_size")&&v==UINT32_MAX)s=L"Null byte array; no payload bytes";
    else if(id==sxl_pef_section.id&&!xx_rt_wcscmp(n,L"alignment"))s=L"log2(alignment in bytes)";
    else if(id==sxl_pef_section.id&&!xx_rt_wcscmp(n,L"name_offset")&&xx_var_get_i64(&r->value)==-1)s=L"No section name";
    else if(id==sxl_pef_header.id&&!xx_rt_wcscmp(n,L"created_mac_epoch"))s=L"Seconds since 1904-01-01";
    else if(id==sxl_pef_loader.id&&!xx_rt_wcscmp(n,L"export_hash_power"))s=L"log2(number of export hash slots)";
    else if(id==sxl_arcfs_directory.id&&!xx_rt_wcscmp(n,L"offset_and_flags"))s=L"Bit 31: directory; low 31 bits: data-relative byte offset or directory-header offset";
    else if(id==sxl_arcfs_directory.id&&(!xx_rt_wcscmp(n,L"load_address")||!xx_rt_wcscmp(n,L"execution_address")))s=L"RISC OS load/exec address, or packed filetype and centisecond timestamp";
    return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_legacy_family={sx_legacy_supports,sx_legacy_build,sx_legacy_layouts,SX_COUNT(sx_legacy_layouts),sx_legacy_comment};
