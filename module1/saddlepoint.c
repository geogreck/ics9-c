#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

int main()
{
    int a;
    size_t m, n;
    scanf("%lu%lu", &m, &n);
    int min_elements[n];
    for (size_t j = 0; j < n; ++j){
        min_elements[j] = INT_MAX;
    }
    int ans = INT_MIN;
    size_t ans_i = 11;
    size_t ans_j = 10;
    int max = ans;
    size_t max_ind = 0;
    for (size_t i = 0; i < m; i++){
        max = INT_MIN;
        for (size_t j = 0; j < n; j++)
        {
            scanf("%d", &a);
            if (a < min_elements[j]){
                if (ans == min_elements[j]){
                    ans = INT_MIN;
                }
                min_elements[j] = a;;
            }
            if (a > max){
                max = a;
                max_ind = j;
            }
        }
        if (max == min_elements[max_ind]){
            ans = max;
            ans_i = i;
            ans_j = max_ind;

        }
    }
    if (ans == INT_MIN){
        printf("none\n");
        return 0;
    }
    printf("%lu %lu\n", ans_i, ans_j);
    return 0;    
}