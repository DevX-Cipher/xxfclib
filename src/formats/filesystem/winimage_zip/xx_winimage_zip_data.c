/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * winimage zip data structures, moved out of the carriermeta schema family. */
#include "../../xx_format_schema_carriermeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_cm_winimage_sfx_marker_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
};
const sx_layout sx_cm_winimage_sfx_marker = {0x60240003U,"winimage_sfx_marker",sx_cm_winimage_sfx_marker_fields,SX_COUNT(sx_cm_winimage_sfx_marker_fields),SX_LE};
static const xx_data_struct_field_desc sx_cm_winimage_zip_local_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_needed","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("compression_method","uint16",8,2,SX_ID),
    SX_FIELD("modified_time","uint16",10,2,SX_NONE),
    SX_FIELD("modified_date","uint16",12,2,SX_NONE),
    SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
    SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
    SX_FIELD("filename_length","uint16",26,2,SX_SIZE),
    SX_FIELD("extra_length","uint16",28,2,SX_SIZE),
};
const sx_layout sx_cm_winimage_zip_local_header = {0x60240004U,"winimage_zip_local_header",sx_cm_winimage_zip_local_header_fields,SX_COUNT(sx_cm_winimage_zip_local_header_fields),SX_LE};
static bool sx_cm_extras(sx_context*c,int64_t p,uint64_t n){uint8_t h[4];if(!sx_cm_span(c,p,n))return false;for(unsigned i=0;i<4096&&n>=4;i++){if(!sx_cm_read(c,p,h,4))return false;unsigned z=xx_data_get_u16(h,4,2,false);if(z>n-4)break;if(!sx_cm_add(c,&sx_cm_winimage_zip_extra_field,p,4))return false;p+=4+z;n-=4+z;}return true;}
static bool sx_cm_winimage(sx_context*c){uint8_t h[46],l[30];int64_t ecd=-1,dir,archive;uint16_t count;uint32_t bytes,relative;bool ok=false;
 xx_archive_record_state*s=sx_cm_records(c);if(!s)return false;
 /* The native reader permits an EOCD only when its comment ends at EOF. */
 int64_t low=c->size>65557?c->size-65557:0;
 for(int64_t p=c->size-22;p>=low;p--){if(!sx_cm_read(c,p,h,22))goto done;if(!xx_rt_memcmp(h,"PK\5\6",4)&&(uint64_t)xx_data_get_u16(h,22,20,false)==(uint64_t)(c->size-p-22)){ecd=p;break;}}
 if(ecd<0)goto done;count=xx_data_get_u16(h,22,10,false);bytes=xx_data_get_u32(h,22,12,false);relative=xx_data_get_u32(h,22,16,false);if(!count||count==65535||bytes>(uint64_t)ecd||relative==UINT32_MAX)goto done;dir=ecd-bytes;if(relative>(uint64_t)dir)goto done;archive=dir-relative;if(archive<4||archive>=dir||!sx_cm_read(c,archive-4,h,4)||xx_rt_memcmp(h,"WSfx",4))goto done;
 if(!sx_cm_add(c,&sx_cm_winimage_sfx_marker,archive-4,4)||!sx_cm_add(c,&sx_cm_winimage_zip_end_record,ecd,22))goto done;
 int64_t local=archive,at=dir;
 for(unsigned i=0;i<count;i++){
  const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r||!sx_cm_read(c,at,h,46)||!sx_cm_read(c,local,l,30)||xx_rt_memcmp(h,"PK\1\2",4)||xx_rt_memcmp(l,"PK\3\4",4))goto done;
  uint64_t name=xx_data_get_u16(h,46,28,false),extra=xx_data_get_u16(h,46,30,false),comment=xx_data_get_u16(h,46,32,false),packed=xx_data_get_u32(h,46,20,false),ln=xx_data_get_u16(l,30,26,false),le=xx_data_get_u16(l,30,28,false);
  if(at>ecd||46+name+extra+comment>(uint64_t)(ecd-at)||local>dir||30+ln+le>(uint64_t)(dir-local))goto done;int64_t data=local+30+(int64_t)ln+(int64_t)le;
  if(packed>(uint64_t)(dir-data)||r->data_offset<c->f->base_address||r->data_offset-c->f->base_address!=data||r->compressed_size<0||(uint64_t)r->compressed_size!=packed||xx_data_get_u32(h,46,42,false)!=(uint64_t)local)goto done;
  if(i<8192&&(!sx_cm_add(c,&sx_cm_winimage_zip_local_header,local,30)||!sx_cm_add(c,&sx_cm_winimage_zip_central_header,at,46)||!sx_cm_extras(c,local+30+(int64_t)ln,le)||!sx_cm_extras(c,at+46+(int64_t)name,extra)))goto done;
  local=data+(int64_t)packed;at+=46+(int64_t)name+(int64_t)extra+(int64_t)comment;
  bool more=(c->f->archive_record_move_to_next)(c->f,s,c->pd);if(more!=(i+1<count))goto done;
 }
 ok=local==dir&&at==ecd;
 done:(c->f->free_archive_records_reading)(c->f,s);return ok;}
bool sx_winimage_zip_build(sx_context*c)
{
 return sx_cm_winimage(c);
}
