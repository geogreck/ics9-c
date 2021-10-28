#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

ll find_fib(ll x, int* n)
{
    ll a = 0, b = 1;
    int k = 1;
    while ((a + b) <= x)
    {
        ll t = b;
        b += a;
        a = t;
        k++;
    }
    *n = k;
    return b;
}

void print_arr(int* m)
{
    int flag = 0;
    for (int i = 100; i > 0; i--)
    {
        if (m[i] || flag)
        {
            flag = 1;
            printf("%d", m[i]);
        }
    }
    printf("\n");
}

int main()
{
    ll x, f;
    int n;
    scanf("%lld", &x);

    int m[100] = {0};


   while (x)
    {
        if (x == 1)
            m[0] = 1;
        else
        {
            f = find_fib(x, &n);
            m[n - 1] = 1;
            x -= f;
        }
    }

    print_arr(m);

    return 0;
}