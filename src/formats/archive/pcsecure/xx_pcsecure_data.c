/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCSECURE data structures, moved out of the archiveresidual schema family. */
#include "../../xx_format_schema_archiveresidual.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarfinal_pcsecure_physical_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("encrypted_header","uint8[56]",4,56,SX_NONE),
 SX_FIELD("wrapped_file_key","uint8[8]",60,8,SX_NONE),
};
const sx_layout sxarfinal_pcsecure_physical_header={UINT32_C(0x60920001),"pcsecure_physical_header",sxarfinal_pcsecure_physical_header_fields,SX_COUNT(sxarfinal_pcsecure_physical_header_fields),SX_LE};
static bool sxarfinal_pcsecure(sx_context*c){uint8_t h[4];return c->size>68&&sxarfinal_read(c,0,h,4)&&(!xx_rt_memcmp(h,"PCT5",4)||!xx_rt_memcmp(h,"PCT6",4)||!xx_rt_memcmp(h,"PCT7",4)||!xx_rt_memcmp(h,"AfoS",4))&&sxarfinal_put(c,&sxarfinal_pcsecure_physical_header,0);}
bool sx_pcsecure_build(sx_context*c)
{
bool ok=false;
ok=sxarfinal_pcsecure(c);
(void)ok;return c->count&&sxarfinal_finish(c);
}
