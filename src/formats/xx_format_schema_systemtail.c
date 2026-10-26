/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-container metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_systemtail_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_systemtail.h"
static const xx_data_struct_field_desc sxst_sabdu_header_fields[] = {
    SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
    SX_FIELD("version","char[4]",21,4,SX_NONE),
    SX_FIELD("terminator","uint8",25,1,SX_RESERVED),
    SX_FIELD("flags","uint16",26,2,SX_FLAGS),
    SX_FIELD("disk_type","uint16",28,2,SX_ID),
    SX_FIELD("cylinders","uint16",30,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("current_cylinder","uint16",36,2,SX_NONE),
    SX_FIELD("current_head","uint16",38,2,SX_NONE),
    SX_FIELD("current_sector","uint16",40,2,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",42,2,SX_SIZE),
    SX_FIELD("bytes_per_track","uint16",44,2,SX_SIZE),
};
static const sx_layout sxst_sabdu_header = {0x60370011U,"sabdu_header",sxst_sabdu_header_fields,SX_COUNT(sxst_sabdu_header_fields),SX_LE};
static const sx_layout *const sx_systemtail_layouts[] = {
    &sxst_irixsa_header,
    &sxst_irixsa_directory_entry,
    &sxst_sos_boot_prefix,
    &sxst_sos_directory_entry,
    &sxst_zoom_header,
    &sxst_zoom_note_checksum,
    &sxst_zoom_chunk,
    &sxst_trdos_entry,
    &sxst_trdos_disk_descriptor,
    &sxst_csidos_root_block,
    &sxst_csidos_catalogue_block,
    &sxst_csidos_entry,
    &sxst_copydisk_header,
    &sxst_apricot_image_header,
    &sxst_apricot_chunk,
    &sxst_apricot_run,
    &sxst_sabdu_header,
    &sxst_adam_volume,
    &sxst_adam_entry,
    &sxst_adam_entry_split_prefix,
    &sxst_adam_entry_split_tail,
    &sxst_pcmag_flp_header,
    &sxst_warp_track,
    &sxst_lhwarp_header0,
    &sxst_lhwarp_header3,
    &sxst_lhwarp_cylinder0,
    &sxst_lhwarp_cylinder,
    &sxst_compdisk_header,
    &sxst_compdisk_cylinder,
    &sxst_crunchdisk_header,
    &sxst_crunchdisk_cylinder,
    &sxst_lisa_blu_header,
    &sxst_ciscopy_header,
    &sxst_ciscopy_track_state,
    &sxst_ciscopy_compression,
    &sxst_copytape_block,
    &sxst_copytape_mark,
    &sxst_copytape_separator,
    &sxst_wcdisk_header,
    &sxst_wcdisk_sector,
    &sxst_wcdisk_fill,
    &sxst_wcdisk_extra,
    &sxst_dri_signature,
    &sxst_dri_diskcopy_bpb,
    &sxst_maxidisk_header,
    &sxst_raydim_header_indices,
    &sxst_raydim_header_counts,
    &sxst_raydim_sector_status,
    &sxst_rside_header,
    &sxst_rside_identify,
    &sxst_t98_header,
    &sxst_pc86f_header,
    &sxst_pc86f_track_offset,
    &sxst_pc86f_track,
    &sxst_pc86f_track_extra,
    &sxst_fdx68_header,
    &sxst_fdx68_track,
    &sxst_h17_header,
    &sxst_h17_chunk,
    &sxst_h17_disk_format2,
    &sxst_h17_disk_format3,
    &sxst_h17_parameters1,
    &sxst_h17_parameters2,
    &sxst_h17_sector_metadata,
};
static bool sx_systemtail_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60370000U||id>=0x60380000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x60370009U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 22U:return xx_data_struct_record_set_comment(r,L"80 tracks, double sided");
    case 23U:return xx_data_struct_record_set_comment(r,L"40 tracks, double sided");
    case 24U:return xx_data_struct_record_set_comment(r,L"80 tracks, single sided");
    case 25U:return xx_data_struct_record_set_comment(r,L"40 tracks, single sided");
    default:break;}}
    if(id==0x6037000fU&&!xx_rt_wcscmp(r->name,L"subtype")&&integer){switch(value){
    case 40592U:return xx_data_struct_record_set_comment(r,L"Stored bytes");
    case 15962U:return xx_data_struct_record_set_comment(r,L"Repeated fill byte");
    default:break;}}
    if(id==0x6037000fU&&!xx_rt_wcscmp(r->name,L"kind")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Disk image data");
    default:break;}}
    if(id==0x60370017U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Unix LZW then RLE90");
    case 2U:return xx_data_struct_record_set_comment(r,L"Squeeze then RLE90");
    case 3U:return xx_data_struct_record_set_comment(r,L"RLE90");
    default:break;}}
    if(id==0x6037001bU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Freeze adaptive Huffman/LZSS");
    case 1U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 7U:return xx_data_struct_record_set_comment(r,L"Vaporize Unix LZW");
    case 10U:return xx_data_struct_record_set_comment(r,L"Squeeze then RLE90");
    default:break;}}
    if(id==0x6037001eU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored transposed sectors");
    case 1U:return xx_data_struct_record_set_comment(r,L"PowerPacker");
    case 2U:return xx_data_struct_record_set_comment(r,L"XPK; native decoder does not support compressed CYL1 records");
    default:break;}}
    if(id==0x60370022U&&!xx_rt_wcscmp(r->name,L"state")&&integer){switch(value){
    case 76U:return xx_data_struct_record_set_comment(r,L"Stored track");
    case 250U:return xx_data_struct_record_set_comment(r,L"Omitted track; restored with byte0xF6");
    case 254U:return xx_data_struct_record_set_comment(r,L"Omitted track; restored with byte0xF6");
    default:break;}}
    if(id==0x60370028U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored sector with CRC16");
    case 1U:return xx_data_struct_record_set_comment(r,L"Unreadable sector; native output is incomplete");
    default:break;}}
    if(id==0x60370029U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"Repeated byte sector");
    default:break;}}
    if(id==0x6037002aU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 3U:return xx_data_struct_record_set_comment(r,L"Comment");
    case 4U:return xx_data_struct_record_set_comment(r,L"Directory listing");
    default:break;}}
    if(id==0x6037002cU&&!xx_rt_wcscmp(r->name,L"drive_code")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"5.25 inch 360 KiB");
    case 1U:return xx_data_struct_record_set_comment(r,L"5.25 inch 1.2 MiB");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5 inch 720 KiB");
    case 7U:return xx_data_struct_record_set_comment(r,L"3.5 inch 1.44 MiB");
    case 9U:return xx_data_struct_record_set_comment(r,L"3.5 inch 2.88 MiB");
    default:break;}}
    if(id==0x60370038U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2D");
    case 1U:return xx_data_struct_record_set_comment(r,L"2DD");
    case 2U:return xx_data_struct_record_set_comment(r,L"2HD");
    case 9U:return xx_data_struct_record_set_comment(r,L"Sampled raw");
    default:break;}}
    if(id==0x6037003eU&&!xx_rt_wcscmp(r->name,L"distribution_disk")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Original distribution disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"Not an original distribution disk");
    case 3U:return xx_data_struct_record_set_comment(r,L"Appears to be a copy of a distribution disk");
    default:break;}}
    if(id==0x6037003fU&&!xx_rt_wcscmp(r->name,L"distribution_disk")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Original distribution disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"Not an original distribution disk");
    case 3U:return xx_data_struct_record_set_comment(r,L"Appears to be a copy of a distribution disk");
    default:break;}}
    if(id==0x6037003fU&&!xx_rt_wcscmp(r->name,L"header_data_source")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"H8D conversion utility");
    case 1U:return xx_data_struct_record_set_comment(r,L"Emulator");
    case 2U:return xx_data_struct_record_set_comment(r,L"Captured on H8/H89");
    case 3U:return xx_data_struct_record_set_comment(r,L"FC5025");
    case 4U:return xx_data_struct_record_set_comment(r,L"AppleSauce");
    default:break;}}
    switch(id){
    case 0x60370001U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Sum of all 128 big-endian header words is zero modulo 2^32.";
        break;
    case 0x60370002U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Block index in the physical image; block size is 512 bytes.";
        break;
    case 0x60370003U:
        if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"AmigaDOS root block number; zero may denote the default.";
        break;
    case 0x60370005U:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))s=L"Inclusive last cylinder index.";
        else if(!xx_rt_wcscmp(r->name,L"header_checksum"))s=L"Stored checksum; the native reader does not authenticate it.";
        break;
    case 0x60370007U:
        if(!xx_rt_wcscmp(r->name,L"cylinders"))s=L"0xFF marks an unused slot.";
        else if(!xx_rt_wcscmp(r->name,L"middle_size"))s=L"Zero means no RLE stage.";
        else if(!xx_rt_wcscmp(r->name,L"final_size"))s=L"Stored value; when middle_size is zero the decoder derives its final length from the sector masks.";
        break;
    case 0x60370008U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Initial 0 ends the catalogue; initial 1 denotes a deleted entry.";
        else if(!xx_rt_wcscmp(r->name,L"start_address"))s=L"Load/start address encoded by TR-DOS; some file types use this word for their own parameters.";
        break;
    case 0x6037000aU:
        if(!xx_rt_wcscmp(r->name,L"low_signature_or_state"))s=L"Native recognition does not constrain this byte.";
        break;
    case 0x6037000cU:
        if(!xx_rt_wcscmp(r->name,L"parent_directory"))s=L"Directory identity occupies the low byte; 0xFF marks an erased entry.";
        else if(!xx_rt_wcscmp(r->name,L"extension"))s=L"All zero denotes a directory.";
        else if(!xx_rt_wcscmp(r->name,L"attributes_or_directory_id"))s=L"File attributes; on a directory this is its identifier.";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 512-byte block index.";
        break;
    case 0x6037000dU:
        if(!xx_rt_wcscmp(r->name,L"geometry_hints"))s=L"Unresolved geometry bytes are preserved without inferred field meanings.";
        break;
    case 0x60370010U:
        if(!xx_rt_wcscmp(r->name,L"repeat_count"))s=L"Number of decoded bytes emitted for the following value.";
        break;
    case 0x60370012U:
        if(!xx_rt_wcscmp(r->name,L"directory_blocks_and_protection"))s=L"Low 7 bits are a block count; bit7 is write protection.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year, not a Unix timestamp.";
        break;
    case 0x60370013U:
        if(!xx_rt_wcscmp(r->name,L"name_and_type"))s=L"Filename followed by type byte and ETX within this physical field.";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 1024-byte EOS block index; the two sectors are interleaved on disk.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year; 00..49 are interpreted as 2000..2049 by the native reader.";
        break;
    case 0x60370014U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 1024-byte EOS block index.";
        else if(!xx_rt_wcscmp(r->name,L"allocated_blocks_low"))s=L"Low byte of the allocated-block count; high byte resides in the interleaved second sector.";
        break;
    case 0x60370015U:
        if(!xx_rt_wcscmp(r->name,L"allocated_blocks_high"))s=L"High byte of the allocated-block count; low byte resides in the first sector.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year.";
        break;
    case 0x60370017U:
        if(!xx_rt_wcscmp(r->name,L"side"))s=L"TOP or BOT with a terminating NUL.";
        else if(!xx_rt_wcscmp(r->name,L"data_crc"))s=L"IBM CRC16 of decoded 5632 sector bytes and 176 label bytes.";
        break;
    case 0x6037001bU:
        if(!xx_rt_wcscmp(r->name,L"presence_bitmap"))s=L"Low 22 bits indicate present sectors; each decoded sector includes 16 label bytes.";
        else if(!xx_rt_wcscmp(r->name,L"old_mode"))s=L"Stored compatibility byte; unused by LhWarp.";
        else if(!xx_rt_wcscmp(r->name,L"data_crc"))s=L"CRC32 over decoded sectors and labels.";
        break;
    case 0x6037001dU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Zero denotes an uncompressed 11264-byte cylinder.";
        break;
    case 0x6037001fU:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"CYL0 stores a full cylinder; CYL1 uses the header compression/transpose mode.";
        break;
    case 0x60370020U:
        if(!xx_rt_wcscmp(r->name,L"bytes_per_block"))s=L"Includes the 512-byte sector and any stored sector tags.";
        break;
    case 0x60370022U:
        if(!xx_rt_wcscmp(r->name,L"state"))s=L"0x4C stored; 0xFA or 0xFE omitted and restored as 0xF6.";
        break;
    case 0x60370023U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"Native reader supports zero (uncompressed) only.";
        break;
    case 0x60370024U:
        if(!xx_rt_wcscmp(r->name,L"block_length"))s=L"Six ASCII decimal digits giving payload byte length.";
        break;
    case 0x60370025U:
        if(!xx_rt_wcscmp(r->name,L"kind"))s=L"MRK filemark; EOT end of tape.";
        break;
    case 0x60370027U:
        if(!xx_rt_wcscmp(r->name,L"extra_flags"))s=L"Bit0 comment; bit1 directory listing.";
        break;
    case 0x6037002dU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Bytes per sector equal 128 shifted left by this value.";
        break;
    case 0x6037002eU:
        if(!xx_rt_wcscmp(r->name,L"cylinders_indices"))s=L"Inclusive highest cylinder index.";
        else if(!xx_rt_wcscmp(r->name,L"heads_indices"))s=L"Inclusive highest head index.";
        break;
    case 0x60370031U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 selects 256-byte sectors instead of 512-byte sectors.";
        break;
    case 0x60370032U:
        if(!xx_rt_wcscmp(r->name,L"serial_number_words"))s=L"ATA string bytes are swapped within each 16-bit word; shown as stored.";
        else if(!xx_rt_wcscmp(r->name,L"obsolete_buffer_size"))s=L"Obsolete buffer capacity in 512-byte units.";
        break;
    case 0x60370035U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Zero means no track; exact duplicate offsets may share a track.";
        break;
    case 0x60370036U:
        if(!xx_rt_wcscmp(r->name,L"index_bit_position"))s=L"Position in encoded bit cells, not a byte offset.";
        break;
    case 0x60370037U:
        if(!xx_rt_wcscmp(r->name,L"extra_bit_cells"))s=L"Signed adjustment; with disk flags0x1080 and zero speed bits it instead gives total bit-cell count.";
        break;
    case 0x60370038U:
        if(!xx_rt_wcscmp(r->name,L"transfer_rate"))s=L"Clock-inclusive transfer rate, normally 500 or 1000 kilobits per second.";
        else if(!xx_rt_wcscmp(r->name,L"options"))s=L"Currently unused by the published format.";
        break;
    case 0x60370039U:
        if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Encoded or sampled bit cells, not bytes.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Bounded wire metadata only. Optional damaged extents and display-budget
 * remainder stay raw. No native subclass casts or factory dependencies. */
