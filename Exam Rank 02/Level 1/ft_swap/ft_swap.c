void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	a = 123;
	int	b = 456;

	printf("a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("a' = %d, b' = %d\n", a, b);
	return (0);
}
*/
