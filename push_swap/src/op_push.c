/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:35:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/14 19:40:07 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_pile *pile, int bonus)
{
	int	i;

	if (pile->size_a)
	{
		pile->size_b++;
		i = pile->size_b;
		while (i > 0)
			pile->b[i--] = pile->b[i - 1];
		pile->b[0] = pile->a[0];
		pile->size_a--;
		i = 0;
		while (i < pile->size_a)
			pile->a[i++] = pile->a[i + 1];
		if (!bonus)
			ft_printf("pb\n");
	}
	else
		return ;
}

void	push_a(t_pile *pile, int bonus)
{
	int	i;

	if (pile->size_b)
	{
		pile->size_a++;
		i = pile->size_a;
		while (i > 0)
			pile->a[i--] = pile->a[i - 1];
		pile->a[0] = pile->b[0];
		pile->size_b--;
		i = 0;
		while (i < pile->size_b)
			pile->b[i++] = pile->b[i + 1];
		if (!bonus)
			ft_printf("pa\n");
	}
	else
		return ;
}

int	ft_push(t_pile *pile, int range, int push)
{
	if (push == 0)
		push_b(pile, 0);
	else
		push_a(pile, 0);
	size--;
	return (size);
}
/*
ft_push is needed to keep track of the range size.
*/