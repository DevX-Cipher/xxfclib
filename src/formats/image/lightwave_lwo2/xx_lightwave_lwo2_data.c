/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LIGHTWAVE_LWO2 data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_lwo2_form_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sxmo_lwo2_form = {UINT32_C(0x60210051),"lwo2_form",sxmo_lwo2_form_fields,SX_COUNT(sxmo_lwo2_form_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxmo_lwo2_chunk = {UINT32_C(0x60210052),"lwo2_chunk",sxmo_lwo2_chunk_fields,SX_COUNT(sxmo_lwo2_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_layer_fields[] = {
    SX_FIELD("number","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("pivot","float32[3]",4,12,SX_NONE),
};
const sx_layout sxmo_lwo2_layer = {UINT32_C(0x60210053),"lwo2_layer",sxmo_lwo2_layer_fields,SX_COUNT(sxmo_lwo2_layer_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_point_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_lwo2_point = {UINT32_C(0x60210054),"lwo2_point",sxmo_lwo2_point_fields,SX_COUNT(sxmo_lwo2_point_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_polygon_type_fields[] = {
    SX_FIELD("polygon_type","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_lwo2_polygon_type = {UINT32_C(0x60210055),"lwo2_polygon_type",sxmo_lwo2_polygon_type_fields,SX_COUNT(sxmo_lwo2_polygon_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_tag_type_fields[] = {
    SX_FIELD("tag_type","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_lwo2_tag_type = {UINT32_C(0x60210056),"lwo2_tag_type",sxmo_lwo2_tag_type_fields,SX_COUNT(sxmo_lwo2_tag_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_polygon_fields[] = {
    SX_FIELD("count_and_flags","uint16",0,2,SX_FLAGS),
};
const sx_layout sxmo_lwo2_polygon = {UINT32_C(0x60210057),"lwo2_polygon",sxmo_lwo2_polygon_fields,SX_COUNT(sxmo_lwo2_polygon_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_index16_fields[] = {
    SX_FIELD("index","uint16",0,2,SX_ID),
};
const sx_layout sxmo_lwo2_index16 = {UINT32_C(0x60210058),"lwo2_index16",sxmo_lwo2_index16_fields,SX_COUNT(sxmo_lwo2_index16_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_index24_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("index","uint24",1,3,SX_ID),
};
const sx_layout sxmo_lwo2_index24 = {UINT32_C(0x60210059),"lwo2_index24",sxmo_lwo2_index24_fields,SX_COUNT(sxmo_lwo2_index24_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_tag_index_fields[] = {
    SX_FIELD("tag_index","uint16",0,2,SX_ID),
};
const sx_layout sxmo_lwo2_tag_index = {UINT32_C(0x6021005a),"lwo2_tag_index",sxmo_lwo2_tag_index_fields,SX_COUNT(sxmo_lwo2_tag_index_fields),SX_BE};
static bool sxmo_lwo_index(sx_context*c,uint64_t*p,uint64_t end){uint8_t b;if(*p>=end||!sxmo_read(c,*p,&b,1))return false;return sxmo_take(c,b==255?&sxmo_lwo2_index24:&sxmo_lwo2_index16,p,end);}
static bool sxmo_lwo(sx_context*c){uint8_t h[12];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"LWO2",4)||!sxmo_add(c,&sxmo_lwo2_form,0))return false;uint64_t p=12,end=8+(uint64_t)sxmo32(h+4,true);if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned i=0;p<end&&i<4096;i++){if(end-p<8||!sxmo_read(c,p,h,8))break;uint64_t z=sxmo32(h+4,true);if(z>end-p-8)break;uint64_t q=p+8,stop=q+z;if(!sxmo_add(c,&sxmo_lwo2_chunk,p))return false;
 if(!xx_rt_memcmp(h,"LAYR",4)&&z>=16){if(!sxmo_add(c,&sxmo_lwo2_layer,q))return false;}
 else if(!xx_rt_memcmp(h,"PNTS",4)&&z%12==0&&z/12<=1000000){if(!sxmo_table(c,&sxmo_lwo2_point,q,z/12))return false;}
 else if(!xx_rt_memcmp(h,"POLS",4)&&z>=4){if(!sxmo_take(c,&sxmo_lwo2_polygon_type,&q,stop))return false;for(unsigned j=0;q<stop&&j<4096;j++){if(stop-q<2||!sxmo_read(c,q,h,2))break;unsigned n=sxmo16(h,true)&1023;if(!sxmo_take(c,&sxmo_lwo2_polygon,&q,stop))return false;bool ok=true;for(unsigned k=0;k<n;k++)if(!sxmo_lwo_index(c,&q,stop)){ok=false;break;}if(!ok)break;}}
 else if(!xx_rt_memcmp(h,"PTAG",4)&&z>=4){if(!sxmo_take(c,&sxmo_lwo2_tag_type,&q,stop))return false;for(unsigned j=0;q<stop&&j<4096;j++){if(!sxmo_lwo_index(c,&q,stop)||stop-q<2)break;if(!sxmo_take(c,&sxmo_lwo2_tag_index,&q,stop))return false;}}p=stop+(z&1);}return !c->failed;}
bool sx_lightwave_lwo2_build(sx_context*c)
{
bool ok=false;
ok=sxmo_lwo(c);
return ok&&c->count>0&&sxmo_finish(c);
}
