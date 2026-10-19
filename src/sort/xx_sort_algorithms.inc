/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/* Included once per backend after defining XX_SORT_IMPL(name) and the
 * backend-local xx_sort_swap_bytes. Keep comparison and swap order shared:
 * only element movement differs between scalar, SSE2, and AVX2 builds. */

static void XX_SORT_IMPL(xx_sort_heap_sift_down)(char *pBase, size_t nRoot, size_t nEnd, size_t nSize, xx_sort_compare_context_fn fnCompare, void *pContext)
{
    while (nRoot <= (nEnd - 1) / 2) {
        size_t nChild = nRoot * 2 + 1;
        size_t nSwap = nRoot;

        if (fnCompare(pBase + nSwap * nSize, pBase + nChild * nSize, pContext) < 0) {
            nSwap = nChild;
        }

        if ((nChild < nEnd) && (fnCompare(pBase + nSwap * nSize, pBase + (nChild + 1) * nSize, pContext) < 0)) {
            nSwap = nChild + 1;
        }

        if (nSwap == nRoot) {
            return;
        }

        xx_sort_swap_bytes(pBase + nRoot * nSize, pBase + nSwap * nSize, nSize);
        nRoot = nSwap;
    }
}

/* In-place heapsort uses constant index state, never allocates, and
 * cannot degrade to quadratic behavior for equal or adversarial keys. */
static void XX_SORT_IMPL(xx_sort_context_impl)(char *pBase, size_t nCount, size_t nSize, xx_sort_compare_context_fn fnCompare, void *pContext)
{
    size_t nStart = nCount / 2;
    size_t nEnd = nCount - 1;

    while (nStart != 0) {
        nStart--;
        XX_SORT_IMPL(xx_sort_heap_sift_down)(pBase, nStart, nEnd, nSize, fnCompare, pContext);
    }

    while (nEnd != 0) {
        xx_sort_swap_bytes(pBase, pBase + nEnd * nSize, nSize);
        nEnd--;
        if (nEnd != 0) {
            XX_SORT_IMPL(xx_sort_heap_sift_down)(pBase, 0, nEnd, nSize, fnCompare, pContext);
        }
    }
}

void XX_SORT_IMPL(xx_sort_context)(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_context_fn fnCompare, void *pContext)
{
    if ((pBase == NULL) || (fnCompare == NULL) || (nCount < 2) || (nSize == 0) || (nCount > ((size_t)-1) / nSize)) {
        return;
    }

    XX_SORT_IMPL(xx_sort_context_impl)((char *)pBase, nCount, nSize, fnCompare, pContext);
}

/* Insertion sort for short runs, median-of-three quicksort above that. */
static void XX_SORT_IMPL(xx_sort_quick_range)(char *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare)
{
    while (nCount > 12) {
        char *pLeft = pBase;
        char *pRight = pBase + (nCount - 1) * nSize;
        char *pMiddle = pBase + (nCount / 2) * nSize;
        size_t nLeftCount = 0;

        if (fnCompare(pMiddle, pLeft) < 0) {
            xx_sort_swap_bytes(pMiddle, pLeft, nSize);
        }

        if (fnCompare(pRight, pMiddle) < 0) {
            xx_sort_swap_bytes(pRight, pMiddle, nSize);

            if (fnCompare(pMiddle, pLeft) < 0) {
                xx_sort_swap_bytes(pMiddle, pLeft, nSize);
            }
        }

        /* Park the pivot at the front and partition the rest. */
        xx_sort_swap_bytes(pMiddle, pBase, nSize);
        pLeft = pBase + nSize;
        pRight = pBase + (nCount - 1) * nSize;

        for (;;) {
            while ((pLeft <= pRight) && (fnCompare(pLeft, pBase) <= 0)) {
                pLeft += nSize;
            }

            while ((pLeft <= pRight) && (fnCompare(pRight, pBase) > 0)) {
                pRight -= nSize;
            }

            if (pLeft > pRight) {
                break;
            }

            xx_sort_swap_bytes(pLeft, pRight, nSize);
            pLeft += nSize;
            pRight -= nSize;
        }

        xx_sort_swap_bytes(pBase, pRight, nSize);

        nLeftCount = (size_t)((pRight - pBase) / (ptrdiff_t)nSize);

        /* Recurse into the smaller side, loop on the larger one. */
        if (nLeftCount < nCount - nLeftCount - 1) {
            XX_SORT_IMPL(xx_sort_quick_range)(pBase, nLeftCount, nSize, fnCompare);
            pBase = pRight + nSize;
            nCount = nCount - nLeftCount - 1;
        } else {
            XX_SORT_IMPL(xx_sort_quick_range)(pRight + nSize, nCount - nLeftCount - 1, nSize, fnCompare);
            nCount = nLeftCount;
        }
    }

    {
        size_t i = 0;

        for (i = 1; i < nCount; i++) {
            size_t j = i;

            while ((j > 0) && (fnCompare(pBase + (j - 1) * nSize, pBase + j * nSize) > 0)) {
                xx_sort_swap_bytes(pBase + (j - 1) * nSize, pBase + j * nSize, nSize);
                j--;
            }
        }
    }
}

void XX_SORT_IMPL(xx_sort_quick)(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare)
{
    if ((pBase == NULL) || (fnCompare == NULL) || (nCount < 2) || (nSize == 0) || (nCount > ((size_t)-1) / nSize) ||
        (nCount * nSize > (size_t)PTRDIFF_MAX)) {
        return;
    }

    XX_SORT_IMPL(xx_sort_quick_range)((char *)pBase, nCount, nSize, fnCompare);
}

void XX_SORT_IMPL(xx_sort_stable)(void *pBase, size_t nCount, size_t nSize, xx_sort_compare_fn fnCompare)
{
    char *pBytes = (char *)pBase;
    size_t i = 0;

    if ((pBase == NULL) || (fnCompare == NULL) || (nCount < 2) || (nSize == 0) || (nCount > ((size_t)-1) / nSize)) {
        return;
    }

    for (i = 1; i < nCount; i++) {
        size_t j = i;

        while ((j > 0) && (fnCompare(pBytes + (j - 1) * nSize, pBytes + j * nSize) > 0)) {
            xx_sort_swap_bytes(pBytes + (j - 1) * nSize, pBytes + j * nSize, nSize);
            j--;
        }
    }
}

