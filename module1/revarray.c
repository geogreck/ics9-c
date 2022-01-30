#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
    unsigned char* t = malloc(width);
    for (size_t i = 0; i < nel / 2; i++)
    {
        memcpy(t, (unsigned char*)base + i * width, width);
        memcpy((unsigned char*)base + i * width, (unsigned char*)base + (nel - i - 1) * width, width);
        memcpy((unsigned char*)base + (nel - i - 1) * width, t, width);
    }
    free(t);
}

int main()
{
    //size_t arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //unsigned char arr_s[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    double arr_d[4] = {1, 2, 3, 4};
    /*print_arr(arr, 10, sizeof(size_t));
    revarray(arr, 10, sizeof(size_t));
    print_arr(arr, 10, sizeof(size_t));

    print_arr(arr_s, 11, sizeof(char));//Не красиво, что поделать
    revarray(arr_s, 11, sizeof(char));
    print_arr(arr_s, 11, sizeof(char));*/

    for (size_t i = 0; i < 4; ++i) {
        printf("%f ", arr_d[i]);
    }
    printf("\n");
    revarray(arr_d, 4, sizeof(double));
    for (size_t i = 0; i < 4; ++i) {
        printf("%f ", arr_d[i]);
    }

    return 0;
}