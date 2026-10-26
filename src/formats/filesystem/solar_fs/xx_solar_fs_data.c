/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SOLAR_FS data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_solar_volume_identity_fields[] = {
    SX_FIELD("boot_prefix","byte[11]",0,11,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("unknown13","byte[5]",13,5,SX_NONE),
    SX_FIELD("total_sectors","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("unknown20","byte[17]",20,17,SX_NONE),
    SX_FIELD("extended_signature","uint8",37,1,SX_SIGNATURE),
    SX_FIELD("unknown38","byte[4]",38,4,SX_NONE),
    SX_FIELD("volume_label","char[11]",42,11,SX_NONE),
    SX_FIELD("filesystem_signature","char[8]",53,8,SX_SIGNATURE),
};
const sx_layout sxdt_solar_volume_identity = {0x607a0066U,"solar_volume_identity",sxdt_solar_volume_identity_fields,SX_COUNT(sxdt_solar_volume_identity_fields),SX_LE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
static bool sxdt_solar(sx_context*c){uint8_t b[61];return sxdt_read(c,0,b,61)&&b[37]==41&&!xx_rt_memcmp(b+53,"SOL_FS  ",8)&&SXDT_ADD(c,solar_volume_identity,0);}
bool sx_solar_fs_build(sx_context*c)
{
bool ok=false;
ok=sxdt_solar(c);
return ok&&c->count&&sxdt_finish(c);
}
