#include <stdio.h>

int set_input()
{
    int n, k, a = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        a |= (1 << k);
    }

    return a;
}

int main()
{
    int a = set_input();
    int b = set_input();

    for (int i = 0; i < 32; i++)
    {
        if ((a & b) & (1 << i))
            printf("%d ", i);
    }

    printf("\n");
}