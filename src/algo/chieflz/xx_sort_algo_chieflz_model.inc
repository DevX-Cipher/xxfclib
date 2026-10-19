/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool chieflz_update(chieflz_model *model, uint32_t node)
{
    uint32_t parent;
    uint32_t sibling;
    uint32_t step;
    if (!model || !chieflz_node_valid(node)) return false;
    ++model->frequency[node];
    parent = model->parent[node];
    if (!chieflz_node_valid(parent)) return false;
    if (parent == CHIEFLZ_ROOT) return true;
    sibling = model->child0[parent];
    if (sibling == node) sibling = model->child1[parent];
    if (!chieflz_node_valid(sibling) || !chieflz_propagate(model, node, sibling)) return false;

    for (step = 0U; step <= CHIEFLZ_NODES; ++step) {
        uint32_t grand = model->parent[parent];
        uint32_t left;
        uint32_t uncle;
        if (!chieflz_node_valid(grand)) return false;
        left = model->child0[grand];
        uncle = parent == left ? model->child1[grand] : left;
        if (!chieflz_node_valid(uncle)) return false;
        if (model->frequency[uncle] < model->frequency[node]) {
            uint32_t node_sibling;
            if (parent == left) model->child1[grand] = (uint16_t)node;
            else model->child0[grand] = (uint16_t)node;
            node_sibling = model->child0[parent];
            if (node == node_sibling) {
                node_sibling = model->child1[parent];
                model->child0[parent] = (uint16_t)uncle;
            } else {
                model->child1[parent] = (uint16_t)uncle;
            }
            if (!chieflz_node_valid(node_sibling)) return false;
            model->parent[uncle] = (uint16_t)parent;
            model->parent[node] = (uint16_t)grand;
            if (!chieflz_propagate(model, uncle, node_sibling)) return false;
            node = uncle;
        }
        node = model->parent[node];
        if (!chieflz_node_valid(node)) return false;
        parent = model->parent[node];
        if (!chieflz_node_valid(parent)) return false;
        if (parent == CHIEFLZ_ROOT) return true;
    }
    return false;
}
