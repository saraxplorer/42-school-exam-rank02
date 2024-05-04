journey to rev_print>

Whenever question says: If the number of parameters is not 1, the program displays a newline.
there can be 2 cases- (argc < 2) and (argc > 2). we only need argc==2. so we write, 
```c
 if (argc == 2) //only case we need to work on
    {
        code
    }
    else //cause there can be more cases
        write(1, "\n", 1);
```
