#include <stdio.h>
#include <stdlib.h>

unsigned char is_power2(int n)
{
    return (n <= 0) ? 0 : (n & (n - 1)) == 0;
}

int count(int* arr, int n)
{
    int res = 0;

    for (int i = 0; i < 1<<n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1<<j))
            {
                sum += arr[j];
            }
        }
        if (is_power2(sum))
            res++;
    }

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int res = count(arr, n);

    printf("%d\n", res);
}