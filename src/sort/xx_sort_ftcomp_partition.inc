/* Private ordering statements from _mylibs/xxfclib/src/formats/ftcomp/xx_ftcomp.c. */

    while (index < XX_FTCOMP_LEAF_END) {
        node[index + 1] = 0U;
        if (node[index] != 0U) {
            if (node[index] == 1U) {
                /* Weight-one symbols stay at the front in symbol order, so
                 * sorting only the tail leaves the whole list sorted. */
                lut[count++] = lut[ones];
                lut[ones++] = (uint16_t)index;
            } else {
                lut[count++] = (uint16_t)index;
            }
        } else {
            last_zero = index;
        }
        index += 4;
    }
