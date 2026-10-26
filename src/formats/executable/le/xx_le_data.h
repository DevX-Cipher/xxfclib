/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XXFCLIB_LE_DATA_INTERNAL_H
#define XXFCLIB_LE_DATA_INTERNAL_H

#include "xxfclib/formats/executable/le/xx_le.h"

/* Called from xx_linear_init_impl(), so it serves both LE and LX. */
void xx_le_setup_data_struct_callbacks(xx_linear_executable *linear);

#endif /* XXFCLIB_LE_DATA_INTERNAL_H */
