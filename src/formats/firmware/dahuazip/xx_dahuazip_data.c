/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DAHUA ZIP data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_installer_zip_local_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16le",4,2,SX_NONE),
 SX_FIELD("flags","uint16le",6,2,SX_FLAGS),
 SX_FIELD("method","uint16le",8,2,SX_ID),
 SX_FIELD("dos_time","uint16le",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16le",12,2,SX_NONE),
 SX_FIELD("crc32","uint32le",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32le",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",22,4,SX_SIZE),
 SX_FIELD("name_length","uint16le",26,2,SX_SIZE),
 SX_FIELD("extra_length","uint16le",28,2,SX_SIZE),
};
const sx_layout sxiw_installer_zip_local={UINT32_C(0x60790055),"installer_zip_local",sxiw_installer_zip_local_fields,SX_COUNT(sxiw_installer_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_central_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("version_made_by","uint16le",4,2,SX_NONE),
 SX_FIELD("version_needed","uint16le",6,2,SX_NONE),
 SX_FIELD("flags","uint16le",8,2,SX_FLAGS),
 SX_FIELD("method","uint16le",10,2,SX_ID),
 SX_FIELD("dos_time","uint16le",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16le",14,2,SX_NONE),
 SX_FIELD("crc32","uint32le",16,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32le",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("name_length","uint16le",28,2,SX_SIZE),
 SX_FIELD("extra_length","uint16le",30,2,SX_SIZE),
 SX_FIELD("comment_length","uint16le",32,2,SX_SIZE),
 SX_FIELD("disk_start","uint16le",34,2,SX_NONE),
 SX_FIELD("internal_attributes","uint16le",36,2,SX_FLAGS),
 SX_FIELD("external_attributes","uint32le",38,4,SX_FLAGS),
 SX_FIELD("local_header_offset","uint32le",42,4,SX_OFFSET),
};
const sx_layout sxiw_installer_zip_central={UINT32_C(0x60790056),"installer_zip_central",sxiw_installer_zip_central_fields,SX_COUNT(sxiw_installer_zip_central_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_eocd_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("disk_number","uint16le",4,2,SX_NONE),
 SX_FIELD("directory_disk","uint16le",6,2,SX_NONE),
 SX_FIELD("disk_entries","uint16le",8,2,SX_COUNT_PROP),
 SX_FIELD("total_entries","uint16le",10,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("comment_length","uint16le",20,2,SX_SIZE),
};
const sx_layout sxiw_installer_zip_eocd={UINT32_C(0x60790057),"installer_zip_eocd",sxiw_installer_zip_eocd_fields,SX_COUNT(sxiw_installer_zip_eocd_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_extra_fields[]={
 SX_FIELD("tag","uint16le",0,2,SX_ID),
 SX_FIELD("data_size","uint16le",2,2,SX_SIZE),
};
const sx_layout sxiw_installer_zip_extra={UINT32_C(0x60790058),"installer_zip_extra",sxiw_installer_zip_extra_fields,SX_COUNT(sxiw_installer_zip_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_name_fields[]={
 SX_FIELD("installer_zip_name","uint8",0,0,SX_NONE),
};
const sx_layout sxiw_installer_zip_name={UINT32_C(0x60790059),"installer_zip_name",sxiw_installer_zip_name_fields,SX_COUNT(sxiw_installer_zip_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_comment_fields[]={
 SX_FIELD("installer_zip_comment","uint8",0,0,SX_NONE),
};
const sx_layout sxiw_installer_zip_comment={UINT32_C(0x6079005a),"installer_zip_comment",sxiw_installer_zip_comment_fields,SX_COUNT(sxiw_installer_zip_comment_fields),SX_LE};
#define SXIW_LIMIT 20000U
static bool sxiw_zip_extras(sx_context*c,uint64_t p,uint64_t end){for(unsigned i=0;p<end&&i<SXIW_LIMIT;i++){uint64_t z;if(end-p<4||!sxiw_word(c,p+2,2,false,&z)||z>end-p-4)return true;if(!sxiw_add(c,&sxiw_installer_zip_extra,p))return false;p+=4+z;}return true;}
static bool sxiw_dahua(sx_context*c){uint64_t end=(uint64_t)c->size,eo=0,n,dir,ds;uint8_t b[4];if(end<22)return false;uint64_t begin=end>65557?end-65557:0;for(uint64_t p=end-22;;p--){uint64_t z;if(sxiw_read(c,p,b,4)&&!xx_rt_memcmp(b,"PK\5\6",4)&&sxiw_word(c,p+20,2,false,&z)&&z<=end-p-22){eo=p;break;}if(p==begin)break;}if(!eo)return sxiw_add(c,&sxiw_installer_zip_local,0);if(!sxiw_add(c,&sxiw_installer_zip_eocd,eo)||!sxiw_word(c,eo+10,2,false,&n)||!sxiw_word(c,eo+12,4,false,&ds)||!sxiw_word(c,eo+16,4,false,&dir))return false;
 uint64_t comment;if(sxiw_word(c,eo+20,2,false,&comment)&&!sxiw_text(c,&sxiw_installer_zip_comment,eo+22,comment,false))return false;
 if(!sxiw_span(c,dir,ds)||dir+ds>eo||n>ds/46)return true;uint64_t p=dir;for(uint64_t i=0;i<n&&c->count<SXIW_LIMIT;i++){uint8_t h[46];if(dir+ds-p<46||!sxiw_read(c,p,h,46)||xx_rt_memcmp(h,"PK\1\2",4))break;uint64_t a=sxiw_uint(h+28,2,false),b=sxiw_uint(h+30,2,false),z=sxiw_uint(h+32,2,false),lo=sxiw_uint(h+42,4,false);if(a+b+z>dir+ds-p-46)break;if(!sxiw_add(c,&sxiw_installer_zip_central,p)||!sxiw_text(c,&sxiw_installer_zip_name,p+46,a,false)||!sxiw_zip_extras(c,p+46+a,p+46+a+b)||!sxiw_text(c,&sxiw_installer_zip_comment,p+46+a+b,z,false))return false;
 uint8_t l[30];if(sxiw_read(c,lo,l,30)&&((!lo&&!xx_rt_memcmp(l,"DH\3\4",4))||!xx_rt_memcmp(l,"PK\3\4",4))){uint64_t ln=sxiw_uint(l+26,2,false),ex=sxiw_uint(l+28,2,false);if(sxiw_span(c,lo,30+ln+ex)){if(!sxiw_add(c,&sxiw_installer_zip_local,lo)||!sxiw_text(c,&sxiw_installer_zip_name,lo+30,ln,false)||!sxiw_zip_extras(c,lo+30+ln,lo+30+ln+ex))return false;}}
 p+=46+a+b+z;}return true;}
bool sx_dahuazip_build(sx_context*c)
{
 return sxiw_dahua(c);
}
