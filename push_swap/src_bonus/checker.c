/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:17:19 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/17 15:17:19 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_error(t_pile *pile, int error)
{
	free(pile->a);
	free(pile->b);
	if (error)
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void exe_instruction(t_pile *pile, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		swap_a(pile, 1);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_b(pile, 1);
	else if (!ft_strcmp(instruction, "ss\n"))
		swap_s(pile, 1);
	else if (!ft_strcmp(instruction, "ra\n"))
		rotate_a(pile, 1);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_b(pile, 1);
	else if (!ft_strcmp(instruction, "rr\n"))
		rotate_r(pile, 1);
	else if (!ft_strcmp(instruction, "rra\n"))
		reverse_rotate_a(pile, 1);
	else if (!ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_b(pile, 1);
	else if (!ft_strcmp(instruction, "rrr\n"))
		reverse_rotate_r(pile, 1);
	else if (!ft_strcmp(instruction, "pa\n"))
		push_a(pile, 1);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_b(pile, 1);
	else
		ps_free_error(pile, 1);
}

void	read_stdin(t_pile *pile)
{
	char	*instructionn;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		exe_instruction(pile, instruction);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (sort_check(pile->a, pile->size_a, 0) && pile->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ps_free_error(pile, 0);
}

int	*checker_array(char **av)
{
	int	*arr;
	int	size;
	int	i;

	size = ps_strlen(av);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
		arr[i++] = ps_atoi(av[i], arr);
	check_doubles(arr, size);
	return (arr);
}

int	main(int ac, char **av)
{
	t_pile	pile;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		pile.a = checker_array(av);
		pile.size_a = ps_strlen(av);
		pile.b = (int *)malloc(pile.size_a * sizeof(int));
		if (!pile.b)
		{
			free(pile.a);
			return (0);
		}
		pile.b = 0;
		read_stdin(&pile);
	}
	return (0);
}
/*
Checker executes the operations on the stdin with ctrl + D at the end for
End of File, and returns OK/KO/Error(std_err) as result.

calculatorsoup.com/calculators/statistics/random-number-generator.php
*/