/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool xx_lzpis2_huffman_rebuild(xx_lzpis2_huffman *tree)
{
    unsigned source;
    unsigned destination = 0U;
    unsigned left;
    unsigned node;
    if (!tree) return false;

    for (source = 0U; source < XX_LZPIS2_TREE_NODE_COUNT; ++source) {
        if (tree->child[source] >= XX_LZPIS2_TREE_NODE_COUNT) {
            if (destination >= XX_LZPIS2_SYMBOL_COUNT) return false;
            tree->frequency[destination] = (uint16_t)((tree->frequency[source] + 1U) / 2U);
            tree->child[destination] = tree->child[source];
            ++destination;
        }
    }
    if (destination != XX_LZPIS2_SYMBOL_COUNT) return false;

    left = 0U;
    for (node = XX_LZPIS2_SYMBOL_COUNT; node < XX_LZPIS2_TREE_NODE_COUNT; ++node) {
        uint16_t sum = (uint16_t)(tree->frequency[left] + tree->frequency[left + 1U]);
        unsigned insert = node;
        unsigned move;
        while (insert > 0U && sum < tree->frequency[insert - 1U]) {
            --insert;
        }
        for (move = node; move > insert; --move) {
            tree->frequency[move] = tree->frequency[move - 1U];
            tree->child[move] = tree->child[move - 1U];
        }
        tree->frequency[insert] = sum;
        tree->child[insert] = (uint16_t)left;
        left += 2U;
    }

    for (node = 0U; node < XX_LZPIS2_TREE_NODE_COUNT; ++node) {
        uint16_t first = tree->child[node];
        if (first >= XX_LZPIS2_TREE_NODE_COUNT + XX_LZPIS2_SYMBOL_COUNT) {
            return false;
        }
        tree->parent[first] = (uint16_t)node;
        if (first < XX_LZPIS2_TREE_NODE_COUNT) {
            tree->parent[first + 1U] = (uint16_t)node;
        }
    }
    return true;
}

static bool xx_lzpis2_huffman_update(xx_lzpis2_huffman *tree, unsigned symbol)
{
    unsigned node;
    unsigned steps = 0U;
    if (!tree || symbol >= XX_LZPIS2_SYMBOL_COUNT) return false;
    if (tree->frequency[XX_LZPIS2_TREE_ROOT] == XX_LZPIS2_REBUILD_FREQUENCY && !xx_lzpis2_huffman_rebuild(tree)) {
        return false;
    }
    /* Walk from the symbol's leaf slot up to the root, incrementing each
     * frequency and restoring the sibling ordering.  This must be a do/while:
     * parent[symbol + TREE_NODE_COUNT] is initialised to `symbol`, so for
     * symbol 0 the starting node is legitimately 0 and a leading `while`
     * test skipped the update entirely, desynchronising the adaptive tree
     * from the encoder on the first occurrence of symbol 0. */
    node = tree->parent[symbol + XX_LZPIS2_TREE_NODE_COUNT];
    do {
        uint16_t updated;
        unsigned candidate;
        if (node >= XX_LZPIS2_TREE_NODE_COUNT || ++steps > XX_LZPIS2_TREE_NODE_COUNT) {
            return false;
        }
        updated = (uint16_t)(tree->frequency[node] + 1U);
        tree->frequency[node] = updated;
        candidate = node + 1U;
        if (candidate > XX_LZPIS2_TREE_NODE_COUNT) return false;
        if (updated > tree->frequency[candidate]) {
            uint16_t moved_child;
            uint16_t displaced_child;
            while (candidate < XX_LZPIS2_TREE_NODE_COUNT && updated > tree->frequency[candidate]) {
                ++candidate;
            }
            --candidate;
            moved_child = tree->child[node];
            displaced_child = tree->child[candidate];
            tree->frequency[node] = tree->frequency[candidate];
            tree->frequency[candidate] = updated;
            tree->child[node] = displaced_child;
            tree->child[candidate] = moved_child;
            if (moved_child >= XX_LZPIS2_TREE_NODE_COUNT + XX_LZPIS2_SYMBOL_COUNT || displaced_child >= XX_LZPIS2_TREE_NODE_COUNT + XX_LZPIS2_SYMBOL_COUNT) {
                return false;
            }
            tree->parent[moved_child] = (uint16_t)candidate;
            if (moved_child < XX_LZPIS2_TREE_NODE_COUNT) {
                tree->parent[moved_child + 1U] = (uint16_t)candidate;
            }
            tree->parent[displaced_child] = (uint16_t)node;
            if (displaced_child < XX_LZPIS2_TREE_NODE_COUNT) {
                tree->parent[displaced_child + 1U] = (uint16_t)node;
            }
            node = candidate;
        }
        node = tree->parent[node];
    } while (node != 0U);
    return true;
}
