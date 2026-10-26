/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * maxis_far_archive data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
/* Reuse validated native record boundaries for ambiguous directory variants. */
static bool sxga_far(sxga_view*v)
{uint64_t end=v->c->size,at,n;if(!GA_ROW(far_header,0,end)||!sxga_word(v,12,4,false,&at,end)||!GA_ROW(count32,at,end)||!sxga_word(v,at,4,false,&n,end))return false;
 xx_archive_record_state*state=xx_format_create_archive_records_reading(v->c->f,NULL,v->c->pd);if(!state)return false;bool ok=true;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(v->c->f,state);if(!r)break;uint64_t z,wide=0,width=0;if(r->header_offset<v->c->f->base_address||r->header_size<14){ok=false;break;}at=(uint64_t)(r->header_offset-v->c->f->base_address);if(!sxga_span(v,at,(uint64_t)r->header_size,end)||!sxga_word(v,at+12,2,false,&z,end)){ok=false;break;}
  if(r->header_size>=16&&sxga_word(v,at+12,4,false,&wide,end)&&wide==(uint64_t)r->header_size-16){width=4;z=wide;}else if(z==(uint64_t)r->header_size-14)width=2;
  if(!width||!sxga_row(v,width==2?&sxga_far_entry16:&sxga_far_entry32,at,end)||!sxga_named(v,at+12+width,z,end,false)){ok=false;break;}
 }while(xx_format_archive_record_move_to_next(v->c->f,state,v->c->pd));xx_format_free_archive_records_reading(v->c->f,state);return ok;}
bool sx_maxis_far_archive_build(sxga_view*v)
{
 return sxga_far(v);
}
#undef GA_ROW
