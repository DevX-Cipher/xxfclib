/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JAM resource archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_jam_header_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxag_jam_header = {UINT32_C(0x60250030),"jam_header",sxag_jam_header_fields,SX_COUNT(sxag_jam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_file_count_fields[] = {
 SX_FIELD("file_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxag_jam_file_count = {UINT32_C(0x60250031),"jam_file_count",sxag_jam_file_count_fields,SX_COUNT(sxag_jam_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_directory_count_fields[] = {
 SX_FIELD("directory_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxag_jam_directory_count = {UINT32_C(0x60250032),"jam_directory_count",sxag_jam_directory_count_fields,SX_COUNT(sxag_jam_directory_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_file_fields[] = {
 SX_FIELD("name","char[15]",0,15,SX_STRING),
 SX_FIELD("data_offset","int32",15,4,SX_OFFSET),
 SX_FIELD("data_size","int32",19,4,SX_SIZE),
};
const sx_layout sxag_jam_file = {UINT32_C(0x60250033),"jam_file",sxag_jam_file_fields,SX_COUNT(sxag_jam_file_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_directory_fields[] = {
 SX_FIELD("name","char[15]",0,15,SX_STRING),
 SX_FIELD("node_offset","int32",15,4,SX_OFFSET),
};
const sx_layout sxag_jam_directory = {UINT32_C(0x60250034),"jam_directory",sxag_jam_directory_fields,SX_COUNT(sxag_jam_directory_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_jam(sx_context *c){uint8_t b[23];if(!sxag_add(c,&sxag_jam_header,0))return false;uint64_t *queue=xx_mem_alloc(4096*sizeof(*queue));if(!queue)return false;size_t head=0,tail=1;queue[0]=3;bool ok=true;
 while(head<tail&&c->count<SXAG_LIMIT){uint64_t p=queue[head++];if(!sxag_read(c,p,b,4)||!sxag_free(c,p,4))continue;uint64_t n=sxag32(b,false);if(n>SXAG_LIMIT||!sxag_span(c,p+4,n*23+4))continue;if(!sxag_add(c,&sxag_jam_file_count,p)||(n&&!sxag_table(c,&sxag_jam_file,p+4,n))){ok=false;break;}p+=4+n*23;if(!sxag_read(c,p,b,4))continue;n=sxag32(b,false);if(n>4096||!sxag_span(c,p+4,n*19))continue;if(!sxag_add(c,&sxag_jam_directory_count,p)||(n&&!sxag_table(c,&sxag_jam_directory,p+4,n))){ok=false;break;}p+=4;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,p+i*19,b,19))break;uint64_t child=sxag32(b+15,false);if(child<3||child>INT32_MAX)continue;bool seen=false;for(size_t j=0;j<tail;j++)if(queue[j]==child)seen=true;if(!seen&&tail<4096)queue[tail++]=child;}}
 xx_mem_free(queue);return ok;}
bool sx_jam_build(sx_context*c)
{
 return sxag_jam(c);
}
