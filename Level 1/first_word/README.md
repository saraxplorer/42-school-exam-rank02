
Approach 1:

while (str[i] != '\0' && (str[i]!= 32 || str[i]!= 9)):
This is like saying, "I'll keep eating snacks as long as they're not apples or not bananas." But here's the trick: if it's not an apple, it must be a banana, and if it's not a banana, it must be an apple. So no matter what snack you have, you'll always keep eating because it fits one of the rules!
while (str[i] != '\0' && (str[i]!= 32 && str[i]!= 9)):
This is different. It's like saying, "I'll keep eating snacks as long as they're not apples and not bananas." Now, you'll only eat if the snack is neither an apple nor a banana. So, when you get an apple or a banana, you'll stop eating because it doesn't meet both rules at the same time.

Approach 2:

The words can be written with a loop running until space. It writes everything but does not skip the first spaces. 
```c
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i]!= ' ')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	
}
```
so I added a if like this 
if (argv[1][0] == ' ')
argv[1][i]++;
The wrong thing is if does not help skipping but while! Even if the first position skips, it will not help consecutive spaces. so we need while.
