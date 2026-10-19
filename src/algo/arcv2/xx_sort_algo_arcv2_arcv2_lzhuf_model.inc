/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool arcv2_lzhuf_reconstruct(arcv2_lzhuf_model *model)
{
    uint32_t leaf_count = 0U;
    uint32_t index;
    if (!model) return false;
    for (index = 0U; index < model->tree_size; ++index) {
        if (model->child[index] >= model->tree_size) {
            if (leaf_count >= model->character_count) return false;
            model->frequency[leaf_count] = (model->frequency[index] + 1U) / 2U;
            model->child[leaf_count] = model->child[index];
            ++leaf_count;
        }
    }
    if (leaf_count != model->character_count) return false;
    for (index = 0U; index < model->character_count - 1U; ++index) {
        uint32_t node = model->character_count + index;
        uint32_t sum = model->frequency[index * 2U] + model->frequency[index * 2U + 1U];
        uint32_t insertion = node;
        uint32_t move;
        while (insertion != 0U && sum < model->frequency[insertion - 1U]) --insertion;
        for (move = node; move > insertion; --move) {
            model->frequency[move] = model->frequency[move - 1U];
            model->child[move] = model->child[move - 1U];
        }
        model->frequency[insertion] = sum;
        model->child[insertion] = index * 2U;
    }
    for (index = 0U; index < model->tree_size; ++index) {
        uint32_t node = model->child[index];
        if (node >= sizeof(model->parent) / sizeof(model->parent[0])) return false;
        model->parent[node] = index;
        if (node < model->tree_size) {
            if (node + 1U >= sizeof(model->parent) / sizeof(model->parent[0])) return false;
            model->parent[node + 1U] = index;
        }
    }
    return true;
}

static bool arcv2_lzhuf_update(arcv2_lzhuf_model *model, uint32_t character)
{
    uint32_t current;
    uint32_t guard = 0U;
    if (!model || character >= model->character_count) return false;
    if (model->frequency[model->root] == model->maximum_frequency && !arcv2_lzhuf_reconstruct(model)) return false;
    current = model->parent[character + model->tree_size];
    do {
        uint32_t updated;
        uint32_t next;
        if (current >= model->tree_size || guard++ > model->tree_size) return false;
        updated = ++model->frequency[current];
        next = current + 1U;
        if (next > model->tree_size) return false;
        if (updated > model->frequency[next]) {
            while (next + 1U <= model->tree_size && updated > model->frequency[next + 1U]) ++next;
            {
                uint32_t old_child = model->child[current];
                uint32_t new_child = model->child[next];
                if (old_child >= sizeof(model->parent) / sizeof(model->parent[0]) || new_child >= sizeof(model->parent) / sizeof(model->parent[0])) return false;
                model->frequency[current] = model->frequency[next];
                model->frequency[next] = updated;
                model->parent[old_child] = next;
                if (old_child < model->tree_size) model->parent[old_child + 1U] = next;
                model->child[next] = old_child;
                model->parent[new_child] = current;
                if (new_child < model->tree_size) model->parent[new_child + 1U] = current;
                model->child[current] = new_child;
                current = next;
            }
        }
        current = model->parent[current];
    } while (current != 0U);
    return true;
}
