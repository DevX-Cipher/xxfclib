/* Private sorting implementation from src/formats/filesystem/adam/xx_adam.c. */

static int adam_compare_names(const void *left, const void *right, void *context)
{
    const adam_member *a = *(const adam_member *const *)left;
    const adam_member *b = *(const adam_member *const *)right;
    size_t index;
    (void)context;
    for (index = 0U; index < ADAM_NAME_BUFFER; ++index) {
        char x = adam_fold(a->name[index]);
        char y = adam_fold(b->name[index]);
        if (x != y) return (unsigned char)x < (unsigned char)y ? -1 : 1;
        if (x == 0) break;
    }
    return a->entry < b->entry ? -1 : (a->entry > b->entry ? 1 : 0);
}
