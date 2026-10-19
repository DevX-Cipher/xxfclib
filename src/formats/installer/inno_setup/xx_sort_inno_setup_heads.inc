/* Private ordering statements from _mylibs/xxfclib/src/formats/installer/inno_setup/xx_inno_setup.c. */

    /* Stable sort of the heads by chunk start, as the merge sort this
     * replaced was, so the order is unchanged. */
    xx_sort_stable_context(heads, n, sizeof(*heads), inno_head_compare, ctx);
    a = heads;
