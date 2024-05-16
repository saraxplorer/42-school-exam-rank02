Basic Theory: Calculating the mirror number

Calculation fomula: 

mirrored_value for uppercase = (ASCII val of) 'Z' - original_value + (ASCII value of) 'A'; 

Subtracting argv[1][i] from 'Z' gives you the distance of the original letter from 'Z'.
Adding 'A' adjusts this distance to the mirrored position from 'A'.


mirrored_value for lowercase = (ascii value of) 'z' - original_value + (Ascii value of) 'a'

Challange:
after updating the argv[1][i] by the calculation, it strated writing the uppercase twice

Reason:
I used if ....if.....else other things

Solution:
if.....else if.....else other things

In the if...else if...else structure, only one block of code executes based on the first condition that evaluates to true. Once a condition is met, subsequent conditions are not evaluated.
In the if...if...else structure, each if statement is independent. If multiple conditions can be true, each corresponding block of code will execute. The else block, if present, is associated only with the last if statement and executes if none of the previous conditions are true.
