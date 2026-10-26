/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCAP data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_pcap_file_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("major_version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("reserved1", "int32", 8, 4, SX_RESERVED),
    SX_FIELD("reserved2", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("snapshot_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("linktype_and_information", "uint32", 20, 4, SX_FLAGS),
};
const sx_layout sx_c_pcap_file_header_le = { UINT32_C(0x6002001E), "pcap_file_header_le", sx_c_pcap_file_header_fields, SX_COUNT(sx_c_pcap_file_header_fields), SX_LE };
const sx_layout sx_c_pcap_file_header_be = { UINT32_C(0x6002001F), "pcap_file_header_be", sx_c_pcap_file_header_fields, SX_COUNT(sx_c_pcap_file_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_pcap_packet_header_fields[] = {
    SX_FIELD("timestamp_seconds", "uint32", 0, 4, SX_TIME),
    SX_FIELD("timestamp_fraction", "uint32", 4, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 12, 4, SX_SIZE),
};
const sx_layout sx_c_pcap_packet_header_le = { UINT32_C(0x60020020), "pcap_packet_header_le", sx_c_pcap_packet_header_fields, SX_COUNT(sx_c_pcap_packet_header_fields), SX_LE };
const sx_layout sx_c_pcap_packet_header_be = { UINT32_C(0x60020021), "pcap_packet_header_be", sx_c_pcap_packet_header_fields, SX_COUNT(sx_c_pcap_packet_header_fields), SX_BE };
static bool sx_c_pcap(sx_context *c)
{
    uint8_t h[24]; uint32_t magic,snap; bool be,nano; int64_t at=24;
    if (!sx_read(c,0,h,24)) return false;
    magic=xx_data_get_u32(h,4,0,true);
    be=magic==UINT32_C(0xa1b2c3d4)||magic==UINT32_C(0xa1b23c4d);
    nano=magic==UINT32_C(0xa1b23c4d)||magic==UINT32_C(0x4d3cb2a1);
    if (!be && magic!=UINT32_C(0xd4c3b2a1) && magic!=UINT32_C(0x4d3cb2a1)) return false;
    snap=xx_data_get_u32(h+16,4,0,be);
    if (xx_data_get_u16(h+4,2,0,be)!=2 || xx_data_get_u16(h+6,2,0,be)!=4 || !snap ||
        !sx_add(c,be ? &sx_c_pcap_file_header_be : &sx_c_pcap_file_header_le,0,24)) return false;
    while (at<c->size) {
        uint32_t fraction,cap,original;
        if (!sx_u32(c,at+4,be,&fraction) || !sx_u32(c,at+8,be,&cap) || !sx_u32(c,at+12,be,&original) ||
            fraction>=(nano?1000000000U:1000000U) || cap>snap || cap>original || !sx_c_bounds(c,at+16,cap) ||
            !sx_add(c,be ? &sx_c_pcap_packet_header_be : &sx_c_pcap_packet_header_le,at,16) || !sx_raw(c,at+16,cap)) return false;
        at+=16+(int64_t)cap;
    }
    return true;
}
bool sx_pcap_build(sx_context*c)
{
    return sx_c_pcap(c);
}
