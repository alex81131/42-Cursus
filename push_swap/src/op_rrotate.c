/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:34:19 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/12 18:22:33 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = pile->size_a - 1;
	temp = pile->a[i];
	while (i > 0)
		pile->a[i--] = pile->a[i - 1];
	pile->a[i] = temp;
	if (!bonus)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = pile->size_b - 1;
	temp = pile->b[i];
	while (i > 0)
		pile->b[i--] = pile->b[i - 1];
	pile->b[i] = temp;
	if (!bonus)
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_pile *pile, int bonus)
{
	int	temp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1
		|| pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = pile->size_a - 1;
	temp = pile->a[i];
	while (i > 0)
		pile->a[i--] = pile->a[i - 1];
	pile->a[i] = temp;
	i = pile->size_b - 1;
	temp = pile->b[i];
	while (i > 0)
		pile->b[i--] = pile->b[i - 1];
	pile->b[i] = temp;
	if (!bonus)
		ft_printf("rrr\n");
}
