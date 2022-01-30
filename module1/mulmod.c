#include <stdio.h>

int main()
{
    size_t a, b, sum = 0, m;
    scanf("%lu%lu%lu", &a, &b, &m);

    for (size_t i = (size_t)1 << 63; i > 0; i>>=1)
    {
        size_t k = 1;
        if (!(i & a))
        {
            k = 0;
        }
        sum = sum * 2 % m + k * (b % m);
        sum %= m;
    }

    printf("%lu\n", sum);
    return 0;
}