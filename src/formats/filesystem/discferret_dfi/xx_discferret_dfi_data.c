/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * discferret dfi data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_discferret_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxdleg_discferret_header = {0x6075001cU,"discferret_header",sxdleg_discferret_header_fields,SX_COUNT(sxdleg_discferret_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdleg_discferret_capture_fields[] = {
    SX_FIELD("cylinder","uint16",0,2,SX_NONE),
    SX_FIELD("head","uint16",2,2,SX_NONE),
    SX_FIELD("sector","uint16",4,2,SX_NONE),
    SX_FIELD("stored_size","uint32",6,4,SX_SIZE),
};
const sx_layout sxdleg_discferret_capture = {0x6075001dU,"discferret_capture",sxdleg_discferret_capture_fields,SX_COUNT(sxdleg_discferret_capture_fields),SX_BE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_dfi(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,4)||(xx_rt_memcmp(h,"DFER",4)&&xx_rt_memcmp(h,"DFE2",4))||!SXDLEG_ADD(c,discferret_header,0))return false;uint64_t p=4;for(unsigned i=0;i<1024&&p<(uint64_t)c->size;i++){if(!sxdleg_read(c,p,h,10))break;uint64_t n=sxdleg32(h+6,1);if(!sxdleg_span(c,p+10,n))break;if(!SXDLEG_ADD(c,discferret_capture,p))return false;p+=10+n;}return true;}
#undef SXDLEG_ADD
bool sx_discferret_dfi_build(sx_context*c)
{
 return sxdleg_dfi(c);
}
