int	check(char *s, char *str)
{
	if (*s == '\0')
		return (1);
	while (*str)
	{
		while (*str && *s && *str == *s)
		{
			str++;
			s++;
		}
		if (*s == '\0')
			return (1);
		str++;
	}
	return (0);
}
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (check(av[1], av[2]) == 1)
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}