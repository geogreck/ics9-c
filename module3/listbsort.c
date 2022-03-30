#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
    struct elem* next;
    char* word;
} list_t;

list_t* list_make(){
    list_t* list = (list_t*)malloc(sizeof(list_t));
    list->next = NULL;
    list->word = NULL;
    return list;
}

size_t list_length(list_t* list){
    if (!list)
        return 0;
    size_t len = 0;
    list_t* x = list;
    while (list->next != NULL){
        len++;
        list = list->next;
    }
    list = x;
    return len;
}

void list_print(list_t* list){
    list_t* x = list;
    while (x){
        if (x->word)
            printf("%s ", x->word);
        x = x->next;
    }
}

void list_free(list_t* list){
    list_t* x = list;
    list_t* y = list;
    while (x){
        x = x->next;
        if (y)
            free(y);
        y = x;
    }
}

int compare(list_t a, list_t b){
    return (int)strlen(a.word) - (int)strlen(b.word);
}

void swap(list_t* a, list_t* b){
    char* t = a->word;
    a->word = b->word;
    b->word = t;
}

list_t* bsort(list_t* list){
    list_t* elem;
    size_t nel = list_length(list);
    for (size_t i = 0; i < nel; i++){
        elem = list;
        while (elem != NULL){
            if (elem->word != NULL && elem->next != NULL){
                if (compare(*elem, *elem->next) > 0){
                    swap(elem, elem->next);
                }
            }
            elem = elem->next;
        }
    }
    return list;
    
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

int main(){
    list_t* list = list_make();
    char BUF[BUFSIZ];
    fgets(BUF, BUFSIZ, stdin);
    if (BUF[strlen(BUF) - 1] == '\n')
        BUF[strlen(BUF) - 1] = 0;
    list_t* x = list;
    list_t* elem;
    char* word;
    size_t n;
    char** s = get_words(BUF, &n);
    for (size_t i = 0; i < n; i++){
        word = s[i];
        elem = (list_t*)malloc(sizeof(list_t));
        elem->next = NULL;
        elem->word = word;
        x->next = elem;
        x = elem;
    }
    list = bsort(list);
    list_print(list);
    list_free(list);
    free(s);
    return 0;
}


