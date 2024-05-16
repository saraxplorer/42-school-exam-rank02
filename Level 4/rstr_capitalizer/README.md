**New concept: Dealing with multiple number of arguments**
When we need to do the same thing for multiple number of arguments, we need to automate that. To achieve that, we need to make a function to do the task and 
pass the arguments through that.
``` c
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc <= 1)// Check if there are command-line arguments
		return;\\or do as instructed;
	else // If there are arguments, perform the action
		{
			int i = 1;//index for argc; // Start with the first argument; the index starts at 1 because argv[0] is the program name
			while (i >= 1)
			{
				function(argv[i]);//pass one argv
				i++;//move to next argv
			}
		}
}
```

**New concept: Segfault**
This program  will segfault. because of the while (i >= 1) line

while (i >= 1):

This condition will always be true because i starts at 1 (to skip the program name in argv[0]), and it remains greater than or equal to 1 throughout the loop.
Since i is never decremented, the loop will continue indefinitely, causing an infinite loop.

while (i < argc):

This condition ensures that the loop will continue as long as i is less than the value of argc.
Since i starts at 1 (to skip the program name) and is incremented with each iteration, it will eventually reach the value of argc, 
causing the loop to terminate when all command-line arguments have been processed.
