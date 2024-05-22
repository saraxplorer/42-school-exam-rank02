#include <stdlib.h>
int *ft_range(int start, int end)
{
    int i = 0;
    int len = 0;
    if (start <= end)
        len = end - start + 1;
    else
        len = start - end + 1;//+1 because end position is inclused
    int *result;
    result = (int*) malloc(sizeof(int) * len);
    if (result == NULL)
    return NULL;
    while (i < len)
    {
        result[i]  = start;//assign the value of start
        if (start < end)
            start++;
        else
            start--;
        i++;
    }
    return(result);
}
#include<stdio.h>
int main()
{
    int *range = ft_range(-1, 2);
    int i = 0;
    while(i < 4)
    {
         printf("%d", range[i]);
         i++;
    }
   
}