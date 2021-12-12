#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* lc_memcpy( void* dest, const void* src, size_t count )
{
    for(size_t i = 0; i < count; i++)
    {
        *((char*)dest + i) = *((const char*)src + i);
    }
    return dest;
}

typedef struct date {
    int Day, Month, Year;
} t_date;

void* distributionsort(void* base, size_t n, size_t width, int field, int set,
    int (*get_key)(void* base, int field))
{
    int* count = calloc((size_t)set, width);    
    for (size_t i = 0; i < n; i++)
    {
        int key = get_key((char*)base + width * i, field);
        count[key]++;
    }
    for (int i = 0; i < set; i++)
    {
        count[i] += count[i - 1];
    }
    char* d = calloc(n, width);
    for (size_t i = n; i > 0; i--)
    {
        int key = get_key((char*)base + width * (i - 1), field);
        count[key]--;
        int j = count[key];
        memcpy(d + (size_t)j * width, (char*)base + (i - 1) * width, width);
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
    t_date* ptr = (t_date*)base;
    if (field == 0)
        return ptr->Year - 1970;
    if (field == 1)
        return ptr->Month - 1;
    return ptr->Day - 1;
}

int main()
{
    size_t n;
    scanf("%lu", &n);
    t_date* arr = malloc(n * sizeof(t_date));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d%d%d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
    }
    int key_set[3] = {60, 12, 30};
    arr = radixsort(arr, n, sizeof(t_date), key_set, 3, get_key);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d %d %d\n", arr[i].Year, arr[i].Month, arr[i].Day);
    }
    free(arr);
}