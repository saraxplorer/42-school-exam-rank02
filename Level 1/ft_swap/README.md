Lesson 1: the theory goes: take a temporary int, put contents of b in it, then put contents of 'a' in 'b', then the contents of temp in 'a'. 

Lesson 2: the temp is int, not a pointer. 

Lesson 3: in the main function, also no need to make pointers, only int will do, just send the address to the function

Lesson 4: If the swap does not function, use printf to troubleshoot. For example, it changes the value of b but does not keep it changed. I found it by printf
``` c
#include <unistd.h>
#include <stdio.h>
void	*ft_swap(int *a, int *b)
{
	int temp;
	temp = *b;

	b = a;
	printf("%d\n", *b);
	*a = temp;
	printf("%d\n", *b);
	return 0;
}


int main()
{
	int a = 10;//Dont need to make a pointer, int will do 
	int b = 69;
	//printf("%d, %d\n", a, b);
	ft_swap(&a, &b);//send the address of a and b
	printf("%d, %d", a, b);
}
```
BIG LESSON: Why did it not work? The problem is "b=a". Apparently, this changes only the pointer b, it makes it point to a, not the value of b itself. So as soon as the value of 'a' is changed
b is changed. To change the value of b, we have to put dereferenced value of a. 
