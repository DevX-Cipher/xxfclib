/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UUE data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_uue_begin_fields[]={
 SX_FIELD("marker","char[5]",0,5,SX_SIGNATURE),
};
const sx_layout sxarm_uue_begin={UINT32_C(0x607c0034),"uue_begin",sxarm_uue_begin_fields,SX_COUNT(sxarm_uue_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_1_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[1]",0,1,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_1={UINT32_C(0x607c0035),"uue_mode_1",sxarm_uue_mode_1_fields,SX_COUNT(sxarm_uue_mode_1_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_2_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[2]",0,2,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_2={UINT32_C(0x607c0036),"uue_mode_2",sxarm_uue_mode_2_fields,SX_COUNT(sxarm_uue_mode_2_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_3_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[3]",0,3,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_3={UINT32_C(0x607c0037),"uue_mode_3",sxarm_uue_mode_3_fields,SX_COUNT(sxarm_uue_mode_3_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_4_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[4]",0,4,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_4={UINT32_C(0x607c0038),"uue_mode_4",sxarm_uue_mode_4_fields,SX_COUNT(sxarm_uue_mode_4_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_5_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[5]",0,5,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_5={UINT32_C(0x607c0039),"uue_mode_5",sxarm_uue_mode_5_fields,SX_COUNT(sxarm_uue_mode_5_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_6_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[6]",0,6,SX_FLAGS),
};
const sx_layout sxarm_uue_mode_6={UINT32_C(0x607c003a),"uue_mode_6",sxarm_uue_mode_6_fields,SX_COUNT(sxarm_uue_mode_6_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_line_fields[]={
 SX_FIELD("encoded_decoded_length","char[1]",0,1,SX_NONE),
};
const sx_layout sxarm_uue_line={UINT32_C(0x607c003b),"uue_line",sxarm_uue_line_fields,SX_COUNT(sxarm_uue_line_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_end_fields[]={
 SX_FIELD("marker","char[3]",0,3,SX_ID),
};
const sx_layout sxarm_uue_end={UINT32_C(0x607c003c),"uue_end",sxarm_uue_end_fields,SX_COUNT(sxarm_uue_end_fields),SX_LE};
static bool sxarm_uue(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*st=(f->create_archive_records_reading)(f,NULL,c->pd);if(!st)return false;bool ok=true;uint8_t b[4096];size_t n;uint64_t next;for(unsigned i=0;i<SXARM_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,st);if(!r)break;if(r->header_offset<f->base_address||r->data_offset<f->base_address||r->header_size<0||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-f->base_address),data=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;if(!sxarm_span(c,p,(uint64_t)r->header_size)||!sxarm_span(c,data,z)||!sxarm_line(c,p,b,sizeof(b),&n,&next)||n<8||xx_rt_memcmp(b,"begin ",6)){ok=false;break;}size_t q=6,a=q;while(q<n&&b[q]>='0'&&b[q]<='7')q++;size_t digits=q-a;const sx_layout*modes[]={&sxarm_uue_mode_1,&sxarm_uue_mode_2,&sxarm_uue_mode_3,&sxarm_uue_mode_4,&sxarm_uue_mode_5,&sxarm_uue_mode_6};if(digits<1||digits>6||q==n||b[q]!=' '||!sxarm_add(c,&sxarm_uue_begin,p)||!sxarm_add(c,modes[digits-1],p+a)){ok=false;break;}q++;size_t name_end=n;while(name_end>q&&(b[name_end-1]==' '||b[name_end-1]=='\t'))name_end--;if(!sxarm_text(c,&sxarm_transport_filename,p+q,name_end-q,false)){ok=false;break;}p=data;while(p<data+z){if(!sxarm_line(c,p,b,sizeof(b),&n,&next)||next>data+z){ok=false;break;}if(n&&!sxarm_add(c,&sxarm_uue_line,p)){ok=false;break;}p=next;}if(!ok)break;/* At most one zero-length line plus native-bounded blank lines and end. */unsigned method=(unsigned)xx_archive_record_get_meta_u64(r,XX_META_ID_COMPRESSION_METHOD,0);bool zero=false;for(unsigned j=0;j<258&&p<(uint64_t)c->size;j++){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))break;if(n>=3&&!xx_rt_memcmp(b,"end",3)){size_t k=3;while(k<n&&(b[k]==' '||b[k]=='\t'))k++;if(k==n){ok=sxarm_add(c,&sxarm_uue_end,p);break;}}if(!zero&&n>=1&&(method?b[0]=='+':b[0]==' '||b[0]=='`')){ok=sxarm_add(c,&sxarm_uue_line,p);zero=true;}else if(!n)zero=true;else break;if(!ok)break;p=next;}if(!ok||!(f->archive_record_move_to_next)(f,st,c->pd))break;}(f->free_archive_records_reading)(f,st);return ok;}
bool sx_uue_build(sx_context*c)
{
 return sxarm_uue(c);
}
