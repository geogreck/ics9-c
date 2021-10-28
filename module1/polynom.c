
#include <stdio.h>

long my_pow(long x, long n)
{
    long a = x, p = 1;
    while (n > 0)
    {
        if ((n & 1) != 0)
            p *= a;
        a *= a;
        n >>= 1;
    }
    return p;
}

int main()
{
    long n, x0, x, a;
    long der_sum = 0, sum = 0;
    scanf("%ld%ld", &n, &x0);

    if (x0 != 0){
        x = my_pow(x0, n);

        for(long i = n; i >= 0; i--){
            scanf("%ld", &a);
            sum += a * x;
            x = x / x0;
            der_sum += i * a * x;
        }
    }
    else{
        for(long i = n; i > 0; i--){
            scanf("%ld", &a);
        }
        der_sum = a;
        scanf("%ld", &a);
        sum = a;
        if (n == 0)
            der_sum = 0;
    }

    printf("%ld\n", sum);
    printf("%ld\n", der_sum);

    return 0;
}
