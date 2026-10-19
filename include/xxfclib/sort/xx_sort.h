/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_sort.h
 * @brief In-place sorting algorithms for contiguous fixed-size elements.
 */

#ifndef XXFCLIB_XX_SORT_H
#define XXFCLIB_XX_SORT_H

#include "xxfclib/xxfc_defs.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/** The comparison callback of every xxfclib sort, and the form each format's
 * private comparator (xx_sort_<format>.inc) takes. Return < 0 when pLeft
 * sorts first, > 0 when pRight does, 0 when they are equal. pContext is the
 * caller's pointer, passed through unchanged; it may be NULL. Comparators
 * must define a consistent order and must not modify the elements. */
typedef int (*xx_sort_callback)(const void *pLeft, const void *pRight, void *pContext);

/* Earlier spellings, kept for existing callers. */
typedef int (*xx_sort_compare_fn)(const void *pLeft, const void *pRight);
typedef xx_sort_callback xx_sort_compare_context_fn;

/* The library-owned algorithms select scalar, SSE2, AVX2 or NEON element
 * movement once per call using the global CPU switches. Small elements remain
 * scalar; comparisons, stability, and equal-element permutations do not change.
 * NULL pointers, zero element size, fewer than two elements and an
 * overflowing count * size are ignored by all sorting entry points.
 *
 * Choosing an algorithm: a comparator that orders every pair (equal only for
 * identical keys, e.g. it falls back to an index) gives the same result with
 * any of them, so use xx_sort_context. One that leaves ties must keep the
 * algorithm whose tie order the output depends on: xx_sort_stable_context to
 * keep input order, xx_sort_quick_context for the DIE database order. */

/** Allocation-free heapsort. O(n log n) comparisons, constant auxiliary
 * storage, and no stable ordering guarantee for elements that compare equal. */
XXFC_API void xx_sort_context(void *pBase, size_t nCount, size_t nSize, xx_sort_callback fnCompare, void *pContext);

/** Median-of-three quicksort with insertion sort for runs below 13 elements.
 * Preserves the original DIE signature database's partitioning and ordering
 * of equal elements on every platform. No allocation; O(log n) recursive
 * stack depth. Ranges larger than PTRDIFF_MAX bytes are ignored. */
XXFC_API void xx_sort_quick_context(void *pBase, size_t nCount, size_t nSize, xx_sort_callback fnCompare, void *pContext);

/** Stable sort: equal elements retain their input order, so the result is the
 * same as any other stable sort's. A merge sort, O(n log n), with one
 * temporary copy of the array; without memory for it, an in-place insertion
 * sort (O(n squared) worst case) gives the identical result. */
XXFC_API void xx_sort_stable_context(void *pBase, size_t nCount, size_t nSize, xx_sort_callback fnCompare, void *pContext);

/** Sort using the platform's general-purpose algorithm: allocation-free
 * heapsort on Windows and libc qsort on hosted POSIX builds. Equal elements
 * may be reordered, differently per platform. */
XXFC_API void xx_sort(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare);

/** xx_sort_quick_context for a comparator without a context. */
XXFC_API void xx_sort_quick(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare);

/** xx_sort_stable_context for a comparator without a context. */
XXFC_API void xx_sort_stable(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare);

#ifdef __cplusplus
}
#endif

#endif /* XXFCLIB_XX_SORT_H */
