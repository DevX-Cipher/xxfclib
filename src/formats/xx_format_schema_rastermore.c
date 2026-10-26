/* SPDX-License-Identifier: MIT
 * Physical raster metadata. Scope: docs/data_struct_rastermore_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_rastermore.h"
static const sx_layout *const sx_rastermore_layouts[] = {
    &sxrm_vtf70_header,
    &sxrm_vtf72_header,
    &sxrm_exr_header,
    &sxrm_exr_attribute_length,
    &sxrm_exr_channel,
    &sxrm_exr_box2i,
    &sxrm_exr_float,
    &sxrm_exr_v2f,
    &sxrm_exr_compression,
    &sxrm_exr_line_order,
    &sxrm_exr_chunk_offset,
    &sxrm_exr_scanline_chunk,
    &sxrm_jp2_box,
    &sxrm_jp2_extended_size,
    &sxrm_jp2_signature,
    &sxrm_jp2_file_type,
    &sxrm_jp2_compatible_brand,
    &sxrm_jp2_image_header,
    &sxrm_jp2_color_header,
    &sxrm_jp2_enumerated_color,
    &sxrm_j2k_marker,
    &sxrm_j2k_segment_length,
    &sxrm_j2k_siz,
    &sxrm_j2k_component,
    &sxrm_j2k_sot,
    &sxrm_bntx_header,
    &sxrm_bntx_container,
    &sxrm_bntx_block,
    &sxrm_bntx_texture_info,
    &sxrm_bntx_pointer,
    &sxrm_bntx_string_length,
    &sxrm_bntx_relocation_header,
    &sxrm_gvr_prefix,
    &sxrm_gvr_dimensions,
    &sxrm_ilbm_form,
    &sxrm_ilbm_chunk,
    &sxrm_ilbm_bitmap_header,
    &sxrm_ilbm_palette_entry,
    &sxrm_ilbm_view_mode,
    &sxrm_utah_rle_header,
    &sxrm_utah_background,
    &sxrm_utah_colormap,
    &sxrm_utah_comment_length,
    &sxrm_utah_opcode,
    &sxrm_utah_long_opcode,
    &sxrm_utah_run_value,
    &sxrm_dpx_file_header_be,
    &sxrm_dpx_image_header_be,
    &sxrm_dpx_element_be,
    &sxrm_dpx_image_reserved_be,
    &sxrm_dpx_orientation_be,
    &sxrm_dpx_film_be,
    &sxrm_dpx_television_be,
    &sxrm_cineon_file_header_be,
    &sxrm_cineon_image_header_be,
    &sxrm_cineon_channel_be,
    &sxrm_cineon_color_be,
    &sxrm_cineon_data_format_be,
    &sxrm_cineon_origin_be,
    &sxrm_cineon_film_be,
    &sxrm_dpx_file_header_le,
    &sxrm_dpx_image_header_le,
    &sxrm_dpx_element_le,
    &sxrm_dpx_image_reserved_le,
    &sxrm_dpx_orientation_le,
    &sxrm_dpx_film_le,
    &sxrm_dpx_television_le,
    &sxrm_cineon_file_header_le,
    &sxrm_cineon_image_header_le,
    &sxrm_cineon_channel_le,
    &sxrm_cineon_color_le,
    &sxrm_cineon_data_format_le,
    &sxrm_cineon_origin_le,
    &sxrm_cineon_film_le,
    &sxrm_aseprite_header,
    &sxrm_aseprite_frame,
    &sxrm_aseprite_chunk,
    &sxrm_aseprite_layer,
    &sxrm_aseprite_layer_uuid,
    &sxrm_aseprite_cel,
    &sxrm_aseprite_cel_dimensions,
    &sxrm_aseprite_linked_cel,
    &sxrm_aseprite_palette,
    &sxrm_aseprite_palette_entry,
    &sxrm_aseprite_string_length,
    &sxrm_aseprite_user_flags,
    &sxrm_aseprite_rgba,
    &sxrm_godot_ctex_header,
    &sxrm_jbig2_file_header,
    &sxrm_jbig2_page_count,
    &sxrm_jbig2_segment_prefix,
    &sxrm_jbig2_reference1,
    &sxrm_jbig2_reference2,
    &sxrm_jbig2_reference4,
    &sxrm_jbig2_segment_tail1,
    &sxrm_jbig2_segment_tail4,
    &sxrm_jbig2_page_info,
    &sxrm_jbig2_region,
    &sxrm_jbig2_extension,
    &sxrm_raf_header,
    &sxrm_raf_metadata_count,
    &sxrm_raf_metadata_entry,
    &sxrm_raf_dimensions,
    &sxrm_x3f_header20,
    &sxrm_x3f_header21,
    &sxrm_x3f_header23,
    &sxrm_x3f_directory_offset,
    &sxrm_x3f_directory,
    &sxrm_x3f_directory_entry,
    &sxrm_x3f_image,
    &sxrm_x3f_camf2,
    &sxrm_x3f_properties,
    &sxrm_x3f_property,
    &sxrm_mrw_header,
    &sxrm_mrw_chunk,
    &sxrm_mrw_prd,
    &sxrm_mrw_white_balance,
    &sxrm_mrw_tiff_header_le,
    &sxrm_mrw_tiff_header_be,
    &sxrm_basis_header,
    &sxrm_basis_slice,
};
static bool sx_rastermore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601d0000U||id>=0x601e0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x601d0001U:
        if(!xx_rt_wcscmp(r->name,L"first_frame"))text=L"Cubemaps use 65535 for six faces; other supported values include the legacy sphere-map face.";
        if(!xx_rt_wcscmp(r->name,L"low_resolution_format"))text=L"-1 means no low-resolution image.";
        break;
    case 0x601d0002U:
        if(!xx_rt_wcscmp(r->name,L"first_frame"))text=L"Cubemaps use 65535 for six faces; other supported values include the legacy sphere-map face.";
        if(!xx_rt_wcscmp(r->name,L"low_resolution_format"))text=L"-1 means no low-resolution image.";
        break;
    case 0x601d0003U:
        if(!xx_rt_wcscmp(r->name,L"version_and_flags"))text=L"Low byte is the version; upper bits are file feature flags.";
        break;
    case 0x601d0005U:
        if(!xx_rt_wcscmp(r->name,L"pixel_type"))text=L"0=UINT, 1=HALF, 2=FLOAT.";
        break;
    case 0x601d0009U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=NONE, 1=RLE, 2=ZIPS, 3=ZIP, 4=PIZ, 5=PXR24, 6=B44, 7=B44A, 8=DWAA, 9=DWAB, 10=HTJ2K256, 11=HTJ2K32.";
        break;
    case 0x601d000aU:
        if(!xx_rt_wcscmp(r->name,L"order"))text=L"0=increasing Y, 1=decreasing Y, 2=random Y.";
        break;
    case 0x601d000dU:
        if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Zero extends to parent end; one selects the following extended size.";
        break;
    case 0x601d0012U:
        if(!xx_rt_wcscmp(r->name,L"bits_per_component"))text=L"Bit 7 is signedness; bits 0..6 store bit depth minus one; 255 uses BPCC.";
        break;
    case 0x601d0016U:
        if(!xx_rt_wcscmp(r->name,L"segment_size"))text=L"Includes this length field; excludes the two-byte marker.";
        break;
    case 0x601d0018U:
        if(!xx_rt_wcscmp(r->name,L"precision_and_sign"))text=L"Bit 7 is signedness; bits 0..6 store precision minus one.";
        break;
    case 0x601d0019U:
        if(!xx_rt_wcscmp(r->name,L"tile_part_size"))text=L"Includes the SOT marker and all bytes through this tile part.";
        break;
    case 0x601d001aU:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Alignment is 1 shifted left by this value, in bytes.";
        break;
    case 0x601d0021U:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Byte count after the eight-byte chunk prefix.";
        if(!xx_rt_wcscmp(r->name,L"palette_format_and_flags"))text=L"High nibble is the palette format; low nibble contains texture flags.";
        break;
    case 0x601d0023U:
        if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Bytes following the eight-byte FORM prefix.";
        break;
    case 0x601d0028U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=clear first, 2=no background, 4=alpha, 8=comments.";
        if(!xx_rt_wcscmp(r->name,L"colormap_length_log2"))text=L"Entries per colormap channel are 1 shifted left by this value.";
        break;
    case 0x601d002cU:
        if(!xx_rt_wcscmp(r->name,L"operand"))text=L"Byte/run data counts store count minus one; other meanings depend on opcode.";
        break;
    case 0x601d002dU:
        if(!xx_rt_wcscmp(r->name,L"operand"))text=L"Byte/run data counts store count minus one; other meanings depend on opcode.";
        break;
    case 0x601d0033U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0035U:
        if(!xx_rt_wcscmp(r->name,L"time_code"))text=L"Packed SMPTE timecode, not a Unix timestamp.";
        break;
    case 0x601d003bU:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0041U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0043U:
        if(!xx_rt_wcscmp(r->name,L"time_code"))text=L"Packed SMPTE timecode, not a Unix timestamp.";
        break;
    case 0x601d0049U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d004bU:
        if(!xx_rt_wcscmp(r->name,L"color_count"))text=L"Zero denotes 256 colors in older sprites.";
        break;
    case 0x601d004cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_count"))text=L"If zero, use old_chunk_count.";
        break;
    case 0x601d0053U:
        if(!xx_rt_wcscmp(r->name,L"palette_size"))text=L"Number of entries, not byte size.";
        break;
    case 0x601d0058U:
        if(!xx_rt_wcscmp(r->name,L"mipmap_count"))text=L"Number of additional levels after the base image.";
        break;
    case 0x601d0059U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=sequential; bit 1=page count unknown.";
        break;
    case 0x601d005bU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Low 6 bits=type; bit 6=wide page association; bit 7=deferred non-retain.";
        if(!xx_rt_wcscmp(r->name,L"reference_count_and_retention"))text=L"High 3 bits=count (native short form); low bits=retention flags.";
        break;
    case 0x601d0063U:
        if(!xx_rt_wcscmp(r->name,L"extension_type"))text=L"Bit 31 marks a necessary extension; other bits identify its type.";
        break;
    case 0x601d0064U:
        if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Uninterpreted header bytes; no field meaning is asserted.";
        break;
    case 0x601d0070U:
        if(!xx_rt_wcscmp(r->name,L"string_pool_codeunits"))text=L"Length in UTF-16 code units, not bytes.";
        break;
    case 0x601d0071U:
        if(!xx_rt_wcscmp(r->name,L"name_index"))text=L"UTF-16 code-unit index relative to the string pool.";
        if(!xx_rt_wcscmp(r->name,L"value_index"))text=L"UTF-16 code-unit index relative to the string pool.";
        break;
    case 0x601d0072U:
        if(!xx_rt_wcscmp(r->name,L"metadata_size"))text=L"Byte length after this header; raw image starts at 8 plus this value.";
        break;
    case 0x601d0074U:
        if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Uninterpreted camera-specific PRD bytes.";
        break;
    case 0x601d0075U:
        if(!xx_rt_wcscmp(r->name,L"denominator_exponents"))text=L"Four encoded gain denominators; the channel order depends on the PRD Bayer pattern.";
        break;
    case 0x601d0076U:
        if(!xx_rt_wcscmp(r->name,L"first_ifd_offset"))text=L"Relative to this embedded TIFF header.";
        break;
    case 0x601d0077U:
        if(!xx_rt_wcscmp(r->name,L"first_ifd_offset"))text=L"Relative to this embedded TIFF header.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
/* Describes stored metadata only. Pixel decoding is deliberately outside this provider. */
bool sxrm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxrm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxrm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxrm_uint(const uint8_t *b,unsigned n,bool be){uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return x;}
uint16_t sxrm16(const uint8_t *b,bool be){return (uint16_t)sxrm_uint(b,2,be);}
uint32_t sxrm32(const uint8_t *b,bool be){return (uint32_t)sxrm_uint(b,4,be);}
/* Pointer aliases are described once. Ambiguous partial overlaps remain covered by the first physical record. */
bool sxrm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n)
{
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);
 if(!n)return true;if(n>20000||!sxrm_span(c,p,z*n))return false;
 for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=a+(uint64_t)c->items[i].total_size;if(p<b&&a<p+z*n)return true;}
 return sx_table(c,l,(int64_t)p,(int64_t)z,n);
}
bool sxrm_add(sx_context *c,const sx_layout *l,uint64_t p){return sxrm_table(c,l,p,1);}
static int sxrm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxrm_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxrm_order);
 for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxrm_order);return !c->failed;
}
static bool sx_rastermore_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_VALVE_VTF:case XX_FILE_TYPE_OPENEXR:case XX_FILE_TYPE_JPEG2000_JP2:case XX_FILE_TYPE_NINTENDO_BNTX:case XX_FILE_TYPE_SEGA_GVR:case XX_FILE_TYPE_IFF_ILBM:case XX_FILE_TYPE_UTAH_RLE:case XX_FILE_TYPE_DPX:case XX_FILE_TYPE_CINEON:case XX_FILE_TYPE_ASEPRITE:case XX_FILE_TYPE_GODOT_CTEX:case XX_FILE_TYPE_JBIG2:case XX_FILE_TYPE_FUJIFILM_RAF:case XX_FILE_TYPE_SIGMA_X3F:case XX_FILE_TYPE_MINOLTA_MRW:case XX_FILE_TYPE_BASIS_TEXTURE:return true;default:return false;}
}
static bool sx_rastermore_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_VALVE_VTF:ok=sx_valve_vtf_build(c);break;case XX_FILE_TYPE_OPENEXR:ok=sx_openexr_build(c);break;case XX_FILE_TYPE_JPEG2000_JP2:ok=sx_jpeg2000_jp2_build(c);break;case XX_FILE_TYPE_NINTENDO_BNTX:ok=sx_nintendo_bntx_build(c);break;case XX_FILE_TYPE_SEGA_GVR:ok=sx_sega_gvr_build(c);break;case XX_FILE_TYPE_IFF_ILBM:ok=sx_iff_ilbm_build(c);break;case XX_FILE_TYPE_UTAH_RLE:ok=sx_utah_rle_build(c);break;case XX_FILE_TYPE_DPX:ok=sx_dpx_build(c);break;case XX_FILE_TYPE_CINEON:ok=sx_cineon_build(c);break;case XX_FILE_TYPE_ASEPRITE:ok=sx_aseprite_build(c);break;case XX_FILE_TYPE_GODOT_CTEX:ok=sx_godot_ctex_build(c);break;case XX_FILE_TYPE_JBIG2:ok=sx_jbig2_build(c);break;case XX_FILE_TYPE_FUJIFILM_RAF:ok=sx_fujifilm_raf_build(c);break;case XX_FILE_TYPE_SIGMA_X3F:ok=sx_sigma_x3f_build(c);break;case XX_FILE_TYPE_MINOLTA_MRW:ok=sx_minolta_mrw_build(c);break;case XX_FILE_TYPE_BASIS_TEXTURE:ok=sx_basis_texture_build(c);break;default:break;}return ok&&c->count>0&&sxrm_finish(c);
}
const sx_family sx_rastermore_family={sx_rastermore_supports,sx_rastermore_build,sx_rastermore_layouts,SX_COUNT(sx_rastermore_layouts),sx_rastermore_comment};
