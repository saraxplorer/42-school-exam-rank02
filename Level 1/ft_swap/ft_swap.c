#include <unistd.h>
#include <stdio.h>
void	*ft_swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return 0;
}


int main()
{
	int a = 10;//Dont need to make a pointer, int will do 
	int b = 69;
	ft_swap(&a, &b);//send the address of a and b
	printf("%d, %d", a, b);
}