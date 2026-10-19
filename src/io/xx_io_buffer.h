/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/* Internal dispatch for attached and wrapper I/O buffers. */
#ifndef XX_IO_BUFFER_INTERNAL_H
#define XX_IO_BUFFER_INTERNAL_H

#include "xxfclib/io/xx_io.h"

ssize_t xx_io_buffer_read_dispatch(xx_io_device *device, void *buffer, size_t size);
ssize_t xx_io_buffer_write_dispatch(xx_io_device *device, const void *buffer, size_t size);
int xx_io_buffer_seek_dispatch(xx_io_device *device, int64_t offset, int whence);
int64_t xx_io_buffer_tell_dispatch(xx_io_device *device);
int xx_io_buffer_close_dispatch(xx_io_device *device);

#endif /* XX_IO_BUFFER_INTERNAL_H */
