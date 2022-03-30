#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

 unsigned int root(unsigned int a)
{
   unsigned int x;
   x = (a/0x3f + 0x3f)>>1;
   x = (a/x + x)>>1;
   x = (a/x + x)>>1;
   return(x); 
}

long primediv(long x)
{
    int* m = calloc((size_t)x + 1, sizeof(int));
    size_t i = 2;
    while (i < root(x)){
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
        if (!m[i] && !(x % i))
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
    long x, div;
    scanf("%ld", &x);
    if (x < 0){
        x = -1 * x;
    }
    printf("%ld\n", x);
    div = primediv(x);
    printf("%ld\n", div);
    return 0;
}