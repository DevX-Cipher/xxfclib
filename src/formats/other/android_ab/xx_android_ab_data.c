/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * android_ab data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_backup_version_fields[]={
 SX_FIELD("backup_version","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_backup_version={0x60710025U,"textwire_backup_version",sxtw_backup_version_fields,SX_COUNT(sxtw_backup_version_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_compression_fields[]={
 SX_FIELD("compression","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_compression={0x60710026U,"textwire_compression",sxtw_compression_fields,SX_COUNT(sxtw_compression_fields),SX_LE};
static bool sxtw_android(sxtw_cursor*q)
{
 int64_t a,end;const sx_layout*l[]={&sxtw_signature,&sxtw_backup_version,&sxtw_compression,&sxtw_encryption};for(unsigned i=0;i<4;i++){if(!sxtw_line(q,&a,&end)||!sxtw_emit(q,l[i],a,end-a))return false;}return true;
}
bool sx_android_ab_build(sxtw_cursor*q)
{
 return sxtw_android(q);
}
