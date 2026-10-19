/* Private sorting implementation from src/formats/installer/ibm_zpak_installer/xx_ibm_zpak_installer.c. */

static char zpi_fold(char c)
{
    return (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
}

static int zpi_name_compare(const char *a, const char *b)
{
    for (;;) {
        char x = zpi_fold(*a++);
        char y = zpi_fold(*b++);
        if (x != y) return (unsigned char)x < (unsigned char)y ? -1 : 1;
        if (x == '\0') return 0;
    }
}
