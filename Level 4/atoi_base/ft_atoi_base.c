int ft_atoi_base(char *str, int base)
{
	int i = 0;
	int result = 0;
	int value = 0;//to process chars
	int sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i]>= '0' && str[i] <= '9'))
			value = str[i] - '0';//add the prev results
		
		else if (str[i]>= 'a' && str[i]<= 'f')
			value = str[i] - 'a' + 10;
		
		else if (str[i]>= 'A' && str[i]<= 'F')
			value = str[i] - 'A' + 10;
		else
			return 0;//for invalid cases
		if (value >= base)// Ensure the value is valid for the given base
			return 0;
		result = result * base + value;
		i++;
	}
	return (sign * result);
}

#include <stdio.h>
int main()
{
	char *input = "123";
	printf("%d", ft_atoi_base(input, 20));//return of the function printed
}