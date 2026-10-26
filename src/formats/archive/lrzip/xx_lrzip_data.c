/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LRZIP data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_lrzip_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("unpacked_size","uint64",6,8,SX_SIZE),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
 SX_FIELD("lzma_properties","uint8",16,1,SX_NONE),
 SX_FIELD("lzma_dictionary_size","uint32",17,4,SX_SIZE),
 SX_FIELD("md5_present","uint8",21,1,SX_FLAGS),
 SX_FIELD("encrypted","uint8",22,1,SX_FLAGS),
 SX_FIELD("reserved23","uint8",23,1,SX_RESERVED),
};
const sx_layout sxal_lrzip_header = {UINT32_C(0x60200034),"lrzip_header",sxal_lrzip_header_fields,SX_COUNT(sxal_lrzip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk1_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint8",2,1,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk1 = {UINT32_C(0x60200035),"lrzip_chunk1",sxal_lrzip_chunk1_fields,SX_COUNT(sxal_lrzip_chunk1_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block1_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint8",1,1,SX_SIZE),
 SX_FIELD("unpacked_size","uint8",2,1,SX_SIZE),
 SX_FIELD("next_block_offset","uint8",3,1,SX_OFFSET),
};
const sx_layout sxal_lrzip_block1 = {UINT32_C(0x60200036),"lrzip_block1",sxal_lrzip_block1_fields,SX_COUNT(sxal_lrzip_block1_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk2_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk2 = {UINT32_C(0x60200037),"lrzip_chunk2",sxal_lrzip_chunk2_fields,SX_COUNT(sxal_lrzip_chunk2_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block2_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint16",1,2,SX_SIZE),
 SX_FIELD("unpacked_size","uint16",3,2,SX_SIZE),
 SX_FIELD("next_block_offset","uint16",5,2,SX_OFFSET),
};
const sx_layout sxal_lrzip_block2 = {UINT32_C(0x60200038),"lrzip_block2",sxal_lrzip_block2_fields,SX_COUNT(sxal_lrzip_block2_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk3_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint24",2,3,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk3 = {UINT32_C(0x60200039),"lrzip_chunk3",sxal_lrzip_chunk3_fields,SX_COUNT(sxal_lrzip_chunk3_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block3_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint24",1,3,SX_SIZE),
 SX_FIELD("unpacked_size","uint24",4,3,SX_SIZE),
 SX_FIELD("next_block_offset","uint24",7,3,SX_OFFSET),
};
const sx_layout sxal_lrzip_block3 = {UINT32_C(0x6020003a),"lrzip_block3",sxal_lrzip_block3_fields,SX_COUNT(sxal_lrzip_block3_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk4_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk4 = {UINT32_C(0x6020003b),"lrzip_chunk4",sxal_lrzip_chunk4_fields,SX_COUNT(sxal_lrzip_chunk4_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block4_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint32",1,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",9,4,SX_OFFSET),
};
const sx_layout sxal_lrzip_block4 = {UINT32_C(0x6020003c),"lrzip_block4",sxal_lrzip_block4_fields,SX_COUNT(sxal_lrzip_block4_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk5_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint40",2,5,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk5 = {UINT32_C(0x6020003d),"lrzip_chunk5",sxal_lrzip_chunk5_fields,SX_COUNT(sxal_lrzip_chunk5_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block5_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint40",1,5,SX_SIZE),
 SX_FIELD("unpacked_size","uint40",6,5,SX_SIZE),
 SX_FIELD("next_block_offset","uint40",11,5,SX_OFFSET),
};
const sx_layout sxal_lrzip_block5 = {UINT32_C(0x6020003e),"lrzip_block5",sxal_lrzip_block5_fields,SX_COUNT(sxal_lrzip_block5_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk6_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint48",2,6,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk6 = {UINT32_C(0x6020003f),"lrzip_chunk6",sxal_lrzip_chunk6_fields,SX_COUNT(sxal_lrzip_chunk6_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block6_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint48",1,6,SX_SIZE),
 SX_FIELD("unpacked_size","uint48",7,6,SX_SIZE),
 SX_FIELD("next_block_offset","uint48",13,6,SX_OFFSET),
};
const sx_layout sxal_lrzip_block6 = {UINT32_C(0x60200040),"lrzip_block6",sxal_lrzip_block6_fields,SX_COUNT(sxal_lrzip_block6_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk7_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint56",2,7,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk7 = {UINT32_C(0x60200041),"lrzip_chunk7",sxal_lrzip_chunk7_fields,SX_COUNT(sxal_lrzip_chunk7_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block7_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint56",1,7,SX_SIZE),
 SX_FIELD("unpacked_size","uint56",8,7,SX_SIZE),
 SX_FIELD("next_block_offset","uint56",15,7,SX_OFFSET),
};
const sx_layout sxal_lrzip_block7 = {UINT32_C(0x60200042),"lrzip_block7",sxal_lrzip_block7_fields,SX_COUNT(sxal_lrzip_block7_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk8_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint64",2,8,SX_SIZE),
};
const sx_layout sxal_lrzip_chunk8 = {UINT32_C(0x60200043),"lrzip_chunk8",sxal_lrzip_chunk8_fields,SX_COUNT(sxal_lrzip_chunk8_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block8_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint64",1,8,SX_SIZE),
 SX_FIELD("unpacked_size","uint64",9,8,SX_SIZE),
 SX_FIELD("next_block_offset","uint64",17,8,SX_OFFSET),
};
const sx_layout sxal_lrzip_block8 = {UINT32_C(0x60200044),"lrzip_block8",sxal_lrzip_block8_fields,SX_COUNT(sxal_lrzip_block8_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_md5_fields[] = {
 SX_FIELD("digest","uint8[16]",0,16,SX_CHECKSUM),
};
const sx_layout sxal_lrzip_md5 = {UINT32_C(0x60200045),"lrzip_md5",sxal_lrzip_md5_fields,SX_COUNT(sxal_lrzip_md5_fields),SX_LE};
static const sx_layout *const sxal_lr_chunks[]={&sxal_lrzip_chunk1,&sxal_lrzip_chunk2,&sxal_lrzip_chunk3,&sxal_lrzip_chunk4,&sxal_lrzip_chunk5,&sxal_lrzip_chunk6,&sxal_lrzip_chunk7,&sxal_lrzip_chunk8};
static const sx_layout *const sxal_lr_blocks[]={&sxal_lrzip_block1,&sxal_lrzip_block2,&sxal_lrzip_block3,&sxal_lrzip_block4,&sxal_lrzip_block5,&sxal_lrzip_block6,&sxal_lrzip_block7,&sxal_lrzip_block8};
static bool sxal_lrzip(sx_context *c){uint8_t b[25];if(!sxal_read(c,0,b,24)||!sxal_add(c,&sxal_lrzip_header,0))return false;bool md5=b[21]!=0;uint64_t end=(uint64_t)c->size,p=24;if(md5){if(end<40)return true;end-=16;if(!sxal_add(c,&sxal_lrzip_md5,end))return false;}
 for(unsigned i=0;i<SXAL_LIMIT&&p<end;i++){if(!sxal_read(c,p,b,2))break;unsigned width=b[0];bool final=b[1]!=0;if(width<1||width>8||b[1]>1||2U+width>end-p)break;if(!sxal_add(c,sxal_lr_chunks[width-1],p))return false;uint64_t base=p+2+width,head=1+3*width,readend=base+2*head;if(readend>end)break;size_t save=c->count;bool valid=true;
  for(unsigned stream=0;stream<2&&valid;stream++){uint64_t at=base+stream*head;if(!sxal_read(c,at,b,(size_t)head)||!sxal_add(c,sxal_lr_blocks[width-1],at))return false;uint64_t next=sxal_uint(b+1+2*width,width,false);unsigned steps=0;
   while(next&&steps++<SXAL_LIMIT){if(next<2*head||next>end-base||head>end-base-next||!sxal_read(c,base+next,b,(size_t)head)){valid=false;break;}uint64_t packed=sxal_uint(b+1,width,false),link=sxal_uint(b+1+2*width,width,false);if(!packed||packed>end-base-next-head||(link&&link<=next)){valid=false;break;}if(!sxal_add(c,sxal_lr_blocks[width-1],base+next))return false;uint64_t stop=base+next+head+packed;if(stop>readend)readend=stop;next=link;}if(next)valid=false;
  }if(!valid){c->count=save;break;}p=readend;if(final)break;
 }return true;}
bool sx_lrzip_build(sx_context*c)
{
 return sxal_lrzip(c);
}
