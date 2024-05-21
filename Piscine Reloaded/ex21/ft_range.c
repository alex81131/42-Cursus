/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:08 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/14 16:56:13 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (0);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while (++i < max - min)
		arr[i] = min + i;
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*table;
	int	i = -1;

	min = 5;
	max = 35;
	table = ft_range(min, max);
	while(++i < max - min)
		printf("%d, ", table[i]);
	printf("\n");
	free(table);
	return (0);
}
*/
