/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical authenticated executable-carrier metadata. Unimplemented payloads remain raw. */

static const xx_data_struct_field_desc sx_cm_sfx_szdd_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("compression_mode","uint8",8,1,SX_ID),
    SX_FIELD("original_last_character","uint8",9,1,SX_NONE),
    SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sx_cm_sfx_szdd_header = {0x60240001U,"sfx_szdd_header",sx_cm_sfx_szdd_header_fields,SX_COUNT(sx_cm_sfx_szdd_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_cm_sfx_szdd_legacy_header_fields[] = {
    SX_FIELD("magic","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("compression_mode","uint8",7,1,SX_ID),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sx_cm_sfx_szdd_legacy_header = {0x60240002U,"sfx_szdd_legacy_header",sx_cm_sfx_szdd_legacy_header_fields,SX_COUNT(sx_cm_sfx_szdd_legacy_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_cm_winimage_sfx_marker_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sx_cm_winimage_sfx_marker = {0x60240003U,"winimage_sfx_marker",sx_cm_winimage_sfx_marker_fields,SX_COUNT(sx_cm_winimage_sfx_marker_fields),SX_LE};

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
static const sx_layout sx_cm_winimage_zip_local_header = {0x60240004U,"winimage_zip_local_header",sx_cm_winimage_zip_local_header_fields,SX_COUNT(sx_cm_winimage_zip_local_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_cm_winimage_zip_central_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_made_by","uint16",4,2,SX_ID),
    SX_FIELD("version_needed","uint16",6,2,SX_ID),
    SX_FIELD("flags","uint16",8,2,SX_FLAGS),
    SX_FIELD("compression_method","uint16",10,2,SX_ID),
    SX_FIELD("modified_time","uint16",12,2,SX_NONE),
    SX_FIELD("modified_date","uint16",14,2,SX_NONE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
    SX_FIELD("filename_length","uint16",28,2,SX_SIZE),
    SX_FIELD("extra_length","uint16",30,2,SX_SIZE),
    SX_FIELD("comment_length","uint16",32,2,SX_SIZE),
    SX_FIELD("start_disk","uint16",34,2,SX_ID),
    SX_FIELD("internal_attributes","uint16",36,2,SX_FLAGS),
    SX_FIELD("external_attributes","uint32",38,4,SX_FLAGS),
    SX_FIELD("local_header_offset","uint32",42,4,SX_OFFSET),
};
static const sx_layout sx_cm_winimage_zip_central_header = {0x60240005U,"winimage_zip_central_header",sx_cm_winimage_zip_central_header_fields,SX_COUNT(sx_cm_winimage_zip_central_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_cm_winimage_zip_end_record_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("disk_number","uint16",4,2,SX_ID),
    SX_FIELD("central_directory_disk","uint16",6,2,SX_ID),
    SX_FIELD("entries_on_disk","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("central_directory_size","uint32",12,4,SX_SIZE),
    SX_FIELD("central_directory_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("comment_length","uint16",20,2,SX_SIZE),
};
static const sx_layout sx_cm_winimage_zip_end_record = {0x60240006U,"winimage_zip_end_record",sx_cm_winimage_zip_end_record_fields,SX_COUNT(sx_cm_winimage_zip_end_record_fields),SX_LE};

static const xx_data_struct_field_desc sx_cm_winimage_zip_extra_field_fields[] = {
    SX_FIELD("header_id","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sx_cm_winimage_zip_extra_field = {0x60240007U,"winimage_zip_extra_field",sx_cm_winimage_zip_extra_field_fields,SX_COUNT(sx_cm_winimage_zip_extra_field_fields),SX_LE};

static const sx_layout *const sx_carriermeta_layouts[] = {
    &sx_cm_sfx_szdd_header,
    &sx_cm_sfx_szdd_legacy_header,
    &sx_cm_winimage_sfx_marker,
    &sx_cm_winimage_zip_local_header,
    &sx_cm_winimage_zip_central_header,
    &sx_cm_winimage_zip_end_record,
    &sx_cm_winimage_zip_extra_field,
};

static bool sx_carriermeta_supports(xx_file_type_t t){return t==XX_FILE_TYPE_SFX_SZDD||t==XX_FILE_TYPE_WINIMAGE_ZIP;}
static bool sx_cm_span(sx_context*c,int64_t p,uint64_t n){return p>=0&&p<=c->size&&n<=(uint64_t)(c->size-p);}
static bool sx_cm_read(sx_context*c,int64_t p,void*b,size_t n){return sx_cm_span(c,p,n)&&sx_read(c,p,b,n);}
static bool sx_cm_add(sx_context*c,const sx_layout*l,int64_t p,int64_t z){if(!sx_cm_span(c,p,(uint64_t)z))return false;if(c->count>=20000)return true;return sx_add(c,l,p,z);}
/* These callbacks revalidate the outer carrier and provide owned enumeration
 * state. Never synthesize a member span by searching untrusted magic alone. */
static xx_archive_record_state *sx_cm_records(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return NULL;return (f->create_archive_records_reading)(f,NULL,c->pd);}
static bool sx_cm_szdd(sx_context*c){xx_archive_record_state*s=sx_cm_records(c);if(!s)return false;const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);bool ok=false;
 if(r&&r->data_offset>=c->f->base_address&&r->compressed_size>=14){int64_t p=r->data_offset-c->f->base_address;uint8_t h[14];if(sx_cm_span(c,p,(uint64_t)r->compressed_size)&&sx_cm_read(c,p,h,14)){
  if(!xx_rt_memcmp(h,"SZDD\x88\xf0\x27\x33",8)&&h[8]=='A')ok=sx_cm_add(c,&sx_cm_sfx_szdd_header,p,14);
  else if(!xx_rt_memcmp(h,"ZDD\x88\xf0\x27\x33" "A",8))ok=sx_cm_add(c,&sx_cm_sfx_szdd_legacy_header,p,12);
 }}(c->f->free_archive_records_reading)(c->f,s);return ok;}
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
static int sx_cm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_cm_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_cm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end||(p>end&&!sx_raw(c,end,p-end)))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_cm_order);return !c->failed;}
static bool sx_carriermeta_build(sx_context*c){if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=c->f->file_type==XX_FILE_TYPE_SFX_SZDD?sx_cm_szdd(c):c->f->file_type==XX_FILE_TYPE_WINIMAGE_ZIP?sx_cm_winimage(c):false;return ok&&sx_cm_finish(c);}
static bool sx_carriermeta_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<0x60240000U||id>=0x60250000U)return true;const wchar_t*s=NULL;uint64_t v=xx_var_get_u64(&r->value);
 if(!xx_rt_wcscmp(r->name,L"compression_mode"))s=v=='A'?L"SZDD LZSS mode A":NULL;
 else if(!xx_rt_wcscmp(r->name,L"original_last_character"))s=L"Original filename's last character, replaced by underscore by the compressor; zero if unavailable";
 else if(!xx_rt_wcscmp(r->name,L"modified_time"))s=L"Packed DOS time: hour bits11..15, minute bits5..10, seconds/2 bits0..4; not a Unix timestamp";
 else if(!xx_rt_wcscmp(r->name,L"modified_date"))s=L"Packed DOS date: year since1980 bits9..15, month bits5..8, day bits0..4; not a Unix timestamp";
 else if(!xx_rt_wcscmp(r->name,L"compression_method"))s=v==0?L"Stored":NULL;
 else if(id==sx_cm_winimage_zip_central_header.id&&!xx_rt_wcscmp(r->name,L"local_header_offset"))s=L"Stored offset relative to the outer executable image start, not to the embedded ZIP start";
 else if(id==sx_cm_winimage_zip_end_record.id&&!xx_rt_wcscmp(r->name,L"central_directory_offset"))s=L"Stored offset relative to the embedded ZIP start immediately after WSfx; value is not translated";
 else if(id==sx_cm_winimage_zip_extra_field.id&&!xx_rt_wcscmp(r->name,L"header_id"))s=v==1?L"ZIP64 extended information":v==0x5455?L"Extended timestamp":v==0x000a?L"NTFS":NULL;
 return !s||xx_data_struct_record_set_comment(r,s);}
