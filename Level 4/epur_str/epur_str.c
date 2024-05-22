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
				flag = 1;//then while proceeds and if more spaces found, flag will still be 1
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))// if a letter if found
			{
				if (flag == 1)
					write(1, " ", 1);//write ONLY one space for one or multiple spaces found
				flag = 0;//it is a must for the next space or bunch of spaces
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
