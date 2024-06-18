/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:13:09 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/18 12:55:17 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qs_3a(t_pile *pile, int range)
{
	if (range == 2)
	{
		if (pile->a[0] > pile->a[1])
			swap_a(pile, 0);
	}
	else if (range == 3 && pile->size_a == 3)
		three_number_case(pile);
	else if (range == 3)
	{
		while (range != 3 || !(pile->a[0] < pile->a[1]
						&& pile->a[1] < pile->a[2]))
		{
			if (range == 3 && pile->a[0] > pile->a[1] && pile->a[2])
				swap_a(pile, 0);
			else if (range == 3 && !(pile->a[2] > pile->a[0]
									&& pile->a[2] > pile->a[1]))
				range = ft_push(pile, range, 0);
			else if (pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (range++)
				push_a(pile, 0);
		}
	}
}
void	qs_3b(t_pile *pile, int range)
{
	if (range == 1)
		push_a(pile, 0);
	else if (range == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile, 0);
		while (range--)
			push_a(pile, 0);
	}
	else if (range == 3)
	{
		while (range || !(pile->a[0] < pile->a[1]
						&& pile->a[1] < pile->a[2]))
		{
			if (range == 1 && pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (range == 1 || (range >= 2 && pile->b[0] > pile->b[1])
								|| (range == 3 && pile->b[0] > pile->b[2]))
				range = ft_push(pile, range, 1);
			else
				swap_b(pile, 0);
		}
	}
}

int		qs_pile_a(t_pile *pile, int range, int rotation)
{
	int	pivot;
	int	subrange;

	if (sort_check(pile->a, range, 0) == 1)
		return (1);
	if (range <= 3)
	{
		qs_3a(pile, range);
		return (1);
	}
	if (!qs_median(&pivot, pile->a, range))
		return (0);
	subrange = range;
	while (subrange != range / 2 + range % 2)
	{
		if (pile->a[0] < pivot && subrange--)
			push_b(pile, 0);
		else if (++rotation)
			rotate_a(pile, 0);
	}
	while (rotation--)
		reverse_rotate_a(pile, 0);
	return (qs_pile_a(pile, subrange, 0)
			&& qs_pile_b(pile, range - subrange, 0));
}

int		qs_pile_b(t_pile *pile, int range, int rotation)
{
	int	pivot;
	int	subrange;

	if (sort_check(pile->a, range, 1) == 1)
		while (range--)
			push_a(pile, 0);
	if (range <= 3)
	{
		qs_3b(pile, range);
		return (1);
	}
	if (!qs_median(&pivot, pile->b, range))
		return (0);
	subrange = range;
	while (subrange != range / 2)
	{
		if (pile->b[0] >= pivot && subrange--)
			push_a(pile, 0);
		else if (++rotation)
			rotate_b(pile, 0);
	}
	while (rotation--)
		reverse_rotate_b(pile, 0);
	return (qs_pile_a(pile, range - subrange, 0)
			&& qs_pile_b(pile, subrange, 0));
}

/*	Recursively grouping the numbers in halves
If size = 0: all returns 1, everything checks out.

qs_3a, else if (range == 3):
[0, 1, 2] -> sorted
[0, 2, 1] 
[1, 0, 2]
[1, 2, 0]
[2, 0, 1]
[2, 1, 0]

if (!qs_median): Protection of malloc failure
	qs_median makes sure that the median is always the middle one,
	or the element just on the left (with even number of element.
Therefore, given every element has a different value,
	range /2 (half of the number of elements)
  + range %2 (including the median itself)
	determines the number of elements staying in stack a.
For the same reason, in qs_pile_b
*/