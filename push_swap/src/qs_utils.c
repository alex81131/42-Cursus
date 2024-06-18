/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:21:06 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:45:29 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_number_case(t_pile *trois)
{
	if (trois->a[0] > trois->a[1] && trois->a[0] < trois->a[2]
		&& trois->a[1] < trois->a[2])
		swap_a(trois, 0);
	if (trois->a[0] > trois->a[1] && trois->a[0] > trois->a[2]
		&& trois->a[1] < trois->a[2])
		rotate_a(trois, 0);
	if (trois->a[0] > trois->a[1] && trois->a[0] > trois->a[2]
		&& trois->a[1] > trois->a[2])
	{
		swap_a(trois, 0);
		reverse_rotate_a(trois, 0);
	}
	if (trois->a[0] < trois->a[1] && trois->a[0] < trois->a[2]
		&& trois->a[1] > trois->a[2])
	{
		reverse_rotate_a(trois, 0);
		swap_a(trois, 0);
	}
	if (trois->a[0] < trois->a[1] && trois->a[0] > trois->a[2]
		&& trois->a[1] > trois->a[2])
		reverse_rotate_a(trois, 0);
}

void	median_sort(int *pile_temp, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_temp[i] > pile_temp[j])
			{
				temp = pile_temp[i];
				pile_temp[i] = pile_temp[j];
				pile_temp[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		qs_median(int *pivot, int *pile, int size)
{
	int	*temp;
	int	i;

	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = -1;
	while (++i < size)
		temp[i] = pile[i];
	median_sort(temp, size);
	*pivot = temp[size / 2];
	free(temp);
	return (1);
}
