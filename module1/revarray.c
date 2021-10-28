#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void print_arr(void* arr, size_t n, size_t width)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *((unsigned char*)arr + i * width));
    }
    printf("\n");
}

void revarray(void *base, size_t nel, size_t width)
{
    unsigned char* t = malloc(width);
    for (size_t i = 0; i < nel / 2; i++)
    {
        *t = *((unsigned char*)base + i * width);
        *((unsigned char*)base + i * width) = *((unsigned char*)base + (nel - i - 1) * width);
        *((unsigned char*)base + (nel - i - 1) * width) = *t;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char arr_s[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

    print_arr(arr, 10, sizeof(int));
    revarray(arr, 10, sizeof(int));
    print_arr(arr, 10, sizeof(int));

    print_arr(arr_s, 11, sizeof(char));//Не красиво, что поделать
    revarray(arr_s, 11, sizeof(char));
    print_arr(arr_s, 11, sizeof(char));

    return 0;
}