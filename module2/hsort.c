#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void* base, size_t width, size_t a, size_t b)
{
    unsigned char* ptr_a = (unsigned char*)base + a * width;
    unsigned char* ptr_b = (unsigned char*)base + b * width;
    for (size_t i = 0; i < width; i++)
    {
        unsigned char t = *ptr_a;
        *ptr_a = *ptr_b;
        *ptr_b = t;
        ptr_a++;
        ptr_b++;
    }
}

void heapify(void *base, size_t nel, size_t width, size_t i,
    int (*compare)(const void *a, const void *b))
{
    size_t max = i;
    size_t l = 2 * i + 1;
    size_t r = l + 1;

    if (l < nel && compare(*((unsigned char**)base + l), *((unsigned char**)base + max)) > 0)
        max = l;
    if (r < nel && compare(*((unsigned char**)base + r), *((unsigned char**)base + max)) > 0)
        max = l;
    if (max != i)
    {
        swap(base, width, i, max);
        heapify(base, nel, width, max, compare);
    }
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
    for (int i = (int)nel / 2; i> 0; i--)
    {
        heapify(base, nel, width, (size_t)i - 1, compare);
    }

    for (int i = (int)nel - 1; i > 0; i--)
    {
        swap(base, width, 0, (size_t)i);
        heapify(base, (size_t)i, width, 0, compare);
    }
}

size_t lc_strlen(const char *s)
{
    size_t n = 0;
    while (*(s + n) != 0)
        n++;
    return n;
}

int compare(const void *a, const void *b)
{
    size_t l = lc_strlen((const char*)a);   
    size_t r = lc_strlen((const char*)b);
    if (l < r)
        return -1;
    if (l == r)
        return 0;
    return 1;
}

int main()
{
    size_t n;
    scanf("%lu\n", &n);
    char** arr = malloc(sizeof(char*) * n);
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(char) * BUFSIZ);
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    hsort(arr, n, sizeof(char*), compare);
    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}