/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:32 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/18 16:34:48 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **av)
{
	t_pile	pile;
	int		size;
	int		i;

	size = ps_strlen(av);
	pile.a = (int *)malloc(size * sizeof(int));
	if (!pile.a)
		return ;
	pile.b = (int *)malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	pile.size_a = size;
	pile.size_b = 0;
	i = -1;
	while (++i < size)
		pile.a[i] = ps_atoi(av[i], pile.a);
	check_doubles(pile.a, size);
	qs_pile_a(&pile, size, 0);
	free(pile.a);
	free(pile.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		if (ac == 2)
			free_array(av, ps_strlen(av));
	}
	return (0);
}
/*
Sorting 100 random values: 700±2.5% steps
Sorting 500 random values: ~5200 steps
*/