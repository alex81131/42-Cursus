#include <unistd.h>

void	rev_print(char *s)
{
	int	i = 0;

		while (s[i]) i++;
		i--;
		while (i >= 0)
		{
			write(1, &s[i], 1);
			i--;
		}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
