#include <unistd.h>
int check(char *str, int a, int index)
{
    int i = 0;
    while (i < index)
    {
        if (str[i] == a)
            return 0;
        i++;
    }
    return 1;
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while (argv[1][i] != '\0')
        {
            j = 0;
            while (argv[2][j] != '\0')
            {
                if (argv[1][i] == argv[2][j] && check(argv[1], argv[1][i], i) == 1
                    && check(argv[2], argv[2][j], j))
                    write(1, &argv[1][i], 1);
                j++;
            }
            i++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}