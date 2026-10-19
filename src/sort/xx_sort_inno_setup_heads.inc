/* Private ordering statements from _mylibs/xxfclib/src/formats/inno_setup/xx_inno_setup.c. */

    /* Stable merge sort of the heads by chunk start. */
    a = heads;
    b = tmp;
    for (width = 1U; width<n; width = width> n / 2U ? n : width * 2U) {
        uint32_t lo;
        for (lo = 0U; lo < n; lo = n - lo <= 2U * width ? n : lo + 2U * width) {
            uint32_t mid = n - lo < width ? n : lo + width;
            uint32_t hi = n - mid < width ? n : mid + width, p = lo, q = mid, o = lo;
            while (p < mid && q < hi) b[o++] = inno_head_before(ctx, a[q], a[p]) ? a[q++] : a[p++];
            while (p < mid) b[o++] = a[p++];
            while (q < hi) b[o++] = a[q++];
        }
        {
            uint32_t *t = a;
            a = b;
            b = t;
        }
    }
