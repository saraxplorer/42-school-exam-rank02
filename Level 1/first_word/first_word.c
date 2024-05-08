#include<unistd.h>
#include<stdio.h>

void display(char *str)
{
    int i = 0;
    while (str[i]== 32 || str[i] == 9)
        str++;
    while (str[i] != '\0' && (str[i]!= 32 && str[i]!= 9))
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        write(1, "\n", 1);
    }
    else if(argc == 2)
        display(argv[1]);
    return 0;
}
