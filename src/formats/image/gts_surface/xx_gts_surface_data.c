/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gts_surface data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_edge_index_fields[]={
 SX_FIELD("edge_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_edge_index={0x6052001fU,"modeltext_edge_index",sxmt_edge_index_fields,SX_COUNT(sxmt_edge_index_fields),SX_LE};
/* The native GTS grammar is token-based, not line-based. Its enabled
 * comments are # and !; a CR alone terminates either comment. */
static bool sxmt_gts_token(sxmt_cursor*q,int64_t*a,int64_t*z){
 for(;;){while(q->p<q->n&&sxmt_space(q->b[q->p]))q->p++;if(q->p==q->n)return false;
  if(q->b[q->p]!='#'&&q->b[q->p]!='!')break;
  while(q->p<q->n&&q->b[q->p]!='\r'&&q->b[q->p]!='\n')q->p++;
 }
 *a=q->p;while(q->p<q->n&&!sxmt_space(q->b[q->p])&&q->b[q->p]!='#'&&q->b[q->p]!='!')q->p++;
 *z=q->p-*a;return *z>0&&!xx_pd_is_stopped(q->c->pd);
}
static bool sxmt_gts_value(sxmt_cursor*q,const sx_layout*l,uint64_t*out){
 int64_t a,z;if(!sxmt_gts_token(q,&a,&z)||!sxmt_emit(q,l,a,z))return false;
 if(out){if(q->b[a]=='+'){a++;z--;}if(!sxmt_uint_token(q,a,z,out))return false;}return true;
}
static bool sxmt_gts(sxmt_cursor*q){uint64_t nv,ne,nf;
 if(!sxmt_gts_value(q,&sxmt_vertex_count,&nv)||!sxmt_gts_value(q,&sxmt_edge_count,&ne)||!sxmt_gts_value(q,&sxmt_face_count,&nf)||nv>1000000||ne>1000000||nf>1000000)return false;
 int64_t save=q->p,a,z;
 if(!sxmt_gts_token(q,&a,&z))return false;
 if(sxmt_eq(q,a,z,"GtsSurface")){
  static const char*classes[]={"GtsSurface","GtsFace","GtsEdge","GtsVertex"};
  for(unsigned i=0;i<4;i++){if(i&&!sxmt_gts_token(q,&a,&z))return false;if(!sxmt_eq(q,a,z,classes[i])||!sxmt_emit(q,&sxmt_object_type,a,z))return false;}
 }else q->p=save;
 const sx_layout*xyz[]={&sxmt_x,&sxmt_y,&sxmt_z};for(uint64_t i=0;i<nv;i++)for(unsigned j=0;j<3;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,xyz[j],NULL))return false;}
 for(uint64_t i=0;i<ne;i++)for(unsigned j=0;j<2;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,&sxmt_vertex_index,NULL))return false;}
 for(uint64_t i=0;i<nf;i++)for(unsigned j=0;j<3;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,&sxmt_edge_index,NULL))return false;}return true;}
bool sx_gts_surface_build(sxmt_cursor*q)
{
 return sxmt_gts(q);
}
