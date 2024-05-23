Development steps:

STEP 1. Find whether it is a palindrome:

      1.1. make a function that gets a start and end point, compares those points and subsequent points in a loop, the one by one, 
      It increases and reduces like this, start++ and end--: meaning those points are used as indexes

        1.1.1. The loop will continue as long as the start is smaller than end***Explanation later
        1.1.2.  to get the start and end point, we simply send one char as index (example i), from a loop, then send another series
                char from another loop(example j).for every i, the rest of the string will be sent using j++. So j gets updated as
                'i' or start every time.
  
   **How i and j Detect Palindromes:***
On the first iteration, both i and j are 0. The pal function checks the substring argv[1][0...0], which is just the first character. A single character is always a palindrome.
In subsequent iterations, j increments from i to the end of the string, checking progressively larger substrings.
For example:
For i = 0, j will be 0, 1, 2, 3, ... checking substrings argv[1][0...0], argv[1][0...1], argv[1][0...2], etc.
For i = 1, j will be 1, 2, 3, ... checking substrings argv[1][1...1], argv[1][1...2], argv[1][1...3], etc.
This way, the program checks all possible substrings and identifies the longest palindrom

STEP 2. If it is palindrome, find the longest one by compare and update:

      2.1. calculate length of current string, then compare inside the loop. That way any palindrome found can be counted.

STEP 3. Then print the longest one:

      3.1. If a palindrome with maximum length is found we calculate the palindrome lenght, which is by adding the start position with             the maximum length
      3.2. run a loop until the start reaches the palindrome length and write


***explanation how does != differ from < ????***

The != operator means "not equal to", and it's used to check if two values are not equal to each other. On the other hand, the < operator means "less than", and it's used to check if one value is smaller than another.

In the context of comparing start and end positions in the palindrome-checking function:

Using !=: The loop continues until start is not equal to end. This means the loop will continue until the start and end positions meet or cross each other. This condition doesn't ensure that all characters in the substring are checked, as it might stop prematurely.
Using <: The loop continues until start is less than end. This means the loop will continue until the start position is less than the end position. This condition ensures that all characters in the substring are checked, as it iterates from both ends towards the middle of the substring.

Imagine two runners, Alice and Bob, are running towards each other on a circular track. The track represents the string being checked for a palindrome, and Alice and Bob represent the start and end positions, respectively.

Using !=:
Alice and Bob keep running until they meet each other. Once they meet, the race is over, and they stop.
In terms of the palindrome check, this is like checking for a palindrome until the start and end positions meet or cross each other. The loop stops as soon as they meet, potentially missing some characters in the middle of the substring.
Using <:
Alice and Bob keep running until Alice is just behind Bob (but not necessarily at the same position). They stop when Alice catches up to Bob.
In terms of the palindrome check, this is like ensuring that Alice and Bob both cover all the ground on the circular track, starting from opposite ends and moving towards each other until they meet. This ensures that all characters in the substring are checked, as they move towards the middle.
In essence, the difference lies in whether the loop continues until the positions meet (!=) or until one position catches up to the other (<). The < condition ensures thorough coverage of the substring, similar to how both runners cover all parts of the circular track before they meet.
