#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int priority;
} tuple;

typedef struct Queue{
    size_t capacity;
    int count;
    tuple *heap;
} queue_t;

void swap(tuple* a, tuple* b){
    tuple t = *a;
    *a = *b;
    *b = t;
}

int heapify(tuple* heap, size_t nel){
    int q = 0;
    int i = 0;
    while ((size_t)i < nel / 2){
        int l = i * 2 + 1;
        int r = l + 1;
        int j = l;
        if ((size_t)r < nel && heap[r].priority > heap[l].priority){
            j = r;
        }
        if (heap[i].priority >= heap[j].priority){
            return q;
        }
        swap(&heap[i], &heap[j]);
        q = i = j;
    }
    return q;
}

void make_priorityQueue(queue_t* q, size_t  n){
    q->heap = (tuple*)malloc(n * sizeof(tuple));
    q->capacity = n;
    q->count = 0;
}

void queue_insert(queue_t* q, tuple x){
    int i = q->count++;
    q->heap[i] = x;
    while (i > 0 && q->heap[i].priority > q->heap[(i - 1) / 2].priority){
        swap(&q->heap[i], &q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

tuple queue_extractMax(queue_t* q){
    tuple t = q->heap[0];
    q->heap[0].priority = INT_MIN;
    q->count = heapify(q->heap, q->capacity);
    return t;
}

int main(){
    size_t n;
    scanf("%lu\n", &n);
    size_t res_size = 0;
    for (size_t i = 0; i < n; i++){
        size_t x;
        scanf("%lu", &x);
        res_size += x;
    }
    queue_t q;
    make_priorityQueue(&q, res_size);
    for (size_t i = 0; i < res_size; i++)
    {
        int x;
        scanf("%d", &x);

        tuple t;
        t.value = x;
        t.priority = -x;
        queue_insert(&q, t);
    }
    for (size_t i = 0; i < res_size; i++)
        printf("%d ", queue_extractMax(&q).value);
    printf("\n");
    free(q.heap);
    return 0;
}