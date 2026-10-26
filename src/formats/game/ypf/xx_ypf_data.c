/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ypf data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_ypf_extra8_fields[]={
 SX_FIELD("extra","bytes",0,8,SX_NONE),
};
const sx_layout sxgco_ypf_extra8={UINT32_C(0x60400042),"ypf_extra8",sxgco_ypf_extra8_fields,SX_COUNT(sxgco_ypf_extra8_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_ypf(sxgco_view*v)
{uint64_t e=v->c->size,version;if(!GC_ROW(ypf_header,0,e)||!sxgco_word(v,4,4,false,&version,e))return false;
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;bool ok=true;unsigned count=0;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(++count>UINT32_C(0xfffff)||r->header_offset<f->base_address||r->header_size<24){ok=false;break;}uint64_t at=(uint64_t)(r->header_offset-f->base_address),n=(uint64_t)r->header_size-23;
 if(!GC_ROW(ypf_name,at,e)||!sxgco_table(v,&sxgco_encoded_byte,at+5,n,e)||!GC_ROW(ypf_fields,at+5+n,e)){ok=false;break;}at+=(uint64_t)r->header_size;if(version>=0x1d9)ok=GC_ROW(ypf_offset_high,at,e);else if(version==0xde)ok=GC_ROW(ypf_extra8,at,e);if(!ok)break;
 }while(xx_format_archive_record_move_to_next(f,s,v->c->pd));xx_format_free_archive_records_reading(f,s);return ok&&!xx_pd_is_stopped(v->c->pd);}
bool sx_ypf_build(sxgco_view*v)
{
 return sxgco_ypf(v);
}
#undef GC_ROW
