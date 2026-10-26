/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MMD_PMX data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_pmx20_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","float32",4,4,SX_ID),
    SX_FIELD("globals_size","uint8",8,1,SX_SIZE),
    SX_FIELD("encoding","uint8",9,1,SX_ID),
    SX_FIELD("additional_uv_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("vertex_index_size","uint8",11,1,SX_SIZE),
    SX_FIELD("texture_index_size","uint8",12,1,SX_SIZE),
    SX_FIELD("material_index_size","uint8",13,1,SX_SIZE),
    SX_FIELD("bone_index_size","uint8",14,1,SX_SIZE),
    SX_FIELD("morph_index_size","uint8",15,1,SX_SIZE),
    SX_FIELD("rigid_body_index_size","uint8",16,1,SX_SIZE),
};
const sx_layout sxmo_pmx20_header = {UINT32_C(0x60210079),"pmx20_header",sxmo_pmx20_header_fields,SX_COUNT(sxmo_pmx20_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_text_length_fields[] = {
    SX_FIELD("byte_length","int32",0,4,SX_SIZE),
};
const sx_layout sxmo_pmx_text_length = {UINT32_C(0x6021007a),"pmx_text_length",sxmo_pmx_text_length_fields,SX_COUNT(sxmo_pmx_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_count_fields[] = {
    SX_FIELD("vertex_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_pmx_vertex_count = {UINT32_C(0x6021007b),"pmx_vertex_count",sxmo_pmx_vertex_count_fields,SX_COUNT(sxmo_pmx_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_face_index_count_fields[] = {
    SX_FIELD("face_index_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_pmx_face_index_count = {UINT32_C(0x6021007c),"pmx_face_index_count",sxmo_pmx_face_index_count_fields,SX_COUNT(sxmo_pmx_face_index_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_texture_count_fields[] = {
    SX_FIELD("texture_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_pmx_texture_count = {UINT32_C(0x6021007d),"pmx_texture_count",sxmo_pmx_texture_count_fields,SX_COUNT(sxmo_pmx_texture_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("normal","float32[3]",12,12,SX_NONE),
    SX_FIELD("u","float32",24,4,SX_NONE),
    SX_FIELD("v","float32",28,4,SX_NONE),
};
const sx_layout sxmo_pmx_vertex = {UINT32_C(0x6021007e),"pmx_vertex",sxmo_pmx_vertex_fields,SX_COUNT(sxmo_pmx_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_additional_uv_fields[] = {
    SX_FIELD("coordinates","float32[4]",0,16,SX_NONE),
};
const sx_layout sxmo_pmx_additional_uv = {UINT32_C(0x6021007f),"pmx_additional_uv",sxmo_pmx_additional_uv_fields,SX_COUNT(sxmo_pmx_additional_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_skinning_fields[] = {
    SX_FIELD("deform_type","uint8",0,1,SX_ID),
};
const sx_layout sxmo_pmx_skinning = {UINT32_C(0x60210080),"pmx_skinning",sxmo_pmx_skinning_fields,SX_COUNT(sxmo_pmx_skinning_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index1_fields[] = {
    SX_FIELD("bone_index","int8",0,1,SX_ID),
};
const sx_layout sxmo_pmx_bone_index1 = {UINT32_C(0x60210081),"pmx_bone_index1",sxmo_pmx_bone_index1_fields,SX_COUNT(sxmo_pmx_bone_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index1_fields[] = {
    SX_FIELD("vertex_index","uint8",0,1,SX_ID),
};
const sx_layout sxmo_pmx_vertex_index1 = {UINT32_C(0x60210082),"pmx_vertex_index1",sxmo_pmx_vertex_index1_fields,SX_COUNT(sxmo_pmx_vertex_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index2_fields[] = {
    SX_FIELD("bone_index","int16",0,2,SX_ID),
};
const sx_layout sxmo_pmx_bone_index2 = {UINT32_C(0x60210083),"pmx_bone_index2",sxmo_pmx_bone_index2_fields,SX_COUNT(sxmo_pmx_bone_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index2_fields[] = {
    SX_FIELD("vertex_index","uint16",0,2,SX_ID),
};
const sx_layout sxmo_pmx_vertex_index2 = {UINT32_C(0x60210084),"pmx_vertex_index2",sxmo_pmx_vertex_index2_fields,SX_COUNT(sxmo_pmx_vertex_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index4_fields[] = {
    SX_FIELD("bone_index","int32",0,4,SX_ID),
};
const sx_layout sxmo_pmx_bone_index4 = {UINT32_C(0x60210085),"pmx_bone_index4",sxmo_pmx_bone_index4_fields,SX_COUNT(sxmo_pmx_bone_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index4_fields[] = {
    SX_FIELD("vertex_index","uint32",0,4,SX_ID),
};
const sx_layout sxmo_pmx_vertex_index4 = {UINT32_C(0x60210086),"pmx_vertex_index4",sxmo_pmx_vertex_index4_fields,SX_COUNT(sxmo_pmx_vertex_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_weight_fields[] = {
    SX_FIELD("weight","float32",0,4,SX_NONE),
};
const sx_layout sxmo_pmx_weight = {UINT32_C(0x60210087),"pmx_weight",sxmo_pmx_weight_fields,SX_COUNT(sxmo_pmx_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_edge_scale_fields[] = {
    SX_FIELD("edge_scale","float32",0,4,SX_NONE),
};
const sx_layout sxmo_pmx_edge_scale = {UINT32_C(0x60210088),"pmx_edge_scale",sxmo_pmx_edge_scale_fields,SX_COUNT(sxmo_pmx_edge_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_sdef_fields[] = {
    SX_FIELD("c","float32[3]",0,12,SX_NONE),
    SX_FIELD("r0","float32[3]",12,12,SX_NONE),
    SX_FIELD("r1","float32[3]",24,12,SX_NONE),
};
const sx_layout sxmo_pmx_sdef = {UINT32_C(0x60210089),"pmx_sdef",sxmo_pmx_sdef_fields,SX_COUNT(sxmo_pmx_sdef_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_material_count_fields[] = {
    SX_FIELD("material_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_pmx_material_count = {UINT32_C(0x6021008a),"pmx_material_count",sxmo_pmx_material_count_fields,SX_COUNT(sxmo_pmx_material_count_fields),SX_LE};
static bool sxmo_pmx(sx_context*c){uint8_t h[17];if(!sxmo_read(c,0,h,17)||xx_rt_memcmp(h,"PMX ",4)||sxmo32(h+4,false)!=0x40000000||h[8]!=8||!sxmo_add(c,&sxmo_pmx20_header,0))return false;unsigned additional=h[10],bone=h[14],vertex=h[11];if(additional>4||(bone!=1&&bone!=2&&bone!=4)||(vertex!=1&&vertex!=2&&vertex!=4))return true;uint64_t p=17,end=(uint64_t)c->size;
 for(unsigned i=0;i<4;i++)if(!sxmo_text(c,&sxmo_pmx_text_length,&p,end))return !c->failed;if(end-p<4||!sxmo_read(c,p,h,4))return true;uint32_t count=sxmo32(h,false);if(count>4096)return true;if(!sxmo_take(c,&sxmo_pmx_vertex_count,&p,end))return false;
 for(uint32_t i=0;i<count;i++){if(end-p<33+(uint64_t)additional*16)return true;if(!sxmo_take(c,&sxmo_pmx_vertex,&p,end)||!sxmo_table(c,&sxmo_pmx_additional_uv,p,additional))return false;p+=additional*16;if(!sxmo_read(c,p,h,1))return false;unsigned deform=h[0];if(deform>3)return true;if(!sxmo_take(c,&sxmo_pmx_skinning,&p,end))return false;unsigned bones=deform==0?1:deform==2?4:2,weights=deform==0?0:deform==2?4:1;uint64_t z=bones*bone+weights*4+(deform==3?36:0)+4;if(z>end-p)return true;const sx_layout*l=bone==1?&sxmo_pmx_bone_index1:bone==2?&sxmo_pmx_bone_index2:&sxmo_pmx_bone_index4;if(!sxmo_table(c,l,p,bones))return false;p+=bones*bone;if(!sxmo_table(c,&sxmo_pmx_weight,p,weights))return false;p+=weights*4;if(deform==3&&!sxmo_take(c,&sxmo_pmx_sdef,&p,end))return false;if(!sxmo_take(c,&sxmo_pmx_edge_scale,&p,end))return false;}
 if(end-p<4||!sxmo_read(c,p,h,4))return true;count=sxmo32(h,false);if(count>1000000||(uint64_t)count*vertex>end-p-4)return true;if(!sxmo_take(c,&sxmo_pmx_face_index_count,&p,end)||!sxmo_table(c,vertex==1?&sxmo_pmx_vertex_index1:vertex==2?&sxmo_pmx_vertex_index2:&sxmo_pmx_vertex_index4,p,count))return false;p+=(uint64_t)count*vertex;
 if(end-p<4||!sxmo_read(c,p,h,4))return true;count=sxmo32(h,false);if(count>65536)return true;if(!sxmo_take(c,&sxmo_pmx_texture_count,&p,end))return false;for(uint32_t i=0;i<count;i++)if(!sxmo_text(c,&sxmo_pmx_text_length,&p,end))return !c->failed;return end-p<4||sxmo_add(c,&sxmo_pmx_material_count,p);}
bool sx_mmd_pmx_build(sx_context*c)
{
bool ok=false;
ok=sxmo_pmx(c);
return ok&&c->count>0&&sxmo_finish(c);
}
