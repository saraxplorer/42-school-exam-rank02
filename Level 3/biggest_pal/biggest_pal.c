#include <unistd.h>

int ft_strlen(char *str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}

int palli(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return 0;
		start++;
		end--;
	}
	return 1;
}
int main(int argc, char **argv)
{
	
	if (argc == 2)
	{
		int i = 0;
		int start = 0;
		int len = ft_strlen(argv[1]);
		int max_start = 0;
		int max_len = 0;

		while (i <= len)//iterate until reaches length
		{
			int j = i;//reset j to same value as i in each iteration?
			while (j < len)//also iterate the number of lenth
			{
				if (palli(argv[1], i, j))//i and j same value for start and end
				{
					int curr_len = j - i + 1;//1? coz i==j?
					if (curr_len >= max_len)
					{
						max_len = curr_len;//set max_len as curr_lenth
						max_start = i;
					}
				}
				j++;
			}	
			i++;
		}
		if (max_len > 0)
		{
			int k = max_start;
			while (k < max_start + max_len)
			{
				write(1, &argv[1][k], 1);
				k++;
			}
		}
		write(1, "\n", 1);
	}
	else
		write (1, "\n", 1);
}