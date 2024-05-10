First try was to iterate through first string and for each char, iterate through the second one, and when found match, write. 
``` c
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while (argv[1][i] != '\0')
        {
            while (argv[2][j] != '\0')
            {
                if (argv[1][i] == argv[2][j])
                    write(1, &argv[1][i], 1);
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
However it was writing only one letter and stopping because after finding a matching character, it increments j, 
which moves to the next character in the second string. Consequently, when the outer loop continues to the next character in the first string, 
the inner loop will start comparing from where j was left off in the second string, potentially skipping characters that could have been matches.

This behavior results in only one letter being written to the output, followed by the program stopping prematurely because comparisons keep getting smaller and smaller

``` c
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while (argv[1][i] != '\0')
        {
            j = 0;
            while (argv[2][j] != '\0')
            {
                if (argv[1][i] == argv[2][j])
                    write(1, &argv[1][i], 1);
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
resetting j= 0 for each char makes it work. However it does not handle the case, where it needs to skip the repeated chars. 
The idea is to make a fuction that checks for duplicate chars in string, then send str1 and it's the chars, then pass str 2 and it's chars
The final code is in the source file
