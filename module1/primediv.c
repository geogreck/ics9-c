#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

int primediv(int x)
{
    int* m = calloc((size_t)x, sizeof(int));
    size_t i = 2;

    while (i < sqrt(x))
    {
        if (!m[i])
        {
            for (size_t j = i * i; j <= (size_t)x; j += i)
            {
                m[j] = 1;
            }
        }
        i++;
    }

    for (i = (size_t)x - 1; i > 0; i--)
    {
        if (!m[i])
        {
            free(m);
            return (int)i;
        }
    }

    free(m);
    return 0;
}

int main()
{
    int x, div;
    scanf("%d", &x);

    div = primediv(x);

    printf("%d\n", div);
    return 0;
}