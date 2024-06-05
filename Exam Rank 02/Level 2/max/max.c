int	max(int* tab, unsigned int len)
{
	int	i = 1;
	int	n;

	if (len == 0)
		return (0);
	else
	{
		n = tab[0];
		while (i < len)
		{
			if (n < tab[i])
				n = tab[i];
			i++;
		}
	}
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	tab[] = {1, 2, 179, 6, 34, 83};
	printf("Max is %d.\n", max(tab, 0));
//	printf("Number is %d.\n", tab[5]);
	return (0);
}
*/