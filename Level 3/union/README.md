Development journey: the one that worked

Step 1. Join the two strings:

	1.1. Join them without allocating memory.
 	1.2. use two separate while loops to iterate.
  	1.3. try to print/write the joined string meanwhile. Important: we would need a new iterator for 	the new joined string because i has the number of the concatenated string, not 0. to iterate 		through the whole string, we would need a new iterator that starts from 0.

Step 2. 

Development journey: the one that did not work
This is not the solution to the problem. These were my first approaches. They can each be treated as mini projects. However I did it in a different approach finally, which is in the source file.

Approach 1: It almost writes, it only cannot identify doubles. So there is Approach 2.
Step 1: Write two strings if we have 2 arguments, otherwise write a newline
```c
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		while (argv[1][i]!='\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][j]!= '\0')
		{
			write(1, &argv[2][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
Step 2: write all the chracters that match in both of them in one 
``` c
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j;
		while (argv[1][i]!='\0')
		{
			j = 0;//must reset j=0 for each iteration
			while (argv[2][j]!='\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					write(1, &argv[1][i], 1);
					break; //stop searching once found a match
				}
				j++;
			}
			
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
Here i take go through the first string and then take one char by one char (that's why j=0 in each iterartion) from str 2 and compare with the whole str1. 
if a match found write and "break". 

Step 3. Now let's do the opposite, write the letters that are unique in each of them. For making it simpler, let's write the unique chars in str 1. 
   I wanted to write each char if mismatched but let's explain why it is not as simple.
```c
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;//for each time i++, j should begin at 0
			while (argv[2][j]!= '\0')
			{
				if (argv[1][i] != argv[2][j])
				{
					write(1, &argv[1][i], 1);
				}
				j++;
			}
			i++;
		}
	
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
It outputted ./a.out "rien" "cette phrase ne cache rien"         
rrrrrrrrrrrrrrrrrrrrrrrriiiiiiiiiiiiiiiiiiiiiiiiieeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnneeee    pppphhhhrrrraaaasssseeee    nnnneeee    ccccaaaacccchhhheeee    rrrriiiieeeennnn

because I am comparing each character of argv[1] with every character of argv[2], I am writing the character from argv[1] to the output stream every time there's a mismatch.

this happens for every character in argv[2], regardless of whether there's a match later in argv[2]. 

To fix this, I should first detect if a char matches with any letter in the second string, then ONLY if they do not match any character in argv[2], write characters from argv[1] . 
A flag can keep track whether a match is found and also be used to only write the character if no match is found after iterating through argv[2].
``` c
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;//for each time i++, j should begin at 0
			int flag_match = 0;
			while (argv[2][j]!= '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					flag_match = 1;
				}
				j++;
			}
			if (flag_match != 1)
				write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
Step 4. Do the same for other one. This writes all the unique chars for both strings
```c
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;//for each time i++, j should begin at 0
			int flag_match = 0;
			while (argv[2][j]!= '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					flag_match = 1;
				}
				j++;
			}
			if (flag_match != 1)
				write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][i] != '\0')
		{
			int j = 0;
			int flag_match = 0;
			while (argv[1][j]!= '\0')
			{
				if (argv[2][i]== argv[1][j])
					flag_match = 1;
				j++;
			}
			if (flag_match != 1)
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```

step 5. Now let's write the matched chars as well once. So I will add else if the flag is matched, write. 
``` c
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;//for each time i++, j should begin at 0
			int flag_match = 0;
			while (argv[2][j]!= '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					flag_match = 1;
				}
				j++;
			}
			if (flag_match != 1)
				write(1, &argv[1][i], 1);
			else if (flag_match == 1)
				write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][i] != '\0')
		{
			int j = 0;
			int flag_match = 0;
			while (argv[1][j]!= '\0')
			{
				if (argv[2][i]== argv[1][j])
					flag_match = 1;
				j++;
			}
			if (flag_match != 1)
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
This writes both matched and unmatched ones but it does not check for doubles. Also the match and mismatch may not be necessary because the subject only requires to check for doubles.
The following addition can skip consecutive same letters. 
``` c
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;//for each time i++, j should begin at 0
			int flag_match = 0;
			while (argv[2][j]!= '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					flag_match = 1;
				}
				j++;
			}
			if (flag_match != 1 && argv[1][i]!=argv[1][i+1])
				write(1, &argv[1][i], 1);
			else if (flag_match == 1 && argv[1][i]!=argv[1][i+1])
				write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][i] != '\0')
		{
			int j = 0;
			int flag_match = 0;
			while (argv[1][j]!= '\0')
			{
				if (argv[2][i]== argv[1][j])
					flag_match = 1;
				j++;
			}
			if (flag_match != 1 && argv[2][i]!=argv[2][i+1])
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```

Approach 2: 
Step 1. write the first string without doubles.
``` c
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;
			int dup = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
				{
					dup = 1;
					break ;
				}
				j++;
			}
			if (dup != 1)
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
It works because it writes each character to the output as soon as it's encountered, and the dup flag comes later, when duplicate is found. 
Step 2. Now we do it for both stings
``` c
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i]!='\0')
		{
			int j = 0;
			int dup = 0;//reset for each char in argv[1]
			while (j < i)
			{
				if (i!=j && (argv[1][i] == argv[1][j]))
					dup = 1;
				j++;
			}
			if (dup != 1)
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i]!= '\0')
		{
			int j = 0;
			int dup = 0;
			while (j < i)
			{
				if (i!=j && (argv[2][i] == argv[2][j]))
					dup = 1;
				j++;
			}
			if (dup != 1)
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
```
Step 3. Now we do them together / each-other: 

