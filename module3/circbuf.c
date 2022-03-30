#include <stdio.h>
#include <stdlib.h>

typedef struct CircleBuffer
{
	int *data;
	size_t capacity;
	size_t count;
	size_t head;
	size_t tail;
} CircleBuffer_t;

void make_queue(CircleBuffer_t *CircleBuff, size_t n){
    CircleBuff->data = (int*)malloc(n * sizeof(int));
    CircleBuff->capacity = n;
    CircleBuff->count = 0;
    CircleBuff->head = 0;
    CircleBuff->tail = 0;
}

char queue_empty(CircleBuffer_t CircleBuff){
    return CircleBuff.count == 0;
}

void enqueue(CircleBuffer_t* CircleBuff, int x){
    CircleBuff->data[CircleBuff->tail] = x;
    CircleBuff->count++;
    CircleBuff->tail++;
    if (CircleBuff->tail == CircleBuff->capacity){
        CircleBuff->capacity *= 2;
        CircleBuff->data = (int*)realloc(CircleBuff->data, CircleBuff->capacity * sizeof(int));
    }
}

int dequeue(CircleBuffer_t* CircleBuff){
    int x = CircleBuff->data[CircleBuff->head];
	CircleBuff->head = (CircleBuff->head + 1) % CircleBuff->capacity;
	CircleBuff->count--;
	return x;
}

size_t lc_strcmp(const char *s1, const char *s2)
{
    while(*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

size_t get_key(char* oper){
    char* opers[] = {"ENQ", "DEQ", "EMPTY"};
    for (size_t i = 1; i <= 3; i++){
        if (lc_strcmp(oper, opers[i - 1]) == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    size_t n;
    scanf("%lu", &n);
    CircleBuffer_t CircleBuff;
    make_queue(&CircleBuff, 4);
    for (size_t i  = 0; i < n; i++){
        char oper[6];
        scanf("%s", oper);
        size_t key = get_key(oper);
        int x;
        switch (key)
        {
        case 1:
            scanf("%d", &x);
            enqueue(&CircleBuff, x);
            break;
        case 2:
            printf("%d\n", dequeue(&CircleBuff));
            break;
        case 3:
            queue_empty(CircleBuff) ? printf("true\n") : printf("false\n");
        default:
            break;
        }
    }
    free(CircleBuff.data);
    return 0;
}