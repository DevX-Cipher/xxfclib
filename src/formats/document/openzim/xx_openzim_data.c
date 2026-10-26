/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * openZIM archives data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_zim_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint16",4,2,SX_ID),
 SX_FIELD("minor_version","uint16",6,2,SX_ID),
 SX_FIELD("uuid","bytes",8,16,SX_ID),
 SX_FIELD("entry_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("cluster_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("url_pointer_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("title_pointer_offset","uint64",40,8,SX_OFFSET),
 SX_FIELD("cluster_pointer_offset","uint64",48,8,SX_OFFSET),
 SX_FIELD("mime_list_offset","uint64",56,8,SX_OFFSET),
 SX_FIELD("main_page","uint32",64,4,SX_ID),
 SX_FIELD("layout_page","uint32",68,4,SX_ID),
 SX_FIELD("checksum_offset","uint64",72,8,SX_OFFSET),
};
const sx_layout sxdm_zim_header={UINT32_C(0x6023002E),"zim_header",sxdm_zim_header_fields,SX_COUNT(sxdm_zim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_url_pointer_fields[]={
 SX_FIELD("directory_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxdm_zim_url_pointer={UINT32_C(0x6023002F),"zim_url_pointer",sxdm_zim_url_pointer_fields,SX_COUNT(sxdm_zim_url_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_title_pointer_fields[]={
 SX_FIELD("entry_index","uint32",0,4,SX_ID),
};
const sx_layout sxdm_zim_title_pointer={UINT32_C(0x60230030),"zim_title_pointer",sxdm_zim_title_pointer_fields,SX_COUNT(sxdm_zim_title_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_cluster_pointer_fields[]={
 SX_FIELD("cluster_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxdm_zim_cluster_pointer={UINT32_C(0x60230031),"zim_cluster_pointer",sxdm_zim_cluster_pointer_fields,SX_COUNT(sxdm_zim_cluster_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_article_entry_fields[]={
 SX_FIELD("mime_type","uint16",0,2,SX_ID),
 SX_FIELD("parameter_length","uint8",2,1,SX_SIZE),
 SX_FIELD("namespace","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint32",4,4,SX_NONE),
 SX_FIELD("cluster_index","uint32",8,4,SX_ID),
 SX_FIELD("blob_index","uint32",12,4,SX_ID),
};
const sx_layout sxdm_zim_article_entry={UINT32_C(0x60230032),"zim_article_entry",sxdm_zim_article_entry_fields,SX_COUNT(sxdm_zim_article_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_redirect_entry_fields[]={
 SX_FIELD("mime_type","uint16",0,2,SX_ID),
 SX_FIELD("parameter_length","uint8",2,1,SX_SIZE),
 SX_FIELD("namespace","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint32",4,4,SX_NONE),
 SX_FIELD("redirect_index","uint32",8,4,SX_ID),
};
const sx_layout sxdm_zim_redirect_entry={UINT32_C(0x60230033),"zim_redirect_entry",sxdm_zim_redirect_entry_fields,SX_COUNT(sxdm_zim_redirect_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_cluster_header_fields[]={
 SX_FIELD("compression_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdm_zim_cluster_header={UINT32_C(0x60230034),"zim_cluster_header",sxdm_zim_cluster_header_fields,SX_COUNT(sxdm_zim_cluster_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_blob_offset32_fields[]={
 SX_FIELD("cluster_data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdm_zim_blob_offset32={UINT32_C(0x60230035),"zim_blob_offset32",sxdm_zim_blob_offset32_fields,SX_COUNT(sxdm_zim_blob_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_blob_offset64_fields[]={
 SX_FIELD("cluster_data_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxdm_zim_blob_offset64={UINT32_C(0x60230036),"zim_blob_offset64",sxdm_zim_blob_offset64_fields,SX_COUNT(sxdm_zim_blob_offset64_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_checksum_fields[]={
 SX_FIELD("md5","bytes",0,16,SX_CHECKSUM),
};
const sx_layout sxdm_zim_checksum={UINT32_C(0x60230037),"zim_checksum",sxdm_zim_checksum_fields,SX_COUNT(sxdm_zim_checksum_fields),SX_LE};
static bool sxdm_zim(sx_context *c)
{
 uint8_t b[80];uint64_t *clusters=NULL,*dirs=NULL;bool ok=false;
 if(!sx_read(c,0,b,80)||!sxdm_add(c,&sxdm_zim_header,0,80))return false;
 uint32_t ne=sxdm_u32(b+24),nc=sxdm_u32(b+28);uint64_t urls=sxdm_u64(b+32),titles=sxdm_u64(b+40),cp=sxdm_u64(b+48),checksum=sxdm_u64(b+72);
 if(!ne||ne>2048||!nc||nc>1024||checksum>INT64_MAX||!sxdm_span(c,(int64_t)checksum,16)||urls>checksum||titles>checksum||cp>checksum||!sxdm_span(c,(int64_t)urls,(uint64_t)ne*8)||!sxdm_span(c,(int64_t)titles,(uint64_t)ne*4)||!sxdm_span(c,(int64_t)cp,(uint64_t)nc*8))return false;
 clusters=xx_mem_alloc(nc*sizeof(*clusters));dirs=xx_mem_alloc(ne*sizeof(*dirs));if(!clusters||!dirs)goto done;
 for(uint32_t i=0;i<nc;i++){if(!sx_u64(c,(int64_t)cp+i*8,false,&clusters[i])||clusters[i]>=checksum||!sxdm_add(c,&sxdm_zim_cluster_pointer,(int64_t)cp+i*8,8))goto done;}
 for(uint32_t i=0;i<ne;i++){
  if(!sx_u64(c,(int64_t)urls+i*8,false,&dirs[i])||dirs[i]>=checksum||!sxdm_add(c,&sxdm_zim_url_pointer,(int64_t)urls+i*8,8)||!sxdm_add(c,&sxdm_zim_title_pointer,(int64_t)titles+i*4,4)||!sx_read(c,(int64_t)dirs[i],b,12))goto done;
  unsigned fixed=sxdm_u16(b)==65535?12:16;if(!sxdm_add(c,fixed==12?&sxdm_zim_redirect_entry:&sxdm_zim_article_entry,(int64_t)dirs[i],fixed))goto done;
 }
 for(uint32_t i=0;i<nc;i++){
  uint64_t at=clusters[i],end=i+1<nc?clusters[i+1]:checksum;if(end<=at)goto done;
  uint64_t tables[]={urls,titles,cp};for(unsigned j=0;j<3;j++)if(tables[j]>at&&tables[j]<end)end=tables[j];for(uint32_t j=0;j<ne;j++)if(dirs[j]>at&&dirs[j]<end)end=dirs[j];
  if(!sx_read(c,(int64_t)at,b,1)||!sxdm_add(c,&sxdm_zim_cluster_header,(int64_t)at,1))goto done;
  if((b[0]&15)<=1){unsigned width=b[0]&16?8:4;uint64_t first;if(end-at-1<width||!sx_read(c,(int64_t)at+1,b,width))goto done;first=width==8?sxdm_u64(b):sxdm_u32(b);if(first<2*width||first%width||first>end-at-1||first/width>65536)goto done;
   for(uint64_t j=0;j<first/width;j++)if(!sxdm_add(c,width==8?&sxdm_zim_blob_offset64:&sxdm_zim_blob_offset32,(int64_t)at+1+(int64_t)j*width,width))goto done;
  }
 }
 ok=sxdm_add(c,&sxdm_zim_checksum,(int64_t)checksum,16);
done:xx_mem_free(clusters);xx_mem_free(dirs);return ok;
}
bool sx_openzim_build(sx_context*c)
{
 return sxdm_zim(c);
}
