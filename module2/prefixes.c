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

int is_repeatable_substr(char* str)
{
    size_t len = strlen(str);
    char* spref = malloc(sizeof(char) *(len + 1));
    strcpy(spref, str);
    char* temp = malloc(sizeof(char) * (len * 2 + 1));
    strcpy(temp, str + 1);
    strcat(temp, spref);
    if (strstr(temp, spref) != (temp + len - 1))
    {   
        free(spref);
        free(temp);
        return 1;
    }
    free(spref);
    free(temp);
    return 0;
}

size_t find_repeatable_sub(char* str)
{
    size_t len = strlen(str);
    char* sub = calloc(sizeof(char), len);
    size_t i;
    for (i = 1; i < len / 2; i++)
    {
        strcpy(sub, str + i);
        if (is_repeatable_substr(sub))
        {
            free(sub);
            return i;
        }
    }
    free(sub);
    return i;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        return 0;
    }
    char* str = argv[1];
    size_t* pref = prefix(str);
    size_t len = strlen(str);
    for(size_t i = 1; i < len; i++)
    {
        if (pref[i] >= 2)
        {
            char* spref = malloc(sizeof(char) * (pref[i] + 1));
            strncpy(spref, str, pref[i]);
            spref[pref[i]] = 0;
            if (is_repeatable_substr(spref))
            {   
                printf("%lu %lu\n", pref[i], strlen(spref) / find_repeatable_sub(spref));
            }
            free(spref);
        }
    }
    if (is_repeatable_substr(str))
            {   
                printf("%lu %lu\n", len, len / find_repeatable_sub(str));
            }

    free(pref);
    return 0;
}