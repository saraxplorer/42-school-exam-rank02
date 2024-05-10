**New concept: Calculation**

**pseudo**

make/update the string as it should output and then write the new updated string.

**basic calculation**
(argv[1][i] - 'a' + 13) % 26) + 'a':

argv[1][i]: This represents the character at index i in the input string argv[1].

argv[1][i] - 'a': This calculates the position of the character relative to the lowercase letter 'a'. For example, if argv[1][i] is 'g', then 'g' - 'a' equals 6, because 'g' is the 7th letter in the alphabet, and 'a' is the first. This step effectively maps the characters 'a' through 'z' to the range 0 through 25.

(argv[1][i] - 'a' + 13): This adds 13 to the position calculated in step 2.

(argv[1][i] - 'a' + 13) % 26): This takes the result of step 3 and calculates the remainder when divided by 26. This ensures that the result stays within the range 0 through 25, effectively wrapping around the alphabet if necessary.

(argv[1][i] - 'a' + 13) % 26) + 'a': Finally, we add 'a' back to the result of step 4. This converts the result back to the ASCII value of the corresponding lowercase letter. For example, if the result is 7, adding 'a' gives us the ASCII value of 'h'.

let's go through the ROT13 transformation for the input string "abc":

Input String: "abc"

Processing Loop:

For 'a':

Calculate the position relative to 'a': 'a' - 'a' = 0

Add 13 to the position: 0 + 13 = 13

Take the remainder when divided by 26: 13 % 26 = 13

Add 'a' back to get the corresponding character: 13 + 'a' = 'n'

Output: 'n'

For 'b':

Calculate the position relative to 'a': 'b' - 'a' = 1

Add 13 to the position: 1 + 13 = 14

Take the remainder when divided by 26: 14 % 26 = 14

Add 'a' back to get the corresponding character: 14 + 'a' = 'o'

Output: 'o'

For 'c':

Calculate the position relative to 'a': 'c' - 'a' = 2

Add 13 to the position: 2 + 13 = 15

Take the remainder when divided by 26: 15 % 26 = 15

Add 'a' back to get the corresponding character: 15 + 'a' = 'p'

Output: 'p'

Output String: "nop"

So, the input string "abc" is transformed to "nop" after applying the ROT13 cipher.






