/* Utage byte-preserving modified-XOR spans. Values remain stored ciphertext. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_utagemedia.h"

static const sx_layout*const sx_utagemedia_layouts[]={&sxutg_png_signature,&sxutg_png_chunk,&sxutg_png_ihdr,&sxutg_png_crc,&sxutg_bmp_file,&sxutg_bmp_core,&sxutg_bmp_info,&sxutg_jpeg_marker,&sxutg_jpeg_segment,&sxutg_jpeg_frame,&sxutg_jpeg_frame_component,&sxutg_jpeg_scan,&sxutg_jpeg_scan_component,&sxutg_jpeg_scan_parameters,&sxutg_riff_webp,&sxutg_riff_chunk,&sxutg_webp_vp8x,&sxutg_webp_vp8l,&sxutg_webp_vp8,&sxutg_ogg_page,&sxutg_ogg_lacing,&sxutg_isobmff_box,&sxutg_isobmff_large_box,&sxutg_isobmff_ftyp,&sxutg_isobmff_brand,&sxutg_isobmff_uuid};
static bool sx_utagemedia_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_UTAGE_MEDIA:return true;default:return false;}}
static bool sx_utagemedia_build(sx_context*c){
 if(!c||!c->f||c->f->file_type!=XX_FILE_TYPE_UTAGE_MEDIA||c->size<32||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return sx_utage_media_build(c);
}
static bool sx_utagemedia_comment(xx_data_struct_record*r,uint32_t id){if((id&UINT32_C(0xffff0000))!=UINT32_C(0x609c0000))return true;if(!r)return false;return xx_data_struct_record_set_comment(r,L"Physical Utage modified-XOR ciphertext bytes for the named media field. These are encoded bytes, not the decoded numeric/string value. The byte-preserving transform identifies this original-file span; compressed media payload remains raw.");}
const sx_family sx_utagemedia_family={sx_utagemedia_supports,sx_utagemedia_build,sx_utagemedia_layouts,SX_COUNT(sx_utagemedia_layouts),sx_utagemedia_comment};
