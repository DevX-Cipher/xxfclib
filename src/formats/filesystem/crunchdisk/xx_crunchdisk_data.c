/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CRUNCHDISK data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_crunchdisk_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint32",4,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("first_cylinder","uint32",16,4,SX_NONE),
    SX_FIELD("last_cylinder","uint32",20,4,SX_NONE),
    SX_FIELD("encrypted","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",25,1,SX_RESERVED),
    SX_FIELD("unknown_1a","byte[2]",26,2,SX_NONE),
    SX_FIELD("efficiency","uint16",28,2,SX_ID),
    SX_FIELD("compression","uint16",30,2,SX_ID),
};
const sx_layout sxst_crunchdisk_header = {0x6037001eU,"crunchdisk_header",sxst_crunchdisk_header_fields,SX_COUNT(sxst_crunchdisk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxst_crunchdisk_cylinder_fields[] = {
    SX_FIELD("type","char[4]",0,4,SX_ID),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxst_crunchdisk_cylinder = {0x6037001fU,"crunchdisk_cylinder",sxst_crunchdisk_cylinder_fields,SX_COUNT(sxst_crunchdisk_cylinder_fields),SX_BE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_crunchdisk(sx_context*c){uint8_t h[32],b[8];if(!sxst_read(c,0,h,32)||!SXST_ADD(c,crunchdisk_header,0))return false;uint64_t low=sxst_uint(h+16,4,true),high=sxst_uint(h+20,4,true),p=32;if(low>high||high>255||h[24])return true;for(uint64_t i=low;i<=high;i++){if(!sxst_read(c,p,b,8)||(xx_rt_memcmp(b,"CYL0",4)&&xx_rt_memcmp(b,"CYL1",4)))break;uint64_t z=sxst_uint(b+4,4,true);if(!sxst_span(c,p+8,z)||!SXST_ADD(c,crunchdisk_cylinder,p))break;p+=8+z;}return true;}
bool sx_crunchdisk_build(sx_context*c)
{
 return sxst_crunchdisk(c);
}
#undef SXST_ADD
