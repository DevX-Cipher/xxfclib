/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OGRE_SKELETON data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_ogre_skeleton_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("serializer_version","char[19]",2,19,SX_STRING),
};
const sx_layout sxmo_ogre_skeleton_header = {UINT32_C(0x6021008b),"ogre_skeleton_header",sxmo_ogre_skeleton_header_fields,SX_COUNT(sxmo_ogre_skeleton_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxmo_ogre_skeleton_chunk = {UINT32_C(0x6021008c),"ogre_skeleton_chunk",sxmo_ogre_skeleton_chunk_fields,SX_COUNT(sxmo_ogre_skeleton_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_bone_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("fixed_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxmo_ogre_skeleton_bone_chunk = {UINT32_C(0x6021008d),"ogre_skeleton_bone_chunk",sxmo_ogre_skeleton_bone_chunk_fields,SX_COUNT(sxmo_ogre_skeleton_bone_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_bone_fields[] = {
    SX_FIELD("handle","uint16",0,2,SX_ID),
    SX_FIELD("position","float32[3]",2,12,SX_NONE),
    SX_FIELD("orientation_xyzw","float32[4]",14,16,SX_NONE),
};
const sx_layout sxmo_ogre_skeleton_bone = {UINT32_C(0x6021008e),"ogre_skeleton_bone",sxmo_ogre_skeleton_bone_fields,SX_COUNT(sxmo_ogre_skeleton_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_scale_fields[] = {
    SX_FIELD("scale","float32[3]",0,12,SX_NONE),
};
const sx_layout sxmo_ogre_skeleton_scale = {UINT32_C(0x6021008f),"ogre_skeleton_scale",sxmo_ogre_skeleton_scale_fields,SX_COUNT(sxmo_ogre_skeleton_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_parent_fields[] = {
    SX_FIELD("child","uint16",0,2,SX_ID),
    SX_FIELD("parent","uint16",2,2,SX_ID),
};
const sx_layout sxmo_ogre_skeleton_parent = {UINT32_C(0x60210090),"ogre_skeleton_parent",sxmo_ogre_skeleton_parent_fields,SX_COUNT(sxmo_ogre_skeleton_parent_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_blend_fields[] = {
    SX_FIELD("blend_mode","uint16",0,2,SX_ID),
};
const sx_layout sxmo_ogre_skeleton_blend = {UINT32_C(0x60210091),"ogre_skeleton_blend",sxmo_ogre_skeleton_blend_fields,SX_COUNT(sxmo_ogre_skeleton_blend_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_duration_fields[] = {
    SX_FIELD("duration","float32",0,4,SX_NONE),
};
const sx_layout sxmo_ogre_skeleton_duration = {UINT32_C(0x60210092),"ogre_skeleton_duration",sxmo_ogre_skeleton_duration_fields,SX_COUNT(sxmo_ogre_skeleton_duration_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_track_fields[] = {
    SX_FIELD("bone_handle","uint16",0,2,SX_ID),
};
const sx_layout sxmo_ogre_skeleton_track = {UINT32_C(0x60210093),"ogre_skeleton_track",sxmo_ogre_skeleton_track_fields,SX_COUNT(sxmo_ogre_skeleton_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_keyframe_fields[] = {
    SX_FIELD("time","float32",0,4,SX_NONE),
    SX_FIELD("rotation_xyzw","float32[4]",4,16,SX_NONE),
    SX_FIELD("translation","float32[3]",20,12,SX_NONE),
};
const sx_layout sxmo_ogre_skeleton_keyframe = {UINT32_C(0x60210094),"ogre_skeleton_keyframe",sxmo_ogre_skeleton_keyframe_fields,SX_COUNT(sxmo_ogre_skeleton_keyframe_fields),SX_LE};
static bool sxmo_skeleton_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<3&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned tag=sxmo16(h,false);uint64_t n=sxmo32(h+2,false),q=p+6;if(n<6)break;
 if(tag==0x2000){if(n!=36&&n!=48)break;if(!sxmo_string(c,&q,end,10)||n-6>end-q)break;if(!sxmo_add(c,&sxmo_ogre_skeleton_bone_chunk,p)||!sxmo_take(c,&sxmo_ogre_skeleton_bone,&q,end))return false;if(n==48&&!sxmo_take(c,&sxmo_ogre_skeleton_scale,&q,end))return false;p=q;continue;}
 if(n>end-p)break;uint64_t stop=p+n;if(!sxmo_add(c,&sxmo_ogre_skeleton_chunk,p))return false;
 if(tag==0x1010&&n==8){if(!sxmo_add(c,&sxmo_ogre_skeleton_blend,q))return false;}else if(tag==0x3000&&n==10){if(!sxmo_add(c,&sxmo_ogre_skeleton_parent,q))return false;}
 else if(tag==0x4000&&sxmo_string(c,&q,stop,10)&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_skeleton_duration,&q,stop)||!sxmo_skeleton_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4100&&stop-q>=2){if(!sxmo_take(c,&sxmo_ogre_skeleton_track,&q,stop)||!sxmo_skeleton_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4110&&(n==38||n==50)){if(!sxmo_take(c,&sxmo_ogre_skeleton_keyframe,&q,stop)||(n==50&&!sxmo_take(c,&sxmo_ogre_skeleton_scale,&q,stop)))return false;}p=stop;}return !c->failed;}
static bool sxmo_skeleton(sx_context*c){uint8_t h[21];if(!sxmo_read(c,0,h,21)||sxmo16(h,false)!=0x1000||!sxmo_add(c,&sxmo_ogre_skeleton_header,0))return false;unsigned budget=0;return sxmo_skeleton_chunks(c,21,(uint64_t)c->size,0,&budget);}
bool sx_ogre_skeleton_build(sx_context*c)
{
bool ok=false;
ok=sxmo_skeleton(c);
return ok&&c->count>0&&sxmo_finish(c);
}
