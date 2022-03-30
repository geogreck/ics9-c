#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)
{
    int abs_a = abs(a);
    int abs_b = abs(b);
    if (abs_a < abs_b)
        return -1;
    if (abs_a == abs_b)
        return 0;
    return 1;
}

void insertionsort(int* arr, size_t n)
{
    for (size_t i = 1; i < n; i++)
    {
        int elem_abs = abs(arr[i]);
        int elem = arr[i];
        size_t loc = i;
        while (loc > 0 && abs(arr[loc - 1]) > elem_abs)
        {
            arr[loc] = arr[loc - 1];
            loc--;
        }
        arr[loc] = elem;
    }
}

void merge(int* arr, size_t l, size_t mid, size_t r)
{
    size_t buf_size = r - l + 1;
    int* buf = malloc(sizeof(int) * buf_size);
    size_t i = l;
    size_t j = mid + 1;
    size_t h;
    for (h = 0; h < (r - l + 1); h++)
    {
        if ((j <= r) &&  (i == mid + 1 || compare(arr[i], arr[j]) >  0))
        {
            buf[h] = arr[j];
            j++;
        }else{
            buf[h] = arr[i];
            i++;
        }
    }
    for (size_t k = l; k <= r; k++)
    {
        arr[k] = buf[k - l];
    }
    free(buf);
}

void mergesort_rec(int* arr, size_t l ,size_t r)
{
    if ((r - l ) > 5)
    {
        size_t mid = (l + r) / 2;
        mergesort_rec(arr, l, mid);
        mergesort_rec(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }else{
        insertionsort(arr + l, r - l + 1);
    }
}

void mergesort(int* arr, size_t n)
{
    mergesort_rec(arr, 0, n - 1);
}

int main()
{
    size_t n;
    scanf("%lu", &n);
    int* arr = malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}