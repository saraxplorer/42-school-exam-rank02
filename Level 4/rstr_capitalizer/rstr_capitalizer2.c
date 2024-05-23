#include <unistd.h>
void capitalizer(char *str)
{
   int i = 0;
   while (str[i])
   {
        if (str[i + 1]== ' ' ||str[i + 1] == '\t' ||str[i + 1] == '\0')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }
        write(1, &str[i], 1);
       i++;
   } 
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "\n", 1);
    else
        {
            int i = 1;
            while (i < argc)
            {
                capitalizer(argv[i]);
                i++;
            }
         
        }
}