#define SXST_LIMIT 24000U
#define SXST_ROWS 1048576U
bool sxst_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxst_read(sx_context*c,uint64_t p,void*b,size_t n){return sxst_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxst_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint16_t sxst16(const uint8_t*b){return (uint16_t)sxst_uint(b,2,false);}
uint32_t sxst32(const uint8_t*b){return (uint32_t)sxst_uint(b,4,false);}
bool sxst_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(n>8||!sxst_read(c,p,b,n))return false;*v=sxst_uint(b,n,be);return true;}
/* Keep metadata sorted as it is collected. Monotonic sector tables take
 * O(log n) overlap checks; out-of-order optional pointers insert in place. */
bool sxst_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>SXST_ROWS||n>(uint64_t)INT64_MAX/z||!sxst_span(c,p,n*z))return false;
 if(xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXST_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static int sxst_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxst_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxst_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxst_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_systemtail_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_IRIXSA:
case XX_FILE_TYPE_SOS:
case XX_FILE_TYPE_ZOOM:
case XX_FILE_TYPE_TRDOS:
case XX_FILE_TYPE_CSIDOS:
case XX_FILE_TYPE_COPYDISK:
case XX_FILE_TYPE_APRICOT:
case XX_FILE_TYPE_SDU:
case XX_FILE_TYPE_SABDU:
case XX_FILE_TYPE_ADAM:
case XX_FILE_TYPE_PC_MAGAZINE_FLP:
case XX_FILE_TYPE_WARP:
case XX_FILE_TYPE_LHWARP:
case XX_FILE_TYPE_COMPDISK:
case XX_FILE_TYPE_CRUNCHDISK:
case XX_FILE_TYPE_LISA_BLU:
case XX_FILE_TYPE_CISCOPY:
case XX_FILE_TYPE_COPYTAPE:
case XX_FILE_TYPE_WC_DISK_IMAGE:
case XX_FILE_TYPE_DRI_DISKCOPY:
case XX_FILE_TYPE_MAXI_DISK:
case XX_FILE_TYPE_RAY_DIM:
case XX_FILE_TYPE_RS_IDE:
case XX_FILE_TYPE_T98_HDD:
case XX_FILE_TYPE_PC_86F:
case XX_FILE_TYPE_FDX68_FDX:
case XX_FILE_TYPE_HEATHKIT_H17:
return true;default:return false;}}
static bool sx_systemtail_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_IRIXSA:ok=sx_irixsa_build(c);break;
case XX_FILE_TYPE_SOS:ok=sx_sos_build(c);break;
case XX_FILE_TYPE_ZOOM:ok=sx_zoom_build(c);break;
case XX_FILE_TYPE_TRDOS:ok=sx_trdos_build(c);break;
case XX_FILE_TYPE_CSIDOS:ok=sx_csidos_build(c);break;
case XX_FILE_TYPE_COPYDISK:ok=sx_copydisk_build(c);break;
case XX_FILE_TYPE_APRICOT:ok=sx_apricot_build(c);break;
case XX_FILE_TYPE_SDU:
case XX_FILE_TYPE_SABDU:ok=SXST_ADD(c,sabdu_header,0);break;
case XX_FILE_TYPE_ADAM:ok=sx_adam_build(c);break;
case XX_FILE_TYPE_PC_MAGAZINE_FLP:ok=sx_pc_magazine_flp_build(c);break;
case XX_FILE_TYPE_WARP:ok=sx_warp_build(c);break;
case XX_FILE_TYPE_LHWARP:ok=sx_lhwarp_build(c);break;
case XX_FILE_TYPE_COMPDISK:ok=sx_compdisk_build(c);break;
case XX_FILE_TYPE_CRUNCHDISK:ok=sx_crunchdisk_build(c);break;
case XX_FILE_TYPE_LISA_BLU:ok=sx_lisa_blu_build(c);break;
case XX_FILE_TYPE_CISCOPY:ok=sx_ciscopy_build(c);break;
case XX_FILE_TYPE_COPYTAPE:ok=sx_copytape_build(c);break;
case XX_FILE_TYPE_WC_DISK_IMAGE:ok=sx_wc_disk_image_build(c);break;
case XX_FILE_TYPE_DRI_DISKCOPY:ok=sx_dri_diskcopy_build(c);break;
case XX_FILE_TYPE_MAXI_DISK:ok=sx_maxi_disk_build(c);break;
case XX_FILE_TYPE_RAY_DIM:ok=sx_ray_dim_build(c);break;
case XX_FILE_TYPE_RS_IDE:ok=sx_rs_ide_build(c);break;
case XX_FILE_TYPE_T98_HDD:ok=sx_t98_hdd_build(c);break;
case XX_FILE_TYPE_PC_86F:ok=sx_pc_86f_build(c);break;
case XX_FILE_TYPE_FDX68_FDX:ok=sx_fdx68_fdx_build(c);break;
case XX_FILE_TYPE_HEATHKIT_H17:ok=sx_heathkit_h17_build(c);break;
default:break;}return ok&&sxst_finish(c);}
#undef SXST_ADD
#undef SXST_TABLE
#undef SXST_LIMIT
#undef SXST_ROWS
const sx_family sx_systemtail_family={sx_systemtail_supports,sx_systemtail_build,sx_systemtail_layouts,SX_COUNT(sx_systemtail_layouts),sx_systemtail_comment};
