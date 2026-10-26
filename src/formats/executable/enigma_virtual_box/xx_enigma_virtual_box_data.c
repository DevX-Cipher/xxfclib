/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Enigma Virtual Box filesystem data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_evb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxbx_evb_header = {UINT32_C(0x603000e6),"evb_header",sxbx_evb_header_fields,SX_COUNT(sxbx_evb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_table_prefix_fields[] = {
 SX_FIELD("node_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("root_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxbx_evb_table_prefix = {UINT32_C(0x603000e7),"evb_table_prefix",sxbx_evb_table_prefix_fields,SX_COUNT(sxbx_evb_table_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_node_fields[] = {
 SX_FIELD("node_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("child_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxbx_evb_node = {UINT32_C(0x603000e8),"evb_node",sxbx_evb_node_fields,SX_COUNT(sxbx_evb_node_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_node_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_ID),
};
const sx_layout sxbx_evb_node_type = {UINT32_C(0x603000e9),"evb_node_type",sxbx_evb_node_type_fields,SX_COUNT(sxbx_evb_node_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_stored_size_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_evb_file_stored_size = {UINT32_C(0x603000ea),"evb_file_stored_size",sxbx_evb_file_stored_size_fields,SX_COUNT(sxbx_evb_file_stored_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_modern_fields[] = {
 SX_FIELD("reserved0","uint16",0,2,SX_NONE),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
 SX_FIELD("unknown","uint32",6,4,SX_NONE),
 SX_FIELD("filetime1","uint64",10,8,SX_NONE),
 SX_FIELD("filetime2","uint64",18,8,SX_NONE),
 SX_FIELD("filetime3","uint64",26,8,SX_NONE),
 SX_FIELD("reserved1","uint8[15]",34,15,SX_NONE),
 SX_FIELD("packed_size","uint32",49,4,SX_SIZE),
};
const sx_layout sxbx_evb_file_modern = {UINT32_C(0x603000f8),"evb_file_modern",sxbx_evb_file_modern_fields,SX_COUNT(sxbx_evb_file_modern_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_legacy_fields[] = {
 SX_FIELD("reserved0","uint16",0,2,SX_NONE),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
 SX_FIELD("unknown","uint32",6,4,SX_NONE),
 SX_FIELD("filetime1","uint64",10,8,SX_NONE),
 SX_FIELD("filetime2","uint64",18,8,SX_NONE),
 SX_FIELD("filetime3","uint64",26,8,SX_NONE),
 SX_FIELD("reserved1","uint8[7]",34,7,SX_NONE),
 SX_FIELD("packed_size","uint32",41,4,SX_SIZE),
 SX_FIELD("reserved2","uint32",45,4,SX_NONE),
};
const sx_layout sxbx_evb_file_legacy = {UINT32_C(0x603000f9),"evb_file_legacy",sxbx_evb_file_legacy_fields,SX_COUNT(sxbx_evb_file_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_chunk_header_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
};
const sx_layout sxbx_evb_chunk_header = {UINT32_C(0x603000fa),"evb_chunk_header",sxbx_evb_chunk_header_fields,SX_COUNT(sxbx_evb_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_chunk_entry_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("total_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_NONE),
};
const sx_layout sxbx_evb_chunk_entry = {UINT32_C(0x603000fb),"evb_chunk_entry",sxbx_evb_chunk_entry_fields,SX_COUNT(sxbx_evb_chunk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_ap32_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint32",16,4,SX_SIZE),
 SX_FIELD("unpacked_crc32","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxbx_evb_ap32 = {UINT32_C(0x603000fc),"evb_ap32",sxbx_evb_ap32_fields,SX_COUNT(sxbx_evb_ap32_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_evb_compressed(sx_context*c,uint64_t p,uint64_t z){uint64_t table;if(z<12||!sxbx_word(c,p,4,false,&table)||table<12||table>=z||(table-12)%12||table>1048576)return true;if(!sxbx_add(c,&sxbx_evb_chunk_header,p))return false;uint64_t count=(table-12)/12+1,data=p+table;for(uint64_t i=0;i<count&&c->count<SXBX_LIMIT;i++){uint64_t n,q=p+8+i*12;if(!sxbx_word(c,q,4,false,&n)||n>p+z-data)break;if(!sxbx_add(c,i+1==count?&sxbx_evb_file_stored_size:&sxbx_evb_chunk_entry,q))return false;uint8_t magic[4];if(n>=24&&sxbx_read(c,data,magic,4)&&!xx_rt_memcmp(magic,"AP32",4)&&!sxbx_add(c,&sxbx_evb_ap32,data))return false;data+=n;}return true;}
static bool sxbx_evb_nodes(sx_context*c,uint64_t*p,uint64_t*payload,uint64_t table_end,uint64_t count,bool legacy,unsigned depth,unsigned*work){if(depth>64||count>SXBX_LIMIT)return false;for(uint64_t i=0;i<count;i++){if(++*work>SXBX_LIMIT||c->count>=SXBX_LIMIT)return false;uint64_t start=*p,size,children,type;if(!sxbx_word(c,start,4,false,&size)||!sxbx_word(c,start+12,4,false,&children)||!sxbx_span(c,start,16))return false;/* First modern child shares one byte with the main-node count, as specified by the external-package layout. */if(!sx_add(c,&sxbx_evb_node,(int64_t)start,16))return false;*p+=16;if(!sxbx_zero_string(c,p,table_end,2)||!sxbx_word(c,*p,1,false,&type)||!sxbx_add(c,&sxbx_evb_node_type,(*p)++))return false;if(type==3){if(legacy){if(size<16||!sxbx_span(c,start,size+4)||start+size+4<*p)return false;*p=start+size+4;}else{if(*p>table_end||table_end-*p<25)return false;*p+=25;}if(!sxbx_evb_nodes(c,p,payload,table_end,children,legacy,depth+1,work))return false;}else if(type==2){uint64_t info,original,packed,data;if(children)return false;if(legacy){if(size<45||!sxbx_span(c,start,size+4)||start+size+4<49||start+size+4-49<*p)return false;info=start+size+4-49;data=start+size+4;}else{info=*p;if(info>table_end||table_end-info<53)return false;data=*payload;}if(!sxbx_word(c,info+2,4,false,&original)||!sxbx_word(c,info+(legacy?41:49),4,false,&packed)||!sxbx_span(c,data,packed)||!sxbx_add(c,legacy?&sxbx_evb_file_legacy:&sxbx_evb_file_modern,info))return false;if(original!=packed&&!sxbx_evb_compressed(c,data,packed))return false;if(legacy)*p=data+packed;else{*p=info+53;*payload+=packed;}}else return false;}return true;}
static bool sxbx_evb(sx_context*c)
{
 uint8_t b[80];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;
 uint8_t*window=xx_mem_alloc(65539);if(!window)return false;unsigned candidates=0;bool result=false;
 for(uint64_t chunk=0;chunk<limit;chunk+=65536){size_t take=(size_t)(limit-chunk>65539?65539:limit-chunk);if(!sxbx_read(c,chunk,window,take))break;
  for(size_t i=0;i+4<=take&&i<65536;i++){
   if(xx_rt_memcmp(window+i,"EVB\0",4))continue;if(++candidates>64)goto done;uint64_t p=chunk+i;
   if(!sxbx_read(c,p,b,80)||sxbx32(b+4,false)!=64)continue;uint64_t size=sxbx32(b+64,false),count=sxbx32(b+76,false);
   if(!count||count>65536||size<15||!sxbx_span(c,p+64,size+4))continue;
   for(unsigned mode=0;mode<2;mode++){size_t keep=c->count;bool legacy=mode!=0;uint64_t q=legacy?p+68+size:p+79,payload=p+68+size,table_end=legacy?(uint64_t)c->size:payload;unsigned work=0;
    if(sxbx_add(c,&sxbx_evb_header,p)&&sxbx_add(c,&sxbx_evb_table_prefix,p+64)&&sxbx_evb_nodes(c,&q,&payload,table_end,count,legacy,0,&work)){result=true;goto done;}c->count=keep;
   }
  }
 }
 done:xx_mem_free(window);return result;
}
bool sx_enigma_virtual_box_build(sx_context*c)
{
 return sxbx_evb(c);
}
