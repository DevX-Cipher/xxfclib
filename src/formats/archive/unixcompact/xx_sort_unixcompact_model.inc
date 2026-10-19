/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_unixcompact_relink(xx_unixcompact_tree *tree, int node, int child_index, int value, int new_parent, uint32_t new_index)
{
    const uint32_t mask = (child_index == 0) ? XX_UNIXCOMPACT_LEAF0 : XX_UNIXCOMPACT_LEAF1;

    if ((mask & tree->nodes[node].flags) == 0U) {
        tree->nodes[value].parent = new_parent;
        tree->nodes[value].flags &= ~XX_UNIXCOMPACT_ISRIGHT;
        if (new_index != 0U) tree->nodes[value].flags |= new_index;
    } else {
        tree->leaf_node[value] = new_parent;
        tree->leaf_info[value] &= ~1;
        if (new_index != 0U) tree->leaf_info[value] |= (int)new_index;
    }
}

/* Add one to @p symbol's weight and to every weight above it, restoring the
 * slot ordering as it goes. */
static void xx_unixcompact_tree_update(xx_unixcompact_tree *tree, int symbol)
{
    int node = tree->leaf_node[symbol];
    uint32_t index = (uint32_t)tree->leaf_info[symbol];

    if (node < 0) return;
    for (;;) {
        int count;
        int old_block;
        /* "above" is the slot before this one in the array, which is the
         * heavier neighbour; "below" is the lighter one after it. */
        int above_count = 0;
        int above_block = 0;
        int below_count = 0;
        int below_block = -1;
        int below_node = 0;

        index &= 1U;
        tree->nodes[node].child[index].count += 1;
        count = tree->nodes[node].child[index].count;
        old_block = tree->nodes[node].child[index].block;

        for (;;) {
            int leader;
            int leader_index;
            uint32_t is_right;
            int moved_in;
            int moved_out;
            uint32_t mask_here;
            uint32_t mask_there;

            if (index != 0U) {
                below_node = node + 1;
                if (node == tree->last_node) {
                    /* Nothing lighter exists; make the tests below behave as
                     * if the neighbour were two lighter. */
                    below_count = count - 2;
                    below_block = -1;
                } else {
                    below_count = tree->nodes[node + 1].child[0].count;
                    below_block = tree->nodes[node + 1].child[0].block;
                }
                above_count = tree->nodes[node].child[0].count;
                above_block = tree->nodes[node].child[0].block;
            } else {
                below_node = node;
                below_count = tree->nodes[node].child[1].count;
                below_block = tree->nodes[node].child[1].block;
                if (node != 0) {
                    above_count = tree->nodes[node - 1].child[1].count;
                    above_block = tree->nodes[node - 1].child[1].block;
                } else {
                    /* The first slot of all: nothing can be heavier. */
                    above_count = count + 1;
                    above_block = 0;
                }
            }

            if (count <= above_count) break;

            /* Swap with the leader of the block just above. The leader is
             * that block's first slot: slot 0 of its node unless slot 0 is
             * already too heavy to be in the block. */
            leader = tree->blocks[above_block].node;
            leader_index = (count <= tree->nodes[leader].child[0].count) ? 1 : 0;
            is_right = (uint32_t)leader_index;
            moved_in = tree->nodes[leader].child[leader_index].value;
            moved_out = tree->nodes[node].child[index].value;
            tree->nodes[leader].child[leader_index].value = moved_out;
            tree->nodes[node].child[index].value = moved_in;
            xx_unixcompact_relink(tree, leader, leader_index, moved_in, node, index);
            xx_unixcompact_relink(tree, node, (int)index, moved_out, leader, is_right);
            mask_here = (index == 0U) ? XX_UNIXCOMPACT_LEAF0 : XX_UNIXCOMPACT_LEAF1;
            mask_there = (is_right == 0U) ? XX_UNIXCOMPACT_LEAF0 : XX_UNIXCOMPACT_LEAF1;
            /* Both sides normalise to the same bit position, so this is just
             * "the two slots disagree about being a leaf". */
            if (((tree->nodes[node].flags & mask_here) << index) != ((tree->nodes[leader].flags & mask_there) << is_right)) {
                tree->nodes[node].flags ^= mask_here;
                tree->nodes[leader].flags ^= mask_there;
            }
            /* The weights stay with the positions, not with the contents. */
            tree->nodes[leader].child[leader_index].count += 1;
            tree->nodes[node].child[index].count -= 1;
            node = leader;
            index = is_right;
            /* The block just lost its first slot to a heavier weight. Its
             * leader moves on, and only crosses into the next node when the
             * slot it lost was the node's second. */
            if (is_right != 0U) tree->blocks[above_block].node += 1;
        }

        if (count == above_count) {
            /* Joins the block above. */
            tree->nodes[node].child[index].block = above_block;
            if (below_count + 1 < count) {
                /* It was alone in its old block, which now disappears. */
                tree->blocks[above_block].next = below_block;
                tree->blocks[old_block].next = tree->block_free;
                tree->block_free = old_block;
            } else if (below_block >= 0) {
                tree->blocks[below_block].node = below_node;
            }
        } else if (count == below_count + 1) {
            /* It left the block it shared with the slot below and is not
             * heavy enough for the one above: it needs a block of its own. */
            int fresh = tree->block_free;
            if (fresh < 0) return;
            tree->block_free = tree->blocks[fresh].next;
            tree->blocks[fresh].next = below_block;
            tree->blocks[fresh].node = node;
            tree->blocks[above_block].next = fresh;
            if (below_block >= 0) tree->blocks[below_block].node = below_node;
            tree->nodes[node].child[index].block = fresh;
        }

        index = tree->nodes[node].flags;
        node = tree->nodes[node].parent;
        if (node < 0) return;
    }
}
