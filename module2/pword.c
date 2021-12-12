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

size_t kmpall(char* s, char* t)
{
    size_t* pref = prefix(s);
    size_t q = 0;
    size_t t_len = strlen(t);
    size_t s_len = strlen(s);
    for (size_t i = 0; i < t_len; i++)
    {
        while (q > 0 && s[q] != t[i])
        {
            q = pref[q - 1];
        }
        if (s[q] == t[i])
            q++;
        if (q == 0)
            return 0;
        if (q == s_len)
            q = pref[q - 1];
    }
    return 1;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        return 0;
    }
    char* s = argv[1];
    char* t = argv[2];
    size_t n = kmpall(s, t);
    if (n)
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}