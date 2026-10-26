/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_packagefortheweb data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_pftw_settings_size_fields[] = {
    SX_FIELD("settings_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_pftw_settings_size = {0x60820050U,"pftw_settings_size",sxiex_pftw_settings_size_fields,SX_COUNT(sxiex_pftw_settings_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_settings_new_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxiex_pftw_settings_new = {0x60820051U,"pftw_settings_new",sxiex_pftw_settings_new_fields,SX_COUNT(sxiex_pftw_settings_new_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_settings_old_fields[] = {
    SX_FIELD("encoded_signature","byte[3]",0,3,SX_NONE),
    SX_FIELD("encoded_version","byte[1]",3,1,SX_NONE),
    SX_FIELD("encoded_cabinet_size","byte[4]",4,4,SX_NONE),
};
const sx_layout sxiex_pftw_settings_old = {0x60820052U,"pftw_settings_old",sxiex_pftw_settings_old_fields,SX_COUNT(sxiex_pftw_settings_old_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_cab_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
    SX_FIELD("cabinet_size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved2","uint32",12,4,SX_RESERVED),
    SX_FIELD("files_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("reserved3","uint32",20,4,SX_RESERVED),
    SX_FIELD("version_minor","uint8",24,1,SX_ID),
    SX_FIELD("version_major","uint8",25,1,SX_ID),
    SX_FIELD("folder_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint16",28,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",30,2,SX_FLAGS),
    SX_FIELD("set_identifier","uint16",32,2,SX_ID),
    SX_FIELD("cabinet_index","uint16",34,2,SX_NONE),
};
const sx_layout sxiex_pftw_cab_header = {0x60820053U,"pftw_cab_header",sxiex_pftw_cab_header_fields,SX_COUNT(sxiex_pftw_cab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_cab_reserve_fields[] = {
    SX_FIELD("header_reserved_size","uint16",0,2,SX_SIZE),
    SX_FIELD("folder_reserved_size","uint8",2,1,SX_SIZE),
    SX_FIELD("data_reserved_size","uint8",3,1,SX_SIZE),
};
const sx_layout sxiex_pftw_cab_reserve = {0x60820054U,"pftw_cab_reserve",sxiex_pftw_cab_reserve_fields,SX_COUNT(sxiex_pftw_cab_reserve_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_cab_folder_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_block_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("compression_type","uint16",6,2,SX_ID),
};
const sx_layout sxiex_pftw_cab_folder = {0x60820055U,"pftw_cab_folder",sxiex_pftw_cab_folder_fields,SX_COUNT(sxiex_pftw_cab_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_cab_file_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("folder_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("folder_index","uint16",8,2,SX_NONE),
    SX_FIELD("dos_date","uint16",10,2,SX_NONE),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("attributes","uint16",14,2,SX_FLAGS),
};
const sx_layout sxiex_pftw_cab_file = {0x60820056U,"pftw_cab_file",sxiex_pftw_cab_file_fields,SX_COUNT(sxiex_pftw_cab_file_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_pftw_cab_data_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxiex_pftw_cab_data = {0x60820057U,"pftw_cab_data",sxiex_pftw_cab_data_fields,SX_COUNT(sxiex_pftw_cab_data_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_cab(sx_context*c,uint64_t p,uint64_t span){
 uint8_t h[36],b[8];if(span<36||!sxiex_read(c,p,h,36)||xx_rt_memcmp(h,"MSCF",4))return true;
 uint64_t total=sxiex32(h+8,false),files=sxiex32(h+16,false),at=p+36;uint16_t folders=sxiex16(h+26,false),count=sxiex16(h+28,false),flags=sxiex16(h+30,false);unsigned fr=0,dr=0;
 if(total>span||total<36)return true;uint64_t end=p+total;if(!SXIEX_ADD(c,pftw_cab_header,p))return false;
 if(flags&4){if(end-at<4||!sxiex_read(c,at,b,4))return true;if(!SXIEX_ADD(c,pftw_cab_reserve,at))return false;fr=b[2];dr=b[3];uint64_t z=sxiex16(b,false);if(z>end-at-4)return true;at+=4+z;}
 if(flags&3)return true;if((uint64_t)folders*(8+fr)>end-at)return true;uint64_t first=end;
 for(unsigned i=0;i<folders;i++){uint64_t q=at+(uint64_t)i*(8+fr);if(!sxiex_read(c,q,b,8)||!SXIEX_ADD(c,pftw_cab_folder,q))return false;uint64_t data=sxiex32(b,false);unsigned n=sxiex16(b+4,false);if(data>total)continue;data+=p;if(data<first)first=data;
  for(unsigned j=0;j<n;j++){if(data>end||end-data<8+dr||!sxiex_read(c,data,b,8))break;uint64_t z=sxiex16(b+4,false);if(z>end-data-8-dr)break;if(!SXIEX_ADD(c,pftw_cab_data,data))return false;data+=8+dr+z;}
 }
 if(files>total)return true;at=p+files;for(unsigned i=0;i<count;i++){if(at>first||first-at<16)break;if(!SXIEX_ADD(c,pftw_cab_file,at))return false;at+=16;if(!sxiex_zstr(c,&at,first))break;}return true;
}
static bool sxiex_pftw(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->packed<36||!sxiex_eq(c,m->data,"MSCF",4))continue;if(!sxiex_cab(c,m->data,m->packed))return false;
  uint64_t candidate[3]={UINT64_MAX,UINT64_MAX,UINT64_MAX};sxiex_pe(c,candidate);uint8_t d[64],h[24],s[40];
  if(sxiex_read(c,0,d,64)){uint64_t nt=sxiex32(d+60,false);if(sxiex_read(c,nt,h,24)){unsigned count=sxiex16(h+6,false),opt=sxiex16(h+20,false);if(count<=96)for(unsigned j=0;j<count;j++)if(sxiex_read(c,nt+24+opt+(uint64_t)j*40,s,40)&&!xx_rt_memcmp(s,"_cabinet",8)){candidate[1]=sxiex32(s+20,false);candidate[2]=candidate[1]+12;}}}
  for(unsigned j=0;j<3;j++){uint64_t p=candidate[j];uint32_t z;if(p==UINT64_MAX||!sxiex_u32(c,p,&z)||z<16||z>1048576||p+4+(uint64_t)z!=m->data)continue;
   if(!SXIEX_ADD(c,pftw_settings_size,p))return false;if(sxiex_eq(c,p+4,"\xdc\xed\xbd\xa9",4)){if(!SXIEX_ADD(c,pftw_settings_new,p+4))return false;}else if(!SXIEX_ADD(c,pftw_settings_old,p+4))return false;break;}
 }
 return true;
}
bool sx_sfx_packagefortheweb_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_pftw(c,records);
}
#undef SXIEX_ADD
