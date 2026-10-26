/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UNIX PACK data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_unix_pack_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 2, 4, SX_SIZE),
};
const sx_layout sx_p_unix_pack_header = { UINT32_C(0x6007003D), "unix_pack_header", sx_p_unix_pack_header_fields, SX_COUNT(sx_p_unix_pack_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pack_tree_fields[] = {
    SX_FIELD("maximum_code_length", "uint8", 0, 1, SX_COUNT_PROP),
};
const sx_layout sx_p_pack_tree = { UINT32_C(0x60070058), "pack_tree", sx_p_pack_tree_fields, SX_COUNT(sx_p_pack_tree_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pack_literal_fields[] = {
    SX_FIELD("literal", "uint8", 0, 1, SX_ID),
};
const sx_layout sx_p_pack_literal = { UINT32_C(0x6007005A), "pack_literal", sx_p_pack_literal_fields, SX_COUNT(sx_p_pack_literal_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_pack_old_tree_fields[] = {
    SX_FIELD("entry_count", "uint16", 0, 2, SX_COUNT_PROP),
};
const sx_layout sx_p_pack_old_tree = { UINT32_C(0x6007005C), "pack_old_tree", sx_p_pack_old_tree_fields, SX_COUNT(sx_p_pack_old_tree_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pack_old_node_fields[] = {
    SX_FIELD("value", "uint8", 0, 1, SX_NONE),
};
const sx_layout sx_p_pack_old_node = { UINT32_C(0x6007005D), "pack_old_node", sx_p_pack_old_node_fields, SX_COUNT(sx_p_pack_old_node_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_pack_old_wide_node_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("value", "uint16", 1, 2, SX_NONE),
};
const sx_layout sx_p_pack_old_wide_node = { UINT32_C(0x6007005E), "pack_old_wide_node", sx_p_pack_old_wide_node_fields, SX_COUNT(sx_p_pack_old_wide_node_fields), SX_LE };
bool sx_unixpack_build(sx_context*c)
{
    uint8_t b[16];bool ok=false;
        ok=sx_read(c,0,b,6)&&b[0]==0x1f&&(b[1]==0x1e||b[1]==0x1f)&&sx_add(c,b[1]==0x1e?&sx_p_unix_pack_header:&sx_p_unix_pack_old_header,0,6);
        if(ok&&b[1]==0x1e){uint8_t depth,counts[24];ok=sx_p_byte(c,6,&depth)&&depth>0&&depth<=24&&sx_read(c,7,counts,depth)&&counts[depth-1]<=253&&sx_add(c,&sx_p_pack_tree,6,1)&&sx_table(c,&sx_p_pack_level,7,1,depth);unsigned literals=1;if(ok){for(unsigned i=0;i<depth;i++)literals+=counts[i];ok=literals<=256&&sx_table(c,&sx_p_pack_literal,7+depth,1,literals);}}
        else if(ok){uint16_t count;ok=sx_u16(c,6,false,&count)&&count>=2&&count<1024&&sx_add(c,&sx_p_pack_old_tree,6,2);int64_t off=8;for(unsigned i=0;ok&&i<count;i++){uint8_t marker;ok=sx_p_byte(c,off,&marker);if(ok){unsigned size=marker==255?3:1;ok=sx_add(c,marker==255?&sx_p_pack_old_wide_node:&sx_p_pack_old_node,off,size);off+=size;}}}
    return ok;
}
