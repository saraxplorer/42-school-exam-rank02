
char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while(s2[i]!='\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';//necessary
	return(s1);
}

#include <stdio.h>
int main()
{
	char s1[10];//segfaults if used pointer
	char *s2 = "chf ufb";
	ft_strcpy(s1, s2);
	printf("%s", s1);
}
