/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WebExe M2E container data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_webexe_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","char[1]",5,1,SX_NONE),
 SX_FIELD("format_marker","char[1]",6,1,SX_NONE),
 SX_FIELD("zip_end_offset","ascii_decimal[10]",7,10,SX_OFFSET),
 SX_FIELD("file_size","ascii_decimal[10]",17,10,SX_SIZE),
};
const sx_layout sxas_webexe_header = {UINT32_C(0x60430014),"webexe_header",sxas_webexe_header_fields,SX_COUNT(sxas_webexe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_local_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint16",26,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
const sx_layout sxas_webexe_zip_local = {UINT32_C(0x60430015),"webexe_zip_local",sxas_webexe_zip_local_fields,SX_COUNT(sxas_webexe_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_central_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_made","uint16",4,2,SX_NONE),
 SX_FIELD("version_needed","uint16",6,2,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("method","uint16",10,2,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",30,2,SX_SIZE),
 SX_FIELD("comment_size","uint16",32,2,SX_SIZE),
 SX_FIELD("starting_disk","uint16",34,2,SX_NONE),
 SX_FIELD("internal_attributes","uint16",36,2,SX_FLAGS),
 SX_FIELD("external_attributes","uint32",38,4,SX_FLAGS),
 SX_FIELD("local_header_offset","uint32",42,4,SX_OFFSET),
};
const sx_layout sxas_webexe_zip_central = {UINT32_C(0x60430016),"webexe_zip_central",sxas_webexe_zip_central_fields,SX_COUNT(sxas_webexe_zip_central_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_end_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("disk_number","uint16",4,2,SX_NONE),
 SX_FIELD("directory_disk","uint16",6,2,SX_NONE),
 SX_FIELD("disk_entries","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("total_entries","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32",12,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("comment_size","uint16",20,2,SX_SIZE),
};
const sx_layout sxas_webexe_zip_end = {UINT32_C(0x60430017),"webexe_zip_end",sxas_webexe_zip_end_fields,SX_COUNT(sxas_webexe_zip_end_fields),SX_LE};
static int64_t sxas_webexe_overlay(sx_context *c)
{
    uint8_t h[64], p[24], section[40];
    uint32_t pe;
    unsigned count, opt, i;
    uint64_t end, n = (uint64_t)c->size;
    if (n < 2 || !sxas_read(c, 0, h, 2)) return -1;
    if (h[0] != 'M' || h[1] != 'Z') return 0;
    if (n < 64 || !sxas_read(c, 0, h, 64)) return -1;
    pe = sxas_uint(h+60,4,false);
    if (!sxas_span(c,pe,24) || !sxas_read(c, pe, p, 24) || xx_rt_memcmp(p, "PE\0\0", 4)) return -1;
    count = xx_data_get_u16(p + 6, 2, 0, false);
    opt = xx_data_get_u16(p + 20, 2, 0, false);
    if (!count || count > 96 || opt < 64 || opt > 4096 || !sxas_span(c,(uint64_t)pe+24,opt+(uint64_t)count*40) || !sxas_read(c, (int64_t)pe + 84, h, 4))
        return -1;
    end = sxas_uint(h,4,false);
    for (i = 0; i < count; ++i) {
        uint64_t finish;
        if (!sxas_read(c, (int64_t)pe + 24 + opt + (int64_t)i * 40, section, 40)) return -1;
        finish = (uint64_t)sxas_uint(section+16,4,false) + sxas_uint(section+20,4,false);
        if (finish > n) return -1;
        if (finish > end) end = finish;
    }
    /* Some signed launchers append their archive after WIN_CERTIFICATE. */
    if (!sxas_read(c, (int64_t)pe + 24, h, 2)) return -1;
    {
        unsigned dd = xx_data_get_u16(h, 2, 0, false) == 0x10b ? 128 : xx_data_get_u16(h, 2, 0, false) == 0x20b ? 144 : 0;
        if (dd && opt >= dd + 8 && sxas_read(c, (int64_t)pe + 24 + dd, h, 8)) {
            uint64_t cert = sxas_uint(h,4,false), bytes = sxas_uint(h+4,4,false);
            if (bytes >= 8 && sxas_span(c,cert,bytes) && (cert == end || (sxas_span(c,end,bytes) && cert + bytes == n))) {
                uint64_t at = cert;
                bool prefix = cert != end;
                if (prefix) {
                    uint8_t first[8], last[8];
                    if (!sxas_read(c, (int64_t)end, first, 8) || !sxas_read(c, (int64_t)cert, last, 8) || xx_rt_memcmp(first, last, 8)) return (int64_t)end;
                    /* A re-signed launcher retains its older certificate
                     * before the appended archive. Their signatures differ. */
                }
                while (at < cert + bytes) {
                    uint32_t size;
                    if (!sxas_read(c, (int64_t)at, h, 8)) return -1;
                    size = sxas_uint(h,4,false);
                    if (size < 8 || !(at<=cert+bytes && size<=cert+bytes-at) || xx_data_get_u16(h + 4, 2, 0, false) != 0x200 || xx_data_get_u16(h + 6, 2, 0, false) != 2)
                        return -1;
                    at = (at + size + 7) & ~UINT64_C(7);
                }
                if (at != cert + bytes) return -1;
                end = prefix ? end + bytes : at;
            }
        }
    }
    return end <= n ? (int64_t)end : -1;
}
static bool sxas_webexe(sx_context*c){int64_t at=sxas_webexe_overlay(c);uint8_t b[1024];uint64_t end=0,physical=0;if(at<0||!sxas_read(c,(uint64_t)at,b,27)||xx_rt_memcmp(b,"*M2E*",5)||b[5]<'1'||b[5]>'9'||b[6]!='A')return false;for(unsigned i=0;i<10;i++){if(b[7+i]<'0'||b[7+i]>'9'||b[17+i]<'0'||b[17+i]>'9')return false;end=end*10+b[7+i]-'0';physical=physical*10+b[17+i]-'0';}if(physical!=(uint64_t)c->size||end>(uint64_t)c->size||end<=(uint64_t)at+27||!sxas_add(c,&sxas_webexe_header,(uint64_t)at))return false;uint64_t p=(uint64_t)at+27,n=end-p;if(n>sizeof(b))n=sizeof(b);if(!sxas_read(c,p,b,(size_t)n))return false;bool found=false;for(uint64_t i=0;i+4<=n;i++)if(!xx_rt_memcmp(b+i,"PK\3\4",4)){p+=i;found=true;break;}if(!found)return false;while(p<end){if(end-p<4||!sxas_read(c,p,b,4))return false;uint64_t sig=sxas_uint(b,4,false),hs,names,packed=0;const sx_layout*l;if(sig==0x04034b50){hs=30;l=&sxas_webexe_zip_local;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;packed=sxas_uint(b+18,4,false);names=sxas_uint(b+26,2,false)+sxas_uint(b+28,2,false);}else if(sig==0x02014b50){hs=46;l=&sxas_webexe_zip_central;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;names=sxas_uint(b+28,2,false)+sxas_uint(b+30,2,false)+sxas_uint(b+32,2,false);}else if(sig==0x06054b50){hs=22;l=&sxas_webexe_zip_end;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;names=sxas_uint(b+20,2,false);}else return false;if(names>end-p-hs||packed>end-p-hs-names||!sxas_add(c,l,p))return false;p+=hs+names+packed;}return true;}
bool sx_webexe_build(sx_context*c)
{
 return sxas_webexe(c);
}
