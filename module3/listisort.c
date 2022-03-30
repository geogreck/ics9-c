#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    struct elem* prev;
    struct elem* next;
    int v;
} list_t;

list_t* list_make(){
    list_t* list = (list_t*)malloc(sizeof(list_t));
    list->next = NULL;
    list->prev = NULL;
    list->v = 0;
    return list;
}

char list_empty(list_t list){
    return list.next == NULL && list.prev == NULL;
}

size_t list_length(list_t* list){
    size_t len = 0;
    list_t* x = list;
    while (list->next != NULL){
        len++;
        list = list->next;
    }
    list = x;
    return len;
}

size_t list_length_prev(list_t* list){
    size_t len = 0;
    list_t* x = list;
    while (list->prev != NULL){
        len++;
        list = list->prev;
    }
    list = x;
    return len;
}

list_t* list_search(list_t* list, int v){
    list_t* x = list;
    while (x->next != NULL && x->v != v){
        x = x->next;
    }
    return x;
}

list_t* list_search_prev(list_t* list, int v){
    list_t* x = list;
    while (x->prev != NULL && x->v != v){
        x = x->prev;
    }
    return x;
}

void list_insert(list_t* list, list_t* y){
    list_t* z = list->next;
    list->next = y;
    y->next = z;
}

list_t* list_insetrbefore(list_t* list, list_t* y){
    y->next = list;
    list = y;
    return list;
}

void print_list(list_t* list){
    list_t* x = list;
    do{
        printf("%d ", x->v);
        x = x->next;
    } while (x != list);
    printf("\n");
}

void list_isort(list_t* list){
    list_t* x = list->next;
    list_t* elem;
    list_t* last = list->prev;
    while (x != list){
        int v = x->v;
        elem = x->prev;
        while ((elem != last) && (elem->v > v))
        {
            elem->next->v = elem->v;
            elem = elem->prev;
        }
        elem->next->v = v;
        x = x->next;
    }
}

void list_free(list_t* list){
    list_t* x = list;
    list_t* elem = list;
    while (x->next != list){
        x = x->next;
        free(elem);
        elem = x;
    }       
    free(elem);
}

int main(){
    list_t* list = list_make();
    size_t n;
    scanf("%lu", &n);
    list_t* x = list;
    if (n > 0){
        int v;
        scanf("%d", &v);
        list_t* elem = x;
        elem->prev = list;
        elem->next = list;
        elem->v = v;
        list->prev = elem;
        x->next = elem;
        x = elem;
    }
    for (size_t i = 1; i < n; i++){
        int v;
        scanf("%d", &v);
        list_t* elem = (list_t*)malloc(sizeof(list_t));
        list->prev = elem;
        x->next = elem;
        elem->v = v;
        elem->prev = x;
        elem->next = list;
        x = elem;
    }
    list_isort(list);
    print_list(list);
    list_free(list);
    return 0;
}
