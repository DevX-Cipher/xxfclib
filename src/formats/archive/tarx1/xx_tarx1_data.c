/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TARX1 data structures, moved out of the archiveresidual schema family. */
#include "../../xx_format_schema_archiveresidual.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarfinal_tarx1_transport_prefix_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxarfinal_tarx1_transport_prefix={UINT32_C(0x6092020b),"tarx1_transport_prefix",sxarfinal_tarx1_transport_prefix_fields,SX_COUNT(sxarfinal_tarx1_transport_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_tarx1_encrypted_tar_core_fields[]={
 SX_FIELD("encoded_name","uint8[100]",0,100,SX_NONE),
 SX_FIELD("encoded_mode","uint8[8]",100,8,SX_NONE),
 SX_FIELD("encoded_uid","uint8[8]",108,8,SX_NONE),
 SX_FIELD("encoded_gid","uint8[8]",116,8,SX_NONE),
 SX_FIELD("encoded_size","uint8[12]",124,12,SX_NONE),
 SX_FIELD("encoded_mtime","uint8[12]",136,12,SX_NONE),
 SX_FIELD("encoded_checksum","uint8[8]",148,8,SX_NONE),
 SX_FIELD("encoded_typeflag","uint8[1]",156,1,SX_NONE),
 SX_FIELD("encoded_linkname","uint8[100]",157,100,SX_NONE),
};
const sx_layout sxarfinal_tarx1_encrypted_tar_core={UINT32_C(0x6092020c),"tarx1_encrypted_tar_core",sxarfinal_tarx1_encrypted_tar_core_fields,SX_COUNT(sxarfinal_tarx1_encrypted_tar_core_fields),SX_LE};
#define SXARFINAL_LIMIT 20000U
/* TARX1's owned inner TAR starts at decoded offset0. Only native member
 * coordinates are translated; none is interpreted as an outer absolute offset. */
static bool sxarfinal_tarx(sx_context*c){
 Abstractformat*f=c->f;uint8_t magic[4];
 if(!sxarfinal_read(c,0,magic,4)||xx_rt_memcmp(magic,"TaRx",4)||!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;
 xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=false;
 if(!sxarfinal_put(c,&sxarfinal_tarx1_transport_prefix,0))goto done;
 for(unsigned i=0;i<SXARFINAL_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r){ok=true;break;}
  if(r->header_offset<0||r->header_size!=512||(uint64_t)r->header_offset>UINT64_MAX-4)goto done;
  uint64_t p=(uint64_t)r->header_offset+4;if(!sxarfinal_span(c,p,512)||!sxarfinal_put(c,&sxarfinal_tarx1_encrypted_tar_core,p))goto done;
  if(!(f->archive_record_move_to_next)(f,s,c->pd)){ok=true;break;}
 }
done:(f->free_archive_records_reading)(f,s);return ok;
}
bool sx_tarx1_build(sx_context*c)
{
bool ok=false;
ok=sxarfinal_tarx(c);
(void)ok;return c->count&&sxarfinal_finish(c);
}
