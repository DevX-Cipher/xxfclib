/* Panorama byte-preserving XOR fields. Every value is stored ciphertext, not a decoded numeric value. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_panorama.h"
static const sx_layout*const sx_panorama_layouts[]={&sxpano_signature,&sxpano_base_header,&sxpano_main_header,&sxpano_file_header,&sxpano_large_sizes,&sxpano_file_name,&sxpano_salt,&sxpano_long_block_size,&sxpano_end_data_crc,&sxpano_end_volume,&sxpano_comment_header,&sxpano_old_service_header,&sxpano_recovery_header};
static bool sx_panorama_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PANORAMA:return true;default:return false;}}
static bool sx_panorama_build(sx_context*c){
 if(!c||!c->f||c->f->file_type!=XX_FILE_TYPE_PANORAMA||c->size<32||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return sx_panorama_schema_build(c);
}
static bool sx_panorama_comment(xx_data_struct_record*r,uint32_t id){
 if((id&UINT32_C(0xffff0000))!=UINT32_C(0x60970000))return true;
 if(!r)return false;
 return xx_data_struct_record_set_comment(r,L"Physical Panorama XOR ciphertext bytes for the named RAR4 field. These are encoded bytes, not the decoded numeric/string value. The byte-preserving stream transform identifies the span; no decompressed-member coordinates are used.");
}
const sx_family sx_panorama_family={sx_panorama_supports,sx_panorama_build,sx_panorama_layouts,SX_COUNT(sx_panorama_layouts),sx_panorama_comment};
