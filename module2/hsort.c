#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t width)
{
	void *temp = malloc(width);
	memcpy(temp, a, width);
	memcpy(a, b, width);
	memcpy(b, temp, width);
	free(temp);
}

void heapify(void *base, size_t nel, size_t width, size_t i,
    int (*compare)(const void *a, const void *b))
{
    size_t max = i;
    size_t l = 2 * i + 1;
    size_t r = l + 1;

    if (l < nel && compare((unsigned char*)base + l * width, (unsigned char*)base + max * width) > 0)
        max = l;
    if (r < nel && compare((unsigned char*)base + r * width, (unsigned char*)base + max * width) > 0)
        max = r;
    if (max != i)
    {
        swap((char*)base + i * width, (char*)base + max * width, width);
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
        swap(base, (char*)base + (size_t)i * width, width);
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

static int compare_char(const void *va, const void *vb)
{
        const char *a = va, *b = vb;
        return *a - *b;
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
    hsort(arr, n, sizeof(char*), compare_char);
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