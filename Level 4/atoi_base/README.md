Step 1. Convert a single digit character to an integer (base 10):

Write a function to convert a single character ('0' to '9') to its corresponding integer value.
Example: '3' should be converted to 3.

**Theory:** For digits '0' through '9', the ASCII values are sequential. To convert a character representing a digit to its corresponding integer value, you can subtract the ASCII value of '0' from the ASCII value of the character:

integer_value = char − ′0′

example: For 0: ’0’−′0′ == 48−48 = 0
``` c
int char_to_int(char digit)
{
	digit = digit - '0';
	return digit;
}

#include <stdio.h>
int main()
{
	char input = '7';
	printf("%d\n", input);//ASCII value of input is printed
	printf("%d", char_to_int(input));//return of the function printed
}
```

Step 2. Convert a single hexadecimal character to an integer (base 16):

Extend the function to handle hexadecimal characters ('0' to '9' and 'a' to 'f', 'A' to 'F').
Example: 'A' should be converted to 10, 'f' should be converted to 15.
Convert a string of digits to an integer (base 10):

Write a function to convert a string of characters representing a decimal number (e.g., "1234") to an integer.
Example: "1234" should be converted to 1234.
Handle negative numbers in base 10:

Extend the string-to-integer function to handle negative numbers (e.g., "-1234").
Example: "-1234" should be converted to -1234.
Convert a string of hexadecimal digits to an integer (base 16):

Write a function to convert a string of hexadecimal characters (e.g., "1A3f") to an integer.
Example: "1A3f" should be converted to 6719.
Generalize the function to handle different bases (up to base 16):

Extend the function to handle any base between 2 and 16, using the same logic as for base 10 and base 16.
Example: "101" in base 2 should be converted to 5 in base 10, "1A" in base 16 should be converted to 26 in base 10.Let's read a quick tutorial about what number base mean.
https://github.com/saraxplorer/bits_on_c/tree/731d6a1c5136d7a1a0fd9a3207e03b0c5e3575fa/Number%20Bases

Now read the subject again. 

**Explanation of "string argument str (base N <= 16)" from the question:**
In the context of the question, the term "string argument str (base N <= 16)" refers to a string (`char*` in C) that represents a number in a specific base.

1. **String Argument (`char*`)**: This refers to a sequence of characters terminated by a null character (`'\0'`). In C, a string is typically represented using an array of characters (`char[]`) or a pointer to the first character (`char*`). Each character in the string represents a digit or symbol.

2. **Base N <= 16**: This specifies the base of the number represented by the string. The base indicates the number of unique digits used to represent numbers. For example:
   - Base 2 (binary) uses digits 0 and 1.
   - Base 10 (decimal) uses digits 0 through 9.
   - Base 16 (hexadecimal) uses digits 0 through 9 and letters A through F (or a through f) to represent values from 10 to 15.

So, "base N <= 16" means that the function should be able to handle strings representing numbers in bases ranging from 2 to 16, inclusive.

characters (`char`) can be used to represent numbers in base 16 (hexadecimal). In hexadecimal notation, digits 0 through 9 are represented as usual, and digits 10 through 15 are represented by the letters A through F (or a through f) in either uppercase or lowercase.

For example:
- The character '0' represents the value 0 in hexadecimal.
- The character 'A' (or 'a') represents the value 10 in hexadecimal.
- The character 'F' (or 'f') represents the value 15 in hexadecimal.

So, when the question asks to convert a string argument `str` (base N <= 16) to an integer (base 10), it means the function should be able to convert a string representing a number in hexadecimal, decimal, or any other base up to 16 into its equivalent integer representation in base 10.

**the statement "Uppercase letters must also be recognized" means** 
that when converting a string representing a number from a base where letters are used as digits (e.g., hexadecimal), 
both lowercase and uppercase letters should be treated as equivalent.because the letters are case-insensitive in hexadecimal notation. 
For instance, the string "12fdb3" should be interpreted the same as "12FDB3" 

**int means decimal**
**ascii values are expressed in decimal**

**Bits on Ascii table**
The ASCII table assigns numeric values to characters.In the ASCII table, the numeric values are reserved for representing characters such as digits, letters, symbols, and control characters. For example:

The ASCII value 48 represents the character '0'.
The ASCII value 49 represents the character '1'.


**Breakdown**
Problem 1. convert a char to int.  







**Development Steps**
Step 1. first we make a while loop iterate through the string.

Step 2. if the first char is a minus, we make the int sign -1 and move one char ahead.

Step 3. Update the sring as all lowercase because the base of hexadecimal is lowercase.

    Challange: we cannot update the string because it is a "const char".
    Solution: we make a variable to store the changed value
Step 4. 
