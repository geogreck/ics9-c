#include <stdio.h>

int arr[] = {0, 1, 2, 3, 4, 5, 6};
const int k = 1;

int compare_ints(unsigned long i)
{ 
    if (arr[i] < k) return -1;
    if (arr[i] > k) return 1;
    return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    size_t m, left = 0, right = nel - 1;
    while (1)
    {
        if (left > right)
            return (nel);
        m = left + (right - left) / 2;
        if (compare(m) < 0)
            left = m + 1;
        if (compare(m) > 0)
            right = m - 1;
        if (compare(m) == 0)
            return m;
    }
}

int main()
{
    printf("%lu\n", binsearch(7, compare_ints));
    return 0;
}