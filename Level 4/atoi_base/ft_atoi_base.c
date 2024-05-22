int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int i = 0;
    int sign = 1;
    if (str[0] == '-')
        sign = -1;
    while(str[i])
    {
        if (str[i]>= '0' && str[i] <= '9')
            result = result * str_base + (str[i] - '0');
    
        else if (str[i]>= 'a' && str[i] <= 'f')
            result = result * str_base + (str[i] - 'a' + 10) ;
        
        else if (str[i]>= 'A' && str[i] <= 'F')
            result = result * str_base + (str[i] - 'A' + 10);

        i++;
    }
    return (sign * result);
}
#include<stdio.h>
int main()
{
    char *s = "b";
    printf("%d", ft_atoi_base(s, 16));

}