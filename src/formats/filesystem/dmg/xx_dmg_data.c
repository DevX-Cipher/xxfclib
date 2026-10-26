/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DMG data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_udif_trailer_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
    SX_FIELD("running_data_fork_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("data_fork_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("data_fork_length","uint64",32,8,SX_SIZE),
    SX_FIELD("resource_fork_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("resource_fork_length","uint64",48,8,SX_SIZE),
    SX_FIELD("segment_number","uint32",56,4,SX_NONE),
    SX_FIELD("segment_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("segment_id","byte[16]",64,16,SX_ID),
    SX_FIELD("data_checksum_type","uint32",80,4,SX_ID),
    SX_FIELD("data_checksum_bits","uint32",84,4,SX_NONE),
    SX_FIELD("data_checksum","uint32[32]",88,128,SX_CHECKSUM),
    SX_FIELD("xml_offset","uint64",216,8,SX_OFFSET),
    SX_FIELD("xml_length","uint64",224,8,SX_SIZE),
    SX_FIELD("reserved1","byte[64]",232,64,SX_RESERVED),
    SX_FIELD("code_signature_offset","uint64",296,8,SX_OFFSET),
    SX_FIELD("code_signature_length","uint64",304,8,SX_SIZE),
    SX_FIELD("reserved2","byte[40]",312,40,SX_RESERVED),
    SX_FIELD("master_checksum_type","uint32",352,4,SX_ID),
    SX_FIELD("master_checksum_bits","uint32",356,4,SX_NONE),
    SX_FIELD("master_checksum","uint32[32]",360,128,SX_CHECKSUM),
    SX_FIELD("image_variant","uint32",488,4,SX_ID),
    SX_FIELD("sector_count","uint64",492,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","byte[12]",500,12,SX_RESERVED),
};
const sx_layout sx_dm_udif_trailer = {0x6029002cU,"udif_trailer",sx_dm_udif_trailer_fields,SX_COUNT(sx_dm_udif_trailer_fields),SX_BE};
bool sx_dmg_build(sx_context*c)
{
 return c->size>=512&&sx_dm_add(c,&sx_dm_udif_trailer,(uint64_t)c->size-512,512);
}
