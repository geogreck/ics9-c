#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dsort(char* str)
{
    int count[26] = {0};
    for (char* p = str; *p; p++)
    {
        count[*p - 'a']++;
    }
    for (char i = 0; i < 26; i++)
    {
        while (count[(int)i])
        {
            *str = i + 'a';
            str++;
            count[(int)i]--;
        }
    }
}

int main()
{
    char* s = malloc(1000000 * sizeof(char));
    scanf("%s\n", s);
    dsort(s);
    printf("%s\n", s);
    return 0;
}