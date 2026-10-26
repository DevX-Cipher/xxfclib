/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GRZIP data structures, moved out of the archiveresidual schema family. */
#include "../../xx_format_schema_archiveresidual.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarfinal_grzip_stream_header_fields[]={
 SX_FIELD("signature","uint8[12]",0,12,SX_SIGNATURE),
};
const sx_layout sxarfinal_grzip_stream_header={UINT32_C(0x60920214),"grzip_stream_header",sxarfinal_grzip_stream_header_fields,SX_COUNT(sxarfinal_grzip_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_grzip_block_header_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("compression_mode","int32",4,4,SX_FLAGS),
 SX_FIELD("mode_parameter","int32",8,4,SX_NONE),
 SX_FIELD("transform_parameter","int32",12,4,SX_NONE),
 SX_FIELD("stored_size","int32",16,4,SX_SIZE),
 SX_FIELD("payload_crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("header_crc32","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sxarfinal_grzip_block_header={UINT32_C(0x60920215),"grzip_block_header",sxarfinal_grzip_block_header_fields,SX_COUNT(sxarfinal_grzip_block_header_fields),SX_LE};
#define SXARFINAL_LIMIT 20000U
static bool sxarfinal_grzip(sx_context*c){
 static const uint8_t magic[12]={'G','R','Z','i','p','I','I',0,2,4,':',')'};uint8_t h[28];uint64_t p=12;
 if(!sxarfinal_read(c,0,h,12)||xx_rt_memcmp(h,magic,12)||!sxarfinal_put(c,&sxarfinal_grzip_stream_header,0))return false;
 for(unsigned blocks=0;p<(uint64_t)c->size&&blocks<SXARFINAL_LIMIT;blocks++){
  if(!sxarfinal_read(c,p,h,28))return false;uint64_t z=sxarfinal_num(h+16,4,false);
  if(z>INT32_MAX||!sxarfinal_span(c,p+28,z)||!sxarfinal_put(c,&sxarfinal_grzip_block_header,p))return false;p+=28+z;
 }
 return true;
}
bool sx_grzip_build(sx_context*c)
{
bool ok=false;
ok=sxarfinal_grzip(c);
(void)ok;return c->count&&sxarfinal_finish(c);
}
