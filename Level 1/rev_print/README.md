



# Whenever question says: If the number of parameters is not 1, the program displays a newline.
there can be 2 cases- (argc < 2) and (argc > 2). we only need argc==2. so we write, 
```c
 if (argc == 2) //only case we need to work on
    {
        code
    }
    else //cause there can be more cases
        write(1, "\n", 1);
```
We can reverse write a string by counting it's length and then write backwods by reducing length
```c
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i]!='\0')
    {
        i++;
    }
    return i;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int len = ft_strlen(*argv);//this was wrong, should be (argv[1])
        while (len != 0)
        {
         write(1, &argv[1][len - 1], 1);//len-1 coz indexing begins from 0
         len--;
        }
    }
    else
        write(1, "\n", 1);
    
}
```

