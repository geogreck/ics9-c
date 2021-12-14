#include <stdio.h>
#include <stdlib.h>

typedef union Int32
{
    int x;
    unsigned char bytes[4];
} u_Int32;


void* lc_memcpy( void* dest, const void* src, size_t count )
{
    for(size_t i = 0; i < count; i++)
    {
        *((char*)dest + i) = *((const char*)src + i);
    }
    return dest;
}

void* distributionsort(void* base, size_t n, size_t width, int field, int set,
    int (*get_key)(void* base, int field))
{
    int* count = calloc((size_t)set, width);    
    for (size_t i = 0; i < n; i++)
    {
        int key = get_key((char*)base + width * i, field);
        count[key]++;
    }
    for (int i = 1; i < set; i++)
    {
        count[i] += count[i - 1];
    }
    char* d = calloc(n, width);
    for (size_t i = n; i > 0; i--)
    {
        int key = get_key((char*)base + width * (i - 1), field);
        count[key]--;
        int j = count[key];
        lc_memcpy(d + (size_t)j * width, (char*)base + (i - 1) * width, width);
    }
    free(base);
    free(count);
    return d;
}

void* radixsort(void* base, size_t n, size_t width, int* key_set, int set_n, 
    int (*get_key)(void* base, int field))
{
    void* d = base;
    for (int i = set_n - 1; i >= 0; i--)
    {
        d  = distributionsort(d, n, width, i, key_set[i], get_key);
    }
    return d;
}

int get_key(void* base, int field)
{
    u_Int32* ptr = base;
    if (!field)
        return ptr->bytes[0] ^ 128;
    return ptr->bytes[3 - field];
}


int main()
{
    size_t n;
    scanf("%lu", &n);
    int* arr = malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key_set[4] = {255, 255, 255, 255};
    arr = radixsort(arr, n, sizeof(int), key_set, 4, get_key);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}