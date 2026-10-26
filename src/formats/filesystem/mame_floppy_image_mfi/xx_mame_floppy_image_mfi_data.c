/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MAME_FLOPPY_IMAGE_MFI data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_mfi_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("cylinders_and_resolution","uint32",16,4,SX_FLAGS),
    SX_FIELD("head_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("form_factor","uint32",24,4,SX_ID),
    SX_FIELD("variant","uint32",28,4,SX_ID),
};
const sx_layout sxsl_mfi_header = {0x60330019U,"mfi_header",sxsl_mfi_header_fields,SX_COUNT(sxsl_mfi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_mfi_track_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("write_splice","uint32",12,4,SX_NONE),
};
const sx_layout sxsl_mfi_track = {0x6033001aU,"mfi_track",sxsl_mfi_track_fields,SX_COUNT(sxsl_mfi_track_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_mfi(sx_context*c){uint8_t b[32];if(!sxsl_read(c,0,b,32)||!SXSL_ADD(c,mfi_header,0))return false;uint64_t n=(sxsl32(b+16)&0x3fffffffU),heads=sxsl32(b+20);unsigned shift=sxsl32(b+16)>>30;if(shift>2||heads>2||n>256)return true;n*=heads*(1U<<shift);return !sxsl_span(c,32,n*16)||SXSL_TABLE(c,mfi_track,32,n);}
bool sx_mame_floppy_image_mfi_build(sx_context*c)
{
bool ok=false;
ok=sxsl_mfi(c);
return ok&&sxsl_finish(c);
}
