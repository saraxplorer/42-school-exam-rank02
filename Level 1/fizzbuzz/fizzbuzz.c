
#include <unistd.h>

int main(void)
{
    int i;
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            
			if(i <= 9)
			{
				char digit = i + '0';
				write(1, &digit, 1);
            	write(1, "\n", 1);
			}
			else
			{
				char tens = i / 10 + '0';
				char units = i % 10 + '0';
				write(1, &tens, 1);
				write(1, &units, 1);
				write(1, "\n", 1);
			}
        }
        i++;
    }
    return 0;
}
