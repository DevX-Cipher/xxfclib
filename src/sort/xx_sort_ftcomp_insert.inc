/* Private ordering statements from _mylibs/xxfclib/src/formats/ftcomp/xx_ftcomp.c. */

    while (alive != 2) {
        int32_t bound = head + 2, insert = (count + head + 2) >> 1;
        int32_t top = count, moved;
        uint32_t weight;
        uint16_t first, second;
        --alive;
        first = lut[head];
        second = lut[head + 1];
        ++head;
        weight = (uint32_t)node[first] + (uint32_t)node[second];
        if (bound < count) {
            for (;;) {
                if ((uint32_t)node[lut[insert]] < weight) {
                    bound = insert + 1;
                    insert = top;
                }
                top = insert;
                insert = (top + bound) >> 1;
                if (bound >= top) break;
            }
            insert = (top + bound) >> 1;
        }
        moved = insert - head - 1;
        if (insert < 1 || insert > count || free_node + 3 >= XX_FTCOMP_NODE_WORDS) return false;
        if (moved > 0) {
            int32_t k;
            for (k = 0; k < moved; ++k) lut[head + k] = lut[head + k + 1];
        }
        lut[insert - 1] = (uint16_t)free_node;
        node[free_node] = (uint16_t)weight;
        node[free_node + 1] = 0U;
        node[free_node + 2] = first;
        node[free_node + 3] = second;
        node[first + 1] = (uint16_t)free_node;
        node[second + 1] = (uint16_t)free_node;
        free_node += 4;
    }
