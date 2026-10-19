/* Private adapter for the BSD-3-Clause Apple encoder. */
#ifndef XX_LZFSE_REFERENCE_H
#define XX_LZFSE_REFERENCE_H
#ifndef NDEBUG
#define NDEBUG 1
#endif
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/memory/xx_memory.h"
#define LZFSE_API
#define malloc xx_mem_alloc
#define free xx_mem_free
#undef memcpy
#undef memmove
#undef memset
#define memcpy xx_rt_memcpy
#define memmove xx_rt_memmove
#define memset xx_rt_memset
#define lzfse_encode_scratch_size xx_ref_lzfse_encode_scratch_size
#define lzfse_encode_buffer xx_ref_lzfse_encode_buffer
#define lzfse_encode_buffer_with_scratch xx_ref_lzfse_encode_buffer_with_scratch
#define lzfse_encode_init xx_ref_lzfse_encode_init
#define lzfse_encode_translate xx_ref_lzfse_encode_translate
#define lzfse_encode_base xx_ref_lzfse_encode_base
#define lzfse_encode_finish xx_ref_lzfse_encode_finish
#define lzvn_encode xx_ref_lzvn_encode
#define lzvn_encode_scratch_size xx_ref_lzvn_encode_scratch_size
#define lzvn_encode_buffer xx_ref_lzvn_encode_buffer
#define fse_init_encoder_table xx_ref_fse_init_encoder_table
#define fse_init_decoder_table xx_ref_fse_init_decoder_table
#define fse_init_value_decoder_table xx_ref_fse_init_value_decoder_table
#define fse_normalize_freq xx_ref_fse_normalize_freq
#include "reference/lzfse.h"
#endif
