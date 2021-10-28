#include <stdio.h>

int array[] = {1, 2, 3, 4, 5, 3, 2, -5};

int my_less(unsigned long i, unsigned long j)
{
    return array[i] < array[j];
}

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
    if (less(1, 0))
    {
        return 0;
    } 
    else 
    { 
        if (less(nel - 2, nel - 1))
        {
            return nel - 1;
        } 
        else
        {
            for (size_t i = 1; i < nel - 1; i++)
            {
                if (less(i - 1, i) && less(i + 1, i))
                {
                    return i;
                }
            }
        }
    }
    return 0;
}

int main()
{
    unsigned long i = peak(8, my_less);
    //printf("%lu", i);
    if ((i == 0 || array[i] >= array[i-1]) && (i == 7 || array[i] >= array[i+1])){
        printf("CORRECT\n");
    } else {
        printf("WRONG\n");
    }
    return 0;
}