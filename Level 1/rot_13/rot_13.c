#include<unistd.h>

int main(int argc, char **argv)
{
   if (argc == 2)
   {
        
        int i = 0;
        while (argv[1][i]!= '\0')
        { 
            if (argv[1][i]>='a' && argv[1][i]<='z')
                argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a';
            else if (argv[1][i]>='A' && argv[1][i]<='Z')
                argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
            write(1, &argv[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
   }
   else
        write(1, "\n", 1);
}