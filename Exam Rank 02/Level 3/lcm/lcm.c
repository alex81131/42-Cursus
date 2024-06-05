unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	i;

	if (!a || !b)
		return (0);
	if (a < b)
		i = b;
	else
		i = a;
	while (i % a != 0 || i % b != 0) i++;
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	printf("lcm is %d.\n", lcm(12, 20));
	return (0);
}
*/