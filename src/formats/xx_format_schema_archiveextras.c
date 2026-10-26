/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Native-supported physical archive metadata. See docs/data_struct_archiveextras_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveextras.h"
static const sx_layout *const sx_archiveextras_layouts[] = {
    &sxae_arc_member_old,
    &sxae_arc_member,
    &sxae_arc_end,
    &sxae_bsn_header,
    &sxae_bsn_member_prefix,
    &sxae_bsn_member_sizes,
    &sxae_bsn_end,
    &sxae_arq_container,
    &sxae_arq_member_prefix,
    &sxae_arq_member_tail,
    &sxae_gxl_header,
    &sxae_gxl_member,
    &sxae_rta_header,
    &sxae_rta_string_size,
    &sxae_rta_member,
    &sxae_rta_codec_header,
    &sxae_rta_end,
    &sxae_sqz_header,
    &sxae_sqz_member,
    &sxae_sqz_block,
    &sxae_sqz_block4,
    &sxae_sqz_comment,
    &sxae_sqz_end,
    &sxae_sqx_main,
    &sxae_sqx_record,
    &sxae_sqx_file32,
    &sxae_sqx_file64,
    &sxae_hap_header,
    &sxae_hap_member,
    &sxae_kwaj_header,
    &sxae_kwaj_unpacked_size,
    &sxae_kwaj_unknown,
    &sxae_kwaj_extension_size,
    &sxae_kwaj_mszip_block,
    &sxae_kwaj_mszip_end,
    &sxae_chz_file,
    &sxae_chz_directory,
    &sxae_chz_directory_end,
    &sxae_swag_member,
    &sxae_swag_member_crc,
    &sxae_swag_footer,
    &sxae_zpak_header,
    &sxae_zpak_member,
    &sxae_zpak_chunk_marker,
    &sxae_zpak_chunk,
    &sxae_asymetrix_header,
    &sxae_asymetrix_member,
    &sxae_asymetrix_block,
    &sxae_diskexpress_header,
    &sxae_diskexpress_track,
    &sxae_ain_header,
    &sxae_amigalzx_header,
    &sxae_amigalzx_member,
};
static bool sx_archiveextras_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60170000)||id>=UINT32_C(0x60180000))return true;
    const wchar_t *comment=NULL;switch(id){
    case UINT32_C(0x60170001):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170002):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170005):
        if(!xx_rt_wcscmp(r->name,L"date_time"))comment=L"Packed DOS date/time words, not a Unix timestamp.";
        break;
    case UINT32_C(0x6017000a):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_crc32"))comment=L"CRC32 of encoded member bytes, not the decoded contents.";
        break;
    case UINT32_C(0x6017000c):
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x6017000f):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170013):
        if(!xx_rt_wcscmp(r->name,L"header_length"))comment=L"Physical header size is this encoded byte plus 2.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170016):
        if(!xx_rt_wcscmp(r->name,L"legacy_size"))comment=L"Superseded by the following extra_size in type-1 comment blocks.";
        break;
    case UINT32_C(0x6017001a):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_low"))comment=L"Byte length; no high word is present in this variant.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_low"))comment=L"Byte length; no high word is present in this variant.";
        break;
    case UINT32_C(0x6017001b):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_low"))comment=L"Low 32 bits of the byte length; combine high word when LARGE flag is set.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_low"))comment=L"Low 32 bits of the byte length; combine high word when LARGE flag is set.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_high"))comment=L"High 32 bits of the byte length, not a complete size.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_high"))comment=L"High 32 bits of the byte length, not a complete size.";
        break;
    case UINT32_C(0x6017001d):
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170022):
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))comment=L"MSZIP block encoded length; includes its CK signature as defined by the stream framing.";
        break;
    case UINT32_C(0x60170027):
        if(!xx_rt_wcscmp(r->name,L"header_length"))comment=L"Counted from byte 2; equals member name size plus 0xBB.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))comment=L"Zero selects a stored member, whose decoded size is packed_size.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"crc32_register"))comment=L"CRC32 register before final inversion.";
        break;
    case UINT32_C(0x6017002b):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"crc_low"))comment=L"Low 16 bits of CRC32; combine high word.";
        if(!xx_rt_wcscmp(r->name,L"crc_high"))comment=L"High 16 bits of CRC32; zero disables checksum validation in this reader.";
        break;
    case UINT32_C(0x6017002f):
        if(!xx_rt_wcscmp(r->name,L"writer_bytes"))comment=L"Uninitialized producer bytes; no date/time or other fields are inferred from them.";
        if(!xx_rt_wcscmp(r->name,L"volume_word"))comment=L"High 16 bits identify the volume containing the data offset.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170031):
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))comment=L"Zero-based final cylinder index, not a count.";
        if(!xx_rt_wcscmp(r->name,L"last_head"))comment=L"Zero-based final head index, not a count.";
        break;
    case UINT32_C(0x60170033):
        if(!xx_rt_wcscmp(r->name,L"version_method"))comment=L"High nibble: format generation 1..3. Low nibble: method 1..4.";
        if(!xx_rt_wcscmp(r->name,L"directory_offset"))comment=L"Offset of the compressed directory; decoded directory entries have no physical file offsets.";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))comment=L"Sum of the preceding 22 header bytes XOR 0x5555.";
        break;
    case UINT32_C(0x60170035):
        if(!xx_rt_wcscmp(r->name,L"group_packed_size"))comment=L"Zero for a merged prefix member; nonzero size belongs to the entire terminating group stream.";
        if(!xx_rt_wcscmp(r->name,L"date_time"))comment=L"Packed Amiga date/time, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"header_crc32"))comment=L"CRC32 of header, name and comment with this field zeroed.";
        break;
    default:break;}
    if(id==UINT32_C(0x60170002)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARC_STORED_OLD";break;
        case 2:comment=L"ARC_STORED";break;
        case 3:comment=L"ARC_PACKED";break;
        case 4:comment=L"ARC_SQUEEZED";break;
        case 5:comment=L"ARC_CRUNCHED_5";break;
        case 6:comment=L"ARC_CRUNCHED_6";break;
        case 7:comment=L"ARC_CRUNCHED_7";break;
        case 8:comment=L"ARC_CRUNCHED";break;
        case 9:comment=L"ARC_SQUASHED";break;
        case 10:comment=L"ARC_CRUSHED";break;
        case 11:comment=L"ARC_DISTILLED";break;
        case 127:comment=L"ARC_COMPRESS";break;
        default:break;}
    if(id==UINT32_C(0x60170001)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARC_STORED_OLD";break;
        default:break;}
    if(id==UINT32_C(0x60170003)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"ARC_END";break;
        default:break;}
    if(id==UINT32_C(0x6017000a)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARQ_STORED";break;
        case 2:comment=L"ARQ_CRUSHED";break;
        default:break;}
    if(id==UINT32_C(0x6017000c)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"GXL_STORED";break;
        default:break;}
    if(id==UINT32_C(0x6017001e)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"KWAJ_STORED";break;
        case 1:comment=L"KWAJ_XOR_FF";break;
        case 2:comment=L"KWAJ_LZSS";break;
        case 3:comment=L"KWAJ_LZH";break;
        case 4:comment=L"KWAJ_MSZIP";break;
        default:break;}
    if(id==UINT32_C(0x6017001d)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 21:comment=L"HAP_STORED";break;
        case 22:comment=L"HAP_PPM";break;
        default:break;}
    if(id==UINT32_C(0x60170024)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"CHZ_STORED";break;
        case 1:comment=L"CHZ_CHARC";break;
        default:break;}
    if(id==UINT32_C(0x60170030)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"ASYMETRIX_STORED";break;
        case 1:comment=L"ASYMETRIX_DCL";break;
        default:break;}
    if(id==UINT32_C(0x60170035)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"AMIGA_LZX_STORED";break;
        case 2:comment=L"AMIGA_LZX_COMPRESSED";break;
        default:break;}
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
/* Every cursor is relative to the caller's original file base. */
uint16_t sxae16(const uint8_t *b){return xx_data_get_u16(b,2,0,false);}
uint32_t sxae32(const uint8_t *b){return xx_data_get_u32(b,4,0,false);}
bool sxae_bound(sx_context *c,int64_t o,uint64_t n){return o>=0&&o<=c->size&&n<=(uint64_t)(c->size-o);}
bool sxae_data(sx_context *c,int64_t o,uint64_t n){return n<=INT64_MAX&&sxae_bound(c,o,n)&&sx_raw(c,o,(int64_t)n);}
bool sxae_add(sx_context *c,const sx_layout *l,int64_t o){int64_t n=l->fields[l->field_count-1].rel_offset+l->fields[l->field_count-1].size;return sx_add(c,l,o,n);}
static int sxae_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxae_finish(sx_context *c)
{
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxae_order);
    size_t count=c->count;int64_t end=0;
    for(size_t i=0;i<count;i++){int64_t p=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(p<end||!sxae_bound(c,p,(uint64_t)n))return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxae_order);return !c->failed;
}
static bool sx_archiveextras_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_SEAARC:case XX_FILE_TYPE_BSN:case XX_FILE_TYPE_ARQ:case XX_FILE_TYPE_GXL:case XX_FILE_TYPE_RTA:case XX_FILE_TYPE_SQZ:case XX_FILE_TYPE_SQX:case XX_FILE_TYPE_HAP:case XX_FILE_TYPE_KWAJ:case XX_FILE_TYPE_CHZ:case XX_FILE_TYPE_SWAG:case XX_FILE_TYPE_ZPAK:case XX_FILE_TYPE_ASYMETRIX:case XX_FILE_TYPE_DISKEXPRESS:case XX_FILE_TYPE_AIN:case XX_FILE_TYPE_AMIGALZX:return true;default:return false;}
}
static bool sx_archiveextras_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_SEAARC:ok=sx_seaarc_build(c);break;case XX_FILE_TYPE_BSN:ok=sx_bsn_build(c);break;case XX_FILE_TYPE_ARQ:ok=sx_arq_build(c);break;case XX_FILE_TYPE_GXL:ok=sx_gxl_build(c);break;case XX_FILE_TYPE_RTA:ok=sx_rta_build(c);break;case XX_FILE_TYPE_SQZ:ok=sx_sqz_build(c);break;case XX_FILE_TYPE_SQX:ok=sx_sqx_build(c);break;case XX_FILE_TYPE_HAP:ok=sx_hap_build(c);break;case XX_FILE_TYPE_KWAJ:ok=sx_kwaj_build(c);break;case XX_FILE_TYPE_CHZ:ok=sx_chz_build(c);break;case XX_FILE_TYPE_SWAG:ok=sx_swag_build(c);break;case XX_FILE_TYPE_ZPAK:ok=sx_zpak_build(c);break;case XX_FILE_TYPE_ASYMETRIX:ok=sx_asymetrix_build(c);break;case XX_FILE_TYPE_DISKEXPRESS:ok=sx_diskexpress_build(c);break;case XX_FILE_TYPE_AIN:ok=sx_ain_build(c);break;case XX_FILE_TYPE_AMIGALZX:ok=sx_amigalzx_build(c);break;default:return false;}return ok&&sxae_finish(c);
}
const sx_family sx_archiveextras_family={sx_archiveextras_supports,sx_archiveextras_build,sx_archiveextras_layouts,SX_COUNT(sx_archiveextras_layouts),sx_archiveextras_comment};
