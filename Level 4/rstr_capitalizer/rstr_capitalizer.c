#include <unistd.h>

void rstr(char *str)
{
	int i = 0;
	while (str[i] !='\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && str[i + 1] == ' ' 
				|| str[i + 1] == '\t' || str[i + 1] == '\0')
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
		{
			int i = 1;//index for argc; so minimum must be 1
			while (i < argc)
			{
				rstr(argv[i]);
				write(1, "\n", 1);//pass one argv
				i++;//move to next argv
			}
		}
}