
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

long long count_sum(int* arr, size_t k){
    long long sum = 0;
    for (size_t i = 0; i < k; i++){
        sum += (long long)*(arr + i);
    }
    return sum;
}

int main(){
    size_t n, k;
    long long sum, max_sum;
    scanf("%lu", &n);
    int* arr = malloc((size_t)n * sizeof(int));
    for (size_t i = 0; i < n; i++){
        scanf("%d", arr + i);
    }
    scanf("%lu", &k);
    max_sum = count_sum(arr, k);
    for (size_t i = 0; i < n - k; i++){
        sum = sum - arr[i] + arr[i + k];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    free(arr);
    printf("%lld\n", max_sum);
    //printf("%d\n", sum_start);

    return 0;
}