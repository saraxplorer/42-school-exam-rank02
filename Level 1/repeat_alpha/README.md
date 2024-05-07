journey to repeat_alpha:

1. Calculate how many times each letter should be printed

   step 1. we check if the letter in str is in a-z or in A-Z.
   
   step 2. if it is within a-z, simply minusing the char 'a' from that letter will give a relative difference which index it belongs to.

   step 3. it gives one less position so we add + 1. So it looks like this:
   ```c
   if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            times = ((argv[1][i] + 1) - 'a');
   ```
   *how the calculation works: The ASCII value of 'A' or 'a' serves as a reference point for calculating the position of letters in the       alphabet. Since characters in the ASCII table are sequentially arranged, subtracting the ASCII value of 'A' from the ASCII value of       any uppercase letter gives us its position relative to 'A' in the alphabet.
   *Adding one cause times = ('A' - 'A') = (65 - 65) = 0, but we want a to be one, b to be 2 and so on.
   
3. use that times to control a while loop that will keep writing till the times become 0.
