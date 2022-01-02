#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    size_t top;
    size_t capacity;
    int* data;
} stack_t;

void make_stack(stack_t* s, size_t n) {
    s->data = (int*)malloc(sizeof(int) * n);
    s->capacity = n;
    s->top = 0;
}

char stack_empty(stack_t s){
    return s.top? 0 : 1;
}

void stack_push(stack_t* s, int new_data){
    s->data[s->top] = new_data;
    s->top++;
}

int stack_pop(stack_t* s){
    if (s->top == 0)
        perror("emptiness and loneliness");
    s->top--;
    return s->data[s->top];
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a > b ? b : a;
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
    char *opers[] = {"CONST", "ADD", "SUB", "MUL", "DIV", "MAX", "MIN", "NEG", "DUP", "SWAP"};
    for (size_t i = 1; i <= 10; i++){
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
    make_stack(&stack, n);
    for (size_t i = 0; i < n; i++){
        char oper[6];
        scanf("%s", oper);
        size_t key = get_key(oper);
        int a, b;
        switch (key)
        {
        case 1:
            scanf("%d", &a);
            stack_push(&stack, a);
            break;
        case 2:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, a + b);
            break;
        case 3:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, a - b);
            break;
        case 4:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, a * b);
            break;
        case 5:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, a / b);
            break;
        case 6:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, max(a, b));
            break;
        case 7:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, min(a, b));
            break;
        case 8:
            a = stack_pop(&stack);
            stack_push(&stack, -1 * a);
            break;
        case 9:
            a = stack_pop(&stack);
            stack_push(&stack, a);
            stack_push(&stack, a);
            break;
        case 10:
            a = stack_pop(&stack);
            b = stack_pop(&stack);
            stack_push(&stack, b);
            stack_push(&stack, a);
            break;
        default: 
            printf("unknown command\n");
            break;
        }
    }
    printf("%d\n", stack_pop(&stack));
    free(stack.data);
    return 0;
}