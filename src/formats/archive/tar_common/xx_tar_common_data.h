/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XXFCLIB_TAR_COMMON_DATA_INTERNAL_H
#define XXFCLIB_TAR_COMMON_DATA_INTERNAL_H

#include "xx_tar_common.h"

#ifdef __cplusplus
extern "C" {
#endif

const char *xx_tar_common_data_struct_id_to_string(xx_tar_common *common, uint32_t id);
uint32_t xx_tar_common_data_struct_string_to_id(xx_tar_common *common, const char *name);
xx_data_struct_state *xx_tar_common_create_data_structs_reading(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd);
const xx_data_struct *xx_tar_common_get_current_data_struct(xx_tar_common *common, xx_data_struct_state *state);
bool xx_tar_common_data_struct_move_to_next(xx_tar_common *common, xx_data_struct_state *state, xx_pd_struct *pd);
void xx_tar_common_free_data_structs_reading(xx_tar_common *common, xx_data_struct_state *state);

xx_data_struct_record_state *xx_tar_common_create_data_struct_records_reading(xx_tar_common *common, const xx_data_struct *data_struct, xx_pd_struct *pd);
const xx_data_struct_record *xx_tar_common_get_current_data_struct_record(xx_tar_common *common, xx_data_struct_record_state *state);
bool xx_tar_common_data_struct_record_move_to_next(xx_tar_common *common, xx_data_struct_record_state *state, xx_pd_struct *pd);
void xx_tar_common_free_data_struct_records_reading(xx_tar_common *common, xx_data_struct_record_state *state);

#ifdef __cplusplus
}
#endif

#endif /* XXFCLIB_TAR_COMMON_DATA_INTERNAL_H */
