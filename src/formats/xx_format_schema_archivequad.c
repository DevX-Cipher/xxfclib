/* SPDX-License-Identifier: MIT
 * QUAD1.12 physical signed output-length word, as serialized by the original
 * encoder. The adaptive entropy stream has no further independently stored
 * fixed header members and remains raw. Native validation uses the optional
 * standalone decoder; no codec implementation is linked into the C library.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivequad.h"

static const xx_data_struct_field_desc sxquad_header_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE)
};
const sx_layout sxquad_header={UINT32_C(0x60960001),"quad_header",sxquad_header_fields,SX_COUNT(sxquad_header_fields),SX_LE};
static const sx_layout*const sx_archivequad_layouts[]={&sxquad_header};
static bool sx_archivequad_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_QUAD:return true;default:return false;}}
static bool sx_archivequad_build(sx_context*c){
 if(!c||!c->f||c->f->file_type!=XX_FILE_TYPE_QUAD)return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return sx_quad_build(c);
}
static bool sx_archivequad_comment(xx_data_struct_record*r,uint32_t id){
 if(id!=sxquad_header.id)return true;
 if(!r||!r->name)return false;
 return xx_rt_wcscmp(r->name,L"uncompressed_size")||xx_data_struct_record_set_comment(r,L"Signed nonnegative decoded byte count; original QUAD1.12 writes a four-byte little-endian int. Entropy-coded payload positions are not decoded-member coordinates.");
}
const sx_family sx_archivequad_family={sx_archivequad_supports,sx_archivequad_build,sx_archivequad_layouts,SX_COUNT(sx_archivequad_layouts),sx_archivequad_comment};
