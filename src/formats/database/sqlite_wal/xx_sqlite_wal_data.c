/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQLITE_WAL data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_sqlite_wal_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("page_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checkpoint_sequence", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("salt1", "uint32", 16, 4, SX_ID),
    SX_FIELD("salt2", "uint32", 20, 4, SX_ID),
    SX_FIELD("checksum1", "uint32", 24, 4, SX_CHECKSUM),
    SX_FIELD("checksum2", "uint32", 28, 4, SX_CHECKSUM),
};
const sx_layout sx_c_sqlite_wal_header = { UINT32_C(0x60020026), "sqlite_wal_header", sx_c_sqlite_wal_header_fields, SX_COUNT(sx_c_sqlite_wal_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_sqlite_wal_frame_header_fields[] = {
    SX_FIELD("page_number", "uint32", 0, 4, SX_NONE),
    SX_FIELD("database_size_pages", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("salt1", "uint32", 8, 4, SX_ID),
    SX_FIELD("salt2", "uint32", 12, 4, SX_ID),
    SX_FIELD("checksum1", "uint32", 16, 4, SX_CHECKSUM),
    SX_FIELD("checksum2", "uint32", 20, 4, SX_CHECKSUM),
};
const sx_layout sx_c_sqlite_wal_frame_header = { UINT32_C(0x60020027), "sqlite_wal_frame_header", sx_c_sqlite_wal_frame_header_fields, SX_COUNT(sx_c_sqlite_wal_frame_header_fields), SX_BE };
static bool sx_c_sqlite_wal(sx_context *c)
{
    uint8_t h[32]; uint32_t magic,page; int64_t at=32;
    if (!sx_read(c,0,h,32))return false;
    magic=xx_data_get_u32(h,4,0,true);page=xx_data_get_u32(h+8,4,0,true);
    if ((magic!=UINT32_C(0x377f0682)&&magic!=UINT32_C(0x377f0683)) || page<512 || page>65536 || (page&(page-1)) ||
        !sx_add(c,&sx_c_sqlite_wal_header,0,32))return false;
    while(at<c->size) {
        uint32_t page_number,salt1,salt2;
        if(!sx_c_bounds(c,at,24+(uint64_t)page)||!sx_u32(c,at,true,&page_number)||!page_number||
           !sx_u32(c,at+8,true,&salt1)||!sx_u32(c,at+12,true,&salt2)||salt1!=xx_data_get_u32(h+16,4,0,true)||salt2!=xx_data_get_u32(h+20,4,0,true)||
           !sx_add(c,&sx_c_sqlite_wal_frame_header,at,24)||!sx_raw(c,at+24,page))return false;
        at+=24+(int64_t)page;
    }
    return true;
}
bool sx_sqlite_wal_build(sx_context*c)
{
    return sx_c_sqlite_wal(c);
}
