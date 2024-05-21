#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int flag = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;//skip consecutive spaces in the beginning
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;//flag 1, if we find one space
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))// if a word if found
			{
				if (flag == 1)
					write(1, " ", 1);//write one space manually
				flag = 0;//and set the flag to 0 for next space/word
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	else
		write (1, "\n", 1);
}