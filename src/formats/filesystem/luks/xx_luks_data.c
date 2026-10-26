/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LUKS data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_luks2_header_fields[] = {
    SX_FIELD("magic", "byte[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("header_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("sequence_id", "uint64", 16, 8, SX_NONE),
    SX_FIELD("label", "char[48]", 24, 48, SX_STRING),
    SX_FIELD("checksum_algorithm", "char[32]", 72, 32, SX_STRING),
    SX_FIELD("salt", "byte[64]", 104, 64, SX_NONE),
    SX_FIELD("uuid", "char[40]", 168, 40, SX_STRING),
    SX_FIELD("subsystem", "char[48]", 208, 48, SX_STRING),
    SX_FIELD("header_offset", "uint64", 256, 8, SX_OFFSET),
    SX_FIELD("padding", "byte[184]", 264, 184, SX_RESERVED),
    SX_FIELD("checksum", "byte[64]", 448, 64, SX_CHECKSUM),
    SX_FIELD("padding4096", "byte[3584]", 512, 3584, SX_RESERVED),
};
const sx_layout sx_st_luks2_header = {0x60080058U, "luks2_header", sx_st_luks2_header_fields, SX_COUNT(sx_st_luks2_header_fields), SX_BE};
static bool sx_st_luks(sx_context *c)
{
    uint16_t version;if(!sx_u16(c,6,true,&version))return false;
    if(version==1)return sx_add(c,&sx_st_luks1_header,0,208)&&sx_table(c,&sx_st_luks1_keyslot,208,48,8);
    if(version==2) {
        uint64_t span;uint8_t magic[8];
        if(!sx_add(c,&sx_st_luks2_header,0,4096)||!sx_u64(c,8,true,&span))return false;
        if(span>=4096&&sx_st_fits(c,span,4096)) {
            uint64_t size,off;
            if(!sx_read(c,(int64_t)span,magic,8))return false;
            if(!xx_rt_memcmp(magic,"SKUL\xba\xbe\0\2",8)) {
                if(!sx_u64(c,(int64_t)span+8,true,&size)||!sx_u64(c,(int64_t)span+256,true,&off))return false;
                if(off==span&&size>=4096&&sx_st_fits(c,span,size)&&!sx_add(c,&sx_st_luks2_header,(int64_t)span,4096))return false;
            }
        }
        return true;
    }
    return false;
}
bool sx_luks_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_luks(c);
    return ok&&sx_st_finish(c);
}
