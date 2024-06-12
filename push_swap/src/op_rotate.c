/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:18:24 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/12 17:39:21 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = 0;
	temp = pile->a[i];
	while (i < pile->size_a - 1)
		pile->a[i++] = pile->a[i + 1];
	pile->a[i] = temp;
	if (!bonus)
		ft_printf("ra\n");
}

void	rotate_b(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = 0;
	temp = pile->b[i];
	while (i < pile->size_b - 1)
		pile->b[i++] = pile->b[i + 1];
	pile->b[i] = temp;
	if (!bonus)
		ft_printf("rb\n");
}

void	rotate_r(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1
		|| pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = 0;
	temp = pile->a[i];
	while (i < pile->size_a - 1)
		pile->a[i++] = pile->a[i + 1];
	pile->a[i] = temp;
	i = 0;
	temp = pile->b[i];
	while (i < pile->size_b - 1)
		pile->b[i++] = pile->b[i + 1];
	pile->b[i] = temp;
	if (!bonus)
		ft_printf("rr\n");
}
