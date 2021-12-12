#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, size_t a, size_t b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void selectsort(int* arr, size_t n)
{
    for (size_t j = n - 1; j > 0; j--)
    {
        size_t k = j;
        for (size_t i = j; i > 0; i--)
        {
            if (arr[k] < arr[i - 1])
                k = i - 1;
        }
        swap(arr, j, k);
    }
}

size_t partition(int* arr, size_t l, size_t r)
{
    size_t i = l;
    int t = arr[r - 1];
    for (size_t j = l; j < r - 1; j++)
    {
        if (arr[j] < t)
        {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, r - 1);
    return i;
}

void quicksort_rec(int* arr, size_t l, size_t r, size_t m)
{
    if (r - l > 0)
    {
        size_t q = partition(arr, l, r);
        quicksort_rec(arr, l, q, m);
        quicksort_rec(arr, q + 1, r, m);
    }else{
        selectsort(arr + l, r - l + 1);
    }
}

void quicksort(int* arr, size_t n, size_t m)
{
    quicksort_rec(arr, 0, n, m);
}

int main()
{
    size_t n, m;
    scanf("%lu%lu", &n, &m);
    int* arr = malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, n, m);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}