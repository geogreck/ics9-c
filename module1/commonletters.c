
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//char -> ulong
unsigned long convert(char s)
{
    if (isupper(s))
        return s - 65;
    if (islower(s))
        return s - 97 + 26;
    return 0;
}

//int -> char
char reverse_convert(unsigned long i)
{
    if (i < 26)
        return i + 65;
    else
        return i + 97 - 26;
}

int main()
{
    unsigned long a = 0, b = 0;
    char s;
    scanf("%c", &s);

    while (s != ' ')
    {
        a |= ((unsigned long)1 << convert(s));
        scanf("%c", &s);
    }

    scanf("%c", &s);

    while (s != '\n')
    {
        b |= ((unsigned long)1 << convert(s));
        scanf("%c", &s);
    }

    a = a & b;

    for (unsigned long i = 0; i < 52; i++)
    {
        if (a & ((unsigned long)1 << i))
        {
            printf("%c", reverse_convert(i));
        }
    }

    return 0;
}