
#include <stdio.h>

void check(int* d1, int* d2, int* d3)
{
    if (*d1 && *d2 && !*d3)
    {
        *d3 = 1;
        *d2 = 0;
        *d1 = 0;
    }
    //printf("%d %d %d\n", *d1, *d2, *d3);
}

void push(int* d1, int* d2, int* d3)
{
    printf("%d ", *d1);
    *d1 = *d2;
    *d2 = *d3;
    scanf("%d", (&*d3));
}

int main()
{
    int n;
    int d1 = 0, d2 = 0, d3 = 0;
    scanf("%d", &n);
    if (n == 1)
    {
        scanf("%d", &d1);
    }
    if (n == 2)
    {
        scanf("%d", &d1);
        scanf("%d", &d2);
    }
    if (n >= 3)
    {
        scanf("%d", &d1);
        scanf("%d", &d2);
        scanf("%d", &d3);
    }
    //printf("%d %d %d\n", d1, d2, d3);
    if (d1)
    {
        d1 = 0;
        d2 = 1;
    }
    else
    {
        d1 = 1;
    }
    //printf("%d %d %d\n", d1, d2, d3);
    check(&d1, &d2, &d3);

    for (int i = 0; i < n - 3; i++)
    {
        push(&d1, &d2, &d3);
        check(&d1, &d2, &d3);
    }
    
    printf("%d ", d1);

    if (d2 && !d3)
    {
        printf("%d\n", d2);
    }
     else if (d2 || d3)
    {
        printf("%d ", d2);
        printf("%d\n", d3);
    }
    else 
    {
        printf("\n");
    }

    return 0;
}