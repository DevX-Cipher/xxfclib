/* Private sorting implementation from src/formats/filesystem/adam/xx_adam.c. */

static char adam_fold(char c)
{
    return (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
}
