/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CAL3D_SKELETON data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_cal3d_skeleton_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","int32",4,4,SX_ID),
    SX_FIELD("bone_count","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmo_cal3d_skeleton_header = {UINT32_C(0x60210095),"cal3d_skeleton_header",sxmo_cal3d_skeleton_header_fields,SX_COUNT(sxmo_cal3d_skeleton_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_bone_name_fields[] = {
    SX_FIELD("name_size","int32",0,4,SX_SIZE),
};
const sx_layout sxmo_cal3d_bone_name = {UINT32_C(0x60210096),"cal3d_bone_name",sxmo_cal3d_bone_name_fields,SX_COUNT(sxmo_cal3d_bone_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_bone_fields[] = {
    SX_FIELD("local_translation","float32[3]",0,12,SX_NONE),
    SX_FIELD("local_rotation_xyzw","float32[4]",12,16,SX_NONE),
    SX_FIELD("bone_space_translation","float32[3]",28,12,SX_NONE),
    SX_FIELD("bone_space_rotation_xyzw","float32[4]",40,16,SX_NONE),
    SX_FIELD("parent_index","int32",56,4,SX_ID),
    SX_FIELD("child_count","int32",60,4,SX_COUNT_PROP),
};
const sx_layout sxmo_cal3d_bone = {UINT32_C(0x60210097),"cal3d_bone",sxmo_cal3d_bone_fields,SX_COUNT(sxmo_cal3d_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_child_fields[] = {
    SX_FIELD("bone_index","int32",0,4,SX_ID),
};
const sx_layout sxmo_cal3d_child = {UINT32_C(0x60210098),"cal3d_child",sxmo_cal3d_child_fields,SX_COUNT(sxmo_cal3d_child_fields),SX_LE};
static bool sxmo_csf(sx_context*c){uint8_t h[64];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"CSF\0",4)||sxmo32(h+4,false)!=700||!sxmo_add(c,&sxmo_cal3d_skeleton_header,0))return false;unsigned count=sxmo32(h+8,false);if(count>4000)return true;uint64_t p=12,end=(uint64_t)c->size;for(unsigned i=0;i<count;i++){if(!sxmo_text(c,&sxmo_cal3d_bone_name,&p,end)||end-p<64||!sxmo_read(c,p,h,64))break;uint64_t n=sxmo32(h+60,false);if(n>4000||n*4>end-p-64)break;if(!sxmo_take(c,&sxmo_cal3d_bone,&p,end)||!sxmo_table(c,&sxmo_cal3d_child,p,n))return false;p+=n*4;}return !c->failed;}
bool sx_cal3d_skeleton_build(sx_context*c)
{
bool ok=false;
ok=sxmo_csf(c);
return ok&&c->count>0&&sxmo_finish(c);
}
