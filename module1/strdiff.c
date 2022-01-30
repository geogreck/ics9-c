#include <stdio.h>
#include <stdlib.h>

size_t strnlen ( const char *s , size_t n)
{
    size_t len;
    for ( len = 0; len < n && s[ len ]; len ++);
    return len ;
}

size_t min(size_t a, size_t b)
{
    return a > b ? b: a;
}

int strdiff(char *a, char *b)
{
    size_t i = 0;
    size_t len = min(strnlen(a, BUFSIZ), strnlen(b, BUFSIZ)) + 1;
    while (i < len && (*(a + i) == *(b + i)))
    {
        i++;
    }
    if (i == len)
        return -1;
    int j = 0;
    while (j < 8 && (*(a + i) & (1 << j)) == (*(b + i) & (1 << j)))
    {
        j++;
    }
    return (int)i * 8 + j;
}

int main()
{
    printf("%d\n", strdiff("T", "The"));

    return 0;
}