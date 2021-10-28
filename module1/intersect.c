
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n;
    long long a, b, a1, b1;
    a1 = LLONG_MIN;
    b1 = LLONG_MIN + 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a, &b);
        if (a <= b1 + 1)
        {
            b1 = max(b, b1);
        }
        else
        {
            if (a1 != LLONG_MIN)
            {
                printf("%lld %lld\n", a1, b1);
            }
            a1 = a;
            b1 = b;
        }
    }
    printf("%lld %lld\n", a1, b1);    

    return 0;
}