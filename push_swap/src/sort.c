/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:21:06 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/13 12:33:57 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	three_number_case_pile_a(t_pile *trois)
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

int	sort(t_pile *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile, 0);
		else if (size == 3)
			three_number_case_pile_a(pile);
		else
			qs_pile_a(pile, size, 0);
	}
	return (0);
}

int	ft_push(t_pile *pile, int len, int push)
{
	if (push == 0)
		push_b(pile, 0);
	else
		push_a(pile, 0);
	len--;
	return (len);
}
