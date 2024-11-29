# include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while (argv[1][i])
        {
            // Print the word
            while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            // Skip spaces/tabs after the word
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            // Print a single space if there's another word
            if (argv[1][i] != '\0')
                write(1, " ", 1);
        }     
    }
    write(1, "\n", 1);
}
