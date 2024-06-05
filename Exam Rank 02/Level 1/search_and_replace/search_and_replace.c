#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])	i++;
	return (i);
}

int	main (int ac, char **av)
{
	int	i = 0;

	if (ac == 4 && ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1)
	{
		while (av[1][i])
		{
			if (av[1][i] == *av[2])
				av[1][i] = *av[3];
			ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}