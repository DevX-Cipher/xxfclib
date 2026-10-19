/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#if !defined(_WIN32)

#include "xxfclib/sort/xx_sort.h"
#include <stdlib.h>

void xx_sort(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare)
{
    if ((pBase == NULL) || (fnCompare == NULL) || (nCount < 2) || (nSize == 0) || (nCount > ((size_t)-1) / nSize)) {
        return;
    }

    qsort(pBase, nCount, nSize, fnCompare);
}

#endif /* !defined(_WIN32) */
