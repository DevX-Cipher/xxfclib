/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RID archives (OS2YOU / LANTERM / TERM2 / DRIVERS packages, 1998-99) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_rid_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_NONE),
 SX_FIELD("reserved","uint8[19]",2,19,SX_NONE),
 SX_FIELD("attributes","uint8",21,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",22,2,SX_NONE),
 SX_FIELD("dos_date","uint16",24,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",26,4,SX_SIZE),
 SX_FIELD("name","char[13]",30,13,SX_NONE),
};
const sx_layout sxafr_rid_member = {UINT32_C(0x60540020),"rid_member",sxafr_rid_member_fields,SX_COUNT(sxafr_rid_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_rid_block_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
 SX_FIELD("type","uint8",2,1,SX_NONE),
};
const sx_layout sxafr_rid_block = {UINT32_C(0x60540021),"rid_block",sxafr_rid_block_fields,SX_COUNT(sxafr_rid_block_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_archiveframes_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
const sx_layout sxafr_archiveframes_dcl = {UINT32_C(0x6054002c),"archiveframes_dcl",sxafr_archiveframes_dcl_fields,SX_COUNT(sxafr_archiveframes_dcl_fields),SX_LE};
static bool sxafr_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxafr_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxafr_add(c,&sxafr_archiveframes_dcl,p);}
static bool sxafr_rid(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){if(!sxafr_add(c,&sxafr_rid_member,p))return false;p+=43;for(;;){uint8_t h[3];if(!sxafr_read(c,p,h,3))return false;uint64_t z=sxafr_uint(h,2,false);if((h[2]!=0&&h[2]!=1&&h[2]!=255)||!sxafr_span(c,p+3,z)||!sxafr_add(c,&sxafr_rid_block,p))return false;p+=3;if(h[2]==255){if(z)return false;break;}if(h[2]==1&&!sxafr_dcl(c,p,z))return false;p+=z;}}return true;}
bool sx_rid_build(sx_context*c)
{
 return sxafr_rid(c);
}
