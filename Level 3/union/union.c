#include<unistd.h>

int check(char *str, int c, int index)
{
    int i = 0;
    while (i < index)
    {
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int k = 0;
    if (argc == 3)
    {
        while (argv[1][i] != '\0')
            i++;
        while (argv[2][j] != '\0')
        {
            argv[1][i] = argv[2][j];
            j++;
            i++;
        }
        i--;
        while (argv[1][k] != '\0')
        {
            if(check(argv[1], argv[1][k] , k) == 1)
                write(1, &argv[1][k], 1);
            k++;
        }

    }
    else
        write(1, "\n", 1);
}