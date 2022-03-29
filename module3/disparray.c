#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    struct elem* next;
    int v;
    size_t key;
} list_t;

typedef struct{
    list_t** array;   
} hashTable_t;


list_t* make_list(){
    list_t* list = (list_t*)malloc(sizeof(list_t));
    list->next = NULL;
    list->key = 0;
    list->v = 0;
    return list;
}

list_t* list_search(hashTable_t* t, size_t nel, size_t key){
    list_t* x = t->array[key % nel];
    while (x && x->key != key){
        x = x->next;
    }
    return x;
}

void list_insert(hashTable_t* table, size_t nel, size_t key, int v){
    list_t* z = make_list();
    z->key = key;
    z->v = v;
    z->next = table->array[key % nel];
    table->array[key % nel] = z;
}

hashTable_t* make_hashTable(size_t nel){
    hashTable_t* t = (hashTable_t*)malloc(sizeof(hashTable_t));
    t->array = (list_t**)malloc(nel * sizeof(list_t*));
    for (size_t i = 0; i < nel; i++){
        t->array[i] = make_list();
    }
    return t;
}

void table_free(hashTable_t* t, size_t m){
    for (size_t i = 0; i < m; i++){
        list_t* x = t->array[i];
        list_t* y;
        while (x){
            y = x->next;
            free(x);
            x = y;
        }
    }
    free(t->array);
    free(t);
}

size_t lc_strcmp(const char *s1, const char *s2){
    while(*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

size_t get_key(char* oper){
    char* opers[] = {"ASSIGN", "AT"};
    for (size_t i = 1; i <= 2; i++){
        if (lc_strcmp(oper, opers[i - 1]) == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    size_t n, m;
    scanf("%lu", &n);
    scanf("%lu", &m);
    hashTable_t* t = make_hashTable(m);
    for (size_t i = 0; i < n; i++){
        char oper[7];
        int v;
        size_t k;
        scanf("%s %lu", oper, &k);
        size_t key = get_key(oper);
        list_t* x;
        switch (key){
            case 1:
                scanf("%d", &v);
                list_insert(t, m, k, v);
                break;
            case 2:
                x = list_search(t, m, k);
                printf("%d\n", x ? x->v : 0);
                break;
            default:
                break;
        }
    }
    table_free(t, m);
    return 0;
}