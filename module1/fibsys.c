#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll find_fib(ll x)
{
    ll a = 0, b = 1;
    while ((a + b) <= x)
    {
        ll t = b;
        b += a;
        a = t;
    }

    return b;
}

int main()
{
    ll x, f;
    scanf("%lld", &x);

   while (x)
    {
        if (x == 1)
            printf("%lld\n", x--);
        else{
            f = find_fib(x);
            x -= f;
            printf("10");
        }
    }

    return 0;
}