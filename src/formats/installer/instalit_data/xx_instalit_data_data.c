/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Instalit data data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_instalit(sxir_view*v)
{Abstractformat*f=v->c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return false;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;bool ok=true;uint64_t previous=0,count=0;
 while(s->has_record){const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r||r->data_offset<f->base_address||r->compressed_size<4){ok=false;break;}uint64_t at=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;uint64_t mode,bits;if(at<previous||++count>65536||!sxir_span(v,at,z,v->c->size)||!IR_U(at,1,mode,v->c->size)||mode>1||!IR_U(at+1,1,bits,v->c->size)||bits<4||bits>6||!IR_ROW(instalit_dcl_header,at,at+z)){ok=false;break;}previous=at+z;if(!xx_format_archive_record_move_to_next(f,s,v->c->pd))break;}
 xx_format_free_archive_records_reading(f,s);return ok&&count&&!xx_pd_is_stopped(v->c->pd);}
bool sx_instalit_data_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_instalit(v);
}
#undef IR_ROW
#undef IR_U
