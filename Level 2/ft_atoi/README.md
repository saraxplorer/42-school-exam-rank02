integers can be both numeric and non numeric. the integer of letters are the ascii values of them 

'A' corresponds to 65
'B' corresponds to 66
'C' corresponds to 67
'`!' corresponds to the integer 33
'`#' corresponds to the integer 35
'`$' corresponds to the integer 36
'`%' corresponds to the integer 37

On the other hand, numbers can be characters

For ft_atoi, we only need to convert the numeric values, not anything else because that's how the atoi works.

Step 1. skip spaces with a while loop

Step 2. if + sign, skip, if -, update variable sign

Step 3. main calculation:

  3.1. take an interger(to return), initialize to 0,
  3.2. make a while loop with limits 0-9
  3.3. then multiply the int with 10 for moving digits to right
  3.4. then minus the '0' from the given char/str to make it int from char
