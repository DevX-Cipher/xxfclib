/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APPLE_RDOS data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_rdos_catalog_entry_fields[] = {
    SX_FIELD("filename","byte[24]",0,24,SX_NONE),
    SX_FIELD("file_type","uint8",24,1,SX_ID),
    SX_FIELD("sectors_used","uint8",25,1,SX_COUNT_PROP),
    SX_FIELD("load_address","uint16",26,2,SX_ADDRESS),
    SX_FIELD("file_size","uint16",28,2,SX_SIZE),
    SX_FIELD("first_logical_sector","uint16",30,2,SX_NONE),
};
const sx_layout sxdt_rdos_catalog_entry = {0x607a0001U,"rdos_catalog_entry",sxdt_rdos_catalog_entry_fields,SX_COUNT(sxdt_rdos_catalog_entry_fields),SX_LE};
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)
static bool sxdt_rdos(sx_context*c){uint64_t sectors=c->size==116480?13:16;if(c->size!=116480&&c->size!=143360)return false;/* All supported native profiles share these88 physical slots. Explicit profiles may override a canonical label, so the RDOS33-only final40 slots remain raw. */return SXDT_TABLE(c,rdos_catalog_entry,sectors*256,88);}
bool sx_apple_rdos_build(sx_context*c)
{
bool ok=false;
ok=sxdt_rdos(c);
return ok&&c->count&&sxdt_finish(c);
}
