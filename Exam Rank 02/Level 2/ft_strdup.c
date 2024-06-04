#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i = 0;

	while(s[i]) i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	len = ft_strlen(src);
	int	i = 0;
	char	*s;

	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while(i < len)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s = ft_strdup(av[1]);

	(void)ac;
	printf("String: %s\n", av[1]);
	printf("String: %s\n", s);
	free(s);
	return (0);
}
*/