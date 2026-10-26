/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech_md2 data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_md2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("skin_width","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("skin_height","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("frame_size","int32",16,4,SX_SIZE),
 SX_FIELD("skin_count","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",24,4,SX_COUNT_PROP),
 SX_FIELD("texcoord_count","int32",28,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("gl_command_words","int32",36,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",40,4,SX_COUNT_PROP),
 SX_FIELD("skins_offset","int32",44,4,SX_OFFSET),
 SX_FIELD("texcoords_offset","int32",48,4,SX_OFFSET),
 SX_FIELD("triangles_offset","int32",52,4,SX_OFFSET),
 SX_FIELD("frames_offset","int32",56,4,SX_OFFSET),
 SX_FIELD("gl_commands_offset","int32",60,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",64,4,SX_OFFSET),
};
const sx_layout sxgm_md2_header = {UINT32_C(0x60270049),"md2_header",sxgm_md2_header_fields,SX_COUNT(sxgm_md2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_game_skin_name_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
};
const sx_layout sxgm_game_skin_name = {UINT32_C(0x6027004a),"game_skin_name",sxgm_game_skin_name_fields,SX_COUNT(sxgm_game_skin_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_texcoord_fields[] = {
 SX_FIELD("s","int16",0,2,SX_NONE),
 SX_FIELD("t","int16",2,2,SX_NONE),
};
const sx_layout sxgm_md2_texcoord = {UINT32_C(0x6027004b),"md2_texcoord",sxgm_md2_texcoord_fields,SX_COUNT(sxgm_md2_texcoord_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_triangle_fields[] = {
 SX_FIELD("vertex0","int16",0,2,SX_ID),
 SX_FIELD("vertex1","int16",2,2,SX_ID),
 SX_FIELD("vertex2","int16",4,2,SX_ID),
 SX_FIELD("texcoord0","int16",6,2,SX_ID),
 SX_FIELD("texcoord1","int16",8,2,SX_ID),
 SX_FIELD("texcoord2","int16",10,2,SX_ID),
};
const sx_layout sxgm_md2_triangle = {UINT32_C(0x6027004c),"md2_triangle",sxgm_md2_triangle_fields,SX_COUNT(sxgm_md2_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_frame_fields[] = {
 SX_FIELD("scale_0","float32",0,4,SX_NONE),
 SX_FIELD("scale_1","float32",4,4,SX_NONE),
 SX_FIELD("scale_2","float32",8,4,SX_NONE),
 SX_FIELD("translate_0","float32",12,4,SX_NONE),
 SX_FIELD("translate_1","float32",16,4,SX_NONE),
 SX_FIELD("translate_2","float32",20,4,SX_NONE),
 SX_FIELD("name","char[16]",24,16,SX_STRING),
};
const sx_layout sxgm_md2_frame = {UINT32_C(0x6027004d),"md2_frame",sxgm_md2_frame_fields,SX_COUNT(sxgm_md2_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_gl_command_fields[] = {
 SX_FIELD("vertex_count_signed","int32",0,4,SX_NONE),
};
const sx_layout sxgm_md2_gl_command = {UINT32_C(0x6027004f),"md2_gl_command",sxgm_md2_gl_command_fields,SX_COUNT(sxgm_md2_gl_command_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_gl_vertex_fields[] = {
 SX_FIELD("s","float32",0,4,SX_NONE),
 SX_FIELD("t","float32",4,4,SX_NONE),
 SX_FIELD("vertex_index","int32",8,4,SX_ID),
};
const sx_layout sxgm_md2_gl_vertex = {UINT32_C(0x60270050),"md2_gl_vertex",sxgm_md2_gl_vertex_fields,SX_COUNT(sxgm_md2_gl_vertex_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_md2(sx_context *c){uint8_t b[68];if(!sxgm_read(c,0,b,68)||!sxgm_add(c,&sxgm_md2_header,0))return false;uint64_t skins=sxgm32(b+20,false),verts=sxgm32(b+24,false),st=sxgm32(b+28,false),tris=sxgm32(b+32,false),words=sxgm32(b+36,false),frames=sxgm32(b+40,false),fs=sxgm32(b+16,false),p=sxgm32(b+56,false);if(!sxgm_table(c,&sxgm_game_skin_name,sxgm32(b+44,false),skins)||!sxgm_table(c,&sxgm_md2_texcoord,sxgm32(b+48,false),st)||!sxgm_table(c,&sxgm_md2_triangle,sxgm32(b+52,false),tris))return false;
 if(verts<=2048&&frames<=512&&fs==40+verts*4&&sxgm_span(c,p,frames*fs))for(uint64_t i=0;i<frames&&c->count<SXGM_LIMIT;i++){if(!sxgm_add(c,&sxgm_md2_frame,p+i*fs)||!sxgm_table(c,&sxgm_quake_vertex,p+i*fs+40,verts))return false;}
 p=sxgm32(b+60,false);if(words>0x1000000||!sxgm_span(c,p,words*4))return true;uint64_t end=p+words*4;for(unsigned i=0;i<SXGM_LIMIT&&end-p>=4&&c->count<SXGM_LIMIT;i++){uint64_t encoded;if(!sxgm_word(c,p,4,false,&encoded))break;int64_t signedn=(int32_t)(uint32_t)encoded;uint64_t n=(uint64_t)(signedn<0?-signedn:signedn);if(n>SXGM_LIMIT||n>(end-p-4)/12)break;if(!sxgm_add(c,&sxgm_md2_gl_command,p))return false;p+=4;if(!n)break;if(!sxgm_table(c,&sxgm_md2_gl_vertex,p,n))return false;p+=n*12;}return true;}
bool sx_idtech_md2_build(sx_context*c)
{
 return sxgm_md2(c);
}
