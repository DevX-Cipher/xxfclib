/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zisofs data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_zisofs_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size_words","uint8",12,1,SX_NONE),
    SX_FIELD("block_size_log2","uint8",13,1,SX_NONE),
    SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
const sx_layout sxvi_zisofs_header = {0x60530022U,"zisofs_header",sxvi_zisofs_header_fields,SX_COUNT(sxvi_zisofs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_zisofs_block_pointer_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxvi_zisofs_block_pointer = {0x60530023U,"zisofs_block_pointer",sxvi_zisofs_block_pointer_fields,SX_COUNT(sxvi_zisofs_block_pointer_fields),SX_LE};
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static bool sxvi_zisofs(sx_context*c){uint8_t b[16];static const uint8_t magic[]={0x37,0xe4,0x53,0x96,0xc9,0xdb,0xd6,0x07};if(!sxvi_read(c,0,b,16)||xx_rt_memcmp(b,magic,8)||b[12]<4||b[13]<9||b[13]>30||!SXVI_ADD(c,zisofs_header,0))return false;uint64_t bs=UINT64_C(1)<<b[13],size=sxvi32(b+8,0),n=(size+bs-1)/bs+1,p=(uint64_t)b[12]*4;if(n>1048576||!sxvi_span(c,p,n*4))return true;return SXVI_TABLE(c,zisofs_block_pointer,p,n);}
bool sx_zisofs_build(sx_context*c)
{
 return sxvi_zisofs(c);
}
#undef SXVI_ADD
#undef SXVI_TABLE
