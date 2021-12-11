#include <stdio.h>
#include <limits.h>
#include <string.h>
//САША ПРОСТИ
int n;
int len[10];
char arr[10][BUFSIZ];
int ans = INT_MAX;
unsigned char used[10];

char *lc_strcpy(char *restrict dest, const char *restrict src)
{
    size_t n = 0;
    while (*(src + n))
    {
        *(dest + n) = *(src + n);
        n++;
    }
    *(dest + n) = 0;
    return dest;
}

char *lc_strcat(char *str1, char *str2)
{
    char *pt = str1;
    while(*pt!='\0') 
        pt++;
    while(*str2!='\0') 
        *pt++ = *str2++;
    *pt = '\0';
    return str1;
}

void gen(char* cur, int cur_len, int used_count)
{
    if (used_count == n)
    {
        ans = cur_len < ans ? cur_len : ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
            if (!used[i]) 
            {
                used[i] = 1;
                int overlap = calc_overlap(cur_len, cur, len[i], arr[i]);
                strcat(cur, arr[i] + overlap);
                gen(cur, cur_len + len[i] - overlap, used_count + 1);
                cur[cur_len] = '\0';
                used[i] = 0;
            }
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; ++i) 
    {
        len[i] = (int)strlen(arr[i]);
    }
    for (int i = 0; i < n; ++i) 
    {
        char buf[BUFSIZ * 10];
        used[i] = 1;
        lc_strcpy(buf, arr[i]);
        gen(buf, len[i], 1);
        used[i] = 0;
    }
    printf("%d\n", ans);
    return 0;
}