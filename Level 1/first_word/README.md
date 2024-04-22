while (str[i] != '\0' && (str[i]!= 32 || str[i]!= 9)):
This is like saying, "I'll keep eating snacks as long as they're not apples or not bananas." But here's the trick: if it's not an apple, it must be a banana, and if it's not a banana, it must be an apple. So no matter what snack you have, you'll always keep eating because it fits one of the rules!
while (str[i] != '\0' && (str[i]!= 32 && str[i]!= 9)):
This is different. It's like saying, "I'll keep eating snacks as long as they're not apples and not bananas." Now, you'll only eat if the snack is neither an apple nor a banana. So, when you get an apple or a banana, you'll stop eating because it doesn't meet both rules at the same time.
