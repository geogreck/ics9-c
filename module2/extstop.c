#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t** delta1(char* str, size_t n)
{
    size_t len = strlen(str);
    size_t** del1 = (size_t**)calloc(len, sizeof(size_t*));
    for(size_t i = 0; i < len; i++)
    {
        del1[i] = (size_t*)malloc(sizeof(size_t) * n);
    }
    for(size_t i = 0; i < len; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            del1[i][j] = len;
        }
    }
    for(size_t i = 0; i < len; i++)
    {
        for(size_t j = 0; j < len - i; j++)
        {
            del1[i][(int)str[j]] = len - j - 1;
        }
    }
    return del1;
}

size_t BMSubst(char* s, char* t)
{ 
    size_t** del1 = delta1(s, 123);
    size_t len_s = strlen(s);
    size_t i = 0;
    size_t k = len_s - 1;
    size_t len_t = strlen(t);
    while(k < len_t)
    {
        i = len_s - 1;
        while(t[k] == s[i])
        {
            if (i == 0)
            {
                for (i = 0; i < len_s; i++)
                {
                    free(del1[i]);
                }
                free(del1);
                return k;
            }
            i--;
            k--;
        }
        k += del1[len_s - i - 1][(size_t)t[k]];        
    }
    for (i = 0; i < len_s; i++)
        free(del1[i]);
    free(del1); 
    return len_t;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        return 0;
    }
    char* s = argv[1];
    char* t = argv[2];
    size_t n = BMSubst(s, t);
    printf("%lu\n", n);
    return 0;
}