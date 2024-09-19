#include<unistd.h>

int check_dup(char *str, int c, int index)
{
    int i = 0;
    while (i < index)  // Loop through the string up to the given index
    {
        if (str[i] == c)  // If the character at str[i] matches the character `c` (current character being checked)
            return 0;  // If a match is found, return 0 indicating this character is a duplicate
        i++;  // Move to the next character
    }
    return 1;  // If no match is found, return 1 indicating this character is unique
}


int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int k = 0;
   if (argc == 3)  // Check if exactly 2 arguments are passed (in addition to the program name).
{
    int i = 0;  // Variable `i` will track the length of `argv[1]` (the first string).
    int j = 0;  // Variable `j` will track the index of `argv[2]` (the second string).
    int k = 0;  // Variable `k` will be used to iterate through the combined string later.

    while (argv[1][i] != '\0')  // Find the length of `argv[1]` (the first string) by iterating until the null terminator.
        i++;

    while (argv[2][j] != '\0')  // Append `argv[2]` (the second string) to the end of `argv[1]` (the first string).
    {
        argv[1][i] = argv[2][j];  // Copy each character from `argv[2]` to the end of `argv[1]`.
        j++;  // Move to the next character in `argv[2]`.
        i++;  // Move to the next position in `argv[1]` where the character is being appended.
    }

    i--;  // Decrement `i` because `i` now points to the null terminator after appending, and we want to start iterating over the combined string.

    while (argv[1][k] != '\0')  // Loop through the newly combined string (`argv[1]` now contains both the original and appended `argv[2]`).
    {
        // In the first iteration, `argv[1][k]` points to the first character of the combined string.
        // The `check_dup` function checks if the character `argv[1][k]` has already appeared earlier in the string.
        // The loop inside `check_dup` compares up to the current index `k` to avoid comparing the character with itself.
        if (check_dup(argv[1], argv[1][k], k) == 1)  // If `check_dup` returns 1, it means the character is unique up to this point.
            write(1, &argv[1][k], 1);  // Write the unique character to the output.
        k++;  // Move to the next character in the combined string.
    }
}
else
    write(1, "\n", 1);  // If the argument count is not 3, print a newline.

