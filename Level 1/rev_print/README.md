journey to rev_print>

## ARGV:
The argv parameter stands for "argument vector" and is an array of strings(char *argv[])(most of the time), which is equivalent to char **argv. This allows the main function to receive and process command-line arguments effectively.

## Whenever question says: If the number of parameters is not 1, the program displays a newline.
there can be 2 cases- (argc < 2) and (argc > 2). we only need argc==2. so we write, 
```c
 if (argc == 2) //only case we need to work on
    {
        code
    }
    else //cause there can be more cases
        write(1, "\n", 1);
```
