//////ПЕРЕПИСАТЬ

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void push_arr(int* m, int k)
{
    int t;
    printf("%d ", *(m + 2));
    for (int i = 0; i < 3; i++)
    {
        t = *(m + i);
        *(m + i) = k;
        k = t;
    }
}

int check_arr(int* m)
{
    return (*m == 0 && *(m + 1) == 1 && *(m + 2) == 1);
}

void fix_arr(int* m)
{
    if (check_arr(m))
    {
        *(m + 2) = 0;
        *(m + 1) = 0;
        *m = 1;
    }
}

int main()
{
    int n, k;
    int flag = 0;
    int* m = malloc(sizeof(int) * 3);

    scanf("%d", &n);

    scanf("%d", &k);
    if (k)
    {
        scanf("%d", &k);
        scanf("%d", &k);
        *m = k;
        *(m + 1) = 1;
        *(m + 2) = 0;
    }
    else
    {
        *(m + 2) = 1;
        scanf("%d", &k);
        *(m + 1) = k;
        scanf("%d", &k);
        *m = k;
    }
    fix_arr(m);

    for(int i = 0; i < n - 3; i++)
    {
        scanf("%d", &k);
        push_arr(m, k);
        fix_arr(m);
    }
    printf("%d %d %d", *(m + 2), *(m + 1), *m);
    free(m);
    return 0;
}