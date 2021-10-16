
#include <stdio.h>
#include <math.h>

long countDeritative(long i, long k)
{
    long res = 1;
    for (long j = 1; j <= k; j++)
    {
        res *= i;
        i--;
    }
    return res;
}

int main()
{
    long n, k, x, a;
    long sum = 0;

    scanf("%ld%ld%ld", &n, &k, &x);

    for(long i = n; i >= k; i--)
    {
        scanf("%ld", &a);
        sum += countDeritative(i, k) * pow(x, i - k) * a;
    }

    printf("%ld\n", sum);

    return 0;
}
