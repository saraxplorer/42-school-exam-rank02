journey to fizzbuzz:
#1 consideration: integers for calculation and char 'num' for using in write function
``c
int main(void)
{
    int i;
    i = '1';
    while (i <= '9')
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            write(1, &i, 1);
            write(1, "\n", 1);
        }
        i++;
    }
    return 0;
}
``
this wont work because '1' means char 1, ascii value of which is 49. So 49 will be used for the calculations. For using the modulus % or any other calculation, number must be integer. so we add + '0' with it 
``c
int main(void)
{
    int i;
    i = 1;
    while (i <= 9)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            char digit = i + '0';//to make it char
			write(1, &digit, 1);
            write(1, "\n", 1);
        }
        i++;
    }
    return 0;
}
``
Then we divide the case with one digit and for two digits. Check out the soluton for that.
