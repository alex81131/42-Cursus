#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int i;
	int gcd;

	i = 1;
	gcd = 0;
	while (i < a && i < b)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
		i++;
	}
	printf("%d", gcd);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}
/*
int	*ft_break(int n)
{
	int	i = 2;
	int	len = 0;
	int	*list;

	if (n == 1)
		len = 1;
	while (i <= n)
	{
		if (n % i == 0)
		{
			len++;
			i++;
		}
		i++;
	}
	list = (int*)malloc(len * sizeof(int));
	i = 2;
	len = 0;
	while (i <= n)
	{
		if (n % i == 0)
		{
			list[len] = i;
			i++;
			len++;
		}
		i++;
	}
	return (list);
}

int	compare(int *a, int *b)
{
	int	i = 0;
	int	j = 0;
	int	k;

	while (a[i + 1])
		i++;
	while (b[j + 1])
		j++;
	while (i >= 0)
	{
		k = j;
		while (k >= 0)
		{
			if (a[i] == b[k])
				return (a[i]);
			k--;
		}
		i--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		printf("%d\n", compare(ft_break(a), ft_break(b)));
	}
	else
		printf("\n");
	return (0);
}
*/