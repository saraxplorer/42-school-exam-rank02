**Step 1. Convert a single digit character to an integer (base 10):**

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

**Step 2. Convert a single hexadecimal character to an integer (base 16):**

Extend the function to handle hexadecimal characters ('0' to '9' and 'a' to 'f', 'A' to 'F').
Example: 'A' should be converted to 10, 'f' should be converted to 15.
**Theory:** letter - 'A': This part calculates the difference of the given letter relative to the character 'A'. For example, if the letter is 'A', the result will be 0. If the letter is 'B', the result will be 1, and so on. + 10: After calculating the offset, we add 10 to the result. 
This is because in hexadecimal notation, the characters 'A' to 'F' represent the numbers 10 to 15 in base 10.

``` c
int char_to_int(char letter)
{
	if (letter >= '0' && letter <= '9')
		letter = letter - '0';
	if (letter >= 'a' && letter <= 'z')
		letter = letter - 'a' + 10;
	if (letter >= 'A' && letter <= 'Z')
		letter = letter - 'A' + 10;
	return letter;
}

#include <stdio.h>
int main()
{
	char input = 'D';
	printf("%d\n", input);//ASCII value of input is printed
	printf("%d", char_to_int(input));//return of the function printed
}
```

**Ster 3. Convert a string of digits to an integer (base 10):**

Write a function to convert a string of characters representing a decimal number (e.g., "1234") to an integer.
Example: "1234" should be converted to 1234.

**Theory:** 
1. It takes a pointer to the string and returns an int. So we make an int to store the result and return
2. the previous result must be added in each iteration otherwise, it will only give out the result of the last iteration.
3. the result must be moved to the left by *10 in each iteration. Otherwise it will give garbage value
``` c
int char_to_int(char *str)
{
	int i = 0;
	int result = 0;
	while (str[i] != '\0')
	{
		if (str[i]>= '0' && str[i] <= '9')
		{
			result = result * 10;//shift the result to left
			result = result + str[i] - '0';//add the prev results
		}
		i++;
	}
	
	return result;
}

#include <stdio.h>
int main()
{
	char *input = "234567";
	printf("%d", char_to_int(input));//return of the function printed
}
```
**Step 4. Handle negative numbers in base 10:**

Extend the string-to-integer function to handle negative numbers (e.g., "-1234").
Example: "-1234" should be converted to -1234.
```c
int char_to_int(char *str)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i]>= '0' && str[i] <= '9')
		{
			result = result * 10;//shift the result to left
			result = result + str[i] - '0';//add the prev results
		}
		i++;
	}
	
	return (sign * result);
}

#include <stdio.h>
int main()
{
	char *input = "-234567";
	printf("%d", char_to_int(input));//return of the function printed
}
```
***Step 5. Convert a string of hexadecimal digits to an integer (base 16):**

Write a function to convert a string of hexadecimal characters (e.g., "1A3f") to an integer.
Example: "1A3f" should be converted to 6719.
**Theory**
Why Multiply by 16?
Hexadecimal is a base-16 number system. This means each digit represents a power of 16, just as each digit in a decimal (base-10) number represents a power of 10.

Place Value in Different Bases:

Decimal (base 10): Each digit is multiplied by a power of 10. For example, 1234 in decimal is calculated as:
1×10^3+2×10^2+3×10^1+4×10^0

Hexadecimal (base 16): Each digit is multiplied by a power of 16. For example, 1A3F in hexadecimal is calculated as:
1×16^3+𝐴×16^2+3×16^1+𝐹×16^0
Here, A = 10 and F = 15 in decimal.

**Step 6. do both base 10 and 16 together:**
``` c
int ft_atoi_base(char *str, int base)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((base == 10) && (str[i]>= '0' && str[i] <= '9'))
		{
			result = result * 10;//shift the result to left
			result = result + str[i] - '0';//add the prev results
		}
		else if ((base == 16) && (str[i]>= '0' && str[i] <= '9'))
		{
			result = result * 16;//shift the result to left
			result = result + str[i] - '0';//add the prev results
		}
		else if (str[i]>= 'a' && str[i]<= 'z')
		{
			result = result * 16;
			result = result + str[i] - 'a' + 10;
		}
		else if (str[i]>= 'A' && str[i]<= 'Z')
		{
			result = result * 16;
			result = result + str[i] - 'A' + 10;
		}
		i++;
	}
	
	return (sign * result);
}

#include <stdio.h>
int main()
{
	char *input = "1A3f";
	printf("%d", ft_atoi_base(input, 10));//return of the function printed
}
```
**Step 7. Generalize the function to handle different bases (up to base 16):**

Extend the function to handle any base between 2 and 16, using the same logic as for base 10 and base 16.
Example: "101" in base 2 should be converted to 5 in base 10, "1A" in base 16 should be converted to 26 in base 10. 


Let's read a quick tutorial about what number base mean.
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
