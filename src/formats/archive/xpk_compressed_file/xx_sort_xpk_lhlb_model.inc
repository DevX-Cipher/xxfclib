/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * Copyright (c) 2017-2026 Teemu Suutari
 * SPDX-License-Identifier: MIT AND BSD-2-Clause
 * Bounded native C adaptation of Ancient LHDecompressor.cpp and
 * DynamicHuffmanDecoder.hpp at commit
 * 61cd9088a218ce43fd389f3f3c48f35fc70f7834. See LICENSE.ancient.
 */

/* Private adaptive frequency ordering; retain the original tie behavior. */

static bool xpk_lhlb_update(xpk_lhlb_tree *tree, uint32_t code)
{
    while (code != XPK_LHLB_NODES - 1U) {
        uint32_t index, destination, other, frequency;
        if (code >= XPK_LHLB_NODES) return false;
        frequency = ++tree->node[code].frequency;
        index = tree->node[code].index;
        destination = index;
        if (index >= XPK_LHLB_NODES) return false;
        while (destination != XPK_LHLB_NODES - 1U && frequency > tree->node[tree->map[destination + 1U]].frequency) ++destination;
        if (index != destination) {
            uint32_t *left, *right, temp;
            other = tree->map[destination];
            if (other >= XPK_LHLB_NODES || tree->node[code].parent >= XPK_LHLB_NODES || tree->node[other].parent >= XPK_LHLB_NODES) return false;
            left = tree->node[tree->node[code].parent].child;
            right = tree->node[tree->node[other].parent].child;
            left = &left[left[0] == code ? 0 : 1];
            right = &right[right[0] == other ? 0 : 1];
            temp = tree->node[code].index;
            tree->node[code].index = tree->node[other].index;
            tree->node[other].index = temp;
            temp = tree->map[index];
            tree->map[index] = tree->map[destination];
            tree->map[destination] = temp;
            temp = *left;
            *left = *right;
            *right = temp;
            temp = tree->node[code].parent;
            tree->node[code].parent = tree->node[other].parent;
            tree->node[other].parent = temp;
        }
        code = tree->node[code].parent;
    }
    ++tree->node[code].frequency;
    return true;
}
