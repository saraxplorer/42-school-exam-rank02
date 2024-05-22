#include <unistd.h>

void print_hex(int n)
{
    char base[] = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16); //make the big num small by recursive diving
    write(1, &base[n % 16], 1);//write the base value at index[n % 16] 
    
}
int ft_atoi(char *str)
{
        int i = 0;
        int n = 0;
        while(str[i])
        {
            n = n * 10 + (str[i] - '0');
            i++;
        }
        return n;
}
int main(int argc, char **argv)
{
    

    if (argc == 2)
    {
        int number = ft_atoi(argv[1]);
        print_hex(number); 
    }
    write(1, "\n,", 1);
}