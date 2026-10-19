/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/** @file xx_rprj.h @brief Radare project container reader. */

#ifndef XXFCLIB_FORMAT_RPRJ_H
#define XXFCLIB_FORMAT_RPRJ_H

#include "xxfclib/formats/xx_format.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct xx_rprj {
    Abstractformat format;
    uint32_t version;
} xx_rprj;

XXFC_API void xx_rprj_init(xx_rprj *reader, xx_io_device *device, int64_t base_address);
XXFC_API xx_rprj *xx_rprj_create(xx_io_device *device, int64_t base_address);
XXFC_API void xx_rprj_destroy(xx_rprj *reader);
XXFC_API void xx_rprj_free(xx_rprj *reader);
XXFC_API bool xx_rprj_check_is_valid(Abstractformat *self, xx_pd_struct *pd);
XXFC_API bool xx_rprj_handle_base_info(Abstractformat *self, xx_pd_struct *pd);

#ifdef __cplusplus
}
#endif

/* BEGIN GENERATED ABSTRACT EXTRACTOR */
#ifdef __cplusplus
extern "C" {
#endif
XXFC_API bool xx_rprj_fast_detect(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API xx_file_type_t xx_rprj_file_type(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API int64_t xx_rprj_size(xx_io_device *device, int64_t base_address, bool is_mapped);
XXFC_API Abstractextractor *xx_rprj_get_abstract_extractor(void);
XXFC_API Abstractdetector *xx_rprj_get_abstract_detector(void);
#ifdef __cplusplus
}
#endif
/* END GENERATED ABSTRACT EXTRACTOR */
#endif /* XXFCLIB_FORMAT_RPRJ_H */
