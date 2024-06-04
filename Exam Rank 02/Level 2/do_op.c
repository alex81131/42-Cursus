#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	i;

	if (ac == 4)
	{
		a = atoi(av[1]);
		b = atoi(av[3]);
		if (*av[2] == '+')
			i = a + b;
		if (*av[2] == '-')
			i = a - b;
		if (*av[2] == '*')
			i = a * b;
		if (*av[2] == '/')
			i = a / b;
		if (*av[2] == '%')
			i = a % b;
		printf("%d\n", i);
	}
	else
		write(1, &"\n", 1);
	return (0);
}