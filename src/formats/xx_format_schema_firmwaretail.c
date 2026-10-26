/* SPDX-License-Identifier: MIT
 * Authenticated physical firmware prefixes. These formats have no generic
 * length-bearing header; unclassified image bodies remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_firmwaretail.h"

static const sx_layout*const sx_firmwaretail_layouts[]={&sxftl_ecos_exception_prefix_le,&sxftl_ecos_exception_prefix_le_nop,&sxftl_ecos_exception_prefix_be,&sxftl_ecos_exception_prefix_be_nop};
static bool sx_firmwaretail_supports(xx_file_type_t type)
{return type==XX_FILE_TYPE_ECOS;}
static bool sx_firmwaretail_build(sx_context*c)
{
    if(!c||!c->f||!sx_firmwaretail_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    return sx_ecos_build(c);
}
static bool sx_firmwaretail_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60860001U||id>0x60860004U)return true;
    if(!xx_rt_wcscmp(r->name,L"cause_instruction"))return xx_data_struct_record_set_comment(r,L"MIPS mfc0 $k0, Cause instruction word; not an address or image length.");
    if(!xx_rt_wcscmp(r->name,L"nop_instruction"))return xx_data_struct_record_set_comment(r,L"Optional MIPS nop instruction.");
    if(!xx_rt_wcscmp(r->name,L"mask_instruction"))return xx_data_struct_record_set_comment(r,L"MIPS andi $k0, $k0, 0x7F instruction word.");

    return true;
}
const sx_family sx_firmwaretail_family={sx_firmwaretail_supports,sx_firmwaretail_build,sx_firmwaretail_layouts,SX_COUNT(sx_firmwaretail_layouts),sx_firmwaretail_comment};
