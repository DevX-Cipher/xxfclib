/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQLITE3 data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_sqlite_cell_pointer_fields[] = {
    SX_FIELD("cell_offset", "uint16", 0, 2, SX_OFFSET),
};
const sx_layout sx_c_sqlite_cell_pointer = { UINT32_C(0x60020025), "sqlite_cell_pointer", sx_c_sqlite_cell_pointer_fields, SX_COUNT(sx_c_sqlite_cell_pointer_fields), SX_BE };
static bool sx_c_sqlite(sx_context *c)
{
    uint8_t h[100],b[12]; uint32_t page,pages,usable; uint16_t cells,start,freeblock; unsigned header;
    if (!sx_read(c,0,h,100) || xx_rt_memcmp(h,"SQLite format 3\0",16)) return false;
    page=xx_data_get_u16(h+16,2,0,true); if(page==1)page=65536;
    pages=xx_data_get_u32(h+28,4,0,true);
    if (page<512||page>65536||(page&(page-1))||h[20]>page-480||!pages||pages>(uint64_t)c->size/page) return false;
    usable=page-h[20];
    if (!sx_add(c,&sx_c_sqlite3_database_header,0,100)||!sx_read(c,100,b,8))return false;
    /* Page one is always the sqlite_schema B-tree. Other page roles require a
     * full logical B-tree/freelist/overflow traversal, and remain explicit raw
     * pages instead of guessing from their leading byte. */
    if (b[0]!=5 && b[0]!=13) return false;
    header=b[0]==5?12:8; cells=xx_data_get_u16(b+3,2,0,true);start=xx_data_get_u16(b+5,2,0,true);freeblock=xx_data_get_u16(b+1,2,0,true);
    if (100U+header+2U*cells>usable || (start && (start<100U+header+2U*cells || start>usable)) || b[7]>60 ||
        (freeblock && (freeblock<100U+header+2U*cells || freeblock>usable-4))) return false;
    if (!sx_add(c,b[0]==5?&sx_c_sqlite_btree_interior_page_header:&sx_c_sqlite_btree_leaf_page_header,100,header) ||
        !sx_table(c,&sx_c_sqlite_cell_pointer,100+header,2,cells)) return false;
    for (uint32_t i=0;i<cells;++i) {
        uint16_t cell;
        if (!sx_u16(c,100+header+2*i,true,&cell) || cell<100U+header+2U*cells || cell>=usable) return false;
    }
    if (!sx_raw(c,100+header+2*cells,page-(100+header+2*cells))) return false;
    /* Coalesce uninterpreted pages to avoid one allocation per page. */
    return sx_raw(c,page,(int64_t)(pages-1)*page) && sx_raw(c,(int64_t)pages*page,c->size-(int64_t)pages*page);
}
bool sx_sqlite3_build(sx_context*c)
{
    return sx_c_sqlite(c);
}
