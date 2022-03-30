#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}

size_t* suffix(char* str)
{
    size_t len = strlen(str);
    size_t* suf = malloc(sizeof(size_t) * len);
    size_t t = len - 1;
    for (size_t i = 0; i < len; i++)
    {
        suf[i] = i;
    }
    for(size_t i = len - 1; i > 0; i--)
    {
        while (t < len - 1 && str[t] != str[i - 1])
        {
            t = suf[t + 1];
        }
        if (str[t] == str[i - 1])
            t--;
        suf[i - 1] = t;
    }
    return suf;
}

size_t* delta1(char* str, size_t n)
{
    size_t* del1 = calloc(n, sizeof(size_t));
    size_t len = strlen(str);
    for (size_t i = 0; i < n; i++)
    {
        del1[i] = len;
    }
    for (size_t i = 0; i < len; i++)
    {
        del1[(int)str[i]] = len - i - 1;
    }
    return del1;
}

size_t* delta2(char* str)
{
    size_t len = strlen(str);
    size_t* del2 = calloc(len, sizeof(size_t));
    size_t* suf = suffix(str);
    size_t t = suf[0];
    for (size_t i = 0; i < len; i++)
    {
        while (t < i)
        {
            t = suf[t + 1];
        }
        del2[i] =t + len - i;
    }
    for (size_t i = 0; i < len - 1; i++)
    {
        t = i;
        while (t < len - 1)
        {
            t = suf[t + 1];
            if (str[i] != str[t])
            del2[t] = len - (i + 1);
        }
    }
    free(suf);
    return del2;
}

void BMSubst(char* s, size_t n, char* t)
{
    size_t* del1 = delta1(s, n);
    size_t* del2 = delta2(s);
    size_t s_len = strlen(s);
    size_t t_len = strlen(t);   
    size_t k = s_len - 1;
    while (k < t_len)
    {
        size_t i = s_len - 1;
        while (t[k] == s[i])
        {
            if (i == 0)
            {
                printf("%lu ", k);
                break;
            }
            i--;
            k--;
        }
        k += max(del1[(int)t[k]], del2[i]);
    }
    free(del1);
    free(del2);
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        return 0;
    }
    char* s = argv[1];
    char* t = argv[2];
    BMSubst(s, 123, t);
    return 0;
}