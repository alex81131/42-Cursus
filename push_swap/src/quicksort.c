/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:13:09 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/13 12:55:26 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qs_3_ab(t_pile *pile, int len)
{
	if (len == 3 && pile->size_a == 3)
		three_number_case_pile_a(pile);
	else if (len == 2)
	{
		if (pile->a[0] > pile->a[1])
			swap_a(pile, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(pile->a[0] < pile->a[1]
						&& pile->a[1] < pile->a[2]))
		{
			
		}
	}
}
int		sort_3_b(t_pile *pile, int len);

int		qs_median(int *pivot, int *pile, int size)
{
	int	temp;
	int	i;

	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = 0;
	while (i < size)
		temp[i] = pile[i++];
	median_sort(temp, size);
	*pivot = median_sort[size / 2];
	free(temp);
	return (1);
}

int		qs_pile_a(t_pile *pile, int len, int count_r);
int		qs_pile_b(t_pile *pile, int len, int count_r);