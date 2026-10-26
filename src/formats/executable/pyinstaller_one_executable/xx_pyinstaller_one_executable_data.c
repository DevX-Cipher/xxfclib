/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PyInstaller CArchive data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_pyinstaller_cookie24_fields[] = {
 SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("package_size","uint32",8,4,SX_SIZE),
 SX_FIELD("toc_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("toc_size","uint32",16,4,SX_SIZE),
 SX_FIELD("python_version","int32",20,4,SX_NONE),
};
const sx_layout sxbx_pyinstaller_cookie24 = {UINT32_C(0x603000b3),"pyinstaller_cookie24",sxbx_pyinstaller_cookie24_fields,SX_COUNT(sxbx_pyinstaller_cookie24_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_pyinstaller_library_fields[] = {
 SX_FIELD("python_library","char[64]",0,64,SX_NONE),
};
const sx_layout sxbx_pyinstaller_library = {UINT32_C(0x603000b4),"pyinstaller_library",sxbx_pyinstaller_library_fields,SX_COUNT(sxbx_pyinstaller_library_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyinstaller_toc_fields[] = {
 SX_FIELD("entry_size","int32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("compressed","uint8",16,1,SX_NONE),
 SX_FIELD("type","char",17,1,SX_ID),
};
const sx_layout sxbx_pyinstaller_toc = {UINT32_C(0x603000b5),"pyinstaller_toc",sxbx_pyinstaller_toc_fields,SX_COUNT(sxbx_pyinstaller_toc_fields),SX_BE};
#define SXBX_LIMIT 20000U
static bool sxbx_pyi_candidate(sx_context*c,uint64_t p,uint64_t limit,uint64_t*outtable,uint64_t*outsize,uint64_t*outcookie){uint8_t b[88];if(limit<p||limit-p<24||!sxbx_read(c,p,b,24)||xx_rt_memcmp(b,"MEI\x0c\x0b\x0a\x0b\x0e",8))return false;uint64_t pkg=sxbx32(b+8,true),off=sxbx32(b+12,true),size=sxbx32(b+16,true);if(off+size>pkg)return false;uint64_t cookie=pkg-off-size;if((cookie!=24&&cookie!=88)||cookie>limit-p||pkg>p+cookie||size<19||size>16777216||!sxbx_read(c,p,b,(size_t)cookie))return false;uint64_t table=p+cookie-pkg+off,q=table,end=table+size;if(end!=p)return false;unsigned count=0;while(q<end){if(++count>SXBX_LIMIT||end-q<19||!sxbx_read(c,q,b,18))return false;uint64_t z=sxbx32(b,true),data=sxbx32(b+4,true),packed=sxbx32(b+8,true);if(z<19||z>end-q||data>off||packed>off-data||b[16]>1)return false;q+=z;}*outtable=table;*outsize=size;*outcookie=cookie;return true;}
static bool sxbx_pyi(sx_context*c){uint64_t limits[2]={(uint64_t)c->size,0},pe;uint8_t b[8];if(sxbx_read(c,0,b,2)&&b[0]=='M'&&b[1]=='Z'&&sxbx_word(c,60,4,false,&pe)&&sxbx_read(c,pe,b,4)&&!xx_rt_memcmp(b,"PE\0\0",4)){uint64_t magic,off;if(sxbx_word(c,pe+24,2,false,&magic)&&(magic==267||magic==523)&&sxbx_word(c,pe+24+(magic==267?128:144),4,false,&off)&&off<limits[0])limits[1]=off;}for(unsigned window=0;window<2;window++){uint64_t limit=limits[window],low=limit>(window?512:4096)?limit-(window?512:4096):0;if(limit<24)continue;for(uint64_t p=limit-24;;p--){uint64_t table,size,cookie;if(sxbx_pyi_candidate(c,p,limit,&table,&size,&cookie)){if(!sxbx_add(c,&sxbx_pyinstaller_cookie24,p)||(cookie==88&&!sxbx_add(c,&sxbx_pyinstaller_library,p+24)))return false;uint64_t q=table;while(q<table+size&&c->count<SXBX_LIMIT){uint64_t z;if(!sxbx_word(c,q,4,true,&z)||!sxbx_add(c,&sxbx_pyinstaller_toc,q))return false;q+=z;}return true;}if(p==low)break;}}return false;}
bool sx_pyinstaller_one_executable_build(sx_context*c)
{
 return sxbx_pyi(c);
}
