/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Uif data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_uif_trailer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("trailer_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","uint16",8,2,SX_ID),
    SX_FIELD("image_type","uint16",10,2,SX_ID),
    SX_FIELD("unknown","uint16",12,2,SX_NONE),
    SX_FIELD("padding","uint16",14,2,SX_RESERVED),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint32",20,4,SX_SIZE),
    SX_FIELD("last_sector_bytes","uint32",24,4,SX_SIZE),
    SX_FIELD("block_table_offset","uint64",28,8,SX_OFFSET),
    SX_FIELD("block_table_size","uint32",36,4,SX_SIZE),
    SX_FIELD("hash","byte[16]",40,16,SX_NONE),
    SX_FIELD("fixed_key_index","uint8",56,1,SX_ID),
    SX_FIELD("cipher","uint8",57,1,SX_ID),
    SX_FIELD("cipher_parameters0","byte[2]",58,2,SX_NONE),
    SX_FIELD("cipher_parameters1","uint32",60,4,SX_NONE),
};
const sx_layout sxvi_uif_trailer = {0x60530019U,"uif_trailer",sxvi_uif_trailer_fields,SX_COUNT(sxvi_uif_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_uif_table_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint32",8,4,SX_FLAGS),
    SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxvi_uif_table_header = {0x6053001aU,"uif_table_header",sxvi_uif_table_header_fields,SX_COUNT(sxvi_uif_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_uif_block_entry_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("first_sector","uint32",12,4,SX_NONE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint32",20,4,SX_ID),
};
const sx_layout sxvi_uif_block_entry = {0x6053001bU,"uif_block_entry",sxvi_uif_block_entry_fields,SX_COUNT(sxvi_uif_block_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_uif_descriptor_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint32",8,4,SX_FLAGS),
    SX_FIELD("original_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxvi_uif_descriptor_header = {0x6053001cU,"uif_descriptor_header",sxvi_uif_descriptor_header_fields,SX_COUNT(sxvi_uif_descriptor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_uif_output_format_fields[] = {
    SX_FIELD("output_format","uint32",0,4,SX_ID),
};
const sx_layout sxvi_uif_output_format = {0x6053001dU,"uif_output_format",sxvi_uif_output_format_fields,SX_COUNT(sxvi_uif_output_format_fields),SX_LE};
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static bool sxvi_uif(sx_context*c){uint8_t t[64],h[20];if(c->size<80)return false;uint64_t end=(uint64_t)c->size-64;if(!sxvi_read(c,end,t,64)||xx_rt_memcmp(t,"bbis",4)||!SXVI_ADD(c,uif_trailer,end))return false;uint64_t p=sxvi64(t+28,0);if(p>end||end-p<16||!sxvi_read(c,p,h,16))return true;if(xx_rt_memcmp(h,"blhr",4)&&xx_rt_memcmp(h,"bsdr",4))return true;if(!SXVI_ADD(c,uif_table_header,p))return false;
 bool encrypted=!xx_rt_memcmp(h,"bsdr",4)||t[57]==2||(sxvi16(t+8,0)>1&&t[56]&&t[56]<=16);if(encrypted)return true;uint64_t count=sxvi32(h+12,0),stored;if(sxvi32(h+8,0)){if(sxvi32(h+4,0)<8)return true;stored=sxvi32(h+4,0)-8;}else{stored=count*24;if(count<=1048576&&stored<=end-p-16&&!SXVI_TABLE(c,uif_block_entry,p+16,count))return false;}if(stored>end-p-16||sxvi16(t+10,0)!=9)return true;p+=16+stored;
 if(p>end||end-p<16||!sxvi_read(c,p,h,16)||xx_rt_memcmp(h,"blms",4))return true;if(!SXVI_ADD(c,uif_descriptor_header,p))return false;if(sxvi32(h+8,0)){if(sxvi32(h+4,0)<8)return true;stored=sxvi32(h+4,0)-8;}else stored=sxvi32(h+12,0);if(stored>end-p-16)return true;p+=16+stored;
 if(p>end||end-p<20||!sxvi_read(c,p,h,20)||xx_rt_memcmp(h,"blss",4))return true;return SXVI_ADD(c,uif_descriptor_header,p)&&SXVI_ADD(c,uif_output_format,p+16);
}
bool sx_uif_build(sx_context*c)
{
 return sxvi_uif(c);
}
#undef SXVI_ADD
#undef SXVI_TABLE
