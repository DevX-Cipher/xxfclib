/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_ws_swap_nodes(xx_ws_tree *tree, int32_t first, int32_t second)
{
    int32_t weight;
    int32_t child;
    uint8_t is_leaf;

    xx_ws_relink(tree, first, second);
    xx_ws_relink(tree, second, first);

    weight = tree->weight[first];
    child = tree->child[first];
    is_leaf = tree->is_leaf[first];

    tree->weight[first] = tree->weight[second];
    tree->child[first] = tree->child[second];
    tree->is_leaf[first] = tree->is_leaf[second];

    tree->weight[second] = weight;
    tree->child[second] = child;
    tree->is_leaf[second] = is_leaf;
    /* Parents stay with the slots.  Deliberate. */
}
