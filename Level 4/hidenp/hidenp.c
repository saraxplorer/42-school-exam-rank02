#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int j = 0;
        int i = 0;
        while (argv[2][j] && argv[1][i])
        {
            if (argv[2][j] == argv[1][i])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
            write(1, "1\n", 1);
        else
            write(1, "0\n", 1);
    }
    write(1, "\n,", 1);

}
    