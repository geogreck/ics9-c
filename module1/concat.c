#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n)
{
    size_t m = 1;
    for (size_t i = 0; i < (size_t)n; i++)
    {
        m += strlen(*(s + i));
    }
    char* s_new = malloc(m * sizeof(char));
    size_t buf = 0;
    for (size_t i = 0; i < (size_t)n; i++)
    {
        for (size_t j = 0; j < strlen(*(s + i)); j++)
        {
            *(s_new + buf + j) = *(*(s + i) + j);
        }
        buf += strlen(*(s + i));
    }
    s_new[buf] = 0;
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
        gets(*(s + i));
    }
    char* s_new = concat(s, (int)n);
    printf("%s", s_new);

    for (size_t i = 0; i < n; i++)
    {
        free(*(s + i));
    }
    free(s);
    free(s_new);
    
    return 0;
}