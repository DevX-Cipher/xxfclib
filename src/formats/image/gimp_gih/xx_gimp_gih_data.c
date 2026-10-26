/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gimp_gih data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_placement_fields[]={
 SX_FIELD("placement","char",0,0,SX_STRING),
};
const sx_layout sxti_placement={0x60410009U,"textimage_placement",sxti_placement_fields,SX_COUNT(sxti_placement_fields),SX_LE};
static const xx_data_struct_field_desc sxti_selection_fields[]={
 SX_FIELD("selection","char",0,0,SX_STRING),
};
const sx_layout sxti_selection={0x6041000aU,"textimage_selection",sxti_selection_fields,SX_COUNT(sxti_selection_fields),SX_LE};
static const xx_data_struct_field_desc sxti_brush_name_fields[]={
 SX_FIELD("brush_name","utf8",0,0,SX_STRING),
};
const sx_layout sxti_brush_name={0x60410013U,"textimage_brush_name",sxti_brush_name_fields,SX_COUNT(sxti_brush_name_fields),SX_LE};
static const xx_data_struct_field_desc sxti_brush_count_fields[]={
 SX_FIELD("brush_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxti_brush_count={0x6041001cU,"textimage_brush_count",sxti_brush_count_fields,SX_COUNT(sxti_brush_count_fields),SX_LE};
static const xx_data_struct_field_desc sxti_ncells_fields[]={
 SX_FIELD("ncells","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxti_ncells={0x6041001dU,"textimage_ncells",sxti_ncells_fields,SX_COUNT(sxti_ncells_fields),SX_LE};
static const xx_data_struct_field_desc sxti_cellwidth_fields[]={
 SX_FIELD("cellwidth","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_cellwidth={0x6041001eU,"textimage_cellwidth",sxti_cellwidth_fields,SX_COUNT(sxti_cellwidth_fields),SX_LE};
static const xx_data_struct_field_desc sxti_cellheight_fields[]={
 SX_FIELD("cellheight","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_cellheight={0x6041001fU,"textimage_cellheight",sxti_cellheight_fields,SX_COUNT(sxti_cellheight_fields),SX_LE};
static const xx_data_struct_field_desc sxti_step_fields[]={
 SX_FIELD("step","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_step={0x60410020U,"textimage_step",sxti_step_fields,SX_COUNT(sxti_step_fields),SX_LE};
static const xx_data_struct_field_desc sxti_dim_fields[]={
 SX_FIELD("dim","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_dim={0x60410021U,"textimage_dim",sxti_dim_fields,SX_COUNT(sxti_dim_fields),SX_LE};
static const xx_data_struct_field_desc sxti_cols_fields[]={
 SX_FIELD("cols","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_cols={0x60410022U,"textimage_cols",sxti_cols_fields,SX_COUNT(sxti_cols_fields),SX_LE};
static const xx_data_struct_field_desc sxti_rows_fields[]={
 SX_FIELD("rows","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_rows={0x60410023U,"textimage_rows",sxti_rows_fields,SX_COUNT(sxti_rows_fields),SX_LE};
static const xx_data_struct_field_desc sxti_rank0_fields[]={
 SX_FIELD("rank0","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_rank0={0x60410024U,"textimage_rank0",sxti_rank0_fields,SX_COUNT(sxti_rank0_fields),SX_LE};
static const xx_data_struct_field_desc sxti_gih_brush_header_fields[]={
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("width","uint32",8,4,SX_NONE),
 SX_FIELD("height","uint32",12,4,SX_NONE),
 SX_FIELD("bytes_per_pixel","uint32",16,4,SX_NONE),
 SX_FIELD("magic","char[4]",20,4,SX_SIGNATURE),
 SX_FIELD("spacing","uint32",24,4,SX_NONE),
};
const sx_layout sxti_gih_brush_header={0x6041005fU,"textimage_gih_brush_header",sxti_gih_brush_header_fields,SX_COUNT(sxti_gih_brush_header_fields),SX_BE};
#define TI_VALUE(n,e,v) do{if(!sxti_value(q,&sxti_##n,(e),(v)))return false;}while(0)
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_gih(sxti_cursor*q)
{
 int64_t a,end;if(!sxti_line(q,&a,&end,false))return false;TI_EMIT(name,a,end-a);if(!sxti_line(q,&a,&end,false))return false;int64_t next=q->p;q->p=a;uint64_t count;TI_VALUE(brush_count,end,&count);if(!count||count>4096)return false;
 while(q->p<end){int64_t k,z;if(!sxti_token(q,end,&k,&z,false))break;int64_t colon=0;while(colon<z&&q->b[k+colon]!=':')colon++;if(colon==z)return false;const sx_layout*l=NULL;
#define TI_KEY(n) if(sxti_eq(q,k,colon,#n))l=&sxti_##n
 TI_KEY(ncells);else TI_KEY(cellwidth);else TI_KEY(cellheight);else TI_KEY(step);else TI_KEY(dim);else TI_KEY(cols);else TI_KEY(rows);else TI_KEY(rank0);else TI_KEY(placement);else if(sxti_eq(q,k,colon,"sel0"))l=&sxti_selection;
#undef TI_KEY
 if(!l||!sxti_emit(q,l,k+colon+1,z-colon-1))return false;
 }q->p=next;
 for(uint64_t i=0;i<count;i++){if(q->n-q->p<28)return false;uint8_t*b=q->b+q->p;uint64_t hs=xx_data_get_u32(b,28,0,true),w=xx_data_get_u32(b,28,8,true),h=xx_data_get_u32(b,28,12,true),channels=xx_data_get_u32(b,28,16,true);if(hs<=28||hs>4124||hs>(uint64_t)(q->n-q->p)||!w||!h||w>32768||h>32768||(channels!=1&&channels!=4)||w*h*channels>(uint64_t)(q->n-q->p)-hs)return false;TI_EMIT(gih_brush_header,q->p,28);if(hs>29)TI_EMIT(brush_name,q->p+28,(int64_t)hs-29);q->p+=(int64_t)(hs+w*h*channels);if(q->c->count>=32000)return true;}
 return true;
}
bool sx_gimp_gih_build(sxti_cursor*q)
{
 return sxti_gih(q);
}
#undef TI_VALUE
#undef TI_EMIT
