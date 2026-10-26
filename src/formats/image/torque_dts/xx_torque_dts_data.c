/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Torque DTS shapes data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_dts_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_NONE),
    SX_FIELD("buffer_size_words","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("start16_words","uint32",8,4,SX_NONE),
    SX_FIELD("start8_words","uint32",12,4,SX_NONE),
};
const sx_layout sxbrs_dts_header = {UINT32_C(0x603e000a),"dts_header",sxbrs_dts_header_fields,SX_COUNT(sxbrs_dts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_counts_fields[] = {
    SX_FIELD("num_nodes","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("num_objects","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("num_decals","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("num_subshapes","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("num_ifl_materials","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("num_node_rotations","int32",20,4,SX_COUNT_PROP),
    SX_FIELD("num_node_translations","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("num_node_uniform_scales","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("num_node_aligned_scales","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("num_node_arbitrary_scales","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("num_ground_frames","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("num_object_states","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("num_decal_states","int32",48,4,SX_COUNT_PROP),
    SX_FIELD("num_triggers","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("num_details","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("num_meshes","int32",60,4,SX_COUNT_PROP),
    SX_FIELD("num_names","int32",64,4,SX_COUNT_PROP),
    SX_FIELD("smallest_visible_size","int32",68,4,SX_NONE),
    SX_FIELD("smallest_visible_detail","int32",72,4,SX_NONE),
};
const sx_layout sxbrs_dts_counts = {UINT32_C(0x603e000b),"dts_counts",sxbrs_dts_counts_fields,SX_COUNT(sxbrs_dts_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_bounds_fields[] = {
    SX_FIELD("radius","float32",0,4,SX_NONE),
    SX_FIELD("tube_radius","float32",4,4,SX_NONE),
    SX_FIELD("center_x","float32",8,4,SX_NONE),
    SX_FIELD("center_y","float32",12,4,SX_NONE),
    SX_FIELD("center_z","float32",16,4,SX_NONE),
    SX_FIELD("min_x","float32",20,4,SX_NONE),
    SX_FIELD("min_y","float32",24,4,SX_NONE),
    SX_FIELD("min_z","float32",28,4,SX_NONE),
    SX_FIELD("max_x","float32",32,4,SX_NONE),
    SX_FIELD("max_y","float32",36,4,SX_NONE),
    SX_FIELD("max_z","float32",40,4,SX_NONE),
};
const sx_layout sxbrs_dts_bounds = {UINT32_C(0x603e000c),"dts_bounds",sxbrs_dts_bounds_fields,SX_COUNT(sxbrs_dts_bounds_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_node_fields[] = {
    SX_FIELD("name_index","int32",0,4,SX_NONE),
    SX_FIELD("parent_index","int32",4,4,SX_NONE),
    SX_FIELD("first_object_index","int32",8,4,SX_NONE),
    SX_FIELD("first_child_index","int32",12,4,SX_NONE),
    SX_FIELD("next_sibling_index","int32",16,4,SX_NONE),
};
const sx_layout sxbrs_dts_node = {UINT32_C(0x603e000d),"dts_node",sxbrs_dts_node_fields,SX_COUNT(sxbrs_dts_node_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_subshape_first_fields[] = {
    SX_FIELD("first_node","int32",0,4,SX_NONE),
    SX_FIELD("first_object","int32",4,4,SX_NONE),
    SX_FIELD("first_decal","int32",8,4,SX_NONE),
};
const sx_layout sxbrs_dts_subshape_first = {UINT32_C(0x603e000e),"dts_subshape_first",sxbrs_dts_subshape_first_fields,SX_COUNT(sxbrs_dts_subshape_first_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_subshape_count_fields[] = {
    SX_FIELD("num_nodes","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("num_objects","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("num_decals","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxbrs_dts_subshape_count = {UINT32_C(0x603e000f),"dts_subshape_count",sxbrs_dts_subshape_count_fields,SX_COUNT(sxbrs_dts_subshape_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_rotation_fields[] = {
    SX_FIELD("x","int16",0,2,SX_NONE),
    SX_FIELD("y","int16",2,2,SX_NONE),
    SX_FIELD("z","int16",4,2,SX_NONE),
    SX_FIELD("w","int16",6,2,SX_NONE),
};
const sx_layout sxbrs_dts_rotation = {UINT32_C(0x603e0010),"dts_rotation",sxbrs_dts_rotation_fields,SX_COUNT(sxbrs_dts_rotation_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_translation_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxbrs_dts_translation = {UINT32_C(0x603e0011),"dts_translation",sxbrs_dts_translation_fields,SX_COUNT(sxbrs_dts_translation_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard32_fields[] = {
    SX_FIELD("guard","uint32",0,4,SX_NONE),
};
const sx_layout sxbrs_dts_guard32 = {UINT32_C(0x603e0012),"dts_guard32",sxbrs_dts_guard32_fields,SX_COUNT(sxbrs_dts_guard32_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard16_fields[] = {
    SX_FIELD("guard","uint16",0,2,SX_NONE),
};
const sx_layout sxbrs_dts_guard16 = {UINT32_C(0x603e0013),"dts_guard16",sxbrs_dts_guard16_fields,SX_COUNT(sxbrs_dts_guard16_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard8_fields[] = {
    SX_FIELD("guard","uint8",0,1,SX_NONE),
};
const sx_layout sxbrs_dts_guard8 = {UINT32_C(0x603e0014),"dts_guard8",sxbrs_dts_guard8_fields,SX_COUNT(sxbrs_dts_guard8_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_name_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
const sx_layout sxbrs_dts_name_byte = {UINT32_C(0x603e0015),"dts_name_byte",sxbrs_dts_name_byte_fields,SX_COUNT(sxbrs_dts_name_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_footer_fields[] = {
    SX_FIELD("sequence_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("material_list_version","uint8",4,1,SX_NONE),
    SX_FIELD("material_count","uint32",5,4,SX_COUNT_PROP),
};
const sx_layout sxbrs_dts_footer = {UINT32_C(0x603e0016),"dts_footer",sxbrs_dts_footer_fields,SX_COUNT(sxbrs_dts_footer_fields),SX_LE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_dts_guard(sx_context*c,int64_t*a,int64_t ae,int64_t*b,int64_t be,int64_t*d,int64_t de,unsigned guard)
{
 if(N(*a,4)!=guard||N(*b,2)!=guard||N(*d,1)!=guard)return false;
 return sxbrs_take(c,&sxbrs_dts_guard32,a,ae,1)&&sxbrs_take(c,&sxbrs_dts_guard16,b,be,1)&&sxbrs_take(c,&sxbrs_dts_guard8,d,de,1);
}
static bool sxbrs_dts(sx_context*c)
{
 if(c->size<25||(N(0,4)&65535)!=24)return false;uint64_t size=N(4,4),s16=N(8,4),s8=N(12,4);
 if(s16<19||s16>s8||s8>size||size>(uint64_t)(c->size-25)/4)return false;
 int64_t at=16,end=16+(int64_t)s16*4,b=end,be=16+(int64_t)s8*4,d=be,de=16+(int64_t)size*4;
 uint64_t nodes=N(16,4),names=N(80,4);if(!nodes||nodes>256||!names||names>1024)return false;
 if(!sxbrs_add(c,&sxbrs_dts_header,0))return false;AL(dts_counts,1);
 unsigned guard=0;
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;AL(dts_bounds,1);
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;AL(dts_node,nodes);
 for(unsigned i=2;i<=5;i++)if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 AL(dts_subshape_first,1);if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 AL(dts_subshape_count,1);if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 if(!sxbrs_take(c,&sxbrs_dts_rotation,&b,be,nodes))return false;AL(dts_translation,nodes);
 for(unsigned i=8;i<=15;i++)if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 int64_t start=d;for(uint64_t i=0;i<names;i++){unsigned length=0;while(d<de&&N(d++,1)){if(++length>=4096)return false;}if(!length||d>de)return false;}
 int64_t cursor=start;if(!sxbrs_take(c,&sxbrs_dts_name_byte,&cursor,d,(uint64_t)(d-start)))return false;
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++)||at!=end)return false;
 return sxbrs_add(c,&sxbrs_dts_footer,de);
}
bool sx_torque_dts_build(sx_context*c)
{
 return sxbrs_dts(c);
}
#undef AL
#undef N
