#include <stdio.h>
#include <stdlib.h>

int arr[] = {10, 1, 5, 6, 7, 2, 3, 4, 9, 8};

void bubblesort(unsigned long nel, 
    int (*compare)(unsigned long i, unsigned long j), 
    void (*swap)(unsigned long i, unsigned long j))
{
    for (size_t i = 0; i < nel; i++)
    {
        if (i % 2 == 0)
        {
            for (size_t j = i; j < nel - 1; j++)
            {
                if (compare(j, j + 1) > 0)
                    swap(j, j + 1);
            }
        }
            for (size_t j = nel - 1; j > i; j--)
            {
                if (compare(j - 1, j) > 0)
                    swap(j - 1, j);
            }
    }
}

void swap(unsigned long i, unsigned long j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int compare(unsigned long i, unsigned long j)
{
    if (arr[i] < arr[j])
        return -1;
    if (arr[i] == arr[j])
        return 0;
    return 1;
}

int main()
{
    bubblesort(10, compare, swap);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}