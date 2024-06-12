/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:39:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/12 17:43:50 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *pile, int bonus)
{
	int	temp;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	temp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = temp;
	if (!bonus)
		ft_printf("sa\n");
}

void	swap_b(t_pile *pile, int bonus)
{
	int	temp;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	temp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = temp;
	if (!bonus)
		ft_printf("sb\n");
}

void	swap_s(t_pile *pile, int bonus)
{
	int	temp;

	if (pile->size_a == 0 || pile->size_a == 1
		|| pile->size_b == 0 || pile->size_b == 1)
		return ;
	temp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = temp;
	temp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = temp;
	if (!bonus)
		ft_printf("ss\n");
}
