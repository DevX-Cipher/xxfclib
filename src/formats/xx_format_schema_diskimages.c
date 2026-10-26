/* SPDX-License-Identifier: MIT
 * Physical disk-image metadata. See docs/data_struct_diskimages_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_diskimages.h"

static const xx_data_struct_field_desc sxdi_disk_fill_byte_fields[] = {
    SX_FIELD("fill_value","uint8",0,1,SX_ID),
};
const sx_layout sxdi_disk_fill_byte = {UINT32_C(0x60150008),"disk_fill_byte",sxdi_disk_fill_byte_fields,SX_COUNT(sxdi_disk_fill_byte_fields),SX_LE};
static const sx_layout *const sx_diskimages_layouts[] = {
    &sxdi_anadisk_sector_header,
    &sxdi_transcopy_header,
    &sxdi_transcopy_geometry,
    &sxdi_transcopy_track_offset,
    &sxdi_transcopy_track_length,
    &sxdi_copyqm_header,
    &sxdi_copyqm_rle_token,
    &sxdi_disk_fill_byte,
    &sxdi_imd_track_header,
    &sxdi_imd_sector_id,
    &sxdi_imd_cylinder_map,
    &sxdi_imd_head_map,
    &sxdi_imd_size_map,
    &sxdi_imd_sector_status,
    &sxdi_fdi_header,
    &sxdi_fdi_track_header,
    &sxdi_fdi_sector_header,
    &sxdi_nec_pc98_fdi_header,
    &sxdi_teledisk_header,
    &sxdi_teledisk_comment,
    &sxdi_teledisk_track,
    &sxdi_teledisk_end,
    &sxdi_teledisk_sector,
    &sxdi_teledisk_data_block,
    &sxdi_d88_disk_header,
    &sxdi_d88_track_offset,
    &sxdi_d88_sector_header,
    &sxdi_ipf_chunk_header,
    &sxdi_ipf_info,
    &sxdi_ipf_image,
    &sxdi_ipf_data,
    &sxdi_ipf_block_encoder1,
    &sxdi_ipf_block_encoder2,
};
static bool sx_diskimages_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60150000U||id>=0x60160000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60150001U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Encoded nominal sector size: 128 << value; stored payload length is independent.";
        break;
    case 0x60150003U:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))text=L"Zero-based last cylinder, not a cylinder count.";
        break;
    case 0x60150004U:
        if(!xx_rt_wcscmp(r->name,L"offset_in_256_byte_units"))text=L"File byte offset = value << 8; zero marks an absent track.";
        break;
    case 0x60150005U:
        if(!xx_rt_wcscmp(r->name,L"byte_length"))text=L"Absent tracks may retain the original 0x3333 filler; offset zero takes precedence.";
        break;
    case 0x60150006U:
        if(!xx_rt_wcscmp(r->name,L"blind_mode"))text=L"0=DOS, 1=blind copy, 2=HFS.";
        if(!xx_rt_wcscmp(r->name,L"density"))text=L"0=double, 1=high, 2=extended.";
        if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: hours bits11..15, minutes bits5..10, two-second units bits0..4.";
        if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: year since1980 bits9..15, month bits5..8, day bits0..4.";
        if(!xx_rt_wcscmp(r->name,L"first_sector_minus_one"))text=L"First sector ID is this encoded value plus one.";
        if(!xx_rt_wcscmp(r->name,L"skew"))text=L"Signed track skew; negative values select alternating sides.";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Sum of all 133 header bytes modulo256 is zero.";
        break;
    case 0x60150007U:
        if(!xx_rt_wcscmp(r->name,L"signed_run_length"))text=L"Positive: literal byte count; negative: repeat next byte -value times; zero: end marker.";
        break;
    case 0x60150008U:
        if(!xx_rt_wcscmp(r->name,L"fill_value"))text=L"Repeated byte stored physically once; expanded bytes have no file offsets.";
        break;
    case 0x60150009U:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"ImageDisk data-rate and recording-mode code.";
        if(!xx_rt_wcscmp(r->name,L"head_and_maps"))text=L"Bit0=head, bit6=head map present, bit7=cylinder map present.";
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))text=L"0..6: 128 << value bytes; 255: per-sector uint16 size map follows.";
        break;
    case 0x6015000eU:
        if(!xx_rt_wcscmp(r->name,L"status"))text=L"0=unavailable; 1/3/5/7=stored; 2/4/6/8=fill; variants encode deleted-data and error status.";
        break;
    case 0x6015000fU:
        if(!xx_rt_wcscmp(r->name,L"write_protected"))text=L"0=write enabled, 1=write protected.";
        break;
    case 0x60150010U:
        if(!xx_rt_wcscmp(r->name,L"track_data_offset"))text=L"Byte offset relative to the file header data_offset, not absolute.";
        break;
    case 0x60150011U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Nominal sector size is 128 << value bytes.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit7=deleted data; bits0..5 record valid CRC for 128 through4096-byte reads; bit6 reserved.";
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to this track data area.";
        break;
    case 0x60150013U:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"TD=uncompressed physical records; td=whole-body compressed.";
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Decimal version multiplied by10.";
        if(!xx_rt_wcscmp(r->name,L"rate_and_fm"))text=L"Low7 bits: 0=250,1=300,2=500 kbit/s; bit7=FM.";
        if(!xx_rt_wcscmp(r->name,L"stepping_and_comment"))text=L"Low bits describe drive/media stepping; bit7 marks an optional comment.";
        break;
    case 0x60150014U:
        if(!xx_rt_wcscmp(r->name,L"year_since_1900"))text=L"Calendar component; not a Unix timestamp.";
        break;
    case 0x60150015U:
        if(!xx_rt_wcscmp(r->name,L"head_and_fm"))text=L"Low bits identify head; bit7 is FM.";
        break;
    case 0x60150017U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Nominal sector size is 128 << value bytes.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits4/5 omit data; other bits preserve duplicate, CRC, deleted and skipped-sector status.";
        break;
    case 0x60150018U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))text=L"Number of bytes beginning with the method byte, including that method.";
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=literal, 1=two-byte pattern, 2=RLE fragments.";
        break;
    case 0x6015001aU:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))text=L"Byte offset from the start of the containing disk image; zero means no track.";
        break;
    case 0x6015001bU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Encoded nominal size: 128 << value; actual stored size is separate.";
        break;
    case 0x6015001cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes the12-byte chunk header; DATA payload follows outside this size.";
        if(!xx_rt_wcscmp(r->name,L"header_crc"))text=L"CRC calculated with this field zero.";
        break;
    case 0x6015001dU:
        if(!xx_rt_wcscmp(r->name,L"creation_date"))text=L"Decimal packed calendar date YYYYMMDD; not Unix seconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Decimal packed time HHMMSSTTT; final3 digits are milliseconds.";
        break;
    case 0x6015001eU:
        if(!xx_rt_wcscmp(r->name,L"track_size_rounded"))text=L"Rounded decoded track-size quantity as stored by the encoder.";
        if(!xx_rt_wcscmp(r->name,L"start_position_rounded"))text=L"Rounded decoded start position; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"start_bit"))text=L"Position in decoded track bits; not a file byte offset.";
        break;
    case 0x60150020U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to DATA payload.";
        break;
    case 0x60150021U:
        if(!xx_rt_wcscmp(r->name,L"gap_offset"))text=L"Byte offset relative to DATA payload.";
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to DATA payload.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
bool sxdi_span(sx_context *c,uint64_t at,uint64_t n){return c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
bool sxdi_read(sx_context *c,uint64_t at,void *p,size_t n){return sxdi_span(c,at,n)&&sx_read(c,(int64_t)at,p,n);}
uint16_t sxdi_le16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
uint32_t sxdi_le32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static int sxdi_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdi_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdi_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdi_order);return !c->failed;
}
static bool sx_diskimages_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_PCE_ANADISK:case XX_FILE_TYPE_PCE_TC:case XX_FILE_TYPE_COPYQM:case XX_FILE_TYPE_IMD:case XX_FILE_TYPE_FDI:case XX_FILE_TYPE_NEC_PC_98_FDI:case XX_FILE_TYPE_TELEDISK:case XX_FILE_TYPE_PC98_D88:case XX_FILE_TYPE_AMIGA_IPF:return true;default:return false;}
}
static bool sx_diskimages_build(sx_context *c)
{
    bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_PCE_ANADISK:ok=sx_pce_anadisk_build(c);break;case XX_FILE_TYPE_PCE_TC:ok=sx_pce_tc_build(c);break;case XX_FILE_TYPE_COPYQM:ok=sx_copyqm_build(c);break;case XX_FILE_TYPE_IMD:ok=sx_imd_build(c);break;case XX_FILE_TYPE_FDI:ok=sx_fdi_build(c);break;case XX_FILE_TYPE_NEC_PC_98_FDI:ok=sx_nec_pc_98_fdi_build(c);break;case XX_FILE_TYPE_TELEDISK:ok=sx_teledisk_build(c);break;case XX_FILE_TYPE_PC98_D88:ok=sx_pc98_d88_build(c);break;case XX_FILE_TYPE_AMIGA_IPF:ok=sx_amiga_ipf_build(c);break;default:break;}return ok&&sxdi_finish(c);
}
const sx_family sx_diskimages_family={sx_diskimages_supports,sx_diskimages_build,sx_diskimages_layouts,SX_COUNT(sx_diskimages_layouts),sx_diskimages_comment};
