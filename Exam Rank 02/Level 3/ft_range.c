#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	iter;
	int	*str;
	int	len;
	int	i = 1;

	if (start < end)
	{
		iter = 1;
		len = end - start + 1;
	}
	else
	{
		iter = -1;
		len = -(end - start) + 1;
	}
	str = (int *)malloc(len * sizeof(int));
	if (!str)
		return (0);
	str[0] = start;
//	printf("%d\n", str[0]);
	while (i < len)
	{
		str[i] = str[i - 1] + iter;
//		printf("%d\n", str[i]);
		i++;
	}
	return (str);
}
/*
int main(int ac, char **av)
{
	int	start = atoi(av[1]);
	int	end = atoi(av[2]);
	int	*s = ft_range(start, end);

	(void)ac;
	printf("start = %d\n", start);
	printf("end = %d\n", end);
	free(s);
	return (0);
}
*/