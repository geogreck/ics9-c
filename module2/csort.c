#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_isspace(int c)
{
    return c >= 0x09 && c <= 0x20;
}

char** get_words(char *src, size_t* amount)
{
    size_t i = 0;
    char** words = malloc(100 * sizeof(char*));
    for (size_t l = 0; l < 100; l++)
    {
        words[l] = malloc(100 * sizeof(char));
    }
    size_t j = 0;
    size_t k = 0;
    while (*(src + i) != 0)
    {
        if (*(src + i) == ' ' && *(src + i - 1) != ' ')
        {
            words[j][k] = 0;
            j++;
            k = 0;
        }else{
            if (*(src + i) != ' ')
            {
                words[j][k] = *(src + i);
                k++;
            }
        }
        i++;
    }
    if (*(src + i - 2) != ' ')
    {
        j++;
    }
    *amount = j;
    return words;
}

int compare(size_t a, size_t b) {
    if (a < b) {
        return 1;
    }
    if (a == b) {
        return 0;
    }
    return -1;
}

void get_string(size_t n, size_t* count, char** words, char* dest) {
    int dest_index = 0;
    for (size_t i = 0; i < n; ++i) 
    {
        size_t j = 0;
        while (count[j] != i) 
        {
            j++;
        }
        for (char* p = words[j]; *p; ++p)
        {
            dest[dest_index] = *p;
            dest_index++;
        }
        dest[dest_index] = ' ';
        dest_index++;
        dest[dest_index] = 0;
    }
}

void csort(char *src, char *dest)
{
    size_t n;
    //char* temp = strcat(src, " ");
    char** s = get_words(src, &n);

    size_t* count = calloc(n, sizeof(size_t));
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (compare(strlen(s[i]), strlen(s[j])) >= 0) {
                count[j]++;
            } else {
                count[i]++;
            }
        }
    }

    get_string(n, count, s, dest);

    for (size_t l = 0; l < 100; l++)
    {
        free(s[l]);
    }
    free(s);
}

int main()
{
    char s[BUFSIZ];
    char new_s[BUFSIZ];
    fgets(s, BUFSIZ, stdin);
    csort(s, new_s);
    printf("%s\n", new_s);
}