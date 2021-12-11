#include <stdio.h>
#include <stdlib.h>

size_t strnlen ( const char *s , size_t n)
{
    size_t len ;
    for ( len = 0; len < n && s[ len ]; len ++);
    return len ;
}

char *concat(char **s, int n)
{
    size_t m = 0;
    for (size_t i = 0; i < (size_t)n; i++)
    {
        m += strnlen(*(s + i), sizeof(*(s + i)));
    }

    char* s_new = malloc(m * sizeof(char));
    if (!s_new)
    {
        perror("malloc");
    }
    size_t buf = 0;
    for (size_t i = 0; i < (size_t)n; i++)
    {
        for (size_t j = 0; j < strnlen(*(s + i), sizeof(*(s + i))); j++)
        {
            *(s_new + buf + j) = *(*(s + i) + j);
        }
        buf += strnlen(*(s + i), sizeof(*(s + i)));
    }
    return s_new;
}

char* fibstr(int n)
{
    char* a = "a";
    char* b = "b";
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    for (size_t i = 0; i < (size_t)n - 2; i++)
    {
        char* t = b;
        char* s_temp[2]= {a, b};
        b = concat(s_temp, 2);
        a = t;
    }

    return b;
}

int main()
{
    char* s = fibstr(5);
    puts(s);
    free(s);
}