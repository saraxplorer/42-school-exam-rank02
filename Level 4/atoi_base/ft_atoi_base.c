int char_to_int(char c, int base)
{
  int max_digit;
  if (base <= 10)//decimal or smaller
    max_digit = base + '0';//turn base into int
  else//bigger than 10, means hexadecimal
    max_digit = base - 10 + 'a'; //16- 10 + 'a == 102, ascii of f//hexadecimal base
  if (c >= '0' && c <= '9' && c <= max_digit)//numerical char
		return (c - '0');//numeric int/ascii
	else if (c >= 'a' && c <= 'f' && c <= max_digit)//lowercase hexa
		return (10 + c - 'a');//ascii 
	else
		return (-1);
}
int ft_atoi_base(const char *str, int str_base)
{
  int result = 0;
  int sign = 1;
  int digit;
  int i = 0;
  char c;

  while (str[i] != '\0')
  {
    
    if (str[0] == '-')//handle minus sign
    {
       sign = -1;
       i++;
    }
    if (str[i] >= 'A' && str[i] <= 'Z') //Handle uppercase
        c = c + ('a' - 'A');//make all lowercase, and store it in a char, because we 
                          //cannot modify a const str
    digit = char_to_int(c, str_base);
    while (digit >= 0)
    {
      result = result * str_base;//move one digit
      result = result + (digit *sign);//??
      i++;//is it right?
    }
    i++;
  }
}
