
#include <stdio.h>

int main() {
    long long n, x0;
    scanf("%lld%lld", &n, &x0);
    long long a;
    long long ans = 0;
    long long der_ans = 0;
    for (unsigned int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        ans = ans * x0 + a;
        der_ans = der_ans * x0 + a * (n - i);
    }
    scanf("%lld", &a);
    ans = ans * x0 + a;
    printf("%lld\n%lld\n", ans, der_ans);
    return 0;
}