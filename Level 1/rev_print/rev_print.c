#include<unistd.h>
#include<printf.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i]!='\0')
    {
        i++;
    }
    return i;
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int len = ft_strlen(argv[1]);
         printf("%d\n", len);
        while (len != 0)
        {
         write(1, &argv[1][len - 1], 1);
          len--;
        }
    }
    else
        write(1, "\n", 1);

}