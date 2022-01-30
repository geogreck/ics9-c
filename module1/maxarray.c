#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(void* a, void* b)
{
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
 
    return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
}

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
    unsigned char* max = malloc(width);
    size_t i_max = 0;

    memcpy(max, base, width);
    for (size_t i = 1; i < nel; i++)
    {
        if (compare(((unsigned char*)base + i * width), max) > 0)
        {
            memcpy(max, (unsigned char*)base + i * width, width);
            i_max = i;
        }
    }
    free(max);
    return (int)i_max;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 110, 7, 8, 9, 10};
    char arr_s[4] = {'a', 'b', 'v', 'd'};

    printf("%d\n", maxarray(arr, 10, sizeof(int), compare_ints));
    //printf("%d\n", maxarray(arr_s, 4, sizeof(char), compare_chars));

    return 0;
}