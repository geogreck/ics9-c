#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t* prefix(char* str)
{
    size_t len = strlen(str);
    size_t* pref = malloc(sizeof(size_t) * len);
    pref[0] = 0;
    size_t t = 0;
    for (size_t i = 1; i < len; i++)
    {
        pref[i] = i;
    }
    for (size_t i = 1; i < len; i++)
    {
        while (t > 0 && str[t] != str[i])
        {
            t = pref[t - 1];
        }
        if (str[t] == str[i])
            t++;
        pref[i] = t;
    }
    return pref;
}

size_t kmpall(char* s, char* t, size_t* arr)
{
    size_t* pref = prefix(s);
    size_t q = 0;
    size_t t_len = strlen(t);
    size_t s_len = strlen(s);
    size_t j = 0;
    for (size_t i = 0; i < t_len; i++)
    {
        while (q > 0 && s[q] != t[i])
        {
            q = pref[q - 1];
        }
        if (s[q] == t[i])
            q++;
        if (q == s_len)
            arr[j++] = i - s_len + 1;
    }
    free(pref);
    return j;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        return 0;
    }
    char* s = argv[1];
    char* t = argv[2];
    size_t* arr = malloc(10000 * sizeof(size_t));
    size_t n = kmpall(s, t, arr);
    for (size_t i = 0; i < n; i++)
    {
        printf("%lu ", arr[i]);
    }
    free(arr);
    return 0;
}