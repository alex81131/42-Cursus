#include <unistd.h>

char	rotone(char c)
{
	if (('a' <= c && c <= 'y') || ('A' <= c && c <= 'Y'))
		c += 1;
	else if (c == 'z' || c == 'Z')
		c -= 25;
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i])
			ft_putchar(rotone(av[1][i++]));
	}
	write(1, "\n", 1);
	return (0);
}