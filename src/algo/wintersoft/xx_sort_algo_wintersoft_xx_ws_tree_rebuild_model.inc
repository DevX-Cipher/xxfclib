/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_ws_tree_rebuild(xx_ws_tree *tree)
{
    int32_t destination = tree->next_free - 1;
    int32_t source;
    int32_t i;

    for (i = tree->next_free - 1; i >= XX_WS_ROOT; i--) {
        if (tree->is_leaf[i]) {
            /* (w + 1) >> 1, not w >> 1: a weight of 1 must stay 1. */
            tree->weight[destination] = (tree->weight[i] + 1) >> 1;
            tree->parent[destination] = tree->parent[i];
            tree->child[destination] = tree->child[i];
            tree->is_leaf[destination] = tree->is_leaf[i];
            destination--;
        }
    }

    source = tree->next_free - 2;
    while (destination >= XX_WS_ROOT) {
        int32_t weight;
        int32_t slot;

        if ((source < 0) || ((source + 1) >= XX_WS_NODES)) {
            return;
        }

        weight = tree->weight[source] + tree->weight[source + 1];
        tree->weight[destination] = weight;
        tree->is_leaf[destination] = 0;

        slot = destination + 1;
        while ((slot < XX_WS_NODES) && (weight < tree->weight[slot])) {
            slot++;
        }
        slot--;

        for (i = destination; i < slot; i++) {
            tree->weight[i] = tree->weight[i + 1];
            tree->parent[i] = tree->parent[i + 1];
            tree->child[i] = tree->child[i + 1];
            tree->is_leaf[i] = tree->is_leaf[i + 1];
        }

        tree->weight[slot] = weight;
        tree->child[slot] = source;
        tree->is_leaf[slot] = 0;

        source -= 2;
        destination--;
    }

    for (i = tree->next_free - 1; i >= XX_WS_ROOT; i--) {
        xx_ws_relink(tree, i, i);
    }
}

static void xx_ws_tree_update(xx_ws_tree *tree, int32_t symbol)
{
    int32_t current;

    if (tree->weight[XX_WS_ROOT] == XX_WS_MAX_WEIGHT) {
        xx_ws_tree_rebuild(tree);
    }
    if ((symbol < 0) || (symbol >= XX_WS_SYMBOLS)) {
        return;
    }

    current = tree->leaf[symbol];
    while (current != -1) {
        int32_t fresh;

        if ((current < 0) || (current >= XX_WS_NODES)) {
            return;
        }
        tree->weight[current]++;

        fresh = current;
        while (fresh > XX_WS_ROOT) {
            if (tree->weight[fresh - 1] >= tree->weight[current]) {
                break;
            }
            fresh--;
        }
        if (current != fresh) {
            xx_ws_swap_nodes(tree, current, fresh);
            current = fresh;
        }
        current = tree->parent[current];
    }
}
