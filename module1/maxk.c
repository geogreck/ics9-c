
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

long long count_sum(int* arr, int k)
{
    long long sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += (long long)*(arr + i);
    }

    return sum;
}

void push_arr(int* arr, int k, int d)
{
    for (int i = 0; i < k - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[k - 1] = d;
}

int main()
{
    int n, k, d, sum_start = 0;
    long long sum, max_sum;

    scanf("%d%d", &n, &k);

    int* arr = malloc((size_t)k * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &*(arr + i));
    }

    max_sum = count_sum(arr, k);

    for (int i = 0; i < n - k; i++)
    {
        scanf("%d", &d);
        push_arr(arr, k, d);
        sum = count_sum(arr, k);
        //printf("%lld\n", sum);
        if (sum > max_sum)
        {
            max_sum = sum;
            sum_start = i + 1; 
        }
    }

    free(arr);

    printf("%lld\n", max_sum);
    //printf("%d\n", sum_start);

    return 0;
}