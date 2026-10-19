/* Private ordering statements from _mylibs/xxfclib/src/formats/common/xx_carrier_helpers.h. */

    for (i = n / 2; i > 0; --i) {
        carrier_sift(r, n, i - 1);
    }
    for (i = n; i > 1; --i) {
        if (carrier_stop(pd)) return false;
        t = r[0];
        r[0] = r[i - 1];
        r[i - 1] = t;
        carrier_sift(r, i - 1, 0);
    }
