#include <unistd.h>
void ft_putnbr(int n)
{
    char base[] = "0123456789";
    if (n >= 10)
        ft_putnbr(n / 10);
    write(1, &base[n % 10], 1);
}
int main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "0\n", 1);
    else
    {
        ft_putnbr(argc - 1);
        write(1, "\n", 1);
    }
       
    

}