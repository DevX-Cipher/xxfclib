/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation included by src/js/xx_js_builtins.c.
 * Retains that translation unit's private types and static linkage.
 */

static int sort_compare(JSCtx *pCtx, JSVal left, JSVal right, JSVal comparator)
{
    /* Undefined values follow all defined values without invoking a user
     * comparator. Missing properties are kept separately when collecting. */
    if (left.tag == JT_UNDEF) return right.tag == JT_UNDEF ? 0 : 1;
    if (right.tag == JT_UNDEF) return -1;

    if (js_is_callable(comparator)) {
        JSVal args[2];
        JSVal result;
        double nResult = 0;

        args[0] = left;
        args[1] = right;
        result = js_call(pCtx, comparator, js_undefined(), 2, args);
        if (!js_has_exception(pCtx)) nResult = js_to_number(pCtx, result);
        js_release(pCtx, result);

        if (nResult < 0) return -1;
        if (nResult > 0) return 1;
        return 0;
    }

    {
        JSVal a = js_to_string(pCtx, left);
        JSVal b = js_undefined();
        int nCmp = 0;
        if (!js_has_exception(pCtx)) b = js_to_string(pCtx, right);
        if (!js_has_exception(pCtx)) {
            size_t nSizeA = js_str_len(a);
            size_t nSizeB = js_str_len(b);
            size_t nMin = nSizeA < nSizeB ? nSizeA : nSizeB;
            nCmp = xx_rt_memcmp(js_str_data(a), js_str_data(b), nMin);
            if (!nCmp) nCmp = nSizeA < nSizeB ? -1 : (nSizeA > nSizeB ? 1 : 0);
        }
        js_release(pCtx, a);
        js_release(pCtx, b);
        return nCmp < 0 ? -1 : (nCmp > 0 ? 1 : 0);
    }
}

static JSVal fn_array_sort(JSCtx *pCtx, JSVal thisVal, int nArgc, JSVal *pArgv, void *pUser)
{
    int64_t nLength = js_array_length(pCtx, thisVal);
    JSVal comparator = ARG(0);
    JSVal *pItems = NULL;
    JSVal *pScratch = NULL;
    JSVal *pSource;
    JSVal *pTarget;
    size_t nItems = 0;
    size_t i, nWidth;
    char sKey[32];

    (void)pUser;

    if (js_has_exception(pCtx)) return js_undefined();
    if (comparator.tag != JT_UNDEF && !js_is_callable(comparator)) {
        return js_throw(pCtx, "TypeError: comparison function must be callable or undefined");
    }
    if (nLength <= 1) return js_dup(thisVal);
    if (nLength > JS_MAX_SORT_ITEMS) {
        return js_throw(pCtx, "RangeError: array is too large to sort");
    }

    pItems = (JSVal *)xx_js_malloc((size_t)nLength * sizeof(JSVal));
    for (i = 0; i < (size_t)nLength; i++) {
        JSVal item = js_get_index(pCtx, thisVal, (int64_t)i);
        int bPresent = 1;
        if (js_has_exception(pCtx)) { js_release(pCtx, item); goto failed; }
        if (item.tag == JT_UNDEF && thisVal.tag == JT_OBJ) {
            size_t nKeySize = (size_t)xx_rt_snprintf(sKey, sizeof(sKey), "%llu", (unsigned long long)i);
            bPresent = jsobj_has(pCtx, thisVal.u.o, sKey, nKeySize);
        }
        if (bPresent) pItems[nItems++] = item;
        else js_release(pCtx, item);
    }

    pScratch = (JSVal *)xx_js_malloc((nItems ? nItems : 1) * sizeof(JSVal));
    pSource = pItems;
    pTarget = pScratch;
    /* Stable bottom-up mergesort. The complete source buffer owns the items;
     * the destination only borrows them until a complete pass has finished.
     * Thus a throwing comparator can never duplicate or lose references. */
    for (nWidth = 1; nWidth < nItems; nWidth *= 2) {
        size_t nBegin;
        for (nBegin = 0; nBegin < nItems; nBegin += nWidth * 2) {
            size_t nMid = nBegin + nWidth;
            size_t nEnd = nBegin + nWidth * 2;
            size_t nLeft = nBegin, nRight, nOut = nBegin;
            if (nMid > nItems) nMid = nItems;
            if (nEnd > nItems) nEnd = nItems;
            nRight = nMid;
            if (nMid == nEnd) {
                xx_rt_memcpy(pTarget + nBegin, pSource + nBegin, (nEnd - nBegin) * sizeof(JSVal));
                continue;
            }
            if (sort_compare(pCtx, pSource[nMid - 1], pSource[nMid], comparator) <= 0) {
                if (js_has_exception(pCtx)) goto compare_failed;
                xx_rt_memcpy(pTarget + nBegin, pSource + nBegin, (nEnd - nBegin) * sizeof(JSVal));
                continue;
            }
            if (js_has_exception(pCtx)) goto compare_failed;
            while (nLeft < nMid && nRight < nEnd) {
                int nCmp = sort_compare(pCtx, pSource[nLeft], pSource[nRight], comparator);
                if (js_has_exception(pCtx)) goto compare_failed;
                pTarget[nOut++] = pSource[nCmp <= 0 ? nLeft++ : nRight++];
            }
            while (nLeft < nMid) pTarget[nOut++] = pSource[nLeft++];
            while (nRight < nEnd) pTarget[nOut++] = pSource[nRight++];
        }
        { JSVal *pSwap = pSource; pSource = pTarget; pTarget = pSwap; }
    }

    for (i = 0; i < nItems; i++) js_set_index(pCtx, thisVal, (int64_t)i, pSource[i]);
    /* Holes follow undefined values and stay absent, rather than becoming
     * enumerable properties containing undefined. */
    if (thisVal.tag == JT_OBJ) {
        for (i = nItems; i < (size_t)nLength; i++) {
            xx_rt_snprintf(sKey, sizeof(sKey), "%llu", (unsigned long long)i);
            jsobj_del(pCtx, thisVal.u.o, sKey);
        }
    }
    xx_js_free(pItems);
    xx_js_free(pScratch);
    return js_dup(thisVal);

compare_failed:
    for (i = 0; i < nItems; i++) js_release(pCtx, pSource[i]);
    xx_js_free(pItems);
    xx_js_free(pScratch);
    return js_undefined();
failed:
    for (i = 0; i < nItems; i++) js_release(pCtx, pItems[i]);
    xx_js_free(pItems);
    return js_undefined();
}
