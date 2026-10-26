/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XVA data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_xva_tar_v7_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_NONE),
    SX_FIELD("mode","ascii_cpio_octal[8]",100,8,SX_FLAGS),
    SX_FIELD("uid","ascii_cpio_octal[8]",108,8,SX_ID),
    SX_FIELD("gid","ascii_cpio_octal[8]",116,8,SX_ID),
    SX_FIELD("data_size","ascii_cpio_octal[12]",124,12,SX_SIZE),
    SX_FIELD("modification_time","ascii_cpio_octal[12]",136,12,SX_TIME),
    SX_FIELD("checksum","ascii_cpio_octal[8]",148,8,SX_CHECKSUM),
    SX_FIELD("type_flag","char[1]",156,1,SX_ID),
    SX_FIELD("link_name","char[100]",157,100,SX_NONE),
    SX_FIELD("padding","byte[255]",257,255,SX_RESERVED),
};
const sx_layout sxdt_xva_tar_v7 = {0x607a003eU,"xva_tar_v7",sxdt_xva_tar_v7_fields,SX_COUNT(sxdt_xva_tar_v7_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_xva_tar_ustar_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_NONE),
    SX_FIELD("mode","ascii_cpio_octal[8]",100,8,SX_FLAGS),
    SX_FIELD("uid","ascii_cpio_octal[8]",108,8,SX_ID),
    SX_FIELD("gid","ascii_cpio_octal[8]",116,8,SX_ID),
    SX_FIELD("data_size","ascii_cpio_octal[12]",124,12,SX_SIZE),
    SX_FIELD("modification_time","ascii_cpio_octal[12]",136,12,SX_TIME),
    SX_FIELD("checksum","ascii_cpio_octal[8]",148,8,SX_CHECKSUM),
    SX_FIELD("type_flag","char[1]",156,1,SX_ID),
    SX_FIELD("link_name","char[100]",157,100,SX_NONE),
    SX_FIELD("magic","char[6]",257,6,SX_SIGNATURE),
    SX_FIELD("version","char[2]",263,2,SX_ID),
    SX_FIELD("user_name","char[32]",265,32,SX_NONE),
    SX_FIELD("group_name","char[32]",297,32,SX_NONE),
    SX_FIELD("device_major","ascii_cpio_octal[8]",329,8,SX_ID),
    SX_FIELD("device_minor","ascii_cpio_octal[8]",337,8,SX_ID),
    SX_FIELD("prefix","char[155]",345,155,SX_NONE),
    SX_FIELD("padding","byte[12]",500,12,SX_RESERVED),
};
const sx_layout sxdt_xva_tar_ustar = {0x607a003fU,"xva_tar_ustar",sxdt_xva_tar_ustar_fields,SX_COUNT(sxdt_xva_tar_ustar_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_xva_sha1_text_fields[] = {
    SX_FIELD("sha1","char[40]",0,40,SX_CHECKSUM),
};
const sx_layout sxdt_xva_sha1_text = {0x607a0040U,"xva_sha1_text",sxdt_xva_sha1_text_fields,SX_COUNT(sxdt_xva_sha1_text_fields),SX_LE};
static const xx_data_struct_field_desc sxdt_xva_xxhash_text_fields[] = {
    SX_FIELD("xxh64","char[16]",0,16,SX_CHECKSUM),
};
const sx_layout sxdt_xva_xxhash_text = {0x607a0041U,"xva_xxhash_text",sxdt_xva_xxhash_text_fields,SX_COUNT(sxdt_xva_xxhash_text_fields),SX_LE};
#define SXDT_LIMIT 24000U
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
static bool sxdt_tar_octal(const uint8_t*b,unsigned n,uint64_t*out){uint64_t v=0;bool digits=false,tail=false;for(unsigned i=0;i<n;i++){unsigned x=b[i];if(x==0||x==32){if(digits)tail=true;continue;}if(tail||x<'0'||x>'7'||v>(UINT64_MAX-(x-'0'))/8)return false;v=v*8+x-'0';digits=true;}*out=v;return true;}
static bool sxdt_xva(sx_context*c){uint64_t p=0;uint8_t h[512];for(unsigned visited=0;visited<1000000&&sxdt_span(c,p,512)&&c->count<SXDT_LIMIT;visited++){if(!sxdt_read(c,p,h,512))return false;bool zero=true;for(unsigned i=0;i<512;i++)if(h[i])zero=false;if(zero)break;uint64_t size;if(!sxdt_tar_octal(h+124,12,&size)||!sxdt_span(c,p+512,size))break;bool ustar=!xx_rt_memcmp(h+257,"ustar",5);if(!sxdt_put(c,ustar?&sxdt_xva_tar_ustar:&sxdt_xva_tar_v7,p,1))return false;size_t namelen=0;while(namelen<100&&h[namelen])namelen++;if(sxdt_eq(h,namelen,"ova.xml")){if(!sxdt_xml(c,p+512,size,false))return false;}else if((namelen>=9&&!xx_rt_memcmp(h+namelen-9,".checksum",9))||(namelen>=7&&!xx_rt_memcmp(h+namelen-7,".xxhash",7))){if(size==40&&!SXDT_ADD(c,xva_sha1_text,p+512))return false;if(size==16&&!SXDT_ADD(c,xva_xxhash_text,p+512))return false;}uint64_t padded=(size+511)&~UINT64_C(511);if(size>UINT64_MAX-511||padded>(uint64_t)c->size-p-512)break;p+=512+padded;}return c->count!=0;}
bool sx_xva_build(sx_context*c)
{
bool ok=false;
ok=sxdt_xva(c);
return ok&&c->count&&sxdt_finish(c);
}
