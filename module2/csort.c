#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ft_isspace(int c)
{
    return c >= 0x09 && c <= 0x20;
}

char** get_words(char *src, size_t* amount)
{
    size_t i = 0;
    char** words = (char**)malloc(100 * sizeof(char*));
    char* word = strtok(src, " ");
    while (word){
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    *amount = i;
    return words;
}

int compare(size_t a, size_t b) {
    if (a < b) {
        return -1;
    }
    if (a == b) {
        return 0;
    }
    return 1;
}

void get_string(size_t n, size_t* count, char** words, char* dest) {
    int dest_index = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t j = 0;
        while (count[j] != i) {
            j++;
        }
        size_t len = strlen(words[j]);
        size_t cur_len = 0;
        for (char* p = words[j]; !isspace(*p) && cur_len < len; ++p)
        {
            dest[dest_index] = *p;
            dest_index++;
            cur_len++;
        }
        if (i + 1 != n){
            dest[dest_index] = ' ';
            dest_index++;
        }
        dest[dest_index] = 0;
    }
}

void csort(char *src, char *dest)
{
    size_t n;
    //  char* temp = strcat(src, " ");
    char** s = get_words(src, &n);
    size_t* count = calloc(n, sizeof(size_t));
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            //printf("%s\n", s[i]);
            if (compare(strlen(s[i]), strlen(s[j])) <= 0) {
                count[j]++;
            } else {
                count[i]++;
            }
        }
    }
    get_string(n, count, s, dest);
    free(s);
    free(count);
}

int main()
{
    char s[BUFSIZ];
    char new_s[BUFSIZ];
    fgets(s, BUFSIZ, stdin);
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = 0;
    csort(s, new_s);
    puts(new_s);
}