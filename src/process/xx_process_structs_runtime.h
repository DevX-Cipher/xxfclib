/* Copyright (c) 2026 hors<horsicq@gmail.com>. SPDX-License-Identifier: MIT */
#ifndef XX_PROCESS_STRUCTS_RUNTIME_H
#define XX_PROCESS_STRUCTS_RUNTIME_H
/* Include after system declarations. The full library already supplies its
 * CRT-compatible runtime (including freestanding Windows configurations).
 * Standalone subset consumers use their hosted C runtime, keeping the small
 * I/O subset independent of the general formatter and math implementation. */
#if defined(XXFC_PROCESS_STRUCTS_USE_RUNTIME)
#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/memory/xx_memory.h"
#undef calloc
#undef realloc
#undef free
#undef memcpy
#undef memset
#undef strlen
#undef strcmp
#undef strstr
#undef strrchr
#undef wcslen
#undef wcscmp
#undef wcsncmp
#undef wcschr
#undef snprintf
#undef vsnprintf
#define calloc xx_mem_calloc
#define realloc xx_mem_realloc
#define free xx_mem_free
#define memcpy xx_mem_copy
#define memset xx_mem_set
#define strlen xx_rt_strlen
#define strcmp xx_rt_strcmp
#define strstr xx_rt_strstr
#define strrchr xx_rt_strrchr
#define wcslen xx_rt_wcslen
#define wcscmp xx_rt_wcscmp
#define wcsncmp xx_rt_wcsncmp
#define wcschr xx_rt_wcschr
#define snprintf xx_rt_snprintf
#define vsnprintf xx_rt_vsnprintf
#endif
#endif
