#include <stdio.h>
#include <stdlib.h>

typedef struct task{
    size_t low;
    size_t high;
} task_t;

typedef struct stack{
    size_t top;
    size_t capacity;
    task_t* data;
} stack_t;

void make_stack(stack_t* s, size_t n) {
    s->data = (task_t*)malloc(sizeof(task_t) * n);
    s->capacity = n;
    s->top = 0;
}

char stack_empty(stack_t s){
    return s.top? 0 : 1;
}

void stack_push(stack_t* s, task_t new_data){
    s->data[s->top] = new_data;
    s->top++;
}

task_t stack_pop(stack_t* s){
    if (s->top == 0)
        perror("emptiness and loneliness");
    s->top--;
    return s->data[s->top];
}

void swap(long* arr, size_t a, size_t b)
{
    long t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

size_t partition(long* arr, size_t l, size_t r)
{
    size_t i = l;
    long t = arr[r - 1];
    for (size_t j = l; j < r - 1; j++)
    {
        if (arr[j] < t)
        {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, r - 1);
    return i;
}

void quicksort(long* arr, size_t n){
    stack_t tasks;
    make_stack(&tasks, n);
    task_t first_task;
    first_task.low = 0;
    first_task.high = n;
    stack_push(&tasks, first_task);
    while (!stack_empty(tasks)){
        task_t task = stack_pop(&tasks);
        if (task.low < task.high){
            task_t new_task;
            size_t q = partition(arr, task.low, task.high);
            new_task.low = q + 1;
            new_task.high = task.high;
            stack_push(&tasks, new_task);
            new_task.low = task.low;
            new_task.high = q;
            stack_push(&tasks, new_task);
        }
    }
    free(tasks.data);
}

int main(){
    size_t n;
    scanf("%lu", &n);
    long* arr = (long*)malloc(n * sizeof(long));
    for (size_t i = 0; i < n; i++){
        scanf("%ld", arr + i);
    }
    quicksort(arr, n);
    for (size_t i = 0; i < n; i++){
        printf("%ld ", *(arr + i));
    }
    printf("\n");
    free(arr);
    return 0;
}
