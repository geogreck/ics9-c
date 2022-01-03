#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct{
    size_t t1;
    size_t t2;
} task;

typedef struct{
    size_t value;
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

size_t max(size_t a, size_t b){
    return a > b ? a : b;
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
    size_t n, m;
    queue_t cluster;
    scanf("%lu", &n);
    make_priorityQueue(&cluster, n);
    tuple pair;
    pair.value = 0;
    pair.priority = 0;
    for (size_t i = 0; i < n; i++){
        queue_insert(&cluster, pair);
    }
    scanf("%lu", &m);
    task* tasks = (task*)malloc(m * sizeof(task));
    for (size_t i = 0; i < m; i++){
        size_t t1, t2;
        scanf("%lu%lu", &t1, &t2);
        tasks[i].t1 = t1;
        tasks[i].t2 = t2;
    }
    size_t min_time = 0;
    for (size_t i = 0; i < m; i++){
        task task1 = tasks[i];
        size_t sum_time = queue_extractMax(&cluster).value;
        sum_time = max(task1.t1, sum_time) + task1.t2;
        min_time = max(sum_time, min_time);
        pair.value = sum_time;
        pair.priority = -(int)sum_time;
        queue_insert(&cluster, pair);
    }
    printf("%lu\n", min_time);
    free(tasks);
    free(cluster.heap);
    return 0;
}