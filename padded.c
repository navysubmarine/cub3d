#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char    *ft_strdup_padded(const char *s)
{
    int        i;
    char    *new;

    new = malloc(sizeof(char) * (ft_strlen(s) + 3));
    if (new == NULL)
        return (NULL);
    new[0] = '0';
    i = 0;
    while (s[i])
    {
        new[i + 1] = s[i];
        i++;
    }
    new[i + 1] = '0';
    new[i + 2] = '\0';
    return (new);
}

int main()
{
  char *str;
  char *padded;
  
  str = "11211";
  padded = ft_strdup_padded(str);
  printf("padded = %s\n", padded);
  return 0;
}