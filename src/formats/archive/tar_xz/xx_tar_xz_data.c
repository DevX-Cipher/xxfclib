/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_tar_xz_data.h"
#include "xx_tar_xz_internal.h"
#include "../tar_common/xx_tar_common_data.h"

const char *xx_tar_xz_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, true);
    return common ? xx_tar_common_data_struct_id_to_string(common, id) : "UNKNOWN";
}

uint32_t xx_tar_xz_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, true);
    return common ? xx_tar_common_data_struct_string_to_id(common, name) : XX_TAR_XZ_DS_UNKNOWN;
}

xx_data_struct_state *xx_tar_xz_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, true);
    if (!self || !common) return NULL;
    return xx_tar_common_create_data_structs_reading(common, self, xx_tar_xz_decode, pd);
}

const xx_data_struct *xx_tar_xz_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    return common ? xx_tar_common_get_current_data_struct(common, state) : NULL;
}

bool xx_tar_xz_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    return common && xx_tar_common_data_struct_move_to_next(common, state, pd);
}

void xx_tar_xz_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    if (common) xx_tar_common_free_data_structs_reading(common, state);
}

xx_data_struct_record_state *xx_tar_xz_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    return common ? xx_tar_common_create_data_struct_records_reading(common, ds, pd) : NULL;
}

const xx_data_struct_record *xx_tar_xz_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    return common ? xx_tar_common_get_current_data_struct_record(common, state) : NULL;
}

bool xx_tar_xz_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    return common && xx_tar_common_data_struct_record_move_to_next(common, state, pd);
}

void xx_tar_xz_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    xx_tar_common *common = xx_tar_xz_common((xx_tar_xz *)self, false);
    if (common) {
        xx_tar_common_free_data_struct_records_reading(common, state);
    }
}

void xx_tar_xz_setup_data_struct_callbacks(xx_tar_xz *tar_xz)
{
    if (!tar_xz) return;
    tar_xz->format.data_struct_id_to_string = xx_tar_xz_data_struct_id_to_string;
    tar_xz->format.data_struct_string_to_id = xx_tar_xz_data_struct_string_to_id;
    tar_xz->format.create_data_structs_reading = xx_tar_xz_create_data_structs_reading;
    tar_xz->format.get_current_data_struct = xx_tar_xz_get_current_data_struct;
    tar_xz->format.data_struct_move_to_next = xx_tar_xz_data_struct_move_to_next;
    tar_xz->format.free_data_structs_reading = xx_tar_xz_free_data_structs_reading;
    tar_xz->format.create_data_struct_records_reading = xx_tar_xz_create_data_struct_records_reading;
    tar_xz->format.get_current_data_struct_record = xx_tar_xz_get_current_data_struct_record;
    tar_xz->format.data_struct_record_move_to_next = xx_tar_xz_data_struct_record_move_to_next;
    tar_xz->format.free_data_struct_records_reading = xx_tar_xz_free_data_struct_records_reading;
}
