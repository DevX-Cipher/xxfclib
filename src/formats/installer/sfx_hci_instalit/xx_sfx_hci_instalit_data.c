/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_hci_instalit data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_instalit_engine_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_instalit_engine = {0x60820014U,"instalit_engine",sxiex_instalit_engine_fields,SX_COUNT(sxiex_instalit_engine_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_footer_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("serial_number","char[12]",1,12,SX_NONE),
    SX_FIELD("script_offset","uint32",13,4,SX_OFFSET),
    SX_FIELD("catalog_end_offset","uint32",17,4,SX_OFFSET),
    SX_FIELD("packed_data_offset","uint32",21,4,SX_OFFSET),
    SX_FIELD("catalog_offset","uint32",25,4,SX_OFFSET),
};
const sx_layout sxiex_instalit_footer = {0x60820015U,"instalit_footer",sxiex_instalit_footer_fields,SX_COUNT(sxiex_instalit_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_catalog_prefix_fields[] = {
    SX_FIELD("record_tag","uint8",0,1,SX_ID),
    SX_FIELD("data_offset","uint32",1,4,SX_OFFSET),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("name","char[13]",6,13,SX_NONE),
    SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("dos_date","uint16",24,2,SX_NONE),
    SX_FIELD("dos_time","uint16",26,2,SX_NONE),
};
const sx_layout sxiex_instalit_catalog_prefix = {0x60820016U,"instalit_catalog_prefix",sxiex_instalit_catalog_prefix_fields,SX_COUNT(sxiex_instalit_catalog_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_catalog_1c55_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",4,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("unknown","byte[16]",11,16,SX_NONE),
};
const sx_layout sxiex_instalit_catalog_1c55 = {0x60820017U,"instalit_catalog_1c55",sxiex_instalit_catalog_1c55_fields,SX_COUNT(sxiex_instalit_catalog_1c55_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_catalog_1c59_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",4,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("unknown","byte[20]",11,20,SX_NONE),
};
const sx_layout sxiex_instalit_catalog_1c59 = {0x60820018U,"instalit_catalog_1c59",sxiex_instalit_catalog_1c59_fields,SX_COUNT(sxiex_instalit_catalog_1c59_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_catalog_1a47_fields[] = {
    SX_FIELD("unpacked_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",2,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
    SX_FIELD("unknown","byte[10]",9,10,SX_NONE),
};
const sx_layout sxiex_instalit_catalog_1a47 = {0x60820019U,"instalit_catalog_1a47",sxiex_instalit_catalog_1a47_fields,SX_COUNT(sxiex_instalit_catalog_1a47_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_script_fields[] = {
    SX_FIELD("marker","byte[9]",0,9,SX_SIGNATURE),
};
const sx_layout sxiex_instalit_script = {0x6082001aU,"instalit_script",sxiex_instalit_script_fields,SX_COUNT(sxiex_instalit_script_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_data_marker_fields[] = {
    SX_FIELD("marker","byte[6]",0,6,SX_SIGNATURE),
};
const sx_layout sxiex_instalit_data_marker = {0x6082001bU,"instalit_data_marker",sxiex_instalit_data_marker_fields,SX_COUNT(sxiex_instalit_data_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_resource_shift_fields[] = {
    SX_FIELD("alignment_shift","uint16",0,2,SX_NONE),
};
const sx_layout sxiex_instalit_resource_shift = {0x6082005cU,"instalit_resource_shift",sxiex_instalit_resource_shift_fields,SX_COUNT(sxiex_instalit_resource_shift_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_resource_type_fields[] = {
    SX_FIELD("type_identifier","uint16",0,2,SX_ID),
    SX_FIELD("resource_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
const sx_layout sxiex_instalit_resource_type = {0x6082005dU,"instalit_resource_type",sxiex_instalit_resource_type_fields,SX_COUNT(sxiex_instalit_resource_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_resource_entry_fields[] = {
    SX_FIELD("offset_units","uint16",0,2,SX_NONE),
    SX_FIELD("length_units","uint16",2,2,SX_NONE),
    SX_FIELD("flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("resource_identifier","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxiex_instalit_resource_entry = {0x6082005eU,"instalit_resource_entry",sxiex_instalit_resource_entry_fields,SX_COUNT(sxiex_instalit_resource_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_resource_end_fields[] = {
    SX_FIELD("type_terminator","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxiex_instalit_resource_end = {0x6082005fU,"instalit_resource_end",sxiex_instalit_resource_end_fields,SX_COUNT(sxiex_instalit_resource_end_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_instalit_resource_name_length_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxiex_instalit_resource_name_length = {0x60820060U,"instalit_resource_name_length",sxiex_instalit_resource_name_length_fields,SX_COUNT(sxiex_instalit_resource_name_length_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_instalit_resources(sx_context*c){
 uint8_t dos[64],ne[40],row[12];if(!sxiex_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return true;
 uint64_t np=sxiex32(dos+60,false);if(!sxiex_read(c,np,ne,40)||ne[0]!='N'||ne[1]!='E')return true;
 uint64_t start=np+sxiex16(ne+36,false),end=np+sxiex16(ne+38,false);uint16_t shift;
 if(end<=start||end-start<4||!sxiex_span(c,start,end-start)||!sxiex_u16(c,start,&shift)||shift>15)return true;
 if(!SXIEX_ADD(c,instalit_resource_shift,start))return false;uint64_t p=start+2;
 for(unsigned types=0;types<1024&&end-p>=2;types++){
  uint16_t type,n;if(!sxiex_u16(c,p,&type))return false;if(!type){if(!SXIEX_ADD(c,instalit_resource_end,p))return false;break;}
  if(end-p<8||!sxiex_read(c,p,row,8))break;n=sxiex16(row+2,false);if((uint64_t)n*12>end-p-8)break;
  if(!SXIEX_ADD(c,instalit_resource_type,p))return false;p+=8;
  for(unsigned i=0;i<=n;i++){
   uint16_t id=type;if(i<n){if(!sxiex_read(c,p+(uint64_t)i*12,row,12))return false;id=sxiex16(row+6,false);if(!SXIEX_ADD(c,instalit_resource_entry,p+(uint64_t)i*12))return false;}
   if(!(id&0x8000U)&&id<end-start){uint8_t z;uint64_t q=start+id;if(sxiex_read(c,q,&z,1)&&z<=end-q-1){if(!SXIEX_ADD(c,instalit_resource_name_length,q)||!sxiex_name(c,q+1,z))return false;}}
  }
  p+=(uint64_t)n*12;
 }
 return true;
}
static bool sxiex_instalit(sx_context*c,const sxiex_records*r){
 if(!sxiex_instalit_resources(c))return false;
 uint8_t foot[29];if(c->size>=29&&sxiex_read(c,(uint64_t)c->size-29,foot,29)&&foot[0]==12){bool digits=true;for(unsigned i=1;i<13;i++)if(foot[i]<'0'||foot[i]>'9')digits=false;
 if(digits){if(!SXIEX_ADD(c,instalit_footer,(uint64_t)c->size-29))return false;uint64_t p=sxiex32(foot+21,false);if(sxiex_eq(c,p,"\x05[PVL]",6)&&!SXIEX_ADD(c,instalit_data_marker,p))return false;p=sxiex32(foot+25,false);if(sxiex_eq(c,p,"\x05[PVM]",6)&&!SXIEX_ADD(c,instalit_data_marker,p))return false;}}
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t tag;if(!sxiex_read(c,m->header,&tag,1))continue;
 if(m->header_size==8){if(!SXIEX_ADD(c,instalit_engine,m->header))return false;}
 else if(m->header_size==9&&sxiex_eq(c,m->header,"\x08[SCRIPT]",9)){if(!SXIEX_ADD(c,instalit_script,m->header))return false;}
 else if((tag==0x1c&&(m->header_size==55||m->header_size==59))||(tag==0x1a&&m->header_size==47)){
  if(!SXIEX_ADD(c,instalit_catalog_prefix,m->header)||!sxiex_put(c,tag==0x1a?&sxiex_instalit_catalog_1a47:m->header_size==55?&sxiex_instalit_catalog_1c55:&sxiex_instalit_catalog_1c59,m->header+28,1))return false;}
 }
 return true;
}
bool sx_sfx_hci_instalit_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_instalit(c,records);
}
#undef SXIEX_ADD
