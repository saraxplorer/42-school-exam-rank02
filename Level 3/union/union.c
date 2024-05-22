#include<unistd.h>

int check_dup(char *str, int c, int index)
{
    int i = 0;
    while (i < index)// Loop through the string up to the given index, ensuring we do NOT compare the current character with itself
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
            //first iteration, argv[1] will point to first char and argv[1][k] is the first char
            //the i < index(k) condition in check function, will prevent that loop from running thus prevent comparing with itself
            //second iteration, argv[1] will point to first char but for k++ here, it has moved on to the next char
            //The loop in check will then run up to the current index k.
            if(check_dup(argv[1], argv[1][k] , k) == 1)
                write(1, &argv[1][k], 1);
            k++;
        }

    }
    else
        write(1, "\n", 1);
}
