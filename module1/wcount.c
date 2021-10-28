#include <stdio.h>
#include <stdlib.h>

size_t strnlen ( const char *s , size_t n)
{
    size_t len ;
    for ( len = 0; len < n && s[ len ]; len ++);
    return len ;
}

int wcount(char *s)
{
    int count = 0;
    int cur_count = 0;

    for (size_t i = 0; i < strnlen(s, BUFSIZ); i++)
    {
        if (*(s + i) == ' ')
        {
            if (cur_count)
            {
                count++;
                cur_count = 0;
            } 
            else 
            {
                continue;
            }
        }
        else
        {
            cur_count++;
        }
    }
    
    if (cur_count)
        count++;
    
    return count;
}

int main()
{
    char* s = malloc(BUFSIZ * sizeof(char));
    gets(s);
    printf("%d\n", wcount(s));

    free(s);
}