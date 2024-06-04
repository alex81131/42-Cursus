#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*rot13(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (('N' <= s[i] && s[i] <= 'Z') || ('n' <= s[i] && s[i] <= 'z'))
			s[i] -= 13;
		else if (('A' <= s[i] && s[i] <= 'M') || ('a' <= s[i] && s[i] <= 'm'))
			s[i] += 13;
		i++;
	}
	return (s);
}

int	main(int ac, char **av)
{
	char *str;
	int	i = 0;

	if (ac == 2)
	{
		str = rot13(av[1]);
		while (str[i])
			ft_putchar(str[i++]);
	}
	ft_putchar('\n');
	return (0);
}