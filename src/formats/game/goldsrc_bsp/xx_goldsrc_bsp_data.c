/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * goldsrc_bsp data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_bsp_header_fields[]={
 SX_FIELD("version","int32",0,4,SX_ID),
};
const sx_layout sxga_bsp_header={UINT32_C(0x603B0050),"bsp_header",sxga_bsp_header_fields,SX_COUNT(sxga_bsp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_vertex_fields[]={
 SX_FIELD("x","float",0,4,SX_NONE),
 SX_FIELD("y","float",4,4,SX_NONE),
 SX_FIELD("z","float",8,4,SX_NONE),
};
const sx_layout sxga_bsp_vertex={UINT32_C(0x603B0053),"bsp_vertex",sxga_bsp_vertex_fields,SX_COUNT(sxga_bsp_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_texinfo_fields[]={
 SX_FIELD("s_x","float",0,4,SX_NONE),
 SX_FIELD("s_y","float",4,4,SX_NONE),
 SX_FIELD("s_z","float",8,4,SX_NONE),
 SX_FIELD("s_shift","float",12,4,SX_NONE),
 SX_FIELD("t_x","float",16,4,SX_NONE),
 SX_FIELD("t_y","float",20,4,SX_NONE),
 SX_FIELD("t_z","float",24,4,SX_NONE),
 SX_FIELD("t_shift","float",28,4,SX_NONE),
 SX_FIELD("miptex","int32",32,4,SX_ID),
 SX_FIELD("flags","int32",36,4,SX_FLAGS),
};
const sx_layout sxga_bsp_texinfo={UINT32_C(0x603B0055),"bsp_texinfo",sxga_bsp_texinfo_fields,SX_COUNT(sxga_bsp_texinfo_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_marksurface_fields[]={
 SX_FIELD("face","uint16",0,2,SX_ID),
};
const sx_layout sxga_bsp_marksurface={UINT32_C(0x603B0059),"bsp_marksurface",sxga_bsp_marksurface_fields,SX_COUNT(sxga_bsp_marksurface_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_edge_fields[]={
 SX_FIELD("vertex0","uint16",0,2,SX_ID),
 SX_FIELD("vertex1","uint16",2,2,SX_ID),
};
const sx_layout sxga_bsp_edge={UINT32_C(0x603B005A),"bsp_edge",sxga_bsp_edge_fields,SX_COUNT(sxga_bsp_edge_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_model_fields[]={
 SX_FIELD("min_x","float",0,4,SX_NONE),
 SX_FIELD("min_y","float",4,4,SX_NONE),
 SX_FIELD("min_z","float",8,4,SX_NONE),
 SX_FIELD("max_x","float",12,4,SX_NONE),
 SX_FIELD("max_y","float",16,4,SX_NONE),
 SX_FIELD("max_z","float",20,4,SX_NONE),
 SX_FIELD("origin_x","float",24,4,SX_NONE),
 SX_FIELD("origin_y","float",28,4,SX_NONE),
 SX_FIELD("origin_z","float",32,4,SX_NONE),
 SX_FIELD("headnode0","int32",36,4,SX_ID),
 SX_FIELD("headnode1","int32",40,4,SX_ID),
 SX_FIELD("headnode2","int32",44,4,SX_ID),
 SX_FIELD("headnode3","int32",48,4,SX_ID),
 SX_FIELD("visibility_leaves","int32",52,4,SX_COUNT_PROP),
 SX_FIELD("first_face","int32",56,4,SX_ID),
 SX_FIELD("faces","int32",60,4,SX_COUNT_PROP),
};
const sx_layout sxga_bsp_model={UINT32_C(0x603B005C),"bsp_model",sxga_bsp_model_fields,SX_COUNT(sxga_bsp_model_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_textures_fields[]={
 SX_FIELD("textures","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxga_bsp_textures={UINT32_C(0x603B005D),"bsp_textures",sxga_bsp_textures_fields,SX_COUNT(sxga_bsp_textures_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_palette_fields[]={
 SX_FIELD("colors","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxga_bsp_palette={UINT32_C(0x603B0060),"bsp_palette",sxga_bsp_palette_fields,SX_COUNT(sxga_bsp_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_color_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
const sx_layout sxga_bsp_color={UINT32_C(0x603B0061),"bsp_color",sxga_bsp_color_fields,SX_COUNT(sxga_bsp_color_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_bsp(sxga_view*v)
{uint64_t end=v->c->size,offsets[15],sizes[15];if(!GA_ROW(bsp_header,0,end)||!sxga_table(v,&sxga_bsp_lump,4,15,end))return false;for(unsigned i=0;i<15;i++)if(!sxga_word(v,4+i*8,4,false,&offsets[i],end)||!sxga_word(v,8+i*8,4,false,&sizes[i],end)||!sxga_span(v,offsets[i],sizes[i],end))return false;
 unsigned plane=sizes[1]%20==0?1:0;const sx_layout*layouts[15]={NULL,NULL,NULL,&sxga_bsp_vertex,NULL,&sxga_bsp_node,&sxga_bsp_texinfo,&sxga_bsp_face,NULL,&sxga_bsp_clipnode,&sxga_bsp_leaf,&sxga_bsp_marksurface,&sxga_bsp_edge,&sxga_bsp_surfedge,&sxga_bsp_model};layouts[plane]=&sxga_bsp_plane;
 for(unsigned i=0;i<15;i++)if(layouts[i]&&sizes[i]){const sx_layout*l=layouts[i];const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=f->rel_offset+f->size;if(sizes[i]%z||!sxga_table(v,l,offsets[i],sizes[i]/z,end))return false;}
 if(sizes[2]){uint64_t at=offsets[2],limit=at+sizes[2],n;if(!GA_ROW(bsp_textures,at,limit)||!sxga_word(v,at,4,false,&n,limit)||!sxga_table(v,&sxga_bsp_texture_offset,at+4,n,limit))return false;for(uint64_t i=0;i<n;i++){uint64_t rel,tex,w,h,mip,palette,colors;if(!sxga_word(v,at+4+i*4,4,false,&rel,limit))return false;if(rel<4+4*n||rel>sizes[2]||sizes[2]-rel<40)continue;tex=at+rel;if(!GA_ROW(bsp_miptex,tex,limit)||!sxga_word(v,tex+16,4,false,&w,limit)||!sxga_word(v,tex+20,4,false,&h,limit)||!sxga_word(v,tex+36,4,false,&mip,limit))return false;if(!w||!h||w>sizes[2]||h>sizes[2]||w*h>sizes[2]||mip>sizes[2]-rel)continue;bool valid=true;for(unsigned level=0;level<4;level++){uint64_t mo,sz=(w>>level)*(h>>level);if(!sxga_word(v,tex+24+4*level,4,false,&mo,limit))return false;if(mo<40||mo>limit-tex||sz>limit-tex-mo){valid=false;break;}}if(!valid)continue;palette=tex+mip+(w>>3)*(h>>3);if(!sxga_span(v,palette,2,limit))continue;if(!sxga_word(v,palette,2,false,&colors,limit))return false;if(colors>256||!sxga_span(v,palette+2,colors*3,limit))continue;if(!GA_ROW(bsp_palette,palette,limit)||!sxga_table(v,&sxga_bsp_color,palette+2,colors,limit))return false;}}
 return true;}
bool sx_goldsrc_bsp_build(sxga_view*v)
{
 return sxga_bsp(v);
}
#undef GA_ROW
