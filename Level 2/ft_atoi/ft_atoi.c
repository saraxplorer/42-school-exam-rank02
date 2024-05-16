int ft_atoi(char *str)
{
	int i = 0;
	int n = 0;//we need a new interger to return
	int sign = 1;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] >= '\t' && str[i] <= '\r')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			else
				i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - '0';
		}
		else
			i++;
		i++;	
	}
	return (sign * n);
}

#include <stdio.h>

int main()
{
	char *s = "+23456tfde";
	printf("%d", ft_atoi(s));
}