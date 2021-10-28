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

int main()
{
    size_t n;
    scanf("%lu ", &n);

    char** s = malloc(n * sizeof(char*));

    for (size_t i = 0; i < n; i++)
    {
        *(s + i) = malloc(BUFSIZ * sizeof(char));
        gets(*(s + i), BUFSIZ);
    }
    char* s_new = concat(s, (int)n);
    puts(s_new);

    for (size_t i = 0; i < n; i++)
    {
        free(*(s + i));
    }
    free(s);
    free(s_new);
    
    return 0;
}