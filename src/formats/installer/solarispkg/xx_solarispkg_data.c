/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SVR4 / Solaris package datastream data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_solaris_package_name_fields[]={
 SX_FIELD("solaris_package_name","utf8",0,0,SX_STRING),
};
const sx_layout sxiw_solaris_package_name={UINT32_C(0x6079001c),"solaris_package_name",sxiw_solaris_package_name_fields,SX_COUNT(sxiw_solaris_package_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_part_count_fields[]={
 SX_FIELD("solaris_part_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxiw_solaris_part_count={UINT32_C(0x6079001d),"solaris_part_count",sxiw_solaris_part_count_fields,SX_COUNT(sxiw_solaris_part_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_block_count_fields[]={
 SX_FIELD("solaris_block_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxiw_solaris_block_count={UINT32_C(0x6079001e),"solaris_block_count",sxiw_solaris_block_count_fields,SX_COUNT(sxiw_solaris_block_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_banner_fields[]={
 SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
};
const sx_layout sxiw_solaris_banner={UINT32_C(0x6079001f),"solaris_banner",sxiw_solaris_banner_fields,SX_COUNT(sxiw_solaris_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_end_header_fields[]={
 SX_FIELD("end_marker","char[15]",0,15,SX_SIGNATURE),
};
const sx_layout sxiw_solaris_end_header={UINT32_C(0x60790020),"solaris_end_header",sxiw_solaris_end_header_fields,SX_COUNT(sxiw_solaris_end_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_newc_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("inode","ascii_cpio_hex[8]",6,8,SX_ID),
 SX_FIELD("mode","ascii_cpio_hex[8]",14,8,SX_FLAGS),
 SX_FIELD("uid","ascii_cpio_hex[8]",22,8,SX_NONE),
 SX_FIELD("gid","ascii_cpio_hex[8]",30,8,SX_NONE),
 SX_FIELD("link_count","ascii_cpio_hex[8]",38,8,SX_COUNT_PROP),
 SX_FIELD("modification_time","ascii_cpio_hex[8]",46,8,SX_TIME),
 SX_FIELD("file_size","ascii_cpio_hex[8]",54,8,SX_SIZE),
 SX_FIELD("device_major","ascii_cpio_hex[8]",62,8,SX_NONE),
 SX_FIELD("device_minor","ascii_cpio_hex[8]",70,8,SX_NONE),
 SX_FIELD("rdevice_major","ascii_cpio_hex[8]",78,8,SX_NONE),
 SX_FIELD("rdevice_minor","ascii_cpio_hex[8]",86,8,SX_NONE),
 SX_FIELD("name_size","ascii_cpio_hex[8]",94,8,SX_SIZE),
 SX_FIELD("checksum","ascii_cpio_hex[8]",102,8,SX_CHECKSUM),
};
const sx_layout sxiw_solaris_cpio_newc={UINT32_C(0x6079005b),"solaris_cpio_newc",sxiw_solaris_cpio_newc_fields,SX_COUNT(sxiw_solaris_cpio_newc_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_odc_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("device","ascii_cpio_octal[6]",6,6,SX_NONE),
 SX_FIELD("inode","ascii_cpio_octal[6]",12,6,SX_ID),
 SX_FIELD("mode","ascii_cpio_octal[6]",18,6,SX_FLAGS),
 SX_FIELD("uid","ascii_cpio_octal[6]",24,6,SX_NONE),
 SX_FIELD("gid","ascii_cpio_octal[6]",30,6,SX_NONE),
 SX_FIELD("link_count","ascii_cpio_octal[6]",36,6,SX_COUNT_PROP),
 SX_FIELD("rdevice","ascii_cpio_octal[6]",42,6,SX_NONE),
 SX_FIELD("modification_time","ascii_cpio_octal[11]",48,11,SX_TIME),
 SX_FIELD("name_size","ascii_cpio_octal[6]",59,6,SX_SIZE),
 SX_FIELD("file_size","ascii_cpio_octal[11]",65,11,SX_SIZE),
};
const sx_layout sxiw_solaris_cpio_odc={UINT32_C(0x6079005c),"solaris_cpio_odc",sxiw_solaris_cpio_odc_fields,SX_COUNT(sxiw_solaris_cpio_odc_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_binary_le_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("device","uint16",2,2,SX_NONE),
 SX_FIELD("inode","uint16",4,2,SX_ID),
 SX_FIELD("mode","uint16",6,2,SX_FLAGS),
 SX_FIELD("uid","uint16",8,2,SX_NONE),
 SX_FIELD("gid","uint16",10,2,SX_NONE),
 SX_FIELD("link_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("rdevice","uint16",14,2,SX_NONE),
 SX_FIELD("mtime_high","uint16",16,2,SX_NONE),
 SX_FIELD("mtime_low","uint16",18,2,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
 SX_FIELD("file_size_high","uint16",22,2,SX_NONE),
 SX_FIELD("file_size_low","uint16",24,2,SX_NONE),
};
const sx_layout sxiw_solaris_cpio_binary_le={UINT32_C(0x6079005d),"solaris_cpio_binary_le",sxiw_solaris_cpio_binary_le_fields,SX_COUNT(sxiw_solaris_cpio_binary_le_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_binary_be_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("device","uint16",2,2,SX_NONE),
 SX_FIELD("inode","uint16",4,2,SX_ID),
 SX_FIELD("mode","uint16",6,2,SX_FLAGS),
 SX_FIELD("uid","uint16",8,2,SX_NONE),
 SX_FIELD("gid","uint16",10,2,SX_NONE),
 SX_FIELD("link_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("rdevice","uint16",14,2,SX_NONE),
 SX_FIELD("mtime_high","uint16",16,2,SX_NONE),
 SX_FIELD("mtime_low","uint16",18,2,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
 SX_FIELD("file_size_high","uint16",22,2,SX_NONE),
 SX_FIELD("file_size_low","uint16",24,2,SX_NONE),
};
const sx_layout sxiw_solaris_cpio_binary_be={UINT32_C(0x6079005e),"solaris_cpio_binary_be",sxiw_solaris_cpio_binary_be_fields,SX_COUNT(sxiw_solaris_cpio_binary_be_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_name_fields[]={
 SX_FIELD("solaris_cpio_name","uint8",0,0,SX_NONE),
};
const sx_layout sxiw_solaris_cpio_name={UINT32_C(0x6079005f),"solaris_cpio_name",sxiw_solaris_cpio_name_fields,SX_COUNT(sxiw_solaris_cpio_name_fields),SX_LE};
#define SXIW_LIMIT 20000U
static bool sxiw_ascii(sx_context*c,uint64_t p,unsigned n,unsigned radix,uint64_t*v){uint8_t b[24];if(n>sizeof(b)||!sxiw_read(c,p,b,n))return false;*v=0;bool any=false;unsigned i=0;while(i<n&&(b[i]==' '||!b[i]))i++;for(;i<n;i++){unsigned d;if(b[i]==' '||!b[i]){for(;i<n;i++)if(b[i]&&b[i]!=' ')return false;break;}if(b[i]>='0'&&b[i]<='9')d=b[i]-'0';else if(b[i]>='a'&&b[i]<='f')d=b[i]-'a'+10;else if(b[i]>='A'&&b[i]<='F')d=b[i]-'A'+10;else return false;if(d>=radix||*v>(UINT64_MAX-d)/radix)return false;*v=*v*radix+d;any=true;}(void)any;return true;}
static bool sxiw_cpio(sx_context*c,uint64_t start,uint64_t*next){uint64_t p=start;for(unsigned i=0;i<SXIW_LIMIT&&c->count<SXIW_LIMIT;i++){uint8_t h[6];uint64_t head,name,z,align=1;const sx_layout*l;if(!sxiw_read(c,p,h,6))return false;
 if(!xx_rt_memcmp(h,"070701",6)||!xx_rt_memcmp(h,"070702",6)){head=110;align=4;l=&sxiw_solaris_cpio_newc;if(!sxiw_ascii(c,p+94,8,16,&name)||!sxiw_ascii(c,p+54,8,16,&z))return false;}
 else if(!xx_rt_memcmp(h,"070707",6)){head=76;l=&sxiw_solaris_cpio_odc;if(!sxiw_ascii(c,p+59,6,8,&name)||!sxiw_ascii(c,p+65,11,8,&z))return false;}
 else if(sxiw_uint(h,2,false)==070707||sxiw_uint(h,2,true)==070707){bool be=sxiw_uint(h,2,true)==070707;uint64_t hi,lo;head=26;align=2;l=be?&sxiw_solaris_cpio_binary_be:&sxiw_solaris_cpio_binary_le;if(!sxiw_word(c,p+20,2,be,&name)||!sxiw_word(c,p+22,2,be,&hi)||!sxiw_word(c,p+24,2,be,&lo))return false;z=(hi<<16)|lo;}
 else return false;if(!name||name>4096||!sxiw_span(c,p,head+name))return false;uint64_t data=p+head+name;data+=((align-(data-start)%align)%align);if(!sxiw_span(c,data,z)||!sxiw_add(c,l,p)||!sxiw_text(c,&sxiw_solaris_cpio_name,p+head,name,false))return false;uint8_t tag[11];bool last=name==11&&sxiw_read(c,p+head,tag,11)&&!xx_rt_memcmp(tag,"TRAILER!!!\0",11);p=data+z;p+=((align-(p-start)%align)%align);if(last){*next=p;return true;}}
 return false;}
static bool sxiw_solaris(sx_context*c){if(!sxiw_add(c,&sxiw_solaris_banner,0))return false;uint8_t h[512];if(!sxiw_read(c,0,h,512))return true;uint64_t p=21;while(p<512){uint64_t a=p;while(p<512&&h[p]!='\n'&&h[p])p++;uint64_t e=p;if(p<512)p++;if(e-a>=15&&!xx_rt_memcmp(h+a,"# end of header",15)){if(!sxiw_add(c,&sxiw_solaris_end_header,a))return false;break;}uint64_t b=a;while(b<e&&h[b]!=' '&&h[b]!='\t')b++;if(b>a&&!sxiw_text(c,&sxiw_solaris_package_name,a,b-a,false))return false;for(unsigned k=0;k<2;k++){while(b<e&&(h[b]==' '||h[b]=='\t'))b++;a=b;while(b<e&&h[b]>='0'&&h[b]<='9')b++;if(a==b)break;if(!sxiw_text(c,k?&sxiw_solaris_block_count:&sxiw_solaris_part_count,a,b-a,false))return false;}if(e>=512||!h[e])break;}
 p=512;for(unsigned i=0;p<(uint64_t)c->size&&i<1024&&c->count<SXIW_LIMIT;i++){uint64_t next;if(!sxiw_cpio(c,p,&next))break;p=next+((512-(next%512))%512);}return true;}
bool sx_solarispkg_build(sx_context*c)
{
 return sxiw_solaris(c);
}
