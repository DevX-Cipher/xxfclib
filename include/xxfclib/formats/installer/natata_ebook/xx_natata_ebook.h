/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#ifndef XX_NATATA_EBOOK_H
#define XX_NATATA_EBOOK_H
#include "xxfclib/formats/xx_format.h"
#ifdef __cplusplus
extern "C" {
#endif
/** Natata framed records, optionally in a PE overlay. Native zlib records
 * and a stored MAIN_PROG_FILE PE are supported. Packed programs are emitted
 * unchanged; their executable code is never run. */
XXFC_API Abstractformat *xx_natata_ebook_create(xx_io_device *device, int64_t base_address);
XXFC_API void xx_natata_ebook_free(Abstractformat *format);
XXFC_API bool xx_natata_ebook_fast_detect(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API xx_file_type_t xx_natata_ebook_file_type(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API int64_t xx_natata_ebook_size(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API Abstractextractor *xx_natata_ebook_get_abstract_extractor(void);
XXFC_API Abstractdetector *xx_natata_ebook_get_abstract_detector(void);
#ifdef __cplusplus
}
#endif
#endif
