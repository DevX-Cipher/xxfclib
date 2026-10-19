/* Private ordering statements from _mylibs/xxfclib/src/formats/ihex/xx_ihex.c. */

    for (index = count / 2U; index-- > 0U;) {
        xx_ihexfmt_sift_down(scan->blocks, order, index, count);
    }
    for (index = count - 1U; index > 0U; --index) {
        uint32_t swap = order[0];
        order[0] = order[index];
        order[index] = swap;
        xx_ihexfmt_sift_down(scan->blocks, order, 0U, index);
    }
