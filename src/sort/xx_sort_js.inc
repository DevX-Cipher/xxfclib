/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation included by src/js/xx_js_builtins.c.
 * Retains that translation unit's private types and static linkage.
 */

static int sort_compare(JSCtx *pCtx, JSVal left, JSVal right, JSVal comparator)
{
    if (js_is_callable(comparator)) {
        JSVal args[2];
        JSVal result;
        double nResult = 0;

        args[0] = left;
        args[1] = right;
        result = js_call(pCtx, comparator, js_undefined(), 2, args);
        nResult = js_to_number(pCtx, result);
        js_release(pCtx, result);

        if (nResult < 0) {
            return -1;
        }

        if (nResult > 0) {
            return 1;
        }

        return 0;
    }

    {
        JSVal a = js_to_string(pCtx, left);
        JSVal b = js_to_string(pCtx, right);
        size_t nSizeA = js_str_len(a);
        size_t nSizeB = js_str_len(b);
        size_t nMin = (nSizeA < nSizeB) ? nSizeA : nSizeB;
        int nCmp = xx_rt_memcmp(js_str_data(a), js_str_data(b), nMin);

        if (nCmp == 0) {
            nCmp = (nSizeA < nSizeB) ? -1 : ((nSizeA > nSizeB) ? 1 : 0);
        }

        js_release(pCtx, a);
        js_release(pCtx, b);

        return (nCmp < 0) ? -1 : ((nCmp > 0) ? 1 : 0);
    }
}

static JSVal fn_array_sort(JSCtx *pCtx, JSVal thisVal, int nArgc, JSVal *pArgv, void *pUser)
{
    int64_t nLength = js_array_length(pCtx, thisVal);
    JSVal comparator = ARG(0);
    JSVal *pItems = NULL;
    int64_t i = 0;
    int64_t j = 0;

    (void)pUser;

    if (nLength <= 1) {
        return js_dup(thisVal);
    }

    /* A nominal length far beyond the number of stored elements would wrap
     * the multiplication below; refuse it instead of allocating.          */
    if (nLength > JS_MAX_SORT_ITEMS) {
        return js_throw(pCtx, "RangeError: array is too large to sort");
    }

    pItems = (JSVal *)xx_js_malloc((size_t)nLength * sizeof(JSVal));

    for (i = 0; i < nLength; i++) {
        pItems[i] = js_get_index(pCtx, thisVal, i);
    }

    /* Insertion sort: stable and adequate for the small arrays used here. */
    for (i = 1; i < nLength; i++) {
        JSVal key = pItems[i];

        j = i - 1;

        while ((j >= 0) && (sort_compare(pCtx, pItems[j], key, comparator) > 0)) {
            pItems[j + 1] = pItems[j];
            j--;
        }

        pItems[j + 1] = key;
    }

    for (i = 0; i < nLength; i++) {
        js_set_index(pCtx, thisVal, i, pItems[i]);
    }

    xx_js_free(pItems);

    return js_dup(thisVal);
}

