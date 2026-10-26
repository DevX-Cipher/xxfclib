/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Microsoft KWAJ stream data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_kwaj_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("method","uint16",8,2,SX_ID),
    SX_FIELD("data_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("extension_flags","uint16",12,2,SX_FLAGS),
};
const sx_layout sxae_kwaj_header = {UINT32_C(0x6017001e),"kwaj_header",sxae_kwaj_header_fields,SX_COUNT(sxae_kwaj_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_unpacked_size_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxae_kwaj_unpacked_size = {UINT32_C(0x6017001f),"kwaj_unpacked_size",sxae_kwaj_unpacked_size_fields,SX_COUNT(sxae_kwaj_unpacked_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_unknown_fields[] = {
    SX_FIELD("unknown","uint16",0,2,SX_NONE),
};
const sx_layout sxae_kwaj_unknown = {UINT32_C(0x60170020),"kwaj_unknown",sxae_kwaj_unknown_fields,SX_COUNT(sxae_kwaj_unknown_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_extension_size_fields[] = {
    SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxae_kwaj_extension_size = {UINT32_C(0x60170021),"kwaj_extension_size",sxae_kwaj_extension_size_fields,SX_COUNT(sxae_kwaj_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_mszip_block_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_NONE),
    SX_FIELD("signature","char[2]",2,2,SX_SIGNATURE),
};
const sx_layout sxae_kwaj_mszip_block = {UINT32_C(0x60170022),"kwaj_mszip_block",sxae_kwaj_mszip_block_fields,SX_COUNT(sxae_kwaj_mszip_block_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_mszip_end_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxae_kwaj_mszip_end = {UINT32_C(0x60170023),"kwaj_mszip_end",sxae_kwaj_mszip_end_fields,SX_COUNT(sxae_kwaj_mszip_end_fields),SX_LE};
static bool sxae_kwaj(sx_context *c)
{
 uint8_t b[14];if(!sx_read(c,0,b,14)||xx_rt_memcmp(b,"KWAJ\x88\xf0\x27\xd1",8)||!sxae_add(c,&sxae_kwaj_header,0))return false;
 uint16_t method=sxae16(b+8),end=sxae16(b+10),flags=sxae16(b+12);int64_t p=14;if(end<14||!sxae_bound(c,0,end))return false;
 if(flags&1){if(p+4>end||!sxae_add(c,&sxae_kwaj_unpacked_size,p))return false;p+=4;}
 if(flags&2){if(p+2>end)goto payload;if(!sxae_add(c,&sxae_kwaj_unknown,p))return false;p+=2;}
 if(flags&4){uint16_t n;if(p+2>end)goto payload;if(!sx_u16(c,p,false,&n)||!sxae_add(c,&sxae_kwaj_extension_size,p))return false;p+=2;if(n>end-p)goto payload;p+=n;}
 for(unsigned k=0;k<2;k++)if(flags&(8u<<k)){unsigned max=k?3:8,j;for(j=0;j<=max;j++){uint8_t ch;if(p+j>=end)goto payload;if(!sx_read(c,p+j,&ch,1))return false;if(!ch){p+=j+1;break;}}if(j>max)goto payload;}
 /* Native reader does not interpret bit-5 data. Keep those bytes opaque. */
 payload:p=end;if(method==4){for(unsigned k=0;p<c->size&&k<20000;k++){uint16_t n;if(!sx_u16(c,p,false,&n))return false;if(!n)return sxae_add(c,&sxae_kwaj_mszip_end,p);
 uint8_t sig[2];if(n<=2||!sxae_bound(c,p,2u+n)||!sx_read(c,p+2,sig,2)||xx_rt_memcmp(sig,"CK",2)||!sxae_add(c,&sxae_kwaj_mszip_block,p)||!sxae_data(c,p+4,n-2))return false;p+=2+n;}return p==c->size;}return true;
}
bool sx_kwaj_build(sx_context*c)
{
 return sxae_kwaj(c);
}
