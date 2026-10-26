/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZTC (Zortech C / Symantec C++ distribution) archives data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_ztc_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[4]",4,4,SX_NONE),
 SX_FIELD("volume_number","uint16",8,2,SX_NONE),
};
const sx_layout sxafr_ztc_header = {UINT32_C(0x6054000a),"ztc_header",sxafr_ztc_header_fields,SX_COUNT(sxafr_ztc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_member_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("stamp","int32",4,4,SX_NONE),
 SX_FIELD("total_size","int32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("name_size","uint16",16,2,SX_SIZE),
};
const sx_layout sxafr_ztc_member = {UINT32_C(0x6054000b),"ztc_member",sxafr_ztc_member_fields,SX_COUNT(sxafr_ztc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_check_fields[] = {
 SX_FIELD("header_check","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxafr_ztc_check = {UINT32_C(0x6054000c),"ztc_check",sxafr_ztc_check_fields,SX_COUNT(sxafr_ztc_check_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_page_sum_fields[] = {
 SX_FIELD("page_sum","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxafr_ztc_page_sum = {UINT32_C(0x6054000d),"ztc_page_sum",sxafr_ztc_page_sum_fields,SX_COUNT(sxafr_ztc_page_sum_fields),SX_LE};
static bool sxafr_ztc(sx_context*c){uint64_t p=10;if(!sxafr_add(c,&sxafr_ztc_header,0))return false;while(p<(uint64_t)c->size){if((uint64_t)c->size-p==2)return true;uint8_t h[18];if(!sxafr_read(c,p,h,18))return false;uint64_t total=sxafr_uint(h+8,4,false),names=sxafr_uint(h+16,2,false);if(total>INT32_MAX||!names||total<22+names||!sxafr_span(c,p+18,names+4)||!sxafr_add(c,&sxafr_ztc_member,p)||!sxafr_add(c,&sxafr_ztc_check,p+18+names))return false;uint64_t q=p+22+names,z=total-22-names;/* Declared geometry locates sums; a truncated page cannot move its checksum earlier. */while(z>=4){uint64_t page=z-4;if(page>4096)page=4096;if(!sxafr_span(c,q,page+4))return true;if(!sxafr_add(c,&sxafr_ztc_page_sum,q+page))return false;q+=page+4;z-=page+4;}if(total>(uint64_t)c->size-p)return true;p+=total;}return true;}
bool sx_ztc_build(sx_context*c)
{
 return sxafr_ztc(c);
}
