/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#if defined(_WIN32)

#include "xxfclib/sort/xx_sort.h"

typedef struct xx_sort_plain_context_s {
    xx_sort_compare_fn fnCompare;
} xx_sort_plain_context;

static int xx_sort_plain_compare(const void *pLeft, const void *pRight, void *pContext)
{
    xx_sort_plain_context *pSort = (xx_sort_plain_context *)pContext;

    return pSort->fnCompare(pLeft, pRight);
}

void xx_sort(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare)
{
    xx_sort_plain_context context;

    if ((pBase == NULL) || (fnCompare == NULL) || (nCount < 2) || (nSize == 0) || (nCount > ((size_t)-1) / nSize)) {
        return;
    }

    context.fnCompare = fnCompare;
    xx_sort_context(pBase, nCount, nSize, xx_sort_plain_compare, &context);
}

#endif /* defined(_WIN32) */
