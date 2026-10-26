/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_nullsoft_pimp data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_pimp_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("install_directory_present","uint8",8,1,SX_FLAGS),
};
const sx_layout sxiex_pimp_header = {0x60820025U,"pimp_header",sxiex_pimp_header_fields,SX_COUNT(sxiex_pimp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_directory_fields[] = {
    SX_FIELD("default_directory","char[260]",0,260,SX_NONE),
};
const sx_layout sxiex_pimp_directory = {0x60820026U,"pimp_directory",sxiex_pimp_directory_fields,SX_COUNT(sxiex_pimp_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_text_fields[] = {
    SX_FIELD("title","char[128]",0,128,SX_NONE),
    SX_FIELD("description","char[128]",128,128,SX_NONE),
};
const sx_layout sxiex_pimp_text = {0x60820027U,"pimp_text",sxiex_pimp_text_fields,SX_COUNT(sxiex_pimp_text_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_v1_count_fields[] = {
    SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxiex_pimp_v1_count = {0x60820028U,"pimp_v1_count",sxiex_pimp_v1_count_fields,SX_COUNT(sxiex_pimp_v1_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_v2_count_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
    SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxiex_pimp_v2_count = {0x60820029U,"pimp_v2_count",sxiex_pimp_v2_count_fields,SX_COUNT(sxiex_pimp_v2_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_name_length_fields[] = {
    SX_FIELD("name_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_pimp_name_length = {0x6082002aU,"pimp_name_length",sxiex_pimp_name_length_fields,SX_COUNT(sxiex_pimp_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_v1_sizes_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_pimp_v1_sizes = {0x6082002bU,"pimp_v1_sizes",sxiex_pimp_v1_sizes_fields,SX_COUNT(sxiex_pimp_v1_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_v2_sizes_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_pimp_v2_sizes = {0x6082002cU,"pimp_v2_sizes",sxiex_pimp_v2_sizes_fields,SX_COUNT(sxiex_pimp_v2_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pimp_command_length_fields[] = {
    SX_FIELD("command_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_pimp_command_length = {0x6082002dU,"pimp_command_length",sxiex_pimp_command_length_fields,SX_COUNT(sxiex_pimp_command_length_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_pimp(sx_context*c,const sxiex_records*r){
 uint64_t p,at;uint8_t dir;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"PIMPFILE",8)||!sxiex_read(c,p+8,&dir,1))return true;
 if(!SXIEX_ADD(c,pimp_header,p))return false;at=p+9;if(dir){if(!sxiex_span(c,at,260))return true;if(!SXIEX_ADD(c,pimp_directory,at))return false;at+=260;}
 if(!sxiex_span(c,at,256))return true;if(!SXIEX_ADD(c,pimp_text,at))return false;at+=256;
 bool known=false,v2=false;for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header==at+8){known=true;v2=true;break;}if(m->header==at+4){known=true;break;}}
 if(!known)return true;if(!sxiex_put(c,v2?&sxiex_pimp_v2_count:&sxiex_pimp_v1_count,at,1))return false;
 uint64_t end=0;for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint32_t n;if(!sxiex_u32(c,m->header,&n)||m->header_size!=(uint64_t)n+(v2?12:8)||n>1024)continue;
 if(!SXIEX_ADD(c,pimp_name_length,m->header)||!sxiex_name(c,m->header+4,n)||!sxiex_put(c,v2?&sxiex_pimp_v2_sizes:&sxiex_pimp_v1_sizes,m->header+4+n,1))return false;if(m->data+m->packed>end)end=m->data+m->packed;}
 uint32_t n;if(end&&sxiex_u32(c,end,&n)&&n<=65536&&sxiex_span(c,end+4,n)){if(!SXIEX_ADD(c,pimp_command_length,end)||!sxiex_name(c,end+4,n))return false;}
 return true;
}
bool sx_sfx_nullsoft_pimp_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_pimp(c,records);
}
#undef SXIEX_ADD
