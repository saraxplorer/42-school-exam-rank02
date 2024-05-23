#include <stdlib.h>
int     *ft_rrange(int start, int end)
{
    int len = 0;
    int i = 0;
    if (start < end)
        len = end - start + 1;
    else
        len = start -end + 1;
    int *result = (int *)malloc(sizeof(int) * len);
    while (i < len)
    {
        result[i] = end;//start at the end
        if (end < start)
            end++;
        else
            end--;
        i++;
    }
    return(result);
}
#include <stdio.h>
int main()
{
    int *x = ft_rrange(0, 0);
    int i = 0;
    while(i < 4)
    {
         printf("%d", x[i]);
         i++;
    }
   


    
}