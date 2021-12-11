#include <stdio.h>
#include <stdlib.h>

long calc_fib(size_t n, int* arr)
{
    arr[0] = 1;
    arr[1] = 2;
    long i = 1;
    while (arr[i - 1] + arr[i] < n)
    {
        arr[i + 1] = arr[i - 1] + arr[i];
        i++;
    }
    return i;
}




void shellsort(unsigned long nel,
    int (*compare)(unsigned long i, unsigned long j),
    void (*swap)(unsigned long i, unsigned long j))
{
    int arr[50];
    long n = calc_fib(nel, arr);
    int d = arr[n];
    while (n >= 0)
    {
        int d = arr[n];
        for (int i = d; i < nel; ++i)
        {
            for (int loc = i - d; loc >= 0 ; loc -= d) 
            {
                if (compare(loc, loc + d) > 0)
                    swap(loc + d, loc);
            }
        }
        n--;
    }
    
           
}

int arr[] = {10, 1, 5, 6, 7, 2, 3, 4, 9, 8};

int compare(unsigned long i, unsigned long j)
{
    if (arr[i] < arr[j])
        return -1;
    if (arr[i] == arr[j])
        return 0;
    return 1;
}

void swap(unsigned long i, unsigned long j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    shellsort(10, compare, swap);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}