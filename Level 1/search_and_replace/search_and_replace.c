#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if ((argc == 4) && !argv[2][1] && !argv[3][1])//3 arguments mean 4 with the name and arg 2 and 3 must be 1 char
    {
        int i = 0;
        while (argv[1][i]!= '\0')
        {
            if (argv[1][i] == argv[2][0])
                write(1, &argv[3][0], 1);
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}