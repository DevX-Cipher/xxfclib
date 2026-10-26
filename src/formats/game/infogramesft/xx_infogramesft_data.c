/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * infogramesft data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_ipak_inline_prefix_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("descriptor_bytes","uint8",1,1,SX_SIZE),
};
const sx_layout sxga_ipak_inline_prefix={UINT32_C(0x603B004F),"ipak_inline_prefix",sxga_ipak_inline_prefix_fields,SX_COUNT(sxga_ipak_inline_prefix_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_ipak(sxga_view*v)
{uint64_t end=v->c->size,table,last=0;if(!sxga_word(v,4,4,false,&table,end)||table%4||!sxga_table(v,&sxga_ipak_offset,0,table/4,end))return false;
 xx_archive_record_state*state=xx_format_create_archive_records_reading(v->c->f,NULL,v->c->pd);if(!state)return false;bool ok=true;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(v->c->f,state);if(!r)break;uint64_t off,n,extra,inl,packed,mark,length;if(r->header_offset<v->c->f->base_address){ok=false;break;}off=(uint64_t)(r->header_offset-v->c->f->base_address);
  /* The public native record includes a leading local PKZIP crumb. */
  if(!sxga_word(v,off,4,false,&n,end)){ok=false;break;}
  if(n==UINT32_C(0x04034b50)){if(!GA_ROW(ipak_local_crumb,off,end)){ok=false;break;}off+=16;}
  if(!GA_ROW(ipak_entry,off,end)||!sxga_word(v,off,4,false,&extra,end)||!sxga_word(v,off+4,4,false,&packed,end)||!sxga_word(v,off+14,2,false,&inl,end)||!sxga_span(v,off+16,inl+extra+packed,end)){ok=false;break;}
  if(inl>=3&&sxga_word(v,off+16,1,false,&mark,end)&&sxga_word(v,off+17,1,false,&length,end)&&mark==0x49&&length==inl){if(!GA_ROW(ipak_inline_prefix,off+16,end)||!sxga_named(v,off+18,inl-2,end,false)){ok=false;break;}}
  if(off+16+inl+extra+packed>last)last=off+16+inl+extra+packed;
 }while(xx_format_archive_record_move_to_next(v->c->f,state,v->c->pd));xx_format_free_archive_records_reading(v->c->f,state);
 uint64_t tag;if(ok&&sxga_span(v,last,16,end)&&sxga_word(v,last,4,false,&tag,end)&&tag==UINT32_C(0x02014b50))ok=GA_ROW(ipak_central_crumb,last,end);return ok;}
bool sx_infogramesft_build(sxga_view*v)
{
 return sxga_ipak(v);
}
#undef GA_ROW
