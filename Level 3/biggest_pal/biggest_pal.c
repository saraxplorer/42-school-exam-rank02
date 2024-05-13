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
		start++;//because this must go forward
		end--;//this must match backwards
	}
	return 1;
}

int main(int argc, char **argv)
{
	
	if (argc == 2)
	{
		int i = 0;//primary index to iterate through string
		int start = 0;
		int len = ft_strlen(argv[1]);
		int max_start = 0;
		int max_len = 0;

		while (i <= len)//iterate until reaches length of argv[1]; i keeps increasing by 1
		{
			int j = i;//start each iteration from i; j iterates from i to end for each 'ith' position
			while (j < len)//'i' is constant here for each iteration; j is main iterator from here on
			{
				if (palli(argv[1], i, j) == 1)//i is start(because it is contant in each iteration, j increases)
				{
					int curr_len = j - i + 1;//difference from strat to end; regular substracting cause 1 less, so add 1
					if (curr_len >= max_len)//find the 'biggest' pal by comparing and updating
					{
						max_len = curr_len;//set max_len as curr_lenth
						max_start = i;
					}
				}
				j++;
			}	
			i++;
		}
		if (max_len > 0)//print if biggest_pal is found
		{
			int k = max_start;//we stored the starting position of the biggest pal
			int pal_len = max_start + max_len;//calculate length 
			while (k < pal_len)
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