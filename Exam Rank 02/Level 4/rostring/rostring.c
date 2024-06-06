#include <unistd.h>
#include <stdlib.h>

int	first_word(char *str)
{
	int	wlen = 0;


	while (*str && (*str == ' ' || (9 <= *str && *str <= 13)))
		str++;
	while (*str && *str != ' ' && !(9 <= *str && *str <= 13))
	{
		wlen++;		//count the length of the 1st word
		str++;
	}
	return (wlen);
}

void	ft_rotate(char *str)
{
	int	wlen = first_word(str);
	char	*s1;
	int	i = 0;
	int	j = 0;

	s1 = (char *)malloc((wlen + 1) * sizeof(char));
	if (!s1)
		return ;
	while (str[i] && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
		i++;
	while (str[i] && str[i] != ' ' && !(9 <= str[i] && str[i] <= 13))
		s1[j++] = str[i++];
	s1[j] = '\0';
	while (str[i] && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && !(9 <= str[i] && str[i] <= 13))
		{
			write(1, &str[i], 1);
			i++;
			if (!str[i])
				write(1, &" ", 1);
		}
		if (str[i] && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
			write(1, &" ", 1);
		while (str[i] && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
			i++;
	}
	j = 0;
	while (s1[j])
	{
		write(1, &s1[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_rotate(av[1]);
	write(1, &"\n", 1);
	return (0);
}