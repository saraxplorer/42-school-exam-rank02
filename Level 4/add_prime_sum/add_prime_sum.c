#include <unistd.h>

void print_num(int n)
{
    char digit[] = "1234567890";
    if (n >= 10)
        print_num(n / 10);
    write(1, &digit[n % 10], 1);
}

int is_prime(int n)
{
    int i = 2;
    if (n <= 1)
        return 0;
    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int ft_atoi(char *str)
{
    int i = 0;
    int n = 0;
    while (str[i])
    {
        n = n * 10 + (str[i] - '0');
        i++;
    }
    return (n);
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int sum = 0;
        int num = ft_atoi(argv[1]);
        while (num > 0)
        {
            if (is_prime(num))
                sum += num;
            num--;
        }
        print_num(sum);
    }
    write(1, "0\n,", 1);
}