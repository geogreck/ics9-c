#include <stdio.h>
#include <stdlib.h>

size_t check_sum(size_t a, size_t b, size_t m)
{
    return (a % m) + (b % m);
}

size_t check_mult(size_t a, size_t b, size_t m)
{
    return (a % m) * (b % m);
}

int main()
{
    size_t a, b, sum = 0, m;
    scanf("%lu%lu%lu", &a,&b,&m);

    for (int i = 63; i >= 0; i--)
    {
        sum = check_sum(sum, 2 * check_mult(a, (b & ((size_t)1 << (size_t)i)), m), m);
    }

    printf("%lu\n", (sum / 2) % m);
    return 0;
}