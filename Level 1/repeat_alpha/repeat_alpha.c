#include<unistd.h>
#include<stdio.h>

void write_times(char a, int times)
{
    
    while (times > 0)
    {
        write(1, &a, 1);
        times--;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int times = 0;
        
        while (argv[1][i]!= '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                times = (argv[1][i] + 1 - 'a'); 
                write_times(argv[1][i], times);
            }
            else if (argv[1][i]>='A' && argv[1][i]<= 'Z')
            {
                times = (argv[1][i] + 1 - 'A');
                write_times(argv[1][i], times);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        
    }
    else
        write(1, "\n", 1);
}