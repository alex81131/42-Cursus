#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int i;

	i = 2;
	if (nb == 1)
	{
		printf("1");
		return ;
	}
	while (nb >= i)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb != i)
				printf("*");
			nb /= i;
			i--;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
//  偉哉 48d31kh413k
/*
int	prime_check(int n)
{
	int	i = 2;

	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	big_prim(int n)
{
	int	i = 2;
	int	a = 1;

	if (n == 2 || n == 3)
		return (n);
	while (i <= n)
	{
		if (prime_check(i) == 1 && n % i == 0)
			a = i;
		i++;
	}
	return (a);
}

int	*ft_break(int n)
{
	int	i = big_prim(n);
	int	len = 0;
	int	*list;
	int	m = n;

	if (n == 1)
		len = 1;
	while (i > 1 && m > 1)
	{
		if (prime_check(i) == 1 && m % i == 0)
		{
			m /= i;
			len++;
		}
		else
			i--;
	}
	list = (int*)malloc((len + 1) * sizeof(int));
	if (!list)
		return (NULL);
	if (n == 1)
		list[0] = 1;
	i = big_prim(n);
	list[len--] = 0;
	m = n;
	while (i > 1 && m > 1)
	{
		if (prime_check(i) == 1 && m % i == 0)
		{
			list[len] = i;
			m /= i;
			len--;
		}
		else
			i--;
	}
	return (list);
}

int	main(int ac, char **av)
{
	int	a;
	int	*list;
	int	i = 0;

	if (ac == 2)
	{
		a = atoi(av[1]);
		if (a <= 0)
			printf("\n");
		list = ft_break(a);
		if (!list)
			return (0);
		while (list[i])
		{
			if (list[i + 1])
				printf("%d*", list[i]);
			else
				printf("%d\n", list[i]);
			i++;
		}
		free (list);
	}
	else
		printf("\n");
	return (0);
}
*/