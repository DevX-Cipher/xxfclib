/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ghost Installer data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_header_fields[] = {
    SX_FIELD("encoded_signature","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_reserved1","byte[4]",4,4,SX_NONE),
    SX_FIELD("encoded_cabinet_size","byte[4]",8,4,SX_NONE),
    SX_FIELD("encoded_reserved2","byte[4]",12,4,SX_NONE),
    SX_FIELD("encoded_files_offset","byte[4]",16,4,SX_NONE),
    SX_FIELD("encoded_reserved3","byte[4]",20,4,SX_NONE),
    SX_FIELD("encoded_version_minor","byte[1]",24,1,SX_NONE),
    SX_FIELD("encoded_version_major","byte[1]",25,1,SX_NONE),
    SX_FIELD("encoded_folder_count","byte[2]",26,2,SX_NONE),
    SX_FIELD("encoded_file_count","byte[2]",28,2,SX_NONE),
    SX_FIELD("encoded_flags","byte[2]",30,2,SX_NONE),
    SX_FIELD("encoded_set_id","byte[2]",32,2,SX_NONE),
    SX_FIELD("encoded_cabinet_index","byte[2]",34,2,SX_NONE),
};
const sx_layout sxil_ghost_encoded_cab_header = {0x60850052U,"ghost_encoded_cab_header",sxil_ghost_encoded_cab_header_fields,SX_COUNT(sxil_ghost_encoded_cab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_encoded_cab_reserve_fields[] = {
    SX_FIELD("encoded_header_reserve_size","byte[2]",0,2,SX_NONE),
    SX_FIELD("encoded_folder_reserve_size","byte[1]",2,1,SX_NONE),
    SX_FIELD("encoded_data_reserve_size","byte[1]",3,1,SX_NONE),
};
const sx_layout sxil_ghost_encoded_cab_reserve = {0x60850053U,"ghost_encoded_cab_reserve",sxil_ghost_encoded_cab_reserve_fields,SX_COUNT(sxil_ghost_encoded_cab_reserve_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_encoded_cab_folder_fields[] = {
    SX_FIELD("encoded_data_offset","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_data_count","byte[2]",4,2,SX_NONE),
    SX_FIELD("encoded_compression_type","byte[2]",6,2,SX_NONE),
};
const sx_layout sxil_ghost_encoded_cab_folder = {0x60850054U,"ghost_encoded_cab_folder",sxil_ghost_encoded_cab_folder_fields,SX_COUNT(sxil_ghost_encoded_cab_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_encoded_cab_file_fields[] = {
    SX_FIELD("encoded_unpacked_size","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_folder_offset","byte[4]",4,4,SX_NONE),
    SX_FIELD("encoded_folder_index","byte[2]",8,2,SX_NONE),
    SX_FIELD("encoded_dos_date","byte[2]",10,2,SX_NONE),
    SX_FIELD("encoded_dos_time","byte[2]",12,2,SX_NONE),
    SX_FIELD("encoded_attributes","byte[2]",14,2,SX_NONE),
};
const sx_layout sxil_ghost_encoded_cab_file = {0x60850055U,"ghost_encoded_cab_file",sxil_ghost_encoded_cab_file_fields,SX_COUNT(sxil_ghost_encoded_cab_file_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_encoded_cab_data_fields[] = {
    SX_FIELD("encoded_checksum","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_packed_size","byte[2]",4,2,SX_NONE),
    SX_FIELD("encoded_unpacked_size","byte[2]",6,2,SX_NONE),
};
const sx_layout sxil_ghost_encoded_cab_data = {0x60850056U,"ghost_encoded_cab_data",sxil_ghost_encoded_cab_data_fields,SX_COUNT(sxil_ghost_encoded_cab_data_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_trailer26_fields[] = {
    SX_FIELD("metadata","byte[20]",0,20,SX_NONE),
    SX_FIELD("marker","char[6]",20,6,SX_SIGNATURE),
};
const sx_layout sxil_ghost_trailer26 = {0x60850057U,"ghost_trailer26",sxil_ghost_trailer26_fields,SX_COUNT(sxil_ghost_trailer26_fields),SX_LE};
static const xx_data_struct_field_desc sxil_ghost_trailer34_fields[] = {
    SX_FIELD("metadata","byte[28]",0,28,SX_NONE),
    SX_FIELD("marker","char[6]",28,6,SX_SIGNATURE),
};
const sx_layout sxil_ghost_trailer34 = {0x60850058U,"ghost_trailer34",sxil_ghost_trailer34_fields,SX_COUNT(sxil_ghost_trailer34_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_ghost_read(sx_context*c,uint64_t p,uint8_t*b,size_t n){if(!sxil_read(c,p,b,n))return false;for(size_t i=0;i<n;i++)b[i]^=0x8d;return true;}
static bool sxil_ghost_zstr(sx_context*c,uint64_t*p,uint64_t end){uint64_t first=*p;uint8_t x;for(unsigned k=0;k<4096&&*p<end;k++,(*p)++){if(!sxil_ghost_read(c,*p,&x,1))return false;if(!x){(*p)++;return sxil_encoded(c,first,*p-first);}}return false;}
static bool sxil_ghost_magic(sx_context*c,uint64_t p){return sxil_span(c,p,71)&&sxil_eq(c,p,"\xc0\xde\xce\xcb\x8d\x8d\x8d\x8d",8);}
static bool sxil_ghost_start(sx_context*c,uint64_t*out){
 if(sxil_ghost_magic(c,0)){*out=0;return true;}
 uint8_t d[64],h[24],row[40];if(!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;uint64_t lf=sxil32(d+60,false);
 if(lf<4||lf>0x10000||!sxil_read(c,lf,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 unsigned count=sxil16(h+6,false),opt=sxil16(h+20,false);if(!count||count>96)return false;uint64_t end=0,tab=lf+24+opt;
 if(opt>=64){uint32_t z;if(!sxil_u32(c,lf+24+60,&z))return false;end=z;}
 if(!sxil_span(c,tab,40U*count))return false;
 for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,row,40))return false;uint64_t n=sxil32(row+16,false),p=sxil32(row+20,false);if(n&&p&&p+n>end)end=p+n;}
 if(!end||end>(uint64_t)c->size)return false;if(sxil_ghost_magic(c,end)){*out=end;return true;}
 if((uint64_t)c->size-end>=105){uint64_t at=(uint64_t)c->size-34;uint32_t p;if(sxil_eq(c,at+28,"GIPEND",6)&&sxil_u32(c,at,&p)&&p>=end&&sxil_ghost_magic(c,p)){*out=p;return true;}}
 return false;
}
static bool sxil_ghost(sx_context*c){uint64_t start;if(!sxil_ghost_start(c,&start))return true;
 for(unsigned seg=0;seg<64;seg++){uint8_t h[36];if(!sxil_ghost_read(c,start,h,36)||xx_rt_memcmp(h,"MSCF",4))return true;uint64_t size=sxil32(h+8,false),files=sxil32(h+16,false);unsigned nf=sxil16(h+26,false),nm=sxil16(h+28,false),flags=sxil16(h+30,false);if(size<36||!sxil_span(c,start,size)||files>size)return true;
  if(!SXIL_ADD(c,ghost_encoded_cab_header,start))return false;uint64_t p=start+36,finish=start+size;unsigned fr=0,dr=0;
  if(flags&4){uint8_t r[4];if(!sxil_ghost_read(c,p,r,4))return true;if(!SXIL_ADD(c,ghost_encoded_cab_reserve,p))return false;uint64_t n=sxil16(r,false);fr=r[2];dr=r[3];p+=4;if(p>finish||n>finish-p)return true;p+=n;}
  for(unsigned bit=1;bit<=2;bit*=2)if(flags&bit){if(!sxil_ghost_zstr(c,&p,finish)||!sxil_ghost_zstr(c,&p,finish))return true;}
  if(p>finish||(uint64_t)nf>(finish-p)/(8+fr))return true;
  for(unsigned i=0;i<nf;i++){uint8_t f[8];if(!sxil_ghost_read(c,p,f,8))return true;if(!SXIL_ADD(c,ghost_encoded_cab_folder,p))return false;uint64_t q=start+sxil32(f,false);unsigned n=sxil16(f+4,false);for(unsigned j=0;j<n;j++){uint8_t d[8];if(q>finish||8+dr>finish-q||!sxil_ghost_read(c,q,d,8))break;uint64_t z=sxil16(d+4,false);if(z>finish-q-8-dr)break;if(!SXIL_ADD(c,ghost_encoded_cab_data,q))return false;q+=8+dr+z;}p+=8+fr;}
  p=start+files;for(unsigned i=0;i<nm&&p<=finish&&16<=finish-p;i++){if(!SXIL_ADD(c,ghost_encoded_cab_file,p))return false;p+=16;if(!sxil_ghost_zstr(c,&p,finish))return true;}
  p=finish;if(sxil_eq(c,p+28,"GIPEND",6)){if(!SXIL_ADD(c,ghost_trailer34,p))return false;start=p+34;}else if(sxil_eq(c,p+20,"GIPEND",6)){if(!SXIL_ADD(c,ghost_trailer26,p))return false;start=p+26;}else return true;
 }return true;}
bool sx_ghost_installer_build(sx_context*c)
{
 return sxil_ghost(c);
}
#undef SXIL_ADD
