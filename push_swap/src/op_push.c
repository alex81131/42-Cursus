/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:35:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/12 17:39:09 by kyeh             ###   ########.fr       */
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