#include <unistd.h>
void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char modulus = n % 10 + '0';
    write(1, &modulus, 1);
}
int ft_atoi(char *str)
{
    int i = 0;
    int n = 0;
    while (str[i]!= '\0')
    {
        n = n * 10 + str[i] - '0';
        i++;
    }
    return n;
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = ft_atoi(argv[1]);
        int first_digit = 1;
        while (first_digit <= 9)
        {
            ft_putnbr(first_digit);
            write(1, "x", 1);
            ft_putnbr(num);
            write(1, "=", 1);
            ft_putnbr(first_digit * num);
            write(1, "\n", 1);
            first_digit++;
        }
    }
    else
        write(1, "\n", 1);
}