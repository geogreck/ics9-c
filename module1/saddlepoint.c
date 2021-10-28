#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

int main()
{
    int a;
    size_t m, n;
    scanf("%lu%lu", &m, &n);
    size_t max_elements_index[n];
    size_t min_elements_index[m];
    int min_elements[m];

    for (size_t j = 0; j < m; ++j)
    {
        min_elements[j] = INT_MAX;
    }

    for (size_t i = 0; i < m; i++)
    {
        int max = INT_MIN;
        size_t max_j = 11;
        for (size_t j = 0; j < n; j++)
        {
            scanf("%d", &a);
            if (a > max)
            {
                max = a;
                max_j = j;
            }
            if (a < min_elements[j])
            {
                min_elements[j] = a;
                min_elements_index[j] = i;
            }
        }
        max_elements_index[i] = max_j;
    }
    for (size_t i = 0; i < n; ++i) {
        if (min_elements_index[max_elements_index[i]] == i)
        {
            printf("%lu %lu\n", i, max_elements_index[i]);
            return 0;
        }
    }
    printf("none\n");
}