int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	while (n > 2)
	{
		if (n % 2 != 0)
			return (0);
		else
			n /= 2;
	}
	return (1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	a = atoi(av[1]);

	(void)ac;
	printf("Number = %d\n", a);
	printf("%d\n", is_power_of_2(a));
	return (0);
}
*/