/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QNX Neutrino boot images data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_qnx_startup_prefix_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("flags1","uint8",6,1,SX_FLAGS),
    SX_FIELD("flags2","uint8",7,1,SX_FLAGS),
    SX_FIELD("header_size","uint16",8,2,SX_SIZE),
    SX_FIELD("machine","uint16",10,2,SX_ID),
    SX_FIELD("startup_vaddr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("paddr_bias","uint32",16,4,SX_NONE),
    SX_FIELD("image_paddr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("ram_paddr","uint32",24,4,SX_ADDRESS),
    SX_FIELD("ram_size","uint32",28,4,SX_SIZE),
    SX_FIELD("startup_size","uint32",32,4,SX_SIZE),
    SX_FIELD("stored_size","uint32",36,4,SX_SIZE),
    SX_FIELD("imagefs_paddr","uint32",40,4,SX_ADDRESS),
    SX_FIELD("imagefs_size","uint32",44,4,SX_SIZE),
    SX_FIELD("preboot_size","uint16",48,2,SX_OFFSET),
    SX_FIELD("zero0","uint16",50,2,SX_RESERVED),
};
const sx_layout sxbrs_qnx_startup_prefix = {UINT32_C(0x603e001c),"qnx_startup_prefix",sxbrs_qnx_startup_prefix_fields,SX_COUNT(sxbrs_qnx_startup_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_qnx_startup_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("flags1","uint8",6,1,SX_FLAGS),
    SX_FIELD("flags2","uint8",7,1,SX_FLAGS),
    SX_FIELD("header_size","uint16",8,2,SX_SIZE),
    SX_FIELD("machine","uint16",10,2,SX_ID),
    SX_FIELD("startup_vaddr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("paddr_bias","uint32",16,4,SX_NONE),
    SX_FIELD("image_paddr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("ram_paddr","uint32",24,4,SX_ADDRESS),
    SX_FIELD("ram_size","uint32",28,4,SX_SIZE),
    SX_FIELD("startup_size","uint32",32,4,SX_SIZE),
    SX_FIELD("stored_size","uint32",36,4,SX_SIZE),
    SX_FIELD("imagefs_paddr","uint32",40,4,SX_ADDRESS),
    SX_FIELD("imagefs_size","uint32",44,4,SX_SIZE),
    SX_FIELD("preboot_size","uint16",48,2,SX_OFFSET),
    SX_FIELD("zero0","uint16",50,2,SX_RESERVED),
    SX_FIELD("zero","uint32[3]",52,12,SX_RESERVED),
    SX_FIELD("info","uint32[48]",64,192,SX_NONE),
};
const sx_layout sxbrs_qnx_startup_header = {UINT32_C(0x603e001d),"qnx_startup_header",sxbrs_qnx_startup_header_fields,SX_COUNT(sxbrs_qnx_startup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_qnx_block_fields[] = {
    SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxbrs_qnx_block = {UINT32_C(0x603e001e),"qnx_block",sxbrs_qnx_block_fields,SX_COUNT(sxbrs_qnx_block_fields),SX_BE};
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
#define B(p,w) sxbrs_num(c,(p),(w),true)
static bool sxbrs_qnx(sx_context*c){
 if(!sxbrs_eq(c,0,"\xeb\x4c\x44\x44\x44\x44\0\0\0\0\0\1\0\0\0\0",16))return false;int64_t start=-1,end=c->size;
 for(int64_t p=0;p+52<=end&&p<=65536;p+=4){if(N(p,4)==0xff7eeb&&N(p+48,4)==(uint64_t)p&&N(p+32,4)>0&&N(p+32,4)<=INT32_MAX&&N(p+44,4)>0&&N(p+44,4)<=134217728&&N(p+32,4)<=(uint64_t)(end-p-2)){start=p;break;}if(xx_pd_is_stopped(c->pd))return false;}
 if(start<0)return false;uint64_t declared=N(start+8,2),startup=N(start+32,4);const sx_layout*l=declared>=256&&startup>=256&&end-start>=256?&sxbrs_qnx_startup_header:&sxbrs_qnx_startup_prefix;if(!sxbrs_add(c,l,start))return false;
 int64_t at=start+(int64_t)startup;unsigned blocks=0;for(;;){uint64_t n=B(at,2);AL(qnx_block,1);if(!n)return blocks>0;if(++blocks>1048576)return false;SK(n);}
}
bool sx_qnxbase_build(sx_context*c)
{
 return sxbrs_qnx(c);
}
#undef AL
#undef SK
#undef N
#undef B
