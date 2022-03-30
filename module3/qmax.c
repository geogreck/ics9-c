#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct DoubleStack{
	size_t capacity;
	size_t top_1;
	size_t top_2;
	int *data;
    int *max;
} stack_t;

void make_stack(stack_t* stack, size_t n){
    stack->data = (int *)malloc(sizeof(int) * n);
    stack->max = (int *)malloc(sizeof(int) * n);
    stack->capacity = n;
    stack->top_1 = 0;
    stack->top_2 = n - 1;   
}

int stack_empty1(stack_t stack){
    return stack.top_1 == 0;
}

int stack_empty2(stack_t stack){
    return stack.top_2 == stack.capacity - 1;
}

int queue_empty(stack_t stack){
    return stack_empty1(stack) && stack_empty2(stack);
}

void stack_push1(stack_t* stack, int x){
    stack->data[stack->top_1] = x;
    if (stack->top_1 == 0){
        stack->max[stack->top_1] = x;
    }else{
        if (stack->max[stack->top_1 - 1] < x){
            stack->max[stack->top_1] = x; 
        }else{
            stack->max[stack->top_1] = stack->max[stack->top_1 - 1];
        }
    }
    stack->top_1++;
}

void stack_push2(stack_t* stack, int x){
    stack->data[stack->top_2] = x;
    if (stack->top_2 == stack->capacity - 1){
        stack->max[stack->top_2] = x;
    }else{
        if (stack->max[stack->top_2 + 1] > x){
            stack->max[stack->top_2] = stack->max[stack->top_2 + 1];
        }else{
            stack->max[stack->top_2] = x; 
        }
    }
    stack->top_2--;
}

int stack_pop1(stack_t* stack){
    int x;
    stack->top_1--;
    x = stack->data[stack->top_1];
    return x;
}

int stack_pop2(stack_t* stack){
    int x;
    stack->top_2++;
    x = stack->data[stack->top_2];
    return x;
}

void enqueue(stack_t* stack, int x){
	stack_push1(stack, x);
}

int dequeue(stack_t* stack){
    if (stack_empty2(*stack)){
        while(stack_empty1(*stack) == 0){
            stack_push2(stack, stack_pop1(stack));
        }
    }
    return stack_pop2(stack);
}

int max(stack_t stack){
    if ((stack.top_1 != 0) && ((stack.top_2 == stack.capacity - 1) || ((stack.top_2 != stack.capacity - 1) && (stack.max[stack.top_1 - 1]> stack.max[stack.top_2 + 1])))){
                return stack.max[stack.top_1 - 1];
    }else{
        return stack.max[stack.top_2 + 1];
    }
}

size_t lc_strcmp(const char *s1, const char *s2){
    while(*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

size_t get_key(char* oper){
    char* opers[] = {"ENQ", "DEQ", "MAX", "EMPTY"};
    for (size_t i = 1; i <= 4; i++){
        if (lc_strcmp(oper, opers[i - 1]) == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    size_t n;
    scanf("%lu", &n);
    stack_t stack;
    make_stack(&stack, n * 2);
    for (size_t i = 0; i < n; i++){
        char oper[6];
        scanf("%s", oper);
        size_t key = get_key(oper);
        int x;
        switch (key)
        {
        case 1:
            scanf("%d", &x);
            enqueue(&stack, x);
            break;
        case 2:
            printf("%d\n", dequeue(&stack));
            break;
        case 3:
            printf("%d\n", max(stack));
            break;
        case 4:
            queue_empty(stack) ? printf("true\n") : printf("false\n");
            break;
        default:
            break;
        }
    }
    free(stack.data);
    free(stack.max);
    return 0;
}