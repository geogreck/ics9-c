#include <stdio.h>

void input_arr(int* arr)
{
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int find(int a, int* arr)
{
    int flag = 0;
    for (int i = 0; i < 8; i++)
    {
        flag += a == arr[i];
    }

    return flag;
}

int main()
{
    int a[8], b[8];

    input_arr(a);
    input_arr(b);

    int flag = 1;
    for (int i = 0; i < 8; i++)
    {
        flag = find(a[i], b);
        if (!flag)
            break;
    }

    if (flag)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}