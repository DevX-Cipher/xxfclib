/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * catsystem_kif data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_kif_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxgco_kif_header={UINT32_C(0x60400038),"kif_header",sxgco_kif_header_fields,SX_COUNT(sxgco_kif_header_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_kif(sxgco_view*v)
{uint64_t e=v->c->size,n;if(!GC_ROW(kif_header,0,e)||!sxgco_word(v,4,4,false,&n,e)||n>UINT32_C(0xfffff))return false;uint8_t name[11];if(sxgco_read(v,8,name,11,e)&&!xx_rt_memcmp(name,"__key__.dat",11))return true;
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;const xx_archive_record*r=xx_format_get_current_archive_record(f,s);int64_t size=r?r->header_size:0;xx_format_free_archive_records_reading(f,s);if(size!=40&&size!=72)return false;return sxgco_table(v,size==40?&sxgco_kif_entry32:&sxgco_kif_entry64,8,n,e);}
bool sx_catsystem_kif_build(sxgco_view*v)
{
 return sxgco_kif(v);
}
#undef GC_ROW
