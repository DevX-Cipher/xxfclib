/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xxfclib/algo/adler32/xx_adler32.h"
#include "xxfclib/global/xx_global.h"

uint32_t xx_adler32_device(xx_io_device *device, int64_t offset, int64_t size)
{
    xx_io_device *temporary = NULL;
    const unsigned char *whole;
    size_t capacity;
    uint32_t value = XX_ADLER32_INIT;

    if (!xx_io_range_clamp(device, offset, &size) || !size) return value;
    capacity = xx_io_buffer_capacity(device);
    if (!capacity) {
        capacity = xx_get_file_buffer_size();
        if (!capacity) capacity = XX_DEFAULT_FILE_BUFFER_SIZE;
        if (capacity > (size_t)PTRDIFF_MAX) capacity = (size_t)PTRDIFF_MAX;
        temporary = xx_io_buffer_open(device, capacity, 0, false);
        if (!temporary) return value;
        device = temporary;
    }

    whole = xx_io_buffer_whole(device, (uint64_t)size);
    if (whole && (uint64_t)size <= SIZE_MAX) {
        value = xx_adler32(whole + offset, (size_t)size);
    } else {
        while (size > 0) {
            size_t count = (uint64_t)size < capacity ? (size_t)size : capacity;
            const unsigned char *view = xx_io_buffer_view(device, offset, &count);
            if (!view || !count) break;
            value = xx_adler32_update(value, view, count);
            offset += (int64_t)count;
            size -= (int64_t)count;
        }
    }

    if (temporary) xx_io_close(temporary);
    return value;
}
