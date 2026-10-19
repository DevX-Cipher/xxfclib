/* Copyright (c) 2026 hors<horsicq@gmail.com>; SPDX-License-Identifier: MIT */
#include "xxfclib/algo/lzfse/xx_lzfse.h"
#include "../xx_pack_memory_internal.h"
#include "xx_lzfse_reference.h"
size_t xx_lzfse_compress_bound(size_t size)
{
    return size>=INT32_MAX || size>SIZE_MAX-12U ? 0U : size+12U;
}
bool xx_lzfse_compress_memory(const void *source,size_t size,void *destination,size_t capacity,size_t *written)
{
    static const uint8_t empty=0;
    if(written)*written=0;
    if ((!source && size) || !destination || !xx_lzfse_compress_bound(size)) return false;
    size_t bound=xx_lzfse_compress_bound(size);if(capacity>bound)capacity=bound;
    void *scratch=xx_mem_alloc(lzfse_encode_scratch_size());if(!scratch)return false;
    size_t n=lzfse_encode_buffer(destination,capacity,source ? source : &empty,size,scratch);
    xx_mem_free(scratch);
    if(!n)return false;
    if(written)*written=n;return true;
}
bool xx_lzfse_pack_device(xx_io_device *source,int64_t offset,int64_t size,xx_io_device *destination,xx_pd_struct *pd)
{
    return xx_codec_pack_memory_device(source,offset,size,destination,pd,xx_lzfse_compress_bound,xx_lzfse_compress_memory);
}
