#include <stdio.h>
#include <stdlib.h>

size_t lc_strlen(const char *s)
{
    size_t n = 0;
    while (*(s + n) != 0)
        n++;
    return n;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int height = atoi(*(argv + 1));
    int width = atoi(*(argv + 2));
    char* text = (*(argv + 3));
    size_t len = lc_strlen(text);
    if (width - 2 < len)
    {
        printf("Error\n");
        return 0;
    }
    for (size_t j = 0; j < width; j++)
    {
        printf("*");
    }
    printf("\n");
    for (size_t i = 1; i < height - 1; i++)
    {
        printf("*");
        if (i != (height - 1) / 2)
        {
            for (size_t j = 1; j < width - 1; j++)
            {
                printf(" ");
            }
        }else{
            for (size_t j = 1; j < (width - len)/ 2 + 1; j++)
            {
                printf(" ");
            }
            printf("%s", text);
            for (size_t j = 1; j < (width - len)/ 2; j++)
            {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for (size_t j = 0; j < width; j++)
    {
        printf("*");
    }
}